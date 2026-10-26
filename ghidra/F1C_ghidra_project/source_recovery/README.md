# Source Recovery — F1 Challenge 99-02

Self-contained workspace for recovering original source structure, class names,
and building the DLL modification framework. Everything here is independent of
the `docs/`, `analysis_pipeline/`, and `work/` directories.

**Rule: nothing in this directory writes to `docs/` or `analysis_pipeline/`.**
Results flow out only via explicit merge steps documented in `ACTION_PLAN.md`.

## Directory Map

```
source_recovery/
  ACTION_PLAN.md          -- THE master plan. Every task lives here.
  FINDINGS.md             -- All discoveries, dated. Append-only log.
  README.md               -- This file.

  01_binary_forensics/    -- PE analysis of F1C exe itself
    rich_header.md          Results of Rich Header decode
    rtti_scan.md            RTTI .?AV scan results
    debug_directory.md      PE debug directory, PDB paths
    strings_forensic.md     Deep string scan (assert patterns, .cpp refs)
    import_export.md        Import/export table analysis

  02_cross_binary/        -- Comparing other isiMotor1 binaries
    inventory.md            Which binaries we have, where from
    diff_results/           Per-binary comparison outputs
    symbols_found/          Any debug symbols recovered

  03_sdk_crossref/        -- rFactor SDK header cross-referencing
    headers/                Downloaded .hpp/.h files
    struct_alignment.md     TelemInfo/TelemWheel vs our docs/13 offsets
    class_hierarchy.md      SDK class tree vs our vtable analysis
    hardware_controls.md    CheckHWControl string grep results

  04_dll_framework/       -- DLL proxy/injection modification framework
    architecture.md         Design doc for the proxy DLL
    src/                    C++ source for the proxy DLL
    hooks/                  Per-subsystem hook definitions
    builds/                 Compiled DLLs

  05_automation/          -- AHK + Frida automated trace pipeline
    ahk_scripts/            AutoHotKey scripts per test scenario
    trace_configs/          Frida hook configs per scenario
    results/                Trace outputs from automated runs

  06_community_sources/   -- External knowledge recovery
    poochihead_patches.md   Analysis of community binary patches
    developer_interviews.md ISI developer quotes/knowledge
    modder_offsets.md       Offsets from F1CUI/community plugins
    downloads.md            URLs and status of all downloads

  binaries/               -- Downloaded exes/demos (gitignored)
    .gitignore              Ignores all binaries
```

## Relationship to Other Directories

| This directory | Reads from | Never writes to |
|---------------|------------|-----------------|
| `01_binary_forensics/` | `F1 Challenge Online.exe` | `docs/`, `work/` |
| `02_cross_binary/` | `binaries/` | `docs/`, `work/` |
| `03_sdk_crossref/` | `docs/13`, `knowledge_graph/` | `docs/` directly |
| `04_dll_framework/` | `knowledge_graph/functions.json` | anywhere else |
| `05_automation/` | `tools/trace/` (reads only) | `tools/trace/` |
| `06_community_sources/` | internet, downloads | `docs/` directly |

## How Results Flow Out

When a finding here is verified and ready to improve `docs/`:
1. Record in `FINDINGS.md` with evidence
2. Add a `[MERGE-READY]` tag
3. A separate session applies it to `docs/` via `work/CHANGELOG.md`

This prevents half-finished analysis from contaminating the authoritative docs.
