import datetime
import random
import string
import os


def generate_files(path: str):
    num_files = 100
    num_lines = 100000
    for i in range(num_files):
        with open(path + f"file_{i}.txt", "w", encoding="utf-8") as f:
            for j in range(num_lines):
                f.write(
                    f"{_random_date()}||{_random_latin_set()}||{_random_russian_set()}||{_random_even_integer()}||{_random_float_number()}\n")


def merge_files(path_to_files: str, path_to_merged_file: str, merged_file_name: str, substr: str):
    counter = 0
    with open(os.path.join(path_to_merged_file, merged_file_name), "w", encoding="utf-8") as outfile:
        if substr and substr.strip():
            for filename in os.listdir(path_to_files):
                with open(os.path.join(path_to_files, filename), "r", encoding="utf-8") as infile:
                    for line in infile:
                        if substr not in line:
                            outfile.write(line)
                        else:
                            counter += 1
        else:
            for filename in os.listdir(path_to_files):
                with open(os.path.join(path_to_files, filename), "r", encoding="utf-8") as infile:
                    for line in infile:
                        outfile.write(line)
    print("Number of deleted rows: ", counter)


def _random_date():
    start_date = datetime.datetime.now() - datetime.timedelta(days=365 * 5 + 1)
    return (start_date + datetime.timedelta(days=random.randint(0, 365 * 5 + 1))).strftime("%d.%m.%Y")


def _random_latin_set():
    return ''.join(random.choice(string.ascii_letters) for _ in range(10))


def _random_russian_set():
    return ''.join(chr(random.randint(ord('А'), ord('я'))) for _ in range(10))


def _random_even_integer():
    return random.randint(1, 50000000) * 2


def _random_float_number():
    return round(random.uniform(1, 20), 8)
