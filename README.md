# lsnotes 

<div style="text-align:center">
<img width="762" height="600" alt="Screen Shot 2025-08-09 at 10 43 26 PM" src="https://github.com/user-attachments/assets/42f09502-402d-4397-af98-7f2cefff99f5" />
</div>

> Adding descriptions to your directories!

<a href="https://www.producthunt.com/products/lsnotes?embed=true&utm_source=badge-featured&utm_medium=badge&utm_source=badge-lsnotes" target="_blank"><img src="https://api.producthunt.com/widgets/embed-image/v1/featured.svg?post_id=1003495&theme=light&t=1754755647427" alt="lsnotes - lsnotes&#0058;&#0032;Annotate&#0032;Your&#0032;Directories&#0044;&#0032;the&#0032;Easy&#0032;Way | Product Hunt" style="width: 250px; height: 54px;" width="250" height="54" /></a>

---

## What’s lsnotes?

**lsnotes** lets you attach and display notes for directories. Just drop a `.lsnotes` file in any folder and voilà—your directory has a description. Now remade with:

- **Python** — easier to use and extend  
- **Typer** — for snappy, intuitive CLI  
- **Markdown support** — so your notes can look sleek and formatted

## A story
It was originally just an April Fools joke that I told [@MrWillCom](https://github.com/MrWillCom), but it turned out to be a brilliant idea. So I made this project.

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
