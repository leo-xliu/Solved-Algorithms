class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        dict1 = {}
        dict2 = {}
        list = s.split(" ")
        j = 0
        if len(list) != len(pattern):
            return False
        for i in pattern:
            if (dict1.get(i) != None and dict2.get(list[j]) != None):
                if (dict1.get(i) != list[j] or dict2.get(list[j]) != i):
                    return False
            elif (dict1.get(i) != None or dict2.get(list[j]) != None):
                return False
            else:
                dict1[i] = list[j]
                dict2[list[j]] = i
            j = j + 1
        return True