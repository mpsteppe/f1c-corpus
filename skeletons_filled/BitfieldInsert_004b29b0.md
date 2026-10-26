## BitfieldInsert_004b29b0 — Bitfield 5-bit insert (bits 12-16)

**Summary:** Multiplies float by 31.0 and inserts 5-bit value into bits 12-16 of bitfield at offset 0x2C via XOR merge. Packs color channel or similar small-range data.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleOrientationFromEulerAngles (004b2dd0), sub_4B32A0 (004b32a0), SetupCarLightingAndRender (004c71c0), AudioSampleCrossFadeInterpolation (004ff8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | RW | — | Bitfield dword (bits 12-16 hold 5-bit packed value, * 31) |

**Written-by note (persistence):**
- this 0x2C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005accd0 | flt_5ACCD0 | R | RGBChannelScaleR [DERIVED] (also: ` — R/B channel scale factor (fixed-point multiplier) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No explicit guard — float converted to uint8 and masked.
