#!/usr/bin/env python
# coding: utf-8

# In[9]:


import math
import os


# In[20]:


def read_f(f = '1.txt'):
    """
    >>> g=open("5.txt","w")
    >>> u=g.write("")
    >>> g.close()
    >>> read_f("5.txt")
    -3
    >>> g=open("2.txt","w")
    >>> u=g.write("1 2 2 -3")
    >>> g.close()
    >>> read_f("2.txt")
    0
    >>> g=open("3.txt","w")
    >>> u=g.write(" 1 1 1")
    >>> g.close()
    >>> read_f("3.txt")
    0
    >>> g=open("4.txt","w")
    >>> u=g.write("1 2 a")
    >>> g.close()
    >>> read_f("4.txt")
    -2
    """
    k=0
    i=0
    if (os.path.exists(f)):
        with open(f) as file:
            for line in file:
                for x in line.split (' '): 
                    if x != "":
                        try:
                            x = int(x)
                            k+=1
                            if i == 0:
                                x1 = x
                                i += 1
                            elif (i == 1) and (x1 != x):
                                x2 = x
                                i += 1
                            elif (i >= 2) and (x2 != x):
                                x3 = x
                                if (x1 < x2 < x3) or (x1 > x2 > x3):
                                    return k-1
                                else:
                                    x1 = x2
                                    x2 = x3
                                    i += 1
                        except ValueError:   
                            return -2
                                
    else:
        return -1
    if i == 0:
        return -3
#    if (i == 2) and (k == 2):
#        return 2
    return 0


# In[21]:


err = read_f()
if err == 0:
    print ("No suсh numbers")
elif err == -1:
    print ("Not file\n")
elif err == -2:
    print ("Bad data")
elif err == -3:
    print ("Empty file\n")
else:
    print (err)


# In[22]:


import doctest
doctest.testmod()

