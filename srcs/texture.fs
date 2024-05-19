#version 330 core
out vec4 FragColor;

in vec3 pos;

void main() {
    if (pos.y >= 0) {
        FragColor = vec4(0.2, 0.5, 0.3, 1.0);
    } else {
        FragColor = vec4(0.5, 0.2, 0.3, 1.0);
    }
}
