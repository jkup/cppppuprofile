# CPU Profile Generator

This project is a simple C++17 script that takes a list of IDs mapped to function names and another list of the same IDs mapped to durations. It then generates a JSON file in the cpuprofile format and writes it to a file named "profile.cpuprofile".

## What is a cpuprofile?

A cpuprofile is a format used by various Google tools, such as Chrome Developer Tools, to represent CPU profiling data. CPU profiling is a method for analyzing the performance of a program or script by collecting information about how much time the CPU spends executing various parts of the code. The cpuprofile format is a JSON-based format that contains information such as the call tree of the profiled script, the total time spent on each function, and the number of samples collected during the profiling process.

A typical cpuprofile JSON file has the following structure

```json
{
  "nodes": [
    {
      "id": <node-id>,
      "callFrame": {
        "functionName": <function-name>,
        "scriptId": <script-id>,
        "url": <script-url>,
        "lineNumber": <line-number>,
        "columnNumber": <column-number>
      },
      "hitCount": <hit-count>,
      "children": [<child-node-id>, ...]
    },
    ...
  ],
  "startTime": <start-time>,
  "endTime": <end-time>,
  "samples": [<node-id>, ...],
  "timeDeltas": [<time-delta>, ...]
}
```

## Prerequisites

This project requires a C++17 compiler and the nlohmann/json library for JSON handling. Make sure you have both installed on your system before running the script.

## Getting Started

To get started, follow these steps:

1. Clone the repository to your local machine:

```sh
git clone https://github.com/yourusername/cpuprofile-generator.git
cd cpuprofile-generator
```

2. Replace the sample data in the id_funcname_pairs and id_duration_pairs vectors in the main.cpp file with your actual data.

3. Compile the project:

```sh
g++ -std=c++17 -o cpuprofile-generator main.cpp -I/path/to/nlohmann-json/include
```

Replace /path/to/nlohmann-json/include with the actual path to the nlohmann/json library's include directory on your system.

4. Run the script:

```
./cpuprofile-generator
```

5. The generated cpuprofile JSON file will be saved as "profile.cpuprofile" in the same directory as the script.

Feel free to modify the README.md file to better suit your specific project needs or provide additional information about your project.
