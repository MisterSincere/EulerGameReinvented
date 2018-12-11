
import java.io.Serializable;


public class Item implements Serializable {
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	private static final long serialVersionUID = 299143864505820360L;
	private String name;
	private String description;
	private String interactDescription;
	private int standort;
	private int itemId;
	private boolean visible;
	private boolean collected = false;
	/******************************FERTIG ATTRIBUTE****************************************/
	
	

	/*****************************ANFANG KONSTRUKTOREN*************************************/
	public Item() {}
	
	public Item(boolean visible) {
		this.visible = visible;
	}
	
	public Item(boolean visible, boolean collected) {
		this.visible = visible;
		this.collected = collected;
	}
	/*****************************ENDE KONSTRUKTOREN***************************************/
	
	
	
	/***************************ANFANG GETTER/SETTER METHODEN******************************/
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public boolean isCollected() {
		return collected;
	}
	public void setCollected(boolean argb) {
		this.collected = argb;
	}
	public int getLocation() {
		return standort;
	}
	public void setLocation(int standort) {
		this.standort = standort;
	}
	public int getItemId() {
		return itemId;
	}
	public void setItemId(int id) {
		this.itemId = id;
	}
	public boolean isVisible() {
		return visible;
	}
	public void setVisible(boolean visible) {
		this.visible = visible;
	}
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}
	public String getInteractDescription() {
		return interactDescription;
	}
	public void setInteractDescription(String interactDescription) {
		this.interactDescription = interactDescription;
	}
	/****************************ENDE GETTER/SETTER METHODEN*******************************/
}