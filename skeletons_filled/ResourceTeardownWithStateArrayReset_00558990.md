## ResourceTeardownWithStateArrayReset_00558990 — RenderResourceTeardown

**Summary:** Teardown render resources: free audio sub-resources (virtual release + drain + free), clear flag bit 8, then reset state struct array (clear bit 6 and two fields per element), zero counters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureFlagTestWithDispatch (00557630)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | Flags bitmask; bit 8 cleared when audio resources freed |
| this | 0x2C | R | — | Element count for state struct array at 0x34 |
| this | 0x30 | RW | 0 | Counter/index, zeroed after array iteration |
| this | 0x34 | RW | — | Pointer to array of state structs (stride 128 bytes) |
| this | 0x38 | RW | 0 | Counter/index, zeroed after reset |
| this | 0x50 | R | — | Pointer to audio sub-context (fields at +28 = audio object, +36 = drain object) |
| this | 0x6C | RW | 0 | unknown (written via sub-struct indirection) |
| this | 0x74 | RW | 0 | unknown (written via sub-struct indirection) |
| this | 0xAC | RW | 0 | unknown (written via array element at v4[30]) |
| this | 0xB0 | RW | 0 | unknown (written via array element at v4[31]) |

**Written-by note (persistence):**
- this 0x20: Bit 8 cleared conditionally (only if audio resources existed); external bits survive
- this 0x30: Written unconditionally to 0 once
- this 0x34: Not written by this function
- this 0x38: Written unconditionally to 0 once
- this 0x6C: Written conditionally per array element; external pokes between resets survive
- this 0x74: Written conditionally per array element; external pokes between resets survive
- this 0xAC: Written unconditionally per array element to 0
- this 0xB0: Written unconditionally per array element to 0

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00540eb0 | ObjectResetWithVirtualRelease | Release audio object via virtual function |
| 00541040 | DrainingLoopFinalizer | Drain/finalize audio processing pipeline |
| 00587bcf | FreeWrapper_7bcf | Heap memory free wrapper |

**Guard conditions:**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x50) | 0x1C | != | 0 | Audio resource pointer within sub-context |

**Guard interpretation:** Guard checks if audio resource pointer (at +28 in sub-context) is non-null; PASS if non-null (teardown audio + free + clear flag), BLOCKED if null (skip audio teardown).
