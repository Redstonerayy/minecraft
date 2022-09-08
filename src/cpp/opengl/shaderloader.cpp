#include "shaderloader.hpp"

ShaderLoader::ShaderLoader(std::vector<std::string> directories, std::vector<std::string> paths){
	// get all filepaths for each directory
    // check if the file ends on .glsl
    // for glsl files starting with "ver" compile to VERTEX_SHADER
    // else compile to FRAGMENT_SHADER
    for(int i = 0; i < directories.size(); ++i){
		std::vector<std::string> filepaths = Utils::getFilePathsInDirectory(directories[i]);
		for(int j = 0; j < filepaths.size(); ++j){
			if(Utils::getFileExtensionFromPath(filepaths[j]) == ".glsl"){
                std::string filename = Utils::getFileNameFromPath(filepaths[j]);
                if(filename.substr(0,3) == "ver"){
                    std::cout << "ver" << "\n";
                    this->shaders.emplace_back(Shader(GL_VERTEX_SHADER, filepaths[j].c_str(), filename));
                } else {
                    this->shaders.emplace_back(Shader(GL_FRAGMENT_SHADER, filepaths[j].c_str(), filename));
                    std::cout << "fra" << "\n";
                }
			}
		}
	}
}
