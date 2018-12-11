
import java.awt.Font;

import javax.swing.BorderFactory;
import javax.swing.JDialog;
import javax.swing.JLabel;


public class WelcomeDialog extends JDialog {
	
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	private static final long serialVersionUID = -5523486445648287585L;
	private JLabel content;
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	
	/*****************************ANFANG KONSTRUKTOREN*************************************/
	public WelcomeDialog(Tuna frame) {
		super(frame);
		setTitle("Willkommensmeldung");
		setResizable(false);
		setModal(true);
		
		content = new JLabel();
		content.setText( "<html><h1><u>TrueStudio pr�sentiert:</u></h1>"
				+ "<br><br><b>Die ultimativen Abenteuer des Euler in seiner Uni, ein Adventure voller Geheimnisse und Kaffee...</b>"
				+ "<br><br>Professor Euler muss einen Vortrag vor seinen Studenten halten, jedoch wurden die Unterlagen von einem Windsto� durch die"
				+ "<br>ganze Universit�t verteilt. Auf der Suche nach diesen muss Euler viele Mysterien l�sen: Wieso ist die Kaffemaschine nicht eingesteckt?"
				+ "<br>Warum sind in einer Uni Geheimg�nge und Schalter versteckt? Warum brennt das Treppenhaus? Und wer ist eigentlich vor der Steckdose"
				+ "<br>zusammengebrochen?"
				+ "<br><br>Kombinieren sie ihre Raffinese mit Kreativit�t, um die acht verschwundenen Seiten wiederzufinden."
				+ "<br>Probieren sie unser revolution�res Kampfsystem aus, und nehmen Sie alles genau unter die Lupe,"
				+ "<br>schlie�lich k�nnten Ihre Seiten �berall sein!"
				+ "<br><br>\"Die ultimativen Abenteuer des Euler in seiner Uni, ein Adventure voller Geheimnisse und Kaffee...\" wird Ihnen in mehr als 10 minuten"
				+ "<br>Spielzeit mit Witz und Unsinn jeden noch so schlechten Tag versch�nern, ein Spa� f�r alle, die mit einer Kaffeemaschine umgehen k�nnen."
				+ "<br><br><br>Viel Spa� w�nscht Ihnen"
				+ "<br><b><font color='002FB6'>CTT</font> \"Wir fordern zum selber Denken auf\"</b><br><br><br><br><br></html>");
		content.setFont(content.getFont().deriveFont(content.getFont().getStyle() & ~Font.BOLD));
		content.setBorder(BorderFactory.createEmptyBorder(5, 5, 0, 0));
		add(content);
		
		pack();
	}
	/*****************************ENDE KONSTRUKTOREN***************************************/
}