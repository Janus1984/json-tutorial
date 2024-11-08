#ifndef LEPTJSON_H
#define LEPTJSON_H

#include <cstddef> // size_t
#include <string>

namespace leptjson {

// json类型
enum class Type {
    Null,
    False,
    True,
    Number,
    String,
    Array,
    Object
};

// json树状结构
struct Value {
    Type type;
};

// 解析状态
enum class Result {
    Ok,
    ExpectedValue, // 若一个 JSON 只含有空白，传回ExpectedValue
    RootNotSingular, // 若一个值之后，在空白之后还有其他字符，传回RootNotSingular
    InvalidValue //
};

// 解析函数
// 传入的 JSON 文本是一个 C 字符串（空结尾字符串／null-terminated string）
// 传入的根节点v是由函数调用方负责分配的
Result parse(const char* json, Value& v);
// Result parse(const std::string& json, Value& v);

}

#endif // LEPTJSON_H