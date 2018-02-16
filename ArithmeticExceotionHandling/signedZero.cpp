#include "defs.h"
#include"floatOperations.h"

/*log(x) when x is limited to positive zero*/
double logPZ() {
	return log(0);
}

/*log(x) when x is limited to negative zero*/
double logNZ() {
	return log(-0.0f);
}

/*sinc(x) when x is limited to positive zero*/
double sincPZ() {
	return sin(0) / +0;
}

/*sinc(x) when x is limited to negative zero*/
double sincNZ() {
	return sin(-0.0f) / (-0.0f);
}
/*sin(x)/|x| when x is limited to negative zero*/
double sincNZA() {
	return sin(-1.0 * 0) / abs(-1.0 * 0);
}