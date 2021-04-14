#!/usr/bin/env python
# coding: utf-8

# In[1]:
import math
import os
import f

def read_f(f):
    arr = [];
    if (os.path.exists(f)):
        with open(f) as file: 
            for line in file:
                for x in line.split (' '): 
                    if x != "":
                        if x.isdigit():
                            arr.append(int(x))
                        else:
                            return arr, -2
    else:
        return arr, -1
    if len(arr) == 0:
        return arr, -3
    return arr, 0


# In[2]:


def add(arr, begin, i):
    if begin != i-1:
        k = i - begin
        for j in range(k):
            arr.insert(i, arr[begin])
            i +=1
            begin += 1;
    return arr, begin, i


# In[3]:


def f_ins(arr):
    i = 1
    begin = 0
    while i < len(arr):
        if arr[i - 1] >= arr[i]:
            arr, begin, i = add(arr, begin, i)
            begin = i
        i += 1 
    arr, begin, i = add(arr, begin, i)
    return arr


# In[ ]:




