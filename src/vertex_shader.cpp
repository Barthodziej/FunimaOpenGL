#include "vertex_shader.hpp"
#include "shader_utils.hpp"
#include <glad/glad.h>

vertex_shader::vertex_shader(unsigned int id)
    : id(id) {}

vertex_shader::vertex_shader(vertex_shader&& other)
    : id(other.id) {
    other.id = 0;
}

vertex_shader& vertex_shader::operator=(vertex_shader&& other) {
    if (this == &other) {
        return *this;
    }
    glDeleteShader(id);
    this->id = other.id;
    other.id = 0;
    return *this;
}

vertex_shader::~vertex_shader() {
    glDeleteShader(id);
}

std::expected<vertex_shader, std::string> vertex_shader::from_code(std::string code) {
    auto compilation_result = compile_shader(code, GL_VERTEX_SHADER);
    if (!compilation_result) {
        return std::unexpected(compilation_result.error());
    }
    else {
        return vertex_shader(compilation_result.value());
    }
}

unsigned int vertex_shader::get_id() const {
    return id;
}
