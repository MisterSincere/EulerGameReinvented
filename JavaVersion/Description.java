import java.io.Serializable;


public class Description implements Serializable {
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	private static final long serialVersionUID = 6762654757525436318L;
	private String defaultDescription = "";
	private String exploreDescription = "";
	private String alreadyExploredDescription = "";		// Wenn der Raum schon untersucht wurde wird diese Beschreibung anstatt der default angezeigt
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	
	/*****************************ANFANG KONSTRUKTOREN*************************************/
	public Description() {}
	
	public Description(String defaultDescription) {
		this.defaultDescription = defaultDescription;
	}
	/*****************************ENDE KONSTRUKTOREN***************************************/
	
	
	
	/***************************ANFANG GETTER/SETTER METHODEN******************************/
	public String getDefaultDescription() {
		return this.defaultDescription;
	}
	public void setDefaultDescription(String defaultDescription) {
		this.defaultDescription = defaultDescription;
	}
	public String getExploreDescription() {
		return this.exploreDescription;
	}
	public void setExploreDescription(String exploreDescription) {
		this.exploreDescription = exploreDescription;
	}
	public String getAlreadyExploredDescription() {
		return this.alreadyExploredDescription;
	}
	public void setAlreadyExploredDescription(String alreadyExploredDescription) {
		this.alreadyExploredDescription = this.defaultDescription + " "  + alreadyExploredDescription;
	}
	/****************************ENDE GETTER/SETTER METHODEN*******************************/
}