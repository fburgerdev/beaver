# Description
What is the description of this project?

## Features
Insert feature bullet points here.

## Support
- Linux (native)
- Windows (supported)

# Usage
## Installation
At your desired location, type this command into the console.
``` console
git clone git@github.com:fburgerdev/logging.git
```

## Project Settings
- Add include directory: "PATH_TO_REPO/include" 
- Add library directory: "PATH_TO_REPO/lib/CONFIG/" 
- Link library:
    - "liblogging.a" for linux
    - "logging.lib" for windows

## Build Yourself (Optional)
### Linux
In the _build_ folder, execute the following command in the console
``` console
make config=CONFIG
```
If you have not installed _make_, execute this command in the console first
``` console
sudo apt-get install make -y
```

### Windows
Open the file "build/logging.sln" with Visual Studio.
After you have selected your desired configuration, click on _Build > Build_ Solution.

__Note:__ Make sure you have the _Desktop developement with C++_ workload installed.