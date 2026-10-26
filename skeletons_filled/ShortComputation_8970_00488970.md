## ShortComputation_8970_00488970 — ScrollPositionClamp

**Summary:** Clamps stored offset at 0xE0 into valid range [0, max-min]. If offset is negative, resets to 0. Otherwise ensures offset + current position does not exceed content extent. Returns result of virtual method at +168.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DeltaBasedUpdate (00488900), ScrollProgressHandler (0048d4b0), InputDispatch (0048d590)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | Virtual +24 — current position value |
| obj | 0x20 | R | — | Virtual +32 — max extent value |
| obj | 0xA8 | R | — | Virtual +168 — some computed state |
| this | 0x0 | R | — | Vtable pointer for virtual dispatch |
| this | 0xE0 | RW | 0 | Stored scroll offset being clamped |

**Written-by note (persistence):**
- this 0xE0: Written conditionally (if negative reset to 0; if overflow, clamped to max - position). Survives between calls.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE0 | >= | 0 | Scroll offset sign check |

**Guard interpretation:** When offset at 0xE0 >= 0, proceeds with clamping against extent; when negative, resets to 0.
