/**
 * @author: WangKang
 * @date: 2023-03-29 12:11:47
 * @blog: kang17.xyz
 * @filepath: cpp\main.cpp
 * @description: json格式化主函数
 * Copyright 2023 WANGKANG, All Rights Reserved.
 */
#include <iostream>
#include <string>

#include "cpp/JsonFormatter.cpp"
#include "head/JsonFormatter.h"
using namespace std;

int main() {
    JsonFormatter jsonFormatter("resource/test1.json");
    cout << jsonFormatter.getJsonFormat() << endl;
    jsonFormatter.saveAs("resource/testFormat.json");
    return 0;
}
