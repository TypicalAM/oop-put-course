
public class Application {

	public static void main(String[] args) {
		Forecast fakeForecast = new Forecast.Fake();
		Weather myWeather = new Weather(fakeForecast, TemperatureUnit.CELCIUS, "2022-12-12");
		assert "37".equals(Float.toString(myWeather.temperature()));
	}

}
