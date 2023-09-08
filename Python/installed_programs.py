import subprocess
import os

def save_installed_programs_windows(filename):
    with open(filename, 'w') as file, open('error_log.txt', 'w') as error_file:
        completed_process = subprocess.run(['C:\\Windows\\System32\\wbem\\wmic', 'product', 'get', 'name'], stdout=file, stderr=error_file, text=True)
        
        # Check return code (0 usually indicates success)
        print("Return code:", completed_process.returncode)

save_installed_programs_windows('.\\installed_programs.txt')

def main():
	save_installed_programs_windows('.\\installed_programs.txt')
	# if file already exists, append to it
	if (os.path.exists('.\\installed_programs.txt')):
		with open('.\\installed_programs.txt', 'a') as file, open('error_log.txt', 'a') as error_file:
			completed_process = subprocess.run(['C:\\Windows\\System32\\wbem\\wmic', 'product', 'get', 'name'], stdout=file, stderr=error_file, text=True)
			print("Return code:", completed_process.returncode)
	else:
		save_installed_programs_windows('.\\installed_programs.txt')
	# make sure if the file is already written, it is not overwritten with the same data repetitively
	if (os.path.exists('installed_programs.txt')):
		with open('installed_programs.txt', 'r') as file:
			# read the file
			contents = file.read()
			# check if the file is empty
			if (contents == ''):
				save_installed_programs_windows('.\\installed_programs.txt')
			else:
				print('File already written, not writing again.')
	else:
		save_installed_programs_windows('.\\installed_programs.txt')
	# also make sure that if there are new programs, they are appended to the file and if programs are removed, they are deleted from the original file
	# this is done by comparing the contents of the file with the contents of the file after the program is run
	# if the contents are the same, then the file is not written to again
	# if the contents are different, then the file is written to again
	if (os.path.exists('installed_programs.txt')):
		with open('installed_programs.txt', 'r') as file:
			# read the file
			contents = file.read()
			# check if the file is empty
			if (contents == ''):
				save_installed_programs_windows('.\\installed_programs.txt')
			else:
				# write to the file again
				save_installed_programs_windows('.\\installed_programs.txt')
	else:
		save_installed_programs_windows('.\\installed_programs.txt')
	# display file contents to the user
	with open('installed_programs.txt', 'r') as file:
		contents = file.read()
		print(contents)
	

if __name__ == '__main__':
	main()