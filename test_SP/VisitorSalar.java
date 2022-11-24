public class VisitorSalar implements Visitor{

    Integer salariuManageri = 0;
    Integer salariuProgramatori = 0;
    Integer salariuTesteri = 0;
    Integer salariuTotal = 0;
    
    @Override
    public void visitDepartament(Departament d) {

    }

    @Override
    public void visitFirma(Firma f) {

    }

    @Override
    public void visitManager(Manager m) {
        this.salariuManageri += m.getSalar();
        this.salariuTotal += m.getSalar();
    }

    @Override
    public void visitProgramator(Programator p) {
        this.salariuProgramatori += p.getSalar();
        this.salariuTotal += p.getSalar();
    }

    @Override
    public void visitTester(Tester t) {
        this.salariuTesteri += t.getSalar();
        this.salariuTotal += t.getSalar();
    }

    @Override
    public void print() {
        System.out.println("Visitor: ");
        System.out.println("Salariu Manageri: " + this.salariuManageri.toString());
        System.out.println("Salariu Programatori: " + this.salariuProgramatori.toString());
        System.out.println("Salariu Testeri: " + this.salariuTesteri.toString());
        System.out.println("Salariu total: " + this.salariuTotal.toString());
    }
}
