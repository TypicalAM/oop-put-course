
public class Ingredient implements Model {
	private final int primaryKey;
	private final double fatsAmount;
	
	@Override
	public Ingredient valueModifier(double value) {
		return new Ingredient(this.primaryKey, fatsAmount+value);
	}

	@Override
	public Ingredient pkSetter(int newPrimaryKey) {
		return new Ingredient(newPrimaryKey, this.fatsAmount);
	}

	@Override
	public String serializeValue() {
		return String.format("{\"pk\": \"%d\", \"fats_amount\": \"%f\"}", this.primaryKey,this.fatsAmount);
	}
	
	public Ingredient(int pk, double fatsPercentage) {
		this.primaryKey = pk; // Here should be some db logic like db.newRecord().key
		this.fatsAmount = fatsPercentage;
	}
	
	public static void main(String[] args) {
		Ingredient tomato = new Ingredient(0, 0.09);
		Ingredient fatTomato = tomato.valueModifier(0.50); // 50% fatter - The American Dream
		Ingredient fatTomatoBreakingMyDatabase = fatTomato.pkSetter(5);
		System.out.println(fatTomatoBreakingMyDatabase.serializeValue());
	}
}
