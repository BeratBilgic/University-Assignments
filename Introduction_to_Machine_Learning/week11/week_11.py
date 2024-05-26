#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import warnings
warnings.filterwarnings("ignore")


# In[2]:


data = "car_evaluation.csv"
df = pd.read_csv(data, header=None)


# In[3]:


df.shape


# In[4]:


df.head()


# In[5]:


col_names = ["buying","maint","doors","person","lug_boot", "safety", "class"]
df.columns = col_names


# In[6]:


df.head()


# In[7]:


df.info()


# In[8]:


for col in col_names:
  print(df[col].value_counts())


# In[9]:


df["class"].value_counts()


# In[10]:


df.isnull().sum()


# In[11]:


x = df.drop(["class"],axis=1)


# In[12]:


y = df["class"]


# In[13]:


from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x,y, test_size=0.3,random_state=42)


# In[14]:


x_train.shape


# In[15]:


x_test.shape


# In[16]:


x_train.dtypes


# In[17]:


x_train.head()


# In[21]:


#pip install category-encoders
import category_encoders as ce


# In[22]:


encoder = ce.OrdinalEncoder(cols=["buying","maint","doors","person","lug_boot", "safety"])
x_train = encoder.fit_transform(x_train)
x_test = encoder.transform(x_test)


# In[23]:


x_train.head()


# In[24]:


x_test.head()


# In[25]:


from sklearn.ensemble import RandomForestClassifier

rfc = RandomForestClassifier(n_estimators=10,random_state=0)
rfc.fit(x_train,y_train)
y_pred = rfc.predict(x_test)


# In[26]:


from sklearn.metrics import accuracy_score
print("Model Accuracy: {0:0.4f}".format(accuracy_score(y_test,y_pred)))


# In[27]:


rfc_100 = RandomForestClassifier(n_estimators=100,random_state=0)
rfc_100.fit(x_train,y_train)
y_pred_100 = rfc_100.predict(x_test)
print("Model Accuracy with  100 decision tree: {0:0.4f}".format(accuracy_score(y_test,y_pred_100)))


# In[ ]:




