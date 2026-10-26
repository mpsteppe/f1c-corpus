# F1 Challenge 99-02 research corpus

Analysis data for F1 Challenge 99-02: decompiled functions, typed and
annotated function sets, skeletons, shadow source, call graph, strings and
indexes. Used by the SDK in the main mods repository.

This repository contains machine-generated analysis of a commercial game for
interoperability research. The game itself is not included. It is kept
separate from the mods repository on purpose.

## Use with the SDK

Clone this repository next to the mods repository, then from the mods repo:

    python sdk/tools/setup_corpus.py PATH_TO_THIS_CLONE

`python tools/f1c_mod.py inspect ADDRESS` (run from `sdk/`) then shows the
code for any function.

## Bugs and questions

Send bug reports and questions on Discord to **mpsteppe**. GitHub issues are
not monitored.
