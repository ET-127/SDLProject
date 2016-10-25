#version 140

in vec2 fragmentPosition;

//The fragment shader operates on each pixel in a given polygon
in vec4 fragmentColor;
//This is the 3 component float vector that gets outputted to the screen
//for each pixel.
out vec4 color;

uniform float time;

void main() {
    //Change color based on position
    color = vec4(fragmentColor.r * (cos(fragmentPosition.x * 5.0 + time) + 1.0) / 2,
                 fragmentColor.g * (cos(fragmentPosition.y * 10.0 + time) + 1.0) / 2,
                 fragmentColor.b * (cos(fragmentPosition.x * 2.0 + time) + 1.0) / 2,
                 fragmentColor.a);
    
}