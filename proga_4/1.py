#!/usr/bin/env python
# coding: utf-8

# In[10]:


import math
import os


# In[ ]:





# In[11]:


def read_f():
    """
    >>> g=open("2.txt","w")
    >>> u=g.write(" ")
    >>> g.close()
    >>> read_f()

    >>> g=open("3.txt","w")
    >>> u=g.write(" ")
    >>> g.close()
    >>> read_f()
    
    >>> g=open("3.txt","w")
    >>> u=g.write(" ")
    >>> g.close()
    >>> read_f()
    
    >>> g=open("3.txt","w")
    >>> u=g.write(" ")
    >>> g.close()
    >>> read_f()
    """
    k=0
    i=0
    if (os.path.exists('1.txt')):
        with open("1.txt") as file:
            for line in file:
                for x in line.split (' '): 
                    if x != "":
                        i += 1
                        if x.isdigit():
                            x = int(x)
                            #print (x)
                            if k == 0:
                                pred = x
                                k += 1
                            else:
                                if pred == x:
                                    k += 1
                                    if k >= 3:
                                        return i-1
                                else:
                                    k = 1
                                    pred = x
                            #print(k)
                        else:
                            return -2                              
    else:
        return -1
    if i == 0:
        return -3
    return 0


# In[12]:


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


# In[13]:


import doctest
doctest.testmod()

