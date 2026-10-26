# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

A mixed set of runtime objects recovered from 25 functions: a growable key/value string table with capacity growth and teardown (0x00423530) plus a quoted-token parser that feeds its builder (0x004236F0); an AI command-response handler that dispatches dequeued command IDs to state/parameter setters (0x00429EE0) with a per-state flag-table getter (0x0042AE90) and a global state-flag inversion helper (0x00435240); a session timer scalar writing a global (0x0042BDA0); a 2D lookup-table ratio calculator (0x0042DD00); three vehicle setup-value formatters sharing a format flag and unit-string/suffix layout (0x0042F180, 0x0042F1E0, 0x0042F260); a brake temperature fade force model (0x00430A50) and a single-step torque-force product step (0x00438100); settings path building and directory enumeration (0x00432180, 0x004326D0, 0x00432870) plus a double-pointer teardown helper (0x00434420); a camera object initializer (0x004348B0); an object constructor with Direct3D state init (0x00448120), a noise-table scalar (0x00448300) and a record midpoint helper (0x00448480); spatial tree node counting and linearization (0x004486A0, 0x004486E0); and collision broad-phase, stream-fed triangle building and BSP material selection (0x004497E0, 0x00449F60, 0x0044A4B0). Class ownership is GUESS for most clusters; only the string table, ratio calculator and camera object carry DERIVED owner hints from the packet, and several objects are left as UnknownObject.

## Function roles

- `0x00423530` **GrowableStringTable** — Insertion into a growable key/value string table with capacity growth by 128 slots and old-buffer teardown.
- `0x004236F0` **UnknownObject** — Quoted-token parsing of an input string into two output buffers, feeding the string-table builder called alongside InsertKeyValuePairWithAutoGrow.
- `0x00429EE0` **AIDriverCommandState** — Dispatch of dequeued AI command IDs (0, 4, 5, 14) to side-effect setters, gated by race-phase and session-type globals.
- `0x0042AE90` **AIDriverStateFlags** — Read-only per-state flag/selector table lookup driven by the selector field at this+0x4588.
- `0x0042BDA0` **SessionTimerScaler** — Scales a double timer input by 400.0 and stores the truncated integer into the session-timer global.
- `0x0042DD00` **RatioCalculator** — Weighted 2D lookup-table ratio computation with row/column bounds guards and 0.0 sentinels.
- `0x0042F180` **SetupValueFormatter** — Formats a scaled setup value as "%d %s" with optional degree-conversion factor.
- `0x0042F1E0` **SetupValueFormatter** — Formats one setup value with a float ("%.1f %s") or integer ("%d %s") branch selected by the format flag.
- `0x0042F260` **SetupValueFormatter** — Formats a setup value with an optional indexed offset term and a metric/inches ("%.1f %s" / "%.3f %s") branch.
- `0x00430A50` **VehicleBrakeFadeState** — Brake temperature fade force model with compound-specific constants, axle temperature blends and per-wheel fade sampling.
- `0x00432180` **SettingsFileScanner** — Builds and persists a settings-file directory path then enumerates files under the search path.
- `0x004326D0` **DirectoryEnumeratorWrapper** — Thin wrapper forwarding the enumerator pointer at this+0 to DirectoryFileEnumerator.
- `0x00432870` **PathStringCombinator** — Combines three path strings from a string-pointer array, defaulting null entries to the default application directory.
- `0x00434420` **DoublePointerOwner** — Destructor-style teardown of a double-pointer object gated by the flag byte at this+8.
- `0x004348B0` **CameraObject** — Allocates and configures a 208-byte camera/transform object and runs post-init camera setup.
- `0x00435240` **UnknownObject** — Boolean helper returning the logical negation of StateFlagCheck evaluated on the global flag value.
- `0x00438100` **VehicleDynamicsState** — Single-step torque-force product accumulation into vehicle dynamics fields.
- `0x00448120` **D3DStateContainer** — Object constructor zeroing this+4 and initializing Direct3D rendering state.
- `0x00448300` **RandomNoiseSource** — Produces a scaled value from a lookup table indexed by a monotonically incrementing global counter.
- `0x00448480` **RecordMidpointHelper** — Unconditional element-wise midpoint (0.5 scale) of two three-field records into the output record.
- `0x004486A0` **SpatialTreeNode** — Recursive node count of a spatial tree over a four-child array at +0x4C and an extra child at +0x5C.
- `0x004486E0` **SpatialTreeNode** — Recursive linearization of a spatial tree into a contiguous output array, recording each node's output index at +0x48.
- `0x004497E0` **CollisionBatchBroadphase** — Sweep-and-prune broad-phase AABB overlap detection over a triangle batch, marking overlapping pairs.
- `0x00449F60` **IndexedCollisionBodyBuilder** — Builds a triangle work set from a 34-byte stream record and packed vertex indices into a caller vertex array.
- `0x0044A4B0` **BspMaterialSelector** — Recursive collision-material selection for a vertex region with arena output and half-region recursion.

## Proposed classes

### GrowableStringTable

Growable key/value string table: 3-dword header (capacity at +0x0, count at +0x4, entries pointer at +0x8) with growth by 128 slots; entries are 16-byte {char*, int, char*, int} records.

Methods: `0x00423530`

- `this+0x00000000` `int capacity` (read_write, GUESS)
- `this+0x00000004` `int count` (read_write, GUESS)
- `this+0x00000008` `void** (16-byte entry array) entries` (read_write, GUESS)

### AIDriverCommandState

AI driver command-response state: reset flag, driver status and AI state flag updated when dequeued AI command IDs are dispatched; behavior gated by race-phase and session-type globals.

Methods: `0x00429EE0`

- `this+0x0000443C` `int ai_state_flag` (read_write, GUESS)
- `this+0x00004510` `int driver_status` (read_write, GUESS)
- `this+0x00004544` `int reset_flag` (read_write, GUESS)

### AIDriverStateFlags

Per-state flag/selector table lookup: reads a selector at +0x4588 and indexes an embedded dword table (base dword index 1113).

Methods: `0x0042AE90`

- `this+0x00004588` `int state_selector` (read, GUESS)

### SessionTimerScaler

Scales a double timer input by 400.0 and stores the truncated integer into the session-timer global dword_7C5694.

Methods: `0x0042BDA0`


### RatioCalculator

2D lookup-table ratio computation: row/column counts and 8-byte entry arrays, divisor and scale; returns a weighted ratio or 0.0 on any guard failure.

Methods: `0x0042DD00`

- `this+0x00000000` `int row_count` (read, GUESS)
- `this+0x00000004` `void* (8-byte entries) row_entries` (read, GUESS)
- `this+0x00000008` `int column_count` (read, GUESS)
- `this+0x0000000C` `void* (8-byte entries) column_entries` (read, GUESS)
- `this+0x00000010` `double divisor` (read, GUESS)
- `this+0x00000014` `double scale` (read, GUESS)

### SetupValueFormatter

Formats vehicle setup values into caller buffers with float/integer and metric/inches variants, an optional indexed offset term, and unit-suffix strings; shared format flag at +0x4.

Methods: `0x0042F180`, `0x0042F1E0`, `0x0042F260`

- `this+0x00000004` `int format_flag` (read, GUESS)
- `this+0x00000C70` `double offset_term_base` (read, GUESS)
- `this+0x00000C78` `double offset_term_multiplier` (read, GUESS)
- `this+0x00000C84` `double offset_term_index` (read, GUESS)
- `this+0x0000199C` `double offset_term_scale` (read, GUESS)

### VehicleBrakeFadeState

Brake temperature fade force model inputs: compound index at +0xBC4, front/rear axle brake temperature/scale/wear triples and per-wheel fade fields.

Methods: `0x00430A50`

- `this+0x00000BC4` `int compound_index` (read, GUESS)
- `this+0x00000C30` `double front_brake_temp` (read, GUESS)
- `this+0x00000C38` `double front_brake_scale` (read, GUESS)
- `this+0x00000C44` `double front_brake_wear` (read, GUESS)
- `this+0x00000CB0` `double rear_brake_temp` (read, GUESS)
- `this+0x00000CB8` `double rear_brake_scale` (read, GUESS)
- `this+0x00000CC4` `double rear_brake_wear` (read, GUESS)
- `this+0x00001570` `double per_wheel_temp` (read, GUESS)
- `this+0x00001578` `double per_wheel_scale` (read, GUESS)
- `this+0x00001584` `double per_wheel_wear` (read, GUESS)

### SettingsFileScanner

Builds a settings-file directory path (sanitized base plus subdirectory and trailing backslash), persists it into global buffers, and enumerates files under a search path.

Methods: `0x00432180`

- `this+0x00000000` `char* search_path` (read, GUESS)

### DirectoryEnumeratorWrapper

Thin wrapper forwarding an enumerator pointer held at this+0 to DirectoryFileEnumerator with a literal 0 argument.

Methods: `0x004326D0`

- `this+0x00000000` `void* enumerator` (read, GUESS)

### PathStringCombinator

Combines three path strings from a string-pointer array (elements 0, 2, 4), substituting the default application directory string for null entries.

Methods: `0x00432870`

- `obj+0x00000000` `char* path_element_0` (read, GUESS)
- `obj+0x00000008` `char* path_element_2` (read, GUESS)
- `obj+0x00000010` `char* path_element_4` (read, GUESS)

### DoublePointerOwner

Small object owning a double pointer; flag-gated teardown frees the inner allocation first, then the outer pointer.

Methods: `0x00434420`

- `this+0x00000000` `void** owned_pointer` (read, GUESS)
- `this+0x00000008` `byte teardown_flag` (read, GUESS)
- `obj+0x00000000` `void* inner_allocation` (read, GUESS)

### CameraObject

Camera/transform object: allocation of a 208-byte object stored at +0xC, float camera parameter configuration, name assignment ('gridwalkcam'), vtable-driven post-init and track-spline setup.

Methods: `0x004348B0`

- `this+0x0000000C` `void* camera_object` (read_write, GUESS)
- `this+0x00000010` `float camera_param_10` (read, GUESS)
- `this+0x00000030` `float camera_param_30` (read, GUESS)
- `*(this+0xC)+0x00000000` `void** vtable` (read, GUESS)
- `*(this+0xC)+0x00000004` `unknown field_4` (unknown, GUESS)
- `*(this+0xC)+0x00000010` `unknown field_10` (read_write, GUESS)
- `*(this+0xC)+0x00000014` `unknown field_14` (read_write, GUESS)
- `*(this+0xC)+0x00000038` `float camera_param_38` (read_write, GUESS)
- `*(this+0xC)+0x0000003C` `float camera_param_3C` (write, GUESS)
- `*(this+0xC)+0x00000048` `float camera_param_48` (write, GUESS)
- `*(this+0xC)+0x000000A4` `float camera_param_A4` (write, GUESS)
- `*(this+0xC)+0x000000A8` `float camera_param_A8` (read_write, GUESS)
- `*(*(this+0xC)+0x0)+0x0000001C` `function ptr vtable_method_1C` (read, GUESS)

### VehicleDynamicsState

Vehicle dynamics force-accumulation fields; the torque-force product step reads inputs at +0x364/+0x36C and writes the intermediate +0x374 and accumulated +0x22C outputs.

Methods: `0x00438100`

- `this+0x0000022C` `double accumulated_torque` (write, GUESS)
- `this+0x00000364` `double force_input` (read, GUESS)
- `this+0x0000036C` `double multiplier_input` (read, GUESS)
- `this+0x00000374` `double torque_product` (write, GUESS)
- `this+0x00000384` `double bias_term` (read, GUESS)
- `this+0x0000038C` `double scale_factor` (read, GUESS)

### D3DStateContainer

Object whose constructor zeroes field +4 and initializes Direct3D rendering state via D3DStateInit.

Methods: `0x00448120`

- `this+0x00000004` `dword init_state` (write, GUESS)

### RandomNoiseSource

Produces a scaled value by indexing a noise lookup table with a monotonically incrementing global counter; scale factor at +0x8, output slot at +0x14.

Methods: `0x00448300`

- `this+0x00000008` `float scale` (read, GUESS)
- `this+0x00000014` `float output` (write, GUESS)

### RecordMidpointHelper

Element-wise midpoint of two records (float at +0x0, double at +0x4, float at +0xC), each scaled by 0.5; returns the first source pointer.

Methods: `0x00448480`

- `this+0x00000000` `float x_float` (read_write, GUESS)
- `this+0x00000004` `double y_double` (read_write, GUESS)
- `this+0x0000000C` `float z_float` (read_write, GUESS)

### SpatialTreeNode

Spatial tree node with a four-child pointer array at +0x4C, an extra child at +0x5C, and a linearization output index at +0x48.

Methods: `0x004486A0`, `0x004486E0`

- `this+0x00000048` `int linearize_index` (read_write, GUESS)
- `this+0x0000004C` `void* [4] children` (read, GUESS)
- `this+0x0000005C` `void* extra_child` (read, GUESS)

### CollisionBatchBroadphase

Collision triangle batch (count at +0x0, 32-byte-strided triangle array at +0x8) with sweep-and-prune AABB overlap marking of triangle pairs.

Methods: `0x004497E0`

- `this+0x00000000` `int triangle_count` (read, GUESS)
- `this+0x00000008` `void* (32-byte stride) triangles` (read, GUESS)

### IndexedCollisionBodyBuilder

Builds a triangle work set from a 34-byte stream record and packed vertex indices, copying 16-byte vertex records from a caller vertex array.

Methods: `0x00449F60`


### BspMaterialSelector

Recursive collision-material selection for a vertex region: writes classification and dispatch-index words at +0x8/+0xA, reserves arena output at +0xC, and recurses over two child half-regions.

Methods: `0x0044A4B0`

- `this+0x00000008` `word material_classification` (read_write, GUESS)
- `this+0x0000000A` `word dispatch_index` (write, GUESS)
- `this+0x0000000C` `void* output_arena` (write, GUESS)
- `*(this+0xC)+0x00000000` `float coverage_coordinate` (write, GUESS)
- `*(this+0xC)+0x00000004` `float coverage_extent` (write, GUESS)
- `*(this+0xC)+0x00000010` `float recurse_coord_0` (write, GUESS)
- `*(this+0xC)+0x00000014` `float recurse_coord_1` (write, GUESS)

## Compatibility contracts

- **GrowableStringTableInsert** — InsertKeyValuePairWithAutoGrow returns 0 on success and -1 when the key or value is null, empty, or the two strings are equal. Growth allocates capacity+128 entries with a 4-byte header and an empty-entry convention {0, -1, 0, -1}; entries are 16-byte key/value records whose strings are duplicated through StringCopyWithBufferRealloc, and the old buffer is freed.
- **StringTokenParse** — Parses quoted tokens from an input string into two caller buffers; returns 0 on success and -1 on null/empty input or when the period separator is absent. Output buffers are zero-initialized and null-terminated.
- **AiCommandResponse** — Processing a dequeued AI command mutates driver-state fields: reset flag at +0x4544, driver status at +0x4510 and AI state flag at +0x443C. Behavior is gated by the race-phase global (3: session cleanup; 4: speed-delta reset) and the session-type global (!= 7 for command-0 handling).
- **SetupValueFormatting** — Setup values are formatted as "%d %s", "%.1f %s" or "%.3f %s" into buffer a2+30 with unit-suffix strings and optional radian-to-degree (5.710147155067049) and metric-to-inches (0.3937007874015748) conversions selected by the format flag at +0x4.
- **BrakeTemperatureFade** — ComputeBrakeTemperatureFade returns (v29 - v26 * a2^2) / v33, where v33 is a normalized brake force, v26 a front-axle temperature blend and v29 a wheel-loop fade ceiling. Requires TireBrandLookup and CompoundIndexLookup to succeed and returns 0 on any guard failure.
- **SettingsPathBuild** — Settings file discovery builds a sanitized path, appends a subdirectory component and a trailing backslash, persists the result into global buffers via StringCopyWithBufferRealloc and enumerates the directory; returns 1 unconditionally.
- **CameraObjectInit** — CameraObjectInit allocates a 208-byte transform/camera object, stores it at +0xC, sets float parameters (+0x38, +0x3C, +0x48, +0xA4, +0xA8), assigns the name 'gridwalkcam', and returns 0 on success or 1 when allocation or track-spline setup fails.
- **SweepAndPruneBroadphase** — SweepAndPruneAABBOverlapDetection allocates a 20-byte-per-entry projection buffer, sorts entries by left bound, and marks overlapping triangle pairs with a 1 byte at triangle+24 after SAT edge-separation validation.

## Unresolved

- The three setup-value formatters (0x0042F180, 0x0042F1E0, 0x0042F260) are grouped as one SetupValueFormatter class, but they read their unit-suffix strings from different this offsets (+56, +72, +24 respectively); common ownership is GUESS, not proven.
- StringHashTokenParsing's this+1/this+2 offsets are character positions within the parsed input string, not object fields; no owning class is proposed, and the token-parser relationship to InsertKeyValuePairWithAutoGrow (both called by 0x00423890) is unproven.
- InsertKeyValuePairWithAutoGrow's 16-byte entry layout {char*, int, char*, int} and the {0, -1, 0, -1} empty-entry convention are DERIVED readings, not independently confirmed; the three StringCopyWithBufferRealloc calls in the growth path discard their results.
- The meaning of the growth step 128 and the role of the 4-byte header word in the string table are source facts whose structural semantics are not confirmed.
- AI command IDs 0/4/5/14 and the magic parameter values 18/99999 depend on ParameterValueSetter's parameter table, which is outside this packet.
- Race-phase constants 3 and 4 in dword_7C56A8 and the session-type inequality 7 in dword_7C56A4 are asserted by prior analysis but not proven here.
- The dword table returned by StateFlagsLookup (base dword index 1113) has unknown length and element semantics; only the selector field at +0x4588 is captured.
- The exact side effect of sub_5895A2 and whether dword_7C5694 is a timer or angle output are not documented.
- RatioCalculator's +0 base / +4 weight meaning within each 8-byte table entry is inferred from the ratio formula, not independently evidenced.
- The 5.710147155067049 (degree) and 0.3937007874015748 (inches) conversion factors are inferred, not grounded in unit definitions.
- SetupValueFormatWithOffset's offset-term fields 0xC70/0xC78/0xC84/0x199C belong to an unidentified owning class; only their use in the indexed offset term is evidenced.
- ComputeBrakeTemperatureFade's compound-struct fields at v4+32..+452 and polynomial coefficients v36..v39 are read but have no field evidence; the meaning of return denominator v33 and clamp constant v40 is unconfirmed.
- SettingsSetupFileRead references global byte_7CE498 (labeled AutoLoadConfigFile) in packet facts, but the global does not appear in the raw source text; its role is unverifiable.
- DirectoryFileEnumeratorWrapper's literal second argument 0 and its cluster_copy pairing with ConditionalFreeWithBit0Flag (0x00404F70) are DERIVED and unverified.
- PathStringCombinator's exact semantics of sub_5665B0 and StringCopyWithBufferRealloc, and the ownership of the returned pointer, are unresolved.
- DoublePointerFree's byte at +8 is unknown (ownership flag vs reference count); the structural twin DestructorWithDoubleFreePattern (0x00418D60) is DERIVED.
- CameraObjectInit's float fields (+0x38/+0x3C/+0x48/+0xA4/+0xA8) have no established semantic meaning (FOV/scale/near/far).
- TorqueForceProductComputation's outputs at +0x22C/+0x374 are recalculated every frame per the persistence note, so external pokes do not persist.
- ObjectConstructor's zeroed field at +4 is either an initialization flag or reference counter; the object type is unidentified.
- RandomScaledValue's lookup table at 0x008AAE74 and counter at 0x008AAE70 (trig/weather noise) are DERIVED from existing analysis, not independently proven.
- WeightedAverageInterpolation's float/double split of the 0.5 constant between flt_59E450 and dbl_59E880 is DERIVED; the caller record type is unidentified.
- DynamicsNodeCountRecursive and BVHTreeLinearize assume recursion on the same node pointer; child-pointer slots 0x50/0x54/0x58 have no packet evidence; no depth bound or cycle protection is evidenced.
- SweepAndPruneAABBOverlapDetection's projection axes are inferred from the SAT test context; the owning collision triangle structure is unidentified.
- IndexedVertexLookupFromStream's interpretation of a2+52/a2+56 as vertex count/record-array base is DERIVED; FileWriteWithBackendDispatch being used to read stream bytes is unproven.
- BspLeafMaterialSelectionAndSubdivision's arena record layout, the sub_44A2D0 coverage-score semantics, and the float-encoded vertex-list-head pointer in a2 are Hex-Rays artifacts.
- The packet lists double constants 0x59E420/0x59E430/0x59E880, 0x59EA58..0x59EA80 and dword_8AD254 for ComputeBrakeTemperatureFade, but several do not appear as named operands in the raw source text; exact roles unresolved.
