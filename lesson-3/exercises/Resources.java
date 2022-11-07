import java.io.File;

public class Resources {
	private final String resourcePath;

	Resources(String path) {
		this.resourcePath = path;
	}

	public Boolean exists() {
		return new File(this.resourcePath).isDirectory();
	}
}
