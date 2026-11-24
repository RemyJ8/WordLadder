
import os
from collections import defaultdict

def preprocess_dictionary(input_file):
    output_dir = "data/processed"
    os.makedirs(output_dir, exist_ok=True)

    # 1. Read words from the input file
    with open(input_file, "r", encoding="utf-8") as file:
        words = file.read().splitlines()

    total_words = len(words)

    # 2. Normalize words to lowercase
    words = [word.strip().lower() for word in words]

    # Remove empty lines
    words = [word for word in words if word]

    # 3. Remove duplicates
    unique_words = set(words)

    # 4. Filter words between 3 and 8 letters
    filtered_words = [
        word for word in unique_words
        if word.isalpha() and 3 <= len(word) <= 8
    ]

    # 5. Split words according to their length
    dictionaries = defaultdict(list)

    for word in filtered_words:
        dictionaries[len(word)].append(word)

    # 6. Create a separate file for each word length
    print("\nDICTIONARY STATISTICS")
    print("-" * 40)

    for length in range(3, 9):
        length_words = sorted(dictionaries[length])

        filename = os.path.join(
            output_dir, f"dictionary_{length}_letters.txt"
        )

        with open(filename, "w", encoding="utf-8") as file:
            for word in length_words:
                file.write(word + "\n")

        print(f"{length}-letter words: {len(length_words)}")

    # 7. Generate general statistics
    print("-" * 40)
    print(f"Original entries: {total_words}")
    print(f"Unique entries: {len(unique_words)}")
    print(f"Filtered entries: {len(filtered_words)}")
    print(f"Removed entries: {len(unique_words) - len(filtered_words)}")
    print(f"Total dictionaries created: 6")
    print(f"Output directory: {output_dir}")


if __name__ == "__main__":
    input_file = "data/original/words_alpha.txt"

    if os.path.exists(input_file):
        preprocess_dictionary(input_file)
    else:
        print("Error: data/original/words_alpha.txt was not found.")
