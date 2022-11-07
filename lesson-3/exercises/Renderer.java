
public class Renderer {
	private final Boolean isSDL;
	
	Renderer(Boolean isSDL) {
		this.isSDL = isSDL;
	}
	
	public String renderType() {
		return this.isSDL ? "SDL" : "Raylib";
	}
}
