#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


# In[2]:


data=pd.read_csv("data.csv")


# In[3]:


data.tail()


# In[4]:


data.drop(["Unnamed: 32","id"],axis=1,inplace=True)


# In[5]:


M= data[data.diagnosis =="M"]
B= data[data.diagnosis =="B"]


# In[6]:


plt.scatter(M.radius_mean,M.texture_mean,color="red",label="kotu",alpha=0.3)
plt.scatter(B.radius_mean,B.texture_mean,color="green",label="iyi",alpha=0.3)
plt.xlabel("radius_mean(radius of the tumor)")
plt.ylabel("texture_mean(texture of the tumor)")
plt.legend()
plt.show()




# In[7]:


data.diagnosis = [1 if each == "M" else 0 for each in data.diagnosis]
y= data.diagnosis.values
x_data= data.drop(["diagnosis"],axis=1) 


# In[8]:


x=(x_data - np.min(x_data))/(np.max(x_data)-np.min(x_data))


# In[9]:


from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test= train_test_split(x,y,test_size=0.3,random_state=1)


# In[10]:


from sklearn.naive_bayes import GaussianNB
nb= GaussianNB()
nb.fit(x_train,y_train)


# In[11]:


print("accuracy of svm algorithm: ",nb.score(x_test,y_test))


# In[ ]:




