import json
from os import path
import storage_keys as StorageKeys
from CentralNode.src.storage.change_tool_database import ChangeToolScheduleDatabase
DB_FILE_PATH = '/home/himaet23/EwasteNonDestructiveDisassembly/src/CentralNode/src/storage/configuration.json'



class RobotDatabase(object):

    _instance = None
    def __new__(self):
        if not self._instance:
            self._instance = super(RobotDatabase,self).__new__(self)
            self.config = {}
        return self._instance
    
    def getScrewSchedule(self):
        return ChangeToolScheduleDatabase().readFromDB(StorageKeys.GET_SCREW_SCHEDULE)
        
    def getMillingSchedule(self):
        return ChangeToolScheduleDatabase().readFromDB(StorageKeys.GET_MILL_SCHEDULE)
    
    def returnMillingSchedule(self):
        return ChangeToolScheduleDatabase().readFromDB(StorageKeys.RETURN_MILL_SCHEDULE)
    
    def returnScrewSchedule(self):
        return ChangeToolScheduleDatabase().readFromDB(StorageKeys.RETURN_SCREW_SCHEDULE)

    def addToDB(self, key, value):
        self.checkFile()
        self.readFile()
        self.config[key] = value
        self.saveFile()
        self.resetConfig()

    def readFromDB(self, key):
        self.checkFile()
        self.readFile()
        val = self.config[key]
        self.resetConfig()
        return val

    def readAllFromDB(self):
        self.checkFile()
        self.readFile()
        val = self.config
        self.resetConfig()
        return val

    def resetWholeFile(self):
        self.checkFile()
        self.config = {}
        self.saveFile()

    def isNotEmpty(self):
        return self.readAllFromDB() != {}

    def checkFile(self):
        if path.isfile(DB_FILE_PATH) is False:
            raise Exception("File not found")
        
    def readFile(self):
        with open(DB_FILE_PATH) as db:
            self.config = json.load(db)

    def saveFile(self):
        with open(DB_FILE_PATH, 'w') as db:
            json.dump(self.config, db)

    def resetConfig(self):
        self.config = {}

if __name__ == "__main__":
    print("Hello, World!")
    f = RobotDatabase()
    f.addToDB("Mohsen", "Computer")

    print(RobotDatabase().readFromDB("Mohsen"))