## sub_4AC1A0_004ac1a0 — BuildEntryTextAndNotify

**Summary:** Clears a 61-byte local buffer, builds a label either via sub_4331B0(&byte_B64150, name at this+0x350) when the selector this+0x358 equals 4 or via sub_433050(selector, this+0x354) otherwise, sprintf's the string at this+0x34C+30 into the buffer, runs sub_499010, and finally invokes the virtual slot +0x24 (0x24) with status argument 0 or 1 depending on whether the this+0x34C object's field +16 is non-zero. Returns 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x34C) | 0x10 | R | — | Field deciding the status argument (0 vs 1) passed to the virtual slot +0x24. |
| obj | 0x24 | R | — | Vtable slot (index 9) invoked with (this, status, Buffer). |
| this | 0x0 | R | — | Vtable pointer of the object. |
| this | 0x34C | R | — | Pointer to the source object/string block; +30 bytes is the string passed to sprintf. |
| this | 0x350 | R | — | Name/string pointer passed to sub_4331B0 when the selector is 4. |
| this | 0x354 | R | — | Value passed as second argument to sub_433050 in the default path. |
| this | 0x358 | R | — | Selector: == 4 chooses the sub_4331B0 path, anything else uses sub_433050. |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f2a98 | aS_2 | R | sprintf format "%s" used to copy the source string into Buffer. |
| 00b64150 | byte_B64150 | R | Global state/base passed to sub_4331B0 along with the name string. |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00433050 | sub_433050 | Default-path builder receiving (selector, this+0x354). |
| 004331b0 | sub_4331B0 | Selector==4 path builder receiving (&byte_B64150, name pointer). |
| 00499010 | sub_499010 | Additional action invoked after the sprintf (arguments via registers). |
| 00631761 | _sprintf | Formats "%s" from this+0x34C+30 into the local Buffer. |

**Guard conditions:** Path selection: this[214] (this+0x358) == 4 → sub_4331B0 path; otherwise sub_433050 runs. The final virtual slot +0x24 receives status 0 when *(DWORD*)(this+0x34C + 16) is non-zero and 1 when that field is zero. No early returns — the sprintf, sub_499010 and the virtual call always execute.
