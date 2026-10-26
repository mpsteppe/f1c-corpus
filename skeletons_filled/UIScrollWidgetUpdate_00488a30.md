## UIScrollWidgetUpdate_00488a30 — UIScrollWidgetUpdate

**Summary:** Main update for a scroll widget. If flag at 0xEC is set, reads position bounds via DualFieldRead, checks if delta falls within range, sets active flag (0xED), runs DeltaBasedUpdate, then conditionally notifies and runs sub_486600 if widget is not hidden.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | Virtual +24 — current position |
| obj | 0x1C | R | — | Virtual +28 — scroll boundary low |
| obj | 0x24 | R | — | Virtual +36 — scroll boundary high |
| obj | 0x2C | R | — | DualFieldRead output — delta range data |
| obj | 0x98 | R | — | Virtual +152 — visibility/hidden test |
| this | 0x0 | R | — | Vtable pointer for virtual dispatch |
| this | 0xEC | R | — | Enable flag controlling update execution |
| this | 0xED | RW | 1 | Active/in-range flag (set to 1 when delta is within bounds) |

**Written-by note (persistence):**
- this 0xED: Written conditionally (set to 1 when delta in bounds). Survives between calls.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486600 | sub_486600 | Additional widget update/notification |
| 00488900 | DeltaBasedUpdate | Process scroll delta changes |
| 00498880 | DualFieldRead | Read input delta pair |

**Guard conditions:** Checks byte at 0xEC; if zero (false), skips entire update body and returns 0.
