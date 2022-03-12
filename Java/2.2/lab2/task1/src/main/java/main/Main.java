package main;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;

public class Main extends Application {
    
    public void start(javafx.stage.Stage stage) throws Exception {
        Scene scene = FXMLLoader.load(getClass().getResource("/Main.fxml"));
        stage.setScene(scene);
        stage.show();
    };

    public static void main(String[] args) {
        launch();
    }
}