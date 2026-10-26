## F_3DDistanceCheckAccumulate_004d0b20 — 3D distance check and accumulate

**Summary:** Iterates a list of objects, computes squared 3D distance from a reference position (obtained via SessionManager virtual dispatch), and accumulates parameter `a2` into objects within 32-unit radius. Calls sub_4A2840 on each updated element.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Count of elements in the list |
| this | 0x4 | R | — | Pointer to array of element structs (132 bytes each) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acee4 | flt_5ACEE4 | R | G6B5ScaleFactor [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c870 | VirtualDispatchHelper | Dispatches virtual call on SessionManager to retrieve reference position/transform pointer |
| 004a2840 | sub_4A2840 | Processes accumulated value at element+0x4 after distance-based update |
| 0054b420 | TripleFieldQuery | Reads three float fields (X, Y, Z coordinates) from an element |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | <= | 0 | Element count |

**Guard interpretation:** If `*this <= 0` (no elements), skip the entire accumulation loop. PASSES (enters loop) when count > 0. BLOCKED (returns early) when count <= 0.
