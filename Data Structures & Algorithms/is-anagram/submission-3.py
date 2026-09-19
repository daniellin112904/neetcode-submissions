class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sfreq = {}
        tfreq = {}

        for letter in s:
            sfreq[letter] = sfreq.get(letter, 0) + 1
        for letter in t:
            tfreq[letter] = tfreq.get(letter, 0) + 1\

        return sfreq == tfreq