#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unordered_map>

#if 1
struct data {
	int nr;
	char const* value;
} dat[] = { {1, "Foo"}
	,{2, "Bar"}
	,{3, "Hello"}
	,{4, "World"}
	};

int comp_dat(const void* a, const void * b)
{
	const data* l = (const data*)a;
	const data* r = (const data*)b;
	if(l->nr < r->nr) return -1;
	else if(l->nr > r->nr) return 1;
	else return 0;
}

int main(int argc, char* argv[])
{
	data key = { .nr = 3 };
	const data* res = (const data*)bsearch(&key, dat, sizeof(dat)/sizeof(dat[0]), sizeof(dat[0]), comp_dat);

	if(res) {
		printf("No %d : %s\n", res->nr, res->value);
	}
	else {
		printf("No %d : not found\n", key.nr);
	}

	return EXIT_SUCCESS;
}

#endif

