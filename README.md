# lsnotes

> Adding descriptions to your directories!

---

## What’s lsnotes?

**lsnotes** lets you attach and display notes for directories. Just drop a `.lsnotes` file in any folder and voilà—your directory has a description. Now remade with:

- **Python** — easier to use and extend  
- **Typer** — for snappy, intuitive CLI  
- **Markdown support** — so your notes can look sleek and formatted

## A story
It was originnaly just an April Fools joke that I told [@MrWillCom](https://github.com/MrWillCom), but it turned out to be a brilliant idea. So I made this project.

## Installation

Clone and build by yourself!
```sh
poetry install
```

or get it from PyPI!

```sh
pip install lsnotes
```

## Usage

```sh
lsnotes view # does the same as above

lsnotes --help # for assistance

lsnotes edit # edits the .lsnotes file with your default editor

lsnotes config # for configuration
```

### Examples

```sh
alias ls = "lsnotes view && ls"
alias pwd = "lsnotes view && pwd"
# etc.
```

## Other Ports

We welcome you to implement the `.lsnotes` standard using various languages or on diverse platforms.

- NodeJS: [MrWillCom/lnn](https://github.com/MrWillCom/lnn)

---
Made with love by [@aeilot](https://github.com/aeilot) at [aeilot.top](https://aeilot.top)
