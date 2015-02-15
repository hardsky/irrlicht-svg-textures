Target = SvgTexturesExample
Sources = main.cpp

# general compiler settings
CPPFLAGS = -I../../irrlicht/include -I/usr/X11R6/include
CXXFLAGS = -O3 -ffast-math
#CXXFLAGS = -g -Wall

#default target is Linux
all: all_linux

ifeq ($(HOSTTYPE), x86_64)
LIBSELECT=64
endif

all_linux: LDFLAGS = -L/usr/X11R6/lib$(LIBSELECT) -L../../irrlicht/lib/Linux -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor \
-lrsvg-2 -lm -lgio-2.0 -lgdk_pixbuf-2.0 -lgobject-2.0 -lglib-2.0 -lcairo
all_linux clean_linux: SYSTEM=Linux
DESTPATH = ../bin/$(Target)

all_linux:
	$(warning Building...)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(Sources) -o $(DESTPATH) $(LDFLAGS)

clean: clean_linux
	$(warning Cleaning...)

clean_linux:
	@$(RM) $(DESTPATH)

.PHONY: all clean clean_linux
