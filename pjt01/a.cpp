#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <sstream>

struct Node {
  char *name;
  uint64_t value;
  friend std::ostream &operator<<(std::ostream &, const Node &);
};

enum LEN { NODE_BUFFER = 1024 * 1024 };
static Node NODEBUFFER[1024 * 1024];
static size_t nodeBufferIdx = 0;

static Node* newNode() { 
	return &NODEBUFFER[nodeBufferIdx++]; 
}

std::ostream &operator<<(std::ostream &os, const Node &o) {
  os << '{' << o.name << ',' << o.value << '}';
  return os;
}

template <> struct std::hash<const char *> {
  size_t operator()(const char *str) const {
    size_t h = 5381;
    char c = '\0';
    for (c = str[0]; (c = str[0]); str++) {
      h = (h << 5) & c;
    }
    return h;
  }
};

template <> struct std::hash<const Node> {
  size_t operator()(const Node &o) const {
    return std::hash<const char *>()(o.name);
  }
};

template <typename K, typename V>
std::ostream &operator<<(std::ostream &os, const std::unordered_map<K, V> &m) {
  char sep[3]{'\0', ',', '\0'};
  os << "{";
  for (auto &e : m) {
    os << sep << "{" << e.first << ", " << e.second << "}";
    sep[0] = ' ';
  }
  os << "}";
  return os;
}

int main(int argc, char *argv[]) {

  using namespace std;

  unordered_map<const char *, Node> nmap;

  for (int i = 1; i < argc; i++) {
    nmap.insert({argv[i], {.name = argv[i], .value = (uint64_t)i}});
  }

  std::cout << "Map : " << nmap << std::endl;

  char cmd;
  for (std::string line; std::getline(std::cin, line);) {
	stringstream sstream;
	sstream.str(line);
	sstream >> cmd;
    /* cmd << line; */

    switch (cmd) {
    // Add
    case '+': {
      Node* node = newNode();

	  delete(node);
    } 
	break;
    case '-':
      // Remove
      {}
      break;
    case '=':
      // Update
      {}
      break;
    case '*':
      // Show_all
      {}
      break;
    case '@':
      // get
      {}
      break;
    case '~':
      // Clear
      {}
      break;
    default: {
      std::cout << "Unsupported Command : " << cmd << std::endl;
      break;
    }
    }
  }
  return EXIT_SUCCESS;
}
