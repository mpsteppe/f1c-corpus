# F1 Challenge 99-02 — Reverse Engineering & Modding Project

Target: `F1 Challenge Online.exe` — x86 PE32, MSVC 6.0 (2002), 3.14 MB.
Goal: complete public documentation of the game engine, and surgical modding
authored directly from the decompilation.

> **New here? Read [`INDEX.md`](INDEX.md) first** — it is the single entry point
> (repo map, trust tiers, where to start for any task). This README is a summary.

---

## Status (current)

- **6,868 functions** mapped (Ghidra + IDA), **16,475 call edges**, ~8,048 named globals.
- **3,018 functions (52%)** cross-matched to NASCAR Thunder 2003/2004 for confirmed
  ISI identity — 17 engine classes recovered (`docs/27`, `tools/cross_binary_final.csv`).
- Documentation complete across `docs/00`–`docs/27` + 18 impl specs + 237 call chains.
- **Modding capability shipped.** First mod: cutting the track = instant DQ,
  confirmed in-game — authored via `tools/mod_pipeline/`.

The reverse-engineering phase is essentially complete. Active work is modding.

---

## Where things are

| Path | What |
|------|------|
| [`INDEX.md`](INDEX.md) | **Start here** — entry point, trust tiers, task router |
| [`MANIFEST.md`](MANIFEST.md) | Every top-level item + purpose + trust tier |
| [`CLAUDE.md`](CLAUDE.md) | Operational instructions + detailed current state |
| `docs/` | Documentation (00–27 by system) — see `docs/_README.md` for trust map |
| `decompiled_all/`, `analysis_pipeline/analyzed/` | Raw decompiled `.c` — **FACT tier** |
| `tools/mod_pipeline/` | **Modding pipeline** — read `MODDING_PLAYBOOK.md` to mod |
| `tools/` | Scripts + IDA/cross-binary CSVs |
| `knowledge_graph/` | Call graph / globals / structs (JSON) |
| `mods/` | Shipped mods |
| `work/PLAN_reorg.md` | Repo reorganization plan |

---

## To mod a behavior

1. Read `tools/mod_pipeline/MODDING_PLAYBOOK.md` (process + iron rules).
2. `python tools/mod_pipeline/mod_pipeline.py map <seed>` — find who touches the anchor.
3. `python tools/mod_pipeline/asm_tools.py resolve <addr>` — identity + signature.
4. `python tools/mod_pipeline/asm_tools.py redirect …` — plan a call redirect safely.
5. Patch a COPY of the exe (never the original); test with Frida first.

## Key environment facts

- Exe ImageBase 0x400000, no ASLR — VAs match Ghidra/IDA.
- Python: `%USERPROFILE%\AppData\Local\Python\bin\python3.exe`
- IDA: `C:\Program Files\IDA Professional 9.1\idat.exe` (PowerShell for headless).
- MSVC 6.0, `/GR-` (no RTTI). thiscall: `this` in ECX, callee cleans via `ret N`.
