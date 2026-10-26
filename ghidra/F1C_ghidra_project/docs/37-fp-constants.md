# 37 — Floating-point constant pool (physics/math magic numbers)

The actual `double`/`float` constants baked into the binary, with their values and
the functions that read them. IDA tagged 1959 FP constants (`dbl_`/`flt_`) and
their readers but only by symbol — this reads the real bytes so `dbl_59E430`
becomes `0x0059e430 = 0.75`, attributed to a subsystem.

- **Tool:** `tools/extract_fp_constants.py`
- **Data:** `work/fp_constants.csv` (`addr, type, value, ref_count, files, ref_funcs`)
- **Inputs:** exe `.rdata`/`.data` bytes + `tools/ida_data_xrefs.csv` (FP symbol→reader)
  + `work/source_file_map_expanded.csv` (reader→source file)

## Provenance

| Column | Basis | Confidence |
|--------|-------|-----------|
| `value` | raw IEEE-754 bytes read from the exe | **FACT** |
| `addr`, `type` | IDA `dbl_`/`flt_` symbol | **FACT** |
| `ref_funcs`, `ref_count` | IDA data-xrefs | **FACT** |
| `files` | reader function → source file (usable rows only) | **DERIVED** (HIGH/ANCHOR only) |

845 constants have readable bytes (the rest are in uninitialized `.data`/BSS —
skipped, no bytes); 160 are attributed to at least one source file.

Cross-check: `0x0059e450 = 0.5` matches the prior mod_pipeline correction
(project memory `mod-pipeline`) — independent agreement.

## Most-referenced

Shared arithmetic constants dominate the head (`0.0` ×334, `1.0` ×208, `0.5` ×146).
The modding value is in the **less common values attributed to physics files** —
`hdvehicle.cpp`, `tire_manager.cpp`, `weather.cpp`, `vehload.cpp` — which are real
model coefficients, not generic arithmetic. Filter `work/fp_constants.csv` by
`files` containing a physics unit and `value` not in {0,1,0.5,-1,2} to find them.

## Uses

- **Physics modding** — change a coefficient by patching the `.rdata` double/float
  (the value is a real byte in the exe, editable via `tools/mod_pipeline/`).
- **Formula recovery** — knowing the constants a function reads narrows what
  equation it implements (feeds a future angr/Triton pass, `docs/33` item E).

## Tooling integration

Surfaced in `tools/investigate.py` — a function's dossier now prints
`FP constants read (N): …` alongside the source-atlas name, vtable role, and
mod-target flag. See the identity block in `investigate.py`.

Full data: `work/fp_constants.csv`.
