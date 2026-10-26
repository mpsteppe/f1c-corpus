## InputBindingConfigSetup_0051cb6d — Rendering mode and function table setup

**Summary:** Allocates and initializes a 24-byte rendering function table based on mode parameters (offsets 0x20, 0x24, 0x28). Selects one of several 2D blit/composite functions (SIMD, scalar copy, color lookup) and initializes the table sub-struct. Conditionally clears channel state buffers and sets mode flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | Vtable[0]: memory allocator — allocates 24 bytes for function table sub-struct |
| obj | 0x0 | R | — | Vtable pointer (a1[0]) — used to set error/success state at obj+0x14 |
| obj | 0x14 | RW | 25 | State field at vtable target+0x14 — set to 8 (invalid config) or 25 (valid) |
| this | 0x0 | R | — | First DWORD (vtable pointer) — read for state write dispatch |
| this | 0x4 | R | — | Vtable pointer — allocator dispatch |
| this | 0x20 | R | — | Mode/type parameter — compared against 1, 3, 4 for compatibility check |
| this | 0x24 | R | — | Sub-mode parameter (v2) — compared against ranges 1, ≤3, ≤5 |
| this | 0x28 | R | — | Blit type selector — values 1, 2, 4 determine which function to install |
| this | 0x4A | R | — | Flag byte — controls whether this+0x68 is set to 1 or copied from this+0x64 |
| this | 0x64 | RW | 1 | Channel count/mode selector — set to 1, 3, or 4 based on blit type |
| this | 0x68 | RW | 1 | Active channel mode — set to 1 if flag at 0x4A set, else copied from 0x64 |
| this | 0xC4 | R | — | Base pointer for channel state buffer — used in clear loop with stride 84 |
| this | 0x1A0 | RW | — | Pointer to allocated 24-byte function table sub-struct (v1) |

**Written-by note (persistence):**
- obj 0x14: Set to 8 (error) on invalid mode combo, or to 25 (success) on valid config. State persists until next config or override.
- this 0x64: Set to 1, 3, or 4 based on blit type. Persists between config calls.
- this 0x68: Set based on this+0x4A flag. Survives external pokes.
- this 0x1A0: Allocated and written once during setup. Pointer persists until reallocation.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051c653 | F_2DBlitTextureCopy | R | 2D texture copy function — installed in table when blit type=2 or compatible fallback |
| 0051c6be | F_2DCopyDelegation | R | 2D copy delegation — installed when blit type=1 |
| 0051c6e1 | sub_51C6E1 | R | Color lookup filter — installed when blit type=4 and sub-mode 4 or 5 |
| 0051c94f | sub_51C94F | R | SIMD/scalar color lookup render — installed when blit type=2 and sub-mode 2 or 3 |
| 0051dfca | nullsub_4 | R | Null stub function — installed as v1[0] (default/error handler) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051c5a3 | TableInitWithArithmeticProgression | Initializes color lookup tables — called when sub_51C94F or sub_51C6E1 is selected |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | == | 1 | Mode where type=1 → compatible with sub-mode v2==1 |
| this | 0x20 | == | 3 | Mode where type=3 → compatible with sub-mode v2 in 2-3 |
| this | 0x20 | == | 4 | Mode where type=4 → compatible with sub-mode v2 in 4-5 |
| this | 0x20 | > | 1 | More than 1 channel → trigger channel buffer zeroing loop |
| this | 0x20 | >= | 1 | Minimum check — pass if ≥1, else set error state=8 |
| this | 0x28 | != | 4 | Blit type not 4 → skip 4-specific path |
| this | 0x28 | != | 1 | Blit type not 1 → skip 1-specific path |
| this | 0x28 | == | 2 | Blit type 2 → install sub_51C94F or F_2DBlitTextureCopy |

**Guard interpretation:** Mode validation (lines 15-37): if this+0x24 (v2) is 1, 2-3, or 4-5, check that this+0x20 matches the expected value (1, 3, or 4 respectively). If combo invalid, set obj+0x14=8 and call default handler (set state to error). Blit type dispatch (lines 42-86): select rendering function based on this+0x28 (1, 2, 4, or match). Invalid type combos hit LABEL_17 (error state=25). If this+0x20 > 1 and blit type=1, zero channel state buffers (84-byte stride up to count). Finally (lines 105-113): if byte this+0x4A is non-zero, force this+0x68=1; else copy this+0x64 to this+0x68.
