//example from https://en.wikibooks.org/wiki/JsonCpp
//modified due to the class Json::Reader is deprecated

#include <iostream>
#include <fstream>
#include <json/json.h>

std::string getStringFromStream(std::ifstream &stream)
{
    return std::string((std::istreambuf_iterator<char>(stream)),
                         std::istreambuf_iterator<char>());
}

const char* getPointerFromString(const std::string &string)
{
    return string.c_str();
}

void print(Json::Value jsonValues)
{
    std::cout << "Book: " << jsonValues["book"].asString() << std::endl;
    std::cout << "Year: " << jsonValues["year"].asUInt()   << std::endl;
    const Json::Value& characters = jsonValues["characters"];
    for (int i = 0; i < characters.size(); i++) {
        std::cout << "    name: " << characters[i]["name"].asString();
        std::cout << " chapter: " << characters[i]["chapter"].asUInt();
        std::cout << std::endl;
    }
}

int main()
{
    std::string path = JSONPATH;
    std::string jsonFilePath = path + "/alice.json";
    std::ifstream jsonStream = std::ifstream(jsonFilePath);

    std::string jsonFile = getStringFromStream(jsonStream);
    const char* beginDoc = getPointerFromString(jsonFile);
    const char* endDoc = beginDoc + jsonFile.size();

    Json::CharReader* reader = Json::CharReaderBuilder().newCharReader();

    Json::Value jsonValues;
    std::string errors;

	reader->parse(beginDoc, endDoc, &jsonValues, &errors);

    print(jsonValues);

    delete reader;
}