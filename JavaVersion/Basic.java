
import java.awt.Color;
import java.io.Serializable;


public class Basic implements Serializable {
	
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	private static final long serialVersionUID = 2236728008371583540L;
	// Zu speichernde Attribute
	public boolean opened = false;
	public boolean soundAllowed;
	public int width = 1100;
	public int height = 700;
	public int selectedItemResolution = 0;
	public Color ausgabeColor = Color.DARK_GRAY;
	public Color inventarColor = new Color(0x602600);
	public Color exitsColor = new Color(0xA03500);
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	public Basic() {}
}