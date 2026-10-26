## ConditionalDestructor_46f0_004646f0 — Conditional object destructor

**Summary:** Frees embedded pointer at +0x0 if flag at +0x8 is nonzero, then optionally frees self if a2 bit 0 is set. Destructor-like pattern.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_45D730 (0045d730), CollisionObjectListManagement (004b4b50), DestroyUIWidgetHierarchy (004b5a30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Embedded pointer to free if flag set |
| this | 0x8 | R | — | Flag controlling whether to free embedded pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper |

**Guard conditions:** Checks byte at this+8. If nonzero, frees embedded pointer at this+0 (PASSES). If zero, skips first free. Checks a2 & 1 — if set, frees self (PASSES). If not set, skips self-free.
