package task1.client.model.net;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

import task1.data.Data;

public class Net {

    private Socket socket;
    private Data data;
    private ObjectInputStream in;
    private ObjectOutputStream out;
    
    public Net(String ip, int port) {
        try {
            socket = new Socket(ip, port);
            in = new ObjectInputStream(socket.getInputStream());
            out = new ObjectOutputStream(socket.getOutputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
        data = new Data();
    }

    public void stop() throws IOException {
        in.close();
        out.close();
        socket.close();
    }

    public void send(double a, double b, String operator) {
        data.setA(a);
        data.setB(b);
        data.setOperator(operator);
        try {
            out.writeObject(data);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public double get() throws ClassNotFoundException, IOException {
        return (Double)in.readObject();
    }

    public void clear() {
        try {
            out.reset();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
