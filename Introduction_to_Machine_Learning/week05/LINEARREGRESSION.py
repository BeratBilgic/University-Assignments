#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import matplotlib.pyplot as plt
import numpy as np


# In[4]:


df=pd.read_csv("linear_regression_dataset.csv")
df


# In[7]:


df=pd.read_csv("linear_regression_dataset.csv",sep=";")
df


# In[8]:


plt.scatter(df.deneyim,df.maas)
plt.xlabel("experience")
plt.ylabel("salary")
plt.show()


# In[9]:


x=df.deneyim.values
x.shape


# In[10]:


x=df.deneyim.values.reshape(-1,1)
y=df.maas.values.reshape(-1,1)


# In[11]:


from sklearn.linear_model import LinearRegression
linear_reg=LinearRegression()
linear_reg.fit(x,y)


# In[15]:


b0=linear_reg.predict([[0]])
b0=linear_reg.intercept_
print(b0)


# In[16]:


b1=linear_reg.coef_
print(b1)


# In[17]:


new_salary=1663+1138*11
print(new_salary)


# In[18]:


b11=linear_reg.predict([[11]])
print(b11)


# In[19]:


y_head=linear_reg.predict(x)
plt.plot(x,y_head,color="red")
plt.scatter(x,y)
plt.show()


# In[20]:


from sklearn.metrics import r2_score
print("r square score",r2_score(y,y_head))


# In[ ]:




