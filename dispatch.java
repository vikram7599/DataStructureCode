class A {
    void callme() {
        System.out.println("Inside A's callmemethod"); 
    } 
}

class B extends A {
    void callme() {
        System.out.println("Inside B's callmemethod"); 
    } 
}
class C extends A {
    void callme() {
        System.out.println("Inside C's callmemethod"); 
    } 
}

class match {
public static void main(String args[]) {
        A a= new A();
        B b= new B();
        C c= new C();
        A r;
        r = a;
        r.callme();
        r = b;
        r.callme();
        r = c;
        r.callme(); 
    } 
}