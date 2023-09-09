import java.util.Scanner;

public class Main {
    public static boolean isPalindrome(String s) {
        String re_string = "";
        String new_string = "";
        s = s.replaceAll("[^a-zA-Z0-9]", "");

        for (int i = s.length() - 1; i >= 0; i--) {
            re_string = re_string + s.charAt(i);
        }
        for (int i = 0; i < s.length(); i++) {
            new_string = new_string + s.charAt(i);
        }
        return new_string.equals(re_string);
    }


    public static void main(String[] args) {
        String Input;
        Scanner sc = new Scanner(System.in);
        Input = sc.nextLine();
        if(isPalindrome(Input))
            System.out.println(1);
        else
            System.out.println(0);

    }
}