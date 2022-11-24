public interface Entity {
    void add(Entity e);
    void remove(Entity e);
    Entity get(int index);
    void accept(Visitor visitor);
    
    void print();
}
