## StructSetupWithTwoCalls_0040e8b0 — LightFrustumClosestPointSetup

**Summary:** Initializes light/shadow structure fields and computes closest point in light frustum via sub-call. Physics rendering system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40FE50 (0040fe50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | type/index discriminator word |
| this | 0x1C | RW | 8 | subtype/kind constant (physics shape type indicator) |
| this | 0x20 | RW | — | pointer to external data passed through to sub-calls |

**Written-by note (persistence):**
- this 0x8: written once unconditionally, external poke survives
- this 0x1C: written once unconditionally, external poke survives
- this 0x20: written once unconditionally, external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e480 | LightFrustumClosestPoint | compute closest point in light frustum from a3, store result floats at this+0x0C and this+0x18 |
| 004be1d0 | NestedLoopRangeTraversal | traverse/validate the structure's range data |

**Guard conditions:** none — no branches in function body
