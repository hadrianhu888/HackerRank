import winreg

import contextlib

def get_installed_programs():
    installed_programs = []
    registry_path = r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall"

    with winreg.OpenKey(winreg.HKEY_LOCAL_MACHINE, registry_path) as key:
        for i in range(winreg.QueryInfoKey(key)[0]):
            subkey_name = winreg.EnumKey(key, i)
            with winreg.OpenKey(key, subkey_name) as subkey:
                with contextlib.suppress(FileNotFoundError):
                    program_name = winreg.QueryValueEx(subkey, "DisplayName")[0]
                    installed_programs.append(program_name)

    with open("installed_programs_windows.txt", "w") as f:
        for program in installed_programs:
            f.write(program + "\n")

if __name__ == "__main__":
    get_installed_programs()
    print("List of installed programs has been saved to installed_programs_windows.txt")
