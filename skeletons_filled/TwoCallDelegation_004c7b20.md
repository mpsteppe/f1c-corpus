## TwoCallDelegation_004c7b20 — Vehicle name enumeration then nationality loader

**Summary:** Delegates to VehicleNameEnumeration with the config path, then loads nationality/career driver info using the enumerated vehicle index. Two-step setup: enumerate available vehicle names, then populate driver data from the first match.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50), LoadVehicleEntries (004b70b0), ProcessDriverEntries (004b8da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ac38c | dword_8AC38C | R | CurrentFontHandle [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c3fe0 | VehicleNameEnumeration | enumerate vehicle names from config path |
| 004c78f0 | NationalityDriverInfoLoader | load nationality/career driver info using enumerated index |

**Guard conditions:** none — both calls always execute
