import java.util.ArrayList;
import java.util.List;

public class Firma implements Entity {

    List<Entity> entityList = null;
    private final String nume;

    public Firma(String nume) {
        this.nume = nume;
        this.entityList = new ArrayList<>();
    }

    @Override
    public void print() {
        System.out.println("Firma: " + this.nume);
        for( Entity e: entityList) {
            e.print();
        }
    }

    @Override
    public void add(Entity e) {
        entityList.add(e);
    }

    @Override
    public void remove(Entity e) {

    }

    @Override
    public Entity get(int e) {
        return null;
    }

    @Override
    public void accept(Visitor visitor) {

    }
}
