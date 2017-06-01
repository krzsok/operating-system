#==============================================================================
#                   Przykladowy plik Makefile
#==============================================================================
# make all, hello.x, mcint.x, run1, run2s, run2d1, run2d2, clean, tar
#==============================================================================
# Objasnienia:
# Wszystko co jest po znaku # do konca linii jest traktowane jako komentarz
#------------------------------------------------------------------------------
# Jezeli uzywamy rozszerzen w nazwach plikow, ktore nie znajduja sie na
# liscie parametrow wewnetrznych make (mozna je sprawdzic wykonujac: make -p),
# to nalezy je umiescic po slowie .SUFFIXES:, np.:
.SUFFIXES: .c .cpp .o .x .h
#------------------------------------------------------------------------------
# Ponizej przyklady definiowania makr (nie musza byc oznaczane wielkimi literami,
# ale moze byc to wygodne, np.latwiej je odroznic od reszty).
# Do makra MAKRO sie przez $(MAKRO)
# Nazwa katalogu (moze sie przydac); wstawiamy wynik polecenia basename, 
# ktore z nazwy sciezkowej wybiera wlasciwa nazwe katalogu lub pliku (po ostatnim /). 
DIR = `basename $(PWD)`
# Nazwy, ktorych bedziemy uzywac, tu: rdzenie nazw plikow
NAME1 = 2
NAME2 = 3
# Program wykonawczy: dodajemy rozszerzenie .x, ale moze byc dowolne.
EXEC1  = $(NAME1).x  
# Pliki powstale po kompilacji plikow zrodlowych, tzw. object files
OBJS1  = $(NAME1).o
# Dolaczane biblioteki (poza standardowymi). 
# Makra moga byc puste, np. przewidziane na przyszlosc.
LIBS1  = 
# Pliki naglowkowe
HEADS1 = 
#------------------------------------------------------------------------------
# Analogicznie dla drugiego programu (dla biblioteki statycznej i dzielonej)
EXEC2  = $(NAME2).x
OBJS2  = $(NAME2).o 
LIBS2=
HEADS2=
# Dla drugiego programu utworzymy biblioteke statyczna oraz dzielona
LIB_NAME = MojeFunkcje
# Katalog dla bibliotek
LIB_DIR = ./lib
# Biblioteka statyczna (static library)
LIB_STAT = lib$(LIB_NAME).a
# Biblioteka dzielona (shared library)
LIB_SHAR = lib$(LIB_NAME).so
# Pliki objectowe wchodzace do biblioteki

# Pliki naglowkowe
HEADS2 = 

#------------------------------------------------------------------------------
# Opcje kompilatora i linkera
CFLAGS =  -O -fPIC
LFLAGS =  -O
# Biblioteki linkera zainstalowane w systemie 
# (tu: biblioteka matematyczna libm)
LDLIBS = -lm
# Kompilator i linker (czesto ta sama nazwa)
CO = gcc
LD = $(CO)
# Program-archiwizer do tworzenia bibliotek statycznych
AR = ar
# Opcje archiwizera: uaktualnianie biblioteki i wypisywanie komunikatow 
ARFLAGS = rv
###############################################################################
# Ponizej przyklady definiowania regul zaleznosci
###############################################################################
# Tzw. regula wzorcowa - mowiaca jak pliki z rozszerzeniem .o otrzymac 
# z plikow o rozszerzeniach .c i .h. 
# To co jest po lewej stronie dwukropka nazywa sie "cel", a to co jest po
# prawej - "prerekwizyty" (tzn. to od czego zalezy "cel"). 
# Najpierw make sprawdza czy plik celowy (tu: odpowiedni plik z rozszerzeniem 
# .o) jest aktualny (tzn. nowszy od odpowiednich plikow .c i .h) - jezeli nie, 
# to wykonuje komende ponizej (tutaj: kompilacja). 
# Znak % oznacza wzorzec, tzn. dowolny ciag znakow, ktore tworza rdzen nazwy 
# pliku. 
# Zmienna wewnetrzna $< oznacza pierwszy prerekwizyt, tu: nazwe odpowiedniego 
# pliku z rozszerzeniem .c, ktory nalezy uaktualnic aby otrzymac plik .o. 
# Uwaga: Komenda zaczyna sie od znaku tabulacji (niewidocznego).
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<
# Jak wyzej, ale bez zaleznosci od plikow naglowkowych
%.o: %.c
	$(CO) $(CFLAGS) -c $<
###############################################################################
# Regula zaleznosci - uaktualnij pliki po prawej stronie dwukropka.
# Na ogol zakladamy, ze w danym katalogu nie ma pliku o nazwie all,
# tzn. ze dana regula zawsze sie wykona. 
# Gdyby plik o takiej nazwie przypadkowo znalazl sie w danym katalogu,
# to mozna wymusic bezwzgledne wykonanie sie ponizszej reguly wpisujac
# nazwe celu po slowie .PHONY:, np.
.PHONY: all
all: $(EXEC1) $(EXEC2) 
###############################################################################
# Jawna regula zaleznosci - najpierw uaktualnij pliki po prawej stronie 
# dwukropka, a potem wykonaj komende, ktora jest w nastepnej linijce (tu:
# wykonaj linkowanie). 
# Zmienna wewnetrzna $@ oznacza cel, tzn. obiekt, ktory jest po lewej stronie 
# dwukropka, tu: $(EXEC1);  a zmienna $^ oznacza wszystkie prerekwizyty, tzn.
# obiekty stojace po prawej stronie dwukropka (tutaj wszystkie pliki .o, ktore
# powinny byc zlinkowane). 
$(EXEC1): $(OBJS1) $(LIBS1) 
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC2): $(OBJS2) $(LIBS2) 
	$(LD) -o $@ $(LFLAGS) $^
###############################################################################
# Aby zapewnic bezwzgledne wykonanie niezaleznie czy istnieja pliki o danych
# nazwach (podobie jak dla all). Jezeli jestesmy pewni, ze plikow o takich
# nazwach nie bedzie w danym katalogu, to mozemy pominac ponizsza deklaracje.
.PHONY: run1
###############################################################################
# Uruchom program $(EXEC1); najpierw sprawdz, czy kod wykonawczy jest aktualny
run1: $(EXEC1)
	./$(EXEC1)
#==============================================================================
#============================  PROGRAM 2 ======================================
#==============================================================================
# Tworzenie bibliteki statycznej dla drugiego programu przy pomocy 
# programu archiwizujacego. Zmienna automatyczne $? oznacza wszystkie 
# prerekwizyty, ktore sa nowsze niz cel (dzieki temu tylko zmodyfikowane
# pliki beda wstawiane do biblioteki-archiwum). Nastepnie tworzony jest
# katalog dla biblioteki (jezeli nie istnieje) i do niego przenoszona jest
# stworzona biblioteka.
$(LIB_STAT): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $?
	mkdir -p $(LIB_DIR)
	mv $(LIB_STAT) $(LIB_DIR)
###############################################################################
# Tworzenie biblioteki dzielonej (shared library)
$(LIB_SHAR): $(LIB_OBJS) 
	$(LD) -shared -o $@ $(LFLAGS) $(LIB_OBJS) 
	mkdir -p $(LIB_DIR)
	mv $(LIB_SHAR) $(LIB_DIR)
###############################################################################
#

###############################################################################
# Sprzataczka (tez "phony target")
###############################################################################
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
