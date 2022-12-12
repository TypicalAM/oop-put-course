import java.time.LocalDate;

public interface Forecast {
	float temperature(LocalDate date, TemperatureUnit unit);

	final class Fake implements Forecast {
		@Override
		public float temperature(LocalDate date, TemperatureUnit unit) {
			return 37.5f;
		}
	}
}
