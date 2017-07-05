public class math_functions {
    public static void main(String args[]) {
        System.out.println(sum(4, 14));
        System.out.println(sub(4, 14));
        System.out.println(mul(4, 14));
        System.out.println(div(4, 14));
        System.out.println(sum(46.7f, 14.3f));
        System.out.println(sub(798f, 567.124f));
        System.out.println(mul(49f, 14f));
        System.out.println(div(63f, 17f));
    }

    public static int sum(int a, int b) {
        return a + b;
    }

    public static int sub(int a, int b) {
        return a - b;
    }

    public static int mul(int a, int b) {
        return a * b;
    }

    public static int div(int a, int b) {
        return a / b;
    }

    public static float sum(float a, float b) {
        return a + b;
    }

    public static float sub(float a, float b) {
        return a - b;
    }

    public static float mul(float a, float b) {
        return a * b;
    }

    public static float div(float a, float b) {
        return a / b;
    }
}
