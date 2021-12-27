import pdb
def reverseVowels(s):
        """
        Given a string s, reverse only all the vowels in the string and return it.
        The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.
        Example 1:
        Input: s = "hello"
        Output: "holle"
        Example 2:
        Input: s = "leetcode"
        Output: "leotcede"

        :type s: str
        :rtype: str
        """
        length=len(s)
        #pdb.set_trace()
        vowels=['a','e','i','o','u','A','E','I','O','U']
        vowelidx=[]
        string=list(s)
        for i in range(length):
            if (s[i] in vowels):
                vowelidx.append(i)
        vlen=len(vowelidx)
        for i in range(int(vlen/2)):
            index1=vowelidx[i]
            index2=vowelidx[vlen-i-1]
            print("index1: "+str(index1)+" index2: "+str(index2))
            temp=string[index1]
            print("temp: "+str(temp)+" string["+str(index1)+"]: "+string[index1]+" string["+str(index2)+"]: "+string[index2])
            string[index1]=string[index2]
            print("temp: "+str(temp)+" string["+str(index1)+"]: "+string[index1]+" string["+str(index2)+"]: "+string[index2])
            string[index2]=temp
            print("temp: "+str(temp)+" string["+str(index1)+"]: "+string[index1]+" string["+str(index2)+"]: "+string[index2])
        print(string)
        return "".join(string)

string="Hello"
reverseVowels(string)