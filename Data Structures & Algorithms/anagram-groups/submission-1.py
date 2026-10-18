class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        idx_map = {}
        res = []
        
        for word in strs:
            # key = tuple(sorted(word))
            key = "".join(sorted(word))
            if key not in idx_map:
                idx_map[key] = []
            idx_map[key].append(word)
        
        return [anagram for anagram in idx_map.values()]
        