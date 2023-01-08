#Jan 8th 2023
# Made by : Elizabeh Ehebald


import pandas as pd 
import json
import csv
import matplotlib.pyplot as plt
import seaborn as sb
from datetime import datetime
import utm
import numpy as np
import sys


#
#try to find distance from 
#'Empty' 'Queue At LU' 'Spot at LU' 'Truck Loading' 'Queuing at Dump' 'Dumping' 'NON_PRODUCTIVE' 'Wenco General Production' 'Hauling'

#flag 
def map_UTM(data_set):

	lognitude = []
	latitude = []
	index_two = []
	for index, row in data_set.iterrows():

	
		if(row['GPSNORTHING'] < 0):
			#print('y')
			
			data_set = data_set.drop(labels = index, axis = 0)

			
		else:
			x,y =  utm.to_latlon(row['GPSEASTING'],row['GPSNORTHING'],44,'N')
		
			lognitude.append(x)
			latitude.append(y)
	


	data_set['lognitude'] = lognitude
	data_set['latitude'] = latitude

	#data_set = data_set.loc[ (data_set['STATUS'] == 'Truck Loading')]
	#sb.lmplot('lognitude', 'latitude', data=data_set, hue='SHOVEL_ID', fit_reg=False)


	sb.scatterplot(data = data_set, x = 'lognitude', y = 'latitude')
	grid = sb.FacetGrid(data_set, col = "SHOVEL_ID", hue = "SHOVEL_ID", col_wrap=3)
	grid.map(sb.scatterplot, "lognitude", "latitude")

	grid.add_legend()

	plt.savefig("log_lag_dump.png")

	plt.show()

def shortest_map(data_set, dump):



	lognitude = []
	latitude = []
	index_two = []
	for index, row in data_set.iterrows():

	
		if(row['GPSNORTHING'] < 0):
			#print('y')
			
			data_set = data_set.drop(labels = index, axis = 0)

			
		else:
			x,y =  utm.to_latlon(row['GPSEASTING'],row['GPSNORTHING'],44,'N')
		
			lognitude.append(x)
			latitude.append(y)
	


	data_set['lognitude'] = lognitude
	data_set['latitude'] = latitude
	print(dump)

	data_set = data_set.loc[ (data_set['DUMP_ID'] == dump)]
	#sb.lmplot('lognitude', 'latitude', data=data_set, hue='SHOVEL_ID', fit_reg=False)

	#sb.scatterplot(data = data_set, x = 'lognitude', y = 'latitude')
	#grid = sb.FacetGrid(data_set, col = "SHOVEL_ID", hue = "SHOVEL_ID", col_wrap=8)
	#grid.map(sb.scatterplot, "lognitude", "latitude")

	#grid.add_legend()

	plt.scatter(data_set['lognitude'],data_set['latitude'])
	plt.plot(data_set['lognitude'],data_set['latitude'])

	plt.savefig("3.png")

	plt.show()

	return plt

	

def least_gas_mileage(x, user_truck,user_shovel):
	date_copy  = x.copy()
	x = x.loc[(x['TRUCK_ID'] == user_truck) & (x['SHOVEL_ID'] == user_shovel)]
	print(x)

	#check if shovel is open 
	#check if the dump site is open
	x  = x.query("STATUS != 'DUMP'")
	for index, row in x.iterrows():

		if(x.empty):
			return ('The load site you requested is closed!')
			sys.exit('The load site you requested is closed!')
			break
	
	x = x.loc[(x['STATUS'] == 'Hauling') & (x['PAYLOAD']) !=0]
	date_copy = x
	print(x)
	
	#calculate how much gas was used in time
	a = x.groupby(['DUMP_ID']).mean()
	a = a.reset_index()
	print(a)
	best_miles =  a['FUEL_RATE'].min(axis = 0)
	a = a.loc[(a['FUEL_RATE'] == best_miles)]
	print('ok')
	print(a)
	b= a['DUMP_ID'].values[0]
	print(b, 'Dump_ID')
	

	
	

	shortest_map(date_copy,b)

def import_json(x):
	print()

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




def main():
	#import_json('data_group1.json')
	pd.set_option('display.max_columns', None)

	x = pd.read_csv('mining.csv',sep = ',')
	data_set = x.dropna()
	data_set['TIMESTAMP'] = pd.to_datetime(data_set['TIMESTAMP'])
	map_UTM(data_set)
	#calculate_average_gas_shovel_ID(data_set)
	#predict_fuel(data_set)
	user_truck = 37
	user_shovel = 3
	#print(data_set.head())

	message = least_gas_mileage(data_set, user_truck,user_shovel)
	print(message)

main()


print("ur mom")
