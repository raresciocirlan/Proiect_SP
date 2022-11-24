public class Tester extends Angajat{
    public Tester(String nume, Integer salar) {
        super(nume, salar);
    }

    @Override
    public void accept(Visitor visitor) {
        visitor.visitTester(this);
    }
}
