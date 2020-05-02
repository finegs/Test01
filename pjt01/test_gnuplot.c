#include <iostream>
#include "pGNUPlot.h"

int main() {

　 CpGnuplot plot ("D:/Programs/gnuplot/bin/wgnuplot.exe");
　
　 plot.cmd ("splot [x=-3:3] [y=-3:3] sin(x) * cos(y)");

	return 0;
}
