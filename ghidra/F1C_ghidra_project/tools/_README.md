# tools/ — Scripts + Derived Data

Currently holds BOTH code (scripts) and DERIVED data (27 IDA/cross-binary CSVs).
The reorg plan (`work/PLAN_reorg.md`, Phase 3) splits data into `data/`; until then
they coexist here. **Note:** many scripts hardcode `tools/<name>.csv` paths, so the
CSVs cannot be moved without a grep-and-update pass.

## Subdirectories

| Dir | Purpose | Trust |
|-----|---------|-------|
| `mod_pipeline/` | **Modding** — SEED/MAP/WATCH/PATCH, asm_tools, MODDING_PLAYBOOK | tooling |
| `trace/` | Frida runtime tracing agents | tooling |
| `knowledge_graph/` | Graph extract/build/query/rebuild | tooling |
| `decompiled_ida/` | 495 IDA Hex-Rays raw `.c` (IDA-only functions) | **FACT** |

## Key data files (DERIVED — regenerable via ida_export_all.py)

| File | Content |
|------|---------|
| `ida_functions.csv` | 6,170 functions (addr, end, size, name, cc, type) |
| `ida_xrefs.csv` | 14,223 call edges |
| `ida_data_xrefs.csv` | 17,037 func→global→read/write (the consumer index) |
| `ida_strings.csv` | 5,434 strings with referencing functions |
| `cross_binary_final.csv` | 3,018 F1C↔NASCAR matches + ISI identity (**CONFIRMED**) |
| `f1c_byte_sigs.csv`, `nascar0*_*.csv` | cross-binary matching inputs |

## Key scripts

| Script | Purpose |
|--------|---------|
| `ida_export_all.py` | Regenerate all ida_*.csv (IDA 9.1 headless, PowerShell) |
| `cross_binary_match.py` | String-anchored function matching |
| `parse_struct_dump.py` | Parse driver*.bin memory dumps |

To mod: go to `mod_pipeline/` and read `MODDING_PLAYBOOK.md`.
