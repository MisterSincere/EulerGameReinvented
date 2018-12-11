

import java.awt.DisplayMode;
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;
import java.awt.Window;
import javax.swing.JFrame;


public class Screen {
	
	private GraphicsDevice device;
	
	
	public Screen() {
		GraphicsEnvironment environment = GraphicsEnvironment.getLocalGraphicsEnvironment();
		device = environment.getDefaultScreenDevice();
	}
	
	
	// set Window FullScreen
	public void setFullScreen(DisplayMode dm, JFrame frame) {
		frame.setResizable(false);
		device.setFullScreenWindow(frame);
		
		if (dm != null && device.isDisplayChangeSupported()) {
			device.setDisplayMode(dm);
		}
	}
	
	// set Window non FullScreen
	public void restoreScreen() {
		Window w = device.getFullScreenWindow();
		if (w!= null) {
			w.dispose();
		}
		device.setFullScreenWindow(null);
	}

	// get Window
	public Window getFullScreenWindow() {
		return device.getFullScreenWindow();
	}
}
