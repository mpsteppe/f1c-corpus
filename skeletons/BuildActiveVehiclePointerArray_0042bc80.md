## BuildActiveVehiclePointerArray_0042bc80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Init (0042c1a0), NetCommPlayerSlotSync (0045fc50), AutoJoinRetryLoop (004637a0), MultiplayerSessionJoinHandler (0046de10), PlayerFileInit (004b0540), LoadVehicleEntries (004b70b0), ProcessDriverEntries (004b8da0), AIDriverCountSetup (004bfd90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 007c54d8 | byte_7C54D8 | R | VehicleArrayEnd [DERIVED] |
| 007c54dc | dword_7C54DC | W | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54e4 | dword_7C54E4 | W | CurrentVehicleIndex [DERIVED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c54f0 | dword_7C54F0 | RW | VehiclePtrArray [FACT] |
| 007c5690 | byte_7C5690 | R | InitStateFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
