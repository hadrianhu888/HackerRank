import winreg


def installed_programs():
    
    
    """
    Executes the installed programs retrieval process.

    Opens the Uninstall key in the Windows registry and iterates over all subkeys to find the DisplayName value of each program. Prints the DisplayName value if it exists.

    Args:
        None

    Returns:
        None

    Raises:
        OSError: Raised when an error occurs while accessing the registry.

    Example:
        ```python
        installed_programs()
        ```
    """

    # Open the Uninstall key.
    # The comment `# Open the Uninstall key.` is describing the purpose of the code line that follows
    # it. In this case, the code line `key = winreg.OpenKey(winreg.HKEY_LOCAL_MACHINE,
    # r"SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall", 0, winreg.KEY_READ |
    # winreg.KEY_WOW64_64KEY)` is opening the Uninstall key in the Windows registry. This key contains
    # information about the installed programs on the system.
    key = winreg.OpenKey(
        winreg.HKEY_LOCAL_MACHINE,
        r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall",
        0,
        winreg.KEY_READ | winreg.KEY_WOW64_64KEY
    )

    # Iterate over all subkeys.
    for i in range(0, winreg.QueryInfoKey(key)[0]):
        skey_name = winreg.EnumKey(key, i)
        skey = winreg.OpenKey(key, skey_name)
        try:
            # Look for the DisplayName value.
            disp_name = winreg.QueryValueEx(skey, 'DisplayName')[0]
            print(disp_name)
        except OSError:
            pass
        finally:
            skey.Close()

    key.Close()
    
    
def main(): 
    installed_programs()
    


