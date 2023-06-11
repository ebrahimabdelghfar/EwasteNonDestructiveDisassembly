#list of dictionaries
class NodeName:
    def __init__(self):
        self.NodesExist = [ "/checkMotors",
                            "/ft_sensor_driver"
                          ]
        #self.NodeInfo = {"/nodename": ["packageName","exceutable","nodename"],
        self.NodeInfo = {"/checkMotors": ["checkMotors","checkMotorsNode.py","checkMotors"],
                         "/ft_sensor_driver": ["ft_sensor_driver","ft_sensor_driver.py","ft_sensor_driver"]
                         }
        pass
