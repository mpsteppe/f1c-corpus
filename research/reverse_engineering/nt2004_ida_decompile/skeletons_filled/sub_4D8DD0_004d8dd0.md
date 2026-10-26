## sub_4D8DD0_004d8dd0 — ReplayEventTreeProcessor

**Summary:** Walks a sorted binary tree of time-stamped replay events, selecting the node at time `a2` and processing events before and after it. Drives replay playback by decoding event descriptors into game-state mutations.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x3AC)+0x4)+0x0) | 0x0 | R | — | Next (right) node's data pointer in the sorted event tree |
| *(*(*(this+0x3AC)+0x8)+0x0) | 0x0 | R | — | Previous (left) node's data pointer in the sorted event tree |
| *(*(this+0x3A4)+0x4) | 0x4 | R | — | First detail entry offset within the active event node |
| *(*(this+0x3AC)+0x0) | 0x0 | R | — | Current tree node's data/timestamp value |
| *(*(this+0x3AC)+0x0) | 0x4 | R | — | Current tree node's sub-data pointer |
| *(*(this+0x3AC)+0x0) | 0x8 | R | — | Current tree node's entry count (uint16) |
| *(*(this+0x3AC)+0x4) | 0x0 | R | — | Right child tree node pointer |
| *(*(this+0x3AC)+0x8) | 0x0 | R | — | Left child tree node pointer |
| *(this+0x3A4) | 0x0 | R | — | Root/head event list pointer |
| *(this+0x3A4) | 0x8 | R | — | Event list structure member |
| *(this+0x3A8) | 0x0 | R | — | Auxiliary pointer used in tree navigation |
| *(this+0x3AC) | 0x0 | R | — | Tree node data (float timestamp) |
| *(this+0x3AC) | 0x4 | R | — | Tree node right-child pointer |
| *(this+0x3AC) | 0x8 | R | — | Tree node left-child pointer |
| this | 0x3A4 | R | — | Pointer to sorted event linked-list/tree head |
| this | 0x3A8 | R | — | Pointer to alternate event tree branch |
| this | 0x3AC | RW | — | Current cursor node in the event tree (navigated by time) |
| this | 0x3B0 | R | — | Tree size / node count for boundary check |
| this | 0x80C | R | — | Event-decoding output buffer/sub-system base |
| this | 0x810 | R | — | Event-decoding subsystem state |

**Written-by note (persistence):**
- this 0x3AC: recalculated every frame based on time parameter `a2` — walks the tree to reposition cursor. External poke would be overwritten on next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d32b0 | sub_4D32B0 | Decode a single event descriptor from the replay data into buffer |
| 004d33b0 | FAILWRONGDESCRIPTION [exact] | Initialize/reset event-decoding scratch structure |
| 004d3400 | sub_4D3400 | Copy event base data into the decoding context |
| 004d4c00 | sub_4D4C00 | Advance the decoding subsystem state to time `a2` |
| 004d4ce0 | sub_4D4CE0 | Check if forward-event decoding is complete/blocked |
| 004d4d20 | sub_4D4D20 | Check if backward-event decoding is complete/blocked |
| 004d4d60 | sub_4D4D60 | Commit a decoded event mutation to the output buffer |
| 004d4eb0 | sub_4D4EB0 | Finalize post-processing on the event output buffer |
| 004d4fe0 | sub_4D4FE0 | Extract final result from the event output buffer |
| 004d6db0 | LinkedListTraversalWithFilter [structural] | Traverse linked list of replay objects filtered by time and active state |
| 0052e5c0 | sub_52E5C0 | Mark replay object as processed/unlock after time-check |
| 0052e5d0 | sub_52E5D0 | Apply a decoded replay event to game state at time `a2` |
| 0052e830 | sub_52E830 | Check if replay object is past its end time (expired) |
| 0052e850 | FloatComparisonCheck [exact] | Check if replay object is before its start time (not yet active) |
| 0057a5b0 | sub_57A5B0 | Lock/acquire replay object for thread-safe processing |

**Guard conditions:** None at function entry — processes all tree nodes unconditionally. Internal guards: tree node pointer null-checks prevent walking past tree boundaries; entry-count bounds (`j < count-1`) prevent processing beyond last node; iteration limit of 64 per direction prevents infinite loops.
