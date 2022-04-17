package task1.client.controller;

import java.io.IOException;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import task1.client.model.net.Net;

public class Controller {
    
    @FXML private Pane titlePane;
    @FXML private ImageView btnMinimize, btnClose;
    @FXML private Label lblResult;

    private double x, y;
    private double num1 = 0;
    private String operator = "";

    private Net net;

    public void init(Stage stage) {
        titlePane.setOnMousePressed(mouseEvent -> {
            x = mouseEvent.getSceneX();
            y = mouseEvent.getSceneY();
        });
        titlePane.setOnMouseDragged(mouseEvent -> {
            stage.setX(mouseEvent.getScreenX()-x);
            stage.setY(mouseEvent.getScreenY()-y);
        });

        btnClose.setOnMouseClicked(mouseEvent -> {
            try {
                net.send(0, 0, "close");
                net.stop();
            } catch (IOException e) {
                e.printStackTrace();
            }
            stage.close();
        });
        btnMinimize.setOnMouseClicked(mouseEvent -> stage.setIconified(true));
        net = new Net("127.0.0.1", 1111);
    }

    @FXML
    void onNumberClicked(MouseEvent event) {
        int value = Integer.parseInt(((Pane)event.getSource()).getId().replace("btn",""));
        lblResult.setText(Double.parseDouble(lblResult.getText())==0?String.valueOf((double)value):String.valueOf(Double.parseDouble(lblResult.getText())*10+value));
    }

    @FXML
    void onSymbolClicked(MouseEvent event) {
        String symbol = ((Pane)event.getSource()).getId().replace("btn","");
        if(symbol.equals("Equals")) {
            double num2 = Double.parseDouble(lblResult.getText());
            if (operator != "" || operator != ".") {
                net.send(num1, num2, operator);
                try {
                    lblResult.setText(net.get() + "");
                } catch (ClassNotFoundException | IOException e) {
                    e.printStackTrace();
                }
                net.clear();
            }
            operator = ".";
        }
        else if(symbol.equals("Clear")) {
            lblResult.setText(String.valueOf(0.0));
            operator = ".";
        }
        else {
            switch (symbol) {
                case "Plus" : {
                    operator = "+";
                    break;
                } 
                case "Minus" : {
                    operator = "-";
                    break;
                } 
                case "Multiply" : {
                    operator = "*";
                    break;
                }  
                case "Divide" : {
                    operator = "/";
                    break;
                }   
            }
            num1 = Double.parseDouble(lblResult.getText());
            lblResult.setText(String.valueOf(0.0));
        }
    }
}