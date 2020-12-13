#include <src/plot/pGNUPlot.h>
#include <iostream>

int main() {
	CpGnuplot plot ("D:/Programs/gnuplot/bin/wgnuplot.exe");

	plot.cmd ("splot [x=-3:3] [y=-3:3] sin(x) * cos(y)");

	return 0;
}
