## __NLG_Notify1_00630fb1 — _NLG_Notify1 (notify tail-stub)

**Summary:** Small SEH/CRT notify stub: tail-jumps into the shared NLG support code at 0x630FC4, passing its argument through registers. Called by __CallSettingFrame as part of the exception-frame machinery.

**Called by:** __CallSettingFrame@12 (00636940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00912870 | unk_912870 | R | Data used by the shared NLG code reached from this stub (accessed at 0x630FC4); exact role not visible in this stub's decompiled body |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — this body is an unconditional jump to the shared routine at 0x630FC4; no values are checked and no path is skipped.
