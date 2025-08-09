#!/usr/bin/env python3
import os
import subprocess
from pathlib import Path
import typer
from rich.console import Console
from rich.markdown import Markdown

app = typer.Typer(add_completion=False)
console = Console()

# Global config instance
class LSConfig:
    def __init__(self, addTitle=0, addBottom=1):
        self.addTitle = addTitle
        self.addBottom = addBottom

instance = LSConfig()

def read_config():
    home = Path.home()
    config_path = home / ".lsnotesrc"
    if config_path.exists():
        try:
            with config_path.open("r") as f:
                t1, t2 = map(int, f.read().split())
                instance.addTitle, instance.addBottom = t1, t2
        except ValueError:
            instance.addTitle, instance.addBottom = 0, 1
    else:
        instance.addTitle, instance.addBottom = 0, 1

read_config()

def save_config():
    home = Path.home()
    config_path = home / ".lsnotesrc"
    tmp_path = home / ".lsnotesrc.tmp"
    with tmp_path.open("w") as f:
        f.write(f"{instance.addTitle} {instance.addBottom}")
    if config_path.exists():
        config_path.unlink()
    tmp_path.rename(config_path)

@app.command()
def view():
    """
    View .lsnotes file (default action if no command).
    """
    note_path = Path(".lsnotes")
    if note_path.exists():
        if instance.addTitle:
            console.print(Markdown("# LSNOTES"))
        console.print(Markdown(note_path.read_text()))
        if instance.addBottom:
            console.print(Markdown("---"))

@app.command()
def edit():
    """
    Edit the .lsnotes file using $EDITOR or defaults.
    """
    editor = os.getenv("EDITOR")
    if not editor:
        typer.echo("Default Editor Not Set.")
        if os.name == "nt":  # Windows
            typer.echo("Using Notepad.exe")
            subprocess.call(["notepad.exe", ".lsnotes"])
        else:
            typer.echo("Using vi")
            subprocess.call(["vi", ".lsnotes"])
        typer.echo("You can set $EDITOR to PATH")
    else:
        typer.echo("Editing the .lsnotes file with the default editor")
        subprocess.call(f"{editor} .lsnotes", shell=True)

@app.command()
def config():
    """
    Configure lsnotes display options.
    """
    typer.echo("CONFIGURATION (0: no, 1: yes)")
    instance.addTitle = typer.prompt(f"Add a title (Currently {instance.addTitle})", type=int)
    instance.addBottom = typer.prompt(f"Add a bottom divider (Currently {instance.addBottom})", type=int)
    save_config()
    typer.echo("Changes saved.")

@app.command()
def main():
    view()

if __name__ == "__main__":
    app()

