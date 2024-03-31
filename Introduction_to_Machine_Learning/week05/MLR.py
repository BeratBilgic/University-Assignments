#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt 
import seaborn as sns


# In[7]:


df=pd.read_csv("advertising.csv")


# In[8]:


df.head()


# In[9]:


df.info()


# In[5]:


from sklearn.model_selection import train_test_split


# In[6]:


x = df[['TV','Radio','Newspaper']]
y=df['Sales']


# In[11]:


x_train, x_test, y_train, y_test = train_test_split(x,y, test_size=0.3, random_state=100)


# In[12]:


from sklearn.linear_model import LinearRegression
mlr=LinearRegression()
mlr.fit(x_train,y_train)


# In[13]:


print("Intercept:", mlr.intercept_)


# In[14]:


print("Coefficents:", list(zip(x, mlr.coef_)))


# In[15]:


y_pred = mlr.predict(x_test)
print("prediction for test set: {}".format(y_pred))


# In[16]:


mlr_dff = pd.DataFrame({"Actual values": y_test, "Prediciton values":y_pred})
mlr_dff.head()


# In[17]:


from sklearn import metrics 
meansqerr = metrics.mean_squared_error(y_test,y_pred)
print("R squared: {:.2f}".format(mlr.score(x,y)*100))
print("Mean Squared error:", meansqerr)


# In[ ]:




