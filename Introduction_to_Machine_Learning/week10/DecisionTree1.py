#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


# In[2]:


dataset = pd.read_csv("mushrooms.csv")


# In[3]:


dataset.head()


# In[4]:


dataset.isnull().sum()


# In[5]:


dataset["class"].unique()


# In[6]:


dataset.info()


# In[7]:


dataset.shape


# In[8]:


sns.histplot(dataset["class"])


# In[9]:


x = dataset.drop(["class"],axis=1)


# In[10]:


y= dataset["class"]


# In[11]:


x = pd.get_dummies(x)
x.head()


# In[12]:


from sklearn.preprocessing import LabelEncoder
encoder =LabelEncoder()
y = encoder.fit_transform(y)
print(y)


# In[13]:


from sklearn.model_selection import train_test_split
x_train, x_test, y_train,y_test= train_test_split(x,y,test_size=0.2,random_state=1)
x_train.shape, x_test.shape


# In[14]:


y_train.shape, y_test.shape


# In[15]:


from sklearn.tree import DecisionTreeClassifier
from sklearn import tree
from sklearn.metrics import accuracy_score


# In[16]:


clf_gini = DecisionTreeClassifier(criterion="gini",max_depth=3,random_state=0)


# In[17]:


clf_gini.fit(x_train,y_train)


# In[18]:


plt.figure(figsize=(12,8))
tree.plot_tree(clf_gini.fit(x_train,y_train))


# In[19]:


y_pred_gini=clf_gini.predict(x_test)


# In[20]:


y_pred_train_gini = clf_gini.predict(x_train)


# In[21]:


y_pred_train_gini


# In[22]:


y_pred_gini


# In[23]:


print("model accuracy score with the criterion gini index: {0:0.4f}".format(accuracy_score(y_test,y_pred_gini)))
print("model accuracy score : {0:0.4f}".format(accuracy_score(y_train,y_pred_train_gini)))


# In[24]:


from sklearn.metrics import confusion_matrix
from sklearn.metrics import classification_report
from sklearn.metrics import f1_score


# In[25]:


cm= confusion_matrix(y_test,y_pred_gini)
print(cm)


# In[26]:


f,ax= plt.subplots(figsize=(10,10))
sns.heatmap(cm, annot=True, linewidth=0.5, linecolor="red",fmt=".0f",ax=ax)
plt.show()


# In[27]:


print(classification_report(y_test,y_pred_gini))


# In[28]:


f1_score= f1_score(y_test,y_pred_gini)
print(f1_score)


# In[ ]:




