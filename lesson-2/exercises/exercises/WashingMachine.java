package exercises;

import java.util.Calendar;

public class WashingMachine {
	String model;
	int year;

	public WashingMachine(String model) {
		this.model = model;
		this.year = Calendar.getInstance().get(Calendar.YEAR);
	}
	
	public WashingMachine(String model, int year) {
		this.model = model;
		this.year = year;
	}
	
	void MakeSound() {
		System.out.println("WRUUMMMMMMMMMMMMMMMMMMMMMMMM\n WRUMMMMMMMMMMMMMMMMMM\nI'm from "+this.year);
	}
}
