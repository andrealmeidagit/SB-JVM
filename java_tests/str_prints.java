public class str_prints {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
        System.out.println("This is from the main function");
        foo();
        System.out.println(bar());
    }

    public static void foo() {
        System.out.println("This is from the foo funtion");
    }

    public static String bar() {
        return "This was returned by bar function";
    }
}
