## sub_56BCC0_0056bcc0 — Zone hit test, then dispatch sub_417460

**Summary:** With this as the owner, it forms the local delta a3 - (this+0x4C/0x50/0x54) and tests it against every zone object in the array at this+0xF20 (count this+0xF1C, stride 748 bytes) using the proximity predicate sub_56A040. On the first hit it forwards all arguments to sub_417460; if no zone matches it returns the last predicate result (false). Called from sub_51B2F0.

**Called by:** sub_51B2F0 (0051b2f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | reference X subtracted from a3[0] to form the local delta |
| this | 0x50 | R | — | reference Y subtracted from a3[1] |
| this | 0x54 | R | — | reference Z subtracted from a3[2] |
| this | 0xF1C | R | — | zone object count; loop bound and gate (`> 0`) for the scan |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091bf88 | dword_91BF88 | R | referenced global; not textually distinguishable in the decompiled listing — likely a constant/base used by the dispatched code path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00417460 | sub_417460 | final handler: called with (a2, a3, a4, a5, a6, a7) once a zone matches; its return value is passed through |
| 0056a040 | sub_56A040 | proximity predicate on one zone object and the delta vector; nonzero return = hit, which breaks the scan |

**Guard conditions:** The scan runs only when the zone count `*(this+0xF1C) > 0`; with zero zones the function returns immediately (result is the low byte of the computed delta Z, i.e. the untouched leftover value — effectively no-op). In the loop, a nonzero return from sub_56A040 breaks out and passes control to sub_417460(a2, a3, a4, a5, a6, a7). If all zones are exhausted without a hit (`++v8 >= v7`), it returns the last (false) predicate result and sub_417460 is never called.
