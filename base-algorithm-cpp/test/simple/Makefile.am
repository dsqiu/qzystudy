EXTRA_DIST = SimplePlugIn.cpp
#AM_INCLUDES = -I$(top_builddir)/include -I$(top_srcdir)/include

bin_PROGRAMS=mytest

mytest_SOURCES=ExampleTestCase.cpp Main.cpp  ExampleTestCase.h

mytest_LDADD= libcppunit.a -ldl -lm
