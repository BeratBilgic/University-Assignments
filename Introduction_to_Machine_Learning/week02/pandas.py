#!/usr/bin/env python
# coding: utf-8

# In[6]:


pip install pandas


# In[7]:


import numpy as np 
import pandas as pd


# In[44]:


t = (1,2,3,4)
t[1:3]


# In[13]:


dictionary = {"name":["ali","veli","zübeyde","ahmet","kubra","can"],
             "age":[12,34,56,78,None,12],
             "note":[123,456,78,87654,None,89]}
print(dictionary)
dataframe1 = pd.DataFrame(dictionary) 
print(dataframe1)


# In[18]:


df = pd.read_csv("data.csv")
print(df)


# In[28]:


head = dataframe1.head() 
print(head)


# In[29]:


tail = dataframe1.tail()
print(tail)


# In[30]:


print(dataframe1.columns)


# In[31]:


print(dataframe1.info())


# In[32]:


print(dataframe1.dtypes)


# In[33]:


print(dataframe1.describe())


# In[69]:


print(dataframe1["name"]) 
print(dataframe1.loc[:, "age"])  
dataframe1["new_feature"] = [1,2,3,4,5,6] 
print(dataframe1.loc[:3,"age"])
print(dataframe1.loc[:3, "name":"note"])
print(dataframe1.loc[::-1])


# In[79]:


print(dataframe1.loc[:, "new_feature"]) 


# In[84]:


print(dataframe1.loc[:3, ["name","note"]])


# In[85]:


print(dataframe1.loc[:,:"age"])


# In[86]:


print(dataframe1.iloc[:,[2]])


# In[87]:


filtre1 = dataframe1.age>10
dataframe1["bool"]= filtre1
print(dataframe1.loc[:,["age","bool"]])


# In[88]:


type(filtre1)


# In[89]:


filtrelenmis_data= dataframe1[filtre1] 
print(filtrelenmis_data)


# In[90]:


filtre2 = dataframe1.note>100
filtrelenmis_data2 = dataframe1[filtre2&filtre1] 
print(filtrelenmis_data2)


# In[91]:


dataframe1[dataframe1.age>20]


# In[92]:


mean1 = dataframe1.note.mean()
print(mean1)
mean_np= np.mean(dataframe1.note) 
print(mean_np)


# In[93]:


dataframe1.dropna(inplace=True) 
dataframe1


# In[94]:


print(dataframe1.note.mean())
dataframe1["mean"]= ["bad" if dataframe1.note.mean()>each else "good" for each in dataframe1.note]
dataframe1


# In[96]:


dataframe1.drop(["new_feature"],axis=1,inplace=True)
dataframe1


# In[100]:


data1 = dataframe1.head()     
data2 = dataframe1.tail()
data_concat = pd.concat([data1,data2],axis=0)
data_concat


# In[101]:


data_contact2 = pd.concat([data1,data2],axis=1)
data_contact2


# In[103]:


dataframe1["new_age"] = [each*2 for each in dataframe1.age]
dataframe1


# In[ ]:




