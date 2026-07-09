#include "shader_utils.hpp"

std::expected<unsigned int, std::string> compile_shader(std::string code, GLenum type) {
    const char* shader_c_str = code.c_str();
    unsigned int shader_id = glCreateShader(type);
    glShaderSource(shader_id, 1, &shader_c_str, NULL);
    glCompileShader(shader_id);
    int success;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info_log[512];
        glGetShaderInfoLog(shader_id, 512, NULL, info_log);
        return std::unexpected(info_log);
    }
    return shader_id;
}
