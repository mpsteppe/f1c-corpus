## UIToggleIncrementDecrementHandler_004713e0 — ToggleIncrementDecrement

**Summary:** Handler for increment/decrement of a UI toggle value. Clamps value to 0/1 range based on direction parameter and updates the display buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x320 | RW | 0 | Pointer to toggle value (0 or 1) stored elsewhere |

**Written-by note (persistence):**
- this 0x320: Init to 0 in constructor; external code pokes toggle value through pointer; this handler reads, adjusts, and writes back

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048b810 | EditBufferStringUpdate | Format buffer and update UI string display |

**Guard conditions:** a2 == 1 → increment (0→1); a2 != 1 → decrement (1→0). Result clamped to [0,1] range. If result is 0 writes 0, if 1 writes 1. No early return — always writes clamped value.
