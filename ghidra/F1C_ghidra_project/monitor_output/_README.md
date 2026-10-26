# monitor_output/ — Runtime Struct-Dump Snapshots (DERIVED)

Output from runtime memory monitoring (F1CUI/Frida) — periodic snapshots of game
struct memory used to identify field offsets by watching what changes.

| File | Content |
|------|---------|
| `snapshot_*.csv` | timestamped memory snapshots |
| `changes.csv` | diffs between snapshots (which offsets changed) |
| `identified_offsets.md`, `param_offset_map.md` | offsets inferred from the diffs |

DERIVED and historical — regenerable by re-running a monitor session. Confirmed
offsets flow into `docs/13` / `docs/26`. Trust the raw `.c` and exe byte-reads
over inferred offsets here.
