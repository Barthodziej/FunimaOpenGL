#ifndef VERTEX_SHADER_HPP
#define VERTEX_SHADER_HPP

#include <expected>
#include <string>

class vertex_shader {
    unsigned int id;
    vertex_shader(unsigned int id);
public:
    vertex_shader(const vertex_shader& other) = delete;
    vertex_shader& operator=(const vertex_shader& other) = delete;
    vertex_shader(vertex_shader&& other);
    vertex_shader& operator=(vertex_shader&& other);
    ~vertex_shader();
    static std::expected<vertex_shader, std::string> construct(std::string code);
    unsigned int get_id() const;
};

#endif //VERTEX_SHADER_HPP
