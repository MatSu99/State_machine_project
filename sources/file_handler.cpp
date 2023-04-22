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

std::string FileHandler::ModifyFile(std::string NameOfFile) {
    return "NOT IMPLEMENTED";
}