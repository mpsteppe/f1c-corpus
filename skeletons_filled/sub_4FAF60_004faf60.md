## sub_4FAF60_004faf60 — SuspensionContactGeometryChainPropagation

**Summary:** Computes suspension contact geometry for a vehicle physics node: calculates distance vectors from reference position to linked neighbor objects, normalizes the direction, computes approach angles via atan2, and propagates cosine similarity values through a chain of up to 4 linked physics nodes. Vehicle suspension/physics system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsNodePropagationWithDistanceFalloff (00401c90), SurfaceHeightfieldCollisionCallback (00404250), MultiPhaseProcessingStateMachine (00404460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x110)+0x110)+0x110) | 0x110 | R | — | third-level linked-list next pointer — traversed in chain propagation loop |
| *(*(this+0x110)+0x110) | 0x94 | R | — | second-level node reference position X |
| *(*(this+0x110)+0x110) | 0x9C | R | — | second-level node reference position Z |
| *(this+0x10C) | 0xA4 | R | — | alternative source object position delta X (fallback path) |
| *(this+0x10C) | 0xA8 | R | — | alternative source object position delta Y (fallback path) |
| *(this+0x10C) | 0xAC | R | — | alternative source object position delta Z (fallback path) |
| *(this+0x110) | 0x94 | R | — | primary linked object reference position X (base for delta computation) |
| *(this+0x110) | 0x98 | R | — | primary linked object reference position Y |
| *(this+0x110) | 0x9C | R | — | primary linked object reference position Z |
| *(this+0x110) | 0x110 | R | — | primary linked object next pointer — head of propagation chain |
| *(this+0x114) | 0x94 | R | — | tertiary object position X — used for secondary distance calculation |
| *(this+0x114) | 0x98 | R | — | tertiary object position Y |
| *(this+0x114) | 0x9C | R | — | tertiary object position Z |
| this | 0x2C | R | — | base lateral position X (used to compute upper/lower bounds) |
| this | 0x30 | R | — | base vertical position Z (used to compute upper/lower bounds) |
| this | 0x3C | RW | — | computed vector length — magnitude of delta to primary target |
| this | 0x40 | RW | — | computed distance to tertiary object (via sqrt of delta components) |
| this | 0x50 | RW | — | computed lower bound X: base_X - 1.5 + half_width |
| this | 0x54 | RW | — | computed upper bound X: base_Z - 1.5 - half_width |
| this | 0x60 | R | — | lateral offset component X (added to base position for combined coords) |
| this | 0x64 | R | — | lateral offset component Z (added to base position for combined coords) |
| this | 0x68 | RW | — | combined lateral position X: offset_X + base_X |
| this | 0x6C | RW | — | combined lateral position Z: offset_Z + base_Z |
| this | 0x94 | R | — | local reference position X (this node's position) |
| this | 0x98 | R | — | local reference position Y |
| this | 0x9C | R | — | local reference position Z |
| this | 0xA0 | R | — | half-width / lateral offset value — used in bound computation |
| this | 0xA4 | RW | — | delta X to target — initialized from child object, then normalized |
| this | 0xA8 | RW | — | delta Y to target — initialized from child object, then normalized |
| this | 0xAC | RW | — | delta Z to target — initialized from child object, then normalized |
| this | 0xB8 | RW | 1070141403 → 1.5708f | computed approach angle (atan2 of delta); set to π/2 when delta Z is zero |
| this | 0xBC | RW | — | cosine similarity values array — 4 entries propagated through chain, clamped to min 0.02411 |
| this | 0x10C | R | — | pointer to alternative source object (used when primary is null) |
| this | 0x110 | R | — | pointer to primary linked neighbor object (head of physics chain) |
| this | 0x114 | R | — | pointer to tertiary object (used for secondary distance calculation) |
| this | 0x12C | R | — | distance threshold guard — processing blocked if >= AiOvertakeDistanceThreshold |

**Written-by note (persistence):**
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x54: recalc every frame — external poke does NOT persist
- this 0x68: recalc every frame — external poke does NOT persist
- this 0x6C: recalc every frame — external poke does NOT persist
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xB8: recalc every frame — external poke does NOT persist
- this 0xBC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e660 | flt_59E660 | R | VehicleBodyDamping [DERIVED] |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` — reverse gear throttle multiplier) |
| 005ad274 | flt_5AD274 | R | Suspension_BumpTravel [DERIVED] |
| 005ea2cc | dword_5EA2CC | R | AiOvertakeDistanceThreshold [DERIVED] — distance guard; processing only runs when this+0x12C < this value |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005894a0 | FloatFunctionPassThrough | float conversion/validation pass-through (applied to cosine similarity value before clamp) |

**Guard conditions:** 
1. this+0x12C (300) >= dword_5EA2CC (AiOvertakeDistanceThreshold): BLOCKED — entire function skipped, no geometry update.
2. this+0x110 (272) == 0: triggers fallback to this+0x10C (268) for delta vector source. If both null, delta vector remains uninitialized.
3. this+0xAC (172) == 0.0: angle set directly to π/2 (1.5708f) — special case when no vertical delta component.
4. this+0xAC (172) > 0.0: angle adjusted by adding π — wraps atan2 result.
5. Cosine similarity in chain loop: if 0.0 or >= 1.0 or < 0.02411 → clamped to minimum 0.02411.
