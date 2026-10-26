## CollisionContactIteration_00460dd0 — CollisionContactAIHandler

**Summary:** Iterates through vehicles to resolve collision contact response. Checks vehicle AI state and penetration ratio, then sets AI control flag and driver visibility based on collision severity.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A3D4 | R | — | Penetration float array per vehicle (value / flt_7D108C = ratio) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] |
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] — vehicle state array base |
| 007c54d8 | byte_7C54D8 | R | VehicleArrayEnd [DERIVED] — end bound for vehicle iteration |
| 007d108c | flt_7D108C | R | MinPenetrationLimit [DERIVED] — divisor for penetration ratio |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045cbf0 | ShortArrayLookupAndZeroCheck | Lookup short value in array and check for zero/contact flag |
| 004c7a70 | VehicleAIControlFlag | Set AI control flag (0 = release, 1 = retain) |
| 004c7aa0 | SetDriverVisibility | Set driver visibility (0 = hide, 1 = show) |

**Guard conditions:**
- Iterates vehicles (step 18624 bytes), starting from unk_5EC6D8 (base), until reaching byte_7C54D8 (end).
- For each vehicle: if state at +0x32C8 != 2 → skip.
- State == 2:
  - penetration_ratio = penetration / flt_7D108C.
  - ratio > 2.0 OR ShortArrayLookupAndZeroCheck returns true (contact active):
    - Set AI control flag to 0 (release AI control).
    - ratio > 8.0 OR abs(lookup_value) > 0.75 → SetDriverVisibility(0) (hide driver).
    - Otherwise → SetDriverVisibility(1) (show driver).
  - ratio <= 2.0 AND no contact:
    - Set AI control flag to 1 (retain AI control).
    - SetDriverVisibility(1) (show driver).
