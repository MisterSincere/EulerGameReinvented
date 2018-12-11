

import java.io.IOException;
import java.net.URL;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.Mixer;
import javax.sound.sampled.UnsupportedAudioFileException;


public class Sound implements Runnable{
	
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	public static Mixer mixer;
	public static Clip clip;
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	
	/*******************************ANFANG METHODEN****************************************/
	public static void playZipper() {
		if (Tuna.isSoundAllowed()) {
			Mixer.Info[] mixInfos = AudioSystem.getMixerInfo();
			mixer = AudioSystem.getMixer(mixInfos[0]);
	
			DataLine.Info dataInfo = new DataLine.Info(Clip.class, null);
			try {
				clip = (Clip) mixer.getLine(dataInfo);
			} catch (LineUnavailableException lue) {
				lue.printStackTrace();
			}
			
			
			try {
				URL soundURL = Sound.class.getResource("zipper.wav");
				AudioInputStream audioStream = AudioSystem.getAudioInputStream(soundURL);
				clip.open(audioStream);
			} catch (LineUnavailableException lue) {
				lue.printStackTrace();
			} catch (UnsupportedAudioFileException uafe) {
				uafe.printStackTrace();
			} catch(IOException ioe) {
				ioe.printStackTrace();
			}
			
			clip.start();
			
			do{
				try {
					Thread.sleep(50);
				}catch (InterruptedException ie) {
					ie.printStackTrace();
				}
			}while(clip.isActive());
		}
	}
	/*********************************ENDE METHODEN****************************************/

	@Override
	public void run() {
		playZipper();
	}
}