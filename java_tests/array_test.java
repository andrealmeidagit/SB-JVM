public class array_test {
    public static void main(String[] args) {
        int[] array_int = {1, 2, 3, 2, 1};
        System.out.println("Array: ");
        for (int i = 0; i <= 4; i++)
            System.out.println(array_int[i]);
        System.out.println("Some operation results: ");
        System.out.println(array_int[0] - array_int[2]);
        System.out.println(array_int[1]);
        System.out.println(array_int[2] * array_int[3]);
    }
}
