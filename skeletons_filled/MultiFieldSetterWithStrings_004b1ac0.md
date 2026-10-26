## MultiFieldSetterWithStrings_004b1ac0 — Multi-field setter with optional string copy

**Summary:** Called from PlayerOptionsInitializer. Copies string from a2, sets three integer fields at +0x14/+0x18/+0x1C, conditionally copies string from a6, and conditionally reassigns field +0x14. Ends with ShortComputation_1b70 to finalize.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerOptionsInitializer (004aa270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Integer field set from a3 |
| this | 0x18 | RW | — | Integer field set from a4 |
| this | 0x1C | RW | — | Integer field set from a5 |
| this | 0x20 | RW | — | unknown |

**Written-by note (persistence):**
- this 0x14: written unconditionally from a3, optionally reassigned from a3 if a7 set; survives external poke unless overwritten
- this 0x18: written unconditionally from a4; survives external poke
- this 0x1C: written unconditionally from a5; survives external poke
- this 0x20: unknown — externally poked value survives unless overwritten elsewhere

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1b70 | ShortComputation_1b70 | Finalize/compute on struct after field assignment |
| 00566650 | StringCopyWithBufferRealloc | Copy string with buffer reallocation |

**Guard conditions:** a6 (non-zero) -> copy string at a6 via StringCopyWithBufferRealloc. a7 (non-zero) -> reassign this[5] (offset 0x14) = a3. If both conditions false, skip those operations.
