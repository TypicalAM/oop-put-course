
public class NoMoneyException extends RuntimeException {
	public NoMoneyException(String errorMessage, Throwable err) {
		super(errorMessage, err);
	}
}
