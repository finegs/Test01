#include <iostream>

char* mstrtok(char* _str, const char* _delim) {
	static char* pstr;
	static char bdelim;
	const char* pdelim;

	if(NULL == _str) {
		_str = pstr;
		if(*pstr) // replace previous null-terminator '\0' with previous delimeter
			*(_str-1)=bdelim;
	}
	else {
		pstr = _str;
	}

	while(*pstr) {
		pdelim = _delim;
		while(*pdelim) {
			if(*pstr == *pdelim) {
				bdelim = *pdelim;
				*pstr = '\0'; 
				pstr++;
				return _str;
			}
			pdelim++;
		}
		pstr++;
	}
	return _str;
}

