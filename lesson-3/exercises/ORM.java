
public class ORM {

	private final String databasePath;
	private final int port;
	
	ORM(String path) {
		this.databasePath = path;
		this.port = (this.databasePath.equals("redis")) ? 6379 : 8000;
	}
	
	public String portValue() {
		return Integer.toString(port);
	}
}

