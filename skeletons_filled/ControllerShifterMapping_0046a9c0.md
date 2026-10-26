## ControllerShifterMapping_0046a9c0 — ControllerShifterActionMapping

**Summary:** Maps controller shifter/gear action to global action arrays. Clears old mapping via IDPairMatchAndClear, writes action ID pair at computed index (28 * this[125]) into dword_7D1B08/dword_7D1B0C. If first ID is 1, switches on action value (this[129]) to find paired gear action and sets force feedback value (0.5f) in ContactForceStateArray.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** KeyBindingUIPressKeyOrController (0046b0c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1F4 | R | — | index/offset into global action arrays (multiplied by 28) |
| this | 0x200 | R | — | first action ID of the shifter pair |
| this | 0x204 | R | — | action value/gear number used in shifter pairing switch |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0046ac58 | jpt_46AA0C | R | jump table for shifter action type switch |
| 0046acdc | byte_46ACDC | R | lookup data for switch cases |
| 007d1490 | dword_7D1490 | W | ContactForceStateArray [DERIVED] — force feedback values |
| 007d1b08 | dword_7D1B08 | W | ActionTypeArray [DERIVED] — action type array |
| 007d1b0c | dword_7D1B0C | RW | ActionValueArray [DERIVED] — action value array |
| 007d1fdc | dword_7D1FDC | R | end bound for action array scan loop |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0046a980 | IDPairMatchAndClear | clears old action ID pair mapping before writing new one |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x200 | == | 1 | first action ID — 1 means gear/shifter action |

**Guard interpretation:** PASSES if this[128] (first action ID) == 1 → enters shifter pairing switch and force feedback update. BLOCKED if != 1 → skips pairing/feedback, just writes action IDs.
