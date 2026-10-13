FlashForge
A Linux USB creation project built with C++ and Qt 6.
Current Status
Early development: a read-only graphical interface for selecting
disk image files and viewing their metadata.
Disk formatting and writing are not implemented.
Requirements
- C++17 compiler
- CMake 3.22 or newer
- Qt 6 Widgets development libraries
Build
cmake -S . -B build
cmake --build build --parallel
./build/flashforge
Roadmap
- Read-only USB device discovery
- System-disk protection
- Safe privileged disk operations
- Raw-image writing and verification
- Linux and Windows installation-media workflows
