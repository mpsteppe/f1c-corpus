# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty-four functions reconstructed as three worker-proposed classes plus unclassified helpers. Particle (0x004C9D60, DERIVED) initializes a particle instance's position, direction, color and attributes from noise-perturbed inputs and the shared weather noise table. ParticleEmitter (GUESS) groups the four weather/effect particle functions: ParticleSpawnAndPositionInit (0x004CC970) and SpawnParticleBurst (0x004CCE90) spawn circular-buffer slots from emission capacity at this+0x58 and detail shift at this+0x8, while ParticlePositionAdd (0x004CCDC0) and ParticleSystemUpdateWithWindAndDamping (0x004CD220) iterate the live particle array at this+0x64/this+0x68 integrating wind, damping, gravity, ground-plane reflection and AABB collision. SpecialFX (0x004CFED0, DERIVED) tears down the special-effects system, freeing count-headed 60- and 108-byte-stride arrays and cleaning the collision tree. The remaining helpers stay UnknownObject: global vtable dispatch (0x004C8D90), a timed vtable callback (0x004C8FC0), vehicle speed sort (0x004C9C00), sentinel and float-struct initializers (0x004C9D50, 0x004CA430), blend-mode token to enum (0x004CADA0), object-type dispatch (0x004CDB20), track-surface token parsing (0x004CDC70), strided string lookup (0x004CE860), driver standings comparison (0x004D0C20), steward light/glow resolution (0x004D0E20), value/single-field setters (0x004D0EC0, 0x004D0F00), timer text rendering (0x004D11D0), pit-stop-order access (0x004D1410) and pit door/tent scene-node setup (0x004D15F0).

## Function roles

- `0x004C8D90` **UnknownObject** — Global-object vtable dispatcher: when global dword_8AC4C4 is non-null, makes an indirect __stdcall call through vtable slot +60 passing selector argument 1 (a1==1) or 0, and returns its result; the null-global path falls through returning an uninitialized value.
- `0x004C8FC0` **UnknownObject** — Timed counter dispatcher: decrements float counter at this+0x18 by dbl_8AFE98; when the counter is <=0 and the ArithmeticComparison_9000 gate passes, resets the counter from this+0x14 and invokes the indirect vtable+12 callback, returning its result (otherwise 0).
- `0x004C9C00` **UnknownObject** — Vehicle speed sort: copies the live vehicle pointer array (dword_7C54F0, each pointer offset by 12), sorts via the generic routine sub_5890AA with the speed-sum comparator at 0x004C9BA0, then writes each driver's summed speed (floats at vehicle+1848 and +1856) into the output buffer this[103..]. Returns the vehicle count.
- `0x004C9D50` **UnknownObject** — Constructor-step sentinel initializer: writes -1 into the dword fields at offsets 0x0, 0x4 and 0x44 marking them invalid/empty, then returns the this pointer. Invoked from sub_4CB120 during object construction.
- `0x004C9D60` **Particle** — Particle position/direction/color/attribute initialization from noise-perturbed inputs: consumes floats from the weather noise table 0x008AB274 via shared counter 0x008AAE70, applies (noise*0.2+1.0) scaling to position parameters, stores reciprocals, packs a lifetime-derived ARGB at this+0x60, normalizes a direction into this+0x48/0x4C/0x50, and stores a random 0..15 index at this+0x54.
- `0x004CA2D0` **UnknownObject** — Child-particle update with 2D rotation and scaling: accumulates time at +0x14, derives scale from flt_8AFEE4 and base/multiplier fields, computes a rotation angle from accumulated time times the frequency field, writes child target X/Y/Z from weighted rotated offsets over the child array at +0x38 (20-byte entries, count +0x34), then clears flag bits 0xFEFFFFDF on a display node fetched via LinkedListIndexedAccessor_c230.
- `0x004CA430` **UnknownObject** — Float-struct initializer: writes unit scalars 1.0f to +0xC/+0x10/+0x14, zeroes +0x18..+0x2C, writes tuning constants 10.0f (+0x30), 3.0f (+0x34/+0x38/+0x3C), 0.25f (+0x44), 16.0f (+0x48), zeroes +0x4C, and returns 0. Single caller is MaterialShaderReactionEffectParser (0x004CA480).
- `0x004CADA0` **UnknownObject** — Blend-mode token to enum converter: only entered when the input matches the ZERO token via sub_588410; each later token failing its match returns the tested mode's enum value (ONE=2, SRCCOLOR=3, INVSRCCOLOR=4, SRCALPHA=5, INVSRCALPHA=6, DSTCOLOR=9, INVDSTCOLOR=10, DSTALPHA=7, INVDSTALPHA=8); a StringSplitLoop probe against the source-path token logs an unknown-mode warning via DebugLogWrite; default return is 1 (ZERO).
- `0x004CC970` **ParticleEmitter** — Weather/rain particle spawner: guarded by the emission count at this+0x58, adds wind noise from flt_8AB274/dword_8AAE70 onto the position vector, resolves magnitude/fall factors through the scoring-gate helpers (dword_8AB6E4==2 delegates via Delegation/VehicleDataAccessor/FloatDifference, else dbl_8AFEA0/dbl_8AFE98), refreshes state via sub_4CC840, derives the per-frame spawn count from detail shift at this+0x8, allocates circular-buffer slots via CircularBufferSlotAlloc, seeds position/speed/id/color per slot, and renders each slot's bounding box via F_3DBoundingBoxRender.
- `0x004CCDC0` **ParticleEmitter** — Particle position offset pass: computes the delta a3-a2 per component, mixes in weather noise from flt_8AB274/dword_8AAE70, iterates the this+0x64 particles whose pointers live at this+0x68 adding the offset to each particle position, then calls ParticleEffectPhysics(this, accumulated) and returns its result.
- `0x004CCE90` **ParticleEmitter** — Particle burst spawner: guarded by slot capacity at this+0x58, scales spread/velocity from a5/a4, selects the emission time scale through the scoring gate (dword_8AB6E4==2 via VehicleDataAccessor/FloatDifference, else dbl_8AFE98) and time base (Delegation vs dbl_8AFEA0), obtains a collision normal via CollisionNormalFromFeature on dbl_7C9360, fetches base velocity via VirtualDispatchHelper from dword_5EA510, computes the particle count from detail shift at this+0x8, allocates slots via CircularBufferSlotAlloc seeding randomized position/velocity from the noise table, and sets up a billboard quad via ParticleEffectBillboardQuadSetup.
- `0x004CD220` **ParticleEmitter** — Full particle-system update: reads the wind vector via VirtualDispatchHelper(dword_5EA510)+36; selects the time step through the scoring gate (dword_8AB6E4==2: VehicleDataAccessor==5 forces 0, else FloatDifference, else dbl_8AFE98) and delegates dword_8AB6EC vs dbl_8AFEA0; removes out-of-lifetime particles via ArrayElementRemoval; integrates velocity with damping/gravity, ground-plane clamps/reflects, runs proximity collision against the player or FindDriversInRange vehicles (AABB tests via F_3DAABBOverlapTestWithSlidingResponse), and draws each particle via ParticleEffectBillboardQuadSetup. Returns the particle count.
- `0x004CDB20` **UnknownObject** — Per-frame object-type dispatch: reads the type selector dword at this+4 and routes through the jump table jpt_4CDB2F (0x004CDB58 / byte_4CDB74 at 0x004CDB74): types 0-4 to ParticleInstanceUpdate, 5 to WheelRenderObjectPerFrameUpdate, 6-7 to ScoringGateTimeoutCheck, 8 to TelemetryBarIndicatorRenderer, 12 to ParticleSystemUpdateWithWindAndDamping, 13 to ParticleEffectPhysics; any other type returns the selector unchanged. Invoked by WeatherParticleUpdate.
- `0x004CDC70` **UnknownObject** — Track surface material token parser: reads the token via sub_565520(a2, buffer, 0); numeric literals (first byte 48-57 or 46) convert directly via sub_58850F; otherwise a linked list headed by a4 is walked comparing names with strcmp, returning the float at entry+32 on match; on failure a StringSplitLoop/DebugLogWrite error path runs and 0 is returned.
- `0x004CE860` **UnknownObject** — Strided string-table lookup: copies the caller string, normalizes it via sub_589901, and walks 108-byte entries from this+0xC bounded by the count at this+0x8, comparing via StringTableLookup; returns the matching index or -1 when empty/not found.
- `0x004CFED0` **SpecialFX** — Special-effects teardown: optionally logs entry (StringSplitLoop/DebugLogWrite), frees the 60-byte-stride emitter array (count at ptr-4) calling per-element sub_4CA280, frees two 108-byte-stride arrays (sub_4CA410 per element / FreeIfNonNull / MultiFieldFree), cleans the collision tree via CollisionTreeNodeCleanup on dbl_7C9360, frees count-header buffers via FreeWrapper_7bcf, and zeroes all twelve fields.
- `0x004D0060` **UnknownObject** — Trivial object zero-init helper: clears the dword at this+0x4, calls the no-argument sub_4D0080, and returns this. Single caller is sub_4D2DD0.
- `0x004D0C20` **UnknownObject** — Driver standings qsort comparator over index bytes at this+0x0 into the 18624-byte-per-driver array unk_5F070C: retired-first ordering (status at +12 == 3), rank dword compare at +11, float time/gap compare at +26 against the zero threshold flt_59E440, and a stable pointer-address tiebreaker. Invoked by PitStopOrderRank.
- `0x004D0E20` **UnknownObject** — Steward light/glow scene-node resolver: evaluates scene node property index 0 for identifiers a2/a3 via EvaluateSceneNodeProperty storing handles at this+4 (line) and this+8 (glow); when a handle is zero a StringSplitLoop probe runs and, on success, DebugLogWrite logs a could-not-find message. Returns the glow handle.
- `0x004D0EC0` **UnknownObject** — Value setter with dual conditional notify gates: stores a2 at this+0x0 unconditionally; if the flag at this+0x4 was non-zero calls sub_5506A0(a2,0,0) keeping its result; if the flag at this+0x8 is non-zero calls sub_5506A0(a2,0,0) again and returns that result directly. Called by PitTimer and Steward_Restart.
- `0x004D0F00` **UnknownObject** — Minimal single-field setter: stores a2 into the dword at this+0x0 and returns a2. No branching or callees; called by MIDI parsing and steward lifecycle helpers.
- `0x004D11D0` **UnknownObject** — Timer text formatter/renderer: formats float elapsed time a1 as "%s%02d:%02d" (prefix:MM:SS, prefix defaulting to byte_5EA438) into a 128-byte buffer and submits it to the render context dword_7CD204 via ShortComputation_bde0 and TextLineWrappingAndRendering; a first pass formats both two-digit fields from a1+2.0, a second recomputes minutes/seconds from a1+1.0. Called by PitTimer.
- `0x004D1410` **UnknownObject** — Lazy-initializing indexed accessor into the pit-stop-order array: if the array pointer at this+0x1AC is null, loads it via PitStopOrderLoader; the index is bounds-checked against the count at this+0x1A8; valid indexes fetch the entry at an 8-byte stride from this+0x1AC, falling back to byte_5EA438 when the entry is null.
- `0x004D15F0` **UnknownObject** — Pit door/tent scene-node setup: calls sub_4D1450 (logo texture loading), then gated on dword_8AFE88 being non-zero loops 52 times formatting "PDOOR%02d"/"PTENT%02d" names, resolving each via EvaluateSceneNodeProperty into the pit-door handle array 52 entries before this+0x280 and the pit-tent handles at this+0x280. Returns the last property result. Invoked by VidMan_Init.

## Proposed classes

### Particle

Particle instance: position, direction, color and attribute state initialized from noise-perturbed inputs and the shared weather noise table (0x008AB274 / counter 0x008AAE70), including a random 0..15 index and a lifetime-derived packed ARGB word.

Methods: `0x004C9D60`

- `this+0x00000010` `float positionX` (write, DERIVED)
- `this+0x00000014` `float positionY` (write, DERIVED)
- `this+0x00000018` `float positionZ` (write, DERIVED)
- `this+0x0000001C` `float positionSpanEnd` (write, DERIVED)
- `this+0x00000020` `float reciprocalY` (write, GUESS)
- `this+0x00000024` `float reciprocalSpan` (write, GUESS)
- `this+0x00000028` `float lifetimeOrSize` (write, DERIVED)
- `this+0x00000048` `float directionX` (write, DERIVED)
- `this+0x0000004C` `float directionY` (write, DERIVED)
- `this+0x00000050` `float directionZ` (write, DERIVED)
- `this+0x00000054` `int randomIndex` (write, DERIVED)
- `this+0x00000060` `dword packedArgb` (write, DERIVED)
- `this+0x00000068` `float scaleFactor` (write, DERIVED)

### SpecialFX

Special-effects manager teardown: releases a 60-byte-stride emitter array and two 108-byte-stride arrays whose element counts are stored 4 bytes before each pointer, cleans the collision tree node pool, and zeroes all fields on session end.

Methods: `0x004CFED0`

- `this+0x00000000` `int emitterCount` (write, DERIVED)
- `this+0x00000004` `void** (60-byte stride) emitterArray` (read_write, DERIVED)
- `this+0x00000008` `int arrayACount` (read_write, GUESS)
- `this+0x0000000C` `void** (108-byte stride) arrayAPointer` (read_write, DERIVED)
- `this+0x00000010` `int arrayBCount` (read, DERIVED)
- `this+0x00000014` `void** (108-byte stride) arrayBPointer` (read_write, DERIVED)
- `this+0x00000018` `int zeroedField18` (write, GUESS)
- `this+0x0000001C` `int zeroedField1C` (write, GUESS)
- `this+0x00000020` `int zeroedField20` (write, GUESS)
- `this+0x00000024` `int zeroedField24` (write, GUESS)
- `this+0x00000028` `int zeroedField28` (write, GUESS)
- `this+0x0000002C` `int zeroedField2C` (write, GUESS)

### ParticleEmitter

Weather/effect particle emitter: spawns particles from noise-table and scoring-gate inputs (detail shift at this+0x8, emission capacity at this+0x58), allocates circular-buffer slots, updates particle positions with wind/damping/gravity/rotation and collision, and renders billboards (live particle array at this+0x64/this+0x68).

Methods: `0x004CC970`, `0x004CCE90`, `0x004CCDC0`, `0x004CD220`

- `this+0x00000008` `int detailShift` (read, DERIVED)
- `this+0x00000058` `int emissionCapacity` (read, DERIVED)
- `this+0x00000064` `int particleCount` (read, DERIVED)
- `this+0x00000068` `void** particleArray` (read, DERIVED)

## Compatibility contracts

- **GlobalObjectVTableDispatch** — A global object pointer dword_8AC4C4 may be null; when non-null a replacement must preserve the indirect __stdcall through vtable slot +60 passing selector argument 1 when the caller predicate (a1==1) holds and 0 otherwise, and must return the dispatched result.
- **ObjectTypeDispatch** — Object dispatch reads a type dword at this+4 and routes through a jump table: preserve routing for types 0-4 (particle instance), 5 (wheel render object), 6-7 (scoring gate timeout), 8 (telemetry bar indicator), 12 (particle system), 13 (particle physics); any other type must return the selector unchanged.
- **VehicleSpeedSortOutput** — SortDriversByDistance writes each driver's summed speed (floats at vehicle+1848 and vehicle+1856) into an output buffer starting at this[103], over a count read from dword_5C329C, using a generic sort with a speed-sum comparator and 4-byte elements.
- **DriverStandingSortOrder** — The driver standings comparator indexes the 18624-byte-per-driver array unk_5F070C by bytes at this+0x0 and orders retired drivers (status dword at +12 == 3) after active ones, comparing rank dwords at +11, then the float time/gap at +26 (byte offset 104) against the zero threshold flt_59E440, with a stable pointer tiebreaker.
- **CountHeadedArrayFree** — SpecialFX teardown releases count-headed arrays in which the element count word is stored 4 bytes before the pointer, with 60-byte and 108-byte element strides; per-element destructors run for the emitter and second 108-byte arrays before the count-header buffers are freed.
- **PitStopOrderAccessorLayout** — The pit-stop-order indexed accessor keeps the element count at this+0x1A8 and the entry array pointer at this+0x1AC with an 8-byte entry stride; out-of-range indexes return null and null entries fall back to the string byte_5EA438.
- **BlendModeTokenEnum** — Blend-mode token to enum mapping: default return 1 (ZERO) when no token matches; ONE=2, SRCCOLOR=3, INVSRCCOLOR=4, SRCALPHA=5, INVSRCALPHA=6, DSTALPHA=7, INVDSTALPHA=8, DSTCOLOR=9, INVDSTCOLOR=10, where each failed match returns the tested mode's value.

## Unresolved

- Most owner object types are UNKNOWN in the packet; only setupParticlePosition (Particle, DERIVED) and Post (SpecialFX, DERIVED) carry named owners. All other functions are assigned to UnknownObject.
- ParticleEmitter is a GUESS grouping: the spawn functions (fields this+0x8 and this+0x58) and the update functions (fields this+0x64 and this+0x68) have disjoint field sets; a single shared struct is inferred but not proven by the packet.
- UpdateChildParticlesWithRotationAndScale (0x004CA2D0) is left unassigned: its field set (this+0x14..+0x38) is disjoint from both Particle and ParticleEmitter, and its 20-byte child-entry layout (target pointer, X/Y/Z, weight) is not evidenced as fields.
- Indirect vtable dispatch targets are not resolvable: slot +60 of the global object behind dword_8AC4C4 (0x004C8D90) and slot +12 (0x004C8FC0) are not packet callees.
- The six ObjectTypeDispatchUpdate handlers (ParticleInstanceUpdate, WheelRenderObjectPerFrameUpdate, ScoringGateTimeoutCheck, TelemetryBarIndicatorRenderer) have decompiler names only; the packet lists no callee entries for them, so their addresses are unverified.
- The packet read-references many globals (flt_59E43C, flt_59E440, flt_59E450, flt_59E46C, flt_59E4DC, flt_59E774, flt_59E778, flt_59E7E8, flt_59E86C, flt_59E8CC, flt_59E9C0, flt_59ED18, flt_59F118, flt_5ACE90, flt_5ACE98, flt_5ACEB0, flt_5ACEB4, flt_5ACEB8, dbl_8AFE88 for FindLightAndGlowNodes) that do not appear in the raw decompiled bodies; their roles are unresolved.
- The null-global path of GlobalVTableDispatchByParam (0x004C8D90) returns an uninitialized local; the effective return value on that path is undefined.
- The steward/pit helper cluster (0x004D0C20, 0x004D0E20, 0x004D0EC0, 0x004D0F00, 0x004D11D0, 0x004D1410, 0x004D15F0) has no defensible common class from packet evidence; owners are kept UNKNOWN rather than forcing a grouping.
- The D3DBLEND-style enum mapping for values 7..10 (DSTALPHA, INVDSTALPHA, DSTCOLOR, INVDSTCOLOR) is DERIVED from existing analysis, not confirmed by this packet.
- The vehicle speed offsets +1848/+1856 and the driver record time/gap at dword +26 (byte offset 104) and status/rank semantics are DERIVED from branch structure, not confirmed.
- StringListLookup's 108-byte table entry layout and the transformation performed by sub_589901 are not established by this packet.
- TrackSurfaceTokenToFloat's linked-list entry layout (float at +32, next pointer at +36) is described from the raw source only; no field evidence refs exist for it.
- SpecialFX field this+0x8 is only observed being zeroed; its count role is inferred from the surrounding free loops.
- The role of field obj+0xC in sub_4C8FC0 is unknown; it may be consumed inside ArithmeticComparison_9000.
- ParticleEmitter and the worker-named classes are evidence-linked proposals, not recovered original source names.
