## FormatRegisterDispatch_0049d440 — Register value text dispatch

**Summary:** Fetches a formatted register/state value via sub_49C6D0 into a 16-byte buffer and renders it to HUD at position (4, 0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SteeringWheelAnimation (0049d070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | display resource context pointer (this[4]) |
| this | 0x64 | R | — | sub-struct pointer (steering input data) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049c6d0 | sub_49C6D0 | formats register/state value string into buffer |
| 00553070 | sub_553070 | renders formatted text to HUD at screen position |

**Guard conditions:** None — always executes both calls unconditionally.
