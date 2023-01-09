
public class Main {

	public static void main(String[] args) {
		// First game
		Shiritori game = new Shiritori();
		System.out.println(game.play("blanket")); 
		System.out.println(game.play("terracotta"));
		System.out.println(game.play("andesite"));
		System.out.println(game.play("errands"));
		System.out.println(game.play("isthisevenaword")); // fail, the characters don't match
		
		// Second game
		System.out.println(game.restart());
		System.out.println(game.play("abacus"));
		System.out.println(game.play("sus"));
		System.out.println(game.play("salsa"));
		System.out.println(game.play("abacus")); // fail, the word is not unique
	}
}
