class Resourse{
	boolean valueset=false;
	
	synchronized void request() {
		while(valueset) {
			try {
				wait();
			}catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("Request accepted");
			valueset=true;
			notify();
		}

	synchronized void response() {
		while(!valueset) {
			try {
				wait();
			}catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("response sent");
			valueset=false;
			notify();
		}
	}
class Server implements Runnable{
	Resourse r;
	Server(Resourse r){
		this.r=r;
		new Thread(this,"Server").start();
	}
	public void run() {
		for(int i=0;i<10;i++) {
			r.response();
		}
	}
	
}
class Client implements Runnable{
	Resourse r;
	Client(Resourse r){
		this.r=r;
		new Thread(this,"Client").start();
	}
	public void run() {
		for(int i=0;i<10;i++){
			r.request();
		}
	}
	
}

public class ClientServerDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Resourse r=new Resourse();
		new Server(r);
		new Client(r);
		System.out.println("press control to stop");
	}

}
