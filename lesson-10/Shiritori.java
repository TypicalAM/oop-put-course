import java.util.ArrayList;

final public class Shiritori {
	private ArrayList<String> words;
	private Boolean gameOver;
	
	private Boolean validSequence() {
		if (words.size() == 1) {
			return true;
		}
		
		String lastWord = words.get(words.size() - 1);
		
		for (int i=0;i<words.size()-1;i++) {
			if (words.get(i).equals(lastWord)) {
				return false;
			}
		}
		
		String secondToLastWord = words.get(words.size() - 2);
		
		return (secondToLastWord.charAt(secondToLastWord.length()-1) == lastWord.charAt(0));
	}
	
	public String play(String word) {
		if (gameOver) {
			return "The game is already over, why cry over spilt milk?";
		}
		
		words.add(word);
		if (!validSequence()) {
			gameOver = true;
			return "The last word you played didn't match, you lost the game... Are you proud of yourself?";
		}
		
		return String.format("You have played %s. %s", word, this.printWords());
	}
	
	public String restart() {
		words = new ArrayList<String>();
		gameOver = false;
		return "The game has been restarted, have fun!";
	}
	
	public String printWords() {
		return String.format("The game is going as follows: %s", String.join(" -> ", words));
	}
	
	public Shiritori() {
		words = new ArrayList<String>();
		gameOver = false;
	}
}
