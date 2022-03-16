package controller;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class MainController {

    @FXML
    private TextField textFieldLeft;

    @FXML
    private TextField textFieldRight;

    @FXML
    private Button button;

    @FXML
    void onClick() {
        String temp = textFieldLeft.getText();
        textFieldLeft.setText(textFieldRight.getText());
        textFieldRight.setText(temp);
        if(button.getText() != "<-") {
            button.setText("<-");
        }
        else {
            button.setText("->");
        }
    }
}

