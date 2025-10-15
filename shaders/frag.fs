#version 330 core

out vec4 FragColor;

uniform vec2 resolution;
uniform float time;

// Simple 2D hash function for pseudo-random values
float random(vec2 p) {
    return fract(sin(dot(p.xy, vec2(12.9898,78.233))) * 43758.5453);
}

// Wavy color distortion based on position and time
void main() {
    // Normalize pixel coordinates to [0,1]
    vec2 uv = gl_FragCoord.xy / resolution;

    // Center UV and apply aspect ratio correction
    vec2 centerUV = uv - 0.5;
    centerUV.x *= resolution.x / resolution.y;

    // Animate distortion
    float wave = sin(centerUV.y * 10.0 + time * 2.0) * 0.05;
    centerUV.x += wave;

    // Length from center
    float dist = length(centerUV);

    // Color gradients modulated by time and distance
    float r = 0.5 + 0.5 * cos(time + dist * 8.0);
    float g = 0.5 + 0.5 * cos(time * 1.2 + dist * 10.0 + 2.0);
    float b = 0.5 + 0.5 * cos(time * 1.7 + dist * 6.0 + 4.0);

    // Add subtle flicker using pseudo-random noise
    float flicker = 0.02 * random(uv * time * 10.0);

    FragColor = vec4(r + flicker, g + flicker, b + flicker, 1.0);
}
