## FloatToBitfieldPack_004b2930 — Float to bitfield pack (15-bit, shifted 17)

**Summary:** Multiplies float by 10.0, clamps to [0, 32767], shifts left 17 bits, and inserts into bitfield at offset 0x2C preserving low 17 bits. Packs unsigned value into high 15 bits of dword.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleOrientationFromEulerAngles (004b2dd0), sub_4B32A0 (004b32a0), SetupCarLightingAndRender (004c71c0), AudioSampleCrossFadeInterpolation (004ff8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | RW | — | Bitfield dword (low 17 bits preserved, bits 17-31 packed with scaled value) |

**Written-by note (persistence):**
- this 0x2C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Float input clamped to [0.0, 3276.7] range — negative values saturate to 0, values above max saturate to 32767.
