## sub_6A4CFF_006a4cff — RebuildScaledTargetObjects

**Summary:** Validates the current object this[64] and its paired element halves (owner this[34], types 0x20500000/0x20400000, scale taken from element+32), dedupes the target objects referenced by element+72, checks the scale factor against the feature mask this[27] (2/4/8/0.5/0.25/0.125 with bits 0x400..0x8000) and adds a sign flag, then rebuilds any target object in this[6] whose element count differs and applies the scale flags to matching elements. Returns 1 on any validation failure, -2147024882 on allocation failure, 0 on success.

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | this[2]: count of this[5] entries scanned when propagating flags to entries sharing the parent link +56 |
| this | 0x10 | R | — | this[4]: table of the interlocked indirection whose control byte bit 0 validates the paired owner |
| this | 0x14 | R | — | this[5]: entry pointer array (owners +4, lists +8, link +56, flags +60/+61, target +72) |
| this | 0x18 | R | — | this[6]: target object array indexed by the deduplicated ids in v49[4..] |
| this | 0x6C | R | — | this[27]: feature bitmask (0x400..0x8000) gating which scale factors are allowed |
| this | 0x88 | R | — | this[34]: expected owner value for the paired elements |
| this | 0xFC | R | — | this[63]: expected index compared against target object fields +84/+88 |
| this | 0x100 | RW | 0 | this[64]: current object being validated and rebuilt; its first dword is cleared to 0 on success |
| this | 0x108 | R | — | descriptor+8 (via this[64]): element id list; first half v5 and second half at v5+count |
| this | 0x10C | R | — | unknown — not visibly referenced in this decompiled body |
| this | 0x110 | R | — | descriptor+16 (via this[64]): element id list used when matching and rebuilding targets |
| this | 0x144 | R | — | unknown — not visibly referenced in this decompiled body |

**Written-by note (persistence):**
- this 0x100: the current-object pointer is unchanged during the call; the pointed object's first dword is cleared to 0 only on the success path at LABEL_98. An external poke survives until the routine next completes successfully (failure returns 1 before the clear).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16e0 | dbl_6F16E0 | R | double constant used in the fabs(v53) scale-switch chain (2.0/4.0/8.0/0.5/0.25/0.125) |
| 006f2358 | dbl_6F2358 | R | double constant used in the fabs(v53) scale-switch chain |
| 006f2370 | dbl_6F2370 | R | double constant used in the fabs(v53) scale-switch chain |
| 006f2378 | dbl_6F2378 | R | double constant used in the fabs(v53) scale-switch chain |
| 006f2dac | flt_6F2DAC | R | float constant used in the scale comparisons |
| 006f37a0 | dbl_6F37A0 | R | double constant used in the scale comparisons |
| 00720770 | dbl_720770 | R | double constant used in the ±1.0 scale-sign decision |
| 00731ce8 | String2 | R | unknown — not visibly referenced in this decompiled body |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0066238f | sub_66238F | releases the replaced target object after the copy and the new object on failure |
| 00680cec | ZeroInit16ElementArray [structural] | zero-initializes the 16 dwords of the rebuilt object |
| 00680d22 | sub_680D22 | attaches the old target object to the new one; negative releases and returns |
| 00681186 | sub_681186 | allocates the 116-byte rebuilt object (null → -2147024882) |
| 006811d1 | sub_6811D1 | initializes the rebuilt object with the old type (*v33) and new count v32; negative releases and returns |

**Guard conditions:** BLOCK (return 1): owner/type combination is not (element owner == this[34] with control-byte bit 0 and type 0x20500000) nor (both owners == this[34] with type 0x20400000); entry+60 of the first element != entry+60 of the paired element, or (entry+60 & 0x80000) with a value other than 0x80000; the list halves differ when v58 is expected (mismatch → return 1); per-element v14+84/+88 != this[63] or (v14+60 & 0x1FFE00) != 0; non-v58 path where scale != entry+32; target objects with type nibble 0x60000000 or 0x72000000; target element count mismatch (v54 != v28); element byte+61 bit 2 with negative scale. Scale must match 2.0/4.0/8.0/0.5/0.25/0.125 with the corresponding this[27] bit (0x400/0x800/0x1000/0x2000/0x4000/0x8000) else return 1. PASS: all targets processed → first dword of this[64] cleared and return 0.
