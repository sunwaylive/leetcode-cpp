import re

#main function
string = input("input the string to inverse: ")
string.strip()
space_re = re.compile('[ ]+')
string = space_re.sub(' ', string)
word_list = string.split(" ")
result = ' '.join(word_list)
print(result)
