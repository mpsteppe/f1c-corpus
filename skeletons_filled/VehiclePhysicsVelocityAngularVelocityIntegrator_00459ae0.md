## VehiclePhysicsVelocityAngularVelocityIntegrator_00459ae0 — Vehicle Physics Two-Pass Integrator

**Summary:** Per-frame vehicle physics integration: computes drag forces from velocity, applies gravity and damping, rotates acceleration into local frame, handles network contact forces from other vehicles (when count > 1), integrates position/velocity via half-step then full-step, and reads remote vehicle state into local transform.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_45A8E0 (0045a8e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | vtable function pointer for physics step callback |
| this | 0x0 | R | — | vtable pointer (used for virtual call offset +8) |
| this | 0x28 | R | — | velocity drag coefficient (scales drag force by squared velocity) |
| this | 0x30 | R | — | gravity acceleration scale |
| this | 0x38 | R | — | longitudinal force component |
| this | 0x40 | R | — | lateral force from velocity squared × drag |
| this | 0x48 | R | — | collision restitution / force transfer ratio |
| this | 0x50 | R | — | contact point count (multi-vehicle collision count) |
| this | 0x54 | R | — | position X (current) |
| this | 0x58 | R | — | position Y (current) |
| this | 0x5C | R | — | position Z (current) |
| this | 0x64 | R | — | orientation matrix element [0][0] |
| this | 0x68 | R | — | orientation matrix element [1][0] |
| this | 0xC0 | RW | — | angular velocity X (output, written per sub-step) |
| this | 0xC4 | RW | — | angular velocity Y (output) |
| this | 0xC8 | RW | — | angular velocity Z (output) |
| this | 0xCC | R | — | angular velocity X (input/previous state) |
| this | 0xD0 | R | — | angular velocity Y (input) |
| this | 0xD8 | R | — | angular velocity Z (input) |
| this | 0xE0 | R | — | orientation quaternion / matrix element (rotation data) |
| this | 0xE8 | R | — | orientation matrix column 3 element |
| this | 0xF0 | R | — | rotation matrix element [0][0] |
| this | 0x100 | R | — | rotation matrix element [1][1] |
| this | 0x108 | R | — | rotation matrix element [2][2] |
| this | 0x110 | R | — | rotation matrix [0][2] or related element |
| this | 0x118 | R | — | rotation matrix element |
| this | 0x120 | R | — | rotation matrix element |
| this | 0x130 | R | — | rotation matrix row 0 (for contact force transform) |
| this | 0x138 | R | — | linear velocity X component |
| this | 0x140 | R | — | linear velocity Y component |
| this | 0x148 | R | — | linear velocity Z component |
| this | 0x150 | R | — | angular velocity component |
| this | 0x158 | R | — | angular velocity component |
| this | 0x160 | R | — | angular velocity component |
| this | 0x180 | R | — | contact force / impulse magnitude |
| this | 0x208 | RW | 0 | accumulated drag force X (zeroed each frame) |
| this | 0x20C | RW | 0 | accumulated drag force Y |
| this | 0x210 | RW | 0 | accumulated drag force Z |
| this | 0x214 | RW | 0 | accumulated angular drag X |
| this | 0x218 | RW | 0 | accumulated angular drag Y |
| this | 0x21C | RW | 0 | accumulated angular drag Z |
| this | 0x220 | RW | 0 | accumulated gravity/damping force X |
| this | 0x224 | RW | 0 | accumulated gravity/damping force Y |
| this | 0x228 | RW | 0 | accumulated gravity/damping force Z |
| this | 0x22C | RW | 0 | accumulated torque X |
| this | 0x230 | RW | 0 | accumulated torque Y |
| this | 0x234 | RW | 0 | accumulated torque Z |

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
| 004361d0 | F_3DVectorTransformBy33Matrix | transform velocity vector by 3×3 rotation matrix |
| 0043aee0 | TransformApply3D | apply 3D transform (rotation + translation) to vector |
| 00459a40 | PhysicsStateIntegration | integrate position/velocity forward by time step |
| 004be4e0 | SpriteGridRender | render sprite/grid at position with given radius |
| 0054b4d0 | sub_54B4D0 | store/update remote vehicle state (position + rotation) |
| 0054fa00 | NetworkPacketDataWriter | write physics state to network packet |
| 0054fa90 | NetworkPacketDataReader | read contact point data from network packet |
| 0054fae0 | BufferEntryClear | clear/commit buffer entry after processing |
| 00569ad0 | AccumulateAngularMomentum | accumulate angular momentum from contact forces |
| 00569c10 | sub_569C10 | perform half-step physics integration |
| 00569de0 | sub_569DE0 | perform full-step physics integration |
| 00588570 | FloatConvertWrapper | convert float to double for computation |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x50 | <= | 1 | contact point count: when <= 1 (single vehicle), skip network contact processing loop |

**Guard interpretation:** When this+0x50 (contact point count) <= 1 (PASSES single-vehicle mode), the network contact processing loop is skipped — only local drag/gravity integration runs. When > 1 (multi-vehicle collision detected), the code enters the contact force processing loop, reading per-contact data from network packets, computing impulse magnitudes, and accumulating angular momentum.
