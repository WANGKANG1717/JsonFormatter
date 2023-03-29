/**
 * @author: WangKang
 * @date: 2023-03-29 12:11:47
 * @blog: kang17.xyz
 * @filepath: cpp\main.cpp
 * @description:
 * Copyright 2023 WANGKANG, All Rights Reserved.
 */
#include <iostream>
#include <string>

#include "./cpp/JsonParser.cpp"
#include "./head/JsonParser.h"
using namespace std;

int main() {
    JsonParser jsonParser("resource/test.json");
    // cout << jsonParser.getJson() << endl;
    // cout << jsonParser.getJsonBlank() << endl;
    // jsonParser.setPath("test2.json");
    // cout << jsonParser.getJson() << endl;
    // cout << jsonParser.getJsonBlank() << endl;
    return 0;
}
