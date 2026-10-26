## ShortComputation_5730_00415730 — DriverLookupAndFlagSetter

**Summary:** Resets list flags, looks up a vehicle by name, resolves current vehicle from global buffer, finds or creates a format list entry for the vehicle's name, and sets the active flag (byte at offset 0xC) to 1 on the matching list node.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerFileInit (004b0540), TextFileReader (004b09a0), sub_4C1050 (004c1050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] — passed to CurrentVehicleAccessor |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00415230 | NamedEntryLookupInFormatList | Finds or creates format list entry for the vehicle name string |
| 00415650 | LinkedListIndexedAccessor | Gets the list node at the index returned by NamedEntryLookupInFormatList |
| 00415700 | sub_415700 | Resets active flags in the format list |
| 004c3f80 | VehicleLookupByName | Looks up vehicle by name string |
| 004c4080 | CurrentVehicleAccessor | Gets current vehicle data from global buffer |

**Guard conditions:** If CurrentVehicleAccessor returns null (no current vehicle), function skips flag setting and returns null. PASSES: vehicle found and list entry exists — sets flag byte at result+0xC to 1. BLOCKED: no current vehicle or no matching list entry.
