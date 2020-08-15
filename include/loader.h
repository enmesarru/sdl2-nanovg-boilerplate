#ifndef _loader_h_
#define _loader_h_

#include <string>
#include <stdint.h>
#include <vector>

class symbol
{
public:
    symbol(): type(sym_type_unknown), name(), addr(0) {}
    enum symbol_type {
        sym_type_unknown = 0,
        sym_type_function = 1
    };
    symbol_type type;
    std::string name;
    uint64_t addr;
};

#endif