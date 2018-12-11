
import java.awt.Color;
import java.awt.Font;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;


public class Fraince {
	
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	private JFrame frame = new JFrame("Verloren   -   Du hast aufgegeben!");
	private JLabel text = new JLabel("Vous avez abandonné", SwingConstants.CENTER);
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	
	/*****************************ANFANG KONSTRUKTOREN*************************************/
	public Fraince() {
		frame.setSize(800, 500);
		frame.setLocationRelativeTo(null);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		

		text.setBounds(0, 0, 800, 200);
		text.setForeground(Color.RED);
		text.setFont(text.getFont().deriveFont(Font.BOLD, 50));
		frame.add(text);
	}
	/*****************************ENDE KONSTRUKTOREN***************************************/
}