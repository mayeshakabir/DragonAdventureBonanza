#version 330

uniform sampler2D screen_texture;
uniform vec2[10] lights;
uniform mat4 transform;
uniform mat3 projection;
uniform int numLights;
uniform vec2 player;

in vec2 vpos;

layout(location = 0) out vec4 color;

void main()
{
    color = vec4(0.0, 0.0, 0.0, 0.9);
    float lightDist = 1000;
    for (int i = 0; i < 10; i++) {
        float radius = distance((projection * vec3(lights[i], 1.0)).xy * vec2(12.0/8.0, 1.0), vec2(vpos.x*(12.0/8.0), vpos.y));
        float dist = distance((projection * vec3(lights[i], 1.0)).xy * vec2(12.0/8.0, 1.0), (projection * vec3(player, 1.0)).xy * vec2(12.0/8.0, 1.0));
        if (dist < lightDist){
            lightDist = dist;
        }
        if (radius < 1.0) {
            color.xyz += (1.0 - radius) * 0.6 * vec3(1.0, 0.7, 0.0);
            color.a = 0.5 + radius*(0.4);
//        } else {
//            float dist = distance((projection * vec3(lights[i], 1.0)).xy, (projection * vec3(player, 1.0)).xy);
//            if (dist > 1.5) {
//                float radius = distance((projection * vec3(player, 1.0)).xy * vec2(12.0/8.0, 1.0), vec2(vpos.x*(12.0/8.0), vpos.y));
//                if(radius < 0.5) {
//                    color = vec4(0.0, 0.0, 0.0, radius + 0.2);
//                }
//            }

        }
        if (i == numLights)
            break;

    }
    if (lightDist > 1.5) {
        float radius = distance((projection * vec3(player, 1.0)).xy * vec2(12.0/8.0, 1.0), vec2(vpos.x*(12.0/8.0), vpos.y));
        if(radius < 0.5) {
            color = vec4(0.0, 0.0, 0.0,0.2+radius*(1.4));
        }
    }
}
