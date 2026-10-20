class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        freq = {}
        # build freq map
        for char in s1:
            freq[char] = freq.get(char, 0) + 1

        substr_freq = {}
        left, right = 0, len(s1) - 1
        sub_str = s2[left: right+1]

        # build substr freq map
        for char in sub_str:
            substr_freq[char] = substr_freq.get(char, 0) + 1

        while right < len(s2):
            if substr_freq == freq:
                return True

            # decrement char out of window
            substr_freq[s2[left]] -= 1
            # if char no longer in window, del from map
            if substr_freq[s2[left]] == 0:
                del substr_freq[s2[left]]
            
            left += 1
            right += 1

            # increment new char in window
            if right < len(s2):
                substr_freq[s2[right]] = substr_freq.get(s2[right], 0) + 1

        return False
            
