## sub_4AA7B0_004aa7b0 — DispatchByGlobalFlags

**Summary:** Runs the object update sub_4D2320(this), derives a mode value (2 if byte_B722FC is set, else 1 when dword_B70E64 is non-zero, else 0), passes it to sub_4CFC00, and returns the consumer sub_4CE770 applied to that result.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b70e64 | dword_B70E64 | R | Flag tested for non-zero to select mode 1 (else mode 0). |
| 00b722fc | byte_B722FC | R | Flag that, when non-zero, forces mode 2 (highest priority). |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ce770 | sub_4CE770 | Consumer for the value returned by sub_4CFC00; its result is returned. |
| 004cfc00 | sub_4CFC00 | Called with the computed mode (0/1/2) to produce a state/handle. |
| 004d2320 | sub_4D2320 | Object update processing invoked first with this. |

**Guard conditions:** Mode selection: if byte_B722FC != 0 the mode is 2 regardless of dword_B70E64; otherwise the mode is 1 when dword_B70E64 != 0, and 0 when it is zero. No early exit — sub_4CE770 always runs on the sub_4CFC00 result.
