class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # List to hold anagrams with sorted key
        anagrams = defaultdict(list)

        # Copy each string, sort for key, and append to list
        for s in strs:
            key = ''.join(sorted(s))
            anagrams[key].append(s)

        # Return a list of the values
        return list(anagrams.values())
        