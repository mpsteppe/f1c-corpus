## NetworkFilterSort_00462160 — ServerListSortAndFilter

**Summary:** Sets the sort order for server browser from input parameter (clamped to valid range), updates display sort type, and triggers refresh.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_475150 (00475150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC4 | RW | — | Server list refresh-needed flag (set when sort changes or a4 is set) |
| obj | 0x1B79C | R | — | Network system pointer (must be non-null to proceed) |
| this | 0x0 | R | — | This pointer dereference |

**Written-by note (persistence):**
- obj 0xC4: written conditionally; persists until consumed by refresh

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5c14 | aNumplayers | R | "numplayers" sort key string |
| 005c5c20 | aMapname | R | "mapname" sort key string |
| 005c5c34 | aHostname | R | "hostname" sort key string |
| 005c61ec | aPing | R | "ping" sort key string |
| 007cd2a0 | byte_7CD2A0 | W | Track/scene refresh flag (set to 1 when refresh needed) |
| 007d1020 | dword_7D1020 | RW | Current sort mode (1=ping, 2=mapname, 3=numplayers, else=hostname) |
| 007d1028 | dword_7D1028 | R | Sort range minimum bound |
| 007d102c | dword_7D102C | R | Sort range maximum bound |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461fc0 | VehicleStateQueryAtLargeOffset | Query vehicle/connection state (triggers refresh when non-zero) |
| 00563ec0 | SwitchParamStoreGlobalSet | Set global sort parameter for server list UI |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0xC4 | == | 0 | Refresh-needed flag — refresh triggered when non-zero |

**Guard interpretation:** Entire body blocked when network system pointer (this+0x1B79C) is null. Refresh flag (obj+0xC4) set when a3 is true AND sort value changed, OR when VehicleStateQueryAtLargeOffset returns non-zero (and a4 is set).
