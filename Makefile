NAZWA_APLIKACJI=pogoda
URUCHOMIENIE_APLIKACJI=./${NAZWA_APLIKACJI}
ZRODLA_PROJEKTU=`/bin/pwd`/src/*.cpp `/bin/pwd`/inc/*.hpp `/bin/pwd`/ui/*.ui`/bin/pwd`/inc/*.h
PODSTAWIENIA=OBJECTS_DIR=${KATALOG_OBJ} INCLUDEPATH=inc\
                         QT+=widgets QT+=network QT+=charts HEADERS+=../inc/weather_data_caller.h\
			QMAKE_CXXFLAGS=-std=c++11 MOC_DIR=${KATALOG_MOC}\
			HEADERS+=../inc/weather_data.h HEADERS+=../inc/weather_data_saver.h\
			HEADERS+=../inc/weather_map.h HEADERS+=../inc/city.h\
			HEADERS+=../inc/weather_forecaster.h HEADERS+=../inc/weather_forecast_data.h\
			HEADERS+=../inc/weather_MainWindow.h HEADERS+=../inc/city_info.h\
			HEADERS+=../inc/weather_charts_tab.h HEADERS+=../inc/weather_animation.h
KATALOG_OBJ=./obj
KATALOG_MOC=./moc

__start__: __sprawdz_Qt__ ${NAZWA_APLIKACJI}
	rm -f core*; ${URUCHOMIENIE_APLIKACJI}

__sprawdz_Qt__: __sprawdz_qmake__
	@if qmake -v | grep 'ver.*5\.[0-9]*\.[0-9]*' > /dev/null;\
         then exit 0;\
         else echo; echo " Brak biblioteki Qt w wersji 5.x.x";\
              echo;  exit 1;\
        fi

__sprawdz_qmake__:
	@if which qmake > /dev/null; then exit 0;\
        else\
          echo; echo " Brak programu qmake."\
               " Prawdopodobnie biblioteka Qt nie zostala zainstalowana.";\
          echo; exit 1;\
        fi


${NAZWA_APLIKACJI}: pro Makefile.app __sprawdz__


pro:
	mkdir pro

__sprawdz__:
	make -f Makefile.app

Makefile.app: pro/${NAZWA_APLIKACJI}.pro
	qmake -o Makefile.app pro/${NAZWA_APLIKACJI}.pro

pro/${NAZWA_APLIKACJI}.pro: Makefile
	rm -f ${NAZWA_APLIKACJI}
	qmake -project -nopwd -o pro/${NAZWA_APLIKACJI}.pro\
               ${PODSTAWIENIA} ${ZRODLA_PROJEKTU} 

project: __usun_pro__ pro/${NAZWA_APLIKACJI}.pro

__usun_pro__:
	rm -f pro/${NAZWA_APLIKACJI}.pro

clean:
	make -f Makefile.app clean

cleanall: clean
	rm -f ${NAZWA_APLIKACJI}

cleantotally: cleanall
	rm -f ${NAZWA_APLIKACJI}.pro Makefile.app
	rm -fr ${KATALOG_MOC} ${KATALOG_OBJ}
	rm -fr pro/ obj/
	rm -fr moc/
	find . -name \*~ -exec rm {} \;
	find . -name \*.tex -exec rm {} \;

help:
	@echo "Podcele:"
	@echo 
	@echo " project  - wymusza utworzenie nowego projektu"
	@echo " clean    - usuwa wszystkie produkty kompilacji i konsolidacji"
	@echo " cleanall - usuwa produkty kompilacji wraz z aplikacja"
	@echo " cleantotally - usuwa wszystko oprocz zrodel i pliku Makefile"
	@echo " help     - wyswietla niniejszy pomoc"
	@echo
