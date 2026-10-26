## VehiclePhysicsVelocityAngularVelocityIntegrator_00459ae0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_45A8E0 (0045a8e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0xC4 | RW | — | [LLM] |
| this | 0xC8 | RW | — | [LLM] |
| this | 0xCC | R | — | [LLM] |
| this | 0xD0 | R | — | [LLM] |
| this | 0xD8 | R | — | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x130 | R | — | [LLM] |
| this | 0x138 | R | — | [LLM] |
| this | 0x140 | R | — | [LLM] |
| this | 0x148 | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x160 | R | — | [LLM] |
| this | 0x180 | R | — | [LLM] |
| this | 0x208 | RW | 0 | [LLM] |
| this | 0x20C | RW | 0 | [LLM] |
| this | 0x210 | RW | 0 | [LLM] |
| this | 0x214 | RW | 0 | [LLM] |
| this | 0x218 | RW | 0 | [LLM] |
| this | 0x21C | RW | 0 | [LLM] |
| this | 0x220 | RW | 0 | [LLM] |
| this | 0x224 | RW | 0 | [LLM] |
| this | 0x228 | RW | 0 | [LLM] |
| this | 0x22C | RW | 0 | [LLM] |
| this | 0x230 | RW | 0 | [LLM] |
| this | 0x234 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xC0: recalc every frame — external poke does NOT persist
- this 0xC4: recalc every frame — external poke does NOT persist
- this 0xC8: recalc every frame — external poke does NOT persist
- this 0x208: recalc every frame — external poke does NOT persist
- this 0x20C: recalc every frame — external poke does NOT persist
- this 0x210: recalc every frame — external poke does NOT persist
- this 0x214: recalc every frame — external poke does NOT persist
- this 0x218: recalc every frame — external poke does NOT persist
- this 0x21C: recalc every frame — external poke does NOT persist
- this 0x220: recalc every frame — external poke does NOT persist
- this 0x224: recalc every frame — external poke does NOT persist
- this 0x228: recalc every frame — external poke does NOT persist
- this 0x22C: recalc every frame — external poke does NOT persist
- this 0x230: recalc every frame — external poke does NOT persist
- this 0x234: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ed50 | dbl_59ED50 | R | VelocityDampingFactor [DERIVED] (also: ` — anti-roll rate scale) |
| 0059f038 | dbl_59F038 | R | Double_Unknown_Dynamics3 [DERIVED] |
| 0059f040 | dbl_59F040 | R | Unknown_Double_59F040 [DERIVED] |
| 0059f048 | dbl_59F048 | R | DualClutchDelay [DERIVED] |
| 0059f050 | dbl_59F050 | R | MathTransformConstant [DERIVED] |
| 0059f058 | dbl_59F058 | R | CollisionRestitution [DERIVED] |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004361d0 | F_3DVectorTransformBy33Matrix | [LLM] |
| 0043aee0 | TransformApply3D | [LLM] |
| 00459a40 | PhysicsStateIntegration | [LLM] |
| 004be4e0 | SpriteGridRender | [LLM] |
| 0054b4d0 | sub_54B4D0 | [LLM] |
| 0054fa00 | NetworkPacketDataWriter | [LLM] |
| 0054fa90 | NetworkPacketDataReader | [LLM] |
| 0054fae0 | BufferEntryClear | [LLM] |
| 00569ad0 | AccumulateAngularMomentum | [LLM] |
| 00569c10 | sub_569C10 | [LLM] |
| 00569de0 | sub_569DE0 | [LLM] |
| 00588570 | FloatConvertWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x50 | <= | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
