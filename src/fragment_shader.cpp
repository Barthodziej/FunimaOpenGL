#include "fragment_shader.hpp"
#include "shader_utils.hpp"
#include <glad/glad.h>

fragment_shader::fragment_shader(unsigned int id)
    : id(id) {}

fragment_shader::fragment_shader(fragment_shader&& other)
    : id(other.id) {
    other.id = 0;
}

fragment_shader& fragment_shader::operator=(fragment_shader&& other) {
    if (this == &other) {
        return *this;
    }
    glDeleteShader(id);
    this->id = other.id;
    other.id = 0;
    return *this;
}

fragment_shader::~fragment_shader() {
    glDeleteShader(id);
}

std::expected<fragment_shader, std::string> fragment_shader::from_code(std::string code) {
    auto compilation_result = compile_shader(code, GL_FRAGMENT_SHADER);
    if (!compilation_result) {
        return std::unexpected(compilation_result.error());
    }
    else {
        return fragment_shader(compilation_result.value());
    }
}

unsigned int fragment_shader::get_id() const {
    return id;
}
