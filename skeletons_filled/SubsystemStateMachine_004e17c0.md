## SubsystemStateMachine_004e17c0 — SubsystemStateMachine

**Summary:** Dispatch function for subsystem slot lifecycle management — routes to lazy init or conditional release based on slot ID and activation intent. Manages 14 slot types (indices 0-13).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0), UIElementIterateUpdate (004e19a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x628 | R | — | Slot pointer for slot index 5 |
| this | 0x668 | R | — | Init flag byte for slot index 5 (slot+64) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004e18a0 | jpt_4E17D6 | R | Jump table for the slot ID switch (cases 0-13) |
| 004e18b0 | byte_4E18B0 | R | Byte data/constants for slot state computation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e0d00 | LazyInitCallback | Lazy-initializes a subsystem slot |
| 004e0d70 | ConditionalResourceRelease | Conditionally releases a subsystem slot |
| 004e0e20 | ArrayEntryCleanup | Cleans up array-backed entries for slots 0-3 |
| 004e0e70 | SubslotCleanup | Cleans up sub-slot data for slots 0-3 |

**Guard conditions:** Switch on a2 (slot ID, 0-13). For cases 0-3: if a3 (activate), checks slot pointer and init flag both non-zero -> calls SubslotCleanup; if !a3, checks either pointer or init flag zero -> calls ArrayEntryCleanup. For cases 4-13: if a3 (activate), checks pointer non-zero AND init flag zero -> LazyInitCallback; if !a3, checks pointer zero OR init flag non-zero -> ConditionalResourceRelease. Default: returns immediately.
