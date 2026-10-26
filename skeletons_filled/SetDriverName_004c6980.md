## SetDriverName_004c6980 — Set driver full name and derive abbreviation

**Summary:** Copies a driver name string (max 63 chars) into the driver name field at this+17952 (offset 0x4620), null-terminates it, then calls DriverAbbreviationNameFormatter to generate and store the abbreviated name.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50), LoadVehicleEntries (004b70b0), ProcessDriverEntries (004b8da0), VehgenScnFileLoader (004c6c40), NationalityDriverInfoLoader (004c78f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x465F | RW | 0 | null terminator byte for driver full name buffer (63-char limit, written as last byte) |

**Written-by note (persistence):**
- this 0x465F: explicitly set to 0 after string copy; persists as string terminator

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c6a10 | DriverAbbreviationNameFormatter | derive and store abbreviated/short driver name from the full name |
| 00587dd0 | sub_587DD0 | bounded string copy (strncpy-like) |

**Guard conditions:** none — always sets name and derives abbreviation
