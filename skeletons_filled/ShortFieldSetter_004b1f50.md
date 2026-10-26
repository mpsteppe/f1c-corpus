## ShortFieldSetter_004b1f50 — Short-field setter with optional string copy

**Summary:** Called from PlayerOptionsInitializer. Copies string from a2, sets three short fields at +0x16/+0x18/+0x1A, optionally copies string from a6, and conditionally copies a3 to +0x14. Ends with ShortComputation_1b70.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerOptionsInitializer (004aa270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | Short field set conditionally from a3 if a7 non-zero |
| this | 0x16 | RW | — | Short field set from a3 |
| this | 0x18 | RW | — | Short field set from a4 |
| this | 0x1A | RW | — | Short field set from a5 |

**Written-by note (persistence):**
- this 0x14: written only if a7 non-zero; otherwise survives external poke
- this 0x16: written unconditionally from a3; survives external poke unless overwritten
- this 0x18: written unconditionally from a4; survives external poke unless overwritten
- this 0x1A: written unconditionally from a5; survives external poke unless overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1b70 | ShortComputation_1b70 | Finalize/compute on struct after field assignment |
| 00566650 | StringCopyWithBufferRealloc | Copy string with buffer reallocation |

**Guard conditions:** a6 (non-zero) -> copy string at a6 via StringCopyWithBufferRealloc. a7 (non-zero) -> set this+0x14 = a3. If both conditions false, skip those operations.
