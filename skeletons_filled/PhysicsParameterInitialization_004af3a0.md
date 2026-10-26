## PhysicsParameterInitialization_004af3a0 — TrackPhysicsParameterInit

**Summary:** Selects and initializes a full set of physics/track-environment parameters (grip, wear, temperature, etc.) based on a track-type selector at this+0x3B40. Four profiles (cases 0-3) each clamp defaults between min/max bounds and populate nested per-wheel arrays. No guard condition; default case returns immediately.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TrackEnvironmentSelect (004ade20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3B40 | R | — | track environment type selector (0-3; default returns) |
| this | 0x3BAC | RW | 0 | physics parameter slot 0 (integer, clamped between bounds) |
| this | 0x3BB4 | R | — | lower bound for parameter at 0x3BAC |
| this | 0x3BB8 | R | — | upper bound for parameter at 0x3BAC |
| this | 0x3BD0 | RW | 0 | physics parameter slot 1 (integer, clamped between bounds) |
| this | 0x3BD8 | R | — | lower bound for parameter at 0x3BD0 |
| this | 0x3BDC | R | — | upper bound for parameter at 0x3BD0 |
| this | 0x3BF4 | RW | 1056964608 → 0.5f | physics parameter slot 2 (float, e.g. grip or friction coefficient) |
| this | 0x3BFC | R | — | lower bound for parameter at 0x3BF4 |
| this | 0x3C00 | R | — | upper bound for parameter at 0x3BF4 |
| this | 0x3C18 | RW | 1039516303 → 0.12f | physics parameter slot 3 (float, e.g. wear rate or sensitivity) |
| this | 0x3C20 | R | — | lower bound for parameter at 0x3C18 |
| this | 0x3C24 | R | — | upper bound for parameter at 0x3C18 |
| this | 0x3C3C | RW | 0 | physics parameter slot 4 (float) |
| this | 0x3C44 | R | — | lower bound for parameter at 0x3C3C |
| this | 0x3C48 | R | — | upper bound for parameter at 0x3C3C |
| this | 0x3C60 | RW | 0 | physics parameter slot 5 (integer) |
| this | 0x3C68 | R | — | lower bound for parameter at 0x3C60 |
| this | 0x3C6C | R | — | upper bound for parameter at 0x3C60 |
| this | 0x3C84 | RW | 1058642330 → 0.6f | physics parameter slot 6 (float, e.g. damping or stiffness) |
| this | 0x3C8C | R | — | lower bound for parameter at 0x3C84 |
| this | 0x3C90 | R | — | upper bound for parameter at 0x3C84 |
| this | 0x3CA8 | RW | 1061997773 → 0.8f | physics parameter slot 7 (float) |
| this | 0x3CB0 | R | — | lower bound for parameter at 0x3CA8 |
| this | 0x3CB4 | R | — | upper bound for parameter at 0x3CA8 |
| this | 0x3CCC | RW | 1177792512 → 11500.0f | physics parameter slot 8 (float, large magnitude — e.g. spring rate or load) |
| this | 0x3CD4 | R | — | lower bound for parameter at 0x3CCC |
| this | 0x3CD8 | R | — | upper bound for parameter at 0x3CCC |
| this | 0x3CF0 | RW | 1072064102 → 1.8f | physics parameter slot 9 (float) |
| this | 0x3CF8 | R | — | lower bound for parameter at 0x3CF0 |
| this | 0x3CFC | R | — | upper bound for parameter at 0x3CF0 |
| this | 0x3D14 | RW | 1063675494 → 0.9f | physics parameter slot 10 (float) |
| this | 0x3D1C | R | — | lower bound for parameter at 0x3D14 |
| this | 0x3D20 | R | — | upper bound for parameter at 0x3D14 |
| this | 0x3D38 | RW | 1014350479 → 0.015f | physics parameter slot 11 (float, very small — e.g. threshold) |
| this | 0x3D40 | R | — | lower bound for parameter at 0x3D38 |
| this | 0x3D44 | R | — | upper bound for parameter at 0x3D38 |
| this | 0x3D5C | RW | 1043542835 → 0.175f | physics parameter slot 12 (float) |
| this | 0x3D64 | R | — | lower bound for parameter at 0x3D5C |
| this | 0x3D68 | R | — | upper bound for parameter at 0x3D5C |
| this | 0x3D80 | RW | 1065353216 → 1.0f | physics parameter slot 13 (float, unity default) |
| this | 0x3D88 | R | — | lower bound for parameter at 0x3D80 |
| this | 0x3D8C | R | — | upper bound for parameter at 0x3D80 |
| this | 0x3DA4 | RW | 1043542835 → 0.175f | physics parameter slot 14 (float) |
| this | 0x3DAC | R | — | lower bound for parameter at 0x3DA4 |
| this | 0x3DB0 | R | — | upper bound for parameter at 0x3DA4 |
| this | 0x3DC8 | RW | 1065353216 → 1.0f | physics parameter slot 15 (float) |
| this | 0x3DD0 | R | — | lower bound for parameter at 0x3DC8 |
| this | 0x3DD4 | R | — | upper bound for parameter at 0x3DC8 |
| this | 0x3DEC | RW | 1043207291 → 0.17f | physics parameter slot 16 (float) |
| this | 0x3DF4 | R | — | lower bound for parameter at 0x3DEC |
| this | 0x3DF8 | R | — | upper bound for parameter at 0x3DEC |
| this | 0x3E10 | RW | 1035489772 → 0.09f | physics parameter slot 17 (float) |
| this | 0x3E18 | R | — | lower bound for parameter at 0x3E10 |
| this | 0x3E1C | R | — | upper bound for parameter at 0x3E10 |
| this | 0x3E34 | RW | 0 | physics parameter slot 18 (float) |
| this | 0x3E3C | R | — | lower bound for parameter at 0x3E34 |
| this | 0x3E40 | R | — | upper bound for parameter at 0x3E34 |
| this | 0x3E58 | RW | 0 | physics parameter slot 19 (float) |
| this | 0x3E60 | R | — | lower bound for parameter at 0x3E58 |
| this | 0x3E64 | R | — | upper bound for parameter at 0x3E58 |
| this | 0x3E7C | RW | 1034147594 → 0.08f | physics parameter slot 20 (float) |
| this | 0x3E84 | R | — | lower bound for parameter at 0x3E7C |
| this | 0x3E88 | R | — | upper bound for parameter at 0x3E7C |
| this | 0x3EA0 | RW | 1063675494 → 0.9f | physics parameter slot 21 (float) |
| this | 0x3EA8 | R | — | lower bound for parameter at 0x3EA0 |
| this | 0x3EAC | R | — | upper bound for parameter at 0x3EA0 |
| this | 0x3EC4 | RW | 1036831949 → 0.1f | physics parameter slot 22 (float) |
| this | 0x3ECC | R | — | lower bound for parameter at 0x3EC4 |
| this | 0x3ED0 | R | — | upper bound for parameter at 0x3EC4 |
| this | 0x3EE8 | RW | 0 | physics parameter slot 23 (float) |
| this | 0x3EF0 | R | — | lower bound for parameter at 0x3EE8 |
| this | 0x3EF4 | R | — | upper bound for parameter at 0x3EE8 |
| this | 0x3F0C | RW | 0 | physics parameter slot 24 (float) |
| this | 0x3F14 | R | — | lower bound for parameter at 0x3F0C |
| this | 0x3F18 | R | — | upper bound for parameter at 0x3F0C |
| this | 0x3F30 | RW | 1028443341 → 0.05f | physics parameter slot 25 (float) |
| this | 0x3F38 | R | — | lower bound for parameter at 0x3F30 |
| this | 0x3F3C | R | — | upper bound for parameter at 0x3F30 |
| this | 0x3F54 | RW | 1051931443 → 0.35f | physics parameter slot 26 (float) |
| this | 0x3F5C | R | — | lower bound for parameter at 0x3F54 |
| this | 0x3F60 | R | — | upper bound for parameter at 0x3F54 |
| this | 0x3F78 | RW | 1058642330 → 0.6f | physics parameter slot 27 (float) |
| this | 0x3F80 | R | — | lower bound for parameter at 0x3F78 |
| this | 0x3F84 | R | — | upper bound for parameter at 0x3F78 |
| this | 0x3F9C | RW | 0 | physics parameter slot 28 (float) |
| this | 0x3FA4 | R | — | lower bound for parameter at 0x3F9C |
| this | 0x3FA8 | R | — | upper bound for parameter at 0x3F9C |
| this | 0x3FC0 | RW | 1069547520 → 1.5f | physics parameter slot 29 (float) |
| this | 0x3FC8 | R | — | lower bound for parameter at 0x3FC0 |
| this | 0x3FCC | R | — | upper bound for parameter at 0x3FC0 |
| this | 0x3FE4 | RW | 1033476506 → 0.075f | physics parameter slot 30 (float) |
| this | 0x3FEC | R | — | lower bound for parameter at 0x3FE4 |
| this | 0x3FF0 | R | — | upper bound for parameter at 0x3FE4 |
| this | 0x4008 | RW | 1065353216 → 1.0f | physics parameter slot 31 (float) |
| this | 0x4010 | R | — | lower bound for parameter at 0x4008 |
| this | 0x4014 | R | — | upper bound for parameter at 0x4008 |
| this | 0x402C | RW | — | physics parameter slot 32 (float, set via ClampedFloatSetter_1de0) |
| this | 0x4034 | R | — | lower bound for parameter at 0x402C |
| this | 0x4038 | R | — | upper bound for parameter at 0x402C |
| this | 0x426C | RW | — | physics parameter slot 33 (float, set via ClampedFloatSetter_1de0) |
| this | 0x4274 | R | — | lower bound for parameter at 0x426C |
| this | 0x4278 | R | — | upper bound for parameter at 0x426C |
| this | 0x44AC | RW | — | physics parameter slot 34 (float, set via ClampedFloatSetter_1de0) |
| this | 0x44B4 | R | — | lower bound for parameter at 0x44AC |
| this | 0x44B8 | R | — | upper bound for parameter at 0x44AC |
| this | 0x46EC | RW | — | physics parameter slot 35 (float, set via ClampedFloatSetter_1de0) |
| this | 0x46F4 | R | — | lower bound for parameter at 0x46EC |
| this | 0x46F8 | R | — | upper bound for parameter at 0x46EC |

**Written-by note (persistence):**
- this 0x3BAC: once per track-type selection (clamped between stored min/max bounds); external poke survives until next track-type change
- this 0x3BD0: once per track-type selection (clamped); external poke survives
- this 0x3BF4: once per track-type selection (clamped float default 0.5); external poke survives
- this 0x3C18: once per track-type selection (clamped float default 0.12); external poke survives
- this 0x3C3C: once per track-type selection (clamped float); external poke survives
- this 0x3C60: once per track-type selection (clamped int); external poke survives
- this 0x3C84: once per track-type selection (clamped float default 0.6); external poke survives
- this 0x3CA8: once per track-type selection (clamped float default 0.8); external poke survives
- this 0x3CCC: once per track-type selection (clamped float default 11500.0); external poke survives
- this 0x3CF0: once per track-type selection (clamped float default 1.8); external poke survives
- this 0x3D14: once per track-type selection (clamped float default 0.9); external poke survives
- this 0x3D38: once per track-type selection (clamped float default 0.015); external poke survives
- this 0x3D5C: once per track-type selection (clamped float default 0.175); external poke survives
- this 0x3D80: once per track-type selection (clamped float default 1.0); external poke survives
- this 0x3DA4: once per track-type selection (clamped float default 0.175); external poke survives
- this 0x3DC8: once per track-type selection (clamped float default 1.0); external poke survives
- this 0x3DEC: once per track-type selection (clamped float default 0.17); external poke survives
- this 0x3E10: once per track-type selection (clamped float default 0.09); external poke survives
- this 0x3E34: once per track-type selection (clamped float); external poke survives
- this 0x3E58: once per track-type selection (clamped float); external poke survives
- this 0x3E7C: once per track-type selection (clamped float default 0.08); external poke survives
- this 0x3EA0: once per track-type selection (clamped float default 0.9); external poke survives
- this 0x3EC4: once per track-type selection (clamped float default 0.1); external poke survives
- this 0x3EE8: once per track-type selection (clamped float); external poke survives
- this 0x3F0C: once per track-type selection (clamped float); external poke survives
- this 0x3F30: once per track-type selection (clamped float default 0.05); external poke survives
- this 0x3F54: once per track-type selection (clamped float default 0.35); external poke survives
- this 0x3F78: once per track-type selection (clamped float default 0.6); external poke survives
- this 0x3F9C: once per track-type selection (clamped float); external poke survives
- this 0x3FC0: once per track-type selection (clamped float default 1.5); external poke survives
- this 0x3FE4: once per track-type selection (clamped float default 0.075); external poke survives
- this 0x4008: once per track-type selection (clamped float default 1.0); external poke survives
- this 0x402C: once per track-type selection (set via ClampedFloatSetter_1de0); external poke survives
- this 0x426C: once per track-type selection (set via ClampedFloatSetter_1de0); external poke survives
- this 0x44AC: once per track-type selection (set via ClampedFloatSetter_1de0); external poke survives
- this 0x46EC: once per track-type selection (set via ClampedFloatSetter_1de0); external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b0154 | jpt_4AF3B4 | R | jump table for switch on track-type selector (4 cases + default) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004646c0 | FloatClamp | clamp float parameter between stored min and max bounds |
| 0047f1f0 | ClampByRange | clamp integer parameter between stored min and max bounds |
| 004b1de0 | ClampedFloatSetter_1de0 | set a physics parameter float to a literal value (used in cases 2-3 for sequential field initialization) |
| 004b20d0 | ArithmeticComparison_20d0 | comparison/sentinel call between parameter groups (likely validates or advances internal state) |

**Guard conditions:** No guard condition. Unconditional switch on this+0x3B40; cases 0-3 execute parameter initialization; default case returns immediately (no parameter changes).
