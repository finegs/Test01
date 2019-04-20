#include <cstdlib>
#include <cstdio>
#include <iostream>
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

int comp_dat(void const* a, void const* b)
{
	struct data const* l = (struct data const*)a;
	struct data const* r = (struct data const*)b;
	if(l->nr < r->nr) return -1;
	else if(l->nr > r->nr) return 1;
	else return 0;
}

int main(int argc, char* argv[])
{
	struct data key = { .nr = 3 };
	struct data const* res = (struct data const*)bsearch(&key, dat, sizeof(dat)/sizeof(dat[0]), sizeof(dat[0]), comp_dat);

	if(res) {
		printf("No %d : %s\n", res->nr, res->value);
	}
	else {
		printf("No %d : not found\n", key.nr);
	}

	return EXIT_SUCCESS;
}

#endif

