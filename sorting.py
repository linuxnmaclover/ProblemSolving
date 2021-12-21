#/usr/bin/python3
import os
import sys
import re
#Below is the given problem statement to solve
"""
You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.
There are two types of logs:
    Letter-logs: All words (except the identifier) consist of lowercase English letters.
    Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:
    The letter-logs come before all digit-logs.
    The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
    The digit-logs maintain their relative ordering.
Return the final order of the logs.

Example 1:
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
Example 2:
Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
"""

def separate_letter_logs(input_list):
    diglogs=[]
    charlogs=[]
    length=len(input_list)
    for i in range(length):
        entry=input_list[i]
        words=entry.split(" ")
        if re.search("[a-z]",words[1]):
            if entry not in charlogs:
                charlogs.append(entry)
        else:
            if entry not in diglogs:
                diglogs.append(entry)
    print("charlogs: "+str(charlogs))
    print("diglogs: "+str(diglogs))
    return [charlogs,diglogs]

def parse_logs_to_dict(logs):
    ldict={}
    length=len(logs)
    print("logs: "+str(logs))
    for i in range(length):
        entry=logs[i]
        words=entry.split(" ")
        key=words[0]
        words.pop(0)
        value=words
        if key not in ldict.keys():
            ldict[key]=value
    print("ldict: "+str(ldict))
    return ldict

logs=["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
print("logs="+str(logs))
output_list=separate_letter_logs(logs)
print("output_list="+str(output_list))
clogs=output_list[0]
dlogs=output_list[1]
cdict=parse_logs_to_dict(clogs)
