# F1 Challenge Online v49 — binary comparison vs corpus V10

Generated: 2026-08-08

## Provenance

| | Old (corpus source) | New |
|---|---|---|
| Path | `%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe` | `%USERPROFILE%\Desktop\f1_challenge_online_version_08082026\F1 Challenge Online.exe` |
| SHA256 | `1A70E5ED0C4A059F7F66741B1682D0AEDB14921AA6140CDB70B09549FDF3A003` | `19A338BDC7D3F2CDCCFE352ECE3E09F0D8A7CFCEDD7959234567BAD5A4BC39C7` |
| Size | 3,141,632 | 3,141,632 |
| TimeDateStamp | 0x3E9C24F6 | 0x3E9C24F6 |
| ImageBase / Entry | 0x400000 / RVA 0x4D8000 | identical |
| PE Checksum | 0x306F7B | 0x30ED71 |

Same toolchain, same linker layout, same timestamp — the new exe is a byte-patched
successor of the corpus binary (the corpus `strings_index.json`/`canonical_variant_profile.json`
already identify "F1 Challenge Online.exe" at this lineage). The corpus IDB
(`analysis/sdk_lab_idb/F1_Challenge_Online_sdk_lab.i64`) is the old build.

## Method

1. New exe fully re-analyzed + decompiled with IDA 9.1 headless (`idat.exe -A`):
   6,189 functions, 6,179 decompiled, 10 Hex-Rays failures (all near 0x8D8xxx).
   Artifacts in this folder: `functions/`, `functions_meta.jsonl`,
   `strings_index.json`, `F1_Challenge_Online_v49.i64`.
2. Old binary function bytes dumped from the corpus IDB (`old_functions_meta.jsonl`).
3. Whole-file byte diff (all 14 differing regions decoded, capstone-disassembled).
4. Addresses are directly comparable: section layout is identical.

## Whole-binary verdict

**14 differing file regions, 550 bytes total (0.018% of the exe).**
Everything else — 99.98% of the file — is byte-identical.

| # | File off | Size | Section | Meaning |
|---|---|---|---|---|
| 1 | 0x190 | 4 | PE header | **Checksum** 0x306F7B → 0x30ED71 |
| 2 | 0x309 | 2 | PE header | `.text1` SizeOfRawData 0xB6000 → 0x20000 (cosmetic fix) |
| 3 | 0x2D9D3 | 4 | .text | **GamePostMainLoop** (0x42D9D3): hook |
| 4 | 0xA0F80 | 4 | .text | **Options_Setup** (0x4A0F80): hook |
| 5 | 0xAA375 | 1 | .text | **PlayerOptionsInitializer** (0x4AA375): Steering Help flag 2→0 |
| 6 | 0xAA3B1 | 1 | .text | **PlayerOptionsInitializer** (0x4AA3B0): Steering Help Functionality default 1→0 |
| 7 | 0x14285D | 4 | .text | **sub_5427D0** (0x54285D): hook + inserted store |
| 8 | 0x1BD0C0 | 13 | .rdata | string `"oph.dll"` → `"plugins\\*.dll"` |
| 9 | 0x1BD0E1 | 48 | .rdata | string table: old oph/steeringwheel names → `"plugins\\"`,`"lstrcpyA"`,`"SetDllDirectoryA"` |
| 10 | 0x1C01F4 | 104 | .data | per-vehicle float max-limits 15.0 → FLT_MAX (5 entries, records `'h'..'l'`) |
| 11 | 0x1C02D0 | 44 | .data | per-vehicle float max-limits 6.0 → FLT_MAX (2 entries, records `'s','t'`) |
| 12 | 0x1C0550 | 4 | .data | global float 1.0 → FLT_MAX |
| 13 | 0x1ED015 | 203 | .text1 | entry stub rewritten (start_008D8000) |
| 14 | 0x1EE580 | 114 | .text1 | trampoline zone (was zero padding) |

## Function-level comparison

| Class | Count | Note |
|---|---|---|
| Byte-identical | 6,157 | addresses + bytes match old IDB exactly |
| Real byte changes | 5 | GamePostMainLoop, Options_Setup, PlayerOptionsInitializer, sub_5427D0, start |
| Old-only in IDB (analysis artifact) | 975 | present in new exe byte-identical; old IDB had human-created functions that fresh auto-analysis does not mark |
| New-marked in fresh analysis (artifact) | 27 | byte-identical in both binaries; 22 stubs at 0x48489B..0x484CEB (alloc-236B constructors sharing vtable `off_5A8048`), 0x500170, 0x59CA3B..0x59CB33 — old IDB simply never marked them |

**No function was actually added or removed between V10 and v49.**

## The changes, decoded

### 1. Plugin loader generalization (v49 headline: "Added functionality for loading plugins")

The startup stub `start` (0x8D8000, grew 190 → 5,607 bytes) was rewritten:

- **Old**: hard-coded `GetModuleHandleA("oph.dll")` + `GetProcAddress(...,"start"/"port"/"ip")`,
  then `GetModuleHandleA("steeringwheel.dll")` + `"start"`, then anti-debug
  `GetProcAddress("IsDebuggerPresent")` + call (exit to 0x18A19E if debugging).
- **New**: `GetModuleHandleA("KERNEL32")` → `GetProcAddress("lstrcpyA")`,
  `GetProcAddress("SetDllDirectoryA")` → `SetDllDirectoryA("plugins\\")`,
  then `FindFirstFileA("plugins\\*.dll")` loop: per DLL `lstrcpyA` name,
  `LoadLibraryA`, `GetProcAddress(...,"start")`, call `start`. Same
  IsDebuggerPresent anti-debug tail.

New string table at 0x5BD0C0: `"plugins\\*.dll"`, `"start"`, `"plugins\\"`,
`"lstrcpyA"`, `"SetDllDirectoryA"`, `"IsDebuggerPresent"`.
Plugin state block 0x5C7520..0x5C754C (module handle, resolved APIs, find handle,
loaded-DLL slots). Matches the shipped `plugins\` folder (Lua.dll, oph.dll,
SteeringWheel.dll all export a `start` entry).

### 2. sub_5427D0 (string-registry / search-path builder) — real code insert

5-byte hook at 0x54285D; trampoline at 0x8D9580 re-executes the original
`mov eax, [0x8B8E30]` and **inserts `mov [0x5C754C], esi`** (new global) before
jumping back. 0x5C754C sits in the plugin state block — the string-lookup path
now hands something (ESI) to plugin-land. 0x8B8E30 is the string-registry global
(corpus: StringRegistry_0053C800 family). Likely v47 "mts file handling" work.

### 3. PlayerOptionsInitializer (0x4AA270) — Steering Help defaults (v45/v46)

- 0x4AA372: option-flag `2` → `0` for the **"Steering Help"** option (string 0x5D1F64)
- 0x4AA3B0: default value `edi(1)` → `ebx(0)` for the **"Steering Help Functionality"**
  option (string 0x5D1EF8: "0 = new help, 1 = new help + grip, 2 = original F1 2001, 3 = original + grip")

Changelog v45/v46 verbatim: "changed Steering Help for 0 as default". Confirmed.

### 4. Float max-limits removed (→ FLT_MAX) — .data tables

- 5 records `'h','i','j','k','l'`: first float 15.0 → FLT_MAX
- 2 records `'s','t'`: first float 6.0 → FLT_MAX
- global 0x5C0550: 1.0 → FLT_MAX

Per-vehicle parameter tables (24-byte records: float limit, char id, dword, 2 floats).
Effect: upper clamp lifted so any value is accepted. Consistent with v25 GUI
spinbox enablement / v29 "increased race grid position limit" family of changes.

### 5. GamePostMainLoop & Options_Setup — no-op relocations

Both are 5-byte `E9` hooks that jump into the trampoline zone and execute the
original instruction(s) unchanged (mov ecx,0x7CD25C / call 0x4A1830) before
jumping back. Zero behavioral difference — patch-tooling leftovers kept in the
build (changelog v26: "fixed code typo at asm, dunno tho what it exactly todo").

## SDK relevance

- Corpus names (name_index / functions/) apply to the new exe **unchanged** —
  identical addresses, identical layout. No re-symbolization needed.
- `GamePostMainLoop` (0x42D8A0) hook site is inside the main loop; useful anchor.
- New plugin ABI: `plugins\*.dll` with export `start` (stdcall `void start()`),
  state block 0x5C7520..0x5C754C, plus new global write 0x5C754C from
  sub_5427D0 (string-registry path lookups).
- All v10-era features (104 players, 8k, DRS, gear 8-9 stubs, 99 AI, borderless,
  oph/steeringwheel plugins) were already present in the corpus binary; v49 only
  generalizes the plugin loader and tweaks Steering Help defaults.

## Artifacts in this folder

- `functions/` — 6,179 decompiled C files (new exe), `<name>_<addr>.c` layout
- `functions_meta.jsonl` — addr/name/size/byte-MD5 per function
- `old_functions_meta.jsonl` — same for corpus IDB
- `strings_index.json` — new exe strings
- `F1_Challenge_Online_v49.i64` — new analysis database (IDA 9.1)
- `f1c_byte_compare.py`, `f1c_definitive_compare.py`, `f1c_decode_delta.py`,
  `f1c_decompile_v49.py`, `f1c_dump_old_bytes.py` — reproducible pipeline
- `delta_decode.txt` — capstone side-by-side disassembly of every changed region
- `changed_functions.json`, `new_functions.json`, `byte_compare.json`,
  `real_changes.json`, `real_new_code.json`

## Caveats

- 10 functions failed Hex-Rays (near 0x8D8xxx — the new entry/exit junk zone).
- Strings diff vs corpus `strings_index.json` is noisy (different extractor
  settings); the authoritative string changes are the 3 regions listed above.
- 27 "new" + 975 "removed" entries are analysis-coverage artifacts, proven by
  byte-identity; do not treat as code added/removed.
