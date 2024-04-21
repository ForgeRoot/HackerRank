#include <file_reader.hpp>

FileReader::FileReader(std::string input_filename): 
    input_filename_(input_filename)
{}

void FileReader::loadLinesFromFile(){
    openFileStream();
    loadContentsFromOpenFileStream();
    closeFileStream();
}

    void FileReader::openFileStream(){
        file_stream_.open(input_filename_);
        if (!file_stream_.is_open())
            std::cerr << "Error opening file: " << input_filename_ << std::endl;
    }

    void FileReader::loadContentsFromOpenFileStream(){
        std::string line;
        while (getline(file_stream_, line))
            contents_.push_back(line);
    }

    void FileReader::closeFileStream(){
        file_stream_.close();
    }

std::vector<std::string> FileReader::getContents() const{
    return contents_;
}
// void FileReader::readNumberOfFromFile(){
//     file_stream_.open(input_filename_);
//     if (!file_stream_.is_open())
//     else { 
//         file_stream_ >> number_of_hrml_lines_ >> number_of_queries_;
//         file_stream_.close();
//     }
// }

// std::vector<std::string> FileReader::clusterLinesFromFile(int number_of_lines){
//     std::vector<std::string> return_value;
//     file_stream_.open(input_filename_);
//     for (int i = 0; i < number_of_lines; i++)
//         std::getline(file_stream_, return_value[i]);
//     file_stream_.close();
//     return return_value;
// }