Getters and setters lead to converting classes to structs (on a fundamental level)

GetDollars should rather be called value() or balance() because thats a noun
SetDollars should rather be called balanceChanger because thats a verb

This is fine :

```java
class Temperature {
	private int t;
	public String toString() {
		return String.format("%d F", this.t); 
	}
}
```

I guess it boils down to the words that you use:

GetDatetime() -> time()
GetMyMom() -> mojastara() - nouns

GetSandwitch().Cheese().Well()
