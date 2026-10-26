## ReplayAIStateCheck_004f1c20 — replay / AI state active check

**Summary:** Reads a pointer to an AI/replay state object and checks if its state flag equals 1. Used by overtaking system to determine if AI or replay is active.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** Overtaking (0042af70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3A9C | R | — | pointer to AI/replay state object |
| this | 0x3BC8 | R | — | state flag at offset 300 from AI/replay object (compared to 1) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3BC8 | == | 1 | AI/replay state flag expected to be 1 when active |

**Guard interpretation:** Pointer at 0x3A9C must be non-null AND value at 0x3BC8 (dereferenced via pointer+300) must equal 1 to pass. NULL pointer or any other value blocks (returns FALSE).
