#version 330 core
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

struct Light {
    vec3 direction;
    bool isDirectional;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

uniform Light light;

struct Material {
    vec3 specular;
    float shininess;
}; 
  
uniform Material material;
uniform sampler2D texture0;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

out vec4 FragColor;

void main()
{
    float ambientStrength = 0.3;
    vec3 ambient = light.ambient * vec3(texture(texture0, TexCoord));
    
    vec3 norm = normalize(Normal);
    vec3 lightDir;
    if(light.isDirectional){
        lightDir = normalize(-light.direction);
    } else {
        lightDir = normalize(light.direction - FragPos);
    }
    
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(texture0, TexCoord));

    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * material.specular; 

    float distance    = length(light.direction - FragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
    		            light.quadratic * (distance * distance));
    
    ambient  *= attenuation; 
    diffuse  *= attenuation;
    specular *= attenuation;

    FragColor = texture2D(texture0, TexCoord) * vec4(ambient + diffuse + specular, 1.0f);
}
