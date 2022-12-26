from service import query_service
from utils import file_utils


def show_interface():
    print("1. Generate files")
    print("2. Merge files")
    print("3. Load to db")
    print("4. Calculate sum of int numbers and median of float numbers")
    print("5. Exit")
    opt = input("Choose option: ")
    if opt == '1':
        _generate_interface()
    if opt == '2':
        _merge_interface()
    if opt == '3':
        _load_interface()
    if opt == '4':
        _query_interface()
    if opt == '5':
        return


def _query_interface():
    result = query_service.get_sum_of_int_and_median_of_float()
    print('Sum of int numbers:', result[0][0])
    print('Median of float number', result[0][1])
    show_interface()


def _generate_interface():
    path_to_files = input("Enter the path where you want to create the files: ")
    file_utils.generate_files(path_to_files)
    show_interface()


def _merge_interface():
    path_to_files = input("Enter the path to folder where files are located: ")
    path_to_merged_file = input("Enter the path to folder where merged file will be located: ")
    merged_file_name = input("Enter name of the merged file: ")
    substr = input("Enter the substring to delete rows: ")
    file_utils.merge_files(path_to_files, path_to_merged_file, merged_file_name, substr)
    show_interface()


def _load_interface():
    path_to_file = input("Enter the path to a file: ")
    query_service.insert(path_to_file)
    show_interface()
