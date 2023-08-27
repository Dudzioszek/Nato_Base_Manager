
# NATO Bases Database Management

## Overview

The NATO Bases project is a C++ based application designed for managing a database of NATO bases located in the Eastern Flank. This application provides an interface for NATO officials to keep track, modify, and analyze the resources and facilities of various bases, especially in the context of potential threats.

It has been made as a project for my OOP studies.

## Features

- **Base Management:** Add, edit, remove, and display information about various NATO bases.
- **Detailed Records:** Each base record includes details such as its name, country, city, and inventory (rifles, tanks, planes, and rocket launchers).
- **Unique Identification:** Each base is assigned a unique ID for easy reference and modifications.
- **Data Persistence:** The ability to save all base data to a `.txt` file and load it back when needed.
- **Threat Analysis:** Compare the resources of a base against hypothetical attack scenarios involving a given number of Russian divisions.

## Usage

1. Run the `main.cpp` to start the application.
2. Follow the on-screen prompts to perform various operations like adding a new base, displaying all bases, editing a base's details, etc.
3. Use the threat analysis feature to assess the capability of a base against potential threats.

## Prerequisites

- C++ compiler (e.g., g++)
- Required libraries: Standard C++ libraries

## Installation and Compilation

1. Clone or download this repository.
2. Navigate to the directory containing the source files.
3. Compile the project using a C++ compiler:

```bash
g++ main.cpp Natobase.cpp -o nato_bases_app
```

4. Run the compiled application:

```bash
./nato_bases_app
```

## Contributing

If you wish to contribute to the development or enhancement of this project, please fork the repository and submit a pull request.

## Acknowledgments

- The project was developed in the context of ongoing global events, especially the conflict in Ukraine, emphasizing the importance of maintaining and analyzing military resources.

## License

This project is open-sourced and available for modification and distribution under the MIT License.

Thank you for exploring the NATO Bases Database Management project!
