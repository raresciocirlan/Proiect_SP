public class Main {
    public static void main(String[] args) {
        Firma nokia = new Firma("Nokia");
        Departament d = new Departament("5G");
        d.add(new Manager("Sefu", 10000));
        d.add(new Programator("Radu", 15000));
        d.add(new Programator("Ion", 4500));
        d.add(new Tester("Alex", 3500));

        nokia.add(d);
        nokia.print();

        Visitor calculSalar = new VisitorSalar();
        d.accept(calculSalar);
        calculSalar.print();
    }
}