## ConditionalRenderPipelineDispatch_00409970 — Conditional Rearview Pipeline Dispatch

**Summary:** If rearview data is present (this[2] non-null), converts camera scale factors from degrees to radians, sets up render pipeline with camera transform and flag reset. Part of mirror rendering system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_409890 (00409890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Rearview data presence flag (non-null = execute pipeline) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004099e0 | sub_4099E0 | R | Function pointer stored by PointerStorePair2 for pipeline callback |
| 0059e65c | flt_59E65C | R | CameraShakeMultiplier [DERIVED] |
| 007cf680 | dword_7CF680 | R | Camera center/target position |
| 007cf6a4 | flt_7CF6A4 | R | Camera scale factor X (multiplied by degrees-to-radians) |
| 007cf6c8 | flt_7CF6C8 | R | Camera scale factor Y (multiplied by degrees-to-radians) |
| 007cf6ec | dword_7CF6EC | R | Camera zoom/distance (passed to Bit5FlagSetReset) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00541ca0 | sub_541CA0 | Sets camera center position from dword_7CF680 |
| 00542050 | sub_542050 | Applies camera rotation from scaled angle factors |
| 00542540 | PointerStorePair2 | Stores (sub_4099E0, 0) as pipeline callback pair |
| 00542650 | Bit5FlagSetReset | Sets/resets bit 5 flag on camera zoom value |
| 00542680 | ConditionalFloatSetter | Sets float parameter to 0.5 |

**Guard conditions:** this[2] (offset 0x8, rearview data) must be non-null. If null, function returns 0 immediately without any pipeline setup.
