## SceneNamePointer_004c0a80 — Scene name pointer accessor

**Summary:** Returns a pointer to the current vehicle's scene name string (offset +124) by looking up the vehicle name stored in the object. Returns 0 if vehicle not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConfigSectionSearchByKeyValue (0041fe00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | vehicle name string for lookup |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path (fallback for null vehicle name) |
| 008ac388 | unk_8AC388 | R | vehicle file path buffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c3f80 | VehicleLookupByName | resolve vehicle name to vehicle data pointer |
| 004c4080 | CurrentVehicleAccessor | get current vehicle entry from lookup cache |

**Guard conditions:** Returns 0 if CurrentVehicleAccessor returns NULL (vehicle not found after lookup). Falls back to default path if this[2] (vehicle name) is null.
