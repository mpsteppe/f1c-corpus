## sub_4EF3F0_004ef3f0 — Playlist shuffle/randomizer with priority-song promotion

**Summary:** Builds a shuffled playlist from a file list: scans for "Magic Carpet Ride" (priority track), randomly selects entries using a float lookup table, rebuilds the linked list in shuffled order, and inserts the priority track at the front. Falls back to calling a virtual method on dword_7D6BB0 when the playlist is empty.

**Called by:** sub_4EFEF0 (004efef0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4)+0x0) | 0x0 | R | — | file path string pointer stored in linked-list node (char**) |
| *(*(this+0x4)+0x4) | 0x0 | R | — | file path string pointer in node (same field, accessed via different path) |
| *(*(this+0x4)+0x4) | 0x4 | R | — | next pointer within linked-list node structure |
| *(this+0x4) | 0x0 | R | — | file path string of head node (dereferenced head pointer) |
| *(this+0x4) | 0x4 | RW | — | next pointer field of head node (tail pointer tracking during removal) |
| *(this+0x4) | 0x8 | R | — | cursor into the linked list (node currently being processed) |
| this | 0x4 | RW | 0 | linked list head pointer (set null after full teardown) |
| this | 0x8 | RW | 0 | linked list tail pointer (set null after teardown) |
| this | 0xC | RW | 0 | linked list cursor/current-position pointer (set to head after rebuild) |
| this | 0x10 | RW | 0 | linked list node count (decremented on removal, guard for empty list) |

**Written-by note (persistence):**
- *(this+0x4) 0x4: written conditionally during node removal (prev->next updated); recalc each removal, external poke would be overwritten
- this 0x4: written once (set to 0 after full list teardown, then rebuilt); external poke would not survive the rebuild
- this 0x8: written once (set to 0 after full list teardown); external poke would not survive
- this 0xC: written once (set to head after scan); external poke would not survive
- this 0x10: written once (set to 0 after teardown); external poke would not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea79c | off_5EA79C | R | referenced by unk_62A0D8 (likely base directory path for file enumeration) |
| 00611130 | dword_611130 | R | parameter passed to virtual method call (dword_7D6BB0 + 76) |
| 0061113c | off_61113C | RW | array of string pointers; written as argument to virtual method call |
| 00611260 | aMagicCarpetRid | R | string literal "Magic Carpet Ride" — priority track name searched for in playlist |
| 00611274 | aMp3 | R | string literal "*.mp3" — MP3 file extension pattern for enumeration |
| 0061127c | aWav | R | string literal "*.wav" — WAV file extension pattern for enumeration |
| 00629120 | byte_629120 | R | empty string constant (fallback when pointers are null) |
| 0062a0d8 | unk_62A0D8 | R | base path/directory structure passed to sub_410E00 for file enumeration |
| 007d3c50 | dword_7D3C50 | RW | index counter into flt_7D3C54 array (incremented each shuffle iteration) |
| 007d3c54 | flt_7D3C54 | R | float array used as random-seed table for shuffle selection |
| 007d6bb0 | dword_7D6BB0 | R | music/playback system object; virtual method at vtable+76 called on empty playlist |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d5b0 | sub_40D5B0 | cleanup/free temporary string buffer (v45) |
| 00410de0 | sub_410DE0 | initialize a new playlist node with a file path string |
| 00410e00 | sub_410E00 | extract file path string from a data structure |
| 00414410 | sub_414410 | insert a node into the linked list at a specific position |
| 00414470 | ShortComputation_a780 [exact] | compute index/value (used in shuffle for node selection) |
| 00414480 | sub_414480 | destroy/free a linked list node (cleanup/deallocate) |
| 004192a0 | sub_4192A0 | remove a node from the temporary linked list |
| 004667a0 | LinkedListDestructorWithData [structural] | destroy entire temporary linked list and free all nodes |
| 004db610 | ShortComputation_ac20 [exact] | create/init a new node structure for the temporary list |
| 004dbcf0 | sub_4DBCF0 | insert "Magic Carpet Ride" node at front of main playlist |
| 004ef7b0 | sub_4EF7B0 | create a new node instance for insertion into main list |
| 004ef7e0 | sub_4EF7E0 | enumerate files matching a pattern (e.g., "*.mp3") and add to list |
| 004f03b0 | sub_4F03B0 | notify/reset something after shuffle completes |
| 00578600 | StringCopyWithBufferRealloc [structural] | copy/duplicate a string (store in node) |
| 00579060 | sub_579060 | case-insensitive string comparison (used to find "Magic Carpet Ride") |
| 005be8e3 | ??2@YAPAXI@Z | operator new (memory allocation for nodes) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 0 | playlist head is null — skip Magic Carpet Ride search |
| this | 0x10 | <= | 0 | playlist count is zero or negative — skip shuffle loop entirely |
| this | 0x10 | == | 0 | playlist count is exactly zero — trigger virtual method call on dword_7D6BB0 |

**Guard interpretation:** When count (0x10) <= 0, the shuffle loop is skipped. When head (0x4) is null alongside count <= 0, skips the Magic Carpet Ride scan. When count is exactly 0 at the end AND dword_7D6BB0 is non-null, calls the fallback virtual method — this is the "empty playlist" handling path that passes control to an external music system.

**String literals referenced (deterministic):**

- `Magic Carpet Ride`
- `*.mp3`
- `*.wav`
