#include "../head/JsonParser.h"

JsonParser::JsonParser(string filePath) {
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
    removeBlank();
    parserJsonBlank();
}
JsonParser::JsonParser() {
    path = "";
}
// 去掉所有空白符
void JsonParser::removeBlank() {
    jsonBlank.clear();
    for (int i = 0; i < json.size(); i++) {
        // 非空白符
        if (!(isblank(json[i]) || json[i] == '\n')) {
            jsonBlank.push_back(json[i]);
        }
    }
}
void JsonParser::parserJsonBlank() {
    // jsonFormat.clear();
    // for (int i = 0; i < jsonBlank.size(); i++) {
    // }
}
string JsonParser::getJson() {
    return json;
}
string JsonParser::getJsonBlank() {
    return jsonBlank;
}
string JsonParser::getJsonFormat() {
    return jsonFormat;
}
string JsonParser::getPath() {
    return path;
}
void JsonParser::setPath(string filePath) {
    (*this) = JsonParser(filePath);
}
