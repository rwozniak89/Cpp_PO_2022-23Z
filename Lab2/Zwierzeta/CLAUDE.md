# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Context

Small C++ exercise from an object-oriented programming course (repo `Cpp_PO_2022-23Z`, one folder per lab: `Lab1`…`Lab6`, each holding separate Code::Blocks projects). This project, `Lab2/Zwierzeta` ("Animals"), practices inheritance and polymorphism. Identifiers, comments and console output are in Polish — keep that convention (e.g. `przedstawSie()` = "introduce yourself").

## Build & run

The project is a Code::Blocks project (`Zwierzeta.cbp`, GCC, flags `-Wall -fexceptions -std=c++11`, include dir `include/`, Debug adds `-g`, Release `-O2`, output in `bin/<Target>/`). There are no tests or linters. When adding a new class, register its `.h`/`.cpp` as `<Unit>` entries in the `.cbp`, or the IDE build won't link.

Command-line build (MinGW g++ is on PATH), equivalent to the Debug target:

```sh
g++ -Wall -fexceptions -std=c++11 -g -Iinclude main.cpp src/*.cpp -o bin/Debug/Zwierzeta.exe
./bin/Debug/Zwierzeta.exe
```

## Structure

- `include/` — class headers (Code::Blocks "new class" layout, `#ifndef NAME_H` guards, `public`/`protected`/`private` sections).
- `src/` — matching implementations.
- `main.cpp` — demo driver that instantiates classes and calls their methods.

Class hierarchy: `Organizm` (`dna`, virtual `przedstawSie()`) → `Zwierze` (`nazwa`, adds virtual `dajGlos()`) → `Owca` (`welna` in kg) → `WilkX` (a wolf in sheep's clothing: tracks `zjedzoneOwce`, has `zjedzOwce(Owca&)`). Each level passes constructor args up via the initializer list and overrides `przedstawSie()` (extending the parent's version) and `dajGlos()`. `main.cpp` demonstrates polymorphism through an array of `Zwierze*`.

Console output avoids Polish diacritics (`zwierzeciem`, not `zwierzęciem`), because they display garbled in the Windows console.

`bin/`, `obj/`, `*.depend` and `*.layout` are Code::Blocks build/IDE artifacts, not source.
