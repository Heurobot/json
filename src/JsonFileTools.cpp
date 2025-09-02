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

void JsonFileTools::WriteFileJson(std::string filePath)
{
	// 写入下列指定内容
	// Json::Value root;
	// root["name"] = Json::Value("Cain");
	// root["sex"] = Json::Value("man");
	// root["age"] = Json::Value(23);

	// // 数组形式
	// root["hobby"].append("Run");
	// root["hobby"].append("Sing");
	// root["hobby"].append("Dance");

	// Json::Value Sub;
	// // 子节点属性
	// Sub["subject1"] = Json::Value("C++");
	// Sub["subject2"] = Json::Value("Java");
	// Sub["subject3"] = Json::Value("Go");

	// // 将子节点内容挂到父节点(root)上
	// root["major"] = Json::Value(Sub);

	/* 测试内容：会在屏幕输出 */
	Json::Value root(Json::arrayValue);
	

	for (const auto &items : Msgarray)
	{
		Json::Value temp;

		temp["ComponentName"] = Json::Value(items.ComponentName);
		temp["ComponentInstance"] = Json::Value(items.ComponentInstance);
		temp["VariableName"] = Json::Value(items.VariableName);
		temp["VariableInstance"] = Json::Value(items.VariableInstance);
		temp["AttributeType"] = Json::Value(items.AttributeType);
		temp["AttributeValue"] = Json::Value(items.AttributeValue);
		temp["Mode"] = Json::Value(items.Mode);
		temp["ValueList"] = Json::Value(items.ValueList);
		temp["DataType"] = Json::Value(items.DataType);
		temp["Private"] = Json::Value(items.Private);
		temp["ValueRange"] = Json::Value(items.ValueRange);
		temp["Unit"] = Json::Value(items.Unit);
		root.append(temp);
	}
	std::cout << "styledwriter: " << std::endl;
	Json::StyledWriter sw;
	std::cout << sw.write(root) << std::endl;

	std::fstream os;
	os.open(filePath, std::ios::out | std::ios::app);
	if (!os.is_open())
	{
		std::cout << "Error: can not find or create the file which named " << filePath << std::endl;
	}
	else
	{
		std::cout << "successful: file write is success! " << std::endl;
	}

	os << sw.write(root);
	os.close();
}
