public class Manager extends Angajat implements Entity{
    public Manager(String nume, Integer salar) {
        super(nume, salar);
    }

    @Override
    public void accept(Visitor visitor) {
        visitor.visitManager(this);
    }
}
