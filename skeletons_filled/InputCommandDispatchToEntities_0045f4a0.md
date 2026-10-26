## InputCommandDispatchToEntities_0045f4a0 — InputCommandDispatchToEntities

**Summary:** Dispatches input commands from ring buffer to session entities. Processes each command through entity-specific logic: direct dispatch for global state handlers, or per-entity filtering with flag checks and texture creation. Final pass handles entity visibility grid updates.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionResponseStatus (00463cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | postProcessInput [CONFIRMED] — method pointer for SingleFunctionForward/SingleFunctionDispatch |
| this | 0x410 | R | — | Entity index/ID array entry (DWORD per entity, used for visibility lookup) |
| this | 0x3C74 | R | — | Node ID array (entity IDs, compared against self ID) |
| this | 0x3E14 | R | — | Number of active entities in the session |
| this | 0x3FB8 | R | — | COM interface pointer passed to sub_57A730 |
| this | 0x3FC4 | R | — | Session phase/state (compared to 3 for flag check gating) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd2a8 | dword_7CD2A8 | R | Unknown_Menu_Struct_7CD2A8 [DERIVED] — used for entity visibility grid |
| 0083ee60 | dword_83EE60 | R | RingBufferCount [DERIVED] — ring buffer counter for input commands |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461440 | ReferencesGlobalState | Check if this object references global state (controls dispatch path) |
| 00461470 | ThunkToFUN00461480 | Thunk to FUN_00461480 for state copy |
| 004614c0 | TwoStageCheck | Two-stage condition check for command filtering |
| 00461530 | FlagBitTest | Test flag bit on entity structure at offset +1 from base |
| 00462250 | TextureCreationWrapper | Create/update texture for entity rendering |
| 00462300 | SingleFunctionDispatch | Dispatch single function on method pointer |
| 00462310 | SingleFunctionForward | Forward call via method pointer |
| 00465300 | sub_465300 | Process input command for global state |
| 00465460 | EntityVisibilityGridManager | Manage entity visibility grid entries |
| 00465c30 | LinkedListPopFront | Pop front node from visibility grid linked list |
| 004b0170 | EmptyStub_0170 | Empty stub |
| 004b3af0 | AdvanceRingBuffer | Advance to next ring buffer entry |
| 004b3b30 | SessionDataCopy | Copy session data / ring buffer state |
| 0057a730 | sub_57A730 | Final cleanup/dispatch with COM interface |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3E14 | > | 0 | Entity count check |
| this | 0x3FC4 | != | 3 | Session phase check |

**Guard interpretation:**
- Ring buffer entry has flag 0x10000000 set → skip entry.
- ReferencesGlobalState(this) true → call sub_465300 with ring buffer data.
- ReferencesGlobalState(this) false → per-entity loop:
  - Skip if entity index == self ID (v14).
  - Skip if this[0x3FC4] == 3 AND flag bit test fails (FlagBitTest(v3, 1) == 0).
  - Skip if 0x8000000 flag not set AND TwoStageCheck() false.
  - On pass: get node ID from this+0x3C74 array, optionally modify command byte, call TextureCreationWrapper.
- After ring buffer loop, if ReferencesGlobalState(this):
  - Per-entity final pass: skip if self ID; skip if phase != 3 AND flag test fails.
  - If TwoStageCheck() passes: get entity index, call EntityVisibilityGridManager, pop entries and create textures.
- Final return: sub_57A730(this[0x3FB8/4], 0).
