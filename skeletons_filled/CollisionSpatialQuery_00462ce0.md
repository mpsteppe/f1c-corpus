## CollisionSpatialQuery_00462ce0 — Collision/Spatial Query via VTable Dispatch

**Summary:** Dispatches a network collision check via vtable call at offset 0x6c. On success (returns 0), sets state byte to 1, timeout float to 5.0, and state enum to 4. Returns 1 on success, 0 if vtable call failed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SendJoinRequest (00462c00), AutoJoinRetryLoop (004637a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x10 | RW | 5.0 (float) | timeout/retry interval set after successful query |
| obj | 0x29 | RW | 1 | state flag: set to 1 (active/querying) on success |
| obj | 0x3FB8 | R | — | sub-object pointer for vtable dispatch |
| obj | 0x3FC4 | RW | 4 | query state enum: set to 4 on success |
| this | 0x0 | R | — | vtable/primary pointer |

**Written-by note (persistence):**
- obj 0x10: written once per call (5.0); survives until next write
- obj 0x29: written once per call (1); survives until next write
- obj 0x3FC4: written once per call (4); survives until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f0a0 | flt_59F0A0 | R | MulticastTimeout [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a580 | VTableCallViaOffset0x6c | calls vtable method at offset 0x6c on sub-object (+0x3FB8) with query params |

**Guard conditions:** VTableCallViaOffset0x6c returns non-zero (query failed/rejected): BLOCKED, return 0 immediately. PASSES only when vtable call returns 0 (success), then writes state fields.
