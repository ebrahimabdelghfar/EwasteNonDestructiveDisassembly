import json
from os import path
DB_FILE_PATH = '/home/himaet23/EwasteNonDestructiveDisassembly/src/CentralNode/src/storage/get_tool_schedule.json'



class ChangeToolScheduleDatabase(object):

    _instance = None
    def __new__(self):
        if not self._instance:
            self._instance = super(ChangeToolScheduleDatabase,self).__new__(self)
            self.config = {}
        return self._instance
    

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
    f = ChangeToolScheduleDatabase()

    print(ChangeToolScheduleDatabase().readFromDB("Mohsen"))