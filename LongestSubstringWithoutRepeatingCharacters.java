import java.util.*;

public class LongestSubstringWithoutRepeatingCharacters {

    public static void main(String[] args){

    }

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> groupedAnagrams = new ArrayList<>();
        Map<String, List<String>> anagramsByAlphabetical = new HashMap<>();
        for(String anagram: strs) {
            char[] characters = anagram.toCharArray();
            Arrays.sort(characters);
            String sortedString = new String(characters);
            anagramsByAlphabetical.putIfAbsent(sortedString, new ArrayList<>());
            anagramsByAlphabetical.get(sortedString).add(anagram);
        }
        for (List<String> anagrams: anagramsByAlphabetical.values()) {
            groupedAnagrams.add(anagrams);
        }
        return groupedAnagrams;

    }





}
