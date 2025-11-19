# SmartTerm

A C++ terminal UI framework for creating interactive terminal-based applications with color support, keyboard input handling, and reusable UI components.

## Overview

SmartTerm provides a modular architecture for building sophisticated terminal user interfaces (TUIs). It abstracts low-level terminal operations into high-level, composable components.

## Project Structure

```
smartterm/
├── lib/
│   ├── term/          # Low-level terminal control library
│   └── tui/           # High-level UI components
├── src/               # Main application entry point
├── task1/             # Example: Basic terminal color output
└── task2/             # Example: Interactive menu navigation
```

## Libraries

### `lib/term` - Terminal Control Library

Low-level terminal manipulation providing:

- **Color Management** (`term.h`)
  - RGB color support
  - Predefined colors: RED, GREEN, BLUE, CYAN, YELLOW, MAGENTA, BLACK, WHITE
  - Foreground and background color control

- **Cursor Control** (`term.h`)
  - Position cursor at specific coordinates
  - Show/hide cursor
  - Clear screen operations

- **Input Handling** (`input.h`)
  - Raw and cooked input modes
  - Keyboard event detection:
    - Arrow keys (UP, DOWN, LEFT, RIGHT)
    - Function keys (F1-F12)
    - Special keys (ESC, ENTER, BACKSPACE, DELETE, etc.)
  - Cross-platform support (Windows and POSIX systems)

### `lib/tui` - Terminal UI Components Library

High-level UI component library built on top of `lib/term`:

- **Widget** (`widget.h`)
  - Base class for all UI components
  - Position and size tracking
  - Virtual keyboard event handler: `onKeyPress(KeyCode key)`
  - Focus management

- **Page** (`page.h`)
  - Container for organizing widgets
  - Title support
  - Event propagation to child widgets
  - Page switching capability

- **Menu** (`menu.h`)
  - Selectable menu widget
  - Navigation:
    - Arrow keys (UP/DOWN) for vertical navigation
    - LEFT/RIGHT for sub-menus or columns
    - HOME/END for first/last item
  - Item selection with ENTER key
  - Customizable colors:
    - Normal item color
    - Hover/highlighted color
    - Selected item color
  - Variable-width column support

## Examples

### Task 1: Basic Terminal Output

Located in `task1/main.cpp`

Demonstrates:
- Setting foreground and background colors
- Positioning cursor at specific coordinates
- Outputting colored text
- Managing screen timing

### Task 2: Interactive Menu Navigation

Located in `task2/main.cpp`

Demonstrates:
- Creating a multi-page navigation system
- Building interactive menus with keyboard controls
- Page switching based on menu selection
- Raw input mode for responsive keyboard handling
- Color-coded UI elements

## Building

### Prerequisites
- CMake 3.10 or higher
- C++17 compatible compiler
- Platform: Windows, Linux, or macOS

### Build Instructions

```bash
# Create build directory and configure
cmake -B build

# Build the project
cmake --build build

# Run examples
./build/task1/task1
./build/task2/task2
```

## Key Features

- **Cross-Platform**: Works on Windows (native console API), Linux, and macOS (POSIX terminals)
- **RGB Colors**: True color support using ANSI escape sequences
- **Event-Driven Architecture**: Keyboard input handling through virtual methods
- **Composable Components**: Build complex UIs from simple widget components

## Architecture

```
Application
    ↓
┌───────────────────────────────────┐
│    lib/tui (UI Components)        │
│  ┌─────────────────────────────┐  │
│  │  Page with Menu Widgets     │  │
│  │  - Event Propagation        │  │
│  │  - Layout Management        │  │
│  └─────────────────────────────┘  │
└───────────────────────────────────┘
    ↓
┌───────────────────────────────────┐
│    lib/term (Terminal Control)    │
│  ┌─────────────────────────────┐  │
│  │  Input Handling             │  │
│  │  Color/Cursor Management    │  │
│  │  Screen Operations          │  │
│  └─────────────────────────────┘  │
└───────────────────────────────────┘
    ↓
    OS Terminal (Windows Console / POSIX Terminal)
```

