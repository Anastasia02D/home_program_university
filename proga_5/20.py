#!/usr/bin/env python
# coding: utf-8

# In[10]:


import math
import os
import f


# In[29]:


def main (F = '1.txt'):
    """
    
    >>> g=open('1.txt','w')
    >>> u=g.write('1 0 2 4 0 0 3 3 3 0 10 20  ')
    >>> g.close()
    >>> main()
    [1, 0, 2, 4, 0, 0, 3, 3, 3, 0, 10, 20]
    [1, 0, 2, 4, 0, 2, 4, 0, 0, 3, 0, 3, 3, 3, 0, 10, 20, 0, 10, 20]
    
    
    >>> g=open('2.txt','w')
    >>> u= g.write('  ')
    >>> g.close()
    >>> main('2.txt')
    Empty file
    
    >>> main('6.txt')
    Not file

    >>> g=open('3.txt','w')
    >>> u=g.write('agberg 1 2\\n')
    >>> g.close()
    >>> main('3.txt')
    Bad data
    
    """
    arr, err = f.read_f(F)
    if err == -1:
        print ("Not file")
    elif err == -2:
        print ("Bad data")
    elif err == -3:
        print ("Empty file")
    else:
        print (arr)
        arr = f.f_ins(arr)
        print (arr)


# In[30]:


import doctest
doctest.testmod()


# In[ ]:




