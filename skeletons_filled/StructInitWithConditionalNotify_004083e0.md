## StructInitWithConditionalNotify_004083e0 — StructResetWithConditionalNotify

**Summary:** Resets struct fields to defaults (zero, except offset 0x08 = 1.0f). If the byte flag at offset 0x15 was non-zero before reset, calls ConditionalBranchByFlag(1) as a deactivation notification. State-change callback pattern.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DelegationWrapperToFUN00408280 (00408210), StateInitWithGlobalConstants (00408290), CamMan_Post (0040cce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | first DWORD of struct, reset to 0 |
| this | 0x4 | RW | 0 | second DWORD, reset to 0 |
| this | 0x8 | RW | 1065353216 → 1.0f | third DWORD (float), reset to 1.0f |
| this | 0xC | RW | 0 | fourth DWORD, reset to 0 |
| this | 0x10 | RW | 0 | fifth DWORD, reset to 0 |
| this | 0x14 | RW | 0 | byte at offset 20, reset to 0 |
| this | 0x15 | RW | 0 | byte flag guarding conditional notification; read BEFORE reset |

**Written-by note (persistence):**
- this 0x0–0x14: overwritten every call; external pokes don't survive
- this 0x15: cleared to 0 every call; the old value determines whether notification fires

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d8860 | ConditionalBranchByFlag | called when struct was active before reset (flag at 0x15 was non-zero); parameter 1 signals deactivation |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15 | == | 0 | byte flag checked BEFORE reset; indicates previous active state |

**Guard interpretation:** If byte at offset 0x15 equals 0 (struct was already inactive), the conditional notification is SKIPPED — struct is simply reinitialized silently. If byte is non-zero (struct was active), ConditionalBranchByFlag(1) fires before the flag is cleared to 0.
