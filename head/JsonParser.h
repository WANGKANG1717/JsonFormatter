#ifndef __JSONPARSER_H__
#define __JSONPARSER_H__
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class JsonParser {
   private:
    string json;        // 存储json
    string jsonBlank;   // 存储去掉空白符的json
    string jsonFormat;  // 存储格式化后的json
    string path;        // 文件路径

   public:
    JsonParser(string path);
    JsonParser();
    void removeBlank();      // 去掉所有空白符
    void parserJsonBlank();  // 将jsonBlank格式化
    string getJson();
    string getJsonBlank();
    string getJsonFormat();
    string getPath();
    void setPath(string filePath);
};
#endif
