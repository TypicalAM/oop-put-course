package exercises;

public class RfidScanner {
	int scannerState;
	String beeperSound;

	public RfidScanner() {
		this.scannerState = 0;
		this.beeperSound = "normal beep unfortunately";
	}

	public RfidScanner(String customBeeperSound) {
		this.scannerState = 0;
		this.beeperSound = customBeeperSound;
	}

	void Approach(CreditCard card) {
		System.out.println(this.beeperSound);
		System.out.println("I've been approached with a credit card with the number " + card.cardNum);
	}

	boolean CheckCardStolen(CreditCard card) {
		if (card.expiredateStr.isEmpty()) {
			return true;
		}
		return false;
	}

	boolean CardDemagnetizer(CreditCard card) {
		if (CheckCardStolen(card)) {
			// Demag the card and remove its fields
			card.cardNum = 0;
			card.cvv = 0;
			card.expiredateStr = "Swiper no swiping";
			return true;
		}
		return false;
	}
}