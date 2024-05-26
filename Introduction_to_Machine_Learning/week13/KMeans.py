#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


# In[2]:


dataset = pd.read_csv("Mall_Customers.csv")


# In[3]:


dataset.head(10)


# In[4]:


dataset.shape


# In[5]:


dataset.info()


# In[6]:


dataset.isnull().sum()


# In[7]:


x=dataset.iloc[:,[3,4]].values


# In[8]:


from sklearn.cluster import KMeans


# In[9]:


wcss=[]
for i in range(1,11):
    kmeans=KMeans(n_clusters=i,init="k-means++",random_state=0)
    kmeans.fit(x)
    wcss.append(kmeans.inertia_)


# In[10]:


plt.plot(range(1,11),wcss)
plt.title("elbow method")
plt.xlabel("no of cluster")
plt.ylabel("wcss")
plt.show()


# In[11]:


kmeansmodel=KMeans(n_clusters=5,init="k-means++",random_state=0)
y_kmeans=kmeansmodel.fit_predict(x)


# In[12]:


plt.scatter(x[y_kmeans==0,0],x[y_kmeans==0,1],s=100,c="red",label="cluster 1")
plt.scatter(x[y_kmeans==1,0],x[y_kmeans==1,1],s=100,c="blue",label="cluster 2")
plt.scatter(x[y_kmeans==2,0],x[y_kmeans==2,1],s=100,c="green",label="cluster 3")
plt.scatter(x[y_kmeans==3,0],x[y_kmeans==3,1],s=100,c="cyan",label="cluster 4")
plt.scatter(x[y_kmeans==4,0],x[y_kmeans==4,1],s=100,c="magenta",label="cluster 5")

plt.scatter(kmeans.cluster_centers_[:,0],kmeans.cluster_centers_[:,1],s=300,c="yellow",label="centroids")
plt.title("müşteri classları")
plt.xlabel("yıllık gelir")
plt.ylabel("harcama skoru")
plt.legend()
plt.show()


# In[ ]:




