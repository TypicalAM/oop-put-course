import java.time.LocalDate;

public class Weather {

	private LocalDate date;
	private Forecast forecast;
	private TemperatureUnit unit;
	
	public float temperature() {
		return forecast.temperature(this.date, this.unit);
	}
	
	public Weather(Forecast forecast, TemperatureUnit unit, String date) {
		this.unit = unit;
		this.forecast = forecast;
		this.date = LocalDate.parse(date);
	}

}
