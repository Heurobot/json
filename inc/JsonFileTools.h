#ifndef  JSONFILETOOLS_H
#define JSONFILETOOLS_H

#include<iostream>  //c++ 的输入输出
#include<fstream>   //c++ 文件处理库
#include<sstream>   //c++ 字符流
#include<string>    //std::string
#include<json/json.h>  //json头文件

class JsonFileTools
{
private:
    Json::CharReaderBuilder rbuilder;
    Json::Value  root;
    /* data */
public:
    JsonFileTools(/* args */);
    ~JsonFileTools();
    
    Json::Value readJsonFile(const std::string & filename);




};




#endif