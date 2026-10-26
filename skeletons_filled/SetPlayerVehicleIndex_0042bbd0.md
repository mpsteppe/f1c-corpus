## SetPlayerVehicleIndex_0042bbd0 — SetPlayerVehicleByIndex

**Summary:** Sets current player vehicle pointer from index a1, searches VehiclePtrArray for matching vehicle, stores found array index as CurrentPlayerIndex.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameStateDispatchChain (0040d240), sub_40DE60 (0040de60), DynMan_Init (0042c1a0), NetCommPlayerSlotSync (0045fc50), sub_4B9890 (004b9890), sub_4BA1F0 (004ba1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 007c54dc | dword_7C54DC | W | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | W | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** VehiclePtrArray[result] does not equal computed vehicle pointer (unk_5EC6D8 + 18624*a1): continue searching. result >= 104 (array exhausted without match): return 104 (not found). Match found: store index in dword_7C54DC, return index.
