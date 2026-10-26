# Implementation Spec: Physics Collision Detection & Response

Source: docs/17-physics-collision.md  |  Functions: ~343 documented  |  Date: 2026-07-15

---

## Overview

The collision detection and response pipeline is F1 Challenge 99-02's system for detecting
contact between vehicles, track geometry, and other world objects, then computing appropriate
response impulses, damage, audio, and visual effects. It runs every physics tick (60 Hz)
during race and qualifying sessions.

The pipeline has three stages:

1. **Broadphase** — Spatial partitioning using a 32×32 grid and BVH trees to cull
   non-overlapping object pairs. Functions like FUN_0044d3a0 (bucket reset),
   FUN_0044aa30 (BVH traversal), and FUN_004497e0 (sweep-and-prune) manage this.
   Key globals include `DAT_007ca470` (CollisionGridSize = 4), `DAT_007cccd8` (grid size = 16),
   `DAT_007cd0c4` (max search dist = 9000).

2. **Narrowphase** — SAT (Separating Axis Theorem, FUN_004491c0), triangle proximity
   (FUN_0044b090), ray-triangle intersection (FUN_004efbd0), quadratic surface test
   (FUN_0044a070), and ray-sphere test (FUN_004dc960). These produce contact points,
   normals, and penetration depth.

3. **Contact Response** — Impulse-based resolution with Coulomb friction model
   (FUN_00436870), restitution (FUN_004584c0), spring-damper constraint solver
   (FUN_0044f6f0), and energy dissipation decay (FUN_0045b840). Results feed
   damage model (docs/03), tire model (docs/04), audio effects (DAT_007cde0c sound
   handles), and particle effects (FUN_004ce3e0 dispatch).

The system owns ~200 global state variables in the DAT_007ca000–007cdfff range,
including material property tables, spatial grid state, contact counters, and
collision sound handles. It interfaces with vehicle dynamics (docs/18) for
wheel-ground contact, the renderer (docs/19) for particle/debris effects, and
audio (docs/21) for collision sounds.

---

## Data Structures

### CollisionProxyNode (linked list node, 12 bytes)

```c
struct CollisionProxyNode {
    /* +0x00 */ void*       data;           // pointer to collision shape/proxy
    /* +0x04 */ CollisionProxyNode* next;   // next in list (null = tail)
    /* +0x08 */ uint8_t     flags;          // active/type flags
};
// Size: 12 bytes (0x0c)
// Used in: FUN_004bac20 (creator), FUN_004b4b50, FUN_004b4e10, FUN_00490d00
```

### CollisionGridCell (spatial partition entry)

```c
struct CollisionGridCell {
    /* +0x00 */ int32_t     occupancy;      // non-zero = cell occupied
    // Remaining fields depend on grid variant (4, 16, 32, 37, 49, 77, 97 cell grids exist)
};
```

### CollisionMaterialTable (2 lookup tables × 8 entries each)

```c
// Material property table (DAT_007ca388[8], float)
// Pair table B (DAT_007ca3a4[8], float, negative stride)
// Used for axis projection in BVH traversal (FUN_0044aa30, FUN_0044a450)
// Index 0-7 selects material type
// Access: tableA[index], tableB + index* -4
```

### CollisionStateBlock (per-bucket spatial state)

```c
struct CollisionStateBlock {
    /* +0x00 */ int32_t     typeId;         // 0x0e, 0x2f, 0x4b, 0x5f, etc.
    /* +0x04 */ int32_t     field0;         // zeroed
    /* +0x08 */ int32_t     field4;         // zeroed
    /* +0x0c */ int32_t     field8;         // zeroed
    /* +0x10 */ int32_t     fieldC;         // zeroed
    /* +0x14 */ int32_t     field10;        // zeroed
    // Some blocks have a 6th field at +0x18 (maxDistance = 9000 or 27000)
};
// Total size: 24 bytes (standard) or 28 bytes (with distance)
```

### ConstraintSolverState (joint/contact constraint)

```c
struct ConstraintSolverState {
    /* +0x40+ax*4 */ float  axisCoeff[3];   // per-axis scaling
    /* +0x60+ax*4 */ float  axisMin[3];     // AABB min bounds
    /* +0x398+ax*4 */ float axisMax[3];    // AABB max bounds
    /* +0xd88 */     float  primarySet[];    // primary collision geometry
    /* +0x1184 */    float  secondarySet[];  // secondary collision geometry
};
// Used in: FUN_00454250 (ConstraintForceEval), FUN_004542d0 (Swept AABB)
```

### CollisionResponseParams (large per-contact state)

```c
struct CollisionResponseParams {
    /* +0x20/24 */   float   contactParam;           // contact parameter pair
    /* +0x80 */      void*   collisionObjectVtable;  // vtable for collision object
    /* +0xac */      float   bodyCollisionBase;      // body collision coefficient
    /* +0xd8/e0/e8*/ double  position[3];            // world position
    /* +0x144 */     float   stiffnessTerm;          // spring-like constraint term
    /* +0x214 */     float   restitution;            // bounce coefficient
    /* +0x20c */     float   damping;                // velocity damping
    /* +0x21c */     float   halfExtent;             // bounding radius
    /* +0x224 */     float[9] rotationMatrix;        // body orientation
    /* +0x2b0/2d0 */ float   frictionFalloff[2];    // cos/sin friction curve
    /* +0x2e4 */     float   frictionScale;          // overall friction scalar
    /* +0x2ec */     float   rollingResistance;      // rolling resistance factor
    /* +0x31c */     float   contactForce;           // normal impulse magnitude
    /* +0x324 */     float   penetrationDepth;       // signed penetration distance
    /* +0x32c */     float   contactArea;            // contact patch size
};
// Used in: FUN_00436870 (contact generation), FUN_004584c0 (filter)
```

### CollisionImpulseAccumulator

```c
struct CollisionImpulseAccumulator {
    /* +0x560 */ double  linearImpulseX;     // accumulated linear impulse
    /* +0x568 */ double  linearImpulseY;
    /* +0x570 */ double  linearImpulseZ;
    /* +0x578 */ double  angularImpulseX;    // accumulated angular impulse
    /* +0x580 */ double  angularImpulseY;
    /* +0x588 */ double  angularImpulseZ;
};
// Used in: FUN_0044fee0
```

### MassProperties

```c
struct MassProperties {
    /* +0x180 */ uint32_t massLow;           // low 32 bits of mass (64-bit)
    /* +0x184 */ uint32_t massHigh;          // high 32 bits
    /* +0x188 */ double   invMass;           // 1.0 / mass
};
// Used in: FUN_00459950 (CollisionInvMassStore)
```

### BVHTreeNode (bounding volume hierarchy)

```c
struct BVHTreeNode {
    /* +0x08 */ int16_t   nodeIdx;           // <0 = leaf, 0 = 2D split, >0 = subtree
    /* +0x0a */ int16_t   axisIdx;           // comparison axis selector
    /* +0x0c */ void*     childPtr;          // child/sibling node pointer
    /* +0x10 */ float     minBound;          // split plane lower bound
    /* +0x14 */ float     maxBound;          // split plane upper bound
};
// Next sibling at childPtr + 0x10
// Used in: FUN_0044aa30
```

### ContactCountBuffer (ring buffer for contact timing)

```c
struct ContactCountBuffer {
    /* +0x00 */ float   accumulator;         // total elapsed time
    /* +0x04 */ float   overflowA;           // scaled overflow part A
    /* +0x08 */ float   overflowB;           // scaled overflow part B
    /* +0x0c+0x6D */ float timestamps[];     // 104 paired entries
};
// Used in: FUN_0045c7e0
```

### CollisionContactEnergy (per-contact decay)

```c
struct CollisionContactEnergy {
    /* +0x320 (stride 0x90) */ float energy;   // impact energy (decayed each tick)
    /* +0x3c */                float pos[3];    // contact position
};
// Used in: FUN_0045b840
```

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007ca470 | int | CollisionGridSize4 | 4-unit grid size init |
| DAT_007ca490 | int | CellInitialCount | Initial cell count = 1 |
| DAT_007cccd8 | int | GridSize16 | 16×16 grid |
| DAT_007cd130 | int | GridSize77 | 77-unit grid |
| DAT_007cd0c4 | float | MaxSearchDist | Broadphase search radius = 9000 |
| DAT_007cd144 | int | MaxDistance27000 | 27000 distance limit |
| DAT_007ca388 | float[8] | MaterialTableA | Material property table |
| DAT_007ca3a4 | float[8] | MaterialTableB | Material response table |
| DAT_007cde0c-2c | ptr[7] | CollisionSoundHandles | Collision sound resources |
| DAT_007cddf0-0c | ptr/int | CollisionNodeList | Linked list head/tail/counter |
| DAT_007cd614 | int | CollisionConfigVersion | Current config version |
| DAT_007ce250 | int | LatestConfigVersion | Latest config version |
| DAT_007d108c | float | PenetrationClamp | Penetration depth clamp |
| DAT_007ce994 | int | FiveContactMode | Enables 5-contact mode vs default 3 |
| DAT_007cd264 | HANDLE | CollisionMutex | Win32 mutex for thread safety |
| DAT_008afe88 | int | CollisionGeometryHandle | Global geometry handle |
| DAT_008afe90 | float | CollisionDecayRate | Energy decay constant |
| DAT_008afea0 | float | SessionTime | Current session time |
| DAT_008b8f24 | ptr | PhysicsWorldVtable | Physics/collision world interface |

---

## Public API — Entry Points

### FUN_0042c690 — PhysicsTick (main physics per-vehicle update)

**Inferred signature:** `void PhysicsTick(int vehicleIndex)`
**Called from:** Game main loop, once per vehicle per physics tick (60 Hz)
**Called by (from callers.json):** FUN_0042c690 called by higher-level game loop

**What it does:**
1. Calls FUN_004ee2d0 (brake/tire physics)
2. Calls FUN_004ed960 (integration)
3. Calls FUN_004ed810 (per-wheel force computation)
4. Calls FUN_004e4930 (suspension forces)
5. Calls FUN_004eb430 (aerodynamics)
6. Calls FUN_004f1c40 (replay/state capture)
7. Calls FUN_004bccc0 (collision detection per vehicle)
8. Calls FUN_004d5960/DAT_004d59b0 (contact processing)
9. Calls FUN_00451720 (network broadcast)

**Side effects:**
- Updates vehicle physics state (all +0x3500–+0x3d44 fields)
- Triggers collision detection pipeline
- Generates network update packets

---

### FUN_00436870 — CollisionContactGeneration (triangle mesh contact)

**Inferred signature:** `int GenerateContact(CollisionResponseParams* params, triangleMesh* mesh, float* contactOut)`
**Called from:** Narrowphase pipeline, per overlapping pair

**What it does:**
1. Reads triangle vertices from param_1+0x15c
2. Builds tangent/binormal/normal basis from triangle edges
3. Tests up to 5 contact points (3 default, 5 if DAT_007ce994 != 0)
4. For each contact: evaluates quadratic Bezier surface (FUN_0044c4c0)
5. Solves contact depth (FUN_0056c640 or FUN_004366e0)
6. Computes normal force, clamps to ≥ 0
7. Applies Coulomb friction model with slip/stick threshold
8. Computes torque from frictional forces
9. Applies damping for penetration correction via _DAT_0059e880

**Side effects:**
- Writes ContactForce (+0x31c), PenetrationDepth (+0x324)
- Writes ContactPointWorld (+0xfc-+0x100)
- Writes FrictionAccum (+0xe4/+0xec/+0xf4)

---

### FUN_004497e0 — SweepAndPrune (broadphase AABB)

**Inferred signature:** `int SweepAndPrune(int count, float* aabbs)`
**Called from:** Physics tick, per frame

**What it does:**
1. Allocates working array of count × 5 floats
2. Reads 3 positions per element, computes min/max for X/Y/Z
3. Sorts array by minX (FUN_005890aa)
4. For each overlapping X pair, checks Z overlap, then Y overlap
5. On full 3-axis overlap: calls FUN_004491c0 (SAT edge test)

---

### FUN_0045b840 — CollisionDamageDecayProcessor

**Inferred signature:** `void ProcessCollisionDamage(void* state)`
**Called from:** Per-frame after physics

**What it does:**
1. Pre-process (FUN_0045bb00), clear done flag
2. Loop 8 contact points (stride 0x5c):
   - If impact energy at +0x90 > 0: spawn spark effect (FUN_004dd030)
   - Reduce energy by _DAT_008afe90 (decay rate)
   - If energy < 0: set done flag
3. Limit to 4 active contacts per frame

**Globals:**
- `DAT_008afe90` — collision energy decay constant

---

### FUN_0045f390 — RunCollisionDetectionLoop (timed sweep)

**Inferred signature:** `int RunTimedCollisionSweep(void* param_1)`
**Called from:** Collision query dispatch; only if shape type == 3

**What it does:**
1. Sets up timer with 4.0s timeout
2. Loop: calls FUN_0057a610 (collision query)
3. On hit: calls collision response chain (FUN_004f9fc0 → FUN_0042bda0 → FUN_0042cf10 → FUN_0045c8b0)
4. Returns 1 on hit, 0 on timeout

---

### FUN_0044c4c0 — SpatialGridQuery (32×32 grid broadphase)

**Inferred signature:** `void* QuerySpatialGrid(SpatialGrid* grid, QueryState* state)`
**Called from:** Various narrowphase entry points

**What it does:**
1. If state already has valid node: calls FUN_0044a070 (narrow-phase check), returns node
2. Transforms query position to grid coordinates:
   `cellX = round((posX - originX) * invCellSize)`
   `cellZ = round((posZ - originZ) * invCellSize)`
3. Grid is 32×32: checks bounds and cell occupancy
4. If cell occupied: calls FUN_0044aa30 (BVH traversal)

---

### FUN_0045c8f0 — CollisionContactSolver

**Inferred signature:** `void SolveContact(void* state, void* contactData)`
**Called from:** Collision response pipeline

**What it does:**
1. Reads contact ID from param_2[0], validates < 104 (0x68)
2. Clears contact active flag
3. If collision threshold met: computes response via FUN_0045c7a0
4. Tracks contact count (capped at 16 per slot)
5. Calls FUN_0045cbf0 (contact callback)
6. Clamps penetration to [-DAT_007d108c, DAT_008afea0]

---

### FUN_00460dd0 — CollisionContactIteration

**Inferred signature:** `void IterateCollisionContacts(void)`
**Called from:** Per-frame collision processing

**What it does:**
1. Iterates collision objects array (stride 0x48c0, base DAT_005ec6d8)
2. For each type == 2: calls FUN_0045cbf0 (collision detection)
3. Normalizes contact ratio: `contactForce / DAT_007d108c`
4. Classifies as heavy or light contact based on thresholds
5. Dispatches heavy response (FUN_004c7a70(0)) or light (FUN_004c7a70(1))
6. Applies response via FUN_004c7aa0

---

### FUN_004ce3e0 — CollisionEffectDispatch (visual/audio)

**Inferred signature:** `void DispatchCollisionEffects(void* effectState, void* contact)`
**Called from:** Post-collision processing

**What it does:**
1. Checks weather/effect flag via FUN_004b9fb0
2. Loops contact array at param_1+0x40
3. Three effect types:
   - Type 0: tire/road spark (position delta > threshold)
   - Type 1: body/chassis impact spark
   - Type 5: heavy collision debris (no threshold)
4. Uses random offset for position jitter (DAT_008ab274)

---

### FUN_004a6b80 — CollisionAvoidanceCheck

**Inferred signature:** `int CheckCollisionAvoidance(int vehicleIndex)`
**Called from:** AI or player vehicle update

**What it does:**
1. Gets player position + direction vector
2. Normalizes, loops all vehicles
3. Dot product test against direction
4. If obstruction detected between 0 and threshold: disable collision
5. If unobstructed and previously blocked: re-enable collision

---

## Internal Call Graph

Major call chains within this system:

```
FUN_0042c690 — PhysicsTick (per-vehicle, 60 Hz)
  +-- FUN_004ee2d0 — Brake/Tire Physics
  +-- FUN_004ed960 — Vehicle Integration
  +-- FUN_004ed810 — Per-Wheel Force
  +-- FUN_004e4930 — Suspension
  +-- FUN_004bccc0 — Collision Detection per Vehicle
  |     +-- FUN_004497e0 — SweepAndPrune Broadphase
  |     |     +-- FUN_005890aa — Sort
  |     |     +-- FUN_004491c0 — SAT Edge Test
  |     +-- FUN_0044c4c0 — SpatialGridQuery
  |           +-- FUN_0044a070 — QuadraticSurfaceTest
  |           +-- FUN_0044aa30 — BVHTraversal
  |                 +-- FUN_0044a070 — ProcessLeafPrimitive
  |                 +-- (recursive self)
  +-- FUN_00436870 — ContactGeneration
  |     +-- FUN_0044c4c0 — Ray-Triangle
  |     +-- FUN_0056c640 — Plane-Line Intersection
  |     +-- FUN_004366e0 — Contact Depth Solve
  +-- FUN_0045c8f0 — ContactSolver
        +-- FUN_0045c7a0 — Response Computation
        +-- FUN_0045cbf0 — ContactCallback/Notification

FUN_00460dd0 — ContactIteration (per-frame post-physics)
  +-- FUN_0045cbf0 — Collision Detection per entity
  +-- FUN_004c7a70 — Heavy/Light Response Setup
  +-- FUN_004c7aa0 — ApplyResponse

FUN_0045b840 — DamageDecayProcessor (per-frame)
  +-- FUN_0045bb00 — Pre-process
  +-- FUN_004dd030 — Spawn Particle/Spark Effect
  +-- FUN_0045b430 — Contact Update

FUN_004ce3e0 — EffectDispatch (on collision event)
  +-- FUN_004b9fb0 — Weather/Effect Check
  +-- FUN_004cbc50 — Spark Emission
  +-- FUN_004cb620 — Debris Emission

Collision Init Chain:
FUN_0047c960 — CollisionSystemInit
  +-- FUN_0047c9d0 — Subsystem Init
  +-- FUN_004b9cb0 — Related Init
  +-- FUN_004b9cd0 — Related Init

(Multiple) FUN_0044cbf0-style — Data Registration (×20+)
  +-- FUN_00587b3e — Register Collision Data Block

(Multiple) FUN_0044d400-style — Spatial Node Init (×10+)
  Sets DAT_007cXXXX type/ID, zeroes fields

(Multiple) FUN_0044c620-style — Grid State Init (×8+)
  Sets grid size + scale

Collision Response Chain (FUN_0045f390):
FUN_0045f390 — TimedSweep
  +-- FUN_0057a5a0 — Sweep Init
  +-- FUN_0057a610 — Collision Query
  +-- FUN_004f9fc0 — Response Handler
  +-- FUN_0042bda0 — Transform/Project
  +-- FUN_0042cf10 — Constraint/Response
  +-- FUN_0045c8b0 — ContactSolver
  +-- FUN_004b0170 — Cleanup

Collision Avoidance:
FUN_004a6b80 — AvoidanceCheck
  +-- FUN_004e9630 — Track Surface Lookup
  +-- FUN_004a4030 — Enable Collision
  +-- FUN_004a4000 — Disable Collision

Collision Network Broadcast:
FUN_00462940 — BroadcastEvent
  +-- FUN_004b33b0 — Event Broadcast
  +-- FUN_0057a680 — Network Message Create
  +-- FUN_0057a6a0 — Buffer Alloc
  +-- FUN_0057a690 — Message Release
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 4.0 | FUN_0045f390 | Sweep timeout in seconds |
| 8 | FUN_0045b840 | Max contact points to process (stride 0x5c) |
| 0x68 (104) | FUN_0045c7e0 | Contact ring buffer entry count |
| 0x10 (16) | FUN_0045c8f0 | Max contact count per slot |
| 9000 | FUN_0044e300, FUN_0044d5e0 | Max broadphase search distance variant |
| 18000 | FUN_0044eae0, FUN_0044e4e0 | Max range/threshold variant |
| 27000 | FUN_0044e3c0, FUN_0044e540 | Max distance variant (grid) |
| 0x3f800000 (1.0f) | Multiple init functions | Default restitution/friction |
| 0xbf800000 (-1.0f) | Multiple init functions | Invalid/null sentinel |
| 0x20 (32) | FUN_0044c4c0 | Spatial grid dimension |
| 0x400 (1024) | FUN_0044ba40 | Raycast grid 32×32 = 1024 samples |
| 0x2c | FUN_0044da60 | Material stride (44 bytes per entry) |
| 0x20 | FUN_0044cce0 | Material stride (32 bytes per entry) |
| 0x5c | FUN_0045b840 | Contact data stride (92 bytes per contact) |
| 0x48c0 | FUN_00460dd0 | Vehicle/collision object stride |
| 0x13c | FUN_00403640 | Entity array stride (316 bytes) |
| 0x30 | FUN_00436870 | Vertex stride (rigid) |
| 0x40 | FUN_00436870 | Vertex stride (skinned) |
| 0xdeadc0de | — | Debug sentinel |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- `DAT_007c56a4` (SessionType, docs/12) — indirectly through config dispatch
- `DAT_007c569c` (SessionType5, docs/12) — server mode check in FUN_00453100
- `DAT_007c54f0` (VehiclePtrArray, docs/12) — vehicle position for avoidance
- `DAT_007cf080` (WeatherMode, docs/12) — weather/rain detection for surface grip
- `DAT_008afea0` (SessionTime, docs/12) — current race time for effect timing
- `DAT_007cde0c-2c` (CollisionSoundHandles, docs/12) — sound resource handles
- `DAT_007c54e8` (PlayerVehiclePtr, docs/12) — player vehicle pointer

**Calls into:**
- docs/10-vehicle-physics.md: FUN_004ed960 (integration), FUN_004e4930 (suspension)
- docs/04-tire-system.md: FUN_004ed810 (tire forces), FUN_004ee2d0 (brake/tire)
- docs/03-engine-wear-damage.md: collision damage triggers via effect dispatch
- docs/19-renderer.md: FUN_004ce3e0 (particle effects), FUN_004cbc50 (spark), FUN_004cb620 (debris)
- docs/20-math-utilities.md: FUN_005890aa (sort), FUN_004484c0/4f0 (vector math)
- docs/21-audio-network-internals.md: FUN_005539f0 (sound release), DAT_007cde0c handles
- docs/06-session-race-logic.md: FUN_0045be00 (penalty scaler)
- docs/09-track-system.md: FUN_004e9630 (track surface lookup)
- docs/01-engine-architecture.md: FUN_00587b3e (init/callback registration)

**Called by:**
- docs/18-physics-dynamics.md: FUN_0042c690 (main physics tick drives collision)
- docs/01-engine-architecture.md: game loop calls physics per-tick
- docs/03-engine-wear-damage.md: collision damage receives contact impulses
- docs/19-renderer.md: particle effects triggered from collision dispatch

---

## Reimplementation Notes

1. **Spatial grid architecture**: The collision system uses ~15 different grid/state block
   pairs, each initialized by a dedicated function (FUN_0044d400, FUN_0044db80, etc.).
   Each block has a type/ID field followed by 5 zeroed dwords. Some have a 6th field
   set to 9000 or 27000. These form the spatial partition for the broadphase.

2. **Material lookup**: FUN_0044a450 reads from two 8-entry tables (DAT_007ca388,
   DAT_007ca3a4) for indices 0-7, and from extended tables for indices >= 8.
   The stride pattern (negative for table B) is unusual.

3. **BVH node layout**: Nodes have a 2-byte signed node index (<0 = leaf), 2-byte
   axis selector, child pointer, and two float bounds. Next sibling is at +0x10
   from child pointer.

4. **Contact limit**: 3 contact points default, 5 if DAT_007ce994 is non-zero.
   This is a hardcoded toggle — no runtime configuration.

5. **Energy decay**: Impact energy at each decay step reduces by `_DAT_008afe90`.
   Only 4 active contacts processed per frame to spread work.

6. **Thread safety**: A Win32 mutex (DAT_007cd264) protects collision state access.
   Created via CreateMutexA, unlocked state = -1 (DAT_007cd268).

7. **Two constraint sets**: FUN_00454250 and FUN_004542d0 both have a `param_3` switch
   that selects between `+0xd88` (primary) and `+0x1184` (secondary) constraint data.

8. **Grid coordinate math**: Cell coordinate computed as
   `round((pos - origin) * invCellSize)` with 32×32 grid size.
   Fractional remainder computed as `pos - cellIndex * cellSize` via __ftol.

9. **Sin table**: FUN_0044c430 precomputes an 8-entry sin table at DAT_007ca384
   for collision normal angular calculations. Entry 7 is hardcoded to 1.0.

10. **Config version sync**: FUN_00475d30 compares DAT_007cd614 (current) vs
    DAT_007ce250 (latest). On mismatch, recalculates all collision params via
    FUN_00455bd0 and FUN_00454da0.

---

## Completeness

- Full specs written: ~50 / ~343 documented functions (major entry points + key subsystems)
- Thunks/empty stubs omitted: ~200 (registration wrappers, static init functions)
- Global state init functions summarized: ~60 (all follow same `set type → zero 5 fields` pattern)
- Confidence: **high** — the core pipeline (broadphase → narrowphase → contact → response → effects)
  is fully described. ~200 static init functions are trivial (set int, zero 4-5 fields) and
  would be replaced by a single initialization table in a reimplementation.
