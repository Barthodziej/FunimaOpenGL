#ifndef SHADER_UTILS_HPP
#define SHADER_UTILS_HPP

#include <string>
#include <expected>
#include <glad/glad.h>

std::expected<unsigned int, std::string> compile_shader(std::string code, GLenum type); 

#endif //SHADER_UTILS_HPP
