public class Angajat implements Entity{
    protected final String nume;

    public String getNume() {
        return nume;
    }

    public Integer getSalar() {
        return salar;
    }

    protected final Integer salar;


    public Angajat(String nume, Integer salar) {
        this.nume = nume;
        this.salar = salar;
    }

    @Override
    public void print() {
        System.out.println("Angajat: " + this.nume + ", Salar: " + this.salar.toString());
    }

    @Override
    public void add(Entity e) {

    }

    @Override
    public void remove(Entity e) {

    }

    @Override
    public Entity get(int index) {
        return null;
    }

    @Override
    public void accept(Visitor visitor) {

    }
}
