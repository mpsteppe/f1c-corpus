# 36 — Recovered C++ vtables (RTTI-less object model)

F1C is compiled `/GR-` (no RTTI), so IDA/Ghidra vtable scans return **empty**
(`tools/ida_vtables.csv` is blank). But the virtual method dispatch tables
physically exist as arrays of code pointers in `.rdata`. This recovers them by
byte-scan, giving the object model IDA/Ghidra could not.

- **Tool:** `tools/extract_vtables.py` (re-runnable, no IDA needed)
- **Data:** `work/vtables.csv`
- **Inputs:** exe `.rdata` bytes + `tools/ida_switches.csv` (exclude jump tables) +
  `tools/ida_data_xrefs.csv` (attribute each table base to its constructor)

## Method

1. Scan `.rdata` for runs of consecutive pointers into `.text`/`.text1`.
2. **Split** back-to-back tables at any address referenced by a data-xref — a
   constructor does `mov [ecx], offset vtable`, so every vtable base is referenced.
   (This split the largest 1924-slot merged run into individual per-class tables.)
3. Classify: `vtable` = base is referenced by code; `unref` = no referencer;
   `switch` = base matches an IDA jump table (excluded).

## Yield

| kind | count | note |
|------|-------|------|
| `vtable` (base referenced by a ctor) | 181 | 3,202 method slots total |
| `unref` | 101 | no data-xref — data blob or table IDA missed |
| `switch` | 0 | jump tables cleanly excluded |

**Confidence:** the tables and their slot pointers are **FACT** (raw bytes).
**72% of the 3,202 method slots resolve to known IDA function starts** — a random
pointer array would not; this confirms they are real vtables. Ctor attribution
(`ctor_funcs`) is **DERIVED** from data-xrefs. Class *names* are mostly **OPEN**
(see below).

Largest classes (by virtual method count): `0x005a6e98` (179 slots, ctor
`0x0047fba0`), `0x0059f210` (138, ctor `0x004668e0`), `0x0059f878` (136, ctor
`0x0046a220`), `0x005a6bc8` (86), then a long tail of 40–53-slot classes around
`0x0048xxxx` ctors (a UI-widget or render-object hierarchy).

## What this unlocks

- **Object model** — each table = one class's virtual methods, in slot order. The
  class hierarchy IDA/Ghidra could not produce without RTTI.
- **vtable-swap mods** — redirect slot N of a class's table to hook *every*
  instance's virtual call. A strictly more powerful mod primitive than the
  single-call byte-patches in `mods/` (e.g. `docs/22 §8`).
- **~887 new-function candidates** — the 28% of slots that do NOT resolve to a
  known function point at code IDA/Ghidra never defined (real methods, missed).
  Feed these to the function-creation pipeline.

## Open / next

- **Naming the classes.** Current atlas (`docs/34`) names lifecycle *singletons*
  (DynMan, Game) that are called directly, not virtually — so only 3 vtables match
  it (e.g. `0x0059e678` → CamMan, 10 slots). Naming the polymorphic hierarchies
  needs cross-binary method-level matching (NASCAR sibling vtables) or tracing
  `call [reg+N]` dispatch sites to the slot in use.
- **Slot → method-name maps** for the confirmed vtables would let vtable-swap mods
  target a named method instead of a slot index.

Full data: `work/vtables.csv` (`vtable_addr, slots, kind, cls, ctor_funcs, method_addrs`).
