[![license](https://img.shields.io/github/license/micro-os-plus/devices-cortexa-xpack)](https://github.com/micro-os-plus/devices-cortexa-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/devices-cortexa-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/devices-cortexa-xpack/actions?query=workflow%3A%22CI+on+Push%22)

# A source library xPack with µOS++ Cortex-A devices definitions

Due to the CMSIS design, some Cortex-A architecture definitions are
available only via the vendor specific device headers, so they
cannot be located in the architecture package.

The project is hosted on GitHub as
[micro-os-plus/devices-cortexa-xpack](https://github.com/micro-os-plus/devices-cortexa-xpack).

## Maintainer info

This page is addressed to developers who plan to include this source
library into their own projects.

For maintainer info, please see the
[README-MAINTAINER](README-MAINTAINER.md) file.

## Install

As a source library xPacks, the easiest way to add it to a project is via
**xpm**, but it can also be used as any Git project, for example as a submodule.

### Prerequisites

A recent [xpm](https://xpack.github.io/xpm/),
which is a portable [Node.js](https://nodejs.org/) command line application.

For details please follow the instructions in the
[xPack install](https://xpack.github.io/install/) page.

### xpm

Note: the package will be available from npmjs.com at a later date.

For now, it can be installed from GitHub:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install github:micro-os-plus/devices-cortexa-xpack
```

When ready, this package will be available as
[`@micro-os-plus/devices-cortexa`](https://www.npmjs.com/package/@micro-os-plus/devices-cortexa)
from the `npmjs.com` registry:

```sh
cd my-project
xpm init # Unless a package.json is already present

xpm install @micro-os-plus/devices-cortexa@latest

ls -l xpacks/micro-os-plus-devices-cortexa
```

### Git submodule

If, for any reason, **xpm** is not available, the next recommended
solution is to link it as a Git submodule below an `xpacks` folder.

```sh
cd my-project
git init # Unless already a Git project
mkdir -p xpacks

git submodule add https://github.com/micro-os-plus/devices-cortexa-xpack.git \
  xpacks/micro-os-plus/devices-cortexa
```

## Branches

Apart from the unused `master` branch, there are two active branches:

- `xpack`, with the latest stable version (default)
- `xpack-develop`, with the current development version

All development is done in the `xpack-develop` branch, and contributions via
Pull Requests should be directed to this branch.

When new releases are published, the `xpack-develop` branch is merged
into `xpack`.

## Developer info

TBD

### Build & integration info

The project is written in C++, and the tests are expected to be
written in C++ too (although there are no
major reasons to prevent adding C wrappers).

On embedded platforms, the test applications should be built with
**Arm semihosting** support.

To integrate this package into user projects, consider the following details:

#### Source files

The source files to be added to user projects are:

- `src/startup/initialize-hardware-early.c`
- `src/startup/initialize-hardware.c`
- `src/startup/initialize-interrupts-stack.cpp`
- `src/startup/terminate.cpp`
- `src/exception-handlers.cpp`

#### Include folders

The following folders should be passed to the compiler during the build:

- `include`

The header files to be included in user projects are:

```c++
#include <micro-os-plus/architecture-cortexa/startup/hooks.h>
#include <micro-os-plus/architecture-cortexa/exception.h>
```

#### Preprocessor definitions

- none

#### Compiler options

- `-std=c++20` or higher for C++ sources
- `-std=c11` for C sources

#### C++ Namespaces

- none

#### C++ Classes

- none

### Examples

TBD

### Known problems

- none

### Tests

The project is fully tested via GitHub
[Actions](https://github.com/micro-os-plus/devices-cortexa-xpack/actions/)
on each push.
The tests run on GNU/Linux, macOS and Windows, are compiled with GCC,
clang and arm-none-eabi-gcc and run natively or via QEMU.

## Change log - incompatible changes

According to [semver](https://semver.org) rules:

> Major version X (X.y.z | X > 0) MUST be incremented if any
backwards incompatible changes are introduced to the public API.

The incompatible changes, in reverse chronological order,
are:

- v1.x: initial release

## License

The original content is released under the
[MIT License](https://opensource.org/licenses/MIT/),
with all rights reserved to
[Liviu Ionescu](https://github.com/ilg-ul/).
