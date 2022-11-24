public interface Visitor {
    void visitDepartament(Departament d);
    void visitFirma(Firma f);
    void visitManager(Manager m);
    void visitProgramator(Programator p);
    void visitTester(Tester t);

    void print();
}
