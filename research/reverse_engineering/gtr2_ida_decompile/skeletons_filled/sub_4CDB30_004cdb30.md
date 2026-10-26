## sub_4CDB30_004cdb30 — flag poll and state-toggle reconciliation

**Summary:** `__thiscall` reconciliation routine: fetches a flag object through virtual slot +0xA4; if absent it sets via virtual +0x24(this, 1) and returns that result. Otherwise it signals virtual +0x24(this, 0), reads the raw flag *v2, derives the desired boolean (direct or inverted depending on the byte at this+0x114), computes the current boolean from the state this[0x84] (true iff state is 1 or 3), and — when the two disagree — invokes the sub_4CD740 toggle dispatcher with the desired value; otherwise returns the current state boolean.

**Called by:** sub_4D02E0 (004d02e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x24 | R | — | Vtable slot +0x24; setter invoked with 1 when the flag object is absent, with 0 when it is present |
| obj | 0xA4 | R | — | Vtable slot +0xA4; getter returning a pointer to the raw flag dword (null when unavailable) |
| this | 0x0 | R | — | Vtable pointer used to resolve slots +0x24 and +0xA4 |
| this | 0x84 | R | — | State index (this[33]); current boolean is true only for states 1 and 3 |
| this | 0x114 | R | — | Polarity selector byte (this[276] byte): non-zero inverts the raw flag (desired = flag==0), zero takes it directly (desired = flag!=0) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd740 | sub_4CD740 | State-toggle dispatcher; invoked with the desired boolean when it differs from the current state boolean |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x84 | == | 1 | State index; one of the two states counted as "current boolean true" |
| this | 0x84 | == | 3 | State index; the other state counted as "current boolean true" |

**Guard interpretation:** If the +0xA4 getter returns null → early path: virtual +0x24(this, 1), no comparison, dispatcher never called. Otherwise: desired boolean = raw flag (if this[0x114] == 0: flag != 0) or inverted (if this[0x114] != 0: flag == 0). Current boolean = (state == 1 || state == 3). Toggle dispatcher sub_4CD740 is called ONLY when desired != current; on agreement the current boolean is returned unchanged (transition blocked).
