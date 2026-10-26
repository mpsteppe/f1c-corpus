## ArrayDestructorViaVirtualDispatch_004526c0 — Destroy array of COM objects

**Summary:** Releases an array of 10 COM-style objects at stride 104 bytes starting at offset 0x64: calls vtable+44 (stop/release method), then vtable+8 (Release), zeroes the pointer. Also resets a count at offset 0x414. Called during HWInput_Post cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HWInput_Post (00455e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x64)+0x0) | 0x8 | R | — | Object vtable offset 8 (method 2) — Release (decrement refcount) |
| *(*(this+0x64)+0x0) | 0x2C | R | — | Object vtable offset 0x2C (method 11) — stop/uninit method |
| *(this+0x64) | 0x0 | R | — | Object vtable pointer |
| this | 0x64 | RW | 0 | Array of 10 COM object pointers (stride 104 bytes = 26 dwords) |
| this | 0x414 | RW | 0 | Object count/reset field |

**Written-by note (persistence):**
- this 0x64: array entries cleared to null unconditionally if non-null; external poke survives
- this 0x414: reset to 0 unconditionally; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** each entry individually guarded — Release/skip only if entry pointer is non-null
