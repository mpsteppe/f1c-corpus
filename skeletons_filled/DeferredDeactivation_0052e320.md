## DeferredDeactivation_0052e320 — DeferredDeactivationWithStubs

**Summary:** Conditionally clears the deferred deactivation flag and sync word, then calls two stub functions. Used to handle pending deactivation requests during MPEG decoder re-initialization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CMpegBase_Open (0052e090), CMpegFilePlayer_Open (0052e1d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24EC | RW | 0 | deferred deactivation flag (cleared to 0) |
| this | 0x24F0 | RW | 0 | sync word (cleared to 0) |

**Written-by note (persistence):**
- this 0x24EC: conditionally written to 0 if was set; external poke overwritten by deactivation
- this 0x24F0: conditionally written to 0; external poke overwritten by deactivation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047abb0 | Return0Stub | stub function that always returns 0 |
| 004b0170 | EmptyStub_0170 | empty/no-op stub function |

**Guard conditions:** only executes clear + stubs if byte at 0x24EC (deferred deactivation flag) is non-zero; otherwise returns 0 immediately (no-op)
