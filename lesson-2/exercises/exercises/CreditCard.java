package exercises;

public class CreditCard {
	int cvv;
	long cardNum;
	String expiredateStr;

	public CreditCard(int cvv, long cardNum, String expired) {
		this.cvv = cvv;
		this.cardNum = cardNum;
		this.expiredateStr = expired;
	}

	public CreditCard(int cvv, long cardNum) {
		this.cvv = cvv;
		this.cardNum = cardNum;
		this.expiredateStr = "";
	}
}