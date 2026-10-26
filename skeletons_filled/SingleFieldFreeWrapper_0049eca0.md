## SingleFieldFreeWrapper_0049eca0 — Single field resource cleanup (this[1])

**Summary:** Releases resource handle at this[1] (offset 0x4) via ResourceCascadeCleanup and clears to 0. Same pattern as ShortComputation_ec40 but operates on offset 0x4 instead of 0x0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiStageCleanupWithRepeatedCallCycle (0049d150), FloatComputation_eb40 (0049eb40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | resource handle at this[1] (cleared after cleanup) |

**Written-by note (persistence):**
- this 0x4: set to 0 after cleanup. If external poke writes here, value is lost on next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005539f0 | ResourceCascadeCleanup | cascade cleanup/release of resource handle |

**Guard conditions:** Checks `this[1]` (offset 0x4) non-null — skips cleanup if already null.
