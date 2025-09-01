#include "../inc/JsonFileTools.h"
#include <json/json.h>
#include <cassert>

JsonFileTools::JsonFileTools(/* args */)
{
}

JsonFileTools::~JsonFileTools()
{
}

// 读取json文件
Json::Value JsonFileTools::readJsonFile(const std::string &filename)
{

    std::ifstream ifs;
    if (!ifs.is_open())
    {
        ifs.open(filename);
    }

    std::string errs;
    bool parsingSuccessful = Json::parseFromStream(rbuilder, ifs, &root, &errs);
    if (!parsingSuccessful)
    {
        // report to the user the failure and their locations in the document.
        std::cout << "Failed to parse configuration\n"
                  << errs;
        return Json::Value();
    }
    ifs.clear();
    ifs.close();
    return root; // 类的属性私有
}