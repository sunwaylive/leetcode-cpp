import re

#main function
#string = input("input the string to inverse: ")
#string.strip()
#space_re = re.compile('[ ]+')
#string = space_re.sub(' ', string)
#word_list = string.split(" ")
#result = ' '.join(word_list)
#print(result)

class Solution:
    def reverseWords(self, s):
        word_list = []
        word = ''
        for c in s:
            if c == ' ':
                if word != '':
                    word_list.append(word)
                    word = ''
                else:
                    continue
            else:
                word += c
        if word != '':
            word_list.append(word)
        word_list.reverse()
        result = ' '.join(word_list)
        return result

#main function
sln = Solution()
string = "   the sky is    blue  "
result = sln.reverseWords(string);
print(result)
