# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Proposes six classes over the ten validated functions. SceneGraphNode (0x0054B770, 0x005569F0) owns world-matrix composition from local/parent/scale state and the per-frame node update with transform upload, collision detection, and bone copies via the dword_8B8F24 vtable. MeshVertexBatchProcessor (0x0054CA00) and MeshVertexLightingTransform (0x0055E320) process mesh vertex elements (material-based transforms, stride selection by flag bit 23) and per-vertex transform/lighting/color-pack respectively, both consuming dword_8B8F24 / dword_8B8F28. RigidBody (0x005692A0, 0x00569410, 0x00569990) groups the R*I*R^T inertia-tensor transform, the R*inv(I)*R^T*T torque-to-angular-acceleration solve, and the world-to-local constraint-point append, sharing the rotation-matrix layout at this+0x1C..0x5C and position at this+0x4/+0xC/+0x14. PhysicsConstraintBatch (0x0056F100) re-roots an active subset of rigid bodies (array stride 580) into a target body's local frame through three constraint batch arrays. AllocatorNodeManager (0x0058EF83, 0x0058F6FE) groups two free functions sharing the allocate (sub_58AB58) / init / finalize (sub_58F362 / MultiFieldFree_f8eb) / free (sub_58AA6F) idiom, keyed by the dword_8D3F44 / dword_8D3F3C mode globals; their common ownership is pattern-based only.

## Function roles

- `0x0054B770` **SceneGraphNode** — SceneNodeTransformUpdate: recompute the node world transform from the local matrix at this+0xD4, the parent world matrix (parent+0x114), and per-axis scale factors at this+0x194/0x198/0x19C; compose via the dword_8B8F24 vtable slot +8 and write this+0x114 (unscaled) or this+0x1A0 (scaled path, bit 14 of this+0x3C).
- `0x0054CA00` **MeshVertexBatchProcessor** — VertexElementBatchProcess: iterate the vertex element array (this[71], 64-byte stride) applying material-based vertex/UV transforms through jump tables jpt_54CBC0 / jpt_54CE21, dedup materials via sub_54FC70, wait on audio state (sub_540940), copy index data, and set done flags (this+0x14 |= 0x9000020). Invoked per node by PriorityQueueRecursiveProcess.
- `0x005569F0` **SceneGraphNode** — SceneNodeStateUpdateWithTransform: run the animation-channel timer update (0x00551760) and dispatch setup (sub_54B570), compute the mesh bounding box (0x0054D9F0) when a2+428 is zero, upload the world transform through the dword_8B8F24 vtable slot +4 when flag 0x20000000 is clear, run collision contact detection (0x0054D7A0), copy 8 bone transforms when flags 0x4 set / 0x8 clear, then material/shader processing (sub_55ED10, sub_55D5C0) and finalize (sub_556D60) under the 0x5 flags.
- `0x0055E320` **MeshVertexLightingTransform** — VertexTransformAndLight: per-vertex 3D transform, lighting, and color-pack. Selects a 12- or 16-byte stride from the node flag word (unk_800000), transforms through the dword_8B8F24 vtable (+0/+20/+24), optionally relocates dynamic vertices, weights by per-vertex distance, packs lit colors via MMX packuswb (qword_8B6C20) into this+0x20 output at +24/+28 and specular channels at +40/+44, scaling specular via TableLookupScale (0x0053AC40).
- `0x005692A0` **RigidBody** — InertiaTensorWorld: transform the diagonal body-space inertia (0xD4/0xDC/0xE4) by the 3x3 rotation matrix (0x1C..0x5C) as R*I*R^T, writing the symmetric world-space inertia matrix at 0xEC..0x12C (upper triangle computed, lower triangle mirrored by paired DWORD copies).
- `0x00569410` **RigidBody** — InertiaTensorAngularAcceleration: compute world-space angular acceleration from a torque vector (0x7C/0x84/0x8C) as R * diag(1/I) * R^T * T, reading the rotation matrix (0x1C..0x5C) and inverse-inertia diagonals (0xBC/0xC4/0xCC), writing the result at 0x94/0x9C/0xA4.
- `0x00569990` **RigidBody** — ConstraintPointAppend: transform a world-space position a2 into the object-local frame using position (0x4/0xC/0x14) and rotation (0x1C..0x5C), then append an 88-byte entry (transformed vector plus four metadata words) to the ring buffer at this+0x240, post-incrementing the write index at this+0x23C. Vehicle physics constraint point batching.
- `0x0056F100` **PhysicsConstraintBatch** — BodiesToLocalFrame: transform a set of rigid bodies (array at this+0x4, stride 580) into the local reference frame of a target body. When a5 is nonzero, transitively mark active bodies through the three batch arrays (strides 48/48/72, flag bytes at +44/+68) until a fixed point; then translate positions and rewrite orientation matrices and Euler angles via EulerAnglesTo33RotationMatrix (0x0056BD40), F_33MatrixMultiply (0x0056C740), FloatConvertWrapper (0x00588570) and F_3x3RotationTensorMatrixTransform (0x005691D0).
- `0x0058EF83` **AllocatorNodeManager** — AllocatorNodeInit: install or replace the tracked allocator/IO node (172-byte block) keyed by global dword_8D3F44. Nonzero mode: allocate via sub_58AB58(1, 172), initialize via sub_58F014, install at off_5E99D0, finalize (sub_58F362) and free (sub_58AA6F) the previous dword_8D3F58 node. Zero mode: point off_5E99D0 at the default callback off_5E99D8, finalize/free the old node, clear dword_8D3F58. Returns 0 on success, 1 on allocation/init failure.
- `0x0058F6FE` **AllocatorNodeManager** — AllocatorNodeInitHead: install or replace the 3-dword allocator node head off_5E9AC0 keyed by global dword_8D3F3C. Nonzero mode: allocate a 48-byte block via sub_58AB58, initialize via sub_58F7C9, copy the current head's three dwords, install the new head, free the old dword_8D3F68 head (MultiFieldFree_f8eb + sub_58AA6F). Zero mode: copy the three head dwords into the static sentinel off_5E9A90/0x94/0x98, repoint off_5E9AC0, free the old head, clear dword_8D3F68. Returns 0 on success, 1 on allocation/init failure.

## Proposed classes

### SceneGraphNode

Scene-graph node carrying local/world transform matrices and node state flags. 0x0054B770 composes the world matrix from local, parent, and scale state through the dword_8B8F24 vtable; 0x005569F0 drives the per-frame state update (animation dispatch, world-transform upload, collision contact detection, bone-transform copies, material/shader finalize). Both functions share the world-matrix slot at this+0x114, the node state word at this+0x3C, and the dword_8B8F24 transform vtable, which supports common ownership.

Methods: `0x0054B770`, `0x005569F0`

- `this+0x0000003C` `uint32 node_flags` (read, DERIVED)
- `this+0x00000040` `SceneGraphNode* parent_node` (read, DERIVED)
- `this+0x00000094` `float[16] alternate_transform` (read, GUESS)
- `this+0x000000D4` `float[16] local_matrix` (read, DERIVED)
- `this+0x00000114` `float[16] world_matrix` (read_write, DERIVED)
- `this+0x00000194` `float scale_x` (read, DERIVED)
- `this+0x00000198` `float scale_y` (read, DERIVED)
- `this+0x0000019C` `float scale_z` (read, DERIVED)
- `this+0x00000204` `float* world_transform_source` (read, GUESS)

### MeshVertexBatchProcessor

Scene-graph mesh object that batches vertex-element processing: iterates the element array (count this+0x118, entries at this+0x11C with 64-byte stride), applies material-based vertex/UV transforms via jump tables jpt_54CBC0 / jpt_54CE21, dedups materials through sub_54FC70, waits on audio resource state (sub_540940), and sets done flags in this+0x14. Re-entry guarded by bit 27 of this+0x14.

Methods: `0x0054CA00`

- `this+0x00000014` `uint32 state_flags` (read_write, DERIVED)
- `this+0x00000118` `int32 element_count` (read, DERIVED)
- `this+0x0000011C` `void* element_array` (read, DERIVED)
- `this+0x00000138` `void* sub_object` (read, GUESS)

### MeshVertexLightingTransform

Per-vertex 3D mesh transform, lighting and color-pack stage. Reads the scene node from this+0x18 and the source vertex buffer from this+0x0C, selects a 12- or 16-byte stride from the node flag word (unk_800000), transforms vertices through the dword_8B8F24 vtable, optionally relocates dynamic vertices, computes per-vertex distance-weighted lighting, and writes packed colors and specular channels to the this+0x20 output. Consumes source-mesh data through this+0x128.

Methods: `0x0055E320`

- `this+0x00000000` `uint32 render_flags` (read, DERIVED)
- `this+0x00000004` `void* vertex_object` (read, GUESS)
- `this+0x00000008` `int32 vertex_count` (read, DERIVED)
- `this+0x0000000C` `void* source_vertex_buffer` (read, DERIVED)
- `this+0x00000018` `void* scene_node` (read, DERIVED)
- `this+0x00000020` `void* output_vertices` (write, DERIVED)
- `this+0x00000128` `void* source_mesh` (read, DERIVED)
- `*(this+0x128)+0x00000000` `float transformed_data_word_0` (read, GUESS)
- `*(this+0x128)+0x00000010` `float transformed_data_word_1` (read, GUESS)
- `*(this+0x128)+0x00000014` `float transformed_data_word_2` (read, GUESS)
- `*(this+0x128)+0x00000018` `float transformed_data_word_3` (read, GUESS)
- `*(this+0x128)+0x0000001C` `float transformed_data_word_4` (read, GUESS)
- `*(*(this+0x128)+0x0)+0x00000000` `void* vertex_data` (read, DERIVED)
- `*(*(this+0x128)+0x0)+0x00000038` `float vertex_position_x` (read, DERIVED)
- `*(*(this+0x128)+0x0)+0x0000003C` `float vertex_position_y` (read, DERIVED)
- `*(*(this+0x128)+0x0)+0x00000040` `float vertex_position_z` (read, DERIVED)
- `*(*(this+0x128)+0x0)+0x00000050` `float vertex_radius_flags` (read, GUESS)

### RigidBody

Rigid physics body carrying a 3x3 rotation matrix (doubles at this+0x1C..0x5C), a world position (this+0x4/+0xC/+0x14), inertia-tensor state (diagonal body inertia, inverse-inertia reciprocals, world-space inertia matrix) and a constraint-point ring buffer. 0x005692A0 computes R*I*R^T, 0x00569410 computes angular acceleration from torque via R*inv(I)*R^T, and 0x00569990 transforms world positions into the body frame and appends 88-byte constraint entries. The shared rotation/position layout across all three functions supports common ownership.

Methods: `0x005692A0`, `0x00569410`, `0x00569990`

- `this+0x00000004` `double position_x` (read, DERIVED)
- `this+0x0000000C` `double position_y` (read, DERIVED)
- `this+0x00000014` `double position_z` (read, DERIVED)
- `this+0x0000001C` `double rotation_00` (read, DERIVED)
- `this+0x00000024` `double rotation_10` (read, DERIVED)
- `this+0x0000002C` `double rotation_20` (read, DERIVED)
- `this+0x00000034` `double rotation_01` (read, DERIVED)
- `this+0x0000003C` `double rotation_11` (read, DERIVED)
- `this+0x00000044` `double rotation_21` (read, DERIVED)
- `this+0x0000004C` `double rotation_02` (read, DERIVED)
- `this+0x00000054` `double rotation_12` (read, DERIVED)
- `this+0x0000005C` `double rotation_22` (read, DERIVED)
- `this+0x0000007C` `double torque_x` (read, DERIVED)
- `this+0x00000084` `double torque_y` (read, DERIVED)
- `this+0x0000008C` `double torque_z` (read, DERIVED)
- `this+0x00000094` `double angular_accel_x` (write, DERIVED)
- `this+0x0000009C` `double angular_accel_y` (write, DERIVED)
- `this+0x000000A4` `double angular_accel_z` (write, DERIVED)
- `this+0x000000BC` `double inv_inertia_xx` (read, GUESS)
- `this+0x000000C4` `double inv_inertia_yy` (read, GUESS)
- `this+0x000000CC` `double inv_inertia_zz` (read, GUESS)
- `this+0x000000D4` `double inertia_xx` (read, DERIVED)
- `this+0x000000DC` `double inertia_yy` (read, DERIVED)
- `this+0x000000E4` `double inertia_zz` (read, DERIVED)
- `this+0x000000EC` `double world_inertia_00` (write, DERIVED)
- `this+0x000000F4` `double world_inertia_01` (write, DERIVED)
- `this+0x000000F8` `double world_inertia_01_high` (read, GUESS)
- `this+0x000000FC` `double world_inertia_02` (write, DERIVED)
- `this+0x00000100` `double world_inertia_02_high` (read, GUESS)
- `this+0x00000104` `double world_inertia_10` (write, DERIVED)
- `this+0x00000108` `double world_inertia_10_high` (write, GUESS)
- `this+0x0000010C` `double world_inertia_11` (write, DERIVED)
- `this+0x00000114` `double world_inertia_12` (write, DERIVED)
- `this+0x00000118` `double world_inertia_12_high` (read, GUESS)
- `this+0x0000011C` `double world_inertia_20` (write, DERIVED)
- `this+0x00000120` `double world_inertia_20_high` (read, GUESS)
- `this+0x00000124` `double world_inertia_21` (write, DERIVED)
- `this+0x00000128` `double world_inertia_21_high` (read, GUESS)
- `this+0x0000012C` `double world_inertia_22` (write, DERIVED)
- `this+0x0000023C` `int32 constraint_write_index` (read_write, DERIVED)
- `this+0x00000240` `void* constraint_ring_buffer` (read, DERIVED)

### PhysicsConstraintBatch

Constraint batch manager holding a rigid-body array (this+0x4, stride 580) and three constraint batch arrays (strides 48/48/72). 0x0056F100 transforms the active subset of bodies (target body plus transitively linked contact partners) into the target body's local reference frame, rewriting positions, orientation matrices and Euler angles.

Methods: `0x0056F100`

- `this+0x00000000` `int32 body_count` (read, DERIVED)
- `this+0x00000004` `RigidBody* body_array` (read, DERIVED)
- `this+0x00000008` `int32 batch1_count` (read, DERIVED)
- `this+0x0000000C` `void* batch1_array` (read, DERIVED)
- `this+0x00000010` `int32 batch2_count` (read, DERIVED)
- `this+0x00000014` `void* batch2_array` (read, DERIVED)
- `this+0x00000018` `int32 batch3_count` (read, DERIVED)
- `this+0x0000001C` `void* batch3_array` (read, DERIVED)

### AllocatorNodeManager

Free-function group managing allocator/IO node registration keyed by the dword_8D3F44 / dword_8D3F3C mode switches. 0x0058EF83 installs or replaces a 172-byte tracked node at off_5E99D0 / dword_8D3F58; 0x0058F6FE installs or replaces a 3-dword node head at off_5E9AC0 / dword_8D3F68. Both follow allocate (sub_58AB58), initialize (sub_58F014 / sub_58F7C9), finalize (sub_58F362 / MultiFieldFree_f8eb) and free (sub_58AA6F); their shared idiom is pattern-based and common class ownership is not proven.

Methods: `0x0058EF83`, `0x0058F6FE`


## Compatibility contracts

- **SceneNodeWorldTransformContract** — A scene node with a parent pointer at +0x40, flag word at +0x3C, and local matrix at +0xD4 must, after the transform update, leave the world matrix at +0x114 consistent with parent-world composition (or a direct local copy for root nodes when flag bit 0 is set). The scaled variant writes +0x1A0 from per-axis factors at +0x194/+0x198/+0x19C. A replacement must preserve the matrix slots and flag-gated copy semantics.
- **RigidBodyInertiaTensorContract** — A rigid body with a 3x3 rotation matrix at +0x1C..+0x5C and diagonal body-space inertia at +0xD4/+0xDC/+0xE4 must produce a symmetric world-space inertia matrix at +0xEC..+0x12C via R*I*R^T (upper triangle mirrored to the lower triangle).
- **RigidBodyTorqueAngularAccelerationContract** — Given a torque vector at +0x7C/+0x84/+0x8C, a 3x3 rotation matrix at +0x1C..+0x5C and inverse-inertia diagonals at +0xBC/+0xC4/+0xCC, the solver must write the world-space angular acceleration vector at +0x94/+0x9C/+0xA4 as R*diag(1/I)*R^T*T.
- **ConstraintPointAppendContract** — WriteRelativeTransformedPosition must append 88-byte entries to the ring buffer at +0x240 and post-increment the write index at +0x23C. Each entry is the world-to-local transformed vector (3 doubles) plus four metadata words; the 88-byte stride and post-increment semantics must be preserved for consumers of the constraint batch.
- **RigidBodyFrameTransformContract** — The batch manager's body array (this+0x4, stride 580, position at +4, rotation at +28) and its active-subset propagation semantics must be preserved so target body, contact partners, and all transitively linked bodies are transformed into one consistent local reference frame with rewritten orientation matrices and Euler angles.
- **AllocatorNodeRegistrationContract** — The game may reconfigure the tracked allocator/IO node through the dword_8D3F44 / dword_8D3F3C switches. A replacement must install the IO function pointer at off_5E99D0 (or the 3-dword node head at off_5E9AC0, including the static sentinel off_5E9A90/0x94/0x98 repointing), keep dword_8D3F58 / dword_8D3F68 consistent, finalize before freeing the old node, and return 0 on success / 1 on allocation or init failure.
- **VertexMaterialTransformContract** — The vertex-element batch (count this+0x118, array this+0x11C, 64-byte stride) must process material-based vertex/UV transforms into packed color output, selecting between the 16-DWORD and 12-DWORD vertex stride paths by flag bit 23 (0x800000) of this+0x14 and writing the stride constant into each element header at offset 56, and set the done flags 0x9000020 in this+0x14.

## Unresolved

- The concrete D3D wrapper behind the dword_8B8F24 vtable and the semantics of its slots +0/+4/+8/+20/+24 (matrix multiply vs concat vs lighting) are not established by this packet; consumers are identified only indirectly.
- The identity of the scene node object carrying +516 (0x204), +416 and +276 state in 0x005569F0 is unknown; this+0x204 (world_transform_source) semantics are GUESS.
- 0x0055E320 fields this+0x2C/+0x54/+0x68/+0x6C/+0x70/+0xA0/+0xB8/+0x124/+0x150 and the static-pipeline guard:0 are listed in packet field evidence but not visible as explicit operands in the raw text; purposes unresolved.
- Globals dbl_59E430, flt_59E43C, flt_59E450, flt_59FEC8 are referenced by extracted facts but not named in the raw source text of 0x0055E320; roles unresolved.
- The second 64-bit half of the MMX operand qword_8B6C20 used by packuswb is unknown; the destination meaning of the output +40/+44 specular channels (surface brightness vs shininess) is not confirmed.
- 0x0054CA00 this+0x174 appears in packet fields but its read site is unresolved; the 37-float material entry layout and the exact meaning of the four switch cases are inferred from loop structure, not proven; the 16-DWORD/12-DWORD path labels (D3D-transformed vs untransformed) are DERIVED from the legacy ABI name only.
- 0x005692A0: exact matrix element ordering (column-major vs row-major) cannot be decided from this packet alone; the lower triangle is written by DWORD copies of doubles (compiler artifact of symmetric layout); the return value (low DWORD of element (1,2)) has no evident purpose.
- 0x00569410: the interleaved register order of v1/v2/v3 makes the per-component mapping a DERIVED reconstruction; the 0xBC/0xC4/0xCC factors are treated as inverse-inertia diagonals but the raw multiplication alone does not prove they are reciprocals.
- 0x00569990: semantic roles of the four metadata words (a3, a4, a5, a6) in the 88-byte entry are not established; owner identity shares its caller with a 56-byte-stride sibling append function not in this packet.
- 0x0056F100: the three batch array object types (strides 48/48/72, flag bytes at +44/+68) are evidenced only from inside this function; the semantics of a5 and of the two-body partners are inferred from flag churn; local stack matrices and the v56 flag buffer are decompiler-inferred shapes.
- 0x0058EF83 / 0x0058F6FE: node identities, the 172-byte and 48-byte layouts, sub_58F014/sub_58F7C9 return-value semantics, and the finalize-before-free requirement are not evidenced by the packet; the two functions share an allocate/init/finalize/free idiom but common class ownership is pattern-based (GUESS) only.
- Whether the scene-node, mesh, and allocator functions all belong to the vehicle-physics subsystem is manifest-scope derived, not evidence-proven from the packet alone.
