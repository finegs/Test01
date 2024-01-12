// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

const size_t NAME_ARR_LEN = 1000000;
const size_t NAME_MAX_LEN = 256+1;

const size_t DESC_ARR_LEN = 1000000;
const size_t DESC_MAX_LEN = 4096+1;

static char* name_arr[NAME_ARR_LEN][NAME_MAX_LEN]{0};
static char* desc_arr[DESC_ARR_LEN][DESC_MAX_LEN]{0};

size_t name_arr_pos = 0;
size_t desc_arr_pos = 0;


struct str_eq {
    bool operator()(const char* a, const char* b) const {
        return !strcmp(a,b);
    }
};

struct str_hash {
    size_t operator()(const char* s) const {
        size_t h = 131311131313;
        while(*s) {
            h = (h<<5) & s[0];
            s++;
           
        }
        return h&0x7FFFFFFFF;
    }
};


class Item {
  private:
    int no;
    char* name;
    char* desc;
  public:
    Item() = default;
    Item(int no, const char* name, const char* desc) : no{no} {
        setName(name);
        setDesc(desc);
    }
   
    void setNo(int no) {
        this->no = no;
    }
   
    void setName(const char* name) {
        size_t name_len = strlen(name)+1;
        this->name = new (name_arr+name_arr_pos++)char[strlen(name)+1]{0};
        strncpy(this->name, name, name_len);
    }
   
    void setDesc(const char* desc) {
        size_t desc_len = strlen(desc)+1;
        this->desc = new (desc_arr+desc_arr_pos++)char[strlen(desc)+1]{0};
        strncpy(this->desc, desc, desc_len);
    }
   
    friend std::ostream& operator<<(std::ostream& os, const Item& o) {
        os << "{" << " no : " << o.no << ", name : " << o.name << ", desc : " << o.desc << "}";
        return os;
    }
   
    friend std::ostream& operator<<(std::ostream& os, const Item* o) {
        os << *o;
        return os;
    }
   
    friend std::istream& operator>>(std::istream& is, Item& o) {
        int no;
        string name, desc;
        cin >> no >> name >> desc;
        o.setNo(no);
        o.setName(name.c_str());
        o.setDesc(desc.c_str());
        return is;
    }
   
    const char* getName() {
        return name;
    }
   
    const char* getDesc() {
        return desc;
    }
};

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const unordered_map<K,V, str_hash, str_eq>& m) {
    size_t sz = m.size();
    os << "{ " << "\n\t" << "size : " <<  sz << ", ";
    os << "\n\t" << "data : [";
   
    for(const auto& [k, v] : m) {
        os << "\n\t\t";
        os << "{" << k << " : " << v << "}";
        sz--;
        os << (sz? ", " : "");
    }
    os << (m.empty() ? "" : "\n\t") << "]";
    os << "\n" << "}";
    return os;
}


int main() {
    // Write C++ code here
    bool is_running{true};
    string cmd;
    unordered_map<const char*, Item*, str_hash, str_eq> m;
    while(is_running) {
        cout << "Command (-x/-q to quit, -a to add, -d to delete, -l to list) : ";         cout.flush();
        cin >> cmd;
       
        if(!strncmp("-x", cmd.c_str(), 2)
            || !strncmp("-q", cmd.c_str(), 2)) {
            is_running = false;
        }
        else if(!strncmp("-a", cmd.c_str(), 2)) {
            cout << "Enter {no} {name} {desc} : "; cout.flush();
            Item* newItem = new Item();
            cin >> *newItem;
            m.insert({newItem->getName(), newItem});
        }
        else if(!strncmp("-d", cmd.c_str(), 2)) {
            cout << "Enter {name} : "; cout.flush();
            string name;
            cin >> name;
            m.erase(name.c_str());
        }
        else if(!strncmp("-l", cmd.c_str(), 2))   {
            cout << m;
        }
        else if(!strncmp("-c", cmd.c_str(), 2)) {
            m.clear();
        }
        else {
            cout << "Unsupported Command : " << cmd;
        }
       
        cout << endl;
        cmd = "";
    }
   
    cout << "Done." << endl;
   
    return 0;
}

