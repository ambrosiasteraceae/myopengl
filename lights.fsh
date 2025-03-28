#version 330 core

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct Light {
    vec3 position; // used in flashlight / spot lights 
    vec3 direction; // used in flashlight / spot lights 
    float cutOff;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

uniform Light light;
uniform Material material;
uniform vec3 viewPos;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;




out vec4 FragColor;
void main()
{

 
   vec3 lightDir = normalize(light.position - FragPos);

   float theta = dot(lightDir, normalize(-light.direction));

   if (theta > light.cutOff)
   {
    //ambient
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
     
     //diffuse
    vec3 norm = normalize(Normal);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;

    //specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;

    float distance = length(light.position - FragPos);
    float attenuation = 1/ (light.constant + light.linear * distance + light.quadratic * distance * distance);

    vec3 result =  (ambient + diffuse + specular) * vec3(attenuation);

    FragColor = vec4(result, 1.0);
   }
   else
   {
   FragColor = vec4(light.ambient * vec3(texture(material.diffuse, TexCoords)),1.0);
   }
   
   

}
