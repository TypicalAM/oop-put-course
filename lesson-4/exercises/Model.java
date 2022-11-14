
public interface Model {
	Model valueModifier(double value);
	Model pkSetter(int newPrimaryKey); // I know we shouldn't do this....
	String serializeValue();
}
