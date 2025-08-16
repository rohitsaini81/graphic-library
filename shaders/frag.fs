 #version 330 core
    out vec4 FragColor;
    uniform vec2 resolution;
    uniform float time;
    float random(vec2 p) {
    return fract(sin(time * 2.0) * 0.5 + 0.5);


    }

    void main() {
        vec2 uv = gl_FragCoord.xy / resolution.xy;

    // Random values for each color channel
    float r = sin(time * 2.0) * 0.5 + 0.5; // Range 0..1
    float g = sin(time * 0.7 + 2.0) * 0.5 + 0.5;
    float b = sin(time * 1.3 + 4.0) * 0.5 + 0.5;

    FragColor = vec4(r, g, b, 1.0);
    // FragColor = vec4(randValue, randValue, 0.3, 1.0);
    }