# include "../headers/file_handler.h"

FileHandler::FileHandler() {

}

FileHandler::~FileHandler() {

}

std::string FileHandler::GetInfoFromFile(std::string Path) {
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

std::string FileHandler::ModifyFile(std::string Path, std::string Input) {
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

std::vector<int> FileHandler::GetInfoCoins(std::string Path) {
    std::vector<int> result;
    std::vector<std::string> output;
    std::string from_file;

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
// TODO All functions should take full path to target file
bool FileHandler::CheckIfFileExists(std::string PathToFile) {
    std::fstream File;
    File.open(PathToFile, std::ios::in);

    if(File.good() == false) {
        File.close();
        return false;
    }
    File.close();
    return true;
}