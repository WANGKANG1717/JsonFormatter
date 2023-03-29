/**
 * @author: WangKang
 * @date: 2023-03-29 18:32:07
 * @blog: kang17.xyz
 * @filepath: cpp\JsonParser.cpp
 * @description:
 * Copyright 2023 WANGKANG, All Rights Reserved.
 */
#include "../head/JsonFormatter.h"

JsonFormatter::JsonFormatter(string filePath) {
    path = filePath;
    ifstream fin;
    fin.open(path.c_str(), ios::in);
    if (!fin.is_open()) {
        cout << "cannot open the file" << endl;
    }
    char c;
    // 这里可以在读取的时候就去掉空白符，我这里分开写主要是为了分离子功能
    while ((c = fin.get()) != EOF) {
        json.push_back(c);
    }
    fin.close();
    removeBlank();
    // cout << jsonBlank << endl;
    parserJsonBlank();
}
JsonFormatter::JsonFormatter() {
    path = "";
}
// 去掉所有空白符
void JsonFormatter::removeBlank() {
    jsonBlank.clear();
    for (int i = 0; i < json.size(); i++) {
        // 非空白符
        if (!(isblank(json[i]) || json[i] == '\n')) {
            jsonBlank.push_back(json[i]);
        }
    }
}
string JsonFormatter::getJson() {
    return json;
}
string JsonFormatter::getJsonBlank() {
    return jsonBlank;
}
string JsonFormatter::getJsonFormat() {
    return jsonFormat;
}
string JsonFormatter::getPath() {
    return path;
}
void JsonFormatter::setPath(string filePath) {
    (*this) = JsonFormatter(filePath);
}

string JsonFormatter::tap(int num) {
    string s = "";
    // string empty="    ";
    for (int i = 0; i < num; i++) {
        s.push_back('\t');
    }
    return s;
}

void JsonFormatter::parserJsonBlank() {
    jsonFormat.clear();
    int tapCount = 0;
    int i = 0;
    int flag = 0;
    while (i < jsonBlank.size()) {
        // cout << jsonFormat << endl;
        if (jsonBlank[i] == '{' || jsonBlank[i] == '[') {
            if (flag == 0) jsonFormat.append(tap(tapCount));
            jsonFormat.push_back(jsonBlank[i]);
            jsonFormat.push_back('\n');
            tapCount++;
            flag = 0;
            i++;
        } else if (jsonBlank[i] == ']' || jsonBlank[i] == '}') {
            tapCount--;
            jsonFormat.append(tap(tapCount));
            jsonFormat.push_back(jsonBlank[i]);
            if (jsonBlank[i + 1] == ',') {
                jsonFormat.push_back(',');
                i++;
            }
            jsonFormat.push_back('\n');
            flag = 0;
            i++;
        } else if (jsonBlank[i] == '\"' && flag == 0) {  // 说明是标签
            jsonFormat.append(tap(tapCount));
            jsonFormat.push_back(jsonBlank[i++]);
            while (jsonBlank[i] != '\"') {
                jsonFormat.push_back(jsonBlank[i++]);
            }
            jsonFormat.push_back(jsonBlank[i++]);
            if (jsonBlank[i] == ':') {
                jsonFormat.append(": ");
            } else if (jsonBlank[i] == ',') {
                jsonFormat.append(", ");
            }
            i++;
            flag = 1;
        } else if (jsonBlank[i] == '\"' && flag == 1) {  // 字符数据
            jsonFormat.push_back(jsonBlank[i++]);
            while (jsonBlank[i] != '\"') {
                jsonFormat.push_back(jsonBlank[i++]);
            }
            jsonFormat.push_back(jsonBlank[i++]);
            // 消除不合理的末尾 ]}不换行
            if (jsonBlank[i] == ']' || jsonBlank[i] == '}') {
                jsonFormat.push_back('\n');
            }
            flag = 0;
        } else if (isdigit(jsonBlank[i]) && flag == 1) {  // 数字数据
            while (isdigit(jsonBlank[i])) {
                jsonFormat.push_back(jsonBlank[i++]);
            }
            // 消除不合理的末尾 ]}不换行
            if (jsonBlank[i] == ']' || jsonBlank[i] == '}') {
                jsonFormat.push_back('\n');
            }
            flag = 0;
        } else if (isalpha(jsonBlank[i]) && flag == 1) {  // true false
            while (isalpha(jsonBlank[i])) {
                jsonFormat.push_back(jsonBlank[i++]);
            }
            // 消除不合理的末尾 ]}不换行
            if (jsonBlank[i] == ']' || jsonBlank[i] == '}') {
                jsonFormat.push_back('\n');
            }
            flag = 0;
        } else if (isalpha(jsonBlank[i]) && flag == 0) {  // null
            jsonFormat.append(tap(tapCount));
            while (isalpha(jsonBlank[i])) {
                jsonFormat.push_back(jsonBlank[i++]);
            }
            flag = 0;
        } else if (jsonBlank[i] == ',') {
            jsonFormat.append(",\n");
            flag = 0;
            i++;
            cout << "dadadasad" << endl;
        }
    }
}

void JsonFormatter::save() {
}
void JsonFormatter::saveAs(string filePath) {
    ofstream fout;
    fout.open(filePath.c_str(), ios::out | ios::trunc);  // 覆盖写
    if (!fout.is_open()) {
        cout << "cannot open the file" << endl;
    }
    for (int i = 0; i < jsonFormat.size(); i++) {
        fout.put(jsonFormat[i]);
    }
    fout.close();
    cout << "saveAs file success!" << endl;
}
