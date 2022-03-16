module main {
    requires javafx.graphics;
    requires javafx.fxml;
    requires javafx.controls;

    opens main to javafx.graphics;
    opens controller to javafx.fxml;
}
