
public class Game {
	private final ORM orm;
	private final Title title;
	private final Renderer renderer;
	private final Resources resources;

	Game(ORM orm, Title title, Renderer renderer, Resources resources) {
		this.orm = orm;
		this.title = title;
		this.renderer = renderer;
		this.resources = resources;
	}

	public String toString() {
		return String.format("ORM port: %s\nEng Title: %s\nRenderertype: %s\nResources exist: %b", this.orm.portValue(), this.title.title("en"), this.renderer.renderType(), this.resources.exists());
	}
	
	public static void main(String[] args) {
		ORM ORMRedis = new ORM("redis");
		Title title = new Title("My little mines game","رحمهم الله");
		Renderer renderer = new Renderer(true);
		Resources resources = new Resources("resources");
		Game game = new Game(ORMRedis, title, renderer, resources);
		System.out.println(game);
	}
}
