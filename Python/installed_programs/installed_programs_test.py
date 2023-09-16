import os
import sys
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import unittest
from unittest.mock import patch, MagicMock
from installed_programs import InstalledPrograms

class TestGetInstalledPrograms(unittest.TestCase):

    @patch('winreg.OpenKey')
    @patch('winreg.QueryInfoKey')
    @patch('winreg.EnumKey')
    @patch('winreg.QueryValueEx')
    def test_get_installed_programs(self, mock_query_value, mock_enum_key, mock_query_info, mock_open_key):
        mock_query_info.return_value = (2, None)
        mock_enum_key.side_effect = ["subkey1", "subkey2"]
        mock_query_value.return_value = ("Program1", None)

        installed_programs_obj = InstalledPrograms()
        installed_programs_obj.get_installed_programs()

        with open("installed_programs_windows.txt", "r") as f:
            programs = f.read().split("\n")

        self.assertEqual(programs, ["Program1", "Program1", ""])

if __name__ == '__main__':
    unittest.main()
