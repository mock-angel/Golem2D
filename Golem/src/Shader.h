/*
 * Shader.h
 *
 *  Created on: 02-Jun-2020
 *      Author: anantha
 */

#ifndef SHADER_H_
#define SHADER_H_

namespace Golem {

class Shader {
public:
    //Shader(const char* vertexPath, const char* fragmentPath);
    Shader(std::string  vertexPath, std::string  fragmentPath);

    virtual ~Shader();

    void use();
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

private:
    unsigned int ID;

    void checkCompileErrors(unsigned int shader, std::string type);

};

} /* namespace Golem */

#endif /* SHADER_H_ */
