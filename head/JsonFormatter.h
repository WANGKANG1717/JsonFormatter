/**
 * @author: WangKang
 * @date: 2023-03-29 18:31:47
 * @blog: kang17.xyz
 * @filepath: head\JsonParser.h
 * @description:
 * Copyright 2023 WANGKANG, All Rights Reserved.
 */
#ifndef __JSONPARSER_H__
#define __JSONPARSER_H__
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class JsonFormatter {
   private:
    string json;        // 存储json
    string jsonBlank;   // 存储去掉空白符的json
    string jsonFormat;  // 存储格式化后的json
    string path;        // 文件路径

   public:
    JsonFormatter(string path);
    JsonFormatter();
    void removeBlank();      // 去掉所有空白符
    void parserJsonBlank();  // 将jsonBlank格式化
    string getJson();
    string getJsonBlank();
    string getJsonFormat();
    string getPath();
    void setPath(string filePath);
    string tap(int num);
    void save();
    void saveAs(string filePath);
};
#endif
