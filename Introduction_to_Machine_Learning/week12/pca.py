#!/usr/bin/env python
# coding: utf-8

# In[25]:


pip install tensorflow
pip install distutils


# In[16]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
get_ipython().run_line_magic('matplotlib', 'inline')
import seaborn as sns 


# In[17]:


from tensorflow.keras.datasets import cifar10
(x_train,y_train),(x_test,y_test)=cifar10.load_data()
print("training data shape:",x_train.shape)
print("test data shape:",x_test.shape)


# In[18]:


classes=np.unique(y_train)
nClasses=len(classes)
print('total number of outputs:',nClasses)
print('output classes:',classes)


# In[19]:


label_dict={
    0:'airplane',
    1:'automobile',
    2:'bird',
    3:'cat',
    4:'deer',
    5:'dog',
    6:'frog',
    7:'horse',
    8:'ship',
    9:'truck'
}


# In[20]:


plt.figure(figsize=[5,5])
plt.subplot(121)
curr_img=np.reshape(x_train[0],(32,32,3))
plt.imshow(curr_img)
print(plt.title("(Label:" +str(label_dict[y_train[0][0]])+")"))

plt.subplot(122)
curr_img=np.reshape(x_test[0],(32,32,3))
plt.imshow(curr_img)
print(plt.title("(Label:" +str(label_dict[y_test[0][0]])+")"))



# In[21]:


np.min(x_train),np.max(x_train)


# In[22]:


x_train=x_train/255.0


# In[23]:


np.min(x_train),np.max(x_train)


# In[24]:


x_train_flat=x_train.reshape(-1,3072)
feat_cols=['pixel'+str(i) for i in range(x_train_flat.shape[1])]
df_cifar=pd.DataFrame(x_train_flat,columns=feat_cols)
df_cifar['label']=y_train
print('size of dataframe:{}'.format(df_cifar.shape))


# In[25]:


df_cifar.head()


# In[26]:


from sklearn.decomposition import PCA
pca_cifar=PCA(n_components=2)
principalcomponent_cifar=pca_cifar.fit_transform(df_cifar.iloc[:,:-1])


# In[27]:


principal_cifar_Df=pd.DataFrame(data=principalcomponent_cifar,columns=['principal component 1','principal component 2'])
principal_cifar_Df['y']=y_train


# In[28]:


principal_cifar_Df.head()


# In[29]:


pca_cifar.explained_variance_ratio_


# In[30]:


plt.figure(figsize=(16,10))
sns.scatterplot(
    x="principal component 1",y="principal component 2",
    hue="y",
    palette=sns.color_palette("hls",10),
    data=principal_cifar_Df,
    legend="full",
    alpha=0.3
)


# In[ ]:




