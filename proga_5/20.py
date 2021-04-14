#!/usr/bin/env python
# coding: utf-8

# In[4]:


import math
import os
import f


# In[5]:

"""
>>> g=open("5.txt","w")
>>> u=g.write("")
>>> g.close()
>>> read_f("5.txt")
-3
>>> g=open("2.txt","w")
>>> u=g.write("1 2 2 -3")
>>> g.close()
>>> f.read_f("2.txt")
1
>>> g=open("3.txt","w")
>>> u=g.write(" 1 1 1")
>>> g.close()
>>> f.read_f("3.txt")
0
>>> g=open("4.txt","w")
>>> u=g.write("1 2 a")
>>> g.close()
>>> f.read_f("4.txt")
-2
"""

arr, err = f.read_f("1.txt")
if err == -1:
    print ("Not file\n")
elif err == -2:
    print ("Bad data")
elif err == -3:
    print ("Empty file\n")
else:
    print (arr)
    arr = f.f_ins(arr)
    print (arr)


# In[6]:


import doctest
doctest.testmod()


# In[ ]:




