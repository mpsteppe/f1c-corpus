## sub_4F7EC0_004f7ec0 — dispatch update over sub-record array

**Summary:** Iterates the object's 768-byte sub-records (count this+0x120, base this+0x124) and dispatches each one: when a2 is set every entry gets sub_4F7C90(entry, 1); when a2 is clear, entries satisfying the a3/entry-flag/entity-id test go to sub_4F7DD0(entry, 0), all others to sub_4F7C90(entry, active-state derived from *dword_B640C8); finishes with an optional sub_5DA8C0 post-step and updates flag bits in this+0xC.

**Called by:** sub_4FA6A0 (004fa6a0), sub_4FA940 (004fa940), sub_4FBE60 (004fbe60), sub_4FEFE0 (004fefe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | entity id compared against dword_91E084 (or 0) when selecting the per-entry path |
| this | 0xC | RW | — | flag dword: bit 0x20 set in a2 mode, low two bits cleared on every call |
| this | 0x120 | R | — | sub-record count (loop bound) |
| this | 0x124 | R | — | base pointer of the 768-byte-stride sub-record array |
| this | 0x12C | R | — | non-null triggers the sub_5DA8C0(0,0) post-step after the loop |

**Written-by note (persistence):**
- this 0xC: rewritten on every call — bit 0x20 is set only when a2 is non-zero, and bits 0/1 are always cleared (`&= 0xFFFFFFFC`); pokes to the low bits never survive, other bits are left untouched.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00757c1c | dword_757C1C | R | mode flag: when non-zero the entity-id comparison uses dword_91E084 instead of 0 |
| 0091e084 | dword_91E084 | R | expected entity id used in the a2-clear, a3-set path |
| 00b640c8 | dword_B640C8 | R | pointer to a state dword; value != 6 and != 0 selects active flag 1 for sub_4F7C90, otherwise 0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f7c90 | sub_4F7C90 | per-entry update with a boolean active flag |
| 004f7dd0 | sub_4F7DD0 | per-entry id lookup (id 0), which tail-jumps into the shared 004F59C0 code |
| 005da8c0 | sub_5DA8C0 | post-step executed once when this+0x12C is non-null (args 0, 0) |

**Guard conditions:** For each entry: if `a2 != 0` → sub_4F7C90(entry, 1) unconditionally. If `a2 == 0`, the sub_4F7DD0 path requires all of: `a3 != 0`, entry byte +11 non-zero, and `*this == (dword_757C1C ? dword_91E084 : 0)`; failing any of these selects sub_4F7C90(entry, v8) with v8 = 1 only when `*dword_B640C8 != 6 && *dword_B640C8 != 0`, else 0. The loop itself runs only for the first this[0x120] entries.
