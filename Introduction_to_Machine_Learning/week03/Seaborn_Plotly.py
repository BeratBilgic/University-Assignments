#!/usr/bin/env python
# coding: utf-8

# In[76]:


pip install seaborn


# In[79]:


# importing packages
import seaborn as sns
import matplotlib.pyplot as plt

# loading dataset x
data = sns.load_dataset("iris")

# draw lineplot
sns.lineplot(x="sepal_length", y="sepal_width", data=data)
plt.title('Title using Matplotlib Function')
plt.xlim(5)
sns.set_style("dark")

plt.show()


# In[80]:


import seaborn as sns

import matplotlib.pyplot as plt

tips = sns.load_dataset("tips")

# customize the scatter plot

sns.scatterplot(x="total_bill", y="tip", hue="sex", size="size", sizes=(50, 200), data=tips)

# add labels and title

plt.xlabel("Total Bill")

plt.ylabel("Tip")

plt.title("Relationship between Total Bill and Tip")

plt.show()


# In[81]:


import seaborn as sns

import matplotlib.pyplot as plt

titanic = sns.load_dataset("titanic")

# customize the bar plot

sns.barplot(x="class", y="fare", hue="sex", palette="muted", data=titanic)

# add labels and title

plt.xlabel("Class")

plt.ylabel("Fare")

plt.title("Average Fare by Class and Gender on the Titanic")

plt.show()


# In[84]:


import seaborn as sns

import matplotlib.pyplot as plt

# Load the dataset
flights = sns.load_dataset('flights')

# Pivot the data
flights = flights.pivot(index='month', columns='year', values='passengers')

# Create a heatmap
sns.heatmap(flights, cmap='Blues', annot=True, fmt='d')

# Set the title and axis labels
plt.title('Passengers per month')

plt.xlabel('Year')

plt.ylabel('Month')

plt.show()


# In[85]:


import seaborn as sns

import matplotlib.pyplot as plt

# load the tips dataset from Seaborn
tips = sns.load_dataset("tips")

sns.boxplot(x="day", y="total_bill", hue="time", data=tips, palette="Set3", linewidth=1.5, fliersize=4)


# add a title, xlabel, and ylabel to the plot using Matplotlib functions

plt.title("Box Plot of Total Bill by Day and Meal Time")

plt.xlabel("Day of the Week")

plt.ylabel("Total Bill ($)")

plt.show()


# In[97]:


pip install plotly


# In[98]:


pip install plotly.express


# In[100]:


import plotly.express as px


# Creating the Figure instance
fig = px.line(x=[1, 2, 3], y=[1, 2, 3])

# showing the plot
fig.show()


# In[91]:


import plotly.express as px

# using the iris dataset
df = px.data.iris()

# plotting the line chart
fig = px.line(df, x="species", y="petal_width")

# showing the plot
fig.show()


# In[92]:


import plotly.express as px

# using the iris dataset
df = px.data.iris()

# plotting the bar chart
fig = px.bar(df, x="sepal_width", y="sepal_length")

# showing the plot
fig.show()


# In[93]:


import plotly.express as px

# using the iris dataset
df = px.data.iris()

# plotting the histogram
fig = px.histogram(df, x="sepal_length", y="petal_width")

# showing the plot
fig.show()


# In[94]:


import plotly.express as px

# using the iris dataset
df = px.data.iris()

# plotting the scatter chart
fig = px.scatter(df, x="species", y="petal_width")

# showing the plot
fig.show()


# In[95]:


import plotly.express as px

# using the tips dataset
df = px.data.tips()

# plotting the pie chart
fig = px.pie(df, values="total_bill", names="day")

# showing the plot
fig.show()


# In[ ]:




