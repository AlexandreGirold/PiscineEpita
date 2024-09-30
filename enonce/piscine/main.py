from exercises import *
import requests
import undetected_chromedriver as uc
import csv

f = open("site.txt",'r')

listOfExercises = []

for line in f:
    exercise =  Exercises()
    name = line.split("/exercises~shell/")[1].split("&quot")[0]
    required = line.split("&quot;_required=")[1].split("/")[0]
    exercise.name = name
    exercise.required = required

    if(check(name, listOfExercises)):
        listOfExercises.append(exercise)

def writeLogsCSV(listOfProfiles, fileName):
    csvfile = open("Shell/"+fileName, 'w', newline='')
    fieldNames = ['name', 'required']
    writer = csv.DictWriter(csvfile,fieldnames=fieldNames)
    writer.writeheader()

    for profile in listOfProfiles:
        writer.writerow({
            'name': profile.name,
            'required': profile.required
        })
    csvfile.close()


writeLogsCSV(listOfExercises, "_listOfExercises.csv")


chunk_size = 2000

driver = uc.Chrome()
driver.get("https://intra.forge.epita.fr/epita-ing-assistants-acu/piscine-2025/")

input()    
browserCookies = driver.get_cookies()
driver.close()
s = requests.Session()
c = [s.cookies.set(c['name'],c['value']) for c in browserCookies]


s.get("https://intra.forge.epita.fr/epita-ing-assistants-yaka")
