#!/usr/bin/env python
# coding: utf-8

# In[10]:


pip install matplotlib


# In[11]:


import matplotlib.pyplot as plt
import numpy as np
data = np.random.randn(1000)


# In[12]:


plt.hist(data,bins=30)
plt.title("histogram")
plt.xlabel("Values")
plt.ylabel("Frequencies")
plt.show()


# In[13]:


sizes=[30,25,15,10,5,5]
plt.pie(sizes)
plt.title("Pie Chart")
plt.show()


# In[ ]:




