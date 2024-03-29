# lsnotes
(Part of the `better coreutils initiative`)

Add a description to your directories! Simply add a `.lsnotes` file and that's it! This is the original repo of the `lsnotes` project.

It's an especially simple project, but the idea makes me feel fresh! It should be made a shell project but I don't feel like that. Anyway, it has endless possibilities!

## A story
It was originnaly just an April Fools joke that I told [@MrWillCom](https://github.com/MrWillCom), but it turned out to be a brilliant idea. So I made this project.

## Installation

```sh
git submodule init
git submodule update
mkdir build && cd build
cmake ..
make
make install
```

## Usage

```sh
lsnotes # for viewing the description
lsnotes --view or lsnotes -v # does the same as above

lsnotes --help # for assistance

lsnotes --edit or lsnotes -e # edits the .lsnotes file with your default editor

lsnotes --config or lsnotes -c # for configuration
```

### Examples

```sh
alias ls = "lsnotes && ls"
alias pwd = "lsnotes && pwd"
# etc.
```

## Other Ports

We welcome you to implement the `.lsnotes` standard using various languages or on diverse platforms.

- NodeJS: [MrWillCom/lnn](https://github.com/MrWillCom/lnn)

---
Made with love by [@aeilot](https://github.com/aeilot) at [aeilot.top](https://aeilot.top)
