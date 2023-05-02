# include "../headers/file_handler.h"

FileHandler::FileHandler() {

}

FileHandler::~FileHandler() {

}

std::string FileHandler::GetInfoFromFile(std::string NameOfFile) {
    std::string Path = "../res/";
    Path += NameOfFile;
    std::fstream File;
    File.open(Path, std::ios::in);

    if(File.good() == false) {
        // ! ERROR
        return "-1";
    }

    std::string from_file;
    std::string output;
    while(getline(File, from_file)) {
        output += from_file;
    }

    File.close();
    return output;
    
}

std::string FileHandler::ModifyFile(std::string NameOfFile, std::string Input) {
    std::string Path = "../res/";
    Path += NameOfFile;
    std::ofstream File;
    File.open(Path, std::ios::out);

    if(File.good() == false) {
    // ! ERROR
    return "result";
    }

    File << Input;
    File.close();

    // TODO Change probably to bool
    return "DONE";
}

std::vector<int> FileHandler::GetInfoCoins(std::string NameOfFile) {
    std::vector<int> result;
    std::vector<std::string> output;
    std::string from_file;
    std::string Path = "../res/";
    Path += NameOfFile;
    std::fstream File;
    File.open(Path, std::ios::in);

    if(File.good() == false) {
        // ! ERROR
        return result;
    }

    while(getline(File, from_file)) {
        result.push_back(std::stoi(from_file));
    }

    File.close();
    return result;

}