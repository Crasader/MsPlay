
varying vec4 v_fragmentColor;	
varying vec2 v_texCoord;	
		
void main()			
{
	vec4 col = texture2D(CC_Texture0, v_texCoord);  
	float plus = 0.3 * col.a; 
	float r = col.r + plus > 1.0 ? 1.0 : col.r + plus; 
	float g = col.g + plus > 1.0 ? 1.0 : col.g + plus;
	float b = col.b + plus > 1.0 ? 1.0 : col.b + plus;
	gl_FragColor = vec4(r, g, b, col.a);
}		
