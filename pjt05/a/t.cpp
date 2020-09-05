
#if 1
#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

int main(int argc, char* argv[]) {

	multimap<int, int> mm;

	mm.insert({10,1});
	mm.insert({40,11});
	mm.insert({70,17});


	multimap<int, int>::iterator iter;

	cout << "mm.size() : " << mm.size() << endl;
	cout << "mm.count() : " << mm.count(40) << endl;

	for(iter = mm.begin();iter != mm.end();iter++) {
		cout << "[" << iter->first << "," << iter->second << "] ";
	}

	cout << endl << endl;

	mm.insert({40,440});
	mm.insert({40,3});

	cout << "mm.size():"<<mm.size()<<endl;
	cout << "mm.count(40):"<<mm.count(40)<<endl;

	std::for_each(mm.begin(), 
			mm.end(), 
			[] (const auto& i){ cout << "{" << i.first << ","<< i.second << "}'\n"; });
	// for(iter = mm.begin();iter != mm.end();iter++) {
	// 	cout << "[" << iter->first << "," << iter->second << "] ";
	// }
	cout << '\n';

	system("pause");

	return 0;
}

#endif

#if 0

#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

namespace my {
	template<typename T>
	void Test_Map(size_t N)
	{
		T dict;
		for (int i = 0; i < N; i++)
		{
			dict.insert({i, i});
		}
		for (int i = 0; i < N; i++)
		{
			dict.find(i);
		}
	};
}

class FactorMaker {
    map<int, double> cache;

    double longRunningFetch(int key)
    {
        const double factor = static_cast<double> (rand()) / RAND_MAX;
        cout << "calculating factor for key " << key << endl;
        // lock
        // cache.insert(make_pair(key, factor));
        cache.insert({key, factor});
        // unlock
        return factor;
    }

public:
    double getFactor(int key) {
        // lock
        map<int, double>::iterator it = cache.find(key);
        // unlock
        return (cache.end() == it) ? longRunningFetch(key) : it->second;
    }
};

FactorMaker & getFactorMaker()
{
    static FactorMaker instance;
    return instance;
}

class UsesFactors {
public:
    UsesFactors() {}

    void printFactor(int key) const
    {
        cout << getFactorMaker().getFactor(key) << endl;
    }
};

int main(int argc, char *argv[])
{
    const UsesFactors obj;

    for (int i = 0; i < 10; ++i)
        obj.printFactor(i);

    for (int i = 0; i < 10; ++i)
        obj.printFactor(i);

    return EXIT_SUCCESS;
}

#endif