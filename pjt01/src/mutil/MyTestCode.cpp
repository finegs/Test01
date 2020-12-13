
#include <boost/functional/hash.hpp>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <iostream>

using uint = unsigned int;

enum class Direction : int
{
    Left = 0,
    Right = 1,
    Up = 2,
    Down = 3,
    Null = 4
};

class RectData
{
private:
    uint width;
    uint height;
    std::vector<uint> datas;
    uint total;

public:
    RectData();
    RectData(uint _width, uint _height);

    size_t hash() const;
    bool operator==(const RectData &o) const;
    bool operator==(const RectData *o) const;

    struct KeyHash;
    struct KeyEqual;
};

RectData::RectData(uint _width, uint _height)
    : width(_width), height(_height), datas(_width * _height, 0)
{
    total = _width * _height;
}

RectData::RectData() : RectData(0u, 0u)
{
    std::cout << "Calling the default coonstructor !!!" << std::endl;
}

size_t RectData::hash() const
{
    // size_t hc = 37;
    // size_t SNPN = 37;
    // for(unit u : datas) { hc = hc*SNPN + u;}
    // return hc;
    return boost::hash_value(datas);
}

struct RectData::KeyHash
{
    std::size_t operator()(const RectData &o) const
    {
        return o.hash();
    }

    std::size_t operator()(const RectData *o) const
    {
        return o->hash();
    }
};

struct RectData::KeyEqual
{
    std::size_t operator()(const RectData &a, const RectData &b) const
    {
        return a == b;
    }

    std::size_t operator()(const RectData *a, const RectData *b) const
    {
        return *a == *b;
    }
};

bool RectData::operator==(const RectData &o) const
{
    if (this == &o)
        return true;
    return (width == o.width) && (height == o.height) && (datas == o.datas);
}

bool RectData::operator==(const RectData *o) const
{
    if (this == o)
        return true;
    return (width == o->width) && (height == o->height) && (datas == o->datas);
}

using namespace std;

using StoredInfo = std::tuple<uint, RectData, Direction>;

int main(int argc, char *argv[])
{

    unordered_map<RectData, StoredInfo, RectData::KeyHash, RectData::KeyEqual> visitMap;

    RectData r1(5u, 5u);
    RectData r2(4u, 4u);
    RectData r3(3u, 3u);
    RectData r4(2u, 2u);

    StoredInfo i0 = std::make_tuple(10u, r1, Direction::Up);
    StoredInfo i1 = std::make_tuple(11u, r2, Direction::Down);
    StoredInfo i2 = std::make_tuple(12u, r3, Direction::Right);
    StoredInfo i3 = std::make_tuple(13u, r4, Direction::Left);

    visitMap[r1] = i0;
    visitMap[r2] = i1;
    visitMap.insert(std::make_pair(r3, i2));
    visitMap.emplace(r4, i3);

    StoredInfo i4 = visitMap[r1];
    std::cout << "Verify (must be 11) == " << std::get<0>(i1) << std::endl;

    StoredInfo &i5 = visitMap[r2];
    std::cout << "Verify (must be 12) == " << std::get<0>(i5) << std::endl;

    auto it = visitMap.find(r3);
    std::cout << "Verify (must be 13) == " << std::get<0>(it->second) << std::endl;

    return EXIT_SUCCESS;
}