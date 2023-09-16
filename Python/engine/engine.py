import os
import sys
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

class Engine:
    """_summary_
    """
    engine_speed = 0
    engine_architecture = ""
    engine_type = ""
    engine_version = ""
    engine_name = ""
    engine_vendor = ""
    engine_vendor_url = ""
    engine_vendor_support_url = ""
    def __init__(self):
        """_summary_
        """
        self.engine_speed = 0
        self.engine_architecture = ""
        self.engine_type = ""
        self.engine_version = ""
        self.engine_name = ""
        self.engine_vendor = ""
        self.engine_vendor_url = ""
        self.engine_vendor_support_url = ""

    def run(self):
        """_summary_
        """
        self.run_windows()
        self.run_linux()
        self.run_mac()
            
    def run_windows(self):
        print("Windows")
        
    def run_linux(self):
        print("Linux")
        
    def run_mac(self):
        print("Mac")
    
def main():
    """_summary_
    """
    engine_obj = Engine()
    engine_obj.run()

if __name__ == "__main__":
    main()