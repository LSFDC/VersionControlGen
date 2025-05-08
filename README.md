# VersionControlGen

VersionControlGen is a simple C++ command-line tool that generates a version header file with a random version number and the current date/time. This can be used to automate versioning in your build process.

## Features

- Generates a header file with:
  - A random version number
  - The current date and time
- Easy integration into build scripts
- Simple command-line interface

## Usage

```
VersionControlGen.exe <output_path>
```

- `<output_path>`: Path to the file where the version information will be written (e.g., `version.h`).

Example:

```
VersionControlGen.exe version.h
```

This will create (or overwrite) `version.h` with content like:

```
#define FILEVER               12345
#define STRFILEVER           "12345"
#define STRINTERNALNAME      "2025/05/08 14:23:01"
```

### Integrating with Visual Studio Build Events

To automatically generate the version file before each build, add the following command to your project's **Pre-Build Event**:

```
"../../../Build/Tools/VersionControlGen.exe" "$(ProjectDir)Version.h"
```

This ensures that `Version.h` is updated every time you build the project.

## Building

1. Open `VersionControlGen.sln` in Visual Studio 2022 or later.
2. Build the solution (choose Debug or Release, x86 or x64 as needed).
3. The executable will be in the output directory.

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.
