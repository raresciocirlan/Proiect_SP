public class Programator extends Angajat {
    public Programator(String nume, Integer salar) {
        super(nume,salar);
    }

    @Override
    public void accept(Visitor visitor) {
        visitor.visitProgramator(this);
    }
}
