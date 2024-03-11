#!/usr/bin/env python
# coding: utf-8

# In[2]:


import numpy as np


# In[17]:


array2 = np.array([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15])
print("Vector:",array2)
print(array2.shape)
a = array2.reshape(3,5)
print(a)


# In[18]:


print("Shape:",a.shape)
print("Dimentsion:",a.ndim)
print("Data Type:",a.dtype.name)
print("Size",a.size)
print("Type",type(a))


# In[7]:


x=np.array([1,2,3])
y=np.array([4,5,6])
print(x+y)
print(x-y)
print(x**2)


# In[8]:


a=np.array([1,2,3])
d=a.copy()
print(d)
b=a
c=a
b[0]=5
print(a,b,c)


# In[15]:


a=np.array([1,2,3,4,5,6,7])
print(a[0])
print(a[0:4])


# In[16]:


reverse_array=a[::-1]
print(reverse_array)


# In[14]:


b=np.array([[1,2,3,4,5],[6,7,8,9,10]])
print(b)
print(b[1,1])
print(b[:,1])
print(b[1,:])
print(b[1,1:4])
print(b[-1,:])
print(b[:,-1])

