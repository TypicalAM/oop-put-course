
public class Title {
	private final String englishTitle;
	private final String arabicTitle;
	
	Title(String englishTitle, String arabicTitle) {
		this.englishTitle = englishTitle;
		this.arabicTitle = arabicTitle;
	}
	
	public String title(String i18nCode) {
		return i18nCode.equals("en") ? this.englishTitle : this.arabicTitle;
	}
}
