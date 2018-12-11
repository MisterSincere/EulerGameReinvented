
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridBagLayout;

import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;


public class Win extends JDialog{

	/****************************** ERSTELLEN DER ATTRIBUTE *********************************/
	private static final long serialVersionUID = 6197585573152068458L;
	private JLabel label;
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	
	public Win(Tuna frame) {
		super(frame, true);
		setUndecorated(true);
		setTitle("Credits");
		
		
		label = new JLabel("<html></body><span style=\"font-size:18px;\"><b><b>Herzlichen Glückwunsch, du hast gewonnen!</b></b></span><br><br>"
				+ "<span style=\"text-align:center;\"><center>Made by CTT<br><i>alias</i><br>Nikkel Heesen Frieso Gerken Lukas Hertel</center></span></body></html>");
		label.setForeground(Color.WHITE);
		label.setFont(new Font(label.getFont().getFontName(), Font.PLAIN, 20));
		
		JPanel panel = new JPanel(new GridBagLayout());
		panel.setBackground(new Color(0x00AD14));
		panel.add(label);
		panel.setPreferredSize(new Dimension(600, 300));
		
		
		panel.setFocusable(true);									// Diese zwei zeilen werden gebraucht, um den Dialog mit ESC zu schließen 
		panel.requestFocusInWindow();								// Es wird auf "Key-Input" geprüft
		
		getContentPane().add(panel);
		
		SwingUtils.createDialogBackPanel(this, frame.getContentPane());				// Ist für den Hintergrund zuständig
		SwingUtils.addEscapeToCloseSupport(this, true);								// Nun kann der Diaog per ESC geschlossen werden
	}
}