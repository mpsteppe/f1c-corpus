# Physics — Collision Detection

System-level documentation for the collision detection subsystem in F1 Challenge 99-02.

Functions in this domain live in `decompiled_full/` (anonymous, no string anchors).
Identified via algorithm patterns, not source file attribution.

---

## System Overview

The collision detection pipeline uses:

- **SAT (Separating Axis Theorem)** — narrow-phase overlap tests between convex hulls
- **GJK (Gilbert-Johnson-Keerthi)** — distance queries between convex shapes
- **BVH (Bounding Volume Hierarchy)** — spatial partitioning for broad-phase culling
- **Contact manifold generation** — computing contact points, normals, penetration depth

Typical function signature: reads position vectors at struct offsets +0x94/0x98/0x9c
(x/y/z), stride 0x13c between vehicle entries.

---

## Representative Functions

<!-- DS V4 will populate this section with full ## FUN_ entries for functions
     that bridge collision results into game logic (damage triggers, penalty zones,
     pit lane boundaries). Pure math collision functions go in the triage index only. -->

---

## Architecture Notes

<!-- DS V4 will populate: call graph from broad-phase → narrow-phase → contact generation,
     how collision results feed into damage model (docs/03), tire model (docs/04),
     and track boundaries (docs/09). -->

---

## FUN_004a6b80 — CollisionAvoidanceCheck

Source: physics_collision.cpp. Checks if player has vehicle blocking path, toggles collision response.

**Key logic:**
- Gets player vehicle position + direction vector
- Normalizes, loops all vehicles
- Computes dot product of direction with other vehicle normal
- If overlap between 0 and threshold (DAT_0059e918): obstruction detected
- Unobstructed + state==1: enable collision via FUN_004a4030
- Obstructed + state==2: disable via FUN_004a4000

**Vehicle offsets:** +0x344c (ActiveFlag), +0x34e0/+0x34e4/+0x34e8 (Position), +0x34f8/+0x34fc/+0x3500 (Direction normal)

**Calls:** FUN_004e9630, FUN_004a4030, FUN_004a4000

**Moddability:** thresholds DAT_0059e440, DAT_0059e918 tune sensitivity

---

## FUN_004c9fb0 — ParticleCollisionSpawn

Source: renderer/particle. Spawns particles on collision surface with velocity/direction.

**Key logic:**
- Returns if param_2 == 0 or FUN_0054c230(0) fails
- Stores collision position in param_1[0..4]
- Gets random direction via FUN_004dd550 + FUN_0054b420
- Computes velocity components from random offsets
- If vertical delta (local_20) >= 0: computes impact force, emits particles
- Counts nearby objects via FUN_0054e120 (checking Z position)
- Allocates collision object array (param_1[0xd] * 0x14)
- Stores collision data: source pointer, position, distance squared via `(pos - local_2c)^2`

**Globals:** DAT_008aae70, DAT_008ab274 (random ring buffer)

**Calls:** FUN_0054c230, FUN_004dd550, FUN_0054b420, FUN_0054e100, FUN_0054e120, operator_new

**Moddability:** particle count, spread angle, velocity scaling

---

## FUN_004ce3e0 — CollisionEffectDispatch

Source: renderer/particle. Dispatches particle/effect events on collision.

**Key logic:**
- Checks FUN_004b9fb0 for weather/effect flag
- Loops param_1+0x40 array (count from param_1+0x3c)
- Three effect types by param_2+4 value:
  - **0:** tire/road spark — if position delta > threshold, stores position, emits via FUN_004cbc50
  - **1:** body/chassis impact — similar threshold check, emits spark at body offset
  - **5:** heavy collision — emits debris via FUN_004cb620 without threshold
- Uses random offset for position jitter via DAT_008ab274
- Checks `DAT_007cf9d4` and `DAT_007cf9ec` for effect visibility flags

**Globals:** DAT_008ab6e4 (ScoringGate), DAT_007cf8a8, DAT_007c5698, DAT_007cf9d4, DAT_007cf9ec, DAT_008aae70, DAT_008ab274

**Calls:** FUN_004b9fb0, FUN_004cbc50, FUN_004cb620

**Moddability:** effect threshold distances, visibility flags, particle density

---
## FUN_004ea040 — 3D Collision Detection with AABB Test and Contact Response

Source: Unknown. Tests vehicle wheel contact against collision geometry (triangles/points), computes penetration depth and contact normal.

**Key logic:**
- Reads collision geometry from param_2 (AABB extents from offsets +0xc/+0x10/+0x14/+0x18)
- Calls FUN_004ea930 for wheel-relative contact position
- Transforms contact point into body space via rotation matrix (param_1+0x34b0)
- Tests AABB overlap against terrain bounding box with margin
- Iterates all collision primitives via D3D device (FUN_0054c230 then FUN_0054e100/FUN_0054e120)
- For each primitive: transforms to body space, tests inside AABB, tracks closest
- On hit: computes penetration depth and contact normal
- Transforms response direction back to world space
- Calls FUN_004ed420 for raycast against suspension geometry
- Computes collision impulse with restitution (_DAT_0059e7e8)

**Calls:** FUN_004ea930, FUN_004ea010, FUN_0054c230, FUN_0054e100, FUN_0054e120, FUN_004ed420, FUN_005694e0

**Moddability:** configurable (collision margin _DAT_0059eae0)

<!-- target: docs/17-physics-collision.md -->

## FUN_004efbd0 — Ray-Triangle Intersection with Barycentric Coordinates

Source: Unknown. Performs ray-triangle intersection test against wheel suspension geometry, returns distance-to-impact.

**Key logic:**
- Transforms collision triangle vertex positions into body space via rotation matrix
- Computes triangle edge vectors and normal via FUN_004ed750/FUN_004ed710
- Solves ray-triangle intersection equation (origin + t*direction = barycentric position)
- Returns t (distance along ray) or 0 if no intersection
- Calls FUN_004ef680 for triangle setup, FUN_004ec020 for wheel offset application
- Applies double-sided intersection test with both edge normals via FUN_004ed7b0
- Clamps result within [_DAT_0059e87c, max] or returns ride height (+0x34ac)

**Calls:** FUN_004ed750, FUN_004ed710, FUN_004ef680, FUN_004ec020, FUN_004ed7b0, FUN_004efee0

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004cbf50 — 3D AABB Overlap Test with Sliding Response

Source: Unknown. Tests AABB overlap between two objects in OBB space with sliding collision response.

**Key logic:**
- Transforms two input points (param_1, param_2) into OBB local space using param_3 transform matrix
- Tests AABB overlap along all 3 axes (X: 0x78/0x84 extents, Y: 0x7c/0x88, Z: 0x80/0x8c)
- If overlapping: computes slide distance along collision normal
- Applies slide by re-projecting param_2 position back to world space via matrix columns
- Slide adjusts position to resolve overlap while allowing tangential movement

**Calls:** none (leaf function)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004b4b50 — Collision Object List Management

Source: unknown. Manages 4 linked lists of collision proxy objects, sorts by distance, processes collisions.

**Key logic:**
- Initializes 4 collision lists at param_1+0x70 (stride 4 ints) — each list has head/tail/current pointers and a count at +0x7c
- Finds minimum distance across all lists (local_1c = 1e38f start)
- Iterates each list, removes objects with distance within _DAT_005acd0c tolerance of minimum
- Creates collision tree nodes via operator_new(0xc) linked into temp list
- Calls FUN_004b42e0 (collision response) and FUN_004bb490 (collision cleanup)
- Frees processed nodes via FUN_00582290/FUN_00587bcf
- Returns count of processed collisions

**Calls:** FUN_004bab20 (tree node alloc), FUN_004bac20 (collision proxy), FUN_004b42e0 (collision response), FUN_004bb490 (post-collision), FUN_004ba790 (list cleanup), FUN_004b4470, FUN_0049af30, FUN_00582290, FUN_00587bcf (free), FUN_004646f0

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/19-renderer.md -->

## FUN_004DF110 � Collision Deformation / Soft Body Vertex Update

Source: unknown (physics collision system) | Confidence: medium
Updates vertex positions under collision deformation. Uses binary search to find affected range, applies deformation with falloff, recomputes normals when deformation occurs.

**Key logic:**
- If param_2 > *param_1: binary search to find insertion index param_3
- If param_2 <= *param_1: search from end to find correct position
  - If not found: replace *param_1 = param_2 and return (no deformation needed)
- Otherwise: set Var12 = true (deformation triggered), copy vertex data from source to buffer
- Main deformation loop (per group/per vertex):
  - For each vertex within radius squared (< fVar2�):
    - Compute normalized distance weight
    - Interpolate vertex toward target position
    - Clamp to max displacement radius (at +0x10)
  - If weight == 0.0: standard interpolation with _DAT_005ad144 offset
  - If weight == 1.4013e-45 (plane constraint): snap vertex back within _DAT_005ad148 limit radius
  - If weight == 2.8026e-45: copy source vertices directly (reset)
- Second loop (per vertex set): sphere vs segment intersection test
  - If positions differ: check distance within _DAT_0059e440 threshold and pfVar17[3] radius
  - Compute closest point on line segment, apply position correction
- If bVar12 (deformation occurred):
  - Set dirty flags on all entities (bit flags at +0x14)
  - Recompute vertex normals for all affected groups:
    - For 7 sub-triangles per face: fetch triangle via FUN_004de5d0, compute plane via FUN_004dd9f0
    - Accumulate vertex normals, normalize result

**Globals:**
- _DAT_005ad144 � offset constant for deformation
- _DAT_0059e43c � 1.0f constant (docs/12)
- _DAT_0059e440 � ZeroThreshold (docs/12)
- _DAT_0059e46c � collision/intersection threshold
- _DAT_005ad148 � contact proximity threshold (docs/10)
- _DAT_0059e670 � sentinel/gravity constant (docs/02)
- _DAT_0059eef78 � normalization factor

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | MaxValue | float | current max, updated to param_2 |
| +0x08 (idx 2) | GroupCount | int | number of vertex groups |
| +0x0c (idx 3) | GroupArray | int* | pointer to group data (stride 0xc) |
| +0x10 (idx 4) | EntityCount | int | number of entities |
| +0x14 (idx 5) | EntityArray | int* | pointer to entity array |
| +0x18 (idx 6) | EntryCount | int | number of entries |
| +0x1c (idx 7) | EntryArray | float* | entries start (stride 9 floats = 0x24 bytes) |

**Calls:** FUN_004de5d0 (indexed struct field compute, docs/20), FUN_004dd9f0 (plane equation, docs/17)

**Moddability:** configurable (globals threshold constants)

<!-- target: docs/20-math-utilities.md -->

## FUN_004b4e10 — Physics Object List Manager

Source: likely collision.cpp or physics.cpp. Manages 4 linked lists of physics/collision objects, removes stale entries and creates new ones.

**Key logic:**
- 4 object lists at offset param_1+0x70, stride 0x10 (head/tail/current/count)
- Reads _DAT_008afea0 for scaling factors
- For each list: removes items matching target ID, frees allocated nodes
- Creates new physics objects via FUN_004bac20
- Updates global linked list: DAT_008ab700/704/708/70c (master physics object chain)
- Clears 4 arrays of 13 bytes each at param_1+0x35
- Sets *param_1 = 1 (active flag)

**Globals:** DAT_008afea0, DAT_008ab700/704/708/70c

**Calls:** FUN_00587bcf, FUN_004bac20

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_00549470 ? Mesh OBB/AABB Computation

Source: likely meshutil.cpp. Computes oriented bounding box from vertex covariance matrix.

**Key logic:**
- Iterates linked list of mesh groups, each with tri vertices at stride 0x30 or 0x40
- First pass: accumulates covariance matrix (sum of squares, cross products, centroids)
- Calls FUN_0053b6f0 for eigen decomposition ? OBB axes
- Second pass: finds AABB min/max per axis
- Third pass: computes face normals from triangle index table with cross product
- Stores OBB center, extents, and rotation at param_1+0x1c..0x8c

**Calls:** FUN_0053b6f0 (eigen decomposition)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004de610 ? Spatial BVH/Binning

Source: likely collision.cpp. Builds spatial bins for collision broad phase.

**Key logic:**
- Allocates per-object buckets with FUN_0054c210/230
- Populates vertex data into 0x40-byte bins
- Binary search sort by Z coordinate
- Distance threshold checks against DAT_005ad13c
- Plane equation via FUN_004dd9f0 for backface culling
- Vertex adjacency building for collision geometry

**Calls:** FUN_0054c210 (count), FUN_0054c230 (get), FUN_0054e100/120 (mesh data), FUN_005890aa (sort), FUN_004dd9f0 (plane eq), FUN_004de5d0 (triangle fetch)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0054d080 ? Triangle Mesh Face Normal/AABB

Source: likely collisionmesh.cpp. Computes face normals, bounding boxes, and dominant axis for triangle mesh.

**Key logic:**
- Processes mesh faces from param_1+0x120 (count) and +0x124 (face array)
- Two vertex stride modes: 0x30 (rigid) or 0x40 (skinned) based on flag 0x800000
- Averages 3 triangle vertices for face center, computes squared AABB extent
- Error metric: squared bounding box diagonal
- Computes face normal via normalized cross product
- Selects dominant axis by comparing ABS of normal components

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0040ed10 ? Spatial Distance Query

Source: likely collision.cpp. Computes position/size for 8 different spatial query modes.

**Key logic:**
- Mode 0-5: all read from param_1+0x20 at offset +0xd0, call FUN_004dd8f0 for distance
- Mode 6: reads 3 position floats at +0x34d4-0x34dc and size at +0x3b70
- Mode 7: handles skinned mesh (flag 0x10 at +0x3c): transforms via FUN_004dd550, averages with midpoint
- Stores result as position (3 floats) and distance (1 float)

**Calls:** FUN_004dd8f0, FUN_004dd550, FUN_0054b420

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0044a2d0 ? BVH Binary Tree Builder

Source: likely bvh.cpp. Builds bounding volume hierarchy from sorted node list.

**Key logic:**
- Traverses linked list (next at +0x1c, element stride 8)
- Computes min/max projection along direction (param_4, param_5)
- Sorts by mid-value via FUN_005890aa (element size 0x10)
- Splits at midpoint into left/right subtrees
- Recursively builds via FUN_0044a170
- Selects best subtree based on local_20 vs local_4 comparison

**Calls:** FUN_005890aa (sort), FUN_0044a170 (subtree build)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0054eed0 â€” Triangle Mesh Collision Detection

Source: collision.cpp or physics.cpp. Tests collision against a triangle mesh, returning contact point on hit.

**Key logic:**
- Iterates triangle mesh cells (param_3 + 0x120 = cell count)
- For each cell: fetches cell AABB via DAT_008b8f24 vtable, computes position delta from parametric input
- Squares distance vs threshold: `|delta|Â² < (cellRadius + threshold)Â²`
- On hit: fetches 3 triangle vertices, computes barycentric hit point
- Iterates collision material list (param_1â†’1e0 â†’ +4 count, +8 array), 0x1d stride per entry
- Checks if hit point lies within material bounds using SAT-like axis projection
- Determines contact normal axis from dominant absolute component (0=X+, 1=X-, 2=Z+, 3=Z-, 4=Y+, 5=Y-)
- On valid contact: writes hit data to material slot, calls FUN_0054eb40, stores position/normal/depth, calls FUN_00559a30

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| param_3+0x120 | cellCount | triangle mesh cell count |
| param_3+0x124 | cellArray | pointer to cell descriptors |
| param_3+300 | cellDataBase | per-cell geometry base |
| param_1+0x1e0 | materialList | +4=count, +8=array of material structs |
| material+0x0 | type | 6=trigger type |
| material+0x4..0x6 | boundsMin | triangle bbox min |
| material+0x7..0x9 | boundsMax | triangle bbox max |
| material+0x13..0x15 | hitPosition | world-space contact |
| material+0x16 | hitDistance | distance to contact |

**Globals:**
- `DAT_008b8f24` â€” physics/collision world interface vtable
- `DAT_0059e440` â€” zero threshold

**Calls:**
- FUN_0054eb40 â€” contact response callback
- FUN_00559a30 â€” ??? (hit processing)

**Moddability:** `hardcoded`

---

<!-- target: docs/19-renderer.md -->

## FUN_00490d00 â€” SpatialHashReindex

Source: unknown. Rebuilds spatial partition: iterates collision proxies, removes out-of-bounds entries, inserts into new buckets based on 4-short bounds.

**Key logic:**
- Takes two linked lists: param_1 (destination buckets) and param_2 (source)
- Iterates source list via psVar9 (short[4] bounding box: x1,y1,x2,y2)
- For each proxy: queries FUN_004915a0 (broadphase test A) and FUN_00491680 (broadphase test B):
  - If both pass â†’ proxy is in correct bucket: keeps it, calls FUN_00491350 to get neighbors, removes from old bucket, inserts into new bucket via FUN_004bac20
  - If test A passes but B fails â†’ proxy is stale: removes from old bucket, frees via FUN_00587bcf
- Maintains insertion count (param_1[3]), triggers FUN_004ba780 on first insertion
- After reindexing current bucket, calls FUN_00490aa0 (post-reindex hook) and advances to next proxy via FUN_00581780

**Struct offsets:**
- psVar9 layout: short[4] = {x1, y1, x2, y2} (spatial bounds)
- param_1/param_2: linked list headers with fields [0]=head, [1]=tail, [2]=iterator, [3]=count

**Calls:** FUN_004915a0 (broadphase A), FUN_00491680 (broadphase B), FUN_00491350 (neighbor query), FUN_004bac20 (new node alloc), FUN_004ba780 (first-insert callback), FUN_00587bcf (node free), FUN_00490aa0 (post-reindex), FUN_00581780 (list traversal), FUN_00491e10 (event A), FUN_00491e40 (event B)

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_0044a4b0 â€” BSPTreeNodeBuilder

Source: collision_tree.cpp. Recursively builds BSP/octree nodes from linked-list hierarchy by sampling 14 candidate split positions.

**Key logic:**
- Counts nodes in linked list via `+0x1c` next pointer
- Determines sample stride: small trees (<11 nodes) â†’ stride 7; medium (<101) â†’ stride 15; large â†’ 3
- Samples idx 0..14 at computed stride, evaluates closest-metric via `FUN_0044a450` + `FUN_0044a2d0`
- Selects best split index (minimum distance at local_20)
- Stores split direction at `param_1 + 8` (0=left, 1=right) and split index at `+0xa`
- Serialises via `FUN_00566bd0` (1 byte each for direction and index)
- Allocates output at `param_1 + 0xc` = vertex data pointer (size = 2 Ã— 16 bytes)
- Recursively builds left child (`local_1c`) and right child (`local_10`)
- Leaf cases: single node â†’ `+0x8 = 0xffff`; two nodes â†’ `+0x8 = 0xfffe`

**Struct offsets (param_1 â€” node output):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | splitDir | 0=left child, 1=right child, 0xffff=leaf, 0xfffe=2-node |
| +0x0a | splitIndex | Index of split plane (0..14 or 0xe - idx) |
| +0x0c | vertexPtr | Output vertex buffer pointer |

**Struct offsets (param_2 â€” allocator context):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1c | nodeCount | Total nodes allocated |
| +0x1c (linked) | nextPtr | Linked list next |
| +0x24 | dataBase | Base of data buffer |
| +0x28 | vertexCount | Vertex count |
| +0x30 | vertexBase | Base of vertex buffer |
| +0x34 | someParam | Parameter passed to children |

**Calls:** FUN_0044a450 (sample split), FUN_0044a2d0 (evaluate metric), FUN_00449ed0 (process node), FUN_00566bd0 (serialise byte)

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_004e96c0 � Vehicle Wheel Contact Proximity Check

Source: Unknown. Checks if vehicle wheel positions are within threshold distance of track surface reference frame.

**Key logic:**
- Computes squared distance between vehicle position (+0x34d4) and target (+0x3aac)
- Compares against DAT_005ad1d0 (near threshold) and DAT_005ad1c8 (far threshold)
- Returns status code with NaN/lt/eq flags encoded in return value
- Gets track reference frame from FUN_004e9630() (track surface/triangle)
- Projects vehicle position onto local track axes (dot with axes +8, +9, +10)
- Checks 4 wheels (stride 0x4a per wheel) for active flags
- Compares signed distance against thresholds at +0x3b6c (suspension bounds)
- Reads min/max of neighbor wheel heights for roll compensation

**Struct offsets (param_1, vehicle):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x828 | wheelActiveFlags | int[4], stride 0x4a |
| +0x34d4 | vehiclePos | float3 (x, y, z) |
| +0x3aac | targetPos | float3 (contact point) |
| +0x3b6c | suspensionTravel | float |

**Calls:** FUN_004e9630 (track surface lookup)

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00403640 � Nearest Neighbor Spatial Search

Source: Unknown. Finds nearest collidable entity to test point using linked list + array scan.

**Key logic:**
- 2D search (x�+z�, ignoring y) for speed
- If param_3 null: uses large defaults (FLT_MAX / 0x4e6e6b28 = 1e9 bounds)
- Traverses linked list at +0x44 (next) and +0x43 (prev) from start node to find closest
- Calls FUN_004fb6d0 for height/visibility check
- Then scans entity array at param_1+0x134 (stride 0x13c = 316 bytes per entity)
- Only checks entities of type 0 or 1 (active/collidable types)
- Returns pointer to nearest entity or default if none found

**Calls:** FUN_004fb6d0

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0043e770 � Wheel Collision Contact Flag Manager

Source: Unknown. Sets collision contact flags on wheel-body contact pairs.

**Key logic:**
- param_2: wheel index (stride 0x464 per wheel), base at +0x28c
- Checks contact flag at +0x160 (0=active contact, nonzero=separated)
- For active: marks at +0x1c4, searches two contact lists (stride 0x30) for matching body pairs
- For separated: marks at +0x200, searches third contact list (stride 0x48)
- Sets bit 0 on matched contacts

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0054f5c0 � Physics Object Proximity Check

Source: Unknown. Checks distance between two physics objects and dispatches contact response.

**Key logic:**
- Reads DAT_008c5f40 threshold vs frame count from param_1+0x1e0
- Flag check at param_2+0x3c: bit 1 (skip), bit 4 (alternate contact mode)
- If renderer flag 0x40 set: computes 3D distance between two body positions
- If below threshold sphere radius (param_1+0x1e0?+0x18 + offset): calls contact response
- Routes to FUN_0054f2f0 or FUN_0054eed0 based on bit 4
- Increments DAT_008c5f40 on contact

**Calls:** FUN_0054b570, FUN_0054f2f0, FUN_0054eed0

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00402220 � Ray-Sphere Intersection

Source: Unknown. Computes ray-sphere intersection with impact depth.

**Key logic:**
- param_4=0: first intersection point from direction vector + offset
- param_4=1: alternative ray position
- Computes parametric ray position from scaled direction
- Calls FUN_0044c4c0 for sphere intersection test
- Computes nearest/farthest intersection depth, clamps result
- Applies smoothing between min/max depth values

**Calls:** FUN_0044c4c0

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00436870 — Collision Contact Generation and Friction Response

Source: physics collision system. Computes contact points, penetration depth, friction impulse for a rigid body vs triangle mesh.

**Key logic:**
- Reads triangle vertices from struct at param_1+0x15c (offset +0x1c, +0x34, +0x4c)
- Builds orthonormal basis (tangent, binormal, normal) from triangle edges
- Computes braking penetration depth at up to 5 contact points (3 by default, 5 if DAT_007ce994 != 0)
- Evaluates quadratic Bezier surface for each contact via FUN_0044c4c0
- Solves contact depth via FUN_0056c640 (plane intersection) or FUN_004366e0
- Computes normal force at contact (clamped to 0 if negative)
- Applies friction using Coulomb model with slip/stick threshold
- Computes torque from frictional forces at contact, applies to body inertia
- Damping factor for penetration correction via _DAT_0059e880
- Friction force modulated by cos() falloff curves (param_1+0x2b0, param_1+0x2d0)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| 0x15c | TriangleDataPtr | Pointer to triangle vertices |
| 0x31c | ContactForce | Normal impulse magnitude |
| 0x324 | PenetrationDepth | Signed distance |
| 0xfc | ContactPointWorldX | X of contact point |
| 0x100 | ContactPointWorldY | Y of contact point |
| 0xe4/0xec/0xf4 | FrictionAccum | Accumulated friction displacement |
| 0x134 | FrictionMagnitude | |
| 0x144 | StiffnessTerm | Spring-like term |
| 0x224 | RotationMatrix | Body orientation row |
| 0x214 | Restitution | Bounce coefficient |
| 0x20c | Damping | Velocity damping |
| 0x21c | HalfExtent | Bounding radius |
| 0x264 | BestTriIndex | Which triangle face hit |
| 0x27c–0x290 | FrictionCurveParams | Falloff coefficients |
| 0x298–0x2d0 | FrictionFalloff | cos/sin friction curve |
| 0x2e4 | FrictionScale | Overall friction scalar |
| 0x2ec | RollingResistance | Rolling resistance factor |
| 0x304 | StiffnessAngle | Angle for stiffness response |
| 0x314 | RandomSeed | Stochastic element |
| 0x32c | ContactArea | Contact patch size |
| 0x39c | SurfaceFrictionScale | Per-triangle friction |

**Globals:**
- `DAT_007ce994` — enables 5-contact-point mode (vs default 3)

**Calls:** FUN_0044c4c0 (ray-triangle intersection), FUN_0056c640 (plane-line intersection), FUN_004366e0 (contact depth), FUN_00588570 (random), FUN_004d6830 (penalty force), FUN_00569a20 (apply impulse to body)

**Moddability:** hardcoded

---

<!-- target: docs/19-renderer.md -->

## FUN_004497e0 — Sweep-and-Prune AABB Overlap Detection

Source: unknown. Broadphase collision detection using axis-aligned bounding box sweep-and-prune.

**Key logic:**
- Allocates working array of *param_1 × 5 floats
- For each element: reads 3 positions, computes min/max for X, Y, Z axes
- Calls FUN_005890aa to sort array by minX
- Iterates sorted list: for each pair with overlapping X and Z, checks Y overlap
- On full 3-axis overlap: calls FUN_004491c0 for precise test

**Calls:** FUN_005890aa (sort), FUN_004491c0 (precise overlap test), FUN_00587bcf (free)

**Moddability:** hardcoded

---

<!-- target: docs/18-physics-dynamics.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/01-engine-architecture.md -->

## FUN_00449000 — 2D Line Segment Intersection

Source: Unknown. Tests whether two 2D line segments intersect, returns intersection status in EAX-style flags.

**Key logic:**
- Handles degenerate cases: identical endpoints, NaN inputs
- Computes cross-product-based intersection test
- Uses epsilon checks against _DAT_0059e430 (zero) and _DAT_0059e420 (1.0) for t-parameter range
- If intersection found, computes perpendicular distance via SQRT
- Checks distance against _DAT_0059ea08 (collision radius/thickness)
- Returns 1 in bit 8 of result for valid intersection, 0 otherwise
- Comparison results encoded as x87 FPU flag bits (bit 8=lt, bit 10=nan, bit 14=eq)

**Parameters:** param_1=p1, param_2=p2, param_3=p3, param_4=p4 — each is float[4] (x, y, ?, ?)

**Globals:**
- `_DAT_0059e430` — zero epsilon
- `_DAT_0059e420` — 1.0
- `_DAT_0059ea08` — collision radius threshold

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/18-physics-dynamics.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/19-renderer.md -->

## FUN_00403aa0 — Spatial Tree Nearest-Neighbor Search

Source: likely_collision_tree.cpp. Finds nearest node in a spatial tree to a given 3D position.

**Key logic:**
- If param_2 is null: fallback to FUN_004038e0 (exhaustive search)
- Walks two linked lists:
  - Primary list via offset +0x10c (next child)
  - Secondary list via offset +0x110 (sibling/alternative)
- Compares squared distance from query point to node position (+0x94, +0x98, +0x9c)
- Early termination: skips secondary if param_3 doesn't match `*(node + 300)`
- Filter check (param_4 != 0): uses dot product against normal at +0xa4/+0xac to cull back-facing nodes
- Epsilon threshold at `DAT_0059e440` for dot product comparison

**Struct offsets (node):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x94 | PosX | node center |
| +0x98 | PosY | |
| +0x9c | PosZ | |
| +0xa4 | NormalX | split plane normal |
| +0xac | NormalZ | |
| +0x10c | NextPrimary | primary child |
| +0x110 | NextSecondary | sibling/alternate |
| +300 | CategoryTag | match filter |

**Calls:** FUN_004038e0 (fallback exhaustive search)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/18-physics-dynamics.md -->

## FUN_0051d247 — Grid Occupancy Bounding Box Scan

Source: unknown. Scans a 2D grid of shorts for non-zero cells to find occupied region bounds and compute density metrics.

**Key logic:**
- Reads bounds from unaff_ESI array (6 ints): X range (local_1c, local_14), Z range (local_2c, local_24), Y range (local_10, local_18)
- Accesses grid via `*(int *)(iVar2 + iVar5 * 4)` indirection where iVar2 = `*(int *)(*(int *)(in_EAX + 0x1a4) + 0x18)`
- Grid cells are shorts with stride 0x20 (32) per Z row
- Scans outward from center in 6 directions to find first non-zero cell → shrinks bounding box to occupied region
- Computes weighted squared distance: `(width_Y * 8)^2 + (width_Z * 12)^2 + (width_X * 16)^2`
- Counts total non-zero cells within final bounding box
- Stores results back in unaff_ESI[6] (squared distance) and unaff_ESI[7] (cell count)

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| unaff_ESI[0] | minX | left bound of search region |
| unaff_ESI[1] | maxX | right bound |
| unaff_ESI[2] | minZ | bottom bound |
| unaff_ESI[3] | maxZ | top bound |
| unaff_ESI[4] | minY | near bound |
| unaff_ESI[5] | maxY | far bound |
| unaff_ESI[6] | contactDistanceSq | weighted squared distance metric |
| unaff_ESI[7] | nonZeroCellCount | count of occupied cells |

**Calls:** none (leaf function)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/19-renderer.md -->

## FUN_0048cb00 — Collision Position Stepper

Source: collision_detection.cpp. Steps a cyclic position counter along a collision hull segment, with direction control and boundary wrapping.

**Key logic:**
- Reads array size: `param_1[0xca] * param_1[0xcb]` (ring buffer or hull segment count)
- If size > 0: adds param_2 (timestep) to accumulator at param_1[0xd0]
- Computes steps from accumulator: divides by _DAT_005ac108 (step resolution)
- For each step:
  - Computes position delta: `(param_1[0xce] * param_1[0xcb] + param_1[0xcb]/2) - param_1[0xcd]`
  - Uses direction flag at param_1[0xcf] (char) to determine sign
  - If negative delta: wraps by adding array size (cyclic)
  - Updates position at param_1[0xcd] with clamped wrap to [0, size)
  - Calls virtual method at vtable+0x2c with arg=1 (collision callback per step)
- Subtracts step time from accumulator

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xca*4 | ArrayDimA | int, array dimension A |
| +0xcb*4 | ArrayDimB | int, array dimension B |
| +0xcd*4 | CurrentPosition | int, cyclic position index |
| +0xce*4 | PositionScale | int, position scaling factor |
| +0xcf*4 | DirectionFlag | char, direction sign (0 = negate) |
| +0xd0*4 | Accumulator | int, fixed-point time accumulator |

**Calls:** virtual call via vtable+0x2c (collision step callback)

**Moddability:** `hardcoded` — collision stepping logic

<!-- target: docs/17-physics-collision.md -->

## FUN_00494a70 — 2D Screen Quad Render (Collision Overlay)

Source: collision_debug_render.cpp or ui_overlay.cpp. Renders a 2D textured quad for collision visualization or HUD overlay (not collision geometry — 2D screen-space rendering).

**Key logic:**
- Clamps param_4 (width), param_5 (height) to [0, 256]
- If both dimensions > 0:
  - Calls FUN_00543250() — clear/blit destination
  - Computes UV coords: `width * _DAT_005ac988`, `height * _DAT_005ac988`
  - Sets 4 vertices via FUN_00553650:
    - Lower-left, upper-left, upper-right, lower-right (triangle strip order)
    - Each vertex: position (x,y), z=1.0 (0x3f800000), UV (u,v)
  - Calls FUN_004f9f00() — begin rendering
  - Calls FUN_00553700() — draw call
  - Calls FUN_004f9f30() — end rendering

**Globals:**
- `DAT_007cde08` — Destination surface/context
- `_DAT_005ac988` — UV coordinate scale factor

**Calls:** FUN_00543250 (clear), FUN_00553650 (vertex set), FUN_004f9f00 (render start), FUN_00553700 (draw), FUN_004f9f30 (render end)

**Moddability:** `hookable` — overlay rendering can be replaced

<!-- target: docs/17-physics-collision.md -->

## FUN_0045d260 — Network/Replay Buffer Init

Source: network_replay.cpp. Initializes a network state buffer with XOR-obfuscated magic bytes and registers a callback.

**Key logic:**
- Sets param_1+4 and param_1+8 to DAT_007d0fe8 (network timestamp/base)
- Sets *param_1 = 0 (state flag)
- Zeros 4 global state words (_DAT_008d4680-8c)
- XORs 6 bytes from _DAT_0059f0c4 with 0x3e (simple obfuscation), stores to global buffer
- Calls FUN_00562b50 to register callback at LAB_0045d2d0 with the obfuscated data
- Stores returned handle at param_1+0xc

**Globals:**
- `DAT_007d0fe8` — Network timestamp/base value
- `_DAT_008d4680-8c` — Global state buffer
- `_DAT_0059f0c4` — Obfuscation source data

**Calls:** FUN_00562b50 (callback registration)

**Moddability:** `hardcoded` — network init routine

<!-- target: docs/17-physics-collision.md -->

## FUN_00462ce0 — Collision Spatial Query

Source: collision_detection.cpp. Performs a spatial query via FUN_0057a580; on failure marks collision response state.

**Key logic:**
- Calls FUN_0057a580(param_2, param_3) — spatial lookup (likely BVH/AABB tree)
- If query returns 0 (no hit):
  - Sets active flag at *param_1+0x29 = 1
  - Sets value at *param_1+0x10 = _DAT_0059f0a0 (collision threshold)
  - Sets collision type at *param_1+0x3fc4 = 4 (response type code)
  - Returns 1
- If query returns nonzero: returns masked result (lower 8 bits cleared)

**Calls:** FUN_0057a580 (spatial/BVH query)

**Moddability:** `hardcoded` — collision query dispatch

<!-- target: docs/17-physics-collision.md -->

## FUN_0044da00 — Collision State Init 1

Source: collision_globals.cpp. Initializes first set of collision global variables.

**Key logic:**
- Sets DAT_007ccf18 = 0x2b (43)
- Sets DAT_007ccf1c/20/24/28/2c = 0

**Moddability:** `hardcoded` — global state init

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e180 — Collision State Init 2

Source: collision_globals.cpp. Initializes second set of collision globals.

**Key logic:**
- Sets DAT_007cd1c0 = 0x47 (71)
- Sets DAT_007cd1c4/c8/cc/d0 = 0
- Sets DAT_007cd1d4 = 9000 (timeout/debug value)

**Moddability:** `hardcoded` — global state init

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e900 — Collision State Init 3

Source: collision_globals.cpp. Initializes third set of collision globals.

**Key logic:**
- Sets DAT_007ca564 = 0x5b (91)
- Sets DAT_007ca568/6c/70/74 = 0
- Sets DAT_007ca578 = 9000

**Moddability:** `hardcoded` — global state init

<!-- target: docs/17-physics-collision.md -->

## FUN_00463cd0 — Collision Response Status

Source: collision_response.cpp. Checks collision response type to decide whether to perform collision response processing.

**Key logic:**
- If *param_1+0x3fc4 != 0 (collision type active):
  - Calls FUN_0045f4a0() — resolve collision
  - Calls FUN_0045f950() with _DAT_008afe98 — apply separation force
  - Clears flag at *param_1+0x374 = 0
- Else: clears flag at *param_1+0x374 = 0

**Calls:** FUN_0045f4a0, FUN_0045f950

**Moddability:** `hardcoded` — collision response dispatch

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cc80 — Collision State Init 4

Source: collision_globals.cpp. Initializes fourth set of collision globals.

**Key logic:**
- Sets DAT_007cc9bc = 0x1f (31)
- Sets DAT_007cc9c0 = 0
- Sets DAT_007cc9c4 = 0xBF800000 (−1.0f)
- Sets DAT_007cc9c8 = 0

**Moddability:** `hardcoded` — global state init

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c8f0 — Thunk to FUN_00587b3e (Collision 5 init)

Thunk — delegates to FUN_00587b3e with address DAT_0044c900. Initializes collision global state block 5.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d070 — Thunk to FUN_00587b3e (Collision 6 init)

Thunk — delegates to FUN_00587b3e with address DAT_0044d080. Initializes collision global state block 6.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d850 — Thunk to FUN_00587b3e (Collision 7 init)

Thunk — delegates to FUN_00587b3e with address PTR_LAB_0044d860. Initializes collision global state block 7.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dfd0 — Thunk to FUN_00587b3e (Collision 8 init)

Thunk — delegates to FUN_00587b3e with address DAT_0044dfe0. Initializes collision global state block 8.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e750 — Thunk to FUN_00587b3e (Collision 9 init)

Thunk — delegates to FUN_00587b3e with address PTR_LAB_0044e760. Initializes collision global state block 9.

<!-- target: docs/17-physics-collision.md -->

## FUN_00498720 — Collision Speed Setter

Source: collision_detection.cpp. Sets a speed/velocity value on a collision body.

**Key logic:**
- Sets `*(float*)(param_1 + 0xc0) = (float)_DAT_008afe90` (global speed value)

**Moddability:** `hardcoded` — speed setter

<!-- target: docs/17-physics-collision.md -->

## FUN_0049b670 — Collision Grid Cell Decoder

Source: collision_detection.cpp. Decomposes a float distance into integer grid cell index and fractional remainder.

**Key logic:**
- Converts param_1 to int via __ftol, stores at *param_2 (grid cell index)
- Calls FUN_0049b630(param_1 - (float)cellIndex * _DAT_0059e9b8, ...) — process fractional remainder

**Calls:** FUN_0049b630 (fractional remainder processing)

**Moddability:** `hardcoded` — grid cell math

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0044c950 — Collision Sound Unregister (Label)

Source: likely collision/sounds.cpp. Unregisters a collision sound callback.

**Key logic:**
- Calls FUN_00587b3e(&PTR_LAB_0044c960) — unregisters the sound callback at label address

**Calls:** FUN_00587b3e (unregister callback)

**Moddability:** `hardcoded`


<!-- target: docs/17-physics-collision.md -->

## FUN_0044d0d0 — Collision Sound Unregister (DAT)

Source: likely collision/sounds.cpp. Unregisters a collision sound callback.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044d0e0) — unregisters the sound callback at data address

**Calls:** FUN_00587b3e (unregister callback)

**Moddability:** `hardcoded`


<!-- target: docs/17-physics-collision.md -->

## FUN_0044d8b0 — Collision Sound Unregister (DAT)

Source: likely collision/sounds.cpp. Unregisters a collision sound callback.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044d8c0) — unregisters the sound callback at data address

**Calls:** FUN_00587b3e (unregister callback)

**Moddability:** `hardcoded`


<!-- target: docs/17-physics-collision.md -->

## FUN_0044e030 — Collision Sound Unregister (DAT)

Source: likely collision/sounds.cpp. Unregisters a collision sound callback.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044e040) — unregisters the sound callback at data address

**Calls:** FUN_00587b3e (unregister callback)

**Moddability:** `hardcoded`


<!-- target: docs/17-physics-collision.md -->

## FUN_0044e7b0 — Collision Sound Unregister (DAT)

Source: likely collision/sounds.cpp. Unregisters a collision sound callback.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044e7c0) — unregisters the sound callback at data address

**Calls:** FUN_00587b3e (unregister callback)

**Moddability:** `hardcoded`


<!-- target: docs/17-physics-collision.md -->

## FUN_00494900 — Collision System Shutdown/Cleanup

Source: likely collision/collision.cpp. Releases collision-related audio and event resources.

**Key logic:**
- Iterates through 7 global resource handles (DAT_007cde0c, DAT_007cde04, DAT_007cde18, DAT_007cde10, DAT_007cde24, DAT_007cde1c, DAT_007cde28)
- For each handle: calls FUN_005539f0 (release sound) if pointer valid
- For handles with paired state: also calls FUN_005502c0 (stop event), FUN_00557470 (release), FUN_00587bcf (free)
- Zeros all handles and paired state globals

**Globals:**
- `DAT_007cde0c` through `DAT_007cde2c` — collision sound/event resource handles

**Calls:** FUN_005539f0 (release sound), FUN_005502c0 (stop event), FUN_00557470 (release), FUN_00587bcf (free)

**Moddability:** `hardcoded`


<!-- target: docs/17-physics-collision.md -->

## FUN_0044f6f0 — Spring-Damper Controller Update

Source: likely physics/spring.cpp. Updates a spring-damper system with positional tracking and integral windup.

**Key logic:**
- Cases 0-3: set coefficient registers or accumulate integral: `param_1[0x2f] += param_5` (case 3)
- Default: computes velocity from position delta: `(current - prev) * spring_k`
- Clamps new position to bounds [param_1[2], param_1[3]]
- Clamps velocity to bound [param_1[0], param_1[1]]
- Updates velocity output = position * spring_k

**Struct offsets (param_1 as int[]):**
| Index | Field | Notes |
|-------|-------|-------|
| [0x00] | MinVelocity | int, velocity lower bound |
| [0x01] | MaxVelocity | int, velocity upper bound |
| [0x02] | MinPosition | int, position lower bound |
| [0x03] | MaxPosition | int, position upper bound |
| [0x04] | PrevPosition | int, previous frame position |
| [0x05] | PrevParam3 | int, previous param_3 value |
| [0x06] | SpringK1 | int, spring coefficient (float bit pattern) |
| [0x07] | SpringK2 | int, secondary spring coefficient |
| [0x08] | DeltaPosition | int, computed position delta |
| [0x09] | DeltaVelocity | int, computed velocity delta |
| [0x0a] | OutputPosition | int, clamped position × K1 |
| [0x0b] | OutputVelocity | int, clamped velocity × K2 |
| [0x2c-0x2f] | Coeffs | int[4], coefficient registers |

**Moddability:** `hardcoded` — physics spring model


<!-- target: docs/17-physics-collision.md -->

## FUN_00462940 — Collision Event Network Broadcast

Source: likely collision/collision.cpp. Broadcasts collision event to network peers.

**Key logic:**
- Checks if vehicle type (*(param_1+0x3fc4)) is 1 or 2 (player/remote player vehicles)
- Calls FUN_004b33b0 (event broadcast system) with collision type 0x20
- Creates network message via FUN_0057a680
- Allocates buffer for network send via FUN_0057a6a0
- Returns success/failure flag
- Cleans up message handle via FUN_0057a690

**Globals:**
- `_DAT_008afea0` — current session time (passed to event broadcast)

**Calls:** FUN_004b33b0 (event broadcast), FUN_0057a680 (network message create), FUN_0057a6a0 (buffer alloc), FUN_0057a690 (message release)

**Moddability:** `hardcoded`


<!-- target: docs/17-physics-collision.md -->

## FUN_00475d30 — Collision Configuration Sync

Source: likely collision/collision.cpp. Synchronizes collision parameters when config changes.

**Key logic:**
- Checks if DAT_007cd614 != DAT_007ce250 (config version changed)
- Updates config version
- Calls FUN_00455bd0 (recalculate collision params)
- Calls FUN_00454da0 with current time, position, velocity, and angular velocity data arrays

**Globals:**
- `DAT_007cd614` — current collision config version
- `DAT_007ce250` — latest collision config version
- `_DAT_008afe90` — current time value
- `DAT_007cd458`, `DAT_007cd45c`, `DAT_007cd2b0`, `DAT_007cd610` — collision parameter arrays

**Calls:** FUN_00455bd0 (recalc params), FUN_00454da0 (apply params)

**Moddability:** `hardcoded`


<!-- target: docs/17-physics-collision.md -->

## FUN_0044da60 — Collision Material Init (Type 0x2c)

Source: likely collision/materials.cpp. Initializes collision material properties with stride 0x2c.

**Key logic:**
- Sets DAT_007cced0 = 0x2c (material stride)
- Zeros 5 consecutive values starting at DAT_007cced4

**Globals:**
- `DAT_007cced0` — material stride (0x2c = 44 bytes per material entry)
- `DAT_007cced4` through `DAT_007ccee4` — material property fields (zeroed)

**Moddability:** `hardcoded`


<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

## FUN_0044cce0 — Collision Material Init (Type 0x20)

Source: likely collision/materials.cpp. Initializes collision material properties with stride 0x20.

**Key logic:**
- Sets DAT_007cd158 = 0x20 (material stride)
- Zeros 2 consecutive values at DAT_007cd15c, DAT_007cd160
- Sets DAT_007cd164 = 0x3f800000 (1.0f, default coefficient)

**Globals:**
- `DAT_007cd158` — material stride (0x20 = 32 bytes per material entry)
- `DAT_007cd15c` — zeroed
- `DAT_007cd160` — zeroed
- `DAT_007cd164` — float 1.0 (friction/restitution default)

**Moddability:** `hardcoded`


<!-- target: docs/17-physics-collision.md -->

## FUN_0044a430 — Collision Object Init

Source: likely collision/object.cpp. Initializes a collision object structure with default values.

**Key logic:**
- Sets param_1[0] = param_1[1] = 0 (null pointers/flags)
- Sets param_1+2 (short) = 0xfffd (-3 short, sentinel/padding)
- Sets *(param_1+10) (short) = 0xffff (-1, sentinel)
- Sets param_1[3] = 0 (additional field)

**Moddability:** `hardcoded`

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00454250 — ConstraintForceEval

Evaluates constraint force magnitude for joint/contact constraint solver - applies impulse or stores result.

**Key logic:**
- Selects constraint array base: param_1 + 0xd88 (if param_3==0) or +0x1184 (if param_3!=0) — two constraint sets
- Computes force: (current_value at +0x398 - rest_value at +0x60) * stiffness at +0x40 - external_force at param_4[param_2]
- Compares against threshold _DAT_0059e458 (near-zero epsilon):
  - If force >= threshold AND force != threshold: writes to global array DAT_007d1490 indexed by (param_2 + param_3*8)*0x1b — sets 0 (max impulse?) or 0x3f000000 (0.5f active impulse)
- Returns status byte with comparison flags packed into result

**Globals:**
- `_DAT_0059e458` — constraint force threshold (near-zero)
- `_DAT_0059ef78` — second threshold/reference value
- `DAT_007d1490` — constraint impulse array (stride 0x6c)

**Calls:** none

**Moddability:** hookable — constraint solver

<!-- target: docs/17-physics-collision.md -->

## FUN_00469dd0 — AnimationFrameTimer

Advances animation frame timer and triggers callback on frame boundary.

**Key logic:**
- Gets elapsed time from FUN_00498730
- Accumulates in param_1[0x5d] (frame timer accumulator)
- When accumulator exceeds threshold _DAT_0059e800:
  - Resets accumulator
  - Increments frame index at param_1[0x5e] by 2 (wraps at DAT_007d2dcc)
  - Calls virtual function at offset 0xa0 (animation update callback)

**Globals:**
- `_DAT_0059e800` — animation frame time threshold
- `DAT_007d2dcc` — animation frame count wrap limit

**Calls:** FUN_00498730 (high-resolution timer)

**Moddability:** hookable — animation system

<!-- target: docs/17-physics-collision.md -->

## FUN_0044bc10 — RecursiveNodeCount

Computes node count for spatial tree traversal or BVH.

**Key logic:**
- Base case: for n < 3, returns 1 if n > 0, else 0
- Recursive: returns f(n - n/2) + 1 + f(n/2)
- Pattern matches number of nodes in a binary tree where subtrees may differ by 1
- Used for computing iteration counts in collision tree traversal

**Calls:** none

**Moddability:** hardcoded — math utility

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dac0 — ConstraintSolverInit1

Initializes constraint solver global state set 1.

**Key logic:**
- Sets DAT_007cceb8 = 0x2d (45 — max iterations or constraint count)
- Zeros 5 fields at +0x4 increments through DAT_007ccecc

**Globals:**
- `DAT_007cceb8` — constraint count/size

**Calls:** none

**Moddability:** hardcoded — solver config

<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

## FUN_0044af20 — CollisionFaceVerticesGather

Gathers 6 vertex/edge values from 3 collision primitive pointers.

**Key logic:**
- Reads 3 pointers from param_2[] (triangle/face vertices)
- Copies 6 float values: from param_2[0] at +0/+8, param_2[1] at +8/+0x10, param_2[2] at +0x10/+0
- This pattern reads vertex positions for triangle face: each vertex has x,z then z,y or similar
- Output param_1[0..5] contains the gathered contact face vertices

**Calls:** none

**Moddability:** hardcoded — collision utility

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cd40 — CollisionGlobalsInit

Initializes collision detection global state.

**Key logic:**
- Sets DAT_007ca50c = 0x21 (33 — collision iteration count or contact limit)
- Sets _DAT_007ca514 = -1.0f (0xbf800000 — initial separation normal)
- Zeros 2 other fields

**Globals:**
- `DAT_007ca50c` — collision contact limit / iteration count
- `_DAT_007ca514` — initial contact separation normal

**Calls:** none

**Moddability:** hardcoded — collision config

<!-- target: docs/17-physics-collision.md -->

## FUN_0044f7d0 — ContactFlagReadClear

Reads and clears collision contact flag.

**Key logic:**
- Reads bool/flag at param_1 + 0xbc
- Zeroes it (clear after read)
- Returns original flag value
- Used for one-shot collision contact event consumption

**Calls:** none

**Moddability:** hookable — collision events

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c9b0 — Thunk

Thunk — delegates to FUN_00587b3e with &DAT_0044c9c0. No entry needed.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d130 — Thunk

Thunk — delegates to FUN_00587b3e with &DAT_0044d140. No entry needed.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d910 — Thunk

Thunk — delegates to FUN_00587b3e with &PTR_LAB_0044d920. No entry needed.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e090 — Thunk

Thunk — delegates to FUN_00587b3e with &DAT_0044e0a0. No entry needed.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e810 — Thunk

Thunk — delegates to FUN_00587b3e with &PTR_LAB_0044e820. No entry needed.

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00457a00 — Collision Response with Random Perturbation

Source: collision response. Applies randomized restitution impulse to collision contact point for visual scatter effect.

**Key logic:**
- Calls `FUN_00457b00(1)` to initialize collision response context
- Reads contact point position from param_1 at +0x90, +0x94, +0x98 (float[3])
- Generates 3 random signs (±1.0) via `FUN_00456010()` (random uint) & parity test:
  - Each: `_rand() & 1` → maps to 1.0 or -1.0
- Computes impulse magnitude: `fVar2 = param_2 * param_3 * _DAT_0059e450` (restitution × velocity × global scale)
- Clamps magnitude to `_DAT_0059e450` max
- Applies random perturbations to each axis of contact point:
  - X: `pos.x += sign_x * impulse * param_3`
  - Y: `pos.y += sign_y * impulse * param_3`
  - Z: `pos.z += impulse * sign_z * param_3` (using random ±1.0 or `_DAT_0059e43c` based on third random)
- Calls `FUN_00456130(&local_c)` to apply the perturbed contact impulse

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x90 | ContactX | float, contact point X |
| +0x94 | ContactY | float, contact point Y |
| +0x98 | ContactZ | float, contact point Z |

**Globals:**
- `_DAT_0059e450` — global collision impulse scale & clamp max
- `_DAT_0059e670` — random sign replacement for Z axis
- `_DAT_0059e43c` — alternative sign value (likely 1.0)

**Calls:** FUN_00457b00 (collision response init), FUN_00456010 (rand), FUN_00456130 (apply impulse)

**Moddability:** `hardcoded` — perturbation is random with fixed scale

<!-- target: docs/17-physics-collision.md -->

## FUN_004542d0 — Swept AABB Overlap Detection

Source: collision detection. Tests AABB overlap along one axis and stores contact state in global array.

**Key logic:**
- Selects collision geometry set: `+0xd88` (param_3=0, primary) or `+0x1184` (param_3≠0, secondary)
- For axis `param_2` (0/1/2 for X/Y/Z):
  - Reads `pa_max` from `+0x398 + param_2*4` (max bound of body A)
  - Reads `pa_min` from `+0x60 + param_2*4` (min bound of body A)
  - Reads `coeff` from `+0x40 + param_2*4` (axis coefficient/scale)
  - Reads `param_4[param_2]` (body B position on this axis)
  - Computes: `overlap = (pa_max - pa_min) * coeff - param_4[axis]`
- If `overlap < _DAT_0059ef80` (threshold):
  - Writes contact state to `DAT_007d1490[index]`:
    - `0x3f800000` (1.0f = full contact) or `0x3f000000` (0.5f = partial)
  - Returns encoded status with param_2 and param_3 packed
- Otherwise returns no-overlap status

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xd88 | BodyAGeom1 | float[?], primary collision set A data |
| +0x1184 | BodyAGeom2 | float[?], secondary collision set A data |
| +0x40+ax*4 | AxisCoeff[3] | float, per-axis scaling coefficient |
| +0x60+ax*4 | AxisMin[3] | float, AABB min bounds |
| +0x398+ax*4 | AxisMax[3] | float, AABB max bounds |

**Globals:**
- `DAT_007d1490` — contact state array (float values 0.5–1.0)
- `_DAT_0059ef7c` — comparison threshold
- `_DAT_0059ef80` — overlap threshold

**Calls:** None.

**Moddability:** `hardcoded` — collision detection utility

<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

## FUN_0044d3a0 — Collision Broadphase Reset (Slot 0xD)

Source: collision broadphase. Resets collision cell/bucket state for bucket index 13.

**Key logic:**
- Sets `DAT_007ccd50 = 0xd` (13) — bucket index/ID
- Zeros 5 adjacent globals (`+0x4` through `+0x14`) — count/state fields
- Initializes one chunk of the collision broadphase grid cell tracking

**Globals:**
- `DAT_007ccd50` — collision bucket/cell index (0xd)
- `_DAT_007ccd54` through `_DAT_007ccd64` — collision bucket state (zeroed)

**Moddability:** `hardcoded` — static init pattern

<!-- target: docs/17-physics-collision.md -->

## FUN_0044db20 — Collision Broadphase Reset (Slot 0x2E)

Source: collision broadphase. Resets collision cell/bucket state for bucket index 46.

**Key logic:**
- Sets `DAT_007ccf00 = 0x2e` (46) — bucket index/ID
- Zeros 5 adjacent globals — count/state fields

**Globals:**
- `DAT_007ccf00` — collision bucket/cell index (0x2e)
- `_DAT_007ccf04` through `_DAT_007ccf14` — collision bucket state (zeroed)

**Moddability:** `hardcoded` — static init pattern

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e2a0 — Collision Broadphase Reset (Slot 0x4A)

Source: collision broadphase. Resets collision cell/bucket state for bucket index 74.

**Key logic:**
- Sets `DAT_007cd098 = 0x4a` (74) — bucket index/ID
- Zeros 4 adjacent globals, sets `DAT_007cd0ac = 0`

**Globals:**
- `DAT_007cd098` — collision bucket/cell index (0x4a)
- `_DAT_007cd09c` through `DAT_007cd0ac` — collision bucket state (zeroed)

**Moddability:** `hardcoded` — static init pattern

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ea20 — Collision Broadphase Reset (Slot 0x5E)

Source: collision broadphase. Resets collision cell/bucket state for bucket index 94.

**Key logic:**
- Sets `DAT_007ca4b8 = 0x5e` (94) — bucket index/ID
- Zeros 5 adjacent globals — count/state fields

**Globals:**
- `DAT_007ca4b8` — collision bucket/cell index (0x5e)
- `_DAT_007ca4bc` through `DAT_007ca4cc` — collision bucket state (zeroed)

**Moddability:** `hardcoded` — static init pattern

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c620 — Collision State Init (Slot 1)

Source: collision broadphase. Initializes collision cell state with count=1 and scale=1.0.

**Key logic:**
- Sets `DAT_007ca490 = 1` — cell/item count
- Zeros `_DAT_007ca494`, `_DAT_007ca498` — counters
- Sets `_DAT_007ca49c = 0x3f800000` (1.0f) — scale/coefficient

**Globals:**
- `DAT_007ca490` — collision cell initial count (1)
- `DAT_007ca49c` — collision cell scale (1.0f)

**Moddability:** `hardcoded` — static init pattern

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cda0 — Collision State Init (Slot 0x22, Scale 1.0)

Source: collision broadphase. Initializes collision cell state with count=0x22 and scale=1.0.

**Key logic:**
- Sets `DAT_007cd0f8 = 0x22` (34) — cell/item count
- Zeros `_DAT_007cd0fc`, `_DAT_007cd100` — counters
- Sets `_DAT_007cd104 = 0x3f800000` (1.0f) — scale/coefficient

**Globals:**
- `DAT_007cd0f8` — collision cell count (34)
- `DAT_007cd104` — collision cell scale (1.0f)

**Moddability:** `hardcoded` — static init pattern

**Orphan classification:** `game_logic_isolated` — no cross-refs found. Likely called from function pointer table during collision system startup.

<!-- target: docs/17-physics-collision.md -->

## FUN_00494600 — Collision Global Zeroing

Source: collision system. Zeroes four collision system global variables.

**Key logic:**
- Sets `DAT_007cddf0 = 0`, `DAT_007cddf4 = 0`, `DAT_007cddf8 = 0`, `_DAT_007cddfc = 0`
- Simple reset of collision state tracking globals

**Globals:**
- `DAT_007cddf0` through `_DAT_007cddfc` — collision state counters/flags (all zeroed)

**Moddability:** `hardcoded` — static init pattern

**Orphan classification:** `game_logic_isolated` — no cross-refs found. Likely called during collision system shutdown or reset.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ca10 — Collision Static Data Registration (1)

Source: collision system. Registers a static data block with the collision manager.

**Key logic:**
- Calls `FUN_00587b3e(&PTR_LAB_0044ca20)` — registers a static collision data structure
- Function 00587b3e likely adds this to an internal collision data registry (material table, shape table, or body template)
- No parameters, no return value — purely side-effect registration

**Calls:** FUN_00587b3e (register static data with collision system)

**Moddability:** `hardcoded` — static registration

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d190 — Collision Static Data Registration (2)

Source: collision system. Registers a static data block with the collision manager.

**Key logic:**
- Calls `FUN_00587b3e(&DAT_0044d1a0)` — registers a different static collision data structure
- Same pattern as FUN_0044ca10

**Calls:** FUN_00587b3e (register static data with collision system)

**Moddability:** `hardcoded` — static registration

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d970 — Collision Static Data Registration (3)

Source: collision system. Registers a static data block with the collision manager.

**Key logic:**
- Calls `FUN_00587b3e(&DAT_0044d980)` — registers static collision data
- Same pattern as other registration thunks

**Calls:** FUN_00587b3e (register static data with collision system)

**Moddability:** `hardcoded` — static registration

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e0f0 — Collision Static Data Registration (4)

Source: collision system. Registers a static data block with the collision manager.

**Key logic:**
- Calls `FUN_00587b3e(&DAT_0044e100)` — registers static collision data

**Calls:** FUN_00587b3e (register static data with collision system)

**Moddability:** `hardcoded` — static registration

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e870 — Collision Static Data Registration (5)

Source: collision system. Registers a static data block with the collision manager.

**Key logic:**
- Calls `FUN_00587b3e(&DAT_0044e880)` — registers static collision data

**Calls:** FUN_00587b3e (register static data with collision system)

**Moddability:** `hardcoded` — static registration

<!-- target: docs/18-physics-dynamics.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

## FUN_00494de0 — Collision Node Allocator

Source: collision_alloc.cpp. Allocates and registers a collision node in a global linked list.

**Key logic:**
- Calls FUN_0053cfe0 with flags 0x10801 (allocation/validation)
- On success and non-null input: allocates new node (0xc bytes)
  - Stores input pointer in node[0]
  - Sets node[1] = 0 (next pointer)
  - Sets node[2] byte = 0 (flags)
- Inserts node into global list (DAT_007cddf0/DAT_007cddf4/DAT_007cddf8)
- Increments global counter `_DAT_007cddfc`

**Globals:**
- `DAT_007cddf0` — collision list head pointer
- `DAT_007cddf4` — collision list tail pointer
- `DAT_007cddf8` — collision list iterator
- `_DAT_007cddfc` — collision node counter

**Calls:** FUN_0053cfe0 (validation), operator_new (allocation)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d400 — Spatial Node Init (index 14)

Source: spatial_init.cpp. Initializes a spatial partitioning node with element count 0xe (14).

**Key logic:**
- Sets `DAT_007ccd38 = 0xe` (14 elements)
- Zeros 5 following dwords: `_DAT_007ccd3c` through `_DAT_007ccd4c`

**Globals:**
- `DAT_007ccd38` — node element count

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044db80 — Spatial Node Init (index 47)

Source: spatial_init.cpp. Initializes a spatial partitioning node with element count 0x2f (47).

**Key logic:**
- Sets `DAT_007ccee8 = 0x2f` (47 elements)
- Zeros 5 following dwords

**Globals:**
- `DAT_007ccee8` — node element count

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e300 — Spatial Node Init (index 75, distance 9000)

Source: spatial_init.cpp. Initializes a spatial partitioning node with element count 0x4b (75) and max distance 9000.

**Key logic:**
- Sets `DAT_007cd0b0 = 0x4b` (75 elements)
- Zeros 4 following dwords
- Sets `DAT_007cd0c4 = 9000` (maximum distance)

**Globals:**
- `DAT_007cd0b0` — node element count
- `DAT_007cd0c4` — max search distance (9000)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ea80 — Spatial Node Init (index 95, distance 9000)

Source: spatial_init.cpp. Initializes a spatial partitioning node with element count 0x5f (95) and max distance 9000.

**Key logic:**
- Sets `DAT_007ca4e0 = 0x5f` (95 elements)
- Zeros 4 following dwords
- Sets `DAT_007ca4f4 = 9000` (maximum distance)

**Globals:**
- `DAT_007ca4e0` — node element count
- `DAT_007ca4f4` — max search distance (9000)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c680 — Spatial Node Init (index 2, radius -1.0)

Source: spatial_init.cpp. Initializes a spatial partitioning node with element count 2 and radius -1.0.

**Key logic:**
- Sets `DAT_007cca44 = 2`
- Zeros `_DAT_007cca48`
- Sets `_DAT_007cca4c = 0xbf800000` (-1.0f float, negative radius/sentinel)
- Zeros `_DAT_007cca50`

**Globals:**
- `DAT_007cca44` — node element count (2)
- `_DAT_007cca4c` — radius or sentinel value (-1.0f)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ce00 — Spatial Node Init (index 35, radius -1.0)

Source: spatial_init.cpp. Initializes a spatial partitioning node with element count 0x23 (35) and radius -1.0.

**Key logic:**
- Sets `DAT_007ca438 = 0x23` (35 elements)
- Zeros `_DAT_007ca43c`
- Sets `_DAT_007ca440 = 0xbf800000` (-1.0f, sentinel radius)
- Zeros `_DAT_007ca444`

**Globals:**
- `DAT_007ca438` — node element count (35)
- `_DAT_007ca440` — radius sentinel (-1.0f)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ee00 — Collision Node Next-Child Accessor

Source: collision_node.cpp. Returns the child/next node pointer from a collision tree node.

**Key logic:**
- If `*param_1 != 0` (node is active): returns `param_1 + 0x4c` (child/next node offset)
- Otherwise: returns null

**Calls:** None

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ca70 — Atexit Handler Registration (collision A)

Source: atexit_reg.cpp. Registers DAT_0044ca80 as an atexit cleanup handler.

**Key logic:**
- Calls FUN_00587b3e with pointer to DAT_0044ca80 (cleanup function)

**Calls:** FUN_00587b3e (atexit/cleanup registration)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d1f0 — Atexit Handler Registration (collision B)

Source: atexit_reg.cpp. Registers DAT_0044d200 as an atexit cleanup handler.

**Key logic:**
- Calls FUN_00587b3e with pointer to DAT_0044d200

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d9d0 — Atexit Handler Registration (collision C)

Source: atexit_reg.cpp. Registers DAT_0044d9e0 as an atexit cleanup handler.

**Key logic:**
- Calls FUN_00587b3e with pointer to DAT_0044d9e0

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e150 — Atexit Handler Registration (collision D)

Source: atexit_reg.cpp. Registers PTR_LAB_0044e160 as an atexit cleanup handler.

**Key logic:**
- Calls FUN_00587b3e with pointer to PTR_LAB_0044e160

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e8d0 — Atexit Handler Registration (collision E)

Source: atexit_reg.cpp. Registers DAT_0044e8e0 as an atexit cleanup handler.

**Key logic:**
- Calls FUN_00587b3e with pointer to DAT_0044e8e0

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

---

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0045b660 — UI Cursor/Selection Rectangle Render with Interpolation

Source: ui_cursor.cpp. Renders an animated selection rectangle or cursor with smooth interpolation.

**Key logic:**
- Checks state via FUN_0045bb00; if inactive and value at +0x328 == DAT_0059e440, resets and returns
- Computes target values: interpolant from FUN_0045b5c0 + offset (_DAT_0059e448), and scaled value from state × _DAT_0059f078
- Smoothly interpolates two float values (+0x324, +0x328) toward targets:
  - If difference small enough (< _DAT_0059f088): snaps directly to target
  - Otherwise: lerps with coefficient _DAT_0059e8c8
- Renders a rectangle border using 4 line segments via FUN_00494c20 with color 0xff999999
- Uses DAT_008b8dc8 for render target

**Calls:** FUN_0045bb00 (state check), FUN_0045b5c0 (position/time input), FUN_004dcda0, FUN_004dcee0, FUN_004dcd60, FUN_004dcf30, FUN_004dcf50, FUN_00494c20 (line render)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0049b6d0 — Lap Time Gap Calculation

Source: timing.cpp. Computes time gap between two vehicles accounting for lap-based wrap-around.

**Key logic:**
- Reads lap indices at param_1+0x403c and param_2+0x403c (SessionPoints/CurrentLap)
- Gets two time values via FUN_004f01b0 (race time)
- If same lap: *param_3 = time difference, returns 0
- If param_2 lap < param_1 lap:
  - If one lap apart and time < threshold: *param_3 = (max_time - time2) + time1 (wrap-around)
  - Otherwise: *param_4 = lap difference, returns 0
- Returns 1 on error (null params)

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x403c | CurrentLap | int, current lap number |

**Globals:**
- `_DAT_005ea408` — max race time / lap time threshold

**Calls:** FUN_004f01b0 (get current race time)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044f5f0 — Cursor Resource Cleanup

Source: ui_cursor.cpp. Destroys cursor handles and clears cursor state.

**Key logic:**
- Calls SetCursor(NULL) to hide cursor
- Iterates 6 cursor slots at param_1+0x30 (stride 5 dwords = 20 bytes)
- For each non-null handle: calls DestroyCursor, zeros slot
- Sets param_1+0xa8 = 0

**Calls:** SetCursor, DestroyCursor (Win32 API)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d460 — Global State Initializer (Collision Set 1)

Source: physics_globals.cpp. Initializes a group of 6 collision-related global variables.

**Key logic:**
- Sets DAT_007cccf0 = 0xf (15)
- Zeroes DAT_007cccf4, DAT_007cccf8, DAT_007cccfc, DAT_007ccd00, DAT_007ccd04

**Moddability:** configurable — coefficients likely read from .gdb or .hdv

---

<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

## FUN_0044eae0 — Global State Initializer (Collision Set 4)

Source: physics_globals.cpp. Initializes collision parameters with spring/damper defaults.

**Key logic:**
- Sets DAT_007ca54c = 0x60 (96)
- Zeroes DAT_007ca550, DAT_007ca554, DAT_007ca558, DAT_007ca55c
- Sets DAT_007ca560 = 18000

**Moddability:** configurable — collision stiffness and limits from data files

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c6e0 — Global State Initializer (Collision Material 1)

Source: physics_globals.cpp. Initializes material/collision surface parameters.

**Key logic:**
- Sets DAT_007ca3e8 = 3 (friction/restitution type)
- Zeroes DAT_007ca3ec, DAT_007ca3f0
- Sets DAT_007ca3f4 = 0x3f800000 (1.0f — restitution coefficient)

**Moddability:** configurable — surface material properties from .trk or .gdb

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ce60 — Global State Initializer (Collision Material 2)

Source: physics_globals.cpp. Initializes a second set of material/collision surface parameters.

**Key logic:**
- Sets DAT_007ca448 = 0x24 (36)
- Zeroes DAT_007ca44c, DAT_007ca450
- Sets DAT_007ca454 = 0x3f800000 (1.0f)

**Moddability:** configurable — surface material properties from .trk or .gdb

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0045be50 — Global State Initializer (Collision System Reset)

Source: physics_globals.cpp. Resets collision globals and triggers system re-init.

**Key logic:**
- Sets DAT_007cd208 = 0
- Sets DAT_007cd20c = 0xffffffff (-1, invalid/idle state)
- Calls FUN_0045bf10 (collision system re-initialization)

**Calls:** FUN_0045bf10

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cad0 — Thunk

Thunk — registers callback via FUN_00587b3e with &DAT_0044cae0. No entry needed.

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d250 — Thunk

Thunk — registers callback via FUN_00587b3e with &PTR_LAB_0044d260. No entry needed.

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044da30 — Thunk

Thunk — registers callback via FUN_00587b3e with &DAT_0044da40. No entry needed.

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e1b0 — Thunk

Thunk — registers callback via FUN_00587b3e with &DAT_0044e1c0. No entry needed.

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e930 — Thunk

Thunk — registers callback via FUN_00587b3e with &DAT_0044e940. No entry needed.

---

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0044d4c0 — CollisionGridInit16x16

Source: unknown. Initializes collision grid parameters for 16×16 (0x10) grid.

**Key logic:**
- Sets DAT_007cccd8 = 0x10 (grid dimension/size = 16)
- Zeroes 5 ints at 007cccdc-007ccec (grid counters/flags)

**Globals:**
- `DAT_007cccd8` — grid size (16)
- `DAT_007cccdc`–`_DAT_007cccec` — grid state (zeroed)

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dc40 — CollisionGridInit49x49

Source: unknown. Initializes collision grid parameters for 49×49 (0x31) grid.

**Key logic:**
- Sets DAT_007cce58 = 0x31 (grid dimension = 49)
- Zeroes 5 ints at 007cce5c-007cce6c

**Globals:**
- `DAT_007cce58` — grid size (49)
- `DAT_007cce5c`–`_DAT_007cce6c` — grid state (zeroed)

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e3c0 — CollisionGridInit77

Source: unknown. Initializes collision grid parameters for 77 (0x4d) units.

**Key logic:**
- Sets DAT_007cd130 = 0x4d (size/stride = 77)
- Zeroes 4 ints at 007cd134-007cd140
- Sets DAT_007cd144 = 27000 (max distance/threshold)

**Globals:**
- `DAT_007cd130` — grid size (77)
- `DAT_007cd134`–`_DAT_007cd140` — grid state (zeroed)
- `DAT_007cd144` — max distance (27000)

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044eb40 — CollisionGridInit97

Source: unknown. Initializes collision grid parameters for 97 (0x61) units.

**Key logic:**
- Sets DAT_007ca51c = 0x61 (size/stride = 97)
- Zeroes 4 ints at 007ca520-007ca52c
- Sets DAT_007ca530 = 27000 (max distance/threshold)

**Globals:**
- `DAT_007ca51c` — grid size (97)
- `DAT_007ca520`–`_DAT_007ca52c` — grid state (zeroed)
- `DAT_007ca530` — max distance (27000)

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c740 — CollisionGridInit4

Source: unknown. Initializes collision grid parameters for 4-unit grid.

**Key logic:**
- Sets DAT_007ca470 = 4 (grid size = 4)
- Zeroes DAT_007ca474, 007ca47c
- Sets _DAT_007ca478 = 0xbf800000 (-1.0f, sentinel/invalid value)

**Globals:**
- `DAT_007ca470` — grid size (4)
- `DAT_007ca474` — zero
- `_DAT_007ca478` — -1.0f sentinel
- `DAT_007ca47c` — zero

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cec0 — CollisionGridInit37

Source: unknown. Initializes collision grid parameters for 37 (0x25) grid.

**Key logic:**
- Sets DAT_007ccbf4 = 0x25 (grid size = 37)
- Zeroes DAT_007ccbf8, 007ccc00
- Sets _DAT_007ccbfc = 0xbf800000 (-1.0f, sentinel)

**Globals:**
- `DAT_007ccbf4` — grid size (37)
- `DAT_007ccbf8` — zero
- `_DAT_007ccbfc` — -1.0f sentinel
- `DAT_007ccc00` — zero

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004628a0 — WeatherSurfaceUpdate

Source: unknown. Updates track surface conditions based on weather/rain state.

**Key logic:**
- Calls FUN_00461550() — update weather timer/phase
- Calls FUN_004630d0() — detect if rain active (returns non-zero)
- If rain active:
  - FUN_00463760(0) — set track wetness/grip
  - FUN_00461610() — update weather particle system
  - FUN_00462760() — update surface material properties
  - FUN_004b33b0(4, 5, 0, 0, _DAT_008afea0, 1) — spawn rain particles with current time
  - FUN_00462250() — update sky/atmosphere
  - FUN_004a0dc0() — update HUD
  - Returns 1 (rain active)
- Returns 0 (no rain)

**Globals:**
- `_DAT_008afea0` — current race time (float)

**Calls:** FUN_00461550, FUN_004630d0 (rain check), FUN_00463760 (track grip), FUN_00461610, FUN_00462760 (surface), FUN_004b33b0 (particles), FUN_00462250 (sky), FUN_004a0dc0 (HUD)

**Moddability:** hookable — rain detection drives surface grip

<!-- target: docs/17-physics-collision.md -->

## FUN_00494e60 — CollisionGeometryFreeList

Source: unknown. Frees all collision geometry/surface resources in a linked list.

**Key logic:**
- Guard: returns if DAT_007cddf0 (head) is null
- First pass: walks list from head, calling FUN_0053d130 for each node's resource handle
  - Stops when DAT_007cddf8 walks to null
- Second pass: walks list from first node:
  - If node[2] (flags byte) non-zero AND *node (resource handle) non-zero:
    - Calls FUN_00557470() — release geometry/shader resource
    - Calls FUN_00587bcf(*node) — free memory
  - Calls FUN_00587bcf(node) — free node itself
- Clears all globals to null/zero

**Globals:**
- `DAT_007cddf0` — linked list head pointer
- `DAT_007cddf4` — list count
- `DAT_007cddf8` — list traversal pointer
- `_DAT_007cddfc` — list tail/size

**Each linked list node:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | ResourceHandle | int, pointer to geometry |
| +0x04 | NextPtr | int, next node |
| +0x08 | Flags | byte, non-zero = active |

**Calls:** FUN_0053d130 (release resource), FUN_00557470 (release geometry), FUN_00587bcf (free memory)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ba40 — CollisionGridRaycast32x32

Source: unknown. Casts 32×32 grid of rays into scene for collision/environment map computation.

**Key logic:**
- Guard: returns if param_1+0x4 == 0 (no plane data)
- Computes ray step from _DAT_0059e420 (screen dim) divided by param_1+0x10 width / param_1+0x20 height
- Handles divide-by-zero: if dimension == _DAT_0059e430 (NaN), step = 0.0
- Loops iVar4=0..31 (rows) and local_3c=0..31 (cols): 1024 total samples
  - Computes sample position: center_offset ± 0.5 within each cell
  - (startX + colOffset) * stepX → x-coordinate, (startY + rowOffset) * stepY → y-coordinate
- Calls FUN_0044a880 for each (x, y) pair — raycast query
- Stores results sequentially after param_1+0x28

**Globals:**
- `_DAT_0059e420` — screen/plane dimension base (float)
- `_DAT_0059e430` — NaN/zero sentinel
- `_DAT_0059e880` — 0.5 offset (centroid)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x004 | PlaneActive | int, guard flag |
| +0x008 | OriginX | double |
| +0x010 | PlaneWidth | double |
| +0x018 | OriginY | double |
| +0x020 | PlaneHeight | double |
| +0x028 | ResultBuffer | float[1024] output |

**Calls:** FUN_0044a880 (raycast per sample point)

**Moddability:** hardcoded — 32×32 grid fixed

<!-- target: docs/06-session-race-logic.md -->

## FUN_00464a40 — CollisionSensorInit

Source: unknown. Initializes a collision/sensor state struct.

**Key logic:**
- Sets param_1+0x71 = _DAT_0059f130 (sensor reading/type)
- Sets param_1+0x6c = 0 (sensor state)
- Sets param_1+0x68 = 0 (sensor timeout)

**Globals:**
- `_DAT_0059f130` — default sensor value

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x068 | SensorTimeout | int |
| +0x06c | SensorState | byte |
| +0x071 | SensorValue | undefined4 (float?) |

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cb30 — CollisionGridFreeA

Source: unknown. Frees collision grid memory for grid A.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044cb40) — frees heap block at static address

**Calls:** FUN_00587b3e (heap free)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d2b0 — CollisionGridFreeB

Source: unknown. Frees collision grid memory for grid B.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044d2c0) — frees heap block at static address

**Calls:** FUN_00587b3e (heap free)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044da90 — CollisionGridFreeC

Source: unknown. Frees collision grid memory for grid C.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044daa0) — frees heap block at static address

**Calls:** FUN_00587b3e (heap free)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e210 — CollisionGridFreeD

Source: unknown. Frees collision grid memory for grid D.

**Key logic:**
- Calls FUN_00587b3e(&PTR_LAB_0044e220) — frees heap block at static address

**Calls:** FUN_00587b3e (heap free)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e990 — CollisionGridFreeE

Source: unknown. Frees collision grid memory for grid E.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044e9a0) — frees heap block at static address

**Calls:** FUN_00587b3e (heap free)

**Moddability:** hardcoded

## FUN_0044f7f0 — CollisionResponseCompute

Source: unknown. Computes collision response parameters using constraint data. Calculates penetration ratios and restitution-based impulse factors.

**Key logic:**
- Reads collision object vtable from param_1+0x80
- Calls vtable+0x14 method with type 4
- Calculates collision response:
  - param_4 = local_14 (output float)
  - param_3 = 0.0 initially (penetration depth)
  - If diff != 0: param_3 = DAT_0059e43c / diff (collision stiffness)
  - Computes interpolated point: param_7 * (fVar4 - fVar1) + fVar1
  - Computes impulse: (fVar4 - fVar1) * param_6 * DAT_0059e450
  - If result differs: param_5 = reciprocal else 0.0
  - param_2 set similarly as second axis component

**Globals:**
- `_DAT_0059e43c` — collision stiffness constant
- `_DAT_0059e450` — collision impulse scale

**Calls:** vtable dispatch at param_1+0x80 (virtual method call)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044a070 — QuadraticSurfaceCollisionTest

Source: unknown. Double-precision collision test against a quadratic surface (sphere/ellipsoid). Tests 3 half-space planes then evaluates signed distance to quadric.

**Key logic:**
- Iterates 3 half-space planes from param_1 (stride 3 floats, offset +0x34 from param_1)
- For each plane: if (param_2[2] * plane.x + param_2[0] * plane.y < plane.z) return 0 (outside)
- Evaluates quadratic form: dVar1 = param_2[2]^2 * param_1[1] + param_2[0]^2 * param_1[0] + param_2[0] * param_2[2] * param_1[2] + param_1[3] * param_2[0] + param_1[4] * param_2[2] + param_1[5]
- dVar2 = dVar1 - param_2[1] (signed distance)
- If distance within bounds param_2[3]..param_2[4]:
  - Updates param_2[4] = min distance
  - Records hit: param_2[5] = distance value, param_2+6 = param_1 (collision object pointer)
  - Returns 1 (hit)
- Otherwise returns 0 (miss)

**Calls:** none (pure computation with double precision)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004636a0 — CollisionThresholdCheck

Source: unknown. Compares vehicle speed/parameter at +0x388 against threshold, branching on FUN_00461dc0() flag.

**Key logic:**
- Calls FUN_00461dc0() to check validity/flag
- If false: compares *(float*)(*param_1 + 0x388) < DAT_0059f124
- If true: compares *(float*)(*param_1 + 0x388) < DAT_0059e8ec
- Builds comparison result flags (bits 8 and 14)
- Returns 1 if all comparisons false (value >= threshold), 0 if any true

**Globals:**
- `_DAT_0059f124` — threshold A (float)
- `_DAT_0059e8ec` — threshold B (float, alternate)

**Calls:** FUN_00461dc0 (validity/state check)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d520 — CollisionStateInit_17

Source: unknown. Initializes collision system state block at DAT_007ccd20 with type 0x11.

**Key logic:**
- Sets 6 consecutive fields starting at DAT_007ccd20
- First field: 0x11 (contact type/subtype ID)
- Fields +4, +8, +c, +10, +14: zeroed

**Globals:**
- `DAT_007ccd20` — collision state block (type=0x11)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dca0 — CollisionStateInit_32

Source: unknown. Initializes collision system state block at DAT_007ccea0 with type 0x32.

**Key logic:**
- Sets 6 consecutive fields starting at DAT_007ccea0
- First field: 0x32 (contact type/subtype ID)
- Rest zeroed

**Globals:**
- `DAT_007ccea0` — collision state block (type=0x32)

**Moddability:** hardcoded

**Orphan classification:** `game_logic_isolated` — no cross-refs found. Likely called from function pointer table during collision system startup.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e420 — CollisionStateInit_4e

Source: unknown. Initializes collision system state block at DAT_007cd004 with type 0x4e.

**Key logic:**
- Sets 6 consecutive fields starting at DAT_007cd004
- First field: 0x4e
- Rest zeroed

**Globals:**
- `DAT_007cd004` — collision state block (type=0x4e)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044eba0 — CollisionStateInit_62

Source: unknown. Initializes collision system state block at DAT_007ca420 with type 0x62.

**Key logic:**
- Sets 6 consecutive fields starting at DAT_007ca420
- First field: 0x62
- Rest zeroed

**Globals:**
- `DAT_007ca420` — collision state block (type=0x62)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c7a0 — CollisionStateInit_Alpha

Source: unknown. Initializes collision state with float 1.0 (0x3f800000) at +0x1a4.

**Key logic:**
- Sets DAT_007cd198 = 5 (type/count)
- Sets +4, +8 = 0
- Sets +12 = 0x3f800000 (1.0f, alpha/scale factor)

**Globals:**
- `DAT_007cd198` — collision state (type=5, alpha=1.0)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cf20 — CollisionStateInit_Alpha2

Source: unknown. Initializes collision state with float 1.0 at +0x3b4.

**Key logic:**
- Sets DAT_007ca3a8 = 0x26 (38, type/count)
- Sets +4, +8 = 0
- Sets +12 = 0x3f800000 (1.0f, alpha/scale)

**Globals:**
- `DAT_007ca3a8` — collision state (type=0x26, alpha=1.0)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0047c960 — CollisionSystemInit

Source: unknown. Initializes collision system by calling 3 initialization subroutines.

**Key logic:**
- Calls FUN_0047c9d0() (collision subsystem init)
- Calls FUN_004b9cb0() (related subsystem)
- Calls FUN_004b9cd0() (related subsystem)

**Calls:** FUN_0047c9d0, FUN_004b9cb0, FUN_004b9cd0

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cb90 — CollisionModuleRegister_A

Source: unknown. Registers collision module data block with system via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044cba0) — registers static collision descriptor

**Calls:** FUN_00587b3e (module registration)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d310 — CollisionModuleRegister_B

Source: unknown. Registers collision module data block via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&PTR_LAB_0044d320)

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044daf0 — CollisionModuleRegister_C

Source: unknown. Registers collision module data block via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044db00)

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e270 — CollisionModuleRegister_D

Source: unknown. Registers collision module data block via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044e280)

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e9f0 — CollisionModuleRegister_E

Source: unknown. Registers collision module data block via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044ea00)

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0045b840 — Collision Damage Decay Processor

Source: likely_collision_damage.cpp. Iterates 8 collision contact points, decays impact energy, triggers visual effects on threshold.

**Key logic:**
- Calls FUN_0045bb00 (pre-process), FLAG byte at param_1+800 = 0
- Calls FUN_0045b660 (setup), FUN_004dcf30 (get frame/tick)
- Loops 8 iterations (local_10 = 0..7) over contact points at stride 0x5c
- For each point: if float at +0x90 (impact energy) > 0.0 (DAT_0059e440):
  - Calls FUN_004dd030 (spawn particle/spark effect) with position +0x3c, energy/2, and parameters
  - Reduces impact energy by _(DAT_008afe90) (decay rate)
  - If energy drops below 0.0: sets byte at param_1+800 = 1 (done flag)
  - Otherwise: calls FUN_0045b430 (contact processing)
- Limits to 4 active contacts per frame (local_14 < 3)

**Globals:**
- `DAT_0059e440` — 0.0f
- `DAT_008afe90` — collision energy decay constant (float)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| +0x31c | ContactCount | int |
| +0x320 (0x90 per contact) | ContactEnergy | float, decayed |
| +0x3c per contact | ContactPosition | vec3/position data |
| +800 (0x320) | DecayDoneFlag | byte |

**Calls:** FUN_0045bb00 (pre-process), FUN_0045b660 (setup), FUN_004dcf30 (get tick), FUN_004dd030 (spawn effect), FUN_0045b430 (contact update)

**Moddability:** configurable — collision energy decay in physics files.

## FUN_0044bb60 — Collision Geometry Operation Selector

Source: likely_collision_geometry.cpp. Dispatches collision/geometry operations on global geometry handle DAT_008afe88.

**Key logic:**
- Reads global geometry handle DAT_008afe88; if 0, calls FUN_004497e0 and returns
- param_1 == 0: calls FUN_0044acb0 (geometry transform)
- param_1 == 1: calls FUN_0044acb0 + FUN_00449700 + FUN_004497e0
- param_1 == 2: calls FUN_004492b0 (push matrix), FUN_0044acb0, FUN_00449700, FUN_0044b370 (apply), FUN_00449340 (pop matrix), FUN_004497e0

**Globals:**
- `DAT_008afe88` — global collision geometry handle

**Calls:** FUN_0044acb0 (geometry transform), FUN_00449700 (update), FUN_004497e0 (finalize), FUN_004492b0 (push), FUN_0044b370 (apply matrix), FUN_00449340 (pop)

**Moddability:** hardcoded.

## FUN_0044f680 — Frustum/Viewport Setup

Source: likely_collision_camera.cpp. Computes projection/viewport parameters from screen coordinates.

**Key logic:**
- Stores int param_4 at param_1[3]
- Computes center_x = (param_2 + param_4) >> 1, center_y = (param_3 + param_5) >> 1
- fVar1 = DAT_0059e43c / ((param_4 - param_2) * DAT_0059e450)
- param_1[6] = int(fVar1) — scale factor
- param_1[7] = int(DAT_0059e43c / ((param_5 - param_3) * DAT_0059e450)) — y scale

**Globals:**
- `DAT_0059e43c` — projection scale constant
- `DAT_0059e450` — 0.5f

**Struct offsets (param_1):**
| Offset | Field | Notes |
|---|---|---|
| [0] | left | int |
| [1] | top | int |
| [2] | right | int |
| [3] | bottom | int |
| [4] | center_x | int |
| [5] | center_y | int |
| [6] | scale_x | int (fixed-point) |
| [7] | scale_y | int (fixed-point) |

**Calls:** none

**Moddability:** hardcoded.

## FUN_0044d580 — Collision Region Init 1 (Type 18)

Source: likely_collision_region.cpp. Initializes global collision region data block #1.

**Key logic:**
- DAT_007ccd08 = 0x12 (18) — region type
- DAT_007ccd0c..DAT_007ccd1c = 0 — clear data

**Globals:**
- `DAT_007ccd08` — region type (18)
- `DAT_007ccd0c` through `DAT_007ccd1c` — region parameters

**Moddability:** configurable — region data from .gdb/.rcd files.

## FUN_0044dd00 — Collision Region Init 2 (Type 51)

Source: likely_collision_region.cpp. Initializes global collision region data block #2.

**Key logic:**
- DAT_007cce88 = 0x33 (51) — region type
- DAT_007cce8c..DAT_007cce9c = 0 — clear data

**Globals:**
- `DAT_007cce88` — region type (51)
- `DAT_007cce8c` through `DAT_007cce9c` — region parameters

**Moddability:** configurable — region data from .gdb/.rcd files.

## FUN_0044e480 — Collision Region Init 3 (Type 79)

Source: likely_collision_region.cpp. Initializes global collision region data block #3.

**Key logic:**
- DAT_007cd034 = 0x4f (79) — region type
- DAT_007cd038..DAT_007cd044 = 0 — clear data
- DAT_007cd048 = 9000 — threshold/limit

**Globals:**
- `DAT_007cd034` — region type (79)
- `DAT_007cd048` — region threshold (9000)

**Moddability:** configurable — region data from track files.

## FUN_0044ec00 — Collision Region Init 4 (Type 99)

Source: likely_collision_region.cpp. Initializes global collision region data block #4.

**Key logic:**
- DAT_007ca3f8 = 99 — region type
- DAT_007ca3fc..DAT_007ca408 = 0 — clear data
- DAT_007ca40c = 9000 — threshold/limit

**Globals:**
- `DAT_007ca3f8` — region type (99)
- `DAT_007ca40c` — region threshold (9000)

**Moddability:** configurable — region data from track files.

## FUN_0044c800 — Collision Region Init 5 (Type 6, -1.0f)

Source: likely_collision_region.cpp. Initializes global collision region with float sentinel.

**Key logic:**
- DAT_007ca3c8 = 6 — region type
- DAT_007ca3cc = 0
- DAT_007ca3d0 = 0xbf800000 (-1.0f) — sentinel/direction
- DAT_007ca3d4 = 0

**Globals:**
- `DAT_007ca3c8` — region type (6)
- `DAT_007ca3d0` — float -1.0f (normal/sentinel)

**Moddability:** configurable — region data from track files.

**Orphan classification:** `game_logic_isolated` — real collision init code, no cross-refs. Likely called from function pointer table during collision system startup. Part of init function family with FUN_0044cda0, FUN_0044d340, FUN_0044d8e0, FUN_0044de80, FUN_0044e420, FUN_0044e9c0.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e9c0 — Collision Detection Init (Type 0x5d, Threshold 27000)

Source: collision detection init. Initializes collision detection state block with type ID 0x5d and large threshold 27000.

**Key logic:**
- Sets DAT_007cca54 = 0x5d (93) — collision detection type/ID
- Zeros _DAT_007cca58, DAT_007cca5c, _DAT_007cca60, _DAT_007cca64 — clear data fields
- Sets DAT_007cca68 = 27000 — threshold/limit value (distance or count limit)

**Globals:**
- `DAT_007cca54` — collision detection state block type ID (93)
- `DAT_007cca68` — collision threshold (27000)

**Moddability:** hardcoded — static init pattern.

**Orphan classification:** `game_logic_isolated` — real collision init code, no cross-refs. Likely called from function pointer table. Same init function family as the other FUN_0044cxxx collision init functions.

<!-- target: docs/17-physics-collision.md -->


## FUN_00455e50 — Collision Global Update Broadcast

Source: likely_collision_update.cpp. Triggers collision update from global value.

**Key logic:**
- Calls FUN_004537b0((float)_DAT_008afe90) — push global value into collision system
- Calls FUN_00455bd0 — update/finalize

**Globals:**
- `DAT_008afe90` — global collision decay value

**Calls:** FUN_004537b0 (collision param set), FUN_00455bd0 (collision update)

**Moddability:** hardcoded.

## FUN_0044cbf0 — Collision Data Registration Block 1

Source: likely_collision_data.cpp. Registers static collision data block via template system.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044cc00) — register data block

**Calls:** FUN_00587b3e (template/param registration)

**Moddability:** hardcoded.

## FUN_0044d370 — Collision Data Registration Block 2

Source: likely_collision_data.cpp. Registers static collision data block via template system.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044d380) — register data block

**Calls:** FUN_00587b3e (template/param registration)

**Moddability:** hardcoded.

## FUN_0044db50 — Collision Data Registration Block 3

Source: likely_collision_data.cpp. Registers static collision data block via template system.

**Key logic:**
- Calls FUN_00587b3e(&PTR_LAB_0044db60) — register data block

**Calls:** FUN_00587b3e (template/param registration)

**Moddability:** hardcoded.

## FUN_0044e2d0 — Collision Data Registration Block 4

Source: likely_collision_data.cpp. Registers static collision data block via template system.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044e2e0) — register data block

**Calls:** FUN_00587b3e (template/param registration)

**Moddability:** hardcoded.

## FUN_0044ea50 — Collision Data Registration Block 5

Source: likely_collision_data.cpp. Registers static collision data block via template system.

**Key logic:**
- Calls FUN_00587b3e(&PTR_LAB_0044ea60) — register data block

**Calls:** FUN_00587b3e (template/param registration)

**Moddability:** hardcoded.

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004987b0 — Collision Response Type Classification

Source: likely collision.cpp. Determines collision response type (1–13) based on object state flags and a timestep accumulator.

**Key logic:**
- Accumulate float at +200 using FUN_00498730 (timestep integrator)
- Cascaded flag tests produce response code:
  - if (+100==0): code = 4 - (+0x84 != 0) → 3 or 4
  - elif (+0x84==0): code=1 (fVar3 < threshold → reset+0) or code=2 (set to 0.65f)
  - else: code=5
  - +0x68==0: if +0x88!=0 → code=10
  - +0x68!=0: code = 9 + (+0x88!=0)*2 → 9 or 11
  - +0x6c==0: if +0x8c!=0 → code=7
  - +0x6c!=0: code = 6 + (+0x8c!=0)*2 → 6 or 8
  - if +0x70!=0: code = 12 + (+0x70<1) → 12 or 13

**Struct offsets (param_1 via ECX):**
| Offset | Field | Notes |
|--------|-------|-------|
| +100 | FlagA | int32, first-level branch |
| +0x68-0x70 | BodyStateFlags | int32, collision body type flags |
| +0x84-0x8C | ContactStateFlags | int32, per-contact flags |
| +200 | TimeAccum | float, accumulated timestep |

**Globals:**
- `_DAT_0059e970` — float threshold for time accumulator reset

**Calls:** FUN_00498730 (timestep accumulation)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0045c7e0 — Collision Contact Buffer Timestep Update

Source: likely collision.cpp. Adds delta time to all contact entries in a ring buffer. When first element exceeds threshold, performs overflow division and resets.

**Key logic:**
- Add param_2 (delta) to param_1[0]
- If param_1[0] > _DAT_0059E43C:
  - Compute ratio = _DAT_0059E43C / param_1[0]
  - Reset param_1[0] = 0.0
  - param_1[3] = (int)param_1[1] × ratio (overflow scaled)
  - Reset param_1[1] = 0.0
  - param_1[4] = (int)param_1[2] × ratio
  - Reset param_1[2] = 0.0
- Loop 0x68 (104) times: for i in 0..103:
  - param_1[i] += param_2
  - param_1[i+0x6D] += param_2

**Globals:**
- `_DAT_0059E43C` — float threshold for contact aging overflow

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044b040 — Collision Capsule/Shape Copy to Pipeline

Source: likely collision.cpp. Copies 6 parameters (shape definition) into local buffer and submits to collision detection pipeline.

**Key logic:**
- Call FUN_00448E90 (collision pipeline init)
- Copy 6 × undefined4 from param_1 to local array (24 bytes)
- Call FUN_00448EC0(param_2) (pipeline receive shape)
- Call FUN_00449A80(local,0) (submit shape with flags=0)

**Calls:** FUN_00448E90, FUN_00448EC0, FUN_00449A80

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d5e0 — Collision Material Coefficients Set 1 (ID 0x13)

Source: likely collisionsetup.cpp. Initializes collision material group with ID 19, zero coefficients.

**Key logic:**
- Set DAT_007CCC80 = 0x13 (19)
- Zero DAT_007CCC84 through DAT_007CCC94 (5 consecutive 4-byte fields)

**Globals:**
- `DAT_007CCC80` — collision material ID (19)
- `DAT_007CCC84-007CCC94` — material coefficients (zeroed)

**Moddability:** hardcoded — material constants

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dd60 — Collision Material Coefficients Set 2 (ID 0x34)

Source: likely collisionsetup.cpp. Initializes collision material group with ID 52, zero coefficients.

**Key logic:**
- Set DAT_007CCE10 = 0x34 (52)
- Zero DAT_007CCE14 through DAT_007CCE24 (5 consecutive fields)

**Globals:**
- `DAT_007CCE10` — collision material ID (52)
- `DAT_007CCE14-007CCE24` — material coefficients (zeroed)

**Moddability:** hardcoded — material constants

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e4e0 — Collision Material Coefficients Set 3 (ID 0x50)

Source: likely collisionsetup.cpp. Initializes collision material with ID 80, zero coefficients except last = 18000.

**Key logic:**
- Set DAT_007CD0C8 = 0x50 (80)
- Zero DAT_007CD0CC through DAT_007CD0D8
- Set DAT_007CD0DC = 18000 (max range/threshold)

**Globals:**
- `DAT_007CD0C8` — collision material ID (80)
- `DAT_007CD0DC` — range/threshold constant (18000)

**Moddability:** hardcoded — material constants

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ec60 — Collision Material Coefficients Set 4 (ID 100)

Source: likely collisionsetup.cpp. Initializes collision material with ID 100, zero coefficients except last = 18000.

**Key logic:**
- Set DAT_007CA4A0 = 100
- Zero DAT_007CA4A4 through DAT_007CA4B0
- Set DAT_007CA4B4 = 18000 (max range/threshold)

**Globals:**
- `DAT_007CA4A0` — collision material ID (100)
- `DAT_007CA4B4` — range/threshold constant (18000)

**Moddability:** hardcoded — material constants

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c860 — Collision Material Coefficients Set 5 (ID 7, 1.0f)

Source: likely collisionsetup.cpp. Initializes collision material with ID 7, last coefficient = 1.0f.

**Key logic:**
- Set DAT_007CCBB0 = 7
- Zero DAT_007CCBB4, DAT_007CCBB8
- Set DAT_007CCBBC = 0x3F800000 (float 1.0f)

**Globals:**
- `DAT_007CCBB0` — collision material ID (7)
- `DAT_007CCBBC` — material coefficient (1.0f)

**Moddability:** hardcoded — material constants

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cfe0 — Collision Material Coefficients Set 6 (ID 40, 1.0f)

Source: likely collisionsetup.cpp. Initializes collision material with ID 40, last coefficient = 1.0f.

**Key logic:**
- Set DAT_007CC9EC = 0x28 (40)
- Zero DAT_007CC9F0, DAT_007CC9F4
- Set DAT_007CC9F8 = 0x3F800000 (float 1.0f)

**Globals:**
- `DAT_007CC9EC` — collision material ID (40)
- `DAT_007CC9F8` — material coefficient (1.0f)

**Moddability:** hardcoded — material constants

---

<!-- target: docs/17-physics-collision.md -->

## FUN_00465fd0 — Collision Distance Reset

Source: likely collision.cpp. Resets collision distance/state tracking globals.

**Key logic:**
- Set DAT_007CD460 = 0
- Set DAT_007CD464 = -1 (0xFFFFFFFF)

**Globals:**
- `DAT_007CD460` — collision distance/state
- `DAT_007CD464` — collision sentinel (-1)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cc50 — Collision Resource Release (Base)

Source: likely collision.cpp. Releases a collision system resource via memory manager.

**Key logic:**
- Call FUN_00587B3E(&PTR_LAB_0044CC60) — free resource at static address

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d430 — Collision Resource Release +30

Source: likely collision.cpp. Releases a collision system resource (+30 offset variant).

**Key logic:**
- Call FUN_00587B3E(&DAT_0044D440)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dbb0 — Collision Resource Release +50

Source: likely collision.cpp. Releases a collision system resource (+50 offset variant).

**Key logic:**
- Call FUN_00587B3E(&DAT_0044DBC0)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e330 — Collision Resource Release +80

Source: likely collision.cpp. Releases a collision system resource (+80 offset variant).

**Key logic:**
- Call FUN_00587B3E(&DAT_0044E340)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_0044eab0 — Collision Resource Release +A0

Source: likely collision.cpp. Releases a collision system resource (+A0 offset variant).

**Key logic:**
- Call FUN_00587B3E(&DAT_0044EAC0)

**Moddability:** hardcoded

---

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0045c8f0 — CollisionContactSolver

Source: Unknown. Processes collision contact points with response calculation.

**Key logic:**
- Reads `param_2[0]` (contact ID byte), validates < 0x68 (104 max contacts)
- Clears storage at `param_1 + 0x14 + id*4` (contact active flag)
- If `_DAT_0059e450` < `*(float*)(param_1 + 0x1b4 + id*4)` (threshold check):
  - Sets output to -1.0f (`0xbf800000`) at `param_1 + 0x1124 + id*4`
  - Calls `FUN_0045c7a0(param_3 - param_2[1], param_1 + buffer)` — collision response with penetration depth
  - Tracks contact count at `param_1 + 0x354 + id` (capped at 0x10)
  - Updates position index at `param_1 + 0x3bc + id` (masked to 0xf)
  - Resets timer at `param_1 + 0x1b4 + id*4` = 0
- Calls `FUN_0045cbf0(id, &param_2)` — contact callback/notification
- Clamps `param_2[1]` (penetration) to `[-DAT_007d108c, DAT_008afea0]` range
- Increments counters at `param_1 + 4` (byte count + (uVar2>>8 & 0x3ff) + 8) and `param_1 + 8` (contact count + 1)

**Globals:**
- `_DAT_008afea0` — max penetration limit
- `_DAT_0059e450` — collision threshold
- `DAT_007d108c` — min penetration limit

**Calls:** FUN_0045c7a0 (collision response), FUN_0045cbf0 (contact notification)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004962c0 — CollisionNoiseGenerator

Source: Unknown. Generates randomized collision property with interpolation.

**Key logic:**
- Checks `DAT_0059e440 <= param_3` (threshold flag for random mode)
- Converts to int `iVar3`, bounds checks against 0x10 (16 entries)
- Reads float pair at `param_1 + 0x162c + iVar3*4` (base range)
- Special case for `iVar3 == 0xf`: uses `_DAT_0059e43c` as second value
- If threshold met (random mode): generates two random values via `FUN_005881f0()`
- Returns interpolated: `random1 * _DAT_0059eed0 * (range_end - range_start) + range_start`

**Calls:** FUN_0058957a (random/seed), FUN_005881f0 (random number generation)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c430 — SinTableInit

Source: Unknown. Initializes a sine lookup table for collision angular calculations.

**Key logic:**
- Fills 8-entry table at `0x7ca384` with `fsin(index * _DAT_0059ef50)` for index 0..6
- Sets entry 7 to 1.0f (`0x3f800000`)
- Table used for collision normal angular calculations

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d640 — CollisionTableInit_14

Source: Unknown. Initializes collision contact array at DAT_007ccc68.

**Key logic:**
- Sets `DAT_007ccc68 = 0x14` (20 — max contacts or type ID)
- Zeroes 5 following fields (DAT_007ccc6c through DAT_007ccc7c)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ddc0 — CollisionTableInit_35

Source: Unknown. Initializes collision contact array at DAT_007ccdf8.

**Key logic:**
- Sets `DAT_007ccdf8 = 0x35` (53 — max contacts or type ID)
- Zeroes 5 following fields (DAT_007ccdfc through DAT_007cce0c)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e540 — CollisionTableInit_51

Source: Unknown. Initializes collision contact array at DAT_007cd0e0.

**Key logic:**
- Sets `DAT_007cd0e0 = 0x51` (81 — max contacts or type ID)
- Zeroes 4 following fields (DAT_007cd0e4 through DAT_007cd0f0)
- Sets `DAT_007cd0f4 = 27000` (stiffness/spring constant)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ecc0 — CollisionTableInit_65

Source: Unknown. Initializes collision contact array at DAT_007ca458.

**Key logic:**
- Sets `DAT_007ca458 = 0x65` (101 — max contacts or type ID)
- Zeroes 4 following fields (DAT_007ca45c through DAT_007ca468)
- Sets `DAT_007ca46c = 27000` (stiffness/spring constant)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c8c0 — CollisionFrictionInit_8

Source: Unknown. Initializes collision friction/contact struct at DAT_007ccfb0.

**Key logic:**
- Sets `DAT_007ccfb0 = 8` (friction type/contact count)
- Zeroes `DAT_007ccfb4`
- Sets `DAT_007ccfb8 = -1.0f` (0xbf800000 — restitution/coefficient)
- Zeroes `DAT_007ccfbc`

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d040 — CollisionFrictionInit_29

Source: Unknown. Initializes collision friction/contact struct at DAT_007ca3d8.

**Key logic:**
- Sets `DAT_007ca3d8 = 0x29` (41 — friction type/contact count)
- Zeroes `DAT_007ca3dc`
- Sets `DAT_007ca3e0 = -1.0f` (0xbf800000 — restitution/coefficient)
- Zeroes `DAT_007ca3e4`

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00466030 — CollisionFlagInit

Source: Unknown. Initializes collision flag fields.

**Key logic:**
- Sets `DAT_007cd468 = 0`
- Sets `DAT_007cd46c = 0xffffffff` (-1, no contact/disabled)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ccb0 — CollisionCallbackRegister_ccc0

Source: Unknown. Registers collision callback/table pointer.

**Key logic:**
- Calls `FUN_00587b3e(&DAT_0044ccc0)` — registers table address with collision system

**Calls:** FUN_00587b3e (system register/init)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d490 — CollisionCallbackRegister_d4a0

Source: Unknown. Registers collision callback/table pointer.

**Key logic:**
- Calls `FUN_00587b3e(&DAT_0044d4a0)` — registers table address with collision system

**Calls:** FUN_00587b3e (system register/init)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dc10 — CollisionCallbackRegister_dc20

Source: Unknown. Registers collision callback/table pointer.

**Key logic:**
- Calls `FUN_00587b3e(&PTR_LAB_0044dc20)` — registers table address with collision system

**Calls:** FUN_00587b3e (system register/init)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e390 — CollisionCallbackRegister_e3a0

Source: Unknown. Registers collision callback/table pointer.

**Key logic:**
- Calls `FUN_00587b3e(&DAT_0044e3a0)` — registers table address with collision system

**Calls:** FUN_00587b3e (system register/init)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044eb10 — CollisionCallbackRegister_eb20

Source: Unknown. Registers collision callback/table pointer.

**Key logic:**
- Calls `FUN_00587b3e(&PTR_LAB_0044eb20)` — registers table address with collision system

**Calls:** FUN_00587b3e (system register/init)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044af60 — Axis permutation matrix read

Read 6 values from a 3×2 axis-permuted matrix based on collision feature type.

**Key logic:**
- `param_3` selects permutation axis:
  - 1: permutation (0,2,1) = identity-like
  - 2: permutation (1,0,2) = swap X/Y
  - 3: permutation (2,1,0) = swap X/Z
  - default: permutation (param_2, param_2, param_2) — identity
- `param_4` selects output layout (symmetric vs asymmetric)
- Reads from `param_2` as array of 3 pointers to 8-byte elements
- Outputs 6 values to `param_1[0..5]`

**Moddability:** `hardcoded`

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044fc20 — Collision parameter clamp and store

Clamp collision coefficients to [0, 1.0] and store per-channel.

**Key logic:**
- `param_4` (friction?): clamped to [0, 1.0] range, stored at `param_1+0x20 + param_2*4`
- `param_3` (threshold?): floored at 0, stored at `param_1+0x2f8 + param_2*4`
- `param_5` (restitution?): clamped to [0, 1.0], stored at `param_1 + param_2*4`
- Calls `FUN_0044f8f0()` (update/dirty flag)

**Globals:**
- `DAT_0059e440` — zero constant
- `_DAT_0059e43c` — 1.0 constant (0x3f800000)

**Calls:** FUN_0044f8f0

**Moddability:** `hardcoded`

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044efc0 — Collision struct copy

Copy stack-initialized collision data into struct buffer.

**Key logic:**
- Sets `param_1+0x278` = param_2 (handle/ID)
- Copies 0x91 dwords (580 bytes) from stack to `param_1+8`

**Moddability:** `hardcoded`

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044d6a0 — Collision global init (group 0x15)

Initialize collision system globals at `DAT_007cccc0`.

**Key logic:**
- Sets `DAT_007cccc0` = 0x15 (21)
- Zeros `_DAT_007cccc4`, `DAT_007cccc8`, `_DAT_007ccccc`, `_DAT_007cccd0`, `_DAT_007cccd4`

**Globals:**
- `DAT_007cccc0`...`_DAT_007cccd4` — collision system data block

**Moddability:** `hardcoded`

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044de20 — Collision global init (group 0x36)

Initialize collision system globals at `DAT_007cce40`.

**Key logic:**
- Sets `DAT_007cce40` = 0x36 (54)
- Zeros `_DAT_007cce44`, `DAT_007cce48`, `_DAT_007cce4c`, `_DAT_007cce50`, `_DAT_007cce54`

**Globals:**
- `DAT_007cce40`...`_DAT_007cce54` — collision system data block

**Moddability:** `hardcoded`

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044e5a0 — Collision global init (group 0x52)

Initialize collision system globals at `DAT_007cc9fc`.

**Key logic:**
- Sets `DAT_007cc9fc` = 0x52 (82)
- Zeros `_DAT_007cca00`, `DAT_007cca04`, `_DAT_007cca08`, `_DAT_007cca0c`, `DAT_007cca10`

**Globals:**
- `DAT_007cc9fc`...`DAT_007cca10` — collision system data block

**Moddability:** `hardcoded`

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044f010 — Store negated absolute values

Take absolute values of two floats, store their negation.

**Key logic:**
- If param_2 < 0: param_2 = -param_2 (abs)
- If param_3 < 0: param_3 = -param_3 (abs)
- Stores `-param_2` at `param_1+0xc7c`, `-param_3` at `param_1+0xc80`

**Globals:**
- `DAT_0059e440` — zero constant for comparison

**Moddability:** `hardcoded`

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044c920 — Collision global init (single group with 1.0)

Initialize collision parameter group at `DAT_007cca6c`.

**Key logic:**
- Sets `DAT_007cca6c` = 9
- Zeros `_DAT_007cca70`, `_DAT_007cca74`
- Sets `_DAT_007cca78` = 0x3f800000 (1.0f)

**Moddability:** `hardcoded`

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044d0a0 — Collision global init (single group with 1.0)

Initialize collision parameter group at `DAT_007ccf90`.

**Key logic:**
- Sets `DAT_007ccf90` = 0x6a (106)
- Zeros `_DAT_007ccf94`, `_DAT_007ccf98`
- Sets `_DAT_007ccf9c` = 0x3f800000 (1.0f)

**Moddability:** `hardcoded`

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044c5e0 — Collision thunk

Thunk — delegates to FUN_004531a0.

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044cd10 — Collision constructor thunk

Thunk — delegates to FUN_00587b3e with PTR_LAB_0044cd20.

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044d4f0 — Collision constructor thunk

Thunk — delegates to FUN_00587b3e with DAT_0044d500.

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044dc70 — Collision constructor thunk

Thunk — delegates to FUN_00587b3e with DAT_0044dc80.

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044e3f0 — Collision constructor thunk

Thunk — delegates to FUN_00587b3e with DAT_0044e400.

===
<!-- target: docs/17-physics-collision.md -->

## FUN_0044eb70 — Collision constructor thunk

Thunk — delegates to FUN_00587b3e with DAT_0044eb80.

===
<!-- target: docs/18-physics-dynamics.md -->

## FUN_00453100 — Collision Result Processing

Source: physics collision code. Processes collision detection result and determines response type.

**Key logic:**
- If FUN_00404f10() (helper call) and DAT_007c569c == 5 (server mode): zeros param_1[9] and param_1[10], returns.
- Switch on param_1[0] (collision state):
  - 0: Calls FUN_0044f460(param_1[1]), stores byte result as param_1[9]. If 0, sets param_1[10]=DAT_0059e440 (0.0f), else param_1[10]=_DAT_0059e43c (-1.0f).
  - 1: Reads uint from param_1[7]+0x10. Same logic as case 0.
  - 2: param_1[10] = ABS(fVar1). If <= _DAT_0059e880 (0.5f threshold), param_1[9]=0, else param_1[9]=1.

**Globals:**
- `DAT_007c569c` — SessionType5, server check

**Calls:** FUN_00404f10, FUN_0044f460

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c470 — Collision Tree Node Cleanup

Source: physics collision code. Frees collision tree node resources and zeros data.

**Key logic:**
- If *param_1 != 0: frees via FUN_00587bcf, sets *param_1 = 0.
- If param_1[1] != 0: frees (param_1[1]-4), sets param_1[1] = 0.
- Zeros fields at param_1[2..7] (6 ints).
- Loops 0x400 times zeroing param_1[10..0x410] — large clearance array.

**Calls:** FUN_00587bcf (free)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044fbb0 — Collision Data Copy

Source: physics collision code. Copies a block of collision data from stack to object.

**Key logic:**
- Sets param_1+0x2f4 = param_2 (store input parameter).
- Copies 0x91 dwords (364 bytes) from stack (caller's frame) to param_1+0x84.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x2f4 | StoredParam | int |
| +0x084 | DataBlock | 0x91 dword data block |

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d700 — Collision Global Init (Set 0x16)

Source: physics collision code. Initializes collision system global state block.

**Key logic:**
- DAT_007ccc98 = 0x16 (22).
- Zeros _DAT_007ccc9c, DAT_007ccca0, _DAT_007ccca4, _DAT_007ccca8, _DAT_007cccac.

**Globals:**
- `DAT_007ccc98` — collision global, int count = 0x16
- `DAT_007ccc9c`-`DAT_007cccac` — collision globals, zeroed

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044de80 — Collision Global Init (Set 0x37)

Source: physics collision code. Initializes collision system global state block.

**Key logic:**
- DAT_007cce28 = 0x37 (55).
- Zeros _DAT_007cce2c, DAT_007cce30, _DAT_007cce34, _DAT_007cce38, _DAT_007cce3c.

**Globals:**
- `DAT_007cce28` — collision global, int count = 0x37
- `DAT_007cce2c`-`DAT_007cce3c` — collision globals, zeroed

**Moddability:** hardcoded

**Orphan classification:** `game_logic_isolated` — no cross-refs found. Likely called from function pointer table during collision system startup.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e600 — Collision Global Init (Set 0x53)

Source: physics collision code. Initializes collision system global state block.

**Key logic:**
- DAT_007cca2c = 0x53 (83).
- Zeros _DAT_007cca30, DAT_007cca34, _DAT_007cca38, _DAT_007cca3c.
- DAT_007cca40 = 9000.

**Globals:**
- `DAT_007cca2c` — collision global, int count = 0x53
- `DAT_007cca40` — collision global, int = 9000

**Moddability:** hardcoded

**Orphan classification:** `game_logic_isolated` — no cross-refs found. Likely called from function pointer table during collision system startup.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044f070 — Collision Data Fill

Source: physics collision code. Fills a data block with repeated byte pattern.

**Key logic:**
- Fills 0x40 dwords at param_1+0x27c with the byte param_2 replicated across all 4 bytes of each dword.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x27c | FillBlock | 0x40 dword block |

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c980 — Collision Global Init (Set 10, -1.0f)

Source: physics collision code. Initializes collision system global state block.

**Key logic:**
- DAT_007ccf80 = 10.
- Zeros _DAT_007ccf84, _DAT_007ccf8c.
- Sets _DAT_007ccf88 = 0xbf800000 (-1.0f).

**Globals:**
- `DAT_007ccf80` — collision global, int = 10
- `DAT_007ccf88` — collision global, float = -1.0f

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d100 — Collision Global Init (Set 0x6b, -1.0f)

Source: physics collision code. Initializes collision system global state block.

**Key logic:**
- DAT_007ccf60 = 0x6b (107).
- Zeros _DAT_007ccf64, _DAT_007ccf6c.
- Sets _DAT_007ccf68 = 0xbf800000 (-1.0f).

**Globals:**
- `DAT_007ccf60` — collision global, int = 0x6b
- `DAT_007ccf68` — collision global, float = -1.0f

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c5f0 — Collision Init Delegator (0xC5F0)

Source: physics collision code. Delegates to FUN_00587b3e with static data block.

**Key logic:**
- Calls FUN_00587b3e(LAB_0044c600). Sets up a collision data block from static template.

**Calls:** FUN_00587b3e (collision data block initializer)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cd70 — Collision Init Delegator (0xCD70)

Source: physics collision code. Delegates to FUN_00587b3e with static data block.

**Key logic:**
- Calls FUN_00587b3e(DAT_0044cd80).

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d550 — Collision Init Delegator (0xD550)

Source: physics collision code. Delegates to FUN_00587b3e with static data block.

**Key logic:**
- Calls FUN_00587b3e(PTR_LAB_0044d560).

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dcd0 — Collision Init Delegator (0xDCD0)

Source: physics collision code. Delegates to FUN_00587b3e with static data block.

**Key logic:**
- Calls FUN_00587b3e(DAT_0044dce0).

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e450 — Collision Init Delegator (0xE450)

Source: physics collision code. Delegates to FUN_00587b3e with static data block.

**Key logic:**
- Calls FUN_00587b3e(PTR_LAB_0044e460).

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ebd0 — Collision Init Delegator (0xEBD0)

Source: physics collision code. Delegates to FUN_00587b3e with static data block.

**Key logic:**
- Calls FUN_00587b3e(DAT_0044ebe0).

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0044aae0 — Recursive Triangle Edge Subdivision for Collision

Source: collision system. Recursively subdivides a triangle along its longest edge until all edges are below a threshold, then processes each sub-triangle for collision.

**Key logic:**
- Takes 3 triangle vertices (param_1, param_2, param_3) plus 2 output parameters
- Computes squared edge lengths using FUN_004484c0 (edge vector) + FUN_004484f0 (length squared)
- Finds the longest edge among the 3
- If longest edge > _DAT_0059ef38 (subdivision threshold): splits that edge at midpoint via FUN_00448480, creates 2 sub-triangles, recurses
- If all edges <= threshold: calls FUN_004493a0 to process the triangle (collision test/insertion)
- This is a standard BSP/collision mesh refinement — subdivide until triangles are small enough for collision testing

**Globals:**
- `_DAT_0059ef38` — double, subdivision threshold (max edge length)

**Calls:** FUN_004484c0 (edge vector calc), FUN_004484f0 (length squared), FUN_00448480 (edge midpoint), FUN_004493a0 (triangle collision processor)

**Moddability:** `configurable` — _DAT_0059ef38 threshold

<!-- target: docs/17-physics-collision.md -->

## FUN_0044b090 — Triangle Proximity Test

Source: collision system. Evaluates signed distance between two triangle/segment representations using quadratic forms.

**Key logic:**
- Takes two 6-element double arrays (param_1, param_2) representing triangle/segment coefficients
- Evaluates polynomial: `((a1 * x + b1) * x + (c1 * x + d1)) * x + e1` at point param_3 for both arrays
- Computes absolute difference between the two evaluations
- Compares against _DAT_0059ef40 threshold
- Returns 1 if difference < threshold (near-contact), 0 otherwise
- Used for determining if two collision primitives are close enough to generate a contact

**Globals:**
- `_DAT_0059ef40` — float, proximity threshold

**Moddability:** `configurable` — _DAT_0059ef40 threshold

<!-- target: docs/17-physics-collision.md -->

## FUN_0045bf90 — Collision Mutex Initialization

Source: thread synchronization. Creates a Win32 mutex for collision pipeline thread safety.

**Key logic:**
- Initializes DAT_007cd264 (handle) to 0, DAT_007cd26c to 0, DAT_007cd268 to -1
- Creates unnamed mutex via CreateMutexA with default security attributes (inheritable handle)
- On success: sets DAT_007cd26c = 1 (initialized flag)
- Provides mutual exclusion for collision system state access

**Globals:**
- `DAT_007cd264` — HANDLE, mutex handle
- `DAT_007cd26c` — int, initialized flag
- `DAT_007cd268` — int, lock state (-1 = unlocked)

**Calls:** CreateMutexA (Win32 API)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d760 — Collision Global Struct Init (Block 0x17)

Source: collision system. Initializes a global collision configuration block.

**Key logic:**
- Sets DAT_007ccc20 = 0x17 (block type/size identifier)
- Zeroes 5 consecutive int fields at offsets +0x24 through +0x34

**Globals:**
- `DAT_007ccc20` through `_DAT_007ccc34` — collision configuration variables

**Moddability:** `configurable` — initialization values

<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

## FUN_0044f640 — Cursor Selector from Array

Source: UI/collision visualization. Selects a cursor from an array by index and sets it via Win32 API.

**Key logic:**
- Bounds-checks param_2 against param_1 + 0xa8 (cursor array count)
- Looks up HCURSOR in array at param_1 + 0x30 with stride 0x14
- If non-null: calls SetCursor, stores selected index at param_1 + 0xac
- Returns 1 on success, 0 on failure

**Calls:** SetCursor (Win32 API)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c9e0 — Collision Global Struct Init (Block 0xB, unit default)

Source: collision system. Initializes a global collision configuration block with unit float.

**Key logic:**
- Sets DAT_007cccb0 = 0xB (block type/size identifier)
- Zeroes 2 int fields at +0xb4, +0xb8
- Sets DAT_007cccbc = 0x3F800000 (1.0f, default multiplier)

**Globals:**
- `DAT_007cccb0` through `_DAT_007cccbc` — collision configuration variables

**Moddability:** `configurable` — initialization values

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d160 — Collision Global Struct Init (Block 0x6C, unit default)

Source: collision system. Initializes a global collision configuration block with unit float.

**Key logic:**
- Sets DAT_007ccf70 = 0x6C (block type/size identifier)
- Zeroes 2 int fields at +0x74, +0x78
- Sets DAT_007ccf7c = 0x3F800000 (1.0f, default multiplier)

**Globals:**
- `DAT_007ccf70` through `_DAT_007ccf7c` — collision configuration variables

**Moddability:** `configurable` — initialization values

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c650 — Collision Init Registration (DAT_0044c660)

Source: collision system. Registers a collision data block with the initialization system.

**Key logic:**
- Calls FUN_00587b3e with pointer to DAT_0044c660 (collision data block)
- Registers the block for initialization/lookup

**Calls:** FUN_00587b3e (init registration)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cdd0 — Collision Init Registration (DAT_0044cde0)

Source: collision system. Registers a collision data block with the initialization system.

**Key logic:**
- Calls FUN_00587b3e with pointer to DAT_0044cde0

**Calls:** FUN_00587b3e (init registration)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d5b0 — Collision Init Registration (DAT_0044d5c0)

Source: collision system. Registers a collision data block with the initialization system.

**Key logic:**
- Calls FUN_00587b3e with pointer to DAT_0044d5c0

**Calls:** FUN_00587b3e (init registration)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dd30 — Collision Init Registration (DAT_0044dd40)

Source: collision system. Registers a collision data block with the initialization system.

**Key logic:**
- Calls FUN_00587b3e with pointer to DAT_0044dd40

**Calls:** FUN_00587b3e (init registration)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e4b0 — Collision Init Registration (DAT_0044e4c0)

Source: collision system. Registers a collision data block with the initialization system.

**Key logic:**
- Calls FUN_00587b3e with pointer to DAT_0044e4c0

**Calls:** FUN_00587b3e (init registration)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ec30 — Collision Init Registration (DAT_0044ec40)

Source: collision system. Registers a collision data block with the initialization system.

**Key logic:**
- Calls FUN_00587b3e with pointer to DAT_0044ec40

**Calls:** FUN_00587b3e (init registration)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004139c0 — CollisionShapeSizeClassify (AABB size classifier)

Source: likely collision/broadphase.cpp. Classifies collision shape by AABB size into discrete categories (0x20-0x2f).

**Key logic:**
- Only when param_2==0 AND param_4=='\0' (initial classification)
- Compares param_3 against 12 descending thresholds (_DAT_0059e420 through _DAT_0059e788)
- If size < 0x4b (75): class=0x2d; <0x6e (110): class=0x2e; >0x3e6 (998): class=0x30; else class=0x2f
- Maps into 16 size classes (0x20-0x2f)
- Writes class to param_1+8, calls FUN_00414180(0), returns 1 or -1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +8 | SizeClass | int, 0x20-0x2f |
| +0xc | SecondaryClass | int |

**Globals:** _DAT_0059e420–_DAT_0059e7e0 (thresholds)

**Calls:** FUN_00414180

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_004584c0 — CollisionResponseFilter (contact velocity resolution)

Source: likely collision/response.cpp. Applies restitution/penalty impulse on contact.

**Key logic:**
- Relative velocity = ABS(v3-v4)+ABS(v1-v2)
- Scaled: param_5 = fVar1 * *(param_1+0xa4) * param_5
- If velocity < scaled AND velocity > epsilon: compute ratio, clamp to 1.0, apply impulse via transforms
- Else: copy source velocity to output

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xa4 | RestitutionFactor | float |

**Globals:** _DAT_0059e440, _DAT_0059e43c

**Calls:** FUN_00455f90, FUN_00455fd0, FUN_00567030, FUN_00567580, FUN_00567010

**Moddability:** `configurable` — restitution from material properties

<!-- target: docs/17-physics-collision.md -->

## FUN_0044f0e0 — CollisionProxyUnregister (shape removal from collision space)

Source: likely collision/space.cpp. Removes proxy shape, clears slot, sets cooldown timer.

**Key logic:**
- Clears registration byte at (param_2+0x37c+param_1)
- Searches 256-entry array at param_1+0xc88 for proxy ID; zeroes on match
- If param_3<=0: clears timer at +0x87c[proxyID]
- If param_3>0: sets timer = _DAT_008afea8 + param_3

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d7c0 — CollisionStaticInit_18 (init 0x007ccc08)

**Key logic:** DAT_007ccc08=0x18; _DAT_007ccc0c through _DAT_007ccc1c=0

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044df40 — CollisionStaticInit_39 (init 0x007ccbc4)

**Key logic:** DAT_007ccbc4=0x39; _DAT_007ccbc8 through _DAT_007ccbd8=0

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e6c0 — CollisionStaticInit_55 (init 0x007cd064)

**Key logic:** DAT_007cd064=0x55; _DAT_007cd068–_DAT_007cd074=0; DAT_007cd078=27000

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0049e520 — RandomCollisionEvent (probabilistic collision trigger)

Source: likely collision/effects.cpp. Triggers collision event based on random threshold.

**Key logic:**
- Random from FUN_0058957a()
- If > _DAT_0059e880: high intensity event (param=1)
- Else: normal (param=0)

**Calls:** FUN_0058957a, FUN_0049e4e0

**Moddability:** `configurable`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ca40 — CollisionStaticInit_12 (init 0x007cca7c)

**Key logic:** DAT_007cca7c=0xc; _DAT_007cca84=0xbf800000 (-1.0f)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d1c0 — CollisionStaticInit_6d (init 0x007ccfa0)

**Key logic:** DAT_007ccfa0=0x6d; _DAT_007ccfa8=0xbf800000 (-1.0f)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c6b0 — CollisionDataTeardown (unregister)

**Key logic:** FUN_00587b3e(&PTR_LOOP_0044c6c0)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ce30 — CollisionDataTeardown_2

**Key logic:** FUN_00587b3e(&DAT_0044ce40)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d610 — CollisionDataTeardown_3

**Key logic:** FUN_00587b3e(&PTR_LAB_0044d620)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dd90 — CollisionDataTeardown_4

**Key logic:** FUN_00587b3e(&DAT_0044dda0)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e510 — CollisionDataTeardown_5

**Key logic:** FUN_00587b3e(&PTR_LAB_0044e520)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ec90 — CollisionDataTeardown_6

**Key logic:** FUN_00587b3e(&DAT_0044eca0)

**Moddability:** `hardcoded`

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00412c30 — MapCollisionShapeToBoneIndex

Source: unknown. Maps collision shape type IDs (1–0x32) to internal bone/skeleton indices with optional offset.

**Key logic:**
- Only operates when param_2 == 0
- Switch on param_3 (case 1 through 0x32):
  - Each case maps to a bone index: 0xbd (189) down to 0x99 (153)
  - If param_4 (offset flag) set: subtracts 1 from index
- If computed index >= 0: stores at param_1+8, calls FUN_00414180(0) to set related field at +0xc
- Returns 1 on success, -1 on failure

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | BoneIndex | int, set to mapped value |
| +0x0c | BoneRelatedValue | undefined4, set by FUN_00414180 |

**Calls:** FUN_00414180 (set bone-related value)

**Moddability:** `hardcoded` — bone mapping table fixed in code

<!-- target: docs/17-physics-collision.md -->

## FUN_0045f390 — RunCollisionDetectionLoop

Source: unknown. Runs a timed collision detection loop with sweep/response and timeout.

**Key logic:**
- Only runs if *(param_1+0x3fc4) == 3 (collision shape type)
- Sets up timer: calls FUN_00568ba0/0xbe0/0xc60 (timer init)
- Main loop with 4.0 second timeout (local_60 initialized to 4.0):
  - Calls FUN_0057a610 for collision query
  - If collision hit: calls FUN_004f9fc0, FUN_0042bda0, FUN_0042cf10, FUN_0045c8b0, FUN_004b0170 (collision response chain), returns 1
  - Accumulates elapsed time via FUN_00568cf0
- If loop times out: calls FUN_004b0170, returns 0

**Calls:** FUN_00568ba0/0xbe0/0xc60 (timer), FUN_0057a5a0 (collision sweep init), FUN_0057a610 (collision query), FUN_004f9fc0 (collision response), FUN_0042bda0, FUN_0042cf10, FUN_0045c8b0, FUN_004b0170 (cleanup), FUN_00568cf0 (timer query)

**Moddability:** `hardcoded` — 4.0s timeout constant

<!-- target: docs/17-physics-collision.md -->

## FUN_00455b30 — TranslateVirtualKey

Source: unknown. Translates a virtual key scancode to ASCII using WinAPI keyboard state. [PARTIAL — keyboard input, not collision]

**Key logic:**
- One-time init: gets keyboard layout via GetKeyboardLayout(0)
- Gets full keyboard state via GetKeyboardState
- Maps scancode param_1 via MapVirtualKeyExA
- Converts to ASCII via ToAsciiEx
- Calls FUN_00455580 for final character processing

**Globals:** DAT_007ccc04 (keyboard init flag), DAT_007ca508 (keyboard layout handle), DAT_007ccab0 (keyboard state buffer), DAT_007ccbc0/DAT_007ccfc0 (output buffers)

**Calls:** GetKeyboardLayout, GetKeyboardState, MapVirtualKeyExA, ToAsciiEx, FUN_00455580 (process key)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_00498740 — InitViewportDimensions

Source: unknown. Initializes viewport/window dimensions from global state variables.

**Key logic:**
- Reads DAT_007cb2fc, DAT_007cb300, DAT_007cb304 (screen/window dimensions)
- Writes to param_1+100, +0x68, +0x6c
- Calls FUN_0044f7d0 (float conversion), stores at +0x70
- Calls __ftol twice, stores at +0x5c, +0x60

**Globals:** DAT_007cb2fc, DAT_007cb300, DAT_007cb304 — viewport dimensions

**Calls:** FUN_0044f7d0 (float conversion), __ftol (float-to-int)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d820 — InitKeyboardAxis0

Source: unknown. Initializes keyboard axis state for device index 0.

**Key logic:**
- Sets DAT_007ccc50 = 25 (0x19)
- Zeros 5 consecutive uint fields at DAT_007ccc54–DAT_007ccc64

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

## FUN_0044e720 — InitMouseAxis

Source: unknown. Initializes mouse/pointer axis state.

**Key logic:**
- Sets DAT_007ccfc4 = 86 (0x56)
- Zeros 3 fields, sets DAT_007ccfd8 = 0

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044caa0 — InitMouseAbsAxisX

Source: unknown. Initializes absolute X-axis for mouse device.

**Key logic:**
- Sets DAT_007cd148 = 102 (0x66)
- Zeros two fields
- Sets DAT_007cd154 = 1.0 (0x3f800000)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d220 — InitMouseAbsAxisY

Source: unknown. Initializes absolute Y-axis for mouse device.

**Key logic:**
- Sets DAT_007ca4f8 = 60 (0x3c)
- Zeros two fields
- Sets DAT_007ca504 = 1.0 (0x3f800000)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c710 — RegisterInputDevice0

Thunk — delegates to FUN_00587b3e(&DAT_0044c720). Registers an input device class/metatable.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ce90 — RegisterInputDevice1

Thunk — delegates to FUN_00587b3e(&DAT_0044cea0). Registers an input device class/metatable.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d670 — RegisterInputDevice2

Thunk — delegates to FUN_00587b3e(&DAT_0044d680). Registers an input device class/metatable.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ddf0 — RegisterInputDevice3

Thunk — delegates to FUN_00587b3e(&DAT_0044de00). Registers an input device class/metatable.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e570 — RegisterInputDevice4

Thunk — delegates to FUN_00587b3e(&DAT_0044e580). Registers an input device class/metatable.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044ecf0 — RegisterInputDevice5

Thunk — delegates to FUN_00587b3e(&DAT_0044ed00). Registers an input device class/metatable.

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0044a700 — Collision Tree Node Deserializer

Source: unknown. Reads collision tree node from byte stream.

**Key logic:**
- Reads 4B header, validates == 4. Reads 1B type code.
- Type [-2, -1]: loads child from pool at +0x24 (stride 0x5c), calls FUN_00449f60
- Type [0, 1]: reads flag, loads child from +0x30 (stride 0x10), recursively reads 2 children
- Returns 0 on success, 0xffffffff on failure

**Struct offsets:** +0x8 (short, type); +0xa (ushort, flags); +0xc (int*, child data); +0x1c/+0x28 (int, pool counts); +0x24/+0x30 (int*, pool bases)

**Calls:** FUN_00566c00, FUN_00449f60

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004039c0 — BVH Nearest-Neighbor Query

Source: unknown. Traverses BVH to find closest node to a point.

**Key logic:**
- Computes squared distance from point to node center (+0x94/98/9c)
- Walks linked list via +0x110, advancing by +0x3c stride
- Returns closest node pointer or 0

**Struct offsets (node):** +0x3c (float, stride); +0x94/98/9c (float[3], center); +0x110 (int*, next)

**Globals:** _DAT_0059e470 (max search distance)

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004599c0 — Collision Contact Impulse

Source: unknown. Computes impulse/relative velocity at contact.

**Key logic:**
- Stores param_3, adds bias _DAT_0059e6f8
- Velocity components × inv mass, computes position delta
- Calls FUN_00569670 (cross product / impulse solve)

**Struct offsets:** +0x20/24 (float, contact params, param_1); +0xd8/e0/e8 (double, position, param_1); +0x4 (float, inv mass, param_2); +0x14/18/1c (float, position, param_2); +0x20/24/28 (float, velocity, param_2)

**Calls:** FUN_00569670

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00456f70 — Collision Coefficient Application

Source: unknown. Applies restitution/friction coefficient.

**Key logic:**
- Selects coefficient: _DAT_0059ef9c or _DAT_0059efa0 based on param_3
- If param_2==0: scales by _DAT_0059e670
- Calls FUN_00456fb0 with scaled coeff×param_4 + body value at +0xac

**Struct offsets:** +0xac (float, body collision base)

**Globals:** _DAT_0059ef9c, _DAT_0059efa0, _DAT_0059e670

**Calls:** FUN_00456fb0

**Moddability:** configurable — coefficients from globals

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d880 — Collision Subsystem Init (DAT_007ccc38)

**Key logic:** Sets DAT_007ccc38=0x1a, zeroes 5 following fields.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e000 — Collision Subsystem Init (DAT_007ccd80)

**Key logic:** Sets DAT_007ccd80=0x43, zeroes 5 following fields.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e780 — Collision Subsystem Init (DAT_007ccfec)

**Key logic:** Sets DAT_007ccfec=0x57, zeroes 4 fields, DAT_007cd000=9000.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cb00 — Collision Subsystem Init (DAT_007ccfdc)

**Key logic:** Sets DAT_007ccfdc=0x67, fields 0 and -1.0f.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d280 — Collision Subsystem Init (DAT_007ca57c)

**Key logic:** Sets DAT_007ca57c=0x3d, fields 0 and -1.0f.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c770 — Collision Callback Registration (DAT_0044c780)

**Key logic:** Calls FUN_00587b3e(DAT_0044c780).

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cef0 — Collision Callback Registration (DAT_0044cf00)

**Key logic:** Calls FUN_00587b3e(DAT_0044cf00).

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d6d0 — Collision Callback Registration (DAT_0044d6e0)

**Key logic:** Calls FUN_00587b3e(DAT_0044d6e0).

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044de50 — Collision Callback Registration (&PTR_LAB_0044de60)

**Key logic:** Calls FUN_00587b3e(&PTR_LAB_0044de60).

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e5d0 — Collision Callback Registration (DAT_0044e5e0)

**Key logic:** Calls FUN_00587b3e(DAT_0044e5e0).

**Calls:** FUN_00587b3e

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044f050 — Collision Node Property Setter

**Key logic:** Writes param_3 to param_2+0x27c+param_1. Sets byte property flag.

**Struct offsets (param_2):** +0x27c (byte[], properties)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0044b910 — Bounding Box Computation from Triangles

Source: collision/bvh. Computes bounding box from triangle vertices.

**Key logic:**
- Iterates over *param_2 triangles (count = param_2[0])
- For each triangle (3 verts): tracks min/max X and Z (Y/height) across all vertices
- Computes extents: fVar1 = (maxX-minX) * _DAT_0059ef48, fVar3 = (maxZ-minZ) * _DAT_0059ef48
- Stores center at param_1+8 (X) and param_1+0x18 (Z) with _DAT_0059e880 scale
- Computes inverse extents for X (param_1+0x10) and Z (param_1+0x20), 0 if extent==0

**Globals:**
- `_DAT_0059ef48` — extent scale factor
- `_DAT_0059e880` — center scale factor
- `_DAT_0059e420` — 1.0f (for inverse)
- `_DAT_0059e430` — 0.0f (zero check)
- `_DAT_0059ef30` — -FLT_MAX

**Moddability:** hardcoded

⌾ 886 — FUN_0044aa30

<!-- target: docs/17-physics-collision.md -->

<!-- target: docs/17-physics-collision.md -->


<!-- target: docs/17-physics-collision.md -->

## FUN_0044d8e0 — Initialize Collision Globals A

Source: collision init. Sets DAT_007ccde0=0x1b, zeros 5 following dwords (to +0x7ccdf4).

Globals: DAT_007ccde0–DAT_007ccdf4. Moddability: hardcoded.

**Orphan classification:** `game_logic_isolated` — no cross-refs found. Likely called from function pointer table during collision system startup.

⌾ 890 — FUN_0044e060 — Global Init (collision vars B)

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e7e0 — Initialize Collision Globals C

Source: collision init. Sets DAT_007cd080=0x58, zeros 4 dwords, sets DAT_007cd094=18000.

Globals: DAT_007cd080–DAT_007cd094. Moddability: hardcoded.

**Orphan classification:** `game_logic_isolated` — no cross-refs found. Likely called from function pointer table during collision system startup.

⌾ 892 — FUN_00455fd0

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cb60 — Initialize Collision Globals D

Source: collision init. Sets DAT_007cd108=0x68, zeros 2 dwords, sets DAT_007cd114=1.0f.

Globals: DAT_007cd108–DAT_007cd114. Moddability: hardcoded.

**Orphan classification:** `game_logic_isolated` — no cross-refs found. Likely called from function pointer table during collision system startup.

⌾ 894 — FUN_0044d2e0 — Global Init (collision vars E)

<!-- target: docs/17-physics-collision.md -->

## FUN_0045c7c0 — Short-to-Float Conversion

Source: math_util. Converts signed short to float with _DAT_0059e600 multiplier.

**Moddability:** hardcoded

⌾ 901 — FUN_004358f0

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0049f530 — ParamRangeClampedLerp

Source: physics/collision. Computes a clamped interpolated parameter with global scaling.

**Key logic:**
- Bounds check: param_1 must be in [0, 4] and param_3 != 0.0
- Switch on param_1 (as 0, 1, 2, 3, 4):
  - case 0: min=0, max=10000, fVar3 from FUN_0049b8d0()
  - case 1: min=120, max=280, fVar3 = _DAT_007c91b4 - _DAT_005acafc
  - case 2: min=120, max=280, fVar3 = _DAT_007c9174 - _DAT_005acafc
  - case 3: min=-3, max=100, fVar3 = _DAT_007c919c
  - case 4: min=0, max=12, fVar3 from FUN_00447bb0()
- Additional scaling based on case:
  - case 1-2: fVar3 = (fVar3 - _DAT_0059eac0) * _DAT_0059eab8 - _DAT_0059eab0
  - case 3-4: fVar3 = fVar3 * _DAT_005acb10
- Clamps fVar3 between param_1 (min) and param_3 (max)
- Stores range (max-min) at param_2+0x20
- Calls FUN_0049ed00, FUN_0049ed10, FUN_0049ed20 with interpolated values

**Globals:**
- `DAT_007c91b4`, `DAT_007c9174`, `DAT_007c919c` — parameter base values (case-dependent)
- `DAT_005acafc` — shared offset subtracted in cases 1,2
- `DAT_0059eac0`, `DAT_0059eab8`, `DAT_0059eab0` — linear transform coefficients
- `DAT_005acb10` — multiplier for cases 3,4

**Calls:** FUN_0049b8d0 (parameter lookup), FUN_00447bb0 (parameter lookup), FUN_0049ed00, FUN_0049ed10, FUN_0049ed20 (interpolation/posting)

**Moddability:** `configurable` — all globals can be tuned

<!-- target: docs/17-physics-collision.md -->

## FUN_00460dd0 — CollisionContactIteration

Source: physics/collision. Iterates collision objects and determines contact response type.

**Key logic:**
- Iterates through entries starting at DAT_005ec6d8 with stride 0x48c0 (per-vehicle/object collision state)
- For each entry where type == 2 (specific collision type):
  - Calls FUN_0045cbf0(iVar5, &local_4) — collision detection
  - Computes fVar1 = *pfVar3 / DAT_007d108c (normalized contact ratio)
  - If fVar1 > _DAT_0059e800 OR cVar2 != 0 (strong contact or special condition):
    - Calls FUN_004c7a70(0) — heavy contact response
    - If fVar1 > _DAT_0059e4dc OR |local_4| > _DAT_0059ea60: uVar6 = 0 (full response)
    - Else: uVar6 = 1 (partial response)
  - Else (light contact):
    - Calls FUN_004c7a70(1) — light contact response
    - uVar6 = 1
  - Calls FUN_004c7aa0(uVar6) — apply contact response type
- Loop ends when pointer reaches address 0x7c54d8

**Globals:**
- `DAT_005ec6d8` — base of collision object array (stride 0x48c0)
- `DAT_007d108c` — contact normalization divisor
- `DAT_0059e800` — heavy contact threshold (float)
- `DAT_0059e4dc` — full response threshold (float)
- `DAT_0059ea60` — angular threshold for partial response

**Calls:** FUN_0045cbf0 (collision detection per entity), FUN_004c7a70 (contact response setup), FUN_004c7aa0 (apply response)

**Moddability:** `configurable` — thresholds and normalization can be tuned

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c550 — CollisionNormalFromFeature

Source: physics/collision. Computes collision normal from a collision feature descriptor.

**Key logic:**
- Calls FUN_0044c4c0(param_1) to get collision feature pointer from descriptor
- If feature exists:
  - Dot product: fVar2 = param_1.x * feature.x + param_1.z * feature.z (doubled) + feature.w (bias)
  - Cross term: fVar3 = param_1.x * feature.z + param_1.z * feature.y (doubled) + feature.other
  - Computes normalization factor: sqrt(fVar2² + fVar3² + 1.0) using _DAT_0059e420 (=1.0)
  - Normalizes: result = -(fVar2, 1.0, fVar3) / sqrt(...) — produces 3D direction vector
- If no feature, returns without modifying param_2

**Globals:**
- `_DAT_0059e420` — constant 1.0 (identity component for normalization)

**Calls:** FUN_0044c4c0 (collision feature lookup from descriptor)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044efe0 — CollisionCullCleanup

Source: physics/collision. Releases collision culling resources.

**Key logic:**
- Sets param_1+0x278 = 0 (disable cull flag)
- If param_1+4 (cull object pointer) is not null:
  - Calls vtable method at +0x20 on the cull object (release/destroy)
  - Calls vtable method at +0x8 on the cull object (delete)
  - Sets param_1+4 = 0

**Calls:** vtable dispatch on cull object

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d940 — CollisionGlobalInitC

Source: physics/collision. Initializes collision globals at address range 0x007ccdc8.

**Key logic:**
- Sets DAT_007ccdc8 = 0x1c (28 — collision type/index)
- Zeroes 5 dwords at 0x007ccdcc, 0x007ccdd0, 0x007ccdd4, 0x007ccdd8, 0x007ccddc

**Globals:**
- `DAT_007ccdc8` — collision object index/type (int)
- `DAT_007ccdcc` through `DAT_007ccddc` — 5 zeroed fields

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e0c0 — CollisionGlobalInitD

Source: physics/collision. Initializes collision globals at address range 0x007ccd98.

**Key logic:**
- Sets DAT_007ccd98 = 0x45 (69 — collision type/index)
- Zeroes 5 dwords at 0x007ccd9c, 0x007ccda0, 0x007ccda4, 0x007ccda8, 0x007ccdac

**Globals:**
- `DAT_007ccd98` — collision object index/type
- `DAT_007ccd9c` through `DAT_007ccdac` — 5 zeroed fields

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e840 — CollisionGlobalInitE

Source: physics/collision. Initializes collision globals at address range 0x007cd01c.

**Key logic:**
- Sets DAT_007cd01c = 0x59 (89 — collision type/index)
- Zeroes 4 dwords at 0x007cd020, 0x007cd024, 0x007cd028, 0x007cd02c
- Sets DAT_007cd030 = 27000 (collision parameter/limit)

**Globals:**
- `DAT_007cd01c` — collision object index/type
- `DAT_007cd020` through `DAT_007cd02c` — 4 zeroed fields
- `DAT_007cd030` — collision limit (set to 27000)

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_00459950 — CollisionInvMassStore

Source: physics/collision. Stores mass and computes inverse.

**Key logic:**
- Receives 64-bit value (param_2, param_3) as double — the mass
- Computes dVar1 = _DAT_0059e420 / mass (1.0 / mass)
- Stores mass at param_1+0x180 and param_1+0x184
- Stores inverse at param_1+0x188 (as double)
- Calls FUN_005697a0(param_4) — likely moment of inertia setup

**Globals:**
- `_DAT_0059e420` — constant 1.0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x180 | MassLow | uint32, low part of mass double |
| +0x184 | MassHigh | uint32, high part of mass double |
| +0x188 | InvMass | double, 1.0/mass |

**Calls:** FUN_005697a0 (inertia setup)

**Moddability:** `configurable` — mass is an input parameter

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cbc0 — CollisionGlobalInitF

Source: physics/collision. Initializes collision globals at address range 0x007cd188.

**Key logic:**
- Sets DAT_007cd188 = 0x69 (105 — collision type/index)
- Zeroes _DAT_007cd18c
- Sets _DAT_007cd190 = 0xbf800000 (-1.0f as float)
- Zeroes _DAT_007cd194

**Globals:**
- `DAT_007cd188` — collision object index/type
- `DAT_007cd190` — initialized to -1.0f (invalid/null index sentinel)

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d340 — CollisionGlobalInitG

Source: physics/collision. Initializes collision globals at address range 0x007ca4d0.

**Key logic:**
- Sets DAT_007ca4d0 = 0x3f (63 — collision type/index)
- Zeroes _DAT_007ca4d4
- Sets _DAT_007ca4d8 = 0xbf800000 (-1.0f as float)
- Zeroes _DAT_007ca4dc

**Globals:**
- `DAT_007ca4d0` — collision object index/type
- `DAT_007ca4d8` — initialized to -1.0f (invalid/null index sentinel)

**Calls:** none

**Moddability:** `hardcoded`

**Orphan classification:** `game_logic_isolated` — no cross-refs found. Likely called from function pointer table during collision system startup.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c830 — ThunkCollisionInitA

Thunk — delegates to FUN_00587b3e(&DAT_0044c840) with a format string. No entry needed.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cfb0 — ThunkCollisionInitB

Thunk — delegates to FUN_00587b3e(&DAT_0044cfc0) with a format string. No entry needed.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d790 — ThunkCollisionInitC

Thunk — delegates to FUN_00587b3e(&DAT_0044d7a0) with a format string. No entry needed.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044df10 — ThunkCollisionInitD

Thunk — delegates to FUN_00587b3e(&PTR_LAB_0044df20) with a format string. No entry needed.

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e690 — ThunkCollisionInitE

Thunk — delegates to FUN_00587b3e(&DAT_0044e6a0) with a format string. No entry needed.

<!-- target: docs/17-physics-collision.md -->

## FUN_0045f2a0 — CollisionInvDistanceStore

Source: physics/collision. Computes and stores inverse of a distance value.

**Key logic:**
- Computes _DAT_0059e43c / param_2 (constant / distance)
- Stores result at param_1+4
- _DAT_0059e43c is likely 1.0f

**Globals:**
- `_DAT_0059e43c` — constant (likely 1.0f for reciprocal)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x04 | InvDistance | float, 1.0/distance |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0045ca20 — Terrain Surface Roughness/Height Sampling

Source: likely_collision_terrain.cpp. Samples surface properties from the terrain database at a given index, computes weighted average height/roughness, and caches results.

**Key logic:**
- Checks surface type at `(&DAT_005ef9a0)[param_2 * 0x1230]` — if not type 2 (valid surface), returns true with *param_3=0.0
- Calls FUN_0045c780(param_2) to get surface index pair (iVar2/iVar3)
- If iVar2 == 0: returns false with *param_3=9.999 (sentinel for invalid)
- Checks cached value at param_1+0x1124[iVar3]: if > 0, returns cached value
- Copies 8 dwords (0x20 bytes) from surface DB at param_1+iVar3×0x20+0x424 into local array
- Calls FUN_005890aa (sorting/filtering) with local data and reference function LAB_0045c760
- Computes normalization factor: 1.0 / rangeLength
- Averages values in range [iVar3...iVar3+rangeLength), weighting by normalization factor
- If param_2 == 0x10 (specific surface type): caches result to param_1+0x1124[param_2], clamps against DAT_007d108c, writes corrective offset to param_1+0x12c4+param_2×2
- Returns bVar7 (equals param_2==0x10)

**Globals:**
- `DAT_005ef9a0` — surface type database array, stride 0x1230 per entry
- `DAT_007d108c` — surface roughness/clamp threshold
- `_DAT_0059e7f8` — surface corrective scale factor

**Calls:** FUN_0045c780 (surface index lookup), FUN_005890aa (sort/filter), FUN_0045c7c0 (surface value read), FUN_0045c7a0 (surface write)

**Moddability:** `configurable` — DAT_007d108c may be a moddable threshold

<!-- target: docs/17-physics-collision.md -->

## FUN_0048c170 — Collision Animation Timer Update

Source: likely_collision_anim.cpp. Updates collision animation timer and dispatches collision events when timer exceeds threshold.

**Key logic:**
- Calls FUN_00486710 (collision system check) — if active, returns -1 (no collision ready)
- If param_1+0x304 (collisionActive flag) != 0:
  - Adds stored delta at param_1+0x318 to timer
  - If timer >= _DAT_0059e908 (collision event threshold):
    - Clamps timer: `timer - 0.5 * (timer - _DAT_0059e7fc)`
    - Calls FUN_00486720() repeatedly (collision event count iterator)
    - For each event: calls vtable+0xb8 (event dispatch) with isTyre param (val==4)
  - Returns 0 (timer active)
- Returns 0xffffffff (no collision active)

**Globals:**
- `_DAT_0059e908` — collision time threshold
- `_DAT_0059e450` — 0.5f (clamp half factor)
- `_DAT_0059e7fc` — collision clamp constant

**Calls:** FUN_00486710 (collision check), FUN_00498730 (timer read), FUN_00486720 (collision event iterator), called by collision manager update

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044f0a0 — BVH Tree Node Array Init

Source: likely_bvh.cpp. Initializes a bounding volume hierarchy node array with 256 entries and 12 leaf slots.

**Key logic:**
- Zeros 256 bytes at param_1+0x37c (per-node active flags)
- Zeros 256 ints at param_1+0x87c (per-node childIndices)
- Zeros 12 ints starting at param_1+0xc84, continuing at param_1+0xc88 (leaf nodes)
- Sets param_1+0xc84 = 0 first (node count)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x37c | NodeActiveFlags | byte[256], per-node active flag |
| +0x87c | ChildIndices | int[256], child node indices |
| +0xc84 | LeafCount | int, number of leaf nodes (0) |
| +0xc88 | LeafNodes | int[12], leaf node indices |

**Calls:** none, called by collision scene setup

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044fbe0 — Collision Object Destructor

Source: likely_collision_object.cpp. Releases a collision object through its vtable.

**Key logic:**
- Reads object pointer from param_1+0x80
- Sets param_1+0x2f4 = 0 (reference/state flag)
- If object exists: calls vtable+0x20 (destructor/cleanup), then vtable+8 (release/delete)
- Clears pointer at param_1+0x80

**Calls:** object vtable functions at +0x20 and +8

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d9a0 — Collision Globals Init #1 (DAT_007ccf30)

Source: likely_collision_globals.cpp. Initializes collision system global counters/state at 0x007ccf30.

**Key logic:**
- Sets DAT_007ccf30 = 0x2a (42, collision counter initial)
- Zeros DAT_007ccf34 through DAT_007ccf44 (5 consecutive dwords)

**Globals:**
- `DAT_007ccf30` — collision init value (42)
- `DAT_007ccf34-44` — collision counters zeroed

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e120 — Collision Globals Init #2 (DAT_007cd1a8)

Source: likely_collision_globals.cpp. Initializes collision system globals at 0x007cd1a8.

**Key logic:**
- Sets DAT_007cd1a8 = 0x46 (70)
- Zeros DAT_007cd1ac through DAT_007cd1bc (5 consecutive dwords)

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e8a0 — Collision Globals Init #3 (DAT_007ca534)

Source: likely_collision_globals.cpp. Initializes collision system globals at 0x007ca534.

**Key logic:**
- Sets DAT_007ca534 = 0x5a (90)
- Zeros DAT_007ca538 through DAT_007ca548 (5 consecutive dwords)

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0045be00 — Collision Penalty Scaler

Source: likely_collision_penalty.cpp. Returns the minimum of a function result and parameter times a penalty multiplier.

**Key logic:**
- Calls FUN_0045bb00() to get a severity/impact value
- If result < param_1: returns `param_1 * _DAT_0059f078` (proportional penalty)
- Otherwise: calls FUN_0045bb00() again and returns `result * _DAT_0059f078`

**Globals:**
- `_DAT_0059f078` — penalty scale factor

**Calls:** FUN_0045bb00 (collision severity query)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044cc20 — Collision Globals Init #4 (DAT_007ca3b8)

Source: likely_collision_globals.cpp. Initializes collision globals at 0x007ca3b8.

**Key logic:**
- Sets DAT_007ca3b8 = 0x1e (30)
- Zeros DAT_007ca3bc, DAT_007ca3c0
- Sets DAT_007ca3c4 = 0x3f800000 (1.0f, friction/restitution default)

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044fee0 — Collision Impulse Accumulator

Source: likely_collision_impulse.cpp. Accumulates 3-component double-precision collision impulse/force vectors.

**Key logic:**
- param_1+0x560 += param_2[0], param_1+0x568 += param_2[1], param_1+0x570 += param_2[2]
- param_1+0x578 += param_3[0], param_1+0x580 += param_3[1], param_1+0x588 += param_3[2]
- First 3 doubles: linear impulse accumulation
- Second 3 doubles: angular impulse accumulation

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x560 | LinearImpulseX | double, accumulated |
| +0x568 | LinearImpulseY | double |
| +0x570 | LinearImpulseZ | double |
| +0x578 | AngularImpulseX | double |
| +0x580 | AngularImpulseY | double |
| +0x588 | AngularImpulseZ | double |

**Calls:** none

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044c890 — Collision Init Wrapper (DAT_0044c8a0)

Source: likely_collision_init.cpp. Registers collision function table via FUN_00587b3e.

**Key logic:**
- Calls FUN_00587b3e with address DAT_0044c8a0 (collision function pointer table)

**Calls:** FUN_00587b3e (table registration)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d010 — Collision Init Wrapper (PTR_LAB_0044d020)

Source: likely_collision_init.cpp. Registers another collision function table.

**Key logic:**
- Calls FUN_00587b3e with PTR_LAB_0044d020

**Calls:** FUN_00587b3e (table registration)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d7f0 — Collision Init Wrapper (DAT_0044d800)

Source: likely_collision_init.cpp. Registers another collision function table.

**Key logic:**
- Calls FUN_00587b3e with DAT_0044d800

**Calls:** FUN_00587b3e (table registration)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044df70 — Collision Init Wrapper (DAT_0044df80)

Source: likely_collision_init.cpp. Registers another collision function table.

**Key logic:**
- Calls FUN_00587b3e with DAT_0044df80

**Calls:** FUN_00587b3e (table registration)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e6f0 — Collision Init Wrapper (DAT_0044e700)

Source: likely_collision_init.cpp. Registers another collision function table.

**Key logic:**
- Calls FUN_00587b3e with DAT_0044e700

**Calls:** FUN_00587b3e (table registration)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_00463d10 — Collision Parameter Dispatch

Source: likely_collision_config.cpp. Dispatches a parameter query to the setup/config system with session-specific data.

**Key logic:**
- Calls FUN_00500010 with _DAT_008afea0 (global param), param_2 (query key), and data from `&DAT_005f0708 + param_1 × 0x48c0` (session-specific config block)
- Returns 1 (success)

**Globals:**
- `_DAT_008afea0` — global configuration parameter
- `DAT_005f0708` — config array, stride 0x48c0 per session

**Calls:** FUN_00500010 (config query dispatch)

**Moddability:** `configurable` — reads from session config

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0044deb0 — CollisionDataFree

Source: Unknown. Frees collision data structure via cleanup function.

**Key logic:**
- Calls FUN_00587b3e with address of static data block DAT_0044dec0

**Calls:** FUN_00587b3e (data cleanup/deallocation)

**Moddability:** `hardcoded`

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0044c7d0 — StringLogDeallocate

Source: collision/debug. Calls FUN_00587b3e on DAT_0044c7e0.

**Calls:** FUN_00587b3e (string dealloc/log)

**Moddability:** hardcoded (debug)

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e630 — StringLogDeallocate2

Source: collision/debug. Calls FUN_00587b3e on DAT_0044e640.

**Calls:** FUN_00587b3e (string dealloc/log)

**Moddability:** hardcoded (debug)

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0044cf50 — Deferred Callback Registration (Collision)

Source: Unknown. Registers collision callback for deferred execution.

**Key logic:**
- Calls FUN_00587b3e with pointer to LAB_0044cf60 (collision callback)
- Thunk/registration wrapper

**Calls:** FUN_00587b3e (deferred function registration)

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0044d730 — GJKShapeDealloc

Source: Unknown. Frees collision shape/support data.

**Key logic:**
- Calls FUN_00587b3e(&DAT_0044d740) to deallocate static data

**Globals:**
- `DAT_0044d740` — static data address

**Calls:** FUN_00587b3e (deallocation)

**Moddability:** hardcoded


<!-- target: docs/06-session-race-logic.md -->

## FUN_0044c4c0 — SpatialGridQuery

Source: Unknown. Queries a 32x32 spatial grid for collision broad phase.

**Key logic:**
- If param_2+6 (collision node pointer) is non-null and node's +0x58 flag is clear: calls FUN_0044a070 (narrow-phase check), returns current node if valid
- If node invalid: zeroes param_2+6
- Transforms param_2 position to grid coordinates: iVar2 = round((x - origin_x) * inv_cell_size), iVar1 = round((z - origin_z) * inv_cell_size)
- Grid is 32x32 (0x20): checks if coords in [-1, 32) range and cell at param_1+0x28 + (iVar2*32+iVar1)*4 is occupied
- If cell occupied: calls FUN_0044aa30 (insert into grid / broad phase)
- Returns node pointer at param_2+6

**Calls:** FUN_0044a070 (narrow-phase check), FUN_0044aa30 (broad phase insert)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044a450 — CollisionMaterialLookup

Source: Unknown. Reads collision material properties from global lookup tables.

**Key logic:**
- If param_1 < 8: reads first value from DAT_007ca388[param_1], second value from DAT_007ca3a4 + param_1*-4 (stride back)
- If param_1 >= 8: reads first value from DAT_007ca3c0 + param_1*-4, second value from -(DAT_007ca36c + param_1*4)

**Globals:**
- `DAT_007ca388` — material property table (8 entries)
- `DAT_007ca3a4` — restitution/response table
- `DAT_007ca3c0` — extended material table
- `DAT_007ca36c` — extended response table

**Moddability:** `configurable` — lookup tables may be tunable parameters

<!-- target: docs/17-physics-collision.md -->

## FUN_0044d2e0 — CollisionGlobalsInit

Source: Unknown. Initializes global collision system parameters.

**Key logic:**
- Sets DAT_007ca410 = 0x3e (62 — iteration count or threshold)
- Sets _DAT_007ca414 = 0
- Sets _DAT_007ca418 = 0
- Sets _DAT_007ca41c = 0x3f800000 (1.0f)

**Globals:**
- `DAT_007ca410` — collision iteration count (0x3e = 62)
- `_DAT_007ca414`, `_DAT_007ca418`, `_DAT_007ca41c` — collision parameters

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_00464ef0 — FloatFractionFromInt

Source: collision/precision. Converts integer to float fraction using 104 iterations of FUN_00464b10, subtracts int * DAT_0059f138.

**Key logic:**
- Calls __ftol() to convert input to int
- Runs FUN_00464b10 in loop of 0x68=104 iterations
- Stores fVar3 - iVar1 * DAT_0059f138 as float at param_1+0x68

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x68 | float | computed fraction |

**Calls:** FUN_00464b10 (iterative lookup)

**Moddability:** hardcoded (104 iterations)

<!-- target: docs/17-physics-collision.md -->

## FUN_00455f90 — AngleWrap

Source: collision/math. Wraps angle to [-bound, bound] range.

**Key logic:**
- If *param_1 > DAT_0059efa4: *param_1 -= DAT_0059efa8
- If *param_1 < -DAT_0059efa4: *param_1 += DAT_0059efa8

**Globals:**
- `DAT_0059efa4` -- PI (half-range)
- `DAT_0059efa8` -- 2*PI (full-range)

**Moddability:** configurable (PI constants)

<!-- target: docs/17-physics-collision.md -->

## FUN_0049b200 — Random Color Generator

Source: Unknown. Generates a random 32-bit color value from seeded float.

**Key logic:**
- Calls FUN_0058957a with _DAT_008afea0 (random seed/state)
- Converts four float components to bytes via __ftol
- Packs into uint: ((word & 0xffff) << 8 | byte) << 8 | byte
- Returns RGBA-like packed color value

**Globals:**
- `_DAT_008afea0` — random seed/state float

**Calls:** FUN_0058957a (pseudo-random float generator)

<!-- target: docs/17-physics-collision.md -->

## FUN_00455fd0 — Angle Normalization / Wrap

Source: Unknown. Normalizes angle to range [-pi, pi] using reflection wrap.

**Key logic:**
- If *param_1 > _DAT_0059efa4 → *param_1 = _DAT_0059efa8 - *param_1
- If *param_1 < -_DAT_0059efa4 → *param_1 = _DAT_0059efa8 + *param_1
- _DAT_0059efa4 is likely pi (3.14159...), _DAT_0059efa8 is likely 2*pi

**Globals:**
- `_DAT_0059efa4` — pi constant
- `_DAT_0059efa8` — 2*pi constant

<!-- target: docs/17-physics-collision.md -->

## FUN_0044aa30 — BVHTreeTraversal

Source: Unknown. Recursive traversal of BVH/AABB tree for collision detection.

**Key logic:**
- Uses signed short at param_1+8 as node index
- If index < 0: leaf node, calls FUN_0044a070(param_2) (process primitive)
  - If index == -2: calls FUN_0044a070 again for both sides
- If index == 0: 2D axis test using DAT_007ca388 and DAT_007ca3a4 tables at index param_1+10
  - fVar4 = tableB[axis] * param_2[2] + tableA[axis] * param_2[0]
- If index != 0:
  - fVar4 = tableA[axis] * param_2[0] - tableB[axis] * param_2[2]
- Compares fVar4 against node bounds (*(param_1+0xc)[0] min, [1] max)
- If below max: recursive call FUN_0044aa30 (go deeper)
- Proceeds to sibling node (param_1+0xc + 0x10)
- If fVar4 < node+0x10 (min bound): branch left
- If fVar4 < node+0x14 (max bound): returns (miss)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x8 | NodeIdx | short, negative=leaf |
| +0xa | AxisIdx | short, picks comparison axis |
| +0xc | ChildPtr | pointer to child/sibling node |

**Globals:**
- `DAT_007ca388` — axis projection table A
- `DAT_007ca3a4` — axis projection table B

**Calls:** FUN_0044a070 (process leaf primitive), recursive self-call

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e060 — CollisionStateClear

Source: Unknown. Resets collision detection global state.

**Key logic:**
- Sets DAT_007ccd68 = 0x44 (68 = version/magic?)
- Clears _DAT_007ccd6c through _DAT_007ccd7c to 0 (5 dwords = 20 bytes)

**Globals:**
- `DAT_007ccd68` — version/magic byte
- `_DAT_007ccd6c` through `_DAT_007ccd7c` — 5 reset fields

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0049b630 — SpatialGridCell

Source: Unknown. Computes spatial grid cell index and intra-cell offset.

**Key logic:**
- Uses __ftol to convert double param_2 to integer cell index
- Stores cell index at *param_3
- Stores remainder: param_2 - (cellIndex * _DAT_0059f118) at *param_4

**Globals:**
- `_DAT_0059f118` — cell size constant (float)

**Moddability:** configurable — cell size from spatial grid setup

<!-- target: docs/17-physics-collision.md -->

## FUN_004491c0 — SATEdgeSeparationTest

Source: Unknown. Separating Axis Theorem edge-edge test between two collision shapes.

**Key logic:**
- Initializes state via `FUN_00448f00(local_48)` 
- Tests 3 edge directions from `param_2` via `FUN_00448fc0` — if any separates: returns 1
- Tests 3 edge directions from `param_1` via `FUN_00448fc0` — if any separates: returns 1
- Tests 3 edge-face combinations: for each edge of `param_2` against each edge+1 of `param_1`, calls `FUN_00449000` — if any separates: returns 1
- Returns 0 if no separating axis found (shapes intersect)

**Calls:** FUN_00448f00 (state init), FUN_00448fc0 (axis test), FUN_00449000 (edge-face test)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004527c0 — Conditional Collision Dispatch

Source: unknown | Confidence: high (collision/physics)
Calls FUN_0044f050 if *param_1 == 0. Guard pattern for collision/physics init.

**Key logic:**
- If *param_1 == 0: calls FUN_0044f050(param_1[1], param_1[2])
- Guard prevents re-initialization when flag already set

**Calls:** FUN_0044f050 (collision helper — unknown, in collision address range)

**Used by system:** docs/17-physics-collision.md — collision system init guard

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00490ee0 — Collision Broadphase Builder

Source: unknown | Confidence: high (collision)
Queries collision proxies via FUN_00490940/00491680/00491350. Builds linked list of intersecting proxies (allocates 0xc nodes via operator_new). Removes stale entries by matching iVar7, notifies via FUN_00491e10. Final cleanup: builds temp list via FUN_004bac20, merges via FUN_00490d00, iterates results via FUN_00434030/FUN_00581780.

**Calls:** FUN_00490940, FUN_00491680, FUN_00491350, FUN_00490aa0, FUN_004bac20, FUN_00490d00, FUN_00434030, FUN_00581780, FUN_00491db0, operator_new

<!-- target: docs/17-physics-collision.md -->

## FUN_00491ad0 — Collision Proxy List Builder (Iterative)

Source: unknown | Confidence: high (collision)
Iterates two passes (index 0, 1). For each: reads list head from param_1+0x1c (pass 0) or param_1+0x2c (pass 1). Walks short-indexed collision proxies via FUN_00490940. Appends matching entries to result list. Calls FUN_00490d00 to finalize.

**Calls:** FUN_004910d0, FUN_00490940, FUN_00490d00, operator_new

<!-- target: docs/20-math-utilities.md -->

## FUN_0048f0b0 — Short Computation (Scroll/Viewport Clamp with Collision Dispatch)

Source: unknown | Confidence: medium
Performs viewport/scroll boundary clamping, then dispatches to collision rendering/layout function.

**Key logic:**
- If param_2 != 0 AND flag at +0x17c set AND +0xe4 non-null:
  - Clamps horizontal scroll (param_3/param_4) against boundaries at +0x120 and +0x140
  - Clamps against sub-struct dimensions (+0x1c, +0x20)
  - Calls FUN_00495150(bounds...) — math_util
  - Calls FUN_00494a30(param_2, offsets...) — math_util short computation

**Calls:**
- FUN_00495150 — math_util short computation (triage index)
- FUN_00494a30 — math_util short computation (triage index)

**Used by system:** docs/17-physics-collision.md — viewport clamping with collision/layout dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00491170 — Collision Broadphase Traversal (Recursive)

Source: unknown | Confidence: medium
Recursive broadphase collision traversal. Walks linked list of collision proxy groups, performs broadphase tests (A and B), queries neighbors, and recurses into child groups.

**Key logic:**
- Reads current node from `*param_1`, stores in param_1[2]
- Null checks on node and its data pointer
- Loop:
  - Calls FUN_004915a0 (broadphase test A) — if true: returns 1
  - Calls FUN_00491680 (broadphase test B) — if true: breaks to neighbor query
  - Advances to next node via `param_1[2] + 4` (next pointer)
  - Null check on next node/data
- On broadphase B pass: calls FUN_00491350 (neighbor query)
  - If neighbor found: recursively calls FUN_00491170 on each neighbor
  - Tracks result bit in param_1._0_1_
- Calls FUN_00490aa0 (post-reindex) to clean up

**Calls:**
- FUN_004915a0 — broadphase test A (docs/17)
- FUN_00491680 — broadphase test B (docs/17)
- FUN_00491350 — neighbor query / rectangle clipping (docs/17)
- FUN_00490aa0 — post-reindex hook (docs/17)

**Used by system:** docs/17-physics-collision.md — recursive broadphase collision traversal

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00491c70 — Short Computation (Collision Query Wrapper)

Source: unknown | Confidence: medium
Thin wrapper for collision broadphase query: converts args, calls traversal, cleans up.

**Key logic:**
- Reads base from `*param_1`
- Calls FUN_00490940(param_4, param_5) — builds query object (95 lines, unknown)
- Calls FUN_00491170(base + 0xc, query) — recursive broadphase traversal
- Calls FUN_00490aa0() — post-reindex cleanup
- Returns traversal result

**Calls:**
- FUN_00490940 — builds query object (triage index)
- FUN_00491170 — recursive broadphase traversal (this docs entry)
- FUN_00490aa0 — post-reindex hook (docs/17)

**Used by system:** docs/17-physics-collision.md — collision query dispatch

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004046b0 — Memory Allocation / Waypoint-Like Struct Processing

Source: collision/session | Confidence: medium
Iterates an array of structs (stride 0x13c), processes a hierarchical linked structure. Applies position accumulation or halving based on a comparison.

**Key logic:**
- Iterates 0 to param_1+0x130 (count)
- Each element at param_1+0x134 + index*0x13c
- If element+300 < param_1+0x10: checks if element+300 == 1, then walks a linked list through +0x110 offsets accumulating `f32 at +0x4c += f32 at *(current+0x10c)+0x4c + f32 at *(current+0x10c)+0x3c`
- Else: calls FUN_004038e0(element, 1) (find nearest waypoint), if found: applies `f32 at element+0x4c = (f32 at (found+0x10c)+0x4c + f32 at found+0x4c) * 0.5 (DAT_0059e450)`

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10 | Threshold | int | Comparison threshold |
| +0x130 | ElementCount | int | Array length |
| +0x134 | ElementArray | int* | Array base (stride 0x13c) |

**Globals:**
- `DAT_0059e450` — 0.5f halving factor

**Calls:** FUN_004038e0 — find nearest waypoint

**Used by system:** docs/17-physics-collision.md — Waypoint/spline position propagation across vehicle chain.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00486830 — Unidentified / Collision Sweep/Test Dispatch

Source: collision/physics | Confidence: medium
Collision detection dispatch: calls virtual methods for shape data, then runs two collision tests.

**Key logic:**
- Calls virtual method at vtable+8 to get 4 shape/transform values into local vars
- Computes iVar2 = EBX - ESI and iVar3 = stack_14 - EBP (offsets/dimensions from register state)
- Calls FUN_00486730() — predicate/check
- If predicate true: runs FUN_00490920 (setup) then FUN_00491c70 (narrowphase test A)
  - If test A fails (returns 0): return 1
- If predicate false or test A passes: runs FUN_00490920 then FUN_00491cb0 (narrowphase test B)
  - return 2 if test B true, 0 otherwise

**Calls:**
- FUN_00486730 — predicate/condition check
- FUN_00490920 — setup/collision prep
- FUN_00491c70 — narrowphase test A
- FUN_00491cb0 — narrowphase test B (no docs)

**Used by system:** docs/17-physics-collision.md — Collision dispatch with two test paths.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00491280 — Unidentified / Linked List Collision Query Iteration

Source: collision/physics | Confidence: medium
Iterates a linked list of collision shapes, calling broadphase test on each.

**Key logic:**
- Reads head from *param_1, stores as current at param_1[2]
- If head non-null and *head (shape pointer) non-null:
  - Loop: calls FUN_00491680(4 short values from shape data) — broadphase test B
  - If test returns true: stop, return 1
  - Advance to next node (param_1[2]+4 = next)
  - Until list exhausted
- Returns 0 if no hit

**Calls:** FUN_00491680 — broadphase collision test B

**Used by system:** docs/17-physics-collision.md — Broadphase collision query over linked list.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_00491cb0 — Short Computation / Collision Query Dispatch

Source: collision/physics | Confidence: medium
Dispatches a collision query: gets a value, runs a linked list query, performs post-reindex.

**Key logic:**
- Reads this pointer from *param_1
- Calls FUN_00490940(param_4, param_5) — get query value from params
- Calls FUN_00491280(iVar1+0x1c, uVar3) — iterate collision list query
- Calls FUN_00490aa0() — post-reindex/cleanup
- Returns query result

**Calls:**
- FUN_00490940 — collision query value getter
- FUN_00491280 — linked list collision query iteration
- FUN_00490aa0 — post-reindex cleanup

**Used by system:** docs/17-physics-collision.md — Collision query dispatch with linked list iteration.

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00497260 — Short Computation / Collision Area Setup

Source: collision | Confidence: high
Sets up collision area: computes dimensions, calls setup and sweep functions.

**Key logic:**
- Calls FUN_004972b0(param_5, param_6, 1, param_1, param_2, param_3, param_4) — register area
- Computes width = param_2 - param_1, height = param_4 - param_3
- Calls FUN_00490920(param_3, param_1, height, width) — collision setup
- Calls FUN_00491960(param_3, param_1, height, width) — collision sweep/test

**Calls:**
- FUN_004972b0 — area registration
- FUN_00490920 — collision setup
- FUN_00491960 — collision sweep/test

**Used by system:** docs/17-physics-collision.md — Collision area definition and processing.

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004ba140 — Arithmetic/Comparison / Collision Proxy Field Setter

Source: collision | Confidence: high
Sets a byte field at a computed offset within a collision proxy or entity.

**Key logic:**
- Reads base pointer from param_1 + 8
- Writes param_2 (byte) to base + 0xf78

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | EntityPtr | Pointer to entity/proxy |
| EntityPtr+0xf78 | FlagField | Byte field set by this function |

**Used by system:** docs/17-physics-collision.md — Collision proxy flag setter.

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004bac20 — Short Computation / Collision Proxy Node Creator

Source: collision | Confidence: high
Creates/initializes a collision proxy list node.

**Key logic:**
- Sets param_1[0] = param_2 (proxy data pointer)
- Sets param_1[1] = 0 (next pointer)
- Sets byte at param_1+2 = param_3 (flag/type)

**Struct offsets (param_1 — node):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Data | Proxy data pointer |
| +0x04 | Next | Next node (null) |
| +0x08 | Flag | Byte flag/type |

**Used by system:** docs/17-physics-collision.md — Collision proxy node initialization.

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_004fb6d0 — Unidentified Logic / Collision Impulse/Response Computation

Source: physics/collision | Confidence: medium
Complex collision response computation: computes projected distance, applies thresholds, compares against two reference points.

**Key logic:**
- Computes delta vector: param_2 - param_1 (positions)
- Computes projected distance along param_1 direction vectors (+8,+9,+10)
- If projection >= 0: subtract offset at +0x17; else: negates + offset at +0x16
- First reference: gets pointer at param_1+0x44, computes normalized direction to target, dot product with delta minus distance
- If result > current: use as max
- Second reference: same at param_1+0x43
- Lower bound clamp: ABS(fVar4) - _DAT_0059e478

**Globals:**
- `DAT_0059e440` — zero threshold (~0.0f)
- `DAT_0059e43c` — 1.0f (normalization factor)
- `DAT_0059e5fc` — sentinel return value
- `DAT_0059e478` — lateral threshold

**Used by system:** docs/17-physics-collision.md — Collision impulse/constraint response computation.

**Algorithm family:** collision response math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bad70 — Collision Node List Insertion

Source: unknown | Confidence: medium
Inserts nodes into two separate linked lists within a collision structure. Handles primary and secondary allocation.

**Key logic:**
- If param_2 non-null: allocates 0xc-byte node, stores *param_2 as data, inserts into list at param_1[0..3]
- If param_3 flag set: allocates additional nodes with incremented values (stride 0x374), inserts into secondary list at param_1[4..7]

**Struct offsets (param_1):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x00 | ListA_Head | pointer | Primary list |
| +0x04 | ListA_Tail | pointer | |
| +0x08 | ListA_Last | pointer | |
| +0x0c | ListA_Count | int | |
| +0x10 | ListB_Head | pointer | Secondary list |
| +0x14 | ListB_Tail | pointer | |
| +0x18 | ListB_Last | pointer | |
| +0x1c | ListB_Count | int | |

**Calls:**
- operator_new (multiple calls)

**Used by system:** docs/17-physics-collision.md — collision structure node allocation

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004bda20 — Proximity Check with Tag Update

Source: unknown | Confidence: medium
3D distance check against two arrays of spheres. Tags matching entries with param_2.

**Key logic:**
- Iterates array at param_1+8 (count at +4): computes squared 3D distance from param_4 to each entry center (+0xc, +0x10, +0x14)
- If distance <= (entry radius + param_5)², and param_3 != entry+0x20, and entry+4 != param_2: sets entry+4 = param_2, calls FUN_0040f380(param_3)
- Repeats for second array at param_1+0x14 (count at +0x10)

**Struct offsets (entry):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x04 | Tag | int | Owner/type tag |
| +0x0c | CenterX | float | Sphere center |
| +0x10 | CenterY | float | |
| +0x14 | CenterZ | float | |
| +0x18 | Radius | float | Sphere radius |
| +0x20 | ExcludeTag | int | Exclude from matching |

**Calls:**
- FUN_0040f380 — callback on match

**Used by system:** docs/17-physics-collision.md — proximity detection

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004dc960 -- Ray-Sphere Intersection Test

Source: unknown | Confidence: high
3D ray-sphere intersection test with collision point and normal computation.

**Key logic:**
- Gets camera/ray origin from FUN_00542460
- Computes squared distance from origin to sphere center (param_2)
- Early exit if distance > param_5^2 (sphere radius squared)
- Computes full intersection via FUN_00542400, vtable+4 transform
- Returns 0 if intersection behind ray origin (dot < 0)
- Computes t-value and normal at intersection point
- Returns hit info in param_3 and param_4

**Algorithm family:** 3D ray-sphere intersection

**Used by system:** docs/17-physics-collision.md -- collision detection

<!-- target: docs/20-math-utilities.md -->

## FUN_0054eb40 — 2D/3D Triangle Point Test

Source: unknown | Medium. Point-in-triangle test with 6 cases (0-5). Cases 0/1: XY plane, checks cross products against DAT_0059e440 threshold. Cases 2/3: XZ plane variant. Cases 4/5: uses FUN_0054ee90 (distance/angle test) with winding-aware results. Returns 0 (outside) or 1 (inside). **Globals:** DAT_0059e440. **Calls:** FUN_0054ee90. **Used by system:** docs/17-physics-collision.md. **Algorithm family:** collision/point-in-triangle. **Moddability:** hardcoded.

<!-- target: docs/20-math-utilities.md -->

## FUN_004b5630 — Collision Filter/AABB Cull

Source: unknown | Confidence: medium
Filters a collision list by AABB proximity, removing out-of-range elements.

**Key logic:**
- Walks list at +0x20, cursor at +0x28
- For each node (data at `*piVar1`): checks proximity via FUN_005001d0()/FUN_005001f0() and AABB distance (`ABS(float diff) <= DAT_005acd30`)
- If in range: keeps node, appends to second linked list at +0x10 (insertion at head)
- If out of range: unlinks from source list, decrements count, frees if flag set
- Nodes in range get re-inserted at head of list at +0x10 using +4 as next link

**Globals:** `DAT_005acd30` — AABB threshold

**Calls:** FUN_005001d0/f0, FUN_004b0170, FUN_00587bcf, operator_new, FUN_004bac20

**Used by system:** docs/17-physics-collision.md — collision/AABB culling

**Moddability:** configurable — DAT_005acd30 is threshold

<!-- target: docs/08-file-formats.md -->

## FUN_004038e0 — Spatial Nearest-Neighbor Query with Plane Test

Source: unknown | Confidence: high
Searches array of spatial elements (stride 0x13c) for nearest to query point with optional filter.

**Key logic:**
- Iterates elements, finds minimum squared distance
- Optional filter: param_3 matches element type at +300
- Plane test using normals at +0xa4, +0xac against DAT_0059e440
- Returns element ID at +0x110 or 0

**Struct offsets (element stride 0x13c):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x94 | float | Position X |
| +0x98 | float | Position Y |
| +0x9c | float | Position Z |
| +0xa4 | float | Normal X |
| +0xac | float | Normal Z |
| +0x110 | int | Return value |
| +0x12c | int | Type filter field |

**Globals:**
- `DAT_0059e440` (ZeroThreshold) — plane test epsilon

**Algorithm family:** spatial query

**Used by system:** docs/17-physics-collision.md — collision query

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00405e60 — Physics Collision Response Computation

Source: unknown | Confidence: medium
Computes collision response with velocity, position, and threshold checks.

**Key logic:**
- Checks param_2 against _DAT_0059e4d8 threshold
- Stores vec3 inputs, calls virtual methods
- Computes factor, caps at _DAT_0059e43c
- Computes delta vector + length or skips based on flag bit 3

**Globals:**
- `_DAT_0059e4d8` — threshold
- `_DAT_0059e43c` — cap constant
- `DAT_0059e440` — ZeroThreshold

**Used by system:** docs/17-physics-collision.md — contact resolution

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_004070e0 — Spatial Query with Weighted Distance Selection

Source: unknown | Confidence: medium
Selects best match from spatial entries by weighted squared distance ratio.

**Key logic:**
- Iterates array (stride 0x14) at *(param_1+0x48)
- Weighted comparison: 2^weight * query_dist^2 < entry_dist^2 * 2^entry_weight
- Dispatches vtable+8 on winner

**Used by system:** docs/17-physics-collision.md — spatial optimization

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_0044e1e0 — Collision Global Init (Group 0x48)

Source: collision init. Sets DAT_007ccf48=0x48, zeroes 4 fields, DAT_007ccf5c=18000. Not previously documented.

**Key logic:**
- DAT_007ccf48 = 0x48 (72)
- Zeros _DAT_007ccf4c, DAT_007ccf50, _DAT_007ccf54, _DAT_007ccf58
- DAT_007ccf5c = 18000
- Part of collision system initialization table (no direct callers found)

**Globals:** DAT_007ccf48, _DAT_007ccf4c, DAT_007ccf50, _DAT_007ccf54, _DAT_007ccf58, DAT_007ccf5c

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/17-physics-collision.md -->

## FUN_0044e240 — CollisionAntiRollInit

Source: collision_init.cpp. Initializes block with type 0x49 (73) and int value 27000.

**Key logic:**
- Sets DAT_007cd1d8 = 0x49 (73 = block type)
- Zeros 3 adjacent dwords
- Sets DAT_007cd1ec = 27000 (collision range/force limit)
- 27000 suggests a force threshold or distance limit

**Globals:**
- DAT_007cd1d8 — block type 0x49
- DAT_007cd1ec — limit value 27000

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->

## FUN_0044dee0 — Collision Init (Slot 0x38)

Source: collision_init_table.cpp. Initializes one slot of collision global state data block at 0x007ccbdc.

**Key logic:**
- Sets `DAT_007ccbdc = 0x38` (56) — collision slot index/type identifier
- Zeros 5 adjacent dwords (`_DAT_007ccbe0` through `_DAT_007ccbf0`) — collision state fields

**Globals:**
- `DAT_007ccbdc` — collision slot index (56 / 0x38)

**Called by:** collision_init_table_loop (unknown address) — one of many similar init functions called from a table-driven initialization loop during collision system startup.

**Call pattern:** Identical to FUN_0044d3a0, FUN_0044ea20, and ~50 other collision init functions — each writes a unique slot ID and zeros adjacent state. The slot addresses are non-consecutive, suggesting entries in different collision subsystems (broadphase, material, region, spatial).

**Moddability:** `hardcoded` — static init pattern

<!-- target: docs/17-physics-collision.md -->

## FUN_004c9820 — Virtual State Check via Index

Source: collision_manager.cpp. Queries state of an indexed sub-object by virtual dispatch.

**Key logic:**
- Computes pointer from array at `param_1 + 0x20` indexed by `*(param_1 + 0x1c)`
- If non-null, calls virtual method at `vtable+0x1c` on the sub-object
- Returns 1 if virtual call result != 2, else 0

**Struct offsets (param_1):**
| Offset | Type | Purpose |
|--------|------|---------|
| +0x1c | int | Index into sub-object array |
| +0x20 | void** | Array of sub-object pointers |

**Virtual dispatch:**
- Calls `subobj->vtbl[0x1c/4](subobj)` — vtable offset 0x1c (method slot 7)
- Return value 2 appears to be a "busy/deactivated" sentinel

**Used by:** collision or spatial manager — checks whether a specific indexed collider/spatial node is available (not in state 2).

**Moddability:** `hardcoded` — interface contract

## FUN_0044cf80 — Collision/Audio Init Block (Type 0x27)

Initializes a global config block at DAT_007ca480 with type 0x27.

**Key logic:**
- Sets DAT_007ca480 = 0x27 (type/magic identifier)
- Zeroes DAT_007ca484
- Sets DAT_007ca488 = 0xbf800000 (-1.0f — default extent/minimum)
- Zeroes DAT_007ca48c

**Globals:**
- `DAT_007ca480` through `_DAT_007ca48c` — config block (type=0x27, float extent=-1.0f, zeroed fields)
- NOTE: DAT_007ca480 is listed in docs/12 as AudioBufferObject but also referenced in collision context. Value 0x27 suggests a type identifier rather than a pointer.

**Reason orphaned:** Called via function pointer array during subsystem init. Same pattern as other collision/audio init functions (FUN_0044c9e0, FUN_0044d520, etc.). Triaged as "collision" but may be audio-related — globals overlap with audio system address range.

---

<!-- target: docs/17-physics-collision.md -->

### FUN_0044e660 — Collision Region Init 84 (Block 0x007cd04c)

Static initializer for collision region descriptor at 0x007cd04c. Sets type=84 (0x54), zeros, and sets DAT_007cd060=18000 (10-minute timer or distance threshold). Called during collision system startup.

**Globals:**
- `DAT_007cd04c` — region type ID (referenced by FUN_00452b10)
- `DAT_007cd060` — threshold value 18000

**Moddability:** `hardcoded`

### FUN_0046c710 — Global Array Scan for Negative

Scans collision-related global arrays (DAT_007cd470 or DAT_007cd2b8) looking for negative values. Branches on byte at param_1+0x174 to select which array to scan. Returns count of entries before first negative value found.

**Key logic:**
- If param_1+0x174 == 0: scan DAT_007cd470 (0x007cd470 to 0x007cd610, 0xA0/4=40 entries)
- If param_1+0x174 != 0: scan DAT_007cd2b8 (0x007cd2b8 to 0x007cd458, ~0x1A0/4=104 entries)
- Returns index of first negative entry, or total count if none found

**Globals:**
- `DAT_007cd470` — first collision data array (40 entries)
- `DAT_007cd2b8` — second collision data array (104 entries)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x174 | ArraySelector | byte, 0=first array, non-zero=second array |

**Moddability:** `hardcoded`

### FUN_00486300 — UI String Accessor

Returns a string pointer from a UI struct. Takes `this` pointer (param_1, __fastcall), checks field at offset +200 (0xC8). If null, returns null. Otherwise dereferences +200 as pointer and returns string at +0x50 within that sub-struct. Falls back to DAT_005ea438 (directory path) if sub-string is null.

**Key logic:**
- if *(param_1+200) == 0: return null
- else: return *(*(param_1+200)+0x50) or DAT_005ea438 as fallback

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xC8 | SubObjectPtr | pointer to sub-object containing string |
| +0x50 (sub) | DisplayString | string pointer |

**Globals:**
- `DAT_005ea438` — directory path default fallback string

**Moddability:** `hardcoded`

<!-- target: docs/20-math-utilities.md -->

## FUN_0044cdb4 — CollisionScaleInit

Source: collision_init.cpp. Initializes two collision grid scale parameters.

**Key logic:**
- Sets flt_7CD100 = 0.0f (CollisionScale0 — min scale)
- Sets dword_7CD104 = 1065353216 = 0x3F800000 = 1.0f (CollisionScale1 — default unit scale, see docs/12)

**Globals:**
- `DAT_007CD100` — CollisionScale0, float, collision grid min scale (new global)
- `DAT_007CD104` — CollisionScale1, float, collision grid unit scale = 1.0f (docs/12)

**Calls:** none (leaf init function)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_00520CE0 — TriangleClosestPointOrNormal

Source: Unknown (collision geometry). Computes closest point on a triangle to origin, or triangle face normal with area scaling.

**Key logic:**
- Takes two float* params: a1 = output (4 floats), a2 = input triangle (12 floats = 3 vertices × 3 axes)
- Computes sum of squares of first column of each vertex: `*a2 + a2[5] + a2[10]` = squared corner radius check
- If sum >= flt_8D627C (threshold): triangle is "large enough" — compute face normal via cross product
  - `a1[3] = sqrt(sum + flt_8D6280) * flt_8D6284` — scaled triangle area
  - Normal = (v0v2 × v0v1) / area: `a1[0..2] = cross(a2[6-8], a2[9-11])...` 
- If sum < threshold (degenerate/small triangle): find the longest edge, compute closest point on that edge
  - Picks edge index v8 based on which vertex pair has smallest projection
  - Uses dword_8D6270[v8] to get next vertex index in triangle
  - Computes closest point on edge with scaled distance check
  - Returns point on edge + scaled edge direction

**Globals:**
- `flt_8D627C` — collision geometry threshold (min triangle size for face normal)
- `flt_8D6280` — bias added to squared-sum before sqrt
- `flt_8D6284` — area scaling factor
- `flt_8D6288` — inverse area factor for normal
- `dword_8D6270` — triangle vertex index lookup table (3 entries, cyclical: [1,2,0])
- `flt_8D6290` — edge-distance bias
- `flt_8D6294` — edge-length scaling factor
- `flt_8D6298` — inverse edge-length factor

**Moddability:** `hardcoded` — pure collision geometry math; thresholds/constants are physics state params

<!-- target: docs/20-math-utilities.md -->

## FUN_0050E491 — RayPlaneIntersect

Source: Unknown (collision). Computes intersection point of a line segment (a3→a4) with a plane defined by a2.

**Key logic:**
- Takes a1 = output point (3 floats), a2 = plane (4 floats: normal xyz + d), a3 = line start, a4 = line end
- v4 = dot(normal, start) = a2·a3 (signed distance from plane to start)
- v5 = v4 − dot(normal, end) = a2·a3 − a2·a4
- If v5 == 0: line parallel to plane, return null
- t = (v4 + plane[3]) / v5 — interpolation parameter along line
- Calls sub_58A88F to validate t (must be in [0,1] range)
- If invalid, return null
- Output point = start + t*(end − start)

**Calls:** FUN_0058A88F (float range check)

**Moddability:** `hardcoded`

<!-- target: docs/01-engine-architecture.md -->

## FUN_00401910 — Swept Suspension Collision Detection

Source: unknown (wheel suspension / collision). Swept collision test between suspension contact points and track surface over a time interval. Finds exact time of closest approach for each wheel contact pair.

**Key logic:**
- Reads element count from param_1+0x130, base array pointer from param_1+0x134
- Each element (stride 0x13c = 316 bytes) is a wheel contact state struct
- **First loop (lines 25–36):** pre-computes extrapolated position for each wheel: `swept_pos = wheel_time * velocity + origin_pos`
  - wheel_time at +0x18 (float), velocity at [8],[9],[10] (vx,vy,vz), result at [0x25],[0x26],[0x27] (swept x,y,z)
- **Second loop (lines 38–105):** for each element, checks collision between two objects referenced at +0x10c and +0x110 (suspension geometry and collision contact pointers)
  - Calls FUN_00401340 (suspension force transform, docs/10) to compute world-space coordinates for each element
  - Calls FUN_004e8ce0 (TireForceSolver, docs/06) to evaluate contact force/penetration at current time
  - Selects the minimum penetration depth among both objects at each time sample
  - **Sweep loop (lines 65–96):** steps time from `wheel_time - Flt_CollisionTolerance` to `wheel_time + TileSteppingMultiplier` by `FrameDelta` increments
  - At each step, evaluates swept position and re-evaluates contact forces; tracks the time that gives the deepest (most negative) penetration
  - After sweep, writes final contact position at optimal time to [0x25],[0x26],[0x27]

**Struct offsets (param_1, array element stride 0x13c):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x130 | count | number of wheel contact elements |
| +0x134 | array_ptr | pointer to wheel contact array (stride 0x13c) |
| +0x00–0x08 | origin_pos | x, y, z position at start of frame (floats) |
| +0x18 | wheel_time | time parameter for this wheel's integration step |
| +0x20–0x28 | velocity | vx, vy, vz (floats, indices [8],[9],[10]) |
| +0x70 | contact_params | contact evaluation parameters (indices [0x1c],[0x1d],[0x1e]) |
| +0x94–0x9c | swept_pos | extrapolated/swept position (indices [0x25],[0x26],[0x27]) |
| +0x10c | susp_geom_ptr | suspension geometry pointer (collision object A) |
| +0x110 | contact_ptr | collision contact surface pointer (collision object B) |

**Globals:**
- `_DAT_0059e44c` (Flt_CollisionTolerance) — subtractive offset from wheel_time defining sweep start
- `_DAT_0059e448` (TileSteppingMultiplier) — additive offset from wheel_time defining sweep end
- `_DAT_0059e444` (FrameDelta = 0.016667) — time step for sweep loop (1/60s)

**Calls:**
- FUN_00401340 — Vehicle Suspension Force Calculation / coordinate transform (docs/10)
- FUN_004e8ce0 — TireForceSolver: computes tire contact force/penetration (docs/06)

**Used by system:** docs/20-math-utilities.md (physics collision detection)

**Moddability:** `hardcoded` — sweep range controlled by global constants

<!-- target: docs/02-ai-system.md -->

## FUN_004493a0 — Triangle Mesh Adjacency Builder

Source: mesh_adjacency.cpp | Confidence: medium
Adds a triangle to a half-edge adjacency structure for a mesh, growing the container as needed.

**Key logic:**
- Container header at param_1: [0]=count, [1]=capacity, [2]=data ptr, [3]=aux1 ptr, [4]=aux2 ptr
- If count ≥ capacity: grows container by +0x2000 entries (0x20 bytes each), copies old data via 8-int copy loop, frees old buffer
- Allocates new element slot at data_ptr + (count × 0x20), increments count
- Calls FUN_00448ec0 (init element) and FUN_00448480 (copy vertex data between param_2/3/4)
- If aux1 (param_1[3]) null: allocates 0x60 bytes, calls FUN_00448510 (init)
- If aux2 (param_1[4]) null: allocates 0x60 bytes, calls FUN_00448510 (init)
- Stores 3 face IDs from FUN_004485d0 into new element slots 0,2,4
- Iterates 3 edges (slots 1,3,5): for each edge, searches existing elements for shared vertex pairs
  - Each element at +0x18 has neighbor count (clamped to 0xb=11), neighbor pointers at +0x1c
  - If adjacency match found: copies existing neighbor link; else: allocates new link
- Updates neighbor links: appends current element to each of the 6 neighbor lists
- If param_6 != 0: copies 3 material/UV entries (2 ints each) from param_6 into element data

**Calls:**
- FUN_00448480 — copy vertex data (3×)
- FUN_00448510 — init auxiliary buffer
- FUN_004485d0 — get/store element ID
- FUN_00448e50 — free auxiliary buffer
- FUN_00448e90 — init element
- FUN_00448ec0 — setup new element
- FUN_00587bcf — operator delete[] (free old buffer)

**Used by system:** docs/19-renderer.md

**Moddability:** `hardcoded` — renderer mesh infrastructure

<!-- target: docs/20-math-utilities.md -->

## FUN_004a5fa0 — Vehicle Proximity Collision Detection

Source: vehicle_collision.cpp | Confidence: medium
Detects proximity between a vehicle and a tracked reference point, computes directional alignment, and triggers state change.

**Key logic:**
- Reads vehicle pointer from `*param_1`
- Calls FUN_00403f70(vehicle+0x48a4, &local_48, local_3c) — gets reference position from render handle
- Calls FUN_004efb20(&local_54, local_30) — gets vehicle world position and orientation
- Computes delta vector (dx, dy, dz) = vehicle_position - reference_position
- If distance² ≤ _DAT_0059e8a0 (proximity threshold):
  - Calls FUN_00566e40() (compute orientation data)
  - Computes fVar4 = dot(direction_vector, delta) — alignment of approach
  - Compares fVar4 against thresholds _DAT_0059e8a4, _DAT_0059f11c, _DAT_0059e908
  - Accesses vehicle rotation/direction at +0x34c4, +0x34d0, +0x34dc
  - Accesses vehicle velocity at +0x34f8, +0x34fc, +0x3500
  - Checks velocity magnitude (fVar1 = SQRT(vx²+vy²+vz²)) against _DAT_0059e46c / _DAT_005acb50
  - Returns uint with encoded comparison flags (bits 8/10/14: less/NaN/equal)
  - If conditions pass AND vehicle+13000 (ComponentType) == 0 AND DAT_007ce7a8 != 0: calls FUN_004a5c80(4)
- If distance² > threshold:
  - Calls FUN_00566e40()
  - Computes dot product, returns comparison flags via POPCOUNT test
  - Falls through to same state-change check

**Struct offsets (param_1 → vehicle struct):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x48a4 | ResourceID/TeamID | Render handle for position query (int) |
| +0x34c4 | DirY | Orientation/rotation component (float) |
| +0x34d0 | DirZ | Orientation/rotation component (float) |
| +0x34dc | PosZ / GridForwardDirZ | Position or direction Z (float) |
| +0x34f8 | VelocityX / RefCoeffX | Velocity component X (float) |
| +0x34fc | VelocityY / RefCoeffY | Velocity component Y (float) |
| +0x3500 | VelocityZ / RefCoeffZ | Velocity component Z (float) |
| +13000 (0x32C8) | ComponentType | Vehicle active flag (0 = active) |

**Globals:**
- `_DAT_0059e8a0` — proximity distance² threshold
- `_DAT_0059e8a4` — alignment dot threshold (reverse gear / pit stop)
- `_DAT_0059f11c` — secondary dot threshold
- `_DAT_0059e908` — collision time threshold / reverse dot threshold
- `_DAT_0059e46c` — velocity comparison threshold
- `_DAT_005acb50` — alternate velocity threshold
- `DAT_0059e440` (ZeroThreshold ~0.0f, docs/06)
- `DAT_007ce7a8` — BrakeDiffSettings byte (docs/12)

**Calls:**
- FUN_00403f70 — render delegate (position from resource handle)
- FUN_004efb20 — vehicle world position / 3D transform (docs/18)
- FUN_00566e40 — EulerToRotationMatrix (docs/18)
- FUN_0042adb0 — Session Cleanup Flag Clear (docs/02)
- FUN_004a5c80 — StateChangeNotify (docs/06)

**Used by system:** docs/17-physics-collision.md

**Moddability:** `configurable` — all threshold globals (_DAT_0059e8a0, _DAT_0059e8a4, etc.) adjustable

<!-- target: docs/17-physics-collision.md -->

## FUN_004dd9f0 — Triangle Normal Computation

Source: math_triangle.cpp | Confidence: high
Computes a normalized triangle normal from 3 input points.

**Key logic:**
- Takes 3 points (param_1, param_2, param_3) and output param_4 (normal vector)
- Computes cross product: normal = (p3-p2) × (p1-p2)
  - X = (p3.z-p2.z)*(p1.y-p2.y) - (p3.y-p2.y)*(p1.z-p2.z)
  - Y = (p3.x-p2.x)*(p1.z-p2.z) - (p3.z-p2.z)*(p1.x-p2.x)
  - Z = (p3.y-p2.y)*(p1.x-p2.x) - (p3.x-p2.x)*(p1.y-p2.y)
- Computes magnitude² = X² + Y² + Z²
- If magnitude² ≤ _DAT_0059e430 (zero threshold ≈ 0.0): degenerate triangle — returns 0xFFFFFFFF (-1), uses 1.0 for normalization
- Else: normalizes by scale = _DAT_0059e420 (1.0) / SQRT(magnitude²)
- Stores X×scale, Y×scale, Z×scale in param_4[0..2]
- Returns 0 on success, -1 on degenerate triangle

**Globals:**
- `_DAT_0059e430` — zero comparison threshold (~0.0f)
- `_DAT_0059e420` — 1.0 constant (docs/06)

**Calls:** none

**Used by system:** docs/17-physics-collision.md

**Moddability:** `hardcoded` — pure math utility

<!-- target: docs/17-physics-collision.md -->

## FUN_004fb2e0 — Vehicle Proximity / Collision Avoidance Radar

Source: vehicle_collision_avoid.cpp | Confidence: medium
Computes closest-approach distance between own vehicle trajectory and up to 2 opponent vehicles.

**Key logic:**
- Reads own vehicle state at param_1[0x43] (state flag), param_1[0x44] (ptr to other vehicle A), param_1[0x45] (ptr to other vehicle B)
- Guard: exits if state == 0, opponent A null, or opponent A's state flag == 0
- For opponent A:
  - Computes steering alignment fVar7 = -own[0x2b]*opponent[0x29] + own[0x29]*opponent[0x2b]
  - If fVar7 outside range [_DAT_005ad280, _DAT_005ad278]: steering divergence — computes 2D line intersection of trajectories
  - If pfVar3 == param_1 (self-reference): sets param_1[0x2c] = 0.0
  - If collision appears on current path: sets param_1[0x2c] = 999999.0 (far, no threat)
  - Otherwise: computes intersection of two line segments (own position+trajectory vs opponent position+trajectory)
  - Distance = SQRT of delta between own start and intersection point
  - Sets param_1[0x2c] = min(distance_to_intersection, distance_from_opponent_to_intersection)
- For opponent B (if ptr non-null at param_1[0x45]):
  - Similar computation using a different reference frame (opponent+0x94/0x9c/0xa4/0xac)
  - Sets param_1[0x2d] = closest-approach distance
  - Special case: if steering aligned (fVar8 in range): sets param_1[0x2d] = 3.4e+38 (FLT_MAX, no threat)

**Struct offsets (param_1 — vehicle dynamics struct):**
| Offset (hex) | Offset (decimal) | Field | Notes |
|--------------|------------------|-------|-------|
| +0x10c | +0x43 | StateFlag | Non-zero indicates active (float) |
| +0x110 | +0x44 | OpponentAPtr | Pointer to first opponent vehicle |
| +0x114 | +0x45 | OpponentBPtr | Pointer to second opponent vehicle |
| +0xac | +0x2b | TrajectoryParam | Steering/trajectory parameter (float) |
| +0x94 | +0x25 | PosX | Own position X (float) |
| +0x9c | +0x27 | PosY | Own position Y (float) |
| +0xa4 | +0x29 | PosZ | Own position Z (float) |
| +0xb0 | +0x2c | ClosestDistA | Output: closest approach to opponent A (float) |
| +0xb4 | +0x2d | ClosestDistB | Output: closest approach to opponent B (float) |

**Globals:**
- `_DAT_005ad280` — steering alignment lower threshold
- `_DAT_005ad278` — steering alignment upper threshold

**Calls:** none

**Used by system:** docs/18-physics-dynamics.md

**Moddability:** `hardcoded` — vehicle dynamics struct internals

<!-- target: docs/01-engine-architecture.md -->

## FUN_0044dbe0 — Collision Parameter Block Init

Source: unknown | Confidence: high
Initializes a collision-related parameter block at DAT_007cce70. Sets first field to 0x30, zeros remaining 4 int fields.

**Key logic:**
- Writes 0x30 to DAT_007cce70 (mode/type selector)
- Zeros DAT_007cce74, DAT_007cce78, DAT_007cce7c, DAT_007cce80, DAT_007cce84 (5 ints, stride 4)

**Globals:**
- DAT_007cce70 — collision parameter block base (0x30 written)
- DAT_007cce74–DAT_007cce84 — parameter fields (zeroed)

**Calls:** none (leaf)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_0051427f — OBBFittingAndProjection

Source: renderer_obb.cpp | Confidence: high
Oriented bounding box (OBB) fitting algorithm — computes min/max bounds from 16 points, iteratively fits the tightest OBB via axis-aligned projection and inner-outer iteration, and outputs final bounding box corners.

**Key logic:**
- Selects corner table based on `param_4` sentinel value: if == 4.2039e-45 (~0.0f denorm) uses `DAT_005af60c`/`DAT_005af600` (TexCoordNormalizeData/D3DVertexConstArray), else uses `DAT_005af5f0`/`DAT_005af5e0` (RendererMatrixConst/TextureRowStartData)
- Initializes min bounds (`local_14`, `local_10`, `local_c`) and max bounds (`local_34[4]`, `local_34[5]`, `local_1c`) from `DAT_005d79bc`/`DAT_005d79c0`/`DAT_005d79c4`/`DAT_005d79c8` (viewport constants) and first 16 input points (stride 4 floats = 16 bytes per point)
- **Outer loop:** Iterates fitting up to 8 iterations
- Computes centroid from min/max, normalizes axis vectors
- Projects each point onto axis-aligned planes, accumulates squared distances in 4 directional bins (orthant test)
- Picks dominant axis (bin with maximum accumulated distance)
- If axis length^2 < `DAT_005ad1b8` (SuspensionMomentArm) threshold: early exit with current bounds
- **Inner loop:** For each input point, computes projection along dominant axis, maps to nearest corner using `local_60` step index, accumulates covariance-like sums for axis refinement
- Updates axis endpoints via weighted sums, clamped by zero-threshold (`DAT_0059e440`)
- Convergence test: if all correction deltas squared < `DAT_005af5dc` (convergence threshold), or iteration > 7: break
- Outputs final bounds in `param_1` (min corner) and `param_2` (max corner) as 3-component floats

**Globals:**
- `DAT_005af60c` (TexCoordNormalizeData) — UV normalization coefficients
- `DAT_005af600` (D3DVertexConstArray) — DirectX vertex constants
- `DAT_005af5f0` (RendererMatrixConst) — 4x4 matrix constants
- `DAT_005af5e0` (TextureRowStartData) — texture row start table
- `DAT_005d79bc` — viewport min bound constant
- `DAT_005d79c0` (Audio3DPositionFloat) — viewport/audio position constant
- `DAT_005d79c4` (RenderSurfaceScale) — render surface scale
- `DAT_005d79c8` — viewport constant
- `PTR_DAT_005ade40` — squared-distance lower bound threshold
- `DAT_005ad1b8` (SuspensionMomentArm) — OBB early-exit threshold
- `DAT_005adb14` (360.0f) — degree wrap constant for negative index wrap
- `DAT_0059e450` (NormalizationHalf) — 0.5f for rounding
- `DAT_0059e4e0` (ForceIncrementClamp) — scale factor for corner vectors
- `DAT_0059e670` — gravity-like constant (used as under-relaxation factor)
- `DAT_0059e440` (ZeroThreshold) — zero clamp for corrections
- `DAT_005af5dc` (Render_MatrixCoeff_Five) — convergence squared threshold

**Calls:**
- FUN_00513e5d — internal helper within OBB fit loop (docs/20)

**Used by system:** docs/20-math-utilities.md (triage), docs/19-renderer.md (actual)

**Moddability:** hardcoded — all constants from fixed global tables

<!-- target: docs/17-physics-collision.md -->

## FUN_0054f2f0 — CollisionContactDetection

Source: collision_detect.cpp | Confidence: high
Triangle mesh collision contact detection — iterates over collision triangles, performs ray-sphere intersection tests against input points, and records contact responses.

**Key logic:**
- Reads vehicle body pointer at `param_3 + 300` and vertex data pointer at `param_1 + 0x204`
- Reads 3 float coordinates from vertex data at offsets `+0xE8`, `+0xEC`, `+0xF0` (query point)
- Iterates `param_3[0x120]` collision triangles (stride 0x12 ushorts per triangle)
- For each triangle: checks if query point is within sphere defined by triangle center + radius:
  - Squared distance from query to triangle center vs (triangle radius + element radius)^2
- On sphere overlap: resolves triangle indices via triangle buffer (`puVar7[0..2]` x 0x30 + base), iterates triangle sub-elements
- For each sub-element (stride 0x1D): if type != 6 (non-skip type), calls D3D device transform via `DAT_008b8f24` vtable+0x20 for ray-triangle intersection
- If intersection depth between triangle entry/exit thresholds: interpolates hit position along triangle edges via parametric factor
- Calls `FUN_0054eb40` (contact response callback, 2D/3D triangle point test)
- On valid contact: flags element as hit (1), stores response parameters (contact position, normal, depth, material ID, collision flags)
- Computes contact distance via `SQRT` of displaced position
- Calls `FUN_00559a30` (contact response post-process)
- Returns count of detected contacts

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x204 | VertexDataPtr | Pointer to vertex/position buffer |
| +0x1E0 | ElementArrayPtr | Pointer to collision element array |

**Struct offsets (param_3):**
| Offset | Field | Notes |
|--------|-------|-------|
| +300 (0x12C) | CollisionNodeBase | Base address for collision node data |
| +0x120 | TriangleCount | Number of collision triangles to check |
| +0x124 | TriangleBuffer | Pointer to triangle data (stride 0x12 ushorts) |

**Globals:**
- `DAT_008b8f24` (D3DDeviceWrapperPtr) — D3D device vtable for ray-triangle intersection

**Calls:**
- FUN_0054eb40 — 2D/3D triangle point test, contact response callback (docs/17)
- FUN_00559a30 — contact response post-process (docs/17)
- (via DAT_008b8f24 vtable+0x20) — D3D coordinate transform

**Used by system:** docs/20-math-utilities.md (triage), docs/17-physics-collision.md (actual)

**Moddability:** hardcoded — all thresholds from collision element data

<!-- target: docs/20-math-utilities.md -->

