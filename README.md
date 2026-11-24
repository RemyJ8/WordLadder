# Word Ladder

A word transformation puzzle game built with C++.

## About

Word Ladder is a word puzzle game where the objective is to transform a starting word into a target word by changing exactly one letter at each step.

Every intermediate word must be a valid word, and all words must have the same length.

**Example:**

```text
COLD
CORD
CARD
WARD
WARM
```

The challenge is to reach the target word using as few moves as possible.

## Current Status

The project is currently in its early development stage.

The first version is a command-line application written in C++. It implements the basic word transformation gameplay.

### Current Features

- Command-line interface.
- Word transformation mechanics.
- Ability to move from a starting word to a target word.
- C++ implementation.

### Planned Features

- [ ] Integrate an English dictionary.
- [ ] Validate every intermediate word.
- [ ] Implement word length validation.
- [ ] Implement move validation (exactly one letter changed).
- [ ] Develop a level generation system.
- [ ] Implement shortest-path algorithms (BFS).
- [ ] Add a scoring system.
- [ ] Develop a mobile application interface.
- [ ] Add multiple difficulty levels.
- [ ] Support additional languages.

## How It Works

The basic rules are simple:

1. You are given a starting word and a target word.
2. You can change exactly one letter per move.
3. Every resulting word must be valid.
4. The length of the word must remain unchanged.
5. The objective is to reach the target word.

## Technology

- **Language:** C++
- **Interface:** Command Line (current version)
- **Planned platform:** Android / iOS

## Getting Started

### Prerequisites

- A C++ compiler (GCC, Clang, or MSVC).
- A development environment supporting C++.

### Installation

Clone the repository:

```bash
git clone <repository-url>
```

Navigate to the project directory:

```bash
cd <repository-name>
```

Compile the project using your preferred C++ compiler.

### Running

Run the compiled executable from your terminal.

*Note: Build instructions will be updated as the project structure evolves.*

## Future Vision

The long-term goal is to turn this command-line prototype into a mobile puzzle game.

Potential features include:

- Progressive levels.
- Daily word challenges.
- Hints and assistance.
- Move limits and scoring.
- Different dictionaries and languages.
- Offline gameplay.

## Contributing

This project is currently under active development.

Suggestions, ideas, and contributions are welcome!

## License

License information will be added later.
