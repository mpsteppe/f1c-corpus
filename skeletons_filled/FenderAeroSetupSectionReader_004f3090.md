## FenderAeroSetupSectionReader_004f3090 — fender aero setup section parser

**Summary:** Reads the fender aerodynamics setup section from a vehicle file, parsing center, drag, lift, and sideways parameter fields. Sets a flag when center data is loaded.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | flag set to 1 when FenderCenter line is parsed |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d52fc | aFenderflareran | R | FenderFlareRangeString [DERIVED] |
| 005d5310 | aFenderflareset | R | FenderFlareSettingString [DERIVED] |
| 005d5324 | aFendersideways | R | FendersidewaysString [DERIVED] |
| 005d5334 | aFenderliftpara | R | FenderLiftParamsStr [DERIVED] |
| 005d5348 | aFenderdragpara | R | FenderDragParamString [DERIVED] |
| 005d535c | aFendercenter | R | FenderCenterField [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e1f0 | CRTMathHelper_e1f0 | computes indexed flare range/setting values into output buffer |
| 005351d0 | LineInputReader | reads a line of text from input (max 384 chars) |
| 005651b0 | sub_5651B0 | checks section marker type: 1 = end-of-section, 0 = data line |
| 00565aa0 | sub_565AA0 | parses key=value pair and writes parsed float(s) to output pointers |

**Guard conditions:** Loop reads lines via LineInputReader. sub_5651B0 result: 1 → break (end of section reached). Non-zero non-1 → skip line (not data). 0 → process as data line (parse parameters).
