#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
import os


# In[72]:


titanic_train = pd.read_csv("train.csv")


# In[16]:


titanic_train.shape     


# In[50]:


titanic_train.head(5)


# In[51]:


categorical = titanic_train.dtypes[titanic_train.dtypes == "object"].index
print(categorical)

titanic_train[categorical].describe()


# In[52]:


titanic_train["Ticket"][0:15]       


# In[29]:


titanic_train["Ticket"].describe()


# In[30]:


del titanic_train["Ticket"] 


# In[53]:


new_Pclass = pd.Categorical(titanic_train["Pclass"], ordered=True)

new_Pclass = new_Pclass.rename_categories(["Class1","Class2","Class3"])     

new_Pclass.describe()


# In[57]:


titanic_train["Pclass"] = new_Pclass
titanic_train.head()


# In[56]:


titanic_train["Cabin"].unique()  


# In[34]:


char_cabin = titanic_train["Cabin"].astype(str) # Convert data to str

new_Cabin = np.array([cabin[0] for cabin in char_cabin]) # Take first letter

new_Cabin = pd.Categorical(new_Cabin)

new_Cabin .describe()


# In[58]:


titanic_train["Cabin"] = new_Cabin
titanic_train.head()


# In[36]:


dummy_vector = pd.Series([1,None,3,None,7,8])

dummy_vector.isnull()


# In[37]:


titanic_train["Age"].describe()


# In[38]:


missing = np.where(titanic_train["Age"].isnull() == True)
missing


# In[39]:


len(missing[0])


# In[64]:


titanic_train.hist(column='Age',    # Column to plot
                   figsize=(9,6),   # Plot size
                   bins=20)         # Number of histogram bins


# In[73]:


new_age_var = np.where(titanic_train["Age"].isnull(), # Logical check
                       28,                       # Value if check is true
                       titanic_train["Age"])     # Value if check is false

titanic_train["Age"] = new_age_var 

titanic_train["Age"].describe()


# In[74]:


titanic_train.hist(column='Age',    # Column to plot
                   figsize=(9,6),   # Plot size
                   bins=20)         # Number of histogram bins

