class vetor
{
    public static void main(final String[] array) {
        final int[] array2 = new int[10];
        final double[] array3 = { 2.0, 3.0, -5.0 };
        final long[] array4 = { -5L, 3L, 6426246L, -433242L };
        final float[] array5 = { 2.0f, 3.0f, -5.0f };
        final byte[] array6 = { -2, 4, 0 };
        final char[] array7 = { 'a', '0', ')' };
        final short[] array8 = { 15, 1000, -2 };
        for (int i = 0; i < 10; ++i) {
            array2[i] = i;
        }
        final int[] array9 = array2;
        final int n = 0;
        array9[n] += 100000;
        for (int j = 0; j < 10; ++j) {
            System.out.println(array2[j]);
        }
        System.out.println(array2.length);
        System.out.println();
        for (int k = 0; k < 3; ++k) {
            System.out.println(array3[k]);
        }
        System.out.println(array3.length);
        System.out.println();
        for (int l = 0; l < 4; ++l) {
            System.out.println(array4[l]);
        }
        System.out.println(array4.length);
        System.out.println();
        for (int n2 = 0; n2 < 3; ++n2) {
            System.out.println(array5[n2]);
        }
        System.out.println(array5.length);
        System.out.println();
        for (int n3 = 0; n3 < 3; ++n3) {
            System.out.println(array6[n3]);
        }
        System.out.println(array6.length);
        System.out.println();
        for (int n4 = 0; n4 < 3; ++n4) {
            System.out.println(array7[n4]);
        }
        System.out.println(array7.length);
        System.out.println();
        for (int n5 = 0; n5 < 3; ++n5) {
            System.out.println(array8[n5]);
        }
        System.out.println(array8.length);
        System.out.println();
    }
}
