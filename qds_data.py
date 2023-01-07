import pandas as pd 
import json
import csv
import matplotlib.pyplot as plt
import seaborn as sb
from datetime import datetime
import utm




#df1 = pd.read_json('data_group1.json', lines = True)
#df2 = pd.read_json('data_group2.json', lines = True)
#df3 = pd.read_json('data_group3.json', lines = True)
#df4 = pd.read_json('data_group4.json', lines = True)
#df5 = pd.read_json('data_group5.json', lines = True)
#df6 = pd.read_json('data_group6.json', lines = True)
#df7 = pd.read_json('data_group7.json', lines = True)
#df8 = pd.read_json('data_group8.json', lines = True)
#df9 = pd.read_json('data_group9.json', lines = True)


#converts the json to dataframe 

#"C:\Users\lizzy\OneDrive\Desktop\QDS Tournament\data_group0.json"

#df0 = open('data_group1.json')
#df0 = json.load(df0)

#new = pd.DataFrame.from_dict(df0)
#print(new.head())
#new.to_csv('mining.csv',index = None)

x = pd.read_csv('mining.csv',sep = ',')
data_set = x.dropna()

#plt.scatter(x['FUEL_RATE'],x['PAYLOAD'], c = 'black')
#plt.xlabel('FUEL_RATE')
#plt.ylabel('PAYLOAD')
#pltlt.show()

data_set['TIMESTAMP'] = pd.to_datetime(data_set['TIMESTAMP'])


#print(x.groupby(['TRUCK_TYPE_ID']).mean())

#print(x['FUEL_RATE'].unique())
#print(x['STATUS'])

#sb.pairplot(x[['FUEL_RATE','PAYLOAD', 'TRUCK_ID','SHOVEL_ID','DUMP_ID','GPSEASTING']], diag_kind = 'kde')
#plt.savefig("test_fuel.png")
#plt.show()

#print(x.describe().transpose())




#print(utm.to_latlon(x['GPSEASTING'],x['GPSNORTHING'],44,'N'))

#
#try to find distance from 
#'Empty' 'Queue At LU' 'Spot at LU' 'Truck Loading' 'Queuing at Dump' 'Dumping' 'NON_PRODUCTIVE' 'Wenco General Production' 'Hauling'

#flag 
def map_UTM():

	lognitude = []
	latitude = []
	for index, row in data_set.iterrows():

	
		if(row['GPSNORTHING'] < 0):
			print('y')
			x,y =  utm.to_latlon(row['GPSEASTING'],row['GPSNORTHING'],38,'S')
		
			lognitude.append(x)
			latitude.append(y)
			#array.append(row['GPSNORTHING'])
		else:
			x,y =  utm.to_latlon(row['GPSEASTING'],row['GPSNORTHING'],44,'N')
		
			lognitude.append(x)
			latitude.append(y)
		

	plt.scatter(lognitude,latitude, c = 'black')
	plt.xlabel('lognitude')
	plt.ylabel('latitude')
	plt.show()





map_UTM()

#want countplot payload shovel id 




#df0 = pd.read_csv('mining.csv', sep = ',')

#print(df0.head())
#print(df0.columns)
#df.to_csv('dfo.csv')

#print(df0.to_string())


#df = pd.DataFrame(df0)
#print(df.head())

#frames =  [df0]

#dataset = pd.concat(frames, ignore_index = True)
#print(dataset.head())
