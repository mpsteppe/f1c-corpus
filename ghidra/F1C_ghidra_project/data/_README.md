# data/ — Derived Datasets (DERIVED)

Regenerable data produced from the binary/dumps. Not ground truth — rebuild from
`inputs/` + `tools/` if in doubt.

| Dir | Content | Regenerate via |
|-----|---------|----------------|
| `inventory/` | `inventory.csv` (string→function), `driver*_annotated.txt`, `driver*_gaps.csv` | `tools/parse_struct_dump.py`, inventory scripts |

Note: the larger IDA export CSVs currently still live in `tools/` (they are
referenced by hardcoded `tools/` paths in many scripts). Phase 3 of
`work/PLAN_reorg.md` relocates them here with a grep-and-update pass.
