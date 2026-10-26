## sub_5FCD70_005fcd70 — Set sub-object mode value and 0x2000 flag

**Summary:** Bounded setter: when the 32-bit argument is below 0x10 it stores (float)a2 at offset +100 of the sub-object pointed to by this[0x40] and then sets or clears that sub-object's flag bit 0x2000 depending on whether a2 > 0. Returns the updated flag word (or a2 when the range check fails).

**Called by:** sub_547DC0 (00547dc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | RW | — | Sub-object pointer/flag word reached via this[16]: its flags at +0 are read and rewritten with bit 0x2000 set (a2 > 0) or cleared (a2 <= 0); the float store goes through the same pointer |
| this | 0xA4 | RW | — | Float at *(this[16])+100: receives (float)a2 — the mode/parameter value |

**Written-by note (persistence):**
- this 0x40: only bit 0x2000 is modified (OR-set or AND-cleared) per call; all other flag bits are preserved, so external pokes to them survive. An external poke to 0x2000 itself is overwritten by the next in-range call.
- this 0xA4: unconditionally overwritten with (float)a2 on every in-range call — fully derived from the argument, external pokes do not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Single gate: `(unsigned)a2 < 0x10`. PASS (0..15): the float store happens and flag bit 0x2000 is updated — cleared when `a2 <= 0`, set when `a2 > 0`; the return value is the new flag word. BLOCKED (a2 >= 0x10): nothing is written and a2 is returned unchanged.
