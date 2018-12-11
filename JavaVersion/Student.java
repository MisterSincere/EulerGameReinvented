
import java.io.Serializable;


public class Student implements Serializable{
	
	/******************************ERSTELLEN DER ATTRIBUTE*********************************/
	private static final long serialVersionUID = 6801985424109656495L;
	private int location;
	private String name;
	private boolean defeated = false;
	private String questionText = "";
	private String answerText = "";
	private String hint = "";
	/******************************FERTIG ATTRIBUTE****************************************/
	
	
	
	/*****************************ANFANG KONSTRUKTOREN*************************************/
	public Student(String name, int location) {
		this.location = location;
		this.setName(name);
	}
	/*****************************ENDE KONSTRUKTOREN***************************************/
	
	
	
	/***************************ANFANG GETTER/SETTER METHODEN******************************/
	public int getLocation() {
		return location;
	}
	public void setLocation(int location) {
		this.location = location;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public boolean isDefeated() {
		return defeated;
	}
	public void setDefeated(boolean defeated) {
		this.defeated = defeated;
	}
	public String getQuestionText() {
		return questionText;
	}
	public void setQuestionText(String questionText) {
		this.questionText = questionText;
	}
	public String getAnswerText() {
		return answerText;
	}
	public void setAnswerText(String answerText) {
		this.answerText = answerText;
	}
	public String getHint() {
		return hint;
	}
	public void setHint(String hint) {
		this.hint = hint;
	}
	/****************************ENDE GETTER/SETTER METHODEN*******************************/
}