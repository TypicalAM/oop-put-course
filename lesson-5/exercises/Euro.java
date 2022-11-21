public class Euro implements Currency {

	private float value;

	// Convert the foreign currency into euro and return a new object with the added
	// value of the new currency
	@Override
	public Euro addedCurrency(float value, String currency) {
		float newCurrencyValue = value / new FakeCantor().euroToRate(currency);
		return new Euro(this.value + newCurrencyValue);
	}

	// Convert the foreign currency into euro and return a new object with the
	// subtracted value or 0 if the subtracted value is more than the available
	// balance
	@Override
	public Euro subtractedCurrency(float value, String currency) {
		float newCurrencyValue = value / new FakeCantor().euroToRate(currency);
		if (this.value - newCurrencyValue < 0) {
			throw new NoMoneyException("No money left in this account", null);
		}
		return new Euro(this.value - newCurrencyValue);
	}

	@Override
	public String abbreviation() {
		return "EUR";
	}

	@Override
	public String symbol() {
		return "€";
	}

	@Override
	public String balance() {
		return String.format("%.2f", this.value);
	}

	@Override
	public float toDollarExchangeRate() {
		return new FakeCantor().euroToRate("USD");
	}

	public Euro(float value) {
		this.value = value;
	}
}
