
import java.io.Serializable;
import java.util.ArrayList;


public class Save implements Serializable {
	
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	private static final long serialVersionUID = 1940836049303449127L;
	// Zu speichernde Attribute
	public ArrayList<String> iObjects = new ArrayList<String>();
	public ArrayList<Location> locations = new ArrayList<Location>();
	public ArrayList<ArrayList<Item>> items = new ArrayList<ArrayList<Item>>();
	public int currentLocation;
	public int lastLocation;
	public int amountNotes;
	public boolean beam;
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	public Save() {}
}