import pkg_resources

def save_to_file(file_name, data):
    with open(file_name, "w") as f:
        for item in data:
            f.write(str(item) + "\n")

def display_list(data):
    for item in data:
        print(item)

def display_file_content(file_name):
    with open(file_name, "r") as f:
        for line in f:
            print(line.strip())

def list_installed_packages():
    installed_packages = [str(pkg) for pkg in pkg_resources.working_set]
    for package in installed_packages:
        print(package)
        
def check_file_exist(file_name):
    try:
        with open(file_name, "r") as f:
            pass
    except FileNotFoundError:
        print(f"File {file_name} does not exist")
        
def append_file(file_name, data):
    with open(file_name, "a") as f:
        for item in data:
            f.write(str(item) + "\n")

def main():
    installed_packages = [str(pkg) for pkg in pkg_resources.working_set]
    list_installed_packages()
    save_to_file("installed_packages.txt", installed_packages)
    display_file_content("installed_packages.txt")
    display_list(installed_packages)

if __name__ == '__main__':
    main()

