import subprocess

def save_installed_programs_windows(filename):
    with open(filename, 'w') as file, open('error_log.txt', 'w') as error_file:
        completed_process = subprocess.run(['C:\\Windows\\System32\\wbem\\wmic', 'product', 'get', 'name'], stdout=file, stderr=error_file, text=True)
        
        # Check return code (0 usually indicates success)
        print("Return code:", completed_process.returncode)

save_installed_programs_windows('.\\installed_programs.txt')
