## MediaBufferPlaybackManager_0048d9d0 — Playback Item Render Loop

**Summary:** Renders a linked list of media buffer items with string lookup, message dispatch, and surface fill operations. Handles playback index clamping, item navigation, state-dependent multi-item rendering, and virtual-method cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE8) | 0x0 | R | — | data/string pointer of first linked list node |
| *(this+0xEC) | 0x4 | R | — | unknown (possibly next-pointer within a node struct) |
| *(this+0xF0) | 0x0 | R | — | data pointer of current list node (checked for null) |
| obj | 0x10 | R | — | vtable entry #4 — render/draw virtual callback |
| obj | 0x2C | R | — | vtable entry #11 — cleanup/reset virtual callback |
| this | 0x0 | R | — | vtable pointer |
| this | 0x4 | R | — | width/dimension parameter for render calls |
| this | 0xC | R | — | X-position parameter for render calls |
| this | 0x84 | R | — | state index passed to ConditionalDelegation_6460 |
| this | 0xC8 | R | — | base pointer; offset +108 yields count for computation |
| this | 0xE8 | R | — | linked list head pointer of media items |
| this | 0xF0 | RW | 0 | current playback node pointer (iterator into linked list) |
| this | 0xF4 | R | — | total list item count (upper bound for index checks) |
| this | 0xF8 | R | — | maximum valid index (page limit, used as this[62]-1) |
| this | 0xFC | RW | — | current playback index (clamped, then snapshotted) |
| this | 0x100 | R | — | target navigation index used to reposition current node |
| this | 0x104 | RW | — | selected/tracked index during multi-item loop |
| this | 0x108 | RW | — | cached X position for item index 0 (from sub_487060) |
| this | 0x10C | RW | — | cached X position for item index 1 (from sub_487060) |
| this | 0x110 | RW | — | cached X position for item index 2 (from sub_487060) |
| this | 0x114 | RW | — | cached X position for item index 3 (from sub_487060) |
| this | 0x118 | RW | — | cached Y/size for item index 0 (from sub_4870E0) |
| this | 0x11C | RW | — | cached Y/size for item index 1 (from sub_4870E0) |
| this | 0x120 | RW | — | cached Y/size for item index 2 (from sub_4870E0) |
| this | 0x124 | RW | — | cached Y/size for item index 3 (from sub_4870E0) |

**Written-by note (persistence):**
- this 0xF0: set unconditionally at start (this[60]=this[58]), conditionally updated during navigation loop; persists across calls as iterator state
- this 0xFC: conditionally written — clamped when index exceeds max, snapshotted at loop entry; persists until next clamp/update
- this 0x104: written unconditionally at loop entry (line 140), conditionally updated when item inside bounds (line 189); persists as selection state
- this 0x108: set once at function start (line 53); persists as cached layout value
- this 0x10C: set once at function start (line 55); persists as cached layout value
- this 0x110: set once at function start (line 57); persists as cached layout value
- this 0x114: set once at function start (line 59); persists as cached layout value
- this 0x118: set once at function start (line 54); persists as cached layout value
- this 0x11C: set once at function start (line 56); persists as cached layout value
- this 0x120: set once at function start (line 58); persists as cached layout value
- this 0x124: set once at function start (line 60); persists as cached layout value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path (fallback when node string is null) |
| 005ec4c0 | byte_5EC4C0 | R | string lookup table (search key for BinarySearchInStringTable) |
| 005ec4cc | byte_5EC4CC | RW | message display buffer (output of string lookup, destination for strcpy) |
| 007cde00 | unk_7CDE00 | R | global render context pointer (fed to GlobalAccessor_5150) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | search string table for key, fill output buffer with result |
| 004862c0 | UIStringAccessor_62c0 | get primary UI string accessor/handle from this |
| 004862e0 | UIStringAccessor_62e0 | get secondary UI string accessor/handle from this (used when item inside clip bounds) |
| 00486460 | ConditionalDelegation_6460 | conditionally delegate based on state index; returns object or null |
| 00486720 | ShortComputation_6720 | compute current playback state/mode (returns byte 3/4/5/8/9 for multi-item path) |
| 00487060 | sub_487060 | get X position for a given item index (0-3) |
| 004870e0 | sub_4870E0 | get Y/size for a given item index (0-3) |
| 00490920 | Accessor | access UI state/context (called before surface fill calls) |
| 004918d0 | RenderSurfaceFillCopy | fill/copy a rectangle on the render surface |
| 00494f00 | ShortComputation_4f00 | compute layout dimensions (width, height) from a UI string |
| 00494f10 | UIMessageDispatch | dispatch UI message/event with position, size, context, and flag |
| 00495150 | GlobalAccessor_5150 | access global render context from unk_7CDE00 |
| 00498880 | DualFieldRead | read two layout/state fields into output parameters |
| 0049adb0 | ShortComputation_adb0 | compute render item count from (this[50] + 108) |

**Guard conditions:** 
1. `!this[58] || !*this[58]` → return 0: **BLOCKS** when linked list head is null or points to null data. **PASSES** when list is populated.
2. `this[63] > this[62]-1` → clamp this[63] = this[62]-1: **PASSES** index through after clamping to max valid value.
3. `this[63] >= 0 && this[63] < this[61]` → walk list to node: **PASSES** when index within [0, count). **BLOCKED** (v11=0) when out of range.
4. `v15 (mode) == 3 || == 4 || == 5 || == 8 || == 9` → enter multi-item rendering loop: **PASSES** for these playback modes. **BLOCKED** for all other modes — loop skipped entirely.
5. `this[64] < 0 || this[64] >= this[61]` → null out this[60]: **BLOCKS** navigation when target index out of bounds (sets current node to 0). **PASSES** by walking list from head to target index.
6. `computed_count > 4` → loop over additional items (indices 4..count-1): **PASSES** when more than 4 items exist. **BLOCKED** for 4 or fewer — no multi-item loop.
7. Clip/intersection test inside loop: `v53 <= v22 || v53 >= v49+v22 || v54 <= v20 || v54 >= v20+v50` → uses secondary UIStringAccessor if item is inside clip bounds, primary otherwise. Both paths always execute (non-blocking branch).
