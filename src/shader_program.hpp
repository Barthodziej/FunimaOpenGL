#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP

#include "vertex_shader.hpp"
#include "fragment_shader.hpp"

#include <expected>
#include <string>

class shader_program {
    unsigned int id;
    shader_program(unsigned int id);
public:
    shader_program(const shader_program& other) = delete;
    shader_program& operator=(const shader_program& other) = delete;
    shader_program(shader_program&& other);
    shader_program& operator=(shader_program&& other);
    ~shader_program();
    static std::expected<shader_program, std::string> construct(const vertex_shader& v_shader, const fragment_shader& f_shader);
    unsigned int get_id() const;
};

#endif //SHADER_PROGRAM_HPP
