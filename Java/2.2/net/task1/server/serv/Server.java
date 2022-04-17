package task1.server.serv;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

import task1.data.Data;
import task1.server.calc.Calc;

public class Server {
    
    private ServerSocket serverSocket;
    private Socket socket;
    
    public Server(int port) {
        try {
            serverSocket = new ServerSocket(port);
        } catch (IOException e) {
            e.printStackTrace();
        }
        while (!serverSocket.isClosed()) {
            try {
                socket = serverSocket.accept();
            } catch (IOException e) {
                e.printStackTrace();
            }
            new Thread(new CalcThread(socket)).start();
        }
        try {
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class CalcThread implements Runnable {

    private Data data;
    private String operator;
    private double result;
    private ObjectInputStream in;
    private ObjectOutputStream out;
    private Socket socket;
    private boolean isClosed = false;

    @Override
    public void run() {
        while (!isClosed) {
            read(); 
            write();
        }
        stop();
    }

    public CalcThread(Socket socket) {
        this.socket = socket;
        try {
            out = new ObjectOutputStream(socket.getOutputStream());
            in = new ObjectInputStream(socket.getInputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void read() {
        try {
            data = (Data) in.readObject();
        } catch (ClassNotFoundException | IOException e) {
            e.printStackTrace();
        }
        operator = data.getOperator();
        System.out.print(data.getA() + " " + data.getB() + " " + data.getOperator() + "\n");
        switch (operator) {                    
            case "/":
                result = Calc.div(data.getA(), data.getB());
                break;
            case "*":
                result = Calc.mul(data.getA(), data.getB());
                break;
            case "+":
                result = Calc.add(data.getA(), data.getB());
                break;
            case "-":
                result = Calc.sub(data.getA(), data.getB());
                break;
            case "close":
                isClosed = true;
                break;
            default:
                result = data.getA();
        }
    }

    public void write() {
        System.out.print(result);
        try {
            out.writeObject(result);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void stop() {
        try {
            in.close();
            out.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
