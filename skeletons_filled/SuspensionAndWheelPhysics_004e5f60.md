## SuspensionAndWheelPhysics_004e5f60 — Vehicle Physics Per-Frame Update (Suspension/Wheel/Tire/Engine)

**Summary:** Computes full vehicle dynamics each frame: wheel contact positions, suspension forces, tire compound behavior, anti-roll bar forces, aerodynamic loads, engine/drivetrain parameters, and particle effects. Reads configuration from parameter structs (a2=car setup, a3=session/track data), writes results back into the vehicle state struct.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LargeConfigFunctionWithPhysicsConstants (004e45b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | — | PhysX [FACT] |
| this | 0x20 | RW | — | PhysY [FACT] |
| this | 0x24 | RW | — | PhysZ [FACT] |
| this | 0x88 | RW | — | wing/aero force X (writable force accumulator) |
| this | 0x8C | RW | — | wing/aero force Y (writable force accumulator) |
| this | 0x6E8 | R | — | pointer to collision mesh / body object (used for contact point transforms) |
| this | 0x72C | RW | — | body world position X (updated each frame) |
| this | 0x730 | RW | — | body world position Y (updated each frame) |
| this | 0x734 | RW | — | body world position Z (updated each frame) |
| this | 0x75C | R | — | steering-geometry reference: track width / wheel offset X |
| this | 0x760 | R | — | steering-geometry reference: wheelbase / wheel offset Y |
| this | 0x764 | R | — | steering-geometry reference: ride height / wheel offset Z |
| this | 0x768 | R | — | steering-geometry reference: front axle / wheel X component |
| this | 0x76C | R | — | steering-geometry reference: front axle / wheel Y component |
| this | 0x770 | R | — | steering-geometry reference: front axle / wheel Z component |
| this | 0x8B8 | RW | — | wheel contact patch position array A (4 wheels, 74-float stride) — X |
| this | 0x8BC | RW | — | wheel contact patch position array A — Y |
| this | 0x8C0 | RW | — | wheel contact patch position array A — Z |
| this | 0xCC8 | R | — | pointer to additional body/part mesh (used for contact point query) |
| this | 0xCCC | R | — | body offset X (read with above pointer) |
| this | 0xCD0 | R | — | body offset Y |
| this | 0xCD4 | R | — | body offset Z |
| this | 0xD0C | R | — | pointer to secondary body/part mesh (used for contact point query) |
| this | 0xD10 | R | — | secondary body offset X |
| this | 0xD14 | R | — | secondary body offset Y |
| this | 0xD18 | R | — | secondary body offset Z |
| this | 0xD50 | R | — | unknown body reference (read in position adjustment block) |
| this | 0x1038 | RW | — | vehicle mass / spring parameter (copied from a2 computation) |
| this | 0x1078 | RW | — | output contact point position array (13 points, 7-float stride) — start |
| this | 0x107C | RW | — | output contact point position Y |
| this | 0x1080 | RW | — | output contact point position Z |
| this | 0x11E4 | RW | — | per-wheel output position array (4 wheels, 7-float stride) — X start |
| this | 0x11E8 | RW | — | per-wheel output position Y |
| this | 0x11EC | RW | — | per-wheel output position Z |
| this | 0x32BC | R | — | flag: if zero, use default body position fallback (replay/no-physics mode) |
| this | 0x34A8 | R | — | tire wear / compound state reference value (copied into per-wheel state) |
| this | 0x3510 | RW | — | vehicle mass (from session config a3+64 * 9.81) |
| this | 0x3514 | RW | — | vehicle mass with added spring load (mass + 0.75 * spring_constant) |
| this | 0x3518 | RW | — | 1.0 / adjusted mass (inverse mass) |
| this | 0x351C | RW | — | aerodynamic drag coefficient |
| this | 0x3520 | RW | — | aerodynamic lift coefficient |
| this | 0x3524 | RW | — | aerodynamic sideforce coefficient |
| this | 0x3528 | RW | — | 1.0 / drag coefficient |
| this | 0x352C | RW | — | 1.0 / lift coefficient |
| this | 0x3530 | RW | — | 1.0 / sideforce coefficient |
| this | 0x3564 | RW | — | aero/suspension parameter from session (offset 300) |
| this | 0x3568 | RW | — | aero/suspension parameter from session (offset 308) |
| this | 0x356C | RW | — | aero/suspension parameter from session (offset 316) |
| this | 0x358C | RW | — | wheel contact patch position array B (4 wheels, 62-float stride) — X |
| this | 0x3590 | RW | — | wheel contact patch position array B — Y |
| this | 0x3594 | RW | — | wheel contact patch position array B — Z |
| this | 0x35AC | RW | 0 | per-wheel suspension state: spring displacement (wheel 0, field 0) |
| this | 0x35B0 | RW | 0 | per-wheel suspension state: spring velocity (wheel 0, field 1) |
| this | 0x35B8 | RW | 0 | per-wheel suspension state: damper force accumulator (wheel 0) |
| this | 0x35BC | RW | 1065353216 → 1.0f | per-wheel suspension: spring rate factor (wheel 0) |
| this | 0x35C0 | RW | 0 | per-wheel suspension: zeroed accumulator (wheel 0) |
| this | 0x35C4 | RW | 0 | per-wheel suspension: zeroed accumulator (wheel 0) |
| this | 0x35D4 | RW | 0 | per-wheel: bump stop force accumulator (wheel 0) |
| this | 0x35D8 | RW | 0 | per-wheel: rebound force accumulator (wheel 0) |
| this | 0x35DC | RW | — | per-wheel: tire temperature (wheel 0) |
| this | 0x35E0 | RW | — | per-wheel: tire temperature reference (wheel 0) |
| this | 0x35E4 | RW | — | per-wheel: tire temperature inner/mid (wheel 0) |
| this | 0x35E8 | RW | — | per-wheel: tire temperature outer (wheel 0) |
| this | 0x35EC | RW | — | per-wheel: tire carcass temperature (wheel 0) |
| this | 0x35F0 | RW | — | per-wheel: tire tread temperature (wheel 0) |
| this | 0x35F8 | RW | — | per-wheel: bump stop travel limit (wheel 0) |
| this | 0x35FC | RW | — | per-wheel: rebound travel limit (wheel 0) |
| this | 0x3610 | R | — | per-wheel: tire pressure / load reference (read only for this wheel) |
| this | 0x3618 | RW | 0 | per-wheel: anti-roll bar force (wheel 0) |
| this | 0x363C | RW | 1065353216 → 1.0f | tirePuncture_RR [CONFIRMED] |
| this | 0x3640 | RW | 0 | per-wheel: tire wear rate accumulator (wheel 0) |
| this | 0x3644 | RW | 2096152002 | per-wheel: tire compound constant A (wheel 0, ~0.7f as float) |
| this | 0x3648 | RW | 2096152002 | per-wheel: tire compound constant B (wheel 0, ~0.7f) |
| this | 0x3658 | RW | 0 | per-wheel: zeroed accumulator (wheel 0) |
| this | 0x365C | RW | 0 | per-wheel: zeroed accumulator (wheel 0) |
| this | 0x3660 | RW | 0 | per-wheel: zeroed accumulator (wheel 0) |
| this | 0x3664 | RW | 0 | per-wheel: zeroed accumulator (wheel 0) |
| this | 0x3668 | RW | 0 | per-wheel: zeroed accumulator (wheel 0) |
| this | 0x366C | RW | — | per-wheel: computed wheel position X (wheel 0) |
| this | 0x3670 | RW | — | per-wheel: computed wheel position Y (wheel 0) |
| this | 0x3674 | RW | — | per-wheel: computed wheel position Z / load transfer value (wheel 0) |
| this | 0x3684 | R | — | per-wheel: spring/force lookup table pointer (wheel 0) |
| this | 0x3688 | R | — | per-wheel: damper/force lookup table pointer (wheel 0) |
| this | 0x368C | R | — | per-wheel: additional force curve pointer (wheel 0) |
| this | 0x3710 | RW | 0 | per-wheel: anti-roll bar force copy for front axle (wheel 0 or front reference) |
| this | 0x377C | R | — | rear-left contact patch position X (read in weight dist calculation) |
| this | 0x3780 | R | — | rear-left contact patch position Y |
| this | 0x3784 | R | — | rear-left contact patch position Z |
| this | 0x3808 | RW | 0 | per-wheel: anti-roll bar force for rear axle (wheel 2 ref) |
| this | 0x3874 | R | — | rear-right contact patch position X |
| this | 0x3878 | R | — | rear-right contact patch position Y |
| this | 0x387C | R | — | rear-right contact patch position Z |
| this | 0x3900 | RW | 0 | per-wheel: anti-roll bar force for rear axle copy |
| this | 0x3960 | RW | — | vehicle parameter: mass/spring constant A (copied from a2 computation) |
| this | 0x3968 | RW | — | vehicle parameter: mass/spring constant B |
| this | 0x396C | RW | — | TireBrandLookup result pointer (tire compound data) |
| this | 0x3970 | R | — | tire compound index from CompoundIndexLookup |
| this | 0x3974 | RW | — | tire compound blend/selection result |
| this | 0x3978 | RW | — | tireChoice [CONFIRMED] |
| this | 0x397C | RW | — | tire compound: softness/hardness factor |
| this | 0x3980 | RW | — | tire compound: grip/stiffness factor |
| this | 0x3984 | RW | — | tire compound: wear rate factor |
| this | 0x3988 | RW | — | tire compound: temperature range min |
| this | 0x398C | RW | — | tire compound: temperature range max |
| this | 0x3990 | RW | — | fuelConsumptionFactor [CONFIRMED] |
| this | 0x3994 | RW | 0 | pointer to parameterized curve data array (allocated via new) |
| this | 0x3998 | RW | — | engine map: torque curve parameter A |
| this | 0x399C | RW | — | engine map: torque curve parameter B |
| this | 0x39A4 | RW | — | EngineMaxRPM [CONFIRMED] |
| this | 0x39A8 | RW | 0 | engine map: zeroed accumulator |
| this | 0x39AC | RW | 0 | engine map: zeroed accumulator |
| this | 0x39B0 | RW | — | engine: power/torque output value |
| this | 0x39B4 | RW | — | engine: throttle position / load |
| this | 0x39B8 | RW | 0 | engine: zeroed accumulator |
| this | 0x39BC | RW | — | drivetrain: clutch engagement |
| this | 0x39C0 | RW | — | drivetrain: transmission efficiency |
| this | 0x39C4 | RW | — | drivetrain: differential setting |
| this | 0x39C8 | RW | 0 | drivetrain: zeroed accumulator |
| this | 0x39CC | RW | — | drivetrain: final drive ratio |
| this | 0x39D4 | R | — | gear ratio table pointer (read for gear-dependent computation) |
| this | 0x39EC | RW | 0 | session: per-vehicle counter/state field (zeroed on init) |
| this | 0x39ED | RW | — | session: boolean flag (weather/condition indicator) |
| this | 0x39EE | RW | 0 | session: zeroed byte flag |
| this | 0x39F0 | RW | 0 | session: zeroed state field |
| this | 0x39F4 | RW | 18446744073709551614 | session: sentinel/default DWORD pair (0xFFFFFFFE pattern) |
| this | 0x39F8 | RW | — | session: state value from SessionStateIndexedLookup index 43 |
| this | 0x39FC | RW | — | CurrentGear [FACT] (also: gearNumber) |
| this | 0x3A00 | RW | — | session: state value from SessionStateIndexedLookup index 44 |
| this | 0x3A04 | RW | 0 | state threshold: zeroed |
| this | 0x3A08 | RW | 0 | state threshold: zeroed |
| this | 0x3A0C | RW | — | state threshold: engine wear trigger value |
| this | 0x3A10 | RW | — | state threshold: fuel level / consumption |
| this | 0x3A18 | RW | — | gear ratio value for current gear (lookup from gear table) |
| this | 0x3A30 | RW | — | front suspension mix factor A (front axle blending) |
| this | 0x3A34 | RW | — | front suspension mix factor B |
| this | 0x3A38 | RW | — | front suspension mix factor C |
| this | 0x3A3C | RW | — | rear suspension mix factor A |
| this | 0x3A40 | RW | — | rear suspension mix factor B |
| this | 0x3A44 | RW | — | rear suspension mix factor C |
| this | 0x3A58 | RW | 0 | accumulated force: front-left contribution |
| this | 0x3A5C | RW | 0 | accumulated force: front-right contribution |
| this | 0x3A60 | RW | 0 | accumulated force: rear-left contribution |
| this | 0x3A64 | RW | — | accumulated force: rear-right contribution |
| this | 0x3A68 | RW | — | accumulated torque: pitch moment |
| this | 0x3A6C | RW | — | accumulated torque: roll moment |
| this | 0x3A70 | RW | — | accumulated torque: yaw moment |
| this | 0x3A74 | RW | 0 | zeroed force accumulator |
| this | 0x3A78 | RW | — | force result: longitudinal (accel/brake) |
| this | 0x3A7C | RW | — | force result: lateral (cornering) |
| this | 0x3A80 | RW | — | force result: vertical (downforce/load) |
| this | 0x3A9C | RW | 0 | zeroed state: contact point accumulator |
| this | 0x3AB8 | R | — | contact point computation source: position reference array (13 points, 3 floats each) |
| this | 0x3ABC | R | — | contact point Y reference |
| this | 0x3AC0 | R | — | contact point Z reference |
| this | 0x3AE8 | RW | 0 | contact point scratch: zeroed |
| this | 0x3AF0 | RW | — | contact point: max distance value |
| this | 0x3AF4 | RW | 0 | contact point scratch: zeroed |
| this | 0x3AFC | RW | — | contact point scratch: bounding sphere radius |
| this | 0x3B00 | RW | — | contact point output flag/state |
| this | 0x3B0C | RW | — | contact point output: byte flag A |
| this | 0x3B10 | RW | 0 | contact point output: byte flag B (zeroed) |
| this | 0x3B14 | RW | 0 | contact point output: byte flag C (zeroed) |
| this | 0x3B54 | RW | 0 | wing/body force accumulator: X (zeroed before sum) |
| this | 0x3B58 | RW | 0 | wing/body force accumulator: Y (zeroed before sum) |
| this | 0x3B5C | RW | 0 | wing/body force accumulator: Z (zeroed before sum) |
| this | 0x3B6C | RW | 0 | contact point: index/counter (zeroed) |
| this | 0x3B70 | RW | — | contact point: current max distance from body center |
| this | 0x3B74 | RW | 1 | contact point: iteration count / flag |
| this | 0x3B75 | RW | 0 | contact point: byte flag (zeroed) |
| this | 0x3BE8 | RW | 0 | force/torque result accumulator field A (zeroed) |
| this | 0x3BEC | RW | 0 | force/torque result accumulator field B (zeroed) |
| this | 0x3BF0 | RW | 0 | force/torque result accumulator field C (zeroed) |
| this | 0x3BF4 | RW | 1065353216 → 1.0f | force/torque: scaling factor initialized to 1.0 |
| this | 0x3BF8 | RW | 18446744073701163007 | force/torque: sentinel DWORD pair (-8388609 = ~0x800000) |
| this | 0x3D48 | RW | 0 | copied data block: field at offset 0 (zeroed from a3+6128 block) |
| this | 0x3D4C | RW | 0 | copied data block: field at offset 4 (zeroed) |
| this | 0x3D50 | RW | 0 | copied data block: field at offset 8 (zeroed) |
| this | 0x3D54 | RW | — | copied data block: field at offset 12 |
| this | 0x3D58 | RW | — | copied data block: field at offset 16 |
| this | 0x3D5C | RW | — | copied data block: field at offset 20 |
| this | 0x3D60 | RW | 0 | copied data block: field at offset 24 (zeroed) |
| this | 0x3D9C | RW | — | tracked point position X (contact point 0, body-relative) |
| this | 0x3DA0 | RW | — | tracked point position Y |
| this | 0x3DA4 | RW | — | tracked point position Z |
| this | 0x3DCC | RW | — | tracked point position X (contact point 1) |
| this | 0x3DD0 | RW | — | tracked point position Y (contact point 1) |
| this | 0x3DD4 | RW | — | tracked point position Z (contact point 1) |
| this | 0x3EB8 | R | — | particle/vertex buffer state flag (read before particle alloc) |
| this | 0x3FF0 | RW | 0 | particle effect: state flag A (zeroed) |
| this | 0x3FF4 | RW | 0 | particle effect: state flag B (zeroed) |
| this | 0x3FF8 | RW | 0 | particle effect: state flag C (zeroed) |
| this | 0x3FFC | RW | 0 | particle effect: state flag D (zeroed) |
| this | 0x4000 | RW | 0 | particle effect: state flag E (zeroed) |
| this | 0x4004 | RW | 0 | particle effect: state flag F (zeroed) |
| this | 0x4008 | RW | 0 | particle effect: state flag G (zeroed) |
| this | 0x400C | RW | 0 | particle effect: state flag H (zeroed) |
| this | 0x4010 | RW | 0 | particle effect: state flag I (zeroed) |
| this | 0x4014 | RW | 0 | particle effect: state flag J (zeroed) |
| this | 0x4018 | RW | 0 | particle effect: state flag K (zeroed) |
| this | 0x401C | RW | 0 | particle effect: state flag L (zeroed) |
| this | 0x4020 | RW | — | vehicle state: post-update flag/value |
| this | 0x4024 | RW | — | vehicle state: post-update flag/value (byte) |

**Written-by note (persistence):**
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x88: recalc every frame — external poke does NOT persist
- this 0x8C: recalc every frame — external poke does NOT persist
- this 0x72C: recalc every frame — external poke does NOT persist
- this 0x730: recalc every frame — external poke does NOT persist
- this 0x734: recalc every frame — external poke does NOT persist
- this 0x8B8: recalc every frame — external poke does NOT persist
- this 0x8BC: recalc every frame — external poke does NOT persist
- this 0x8C0: recalc every frame — external poke does NOT persist
- this 0x1038: recalc every frame — external poke does NOT persist
- this 0x1078: recalc every frame — external poke does NOT persist
- this 0x107C: recalc every frame — external poke does NOT persist
- this 0x1080: recalc every frame — external poke does NOT persist
- this 0x11E4: recalc every frame — external poke does NOT persist
- this 0x11E8: recalc every frame — external poke does NOT persist
- this 0x11EC: recalc every frame — external poke does NOT persist
- this 0x3510: recalc every frame — external poke does NOT persist
- this 0x3514: recalc every frame — external poke does NOT persist
- this 0x3518: recalc every frame — external poke does NOT persist
- this 0x351C: recalc every frame — external poke does NOT persist
- this 0x3520: recalc every frame — external poke does NOT persist
- this 0x3524: recalc every frame — external poke does NOT persist
- this 0x3528: recalc every frame — external poke does NOT persist
- this 0x352C: recalc every frame — external poke does NOT persist
- this 0x3530: recalc every frame — external poke does NOT persist
- this 0x3564: recalc every frame — external poke does NOT persist
- this 0x3568: recalc every frame — external poke does NOT persist
- this 0x356C: recalc every frame — external poke does NOT persist
- this 0x358C: recalc every frame — external poke does NOT persist
- this 0x3590: recalc every frame — external poke does NOT persist
- this 0x3594: recalc every frame — external poke does NOT persist
- this 0x35AC: recalc every frame — external poke does NOT persist
- this 0x35B0: recalc every frame — external poke does NOT persist
- this 0x35B8: recalc every frame — external poke does NOT persist
- this 0x35BC: recalc every frame — external poke does NOT persist
- this 0x35C0: recalc every frame — external poke does NOT persist
- this 0x35C4: recalc every frame — external poke does NOT persist
- this 0x35D4: recalc every frame — external poke does NOT persist
- this 0x35D8: recalc every frame — external poke does NOT persist
- this 0x35DC: recalc every frame — external poke does NOT persist
- this 0x35E0: recalc every frame — external poke does NOT persist
- this 0x35E4: recalc every frame — external poke does NOT persist
- this 0x35E8: recalc every frame — external poke does NOT persist
- this 0x35EC: recalc every frame — external poke does NOT persist
- this 0x35F0: recalc every frame — external poke does NOT persist
- this 0x35F8: recalc every frame — external poke does NOT persist
- this 0x35FC: recalc every frame — external poke does NOT persist
- this 0x3618: recalc every frame — external poke does NOT persist
- this 0x363C: recalc every frame — external poke does NOT persist
- this 0x3640: recalc every frame — external poke does NOT persist
- this 0x3644: recalc every frame — external poke does NOT persist
- this 0x3648: recalc every frame — external poke does NOT persist
- this 0x3658: recalc every frame — external poke does NOT persist
- this 0x365C: recalc every frame — external poke does NOT persist
- this 0x3660: recalc every frame — external poke does NOT persist
- this 0x3664: recalc every frame — external poke does NOT persist
- this 0x3668: recalc every frame — external poke does NOT persist
- this 0x366C: recalc every frame — external poke does NOT persist
- this 0x3670: recalc every frame — external poke does NOT persist
- this 0x3674: recalc every frame — external poke does NOT persist
- this 0x3710: recalc every frame — external poke does NOT persist
- this 0x3808: recalc every frame — external poke does NOT persist
- this 0x3900: recalc every frame — external poke does NOT persist
- this 0x3960: recalc every frame — external poke does NOT persist
- this 0x3968: recalc every frame — external poke does NOT persist
- this 0x396C: recalc every frame — external poke does NOT persist
- this 0x3974: recalc every frame — external poke does NOT persist
- this 0x3978: recalc every frame — external poke does NOT persist
- this 0x397C: recalc every frame — external poke does NOT persist
- this 0x3980: recalc every frame — external poke does NOT persist
- this 0x3984: recalc every frame — external poke does NOT persist
- this 0x3988: recalc every frame — external poke does NOT persist
- this 0x398C: recalc every frame — external poke does NOT persist
- this 0x3990: recalc every frame — external poke does NOT persist
- this 0x3994: recalc every frame — external poke does NOT persist
- this 0x3998: recalc every frame — external poke does NOT persist
- this 0x399C: recalc every frame — external poke does NOT persist
- this 0x39A4: recalc every frame — external poke does NOT persist
- this 0x39A8: recalc every frame — external poke does NOT persist
- this 0x39AC: recalc every frame — external poke does NOT persist
- this 0x39B0: recalc every frame — external poke does NOT persist
- this 0x39B4: recalc every frame — external poke does NOT persist
- this 0x39B8: recalc every frame — external poke does NOT persist
- this 0x39BC: recalc every frame — external poke does NOT persist
- this 0x39C0: recalc every frame — external poke does NOT persist
- this 0x39C4: recalc every frame — external poke does NOT persist
- this 0x39C8: recalc every frame — external poke does NOT persist
- this 0x39CC: recalc every frame — external poke does NOT persist
- this 0x39EC: recalc every frame — external poke does NOT persist
- this 0x39ED: recalc every frame — external poke does NOT persist
- this 0x39EE: recalc every frame — external poke does NOT persist
- this 0x39F0: recalc every frame — external poke does NOT persist
- this 0x39F4: recalc every frame — external poke does NOT persist
- this 0x39F8: recalc every frame — external poke does NOT persist
- this 0x39FC: recalc every frame — external poke does NOT persist
- this 0x3A00: recalc every frame — external poke does NOT persist
- this 0x3A04: recalc every frame — external poke does NOT persist
- this 0x3A08: recalc every frame — external poke does NOT persist
- this 0x3A0C: recalc every frame — external poke does NOT persist
- this 0x3A10: recalc every frame — external poke does NOT persist
- this 0x3A18: recalc every frame — external poke does NOT persist
- this 0x3A30: recalc every frame — external poke does NOT persist
- this 0x3A34: recalc every frame — external poke does NOT persist
- this 0x3A38: recalc every frame — external poke does NOT persist
- this 0x3A3C: recalc every frame — external poke does NOT persist
- this 0x3A40: recalc every frame — external poke does NOT persist
- this 0x3A44: recalc every frame — external poke does NOT persist
- this 0x3A58: recalc every frame — external poke does NOT persist
- this 0x3A5C: recalc every frame — external poke does NOT persist
- this 0x3A60: recalc every frame — external poke does NOT persist
- this 0x3A64: recalc every frame — external poke does NOT persist
- this 0x3A68: recalc every frame — external poke does NOT persist
- this 0x3A6C: recalc every frame — external poke does NOT persist
- this 0x3A70: recalc every frame — external poke does NOT persist
- this 0x3A74: recalc every frame — external poke does NOT persist
- this 0x3A78: recalc every frame — external poke does NOT persist
- this 0x3A7C: recalc every frame — external poke does NOT persist
- this 0x3A80: recalc every frame — external poke does NOT persist
- this 0x3A9C: recalc every frame — external poke does NOT persist
- this 0x3AE8: recalc every frame — external poke does NOT persist
- this 0x3AF0: recalc every frame — external poke does NOT persist
- this 0x3AF4: recalc every frame — external poke does NOT persist
- this 0x3AFC: recalc every frame — external poke does NOT persist
- this 0x3B00: recalc every frame — external poke does NOT persist
- this 0x3B0C: recalc every frame — external poke does NOT persist
- this 0x3B10: recalc every frame — external poke does NOT persist
- this 0x3B14: recalc every frame — external poke does NOT persist
- this 0x3B54: recalc every frame — external poke does NOT persist
- this 0x3B58: recalc every frame — external poke does NOT persist
- this 0x3B5C: recalc every frame — external poke does NOT persist
- this 0x3B6C: recalc every frame — external poke does NOT persist
- this 0x3B70: recalc every frame — external poke does NOT persist
- this 0x3B74: recalc every frame — external poke does NOT persist
- this 0x3B75: recalc every frame — external poke does NOT persist
- this 0x3BE8: recalc every frame — external poke does NOT persist
- this 0x3BEC: recalc every frame — external poke does NOT persist
- this 0x3BF0: recalc every frame — external poke does NOT persist
- this 0x3BF4: recalc every frame — external poke does NOT persist
- this 0x3BF8: recalc every frame — external poke does NOT persist
- this 0x3D48: recalc every frame — external poke does NOT persist
- this 0x3D4C: recalc every frame — external poke does NOT persist
- this 0x3D50: recalc every frame — external poke does NOT persist
- this 0x3D54: recalc every frame — external poke does NOT persist
- this 0x3D58: recalc every frame — external poke does NOT persist
- this 0x3D5C: recalc every frame — external poke does NOT persist
- this 0x3D60: recalc every frame — external poke does NOT persist
- this 0x3D9C: recalc every frame — external poke does NOT persist
- this 0x3DA0: recalc every frame — external poke does NOT persist
- this 0x3DA4: recalc every frame — external poke does NOT persist
- this 0x3DCC: recalc every frame — external poke does NOT persist
- this 0x3DD0: recalc every frame — external poke does NOT persist
- this 0x3DD4: recalc every frame — external poke does NOT persist
- this 0x3FF0: recalc every frame — external poke does NOT persist
- this 0x3FF4: recalc every frame — external poke does NOT persist
- this 0x3FF8: recalc every frame — external poke does NOT persist
- this 0x3FFC: recalc every frame — external poke does NOT persist
- this 0x4000: recalc every frame — external poke does NOT persist
- this 0x4004: recalc every frame — external poke does NOT persist
- this 0x4008: recalc every frame — external poke does NOT persist
- this 0x400C: recalc every frame — external poke does NOT persist
- this 0x4010: recalc every frame — external poke does NOT persist
- this 0x4014: recalc every frame — external poke does NOT persist
- this 0x4018: recalc every frame — external poke does NOT persist
- this 0x401C: recalc every frame — external poke does NOT persist
- this 0x4020: recalc every frame — external poke does NOT persist
- this 0x4024: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e454 | flt_59E454 | R | PhysicsConstant_59E454 [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 0059e99c | flt_59E99C | R | PhysicsConversionFactor [DERIVED] (also: ` — conversion factor) |
| 0059ea58 | dbl_59EA58 | R | TireFormulaConstant [DERIVED] (also: /60/50/48 � Tire formula constants) |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 0059ec20 | flt_59EC20 | R | ForceClampMax [DERIVED] |
| 0059ed10 | dbl_59ED10 | R | TimeStepScale [DERIVED] (also: time-step scaling factor) |
| 005acafc | flt_5ACAFC | R | TemperatureOffset [DERIVED] (also: ` — additive offset) |
| 005acd44 | flt_5ACD44 | R | TireLateralForceCoeff1 [DERIVED] |
| 005acdc0 | flt_5ACDC0 | R | InterpFactor_5ACDC0 [DERIVED] |
| 005ace00 | flt_5ACE00 | R | RaceSpeedFactor [DERIVED] |
| 005aceac | flt_5ACEAC | R | MatrixRotationScaleConst [DERIVED] |
| 005acee0 | flt_5ACEE0 | R | VehicleDynamicsFloat [DERIVED] |
| 005ad184 | flt_5AD184 | R | SteeringFilterThreshold [DERIVED] |
| 005ad188 | flt_5AD188 | R | PhysicsFloatConst_5AD188 [DERIVED] |
| 005ad18c | flt_5AD18C | R | FlipbookFrameRate [DERIVED] |
| 005ad190 | dbl_5AD190 | R | UnknownDoubleConst4 [DERIVED] |
| 005ad19c | flt_5AD19C | R | TireWearDecayMult [DERIVED] |
| 005ad1a0 | flt_5AD1A0 | R | Unknown_Float_5AD1A0 [DERIVED] |
| 005ad1a8 | dbl_5AD1A8 | R | Double_Unknown_Dynamics4 [DERIVED] |
| 007c8a24 | dbl_7C8A24 | R | SteeringGeometry_dbl_7C8A24 [DERIVED] |
| 007c8a2c | dbl_7C8A2C | R | VehiclePhysicsState [DERIVED] |
| 007c8a34 | dbl_7C8A34 | R | SuspensionForceDouble [DERIVED] |
| 007d01e8 | flt_7D01E8 | R | AIDifficultyScale [DERIVED] |
| 007d0b64 | dword_7D0B64 | R | FuelMult [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |
| 008afef0 | flt_8AFEF0 | R | TemperatureOffset [CONFIRMED] (also: GlobalForceReference, ` — global force/torque reference) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ed00 | SessionStateIndexedLookup | retrieves per-session state value by index from session data array |
| 004a5330 | PitPartStateCopy | copies pit stop / part configuration state from car setup to vehicle struct |
| 004d6ae0 | VehicleSuspensionForceHelper | computes suspension spring/damper force for wheel load transfer |
| 004d7570 | CompoundIndexLookup | looks up tire compound index from tire brand data |
| 004d7880 | TireBrandLookup | retrieves tire brand/manufacturer data pointer from state flags |
| 004dd7c0 | sub_4DD7C0 | transforms a 2D direction vector through a body/mesh transform (contact point projection) |
| 004e2540 | WheelSuspensionTireStateInit | initializes per-wheel suspension and tire state for a single wheel iteration |
| 004e9bd0 | F_3x3MatrixTransformWithTranslation | applies a 3x3 matrix transform with translation offset to position data |
| 004ee150 | EngineWearFailureSimulation | simulates engine wear and failure state each frame |
| 004f1a60 | LoopWithConditionalSubCall | calls a function pointer conditionally with loop control |
| 004f3190 | QuadraticCubicPolynomialEvaluator | evaluates quadratic/cubic polynomial from parameterized coefficients |
| 004f6720 | ParameterizedCurveInterpolation | interpolates along a parameterized curve for engine/gearbox mapping |
| 004f6850 | RandomOffsetCalculator | computes a random offset value for simulation variance |
| 004f6880 | BiasValueComputation | computes a bias value for simulation parameter adjustment |
| 004f68b0 | TireForceTorqueComputation | computes tire forces and torques from slip/load parameters |
| 004f6950 | QuadraticForceModel | evaluates quadratic force model for vehicle dynamics |
| 004f69e0 | LinearVehicleParameterEvaluation | evaluates linear vehicle parameter model with interpolation |
| 004f6a50 | QuadraticForceTorqueCurveEvaluation | evaluates quadratic force/torque curve from parameterized data |
| 004f8330 | ArithmeticComparison_8330 | performs arithmetic comparison/validation on parameter block |
| 0054b420 | TripleFieldQuery | queries a 3-field position block (possibly from collision/physics engine) |
| 0054f830 | VertexParticleBufferAllocator | allocates vertex/particle buffer for contact point visualization |
| 00587bdc | CRTFtol | converts floating-point to integer (truncation) |
| 00587c03 | OperatorNewNhMallocWrapper | allocates memory (operator new with nothrow) |
| 005884ed | RandLCGRandomNumberGenerator | generates random number using linear congruential generator |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x39B0 | > | 0 | engine power/torque output: if positive, engine is producing power |
| this | 0x39F8 | >= | 2 | session state value: if >= 2, gear-dependent computation path is active |

**Guard interpretation:** `this+0x39B0 > 0` — PASSES when engine is producing positive power (throttle applied, RPM in range). BLOCKED when engine output is zero or negative (idle/off). `this+0x39F8 >= 2` — PASSES when session state indicates gear 2 or higher (car is in motion, not in neutral/reverse). BLOCKED for gears 0-1 (neutral/first, possibly pit lane or start condition).