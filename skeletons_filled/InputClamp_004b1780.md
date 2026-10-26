## InputClamp_004b1780 — InputValueClamp

**Summary:** Clamps an input value (at this+0x2988) to the range [-1, 1]. If StateCheckWrapper fails (game not in correct state), returns the raw value unclamped.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A1830 (004a1830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2988 | R | — | input value to clamp (this[2658]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461dc0 | StateCheckWrapper | checks game state; if fails, input is returned unclamped |

**Guard conditions:** Three guards:
1. If StateCheckWrapper(dword_7CD25C) returns 0 (invalid state), return raw value immediately (bypass clamp).
2. If value < -1, return -1.
3. If value <= 1, return value (pass through). If value > 1, return 1.
Blocked: values outside [-1, 1] are clamped to the boundary.
