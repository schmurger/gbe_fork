## :large_orange_diamond: **This is a fork**
Fork of https://gitlab.com/Mr_Goldberg/goldberg_emulator  

---

:red_circle:  

**This fork is not a takeover, not a resurrection of the original project, and not a replacement.**  
**This is just a fork, don't take it seriously.**  
**You are highly encouraged to fork/clone it and do whatever you want with it.**  

:red_circle:

---

## **Credits**
Thanks to everyone contributing to this project in any way possible, we try to keep the [CHANGELOG.md](./CHANGELOG.md) updated with all the changes and their authors.  

This project depends on many third-party libraries and tools, credits to them for their amazing work, you can find their listing here in [CREDITS.md](./CREDITS.md).  

---

## Original README
You can find the original README here: [README.md](./z_original_repo_files/README.md)

---

# How to use the emu
* **Always generate the interfaces file using the `find_interfaces` tool.**  
* **Generate the proper app configuration using the `generate_emu_config` tool.**  
* **If things don't work, try the `ColdClientLoader` setup.**  

You can find helper guides, scripts, and tools here in this wiki: https://github.com/otavepto/gbe_fork/wiki/Emu-helpers  
You can also find instructions here in [README.release.md](./post_build/README.release.md)  

---
---

<br/>

# **Compiling**
## One time setup
### **Cloning the repo**

 Disable automatic CRLF handling:  
 *Locally*
 ```shell
 git config --local core.autocrlf false
 ```
 *Or globally/system wide*
 ```shell
 git config --system core.autocrlf false
 git config --global core.autocrlf false
 ```

 Clone the repo and its submodules **recursively**
 ```shell
 git clone --recurse-submodules -j8 https://github.com/otavepto/gbe_fork.git
 ```
 The switch `-j8` is optional, it allows Git to fetch up to 8 submodules

 It is adviseable to always checkout submodules every now and then, to make sure they're up to date
 ```shell
 git submodule update --recursive --remote
 ```

### For Windows:
* You need Windows 10 or 8.1
* Install `Visual Studio 2022 Community`: https://visualstudio.microsoft.com/vs/community/
   * Select the Workload `Desktop development with C++`
   * In the `Individual componenets` scroll to the buttom and select the **latest** version of `Windows XX SDK (XX.X...)`  
     For example `Windows 11 SDK (10.0.22621.0)`
* *(Optional)* Install a GUI for Git like [GitHub Desktop](https://desktop.github.com/), or [Sourcetree](https://www.sourcetreeapp.com/)
* Python 3.10 or above: https://www.python.org/downloads/windows/  
   After installation, make sure it works
   ```batch
   python --version
   ```

### For Linux:

* Ubuntu 22.04 LTS: https://ubuntu.com/download/desktop
* Python 3.10 or above
   ```shell
   sudo add-apt-repository ppa:deadsnakes/ppa -y
   sudo apt update -y
   sudo apt install python3.10 -y
   
   # make sure it works
   python3.10 --version
   ```

### **Building dependencies**

These are third party libraries needed to build the emu later, they are linked with the emu during its build process.  
You don't need to build these dependencies every time, they rarely get updated.  
The only times you'll need to rebuild them is either when their separete build folder was accedentally deleted, or when the dependencies were updated.  

<br/>

#### On Windows:
Open CMD in the repo folder, then run the batch script
```batch
build_win_deps.bat
```
This will:
* Extract all third party dependencies from the folder `third-party` into the folder `build\deps\win` 
* Build all dependencies  

Additional arguments you can pass to this script:
* `-j <n>`: build with `<n>` parallel jobs, by default 70% of the available threads
* `-verbose`: output compiler/linker commands used by `CMAKE`

#### On Linux:
Open bash terminal in the repo folder, then run the bash script
```shell
sudo ./build_linux_deps.sh
```
This will:
* Install the required Linux packages via `apt install` (compiler + build tools/libraries)
* Extract all third party dependencies from the folder `third-party` into the folder `build/deps/linux` 
* Build all dependencies  

Additional arguments you can pass to this script:
* `-j <n>`: build with `<n>` parallel jobs, by default 70% of the available threads
* `-verbose`: output compiler/linker commands used by `CMAKE`
* `-packages_skip`: skip package installation via `apt install` and continue build
* `-packages_only`: install the required Linux packages via `apt install` and exit (don't rebuild)

---

## **Building the emu**
### On Windows:
Open CMD in the repo folder, then run the batch script
```batch
build_win.bat release
```
This will build a release build of the emu in the folder `build\win\release`

<br/>

Arguments you can pass to this script:
* `release`: build the emu in release mode
* `debug`: build the emu in debug mode, which writes events to a log file, and includes `.pdb` files,  
  check the debug build readme: [README.debug.md](./post_build/README.debug.md)
* `clean`: clean the build folder before building again, otherwise the script will retain everything from previous builds

>>>>>>>>>  ___

* `-j <n>`: build with `<n>` parallel jobs, by default 70% of the available threads
* `+build_str <str>`: add an identification string to the build (default date-time)
* `-verbose`: output compiler/linker commands

>>>>>>>>>  ___

* `+lib-32`: build normal `steam_api.dll`
* `+lib-64`: build normal `steam_api64.dll`

>>>>>>>>>  ___

* `+ex-lib-32`: build experimental `steam_api.dll`
* `+ex-lib-64`: build experimental `steam_api64.dll`

>>>>>>>>>  ___

* `+ex-client-32`: build experimental `steamclient.dll`
* `+ex-client-64`: build experimental `steamclient64.dll`

>>>>>>>>>  ___

* `+exclient-32`: build steamclient `steamclient.dll`
* `+exclient-64`: build steamclient `steamclient64.dll`
* `+exclient-ldr-32`: build steamclient loader (32) `steamclient_loader_32.exe`
* `+exclient-ldr-64`: build steamclient loader (64) `steamclient_loader_64.exe`

>>>>>>>>>  ___

* `+exclient-extra-32`: build the 32 bit version of the additional dll `steamclient_extra.dll` which is injected by the client loader
* `+exclient-extra-64`: build the 64 bit version of the additional dll `steamclient_extra64.dll` which is injected by the client loader

>>>>>>>>>  ___

* `+tool-itf` build the tool `find_interfaces`
* `+tool-lobby`: build the tool `lobby_connect`

>>>>>>>>>  ___

* `+lib-netsockets-32` *(experimental)*: build a standalone networking sockets library (32-bit)
* `+lib-netsockets-64` *(experimental)*: build a standalone networking sockets library (64-bit)

>>>>>>>>>  ___

* `+lib-gameoverlay-32` *(experimental)*: build a standalone stub/mock GameOverlayRenderer.dll library (32-bit)
* `+lib-gameoverlay-64` *(experimental)*: build a standalone stub/mock GameOverlayRenderer64.dll library (64-bit)

<br/>

### On Linux:
Open bash terminal in the repo folder, then run the bash script (without sudo)
```shell
./build_linux.sh release
```
This will build a release build of the emu in the folder `build/linux/release`

<br/>

Arguments you can pass to this script:
* `release`: build the emu in release mode
* `debug`: build the emu in debug mode, which writes events to a log file, and includes `.pdb` files,  
  check the debug build readme: [README.debug.md](./post_build/README.debug.md)
* `clean`: clean the build folder before building again, otherwise the script will retain everything from previous builds

>>>>>>>>>  ___

* `-j <n>`: build with `<n>` parallel jobs, by default 70% of the available threads
* `+build_str <str>`: add an identification string to the build (default date-time)
* `-verbose`: output compiler/linker commands

>>>>>>>>>  ___

* `+lib-32`: build normal 32-bit `libsteam_api.so`
* `+lib-64`: build normal 64-bit `libsteam_api.so`

>>>>>>>>>  ___

* `+client-32`: build steam client 32-bit `steamclient.so`
* `+client-64`: build steam client 64-bit `steamclient.so`

>>>>>>>>>  ___

* `+exp-lib-32`: build experimental 32-bit `libsteam_api.so`
* `+exp-lib-64`: build experimental 64-bit `libsteam_api.so`
* `+exp-client-32`: build experimental steam client 32-bit `steamclient.so`
* `+exp-client-64`: build experimental steam client 64-bit `steamclient.so`

>>>>>>>>>  ___

* `+tool-clientldr`: copy the tool `steamclient_loader`

>>>>>>>>>  ___

* `+tool-itf-32`: build the tool 32-bit `find_interfaces`
* `+tool-itf-64`: build the tool 64-bit `find_interfaces`
* `+tool-lobby-32`: build the tool 32-bit `lobby_connect`
* `+tool-lobby-64`: build the tool 64-bit `lobby_connect`

>>>>>>>>>  ___

* `+lib-netsockets-32` *(experimental)*: build a standalone networking sockets library (32-bit)
* `+lib-netsockets-64` *(experimental)*: build a standalone networking sockets library (64-bit)

---

## **Building the tool `generate_emu_config`**
Navigate to the folder `tools/generate_emu_config/` then  

### On Windows:
Open CMD then:
1. Create python virtual environemnt and install the required packages/dependencies
   ```batch
   recreate_venv_win.bat
   ```
2. Build the tool using `pyinstaller`  
   ```batch
   rebuild_win.bat
   ```

This will build the tool inside `bin\win`

### On Linux:
Open bash terminal then:
1. Create python virtual environemnt and install the required packages/dependencies
   ```shell
   sudo ./recreate_venv_linux.sh
   ```  
   You might need to edit this script to use a different python version.  
   Find this line and change it:
   ```shell
   python_package="python3.10"
   ``` 
2. Build the tool using `pyinstaller`  
   ```shell
   ./rebuild_linux.sh
   ```

This will build the tool inside `bin/linux`

---

## **Using Github CI as a builder**

This is really slow and mainly intended for the CI Workflow scripts, but you can use it as another outlet if you can't build locally.  
**You have to fork the repo first**.

### Initial setup
In your fork, open the `Settings` tab from the top, then:
* From the left side panel select `Actions` -> `General`
* In the section `Actions permissions` select `Allow all actions and reusable workflows`
* Scroll down, and in the section `Workflow permissions` select `Read and write permissions`
* *(Optional)* In the section `Artifact and log retention`, you can specify the amount of days to keep the build artifacts/archives.  
  It is recommended to set a reasonable number like 3-4 days, otherwise you may consume your packages storage if you use Github as a builder frequently, more details here: https://docs.github.com/en/get-started/learning-about-github/githubs-plans  

### Manual trigger
1. Go to the `Actions` tab in your fork
2. Select the emu dependencies Workflow (ex: `Emu third-party dependencies (Windows) `) and run it on the **main** branch (ex: `dev`).  
   Dependencies not created on the main branch won't be recognized by other branches or subsequent runs
3. Select one of the Workflow scripts from the left side panel, for example `Build all emu variants (Windows)`
3. On the top-right, select `Run workflow` -> select the desired branch (for example `dev`) -> press the button `Run workflow`
4. When it's done, many packages (called build artifacts) will be created for that workflow.  
   Make sure to select the workflow again to view its history, then select the last run at the very top to view its artifacts

<br/>

Important note:
---

When you build the dependencies workflows, they will be cached to decrease the build times of the next triggers and avoid unnecessary/wasteful build process.  
This will cause a problem if at any time the third-party dependencies were updated, in that case you need to manually delete the cache, in your fork:
1. Go to the `Actions` tab at the top
2. Select `Caches` from the left side panel
3. Delete the corresponding cache

<br/>

---

## ***(Optional)* Packaging**
This step is intended for Github CI/Workflow, but you can create a package locally.

### On Windows:
Open CMD in the repos's directory, then run this script
```batch
package_win.bat <build_folder>
```
`build_folder` is any folder inside `build\win`, for example: `release`  
The above example will create a `.7z` archive inside `build\package\win\release`

### On Linux:
Open bash terminal in the repos's directory, then run this script
```shell
package_linux.sh <build_folder>
```
`build_folder` is any folder inside `build/linux`, for example: `release`  
The above example will create a compressed `.tar` archive inside `build/package/linux/release`
