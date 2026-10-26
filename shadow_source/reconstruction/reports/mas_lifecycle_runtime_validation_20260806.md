# MAS lifecycle runtime validation — 2026-08-06

Evidence: `mas_lifecycle_runtime_20260806.jsonl`, captured by the read-only Frida probe against the original running game. The probe attached after process startup, wrote no target memory, and detached when the game exited normally.

## Outcome

The exercised load, unload, and shutdown path supports main-thread confinement and preserves every observed live-list invariant.

- Hook events before the synthetic final-row artifact: 1,248.
- Root MAS loads completed: 268 (`263` returned `0`, `5` returned `-2`).
- Single-node removals completed: 173, all returned `0`.
- Marked bulk prunes completed: 79, all returned `0`.
- Scene top-level parser invocations: 23.
- Vertex-buffer/resource-setup invocations: 79.
- Actual list snapshots: 1,040.
- Maximum observed live-list count: 12.
- Count mismatches, broken reciprocal links, cycles, or unreadable nodes during actual hooks: 0.
- Last valid shutdown snapshot: head null, declared count 0, traversed count 0.

Every MAS root load, single removal, bulk prune, scene parse, vertex/resource setup, and resource-manager shutdown event ran on thread `11116`. The live `GamePostMainLoop` marker also ran on `11116`. No MAS mutation was observed on another thread. The recovered network-thread marker did not fire in this session, so the result proves confinement only for the exercised path rather than every possible network mode.

## Failure observations

Five root calls returned `-2` for filename buffers beginning with `SEASONDATA\VEHICLES\GENERIC_F1.mas`. That file is absent from the installed tree. Each observed output value was null, and the list remained unchanged and valid.

The first probe version used Frida `readCString(512)`. In Frida, supplying `size` means the caller declares the string's byte size; it does not mean “scan for a terminator with this maximum.” The adjacent stack text captured after the filename therefore does **not** prove an unterminated input. Termination state for these five calls is undetermined. The probe now reads a bounded byte array, searches it explicitly for zero, and records a short preview plus terminator offset for future traces.

No zero-result/no-object event occurred. No parser `-1/-2` result occurred, so the statically proven freed-pointer publication after parser failure was not exercised and remains a negative-test requirement.

## Harness artifact

After normal process exit, the first runner version attempted one final RPC against an already destroyed script and reported that RPC failure as a list-invariant failure. This was not a target snapshot. The immediately preceding resource-manager-shutdown event contained a valid empty-list snapshot. The runner now falls back to the last readable snapshot on normal detach and excludes the synthetic final row from invariant accounting.

The same first-version capture recorded fixed-size filename strings, so trailing bytes after the meaningful filename are a harness artifact and are excluded from behavioral conclusions.

## Decision

For the exercised single-player lifecycle, implement the replacement list as main-thread confined with debug assertions for thread identity, count equality, reciprocal links, and empty shutdown. Do not generalize this to multiplayer/network loading until a network-session trace confirms the same boundary. Retain explicit synchronization as a future option rather than reproducing an unsynchronized global list implicitly.

Runtime-negative tests are still required for malformed headers, short reads, allocation failure, parser failure, and obsolete versions. The replacement must use the transactional failure policy regardless of whether those unsafe original paths are common in deployed content.
