
precision mediump float;	// Precisión media

varying vec4 v_Color;		// in: color del vertex shader
varying vec2 v_UV;

uniform sampler2D u_TextureUnit;

void main()
{

    		gl_FragColor = v_Color + texture2D(u_TextureUnit, v_UV);
    		//gl_FragColor = mix(texture2D(u_TextureUnit, v_UV), v_Color, 0.7);

}
