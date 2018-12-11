import java.io.Serializable;
import java.util.ArrayList;


public class Location implements Serializable{
	
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	private static final long serialVersionUID = -8722351726756633566L;
	private Description description = new Description();
	private ArrayList<Item> items;
	private Student student;
	private String name;
	private String exits;
	private boolean visible;
	private boolean explored = false;
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	
	/*****************************ANFANG KONSTRUKTOREN*************************************/
	public Location(String name, String defaultDescription) {
		items = new ArrayList<Item>();
		this.description.setDefaultDescription(defaultDescription);
		this.name = name;
	}
	
	public Location(String name, String defaultDescription, boolean visible) {
		items = new ArrayList<Item>();
		this.description.setDefaultDescription(defaultDescription);
		this.name = name;
		this.visible = visible;
	}
	/*****************************ENDE KONSTRUKTOREN***************************************/
	
	
	
	/*******************************ANFANG METHODEN****************************************/
	public void createItem(int index, String name, int location,						// Für einen Standort ein Item erstellen
			int itemId) {
		items.add(index, new Item());
		items.get(index).setName(name);
		items.get(index).setLocation(location);
		items.get(index).setItemId(itemId);;
	}
	public void createItem(int index, String name, int location,
			int itemId, boolean visible) {
		items.add(index, new Item(visible));
		items.get(index).setName(name);
		items.get(index).setLocation(location);
		items.get(index).setItemId(itemId);;
	}
	public void createItem(int index, String name, int location,
			int itemId, boolean visible, boolean collected) {
		items.add(index, new Item(visible, collected));
		items.get(index).setName(name);
		items.get(index).setLocation(location);
		items.get(index).setItemId(itemId);;
	}
	
	public void createStudent(String name, int location) {				// Für einen Standort ein Studenten erstellen 
		student = new Student(name, location);
	}
	/*********************************ENDE METHODEN****************************************/
	
	
	
	/***************************ANFANG GETTER/SETTER METHODEN******************************/
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Description getDescriptions() {
		return description;
	}
	public void setDescriptions(Description description) {
		this.description = description;
	}
	public Item getItem(int index) {
		return items.get(index);
	}
	public Item getItemByName(String name) {
		for (int i = 0; i < items.size(); i++) {
			if (items.get(i).getName().equals(name)) {
				return items.get(i);
			}
		}
		return null;
	}
	public Student getStudent() {
		return student;
	}
	public boolean isVisible() {
		return visible;
	}
	public void setVisible(boolean visible) {
		this.visible = visible;
	}
	public boolean isExplored() {
		return explored;
	}
	public void setExplored(boolean explored) {
		this.explored = explored;
	}
	public String getExits() {
		return exits;
	}
	public void setExits(String exits) {
		this.exits = exits;
	}
	public ArrayList<Item> getItems() {
		return items;
	}
	public void setItems(ArrayList<Item> itemList) {
		this.items = itemList;
	}
	/****************************ENDE GETTER/SETTER METHODEN*******************************/
}