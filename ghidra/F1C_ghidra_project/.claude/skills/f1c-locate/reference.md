# f1c-locate reference — mode-by-mode output shapes

Companion to `f1c-locate` SKILL.md. All transcripts below show OUTPUT SHAPE with
placeholder addresses (`FUN_00XXXXXX`, `DAT_00XXXXXX`, `+0xNNN`). Real addresses in
your session come from the tool's live output; canonical global names live in
`docs/12-globals-reference.md` and struct offsets in `docs/13-struct-offsets.md` —
never copy addresses from this file into work products.

All commands run from `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project`.
Command syntax source of truth: `.claude/skills/_meta/toolfacts.md` §tools/investigate.py.

## `find <term...>` — concept → ranked locations

```
$ python tools/investigate.py find "tire wear"
=== FUNCTIONS ===
  FUN_00XXXXXX  TireWearUpdate        score NN   docs/04-tire-system.md
  FUN_00XXXXXX  <name>                score NN   docs/10-vehicle-physics.md
=== GLOBALS ===
  DAT_00XXXXXX  TireWearMultiplier    docs/12
=== DOC SECTIONS ===
  docs/04-tire-system.md :: <heading>
=== DOC CONTENT ===
  docs/31-call-chains/NNNN...md : <matching line>
```

How to read it: ranked hits, best first. Function/global NAMES here are doc labels —
GUESS tier per `INDEX.md` §Trust tiers. `find` also full-text scans doc bodies, so an
impl-spec or call-chain paragraph (LEAD tier) may itself be the best lead.
Empty result prints `nothing found` and exits 0.

## `global <DAT_addr>` — who touches a global

```
$ python tools/investigate.py global DAT_00XXXXXX
DAT_00XXXXXX — <docs/12 label if any>
graph users:   N functions
raw .c users:  M functions (ground truth)
  FUN_00XXXXXX  [R]  <line where it reads>
  FUN_00XXXXXX  [W]  <line where it writes>
```

The raw-`.c` count is authoritative; the graph under-reports (REFERENCE.md
§Bug Investigation — START HERE documents a 10-vs-~98 undercount case).

## `uses <token>` — raw ground-truth scan for ANY literal

Accepts hex values, struct offsets, `DAT_` names, identifiers. Output = file/function
hits, each tagged `[R]` read or `[W]` write, with the source line shown. Use it when
`find` fails (exact token, not a concept) and to enumerate every reader/writer of a
struct offset before trusting a docs/13 label.

## `system <term>` / `mod <term>` — subsystem map / patch surface

`system tire` → functions + shared globals + impl specs + call chains + mod targets +
vtables for the subsystem, in one screen. `mod penalty` → ranked patch surface:
docs/16 data-file params, mod_targets patch-points, runtime-writable globals.
Start every modding investigation here, not with a concept grep
(REFERENCE.md §Bug Investigation — START HERE, STEP 0).

## `param <field-name>` — data-file field → parser → format

`param FuelConsumption` → which parser function reads the field and which file format
carries it (docs/16 join). The cheapest mod rung (data file) starts here.

## Dossier — `<addr> [addr2 ...] [--snippet|--no-source|--callees]`

```
$ python tools/investigate.py <addr> --snippet
FUN_00XXXXXX — <name>
identity : <source atlas / vtable role / mod-target flags if known>
edges    : callers N / callees M
offsets  : +0xNNN  <docs/13 label>            <- auto-decoded (idx×4 already done)
           +0xNNN  <Field [StructA]; Field2 [StructB] ?>   <- ambiguous, pick by context
           ↳ +0xNNN  <label>                  <- pointer-chain base: offset into a SUB-object
globals  : DAT_00XXXXXX <label>  [R/W]
calls    : FUN_00XXXXXX <label>, ...
source   : <decisive lines only under --snippet>
```

Rules that live here:
- Batch ALL addresses your hypothesis touches in ONE invocation (iron rule 2).
- `--snippet` is the default choice (5–10× cheaper); full source dump only when the
  snippet is insufficient; `--no-source` for wide triage; `--callees` to pull callee
  source in the same call.
- The `↳` marker means the offset is into a sub-object, not the base struct — the
  exact confusion class that stalled a prior bug hunt (REFERENCE.md §Bug
  Investigation — START HERE). Do not add sub-object offsets to base-struct claims.
- Build the offset table once, reason once. Never re-derive by hand.

## `query.py` — graph structure questions

```
$ python tools/knowledge_graph/query.py traceback <addr> 3
FUN_00XXXXXX
  <- FUN_00XXXXXX <name>
     <- FUN_00XXXXXX <name>
  ... (caps 15 per node)
```

Wired commands only: `func calls callers trace traceback path global system search
stats context`. (`calls` ≡ `trace <addr> 1`; `callers` ≡ `traceback <addr> 1`;
`path <a> <b>` = shortest call-edge path; `context <addr|system>` = focused LLM
context window with a size estimate.) `struct`/`module`/`top` appear in the docstring
but are NOT dispatched — `Unknown command`. Graph content is DERIVED tier: regenerable
and mechanical, but names inside it inherit doc trust (GUESS/LEAD).

## Escalation ladder (cheap → expensive)

1. `query.py` graph lookups — structure only, instant.
2. `investigate.py` find/global/uses/system/mod/param — ranked leads + raw-scan truth.
3. `investigate.py` dossier `--snippet` — decisive source lines, batched.
4. Full raw `.c` read of a SPECIFIC located file (`analysis_pipeline/analyzed/`,
   `decompiled_all/`, `tools/decompiled_ida/`) — FACT tier, the final word.

Never invert the ladder: raw reads without an address in hand = the grep fan-out
iron rule 2 forbids.

---
Canonical sources: REFERENCE.md §Bug Investigation — START HERE; REFERENCE.md §Knowledge Graph; REFERENCE.md §Source Data; INDEX.md §Trust tiers — READ THIS BEFORE TRUSTING ANY FILE
Last validated: 2026-07-18 against 6bcccfe
