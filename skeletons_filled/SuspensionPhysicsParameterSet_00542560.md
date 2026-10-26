## SuspensionPhysicsParameterSet_00542560 — Store parameter and trigger viewport setup

**Summary:** Stores a2 at offset 0x19C (if non-zero), then calls sub_542200 (viewport setup) with viewport dimensions from offsets 0x54, 0x58, 0x64, 0x68 and flag 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_409890 (00409890), sub_548AD0 (00548ad0), sub_560FE0 (00560fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x54 | R | — | viewport width (passed to sub_542200) |
| this | 0x58 | R | — | viewport height (passed to sub_542200) |
| this | 0x64 | R | — | height component (passed to sub_542200) |
| this | 0x68 | R | — | width component (passed to sub_542200) |
| this | 0x19C | RW | — | stored parameter/pointer a2 |

**Written-by note (persistence):**
- this 0x19C: written with a2 each call (if a2 non-zero).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00542200 | sub_542200 | viewport dimension setup with flag 1 |

**Guard conditions:** a2 must be non‑zero. If zero, function returns 0 immediately — no parameter stored, no viewport setup.
