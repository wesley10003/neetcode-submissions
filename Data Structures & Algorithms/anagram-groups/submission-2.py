from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        # O(nlogn)
        # idx_map = {}
        # res = []
        
        # for word in strs:
        #     # key = tuple(sorted(word))
        #     key = "".join(sorted(word))
        #     if key not in idx_map:
        #         idx_map[key] = []
        #     idx_map[key].append(word)
        
        # return [anagram for anagram in idx_map.values()]


        # O(n)
        idx_map = defaultdict(list)
        
        for word in strs:
            count = [0] * 26
            for char in word:
                count[ord(char) - ord('a')] += 1
            
            # Using an immutable fixed-size tuple of counts as the key
            idx_map[tuple(count)].append(word)
            
        return list(idx_map.values())
        