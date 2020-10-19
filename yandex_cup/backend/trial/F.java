import java.util.*;
import java.net.*;
import java.io.*;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;


public class F {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String url = scanner.nextLine();
        int port = scanner.nextInt();
        int firstNumber = scanner.nextInt();
        int secondNumber = scanner.nextInt();

        JSONParser parser = new JSONParser();

        try {
            URL requestUrl = new URL(url + ":" + port + "?a=" + firstNumber + "&b=" + secondNumber);
            URLConnection connection = requestUrl.openConnection();
            BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
            String line;
            long sum = 0;
            while ((line = in.readLine()) != null) {
                JSONArray array = (JSONArray)parser.parse(line);
                for (int i = 0; i < array.size(); ++i) {
                    sum += (Long)array.get(i);
                }
            }
            in.close();
            System.out.println(sum);
        } catch (MalformedURLException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }
}
