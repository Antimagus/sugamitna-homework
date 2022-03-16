package main;

import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.CheckBox;
import javafx.scene.control.PasswordField;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.ProgressIndicator;

public class MainController {

    @FXML
    private ProgressIndicator g1;

    @FXML
    private CheckBox ch1;

    @FXML
    private ProgressBar g2;

    @FXML
    private CheckBox ch2;

    @FXML
    private PasswordField g3;

    @FXML
    private CheckBox ch3;
    
    @FXML
    void onCh1() {
        if(ch1.isSelected()) {
            g1.setVisible(true);
        }
        else g1.setVisible(false);
    }

    @FXML
    void onCh2() {
        if(ch2.isSelected()) {
            g2.setVisible(true);
        }
        else g2.setVisible(false); 
    }

    @FXML
    void onCh3() {
        if(ch3.isSelected()) {
            g3.setVisible(true);
        }
        else g3.setVisible(false);
    }

}
