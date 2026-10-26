## UIElementBitfieldStateSetter_0054bdc0 — Set/clear UI element bitfield states with color processing

**Summary:** Walks UI element linked list (head at this+0x204, next at node+0x10). For each element, applies bitfield mask: sets bits from a2, clears bits from ~a3 on each state entry (array at node+0x11C, count at node+0x118). When bit 5 (0x20) is set in a2, processes color/texture data: encodes color from global counter (dword_8B8F28+0x1B0), updates sub-element color bytes, and increments counter. When bit 5 is cleared in a3, dispatches to state change callbacks based on low 2 bits (sub_55DA50, sub_55E320, sub_55D900). Part of UI scene node update system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FBA10 (004fba10), RecursiveTraversal (0054bcd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | Head of UI element linked list |
| this | 0x224 | R | — | Accessed by callees during state processing |
| this | 0x228 | R | — | Accessed by callees during state processing |
| this | 0x32C | R | — | State entry count guard; must be > 0 for processing |
| this | 0x330 | RW | — | Color/texture allocation counter incremented per element |
| this | 0x338 | R | — | Sub-element count guard; must be > 0 for color update |
| this | 0x350 | R | — | Accessed by callees during state processing |

**Written-by note (persistence):**
- this 0x330: incremented once per state entry when bit 5 is set; cumulative counter across calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f28 | dword_8B8F28 | R | UIRootContextPtr [DERIVED] — UI root context; offset +432 used as color/texture allocation counter |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054e0e0 | SingleCallWrapper_e0e0 | Single-element state processing for color update |
| 0054e0f0 | Wrapper_e0f0 | Reapply state after color update |
| 0055d900 | sub_55D900 | State change handler (low bits clear) |
| 0055da50 | sub_55DA50 | State change handler (bit 0 set) |
| 0055e320 | sub_55E320 | State change handler (bit 1 set) |
| 0055eb30 | sub_55EB30 | Additional state change handler for flagged elements |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32C | > | 0 | State entry count; must be positive to process element state |
| this | 0x338 | > | 0 | Sub-element count; must be positive for color data update loop |

**Guard interpretation:** List walk BLOCKED if `this[0x204]` (head) is null. Per-element: BLOCKED if state entry count ≤ 0. Per-entry color update BLOCKED if sub-element count (v5[2]) ≤ 0. If `a2 & 0x20` is set → color encode path. Else if `a3 & 0x20` is set → state change dispatch path based on low 2 bits of updated value.
