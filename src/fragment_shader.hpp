#ifndef FRAGMENT_SHADER_HPP
#define FRAGMENT_SHADER_HPP

#include <expected>
#include <string>

class fragment_shader {
    unsigned int id;
    fragment_shader(unsigned int id);
public:
    fragment_shader(const fragment_shader& other) = delete;
    fragment_shader& operator=(const fragment_shader& other) = delete;
    fragment_shader(fragment_shader&& other);
    fragment_shader& operator=(fragment_shader&& other);
    ~fragment_shader();
    static std::expected<fragment_shader, std::string> construct(std::string code);
    unsigned int get_id() const;
};

#endif //FRAGMENT_SHADER_HPP
