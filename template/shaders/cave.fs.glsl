#version 330

uniform sampler2D screen_texture;
uniform vec2[10] lights;
uniform mat4 transform;
uniform mat3 projection;
uniform int numLights;

in vec2 vpos;

layout(location = 0) out vec4 color;

void main()
{
    color = vec4(0.0, 0.0, 0.0, 0.7);
    for (int i = 0; i < 10; i++) {
        float radius = distance((projection * vec3(lights[i], 1.0)).xy * vec2(12.0/8.0, 1.0), vec2(vpos.x*(12.0/8.0), vpos.y));
        if (radius < 1.0) {
            color.xyz += (1.0 - radius) * 0.6 * vec3(1.0, 0.7, 0.0);
        }
        if (i == numLights)
            break;

    }
}
