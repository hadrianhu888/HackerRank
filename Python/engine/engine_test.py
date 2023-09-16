import os 
import sys
import unittest
from unittest.mock import patch, MagicMock
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import engine 
from engine import Engine

class TestEngine(unittest.TestCase):
    def test_run_mac(self):
        with patch('engine.Engine.run_mac') as mock_run_mac:
            engine_obj = Engine()
            engine_obj.run()
            mock_run_mac.assert_called_once()
    
    def test_run_linux(self):
        with patch('engine.Engine.run_linux') as mock_run_linux:
            engine_obj = Engine()
            engine_obj.run()
            mock_run_linux.assert_called_once()
    
    def test_run_windows(self):
        with patch('engine.Engine.run_windows') as mock_run_windows:
            engine_obj = Engine()
            engine_obj.run()
            mock_run_windows.assert_called_once()
            
    def test_engine(self):
        engine_obj = Engine()
        self.assertEqual(engine_obj.engine_speed, 0)
        self.assertEqual(engine_obj.engine_architecture, "")
        self.assertEqual(engine_obj.engine_type, "")
        self.assertEqual(engine_obj.engine_version, "")
        self.assertEqual(engine_obj.engine_name, "")
        self.assertEqual(engine_obj.engine_vendor, "")
        self.assertEqual(engine_obj.engine_vendor_url, "")
        self.assertEqual(engine_obj.engine_vendor_support_url, "")
            
if __name__ == '__main__':
    unittest.main()
