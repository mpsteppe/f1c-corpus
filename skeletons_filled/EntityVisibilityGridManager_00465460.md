## EntityVisibilityGridManager_00465460 — Entity Visibility Grid & Priority Dispatch Manager

**Summary:** Manages a grid-based entity visibility system: clears old allocation lists, classifies visible entities by distance threshold, sorts them by priority (via merge sort), and dispatches visibility/computation updates to each entity. Uses a budget system (v83 counter) to limit per-frame work. Part of the entity management / LOD system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InputCommandDispatchToEntities (0045f4a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(obj+0xE5B8)+0x0)+0x0) | 0x6C | R | — | entity type/class ID byte |
| *(*(*(obj+0xE5B8)+0x0)+0x0) | 0x6D | R | — | entity visibility flag byte |
| *(*(*(obj+0xE5B8)+0x0)+0x0) | 0x71 | R | — | entity LOD distance threshold (byte) |
| *(*(*(obj+0xE5B8)+0x0)+0x0) | 0x219 | R | — | entity owner/team ID (dword, compared against a3) |
| *(*(obj+0x7C)+0x0) | 0x1AC | R | — | entity render/state flag (compared against a3) |
| *(*(obj+0xE5B0)+0x0) | 0x6D | R | — | visibility flag from alternate entity data source |
| *(*(obj+0xE5B8)+0x0) | 0x0 | R | — | pointer to entity data block (sentinel check: != -109) |
| *(obj+0x6C) | 0x0 | R | — | entity pointer within first allocation list |
| *(obj+0x6C) | 0x1AC | R | — | entity render/state flag in first-list node |
| *(obj+0x74) | 0x0 | R | — | entity pointer within second allocation list (visibility dispatch) |
| *(obj+0x7C) | 0x0 | R | — | entity pointer within third allocation list |
| *(obj+0x84) | 0x0 | R | — | entity pointer within fourth allocation list (dispatch queue) |
| *(obj+0xE5B0) | 0x0 | R | — | entity pointer within fifth allocation list |
| *(obj+0xE5B8) | 0x0 | R | — | entity pointer within sixth allocation list (primary visibility) |
| *(obj+0xE5C0) | 0x8 | R | — | linked-list next pointer in seventh allocation list |
| obj | 0x60 | R | — | float multiplier for grid cell size |
| obj | 0x64 | R | — | float multiplier for grid dimension |
| obj | 0x6C | R | — | head pointer of first entity linked list (allocation pool) |
| obj | 0x74 | RW | — | head pointer of second entity linked list (visibility work list) |
| obj | 0x78 | R | — | tail/sentinel pointer for second list |
| obj | 0x7C | R | — | head pointer of third entity linked list |
| obj | 0x84 | RW | — | head pointer of fourth entity linked list (dispatch output queue) |
| obj | 0x88 | R | — | tail/sentinel pointer for fourth list |
| obj | 0xE5B0 | RW | 0 | head pointer of fifth entity linked list (reset to 0) |
| obj | 0xE5B4 | RW | 0 | tail pointer of fifth list (reset to 0) |
| obj | 0xE5B8 | RW | 0 | head pointer of sixth entity linked list (primary visibility, reset to 0) |
| obj | 0xE5BC | RW | 0 | tail pointer of sixth list (reset to 0) |
| obj | 0xE5C0 | RW | 0 | head pointer of seventh entity linked list (reset to 0) |
| obj | 0xE5C4 | RW | 0 | tail pointer of seventh list (reset to 0) |
| obj | 0xE5C8 | RW | 0 | list sentinel / count for seventh list (reset to 0) |
| obj | 0xE5CC | RW | 0 | secondary list sentinel for seventh list (reset to 0) |
| this | 0x0 | R | — | pointer to the global entity array (vehicle array base) |

**Written-by note (persistence):**
- obj 0x74: written during visibility pass — external poke does NOT persist
- obj 0x84: written during visibility pass — external poke does NOT persist
- obj 0xE5B0: written once per dispatch cycle (reset list) — external poke does NOT persist
- obj 0xE5B4: written once per dispatch cycle (reset list) — external poke does NOT persist
- obj 0xE5B8: written once per dispatch cycle (reset list) — external poke does NOT persist
- obj 0xE5BC: written once per dispatch cycle (reset list) — external poke does NOT persist
- obj 0xE5C0: written once per dispatch cycle (reset list) — external poke does NOT persist
- obj 0xE5C4: written once per dispatch cycle (reset list) — external poke does NOT persist
- obj 0xE5C8: written once per dispatch cycle (reset list) — external poke does NOT persist
- obj 0xE5CC: written once per dispatch cycle (reset list) — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00465c18 | jpt_4655B3 | R | jump table for switch on ThresholdToRankClassifier result |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8 — vehicle on-track status flag (-1 = not on track) |
| 005f0f88 | word_5F0F88 | R | VEH[0].0x48B0 — vehicle index lookup table entry |
| 007cd2ac | dword_7CD2AC | W | base address for sort priority table (stores *this pointer) |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00464990 | ShortComputation_4990 | compute distance/screen-size metrics between entity and viewer |
| 00464ad0 | DispatchWrapper | execute visibility-related dispatch on matched entity |
| 00464ae0 | CharacterRangeCheckWithSignFlag | check if entity character/byte range matches grid cell |
| 00464bb0 | UtilityFunction_4bb0 | evaluate visibility threshold (uses cooling-rate float + distance) |
| 00464bd0 | FloatFieldDecrementWithClamp | decrement entity's LOD field by grid step, clamped above 0 |
| 00464f50 | DivisionWithCapComputation | compute grid cell count with cap (a2-based division) |
| 00464f90 | ThresholdToRankClassifier | classify grid cell count into rank 0-4 (returns enum) |
| 00465c70 | MergeSortOnLinkedList | sort entity linked list by priority value |
| 00465d70 | sub_465D70 | merge/sort an auxiliary entity list for dispatch ordering |
| 004b2c80 | VectorToShort3Conversion | encode 3D position vector to short integers |
| 004b33b0 | ProgressBarEventEncode | encode a progress-bar / event notification for entity |
| 00582290 | ConditionalFreeByFlagCheck | conditional free: check flag then free if set |
| 00587bcf | FreeWrapper_7bcf | generic memory deallocation wrapper |
| 00587bdc | CRTFtol | C runtime float-to-long conversion |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation with no-throw guarantee |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(obj+0xE5B8)+0x0) | 0x0 | != | 18446744073709551507 | entity data pointer is valid (not equal to -109 sentinel) |
| obj | 0x7C | == | 0 | third entity list is empty (skip iteration on empty list) |

**Guard interpretation:** The first guard checks if the entity data pointer at the head of the sixth list is not the sentinel value -109 (0xFFFFFFFFFFFFFF93). When the pointer IS -109, the entity is considered invalid/deleted and the code skips allocating it into the output list (BLOCKED from dispatch). A valid pointer PASSES through to be added to the visibility work list. The second guard (obj+0x7C == 0) checks if the third entity list is empty — when empty, the entire entity-iteration block that follows is skipped.