# scripts/ — Ghidra Java Extraction Scripts

Java scripts run inside Ghidra (not standalone Python). Used during the original
decompilation to export data and create functions Ghidra missed.

| Script | Purpose |
|--------|---------|
| `ExportFunctionSizes.java` | Export all functions → `work/function_sizes.csv` |
| `CreateMissedFunctions.java` | Create + decompile HIGH-confidence binary-gap functions |
| `CreateGapFunctions.java` | Create gap functions (superseded by the IDA approach) |

Run via Ghidra's Script Manager against the `F1C_Analysis` project. Not part of
the runtime modding or Python pipeline.
