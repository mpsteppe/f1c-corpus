---
name: f1c-locate
description: Find where code or data lives in the F1C binary — function, global, string, struct field, subsystem, or mod-target — using tools/investigate.py and the knowledge graph. Use when a task says "where is X handled", "what does this function do", "who reads/writes this global", "map the tire subsystem", or "find a patch-point candidate". Do NOT use to verify whether a located doc label is TRUE — use f1c-verify-claim; do NOT use for live memory reads — use f1c-live-probe; do NOT use for sibling binaries — use f1c-port-sibling.
---

# Locate code and data with investigate.py (never grep fan-out)

## When to use / when not

Any "find/where/who-touches/what-is" question about the F1C binary. Everything this
skill returns from docs or the graph is a GUESS/LEAD-tier hint per `INDEX.md` §Trust
tiers — before building a mod or precise claim on a hit, route to `f1c-verify-claim`.

The governing rule, verbatim from `CLAUDE.md` §Iron rules:

> 2. **LOCATE with `tools/investigate.py`** (`find` / `system` / `mod` / `global` /
>    `uses` / address dossier) — never fan out raw greps or hand-read `.c` files to
>    find code. Batch all addresses in ONE call. Offset table auto-decodes idx×4 and
>    docs/13 names — build it once, reason once, never re-derive by hand.

## Prerequisites

| Prerequisite | Check command | Expected |
|---|---|---|
| investigate.py runnable | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py` | Module docstring / usage help (read-only, safe) |
| Graph present (optional — degrades gracefully) | `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/knowledge_graph/query.py stats` | Graph-wide statistics table |

## Procedure

### Step 1: pick the subcommand from the question shape

| Question | Subcommand |
|---|---|
| Concept → where? ("tire wear", "commentary") | `find <term...>` |
| Who touches a global? | `global <DAT_addr\|addr>` |
| Where does a literal token appear (hex, offset, identifier)? | `uses <token...>` |
| Map a whole subsystem | `system <term...>` |
| What is the patch surface for a behavior? | `mod <term...>` |
| Data-file field → parser → format | `param <field-name...>` |
| I have address(es) → full picture | dossier: `<addr> [addr2 ...]` |

### Step 2: run the concept search

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py find "tire wear"
```
Expected output: ranked FUNCTIONS / GLOBALS / DOC sections / DOC content lists.
If instead you see `nothing found` (exit 0, not an error) → try synonyms, then
`uses <literal>` for exact tokens, then `system <term>` for the subsystem map.

### Step 3: globals and raw tokens (raw-.c ground truth, not just the graph)

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py global DAT_<addr>
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py uses <token>
```
(Substitute a real global, e.g. the SessionType address listed in `CLAUDE.md` §Key pointers.)
Expected output: merged graph + raw-`.c` hit list; `uses` tags each hit `[R]`/`[W]` with the line.
If instead the list looks implausibly short → the graph under-reports; `global`/`uses`
scan the actual `.c` files, so trust their output over `query.py global` for usage counts
(REFERENCE.md §Bug Investigation — START HERE).

### Step 4: dossier — batch EVERY address in ONE call

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/investigate.py <addr1> <addr2> <addr3> --snippet
```
Accepted forms: `0x...` hex, bare hex, `FUN_...`. Flags: `--snippet` (decisive lines only,
5–10× cheaper — default choice), `--no-source` (tables only, fast triage), `--callees`
(also dump each callee). Expected output: per-address `FUN_XXXXXXXX — name` header, then
identity / graph edges / auto-decoded struct-offset table / globals / calls / source.
If instead an offset label carries `?` → ambiguous docs/13 struct section: pick by
context, never trust a `?`-marked label blindly. Build the offset table ONCE from the
dossier and reason from it — never re-derive idx×4 by hand.

### Step 5: graph queries (structure questions the dossier doesn't answer)

```bash
cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/knowledge_graph/query.py traceback <addr> 3
```
Wired commands (the ONLY ones): `func calls callers trace traceback path global system
search stats context`. The docstring also lists `struct`, `module`, `top` — these are
NOT wired; calling them prints `Unknown command: <cmd>`. Do not use them.
Expected output: caller tree (depth 3, capped 15/node).
If instead `Unknown function: <addr>` → address not in the graph; fall back to the
Step-4 dossier, which also scans the decompiled dirs directly.

### Step 6: escalate to raw source (FACT tier) only with an address in hand

Read the specific file for a located address under `analysis_pipeline/analyzed/`,
`decompiled_all/`, or `tools/decompiled_ida/` (filename convention
`0x00XXXXXX__FUN_00XXXXXX.c`, REFERENCE.md §Source Data). Reading a known file is fine;
hunting through many files by grep is what Step 1–3 exist to prevent.

## STOP — do not proceed if

- You are about to fan out `grep`/`rg` over the repo to FIND code → forbidden (iron
  rule 2, quoted above). Use `find`/`uses`/`system` instead.
- You are about to run `tools/search_docs.py` → its docs path is broken (it resolves
  `tools/docs/`, which does not exist) — use `investigate.py find` / `uses` instead.
- You are about to hand-read `.c` files serially to locate something → dossier with
  `--snippet`, all addresses batched in one call.
- You are about to build a mod or precise claim on a located doc label → it is
  GUESS/LEAD tier (`INDEX.md` §Trust tiers); route to `f1c-verify-claim` first.

## Failure modes and recovery

| Symptom | Likely cause | Action |
|---|---|---|
| `nothing found` from `find` | term not in strings/names/docs | synonyms → `uses <literal>` → `system <term>` |
| `Unknown command: <cmd>` from query.py | `struct`/`module`/`top` not wired | use the 11 wired commands listed in Step 5 |
| `Unknown function: <addr>` from query.py | address absent from graph | run the investigate.py dossier instead |
| `usage: ...` from a subcommand | missing term/args | re-run with the term appended |
| Offset label ends in `?` in dossier | ambiguous docs/13 section | choose by context; verify via `f1c-verify-claim` |

## Deep reference

Read `reference.md` in this skill's directory for mode-by-mode output-shape transcripts
(what each subcommand's output looks like and how to read it).

---
Canonical sources: CLAUDE.md §Iron rules; CLAUDE.md §Everyday commands; REFERENCE.md §Bug Investigation — START HERE; REFERENCE.md §Knowledge Graph; REFERENCE.md §Key Commands; REFERENCE.md §Source Data; INDEX.md §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE; docs/_README.md §Trust map
Last validated: 2026-07-18 against 6bcccfe
