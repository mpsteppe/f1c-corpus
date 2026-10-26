## sub_54EDF0_0054edf0 — Sentinel check: global float differs from FLT_MAX

**Summary:** No-argument predicate returning true when the DWORD global dword_757C20 reinterpreted as float is different from 3.4028235e38 (FLT_MAX). Used to test whether that global still holds the "unset" sentinel value.

**Called by:** sub_550650 (00550650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f39c0 | flt_6F39C0 | R | Read-flagged by IDB; not visibly consumed in the decompiled body — purpose unknown |
| 00757c20 | dword_757C20 | R | Compared as float against the FLT_MAX sentinel (3.4028235e38) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Single comparison, no branching: returns TRUE (1) when `*(float*)&dword_757C20 != FLT_MAX`, FALSE (0) when it equals the sentinel. Nothing is skipped or blocked.
