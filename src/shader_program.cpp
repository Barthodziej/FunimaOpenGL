#include "shader_program.hpp"
#include <glad/glad.h>

shader_program::shader_program(unsigned int id)
    : id(id) {}

shader_program::shader_program(shader_program&& other)
    : id(other.id) {
    other.id = 0;
}

shader_program& shader_program::operator=(shader_program&& other) {
    if (this == &other) {
        return *this;
    }
    glDeleteShader(id);
    this->id = other.id;
    other.id = 0;
    return *this;
}

shader_program::~shader_program() {
    glDeleteShader(id);
}

std::expected<shader_program, std::string> shader_program::construct(const vertex_shader& v_shader, const fragment_shader& f_shader) {
    unsigned int shader_program_id = glCreateProgram();
    glAttachShader(shader_program_id, v_shader.get_id());
    glAttachShader(shader_program_id, f_shader.get_id());
    glLinkProgram(shader_program_id);
    return shader_program(shader_program_id);
}

unsigned int shader_program::get_id() const {
    return id;
}
