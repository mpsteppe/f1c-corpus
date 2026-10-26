## CollisionObjectDestructor_0044fbe0 — Release and destroy Direct3D device

**Summary:** Releases the Direct3D device object: calls its stop/unacquire method (vtable+32), then Release (vtable+8), zeroes the device pointer at 0x80, and resets version field at 0x2F4. Called during setup, post-frame, and exit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HWInput_Setup (00455c60), HWInput_Post (00455e70), HWInput_Exit (00455f00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x80) | 0x8 | R | — | Device vtable offset 8 (method 2) — Release (decrement refcount) |
| *(this+0x80) | 0x20 | R | — | Device vtable offset 0x20 (method 8) — Unacquire/stop method |
| this | 0x80 | RW | 0 | Direct3D device pointer (cleared to null) |
| this | 0x2F4 | RW | 0 | Capability version/count (reset to 0) |

**Written-by note (persistence):**
- this 0x80: cleared to null unconditionally if device existed; external set survives
- this 0x2F4: reset to 0 unconditionally; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** BLOCKED: no early exit test. Device release only runs if device pointer at 0x80 is non-null. If null, only version field is zeroed.
