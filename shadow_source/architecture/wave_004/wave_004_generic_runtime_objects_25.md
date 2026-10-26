# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

This scope collects generic runtime objects that are not vehicle physics, UI/options or math: a texture creation path with power-of-two validation (0x0054FEC0), a texture path parser and coordinate scaler (0x00552F20), a font glyph renderer and string measurer that share a glyph table anchor this+8*char-148 (0x00552910, 0x005531F0), a family of vertex/render buffer objects that submit 36-byte descriptors to the global render device 0x008B78A0 (0x005527C0, 0x00553370, 0x00553650, 0x00553700, 0x00553980), a device-state object family that seeds channels and publishes state changes to the global device object 0x008B89A0 through vtable slot +252 (0x00553E10, 0x00553FC0, 0x00554660), a mode-state switch that dispatches property 14 through a device vtable slot +0xC8 (0x00554BE0), a QPC-based timer state with an elapsed cap behind this+0x1C (0x005514C0) plus its conditional forwarder (0x00551810), two linked-list walkers over animation/scrolling entries anchored at this+0x204 (0x005505A0, 0x00550620), a name-matching linked-list walker at this+0x13C (0x00551830), and leaf utilities (setter 0x00550300, zero-initializers 0x005507A0/0x00550800, wrapper 0x00550AC0, global audio flag setter 0x00551FB0, hash/string-table entry constructor 0x005523E0). Class boundaries are derived from shared field layouts and shared callees; ownership of most leaf objects remains unconfirmed.

## Function roles

- `0x0054FEC0` **TextureObject** — Create a texture: validate width/height are powers of two (accepted set 1..4096), report 'Texture %s size not power of 2' on failure via sub_53C590, associate the texture name, initialize the texture data and clean up on initialization failure.
- `0x00550300` **UnknownObject** — Inline setter: store the caller value into this+0x4C and return it unchanged.
- `0x005505A0` **AnimationNodeListOwner** — Walk the animation-node linked list anchored at this+0x204 and decrement track values that reference a given animation data entry, gated by entry index bounds, entry type and step threshold.
- `0x00550620` **AnimationNodeListOwner** — Walk the scrolling/audio-entry linked list anchored at this+0x204 and add a step value to track values referencing a given target, with the same index/type/threshold guards as the decrement twin.
- `0x005507A0` **UnknownObject** — Constructor/initializer: call IdentityFunction_b490(this+4), zero the eight dwords from this+0x0 through this+0x1C and return this.
- `0x00550800` **UnknownObject** — Object initializer: zero the first two dwords (this+0x0, this+0x4) and return this; structurally similar to ZeroPairInit per cluster analysis.
- `0x00550AC0` **UnknownObject** — Wrapper that calls sub_550F70 with no arguments and always returns the constant 0.
- `0x005514C0` **TimerStateObject** — Advance a timed entity state: on the 0x1000 flag clear it, set the 0x8000 timer-active bit, zero the accumulator and reset the QPC handle; on the 0x80 flag query elapsed time from the QPC handle and cap it at *(this+0x1C)+8; at the cap dispatch through the 0x20000 cascade path or the sub-init/audio-flag path and apply the elapsed time via sub_551210.
- `0x00551810` **UnknownObject** — Dispatch guard: when the second argument a2 is non-null, forward to sub_551210(a2, this, a3) with a2 as the callee's primary object; no-op when a2 is null.
- `0x00551830` **NamedNodeListOwner** — Walk the singly linked list at this+0x13C, compare each node's name string (node+28 dereferenced at +28) against the search key and return the first matching node; return 0 for an empty list or no match.
- `0x00551FB0` **UnknownObject** — Normalize the integer argument to a BOOL (nonzero becomes 1), store it into the global audio flag dword_8B6AC4 and return the BOOL.
- `0x005523E0` **HashTableEntryObject** — Constructor/initializer: zero-fill the object via GlobalZeroInit_c2a0 then install default literals across 26 fields (float 1.0 at 0x0/0x4/0x5C/0x60, -8.0 at 0x48, 0x10000 at 0x24, 192/65538/127 at 0x50/0x54/0x58, value 1 at 0x34..0x40, zeros elsewhere) and return this.
- `0x005527C0` **VertexBufferSurfaceObject** — Initialize a vertex-buffer surface: gate on flag bit 0x20000 at this+0x24, lazily allocate a 36-byte descriptor at this+0xC, fill primitive type 34/count 768/size 28/stride dword_8CEF78, validate against the device, allocate the vertex buffer into this+0x10, initialize each 28-byte vertex and finalize.
- `0x00552910` **FontGlyphRenderer** — Render a single font glyph as a textured quad: validate the glyph index against this+0x44, select the clipped path (flag 0x10000 at this+0x24) or append six 28-byte textured vertices to the buffer at this+0x10, then return the per-glyph attribute byte.
- `0x00552F20` **TexturePathParser** — Parse a texture file path and compute texture-coordinate scale factors: dispatch on the loader pixel format at *(this+0x64)+0x30, strip the directory prefix, copy the file name into this+0x14, store 1/width and 1/height at this+0x0/+0x4 and copy the key color into loader field +0x34.
- `0x005531F0` **FontGlyphRenderer** — Measure a text string with the font descriptor: compute the scale factor (default 1.0 or this+0x5C), write the truncated height through a4 and accumulate per-glyph widths for chars in [0x20, this+0x44) through the width table, returning the last truncated scale value.
- `0x00553370` **RenderVertexBufferObject** — Initialize a render vertex-buffer object in mode 1 or 2: lazily allocate the source buffer and descriptor, write primitive type 34/count 16 and mode-specific stride/size, validate the descriptor, lock the device buffer and copy the source vertices with a 24- or 28-byte layout, then commit.
- `0x00553650` **RenderVertexBufferObject** — Insert one 28-byte vertex into the UI/2D primitive vertex buffer at index a2 (0..15): guard the insertion-enabled bit and the index bound, write the vertex record into the data array at this+0x18, grow the stored count and set the dirty flag bit 0x8000.
- `0x00553700` **RenderVertexBufferObject** — Per-frame audio/render buffer update: when the element count is positive and the pending-update flag bit is set, clear the bit and upload count elements from this+0x18 into the locked buffer at this+0x14 with a 24- or 28-byte stride, then rebuild UI/format state, initialize local audio state, configure the audio buffer format and apply vtable-driven UI text updates.
- `0x00553980` **RenderVertexBufferObject** — stdcall constructor for a 36-byte heap object: allocate via OperatorNewNhMallocWrapper, zero-initialize, configure through sub_553370, SetterWrites0x10Returns0 and TwoFieldSetter_3630 when the parameters are nonzero, run sub_55C2A0 as a post-init hook and store the constructed object through a1.
- `0x00553E10` **DeviceStateObject** — Initialize a device-state object: store the object id at this+0x0, seed channel fields with defaults 1/2, zero the remaining state fields this+0x24 through this+0x40 and publish each channel's value to the global device object 0x008B89A0 through its virtual dispatch table.
- `0x00553FC0` **DeviceStateObject** — State-machine transition setter: skip when a2 is -1 or equals the stored state this+0x24, dispatch on a2 writing the three mode fields this+0x4/+0x8/+0xC (guarded per field), notify the GameDeviceObject through vtable slot +252 and store the new state on the shared exit path.
- `0x00554660` **DeviceStateObject** — Float state setter: when a2 differs from the stored value at this+0x40, store a2 and dispatch a change notification through the global device object's vtable slot +252 with the object id, constant selector 19 and the new value.
- `0x00554BE0` **ModeStateObject** — Set the active mode state on a device object: short-circuit when a2 equals the mode at this+0x13A0, otherwise store a2, read the device pointer at this+0x1100 and dispatch property 14 through its vtable slot +0xC8 with value 1 or 0, storing the dispatch result at this+0x0.

## Proposed classes

### FontGlyphRenderer

Renders font glyphs as textured quads and measures text strings against a shared glyph table anchored at this+8*char-148, bounded by the glyph count at this+0x44.

Methods: `0x00552910`, `0x005531F0`

- `this+0x00000008` `int vertexCount` (read_write, GUESS)
- `this+0x00000010` `void* vertexBufferPtr` (read_write, GUESS)
- `this+0x00000024` `uint renderPathFlags` (read, GUESS)
- `this+0x0000002C` `unknown renderParameter` (read, GUESS)
- `this+0x00000034` `float cellWidth` (read, GUESS)
- `this+0x00000038` `float cellHeight` (read, GUESS)
- `this+0x00000044` `int glyphCount` (read, GUESS)
- `this+0x00000048` `uint diffuseColor` (read, GUESS)
- `this+0x0000005C` `float cellScaleX` (read, GUESS)
- `this+0x00000060` `float cellScaleY` (read, GUESS)
- `this+0x00000064` `void* glyphTexturePtr` (read, GUESS)
- `*(this+0x64)+0x0000001C` `float sourceTextureWidth` (read, GUESS)
- `*(this+0x64)+0x00000020` `float sourceTextureHeight` (read, GUESS)
- `*(this+0x10)+0x00000000` `float vertexX` (write, GUESS)
- `*(this+0x10)+0x00000004` `float vertexY` (write, GUESS)
- `*(this+0x10)+0x00000008` `unknown vertexPad` (write, GUESS)
- `*(this+0x10)+0x0000000C` `float vertexRhw` (write, GUESS)
- `*(this+0x10)+0x00000010` `uint vertexDiffuse` (write, GUESS)
- `*(this+0x10)+0x00000014` `float vertexU` (write, GUESS)
- `*(this+0x10)+0x00000018` `float vertexV` (write, GUESS)
- `*(this+0x10)+0x0000001C` `int vertexStride` (write, GUESS)

### RenderVertexBufferObject

Render/audio vertex-buffer object holding type/flags at this+0x0, element count at this+0x4, a 36-byte device descriptor at this+0x14 and a source vertex array at this+0x18; initialized by type, filled vertex-by-vertex, uploaded per frame and constructed by a stdcall allocator.

Methods: `0x00553370`, `0x00553650`, `0x00553700`, `0x00553980`

- `this+0x00000000` `uint typeAndFlags` (read_write, GUESS)
- `this+0x00000004` `int elementCount` (read_write, GUESS)
- `this+0x00000008` `unknown formatParamA` (read, GUESS)
- `this+0x0000000C` `unknown formatParamB` (read, GUESS)
- `this+0x00000010` `unknown formatParamC` (read, GUESS)
- `this+0x00000014` `void* bufferDescriptorPtr` (read_write, GUESS)
- `this+0x00000018` `void* vertexDataPtr` (read_write, GUESS)

### VertexBufferSurfaceObject

Rendering object that owns a lazily allocated 36-byte vertex-buffer descriptor (this+0xC), a vertex buffer pointer (this+0x10) and an enable flag (this+0x24); initializes and finalizes a 768-vertex buffer on the render device.

Methods: `0x005527C0`

- `this+0x0000000C` `void* bufferDescriptorPtr` (read_write, GUESS)
- `this+0x00000010` `void* vertexBufferPtr` (read_write, GUESS)
- `this+0x00000024` `uint enableFlag` (read, GUESS)
- `*(this+0xC)+0x00000000` `int primitiveType` (write, GUESS)
- `*(this+0xC)+0x00000004` `int vertexStride` (write, GUESS)
- `*(this+0xC)+0x00000008` `int vertexSize` (write, GUESS)
- `*(this+0xC)+0x0000000C` `int vertexCount` (write, GUESS)

### DeviceStateObject

Device-state object that seeds channel fields with defaults, zeroes the remaining state block, stores transitions and publishes every channel and state change to the global GameDeviceObject 0x008B89A0 through its virtual dispatch table (vtable slot +252).

Methods: `0x00553E10`, `0x00553FC0`, `0x00554660`

- `this+0x00000000` `int objectId` (read, GUESS)
- `this+0x00000004` `int channelFieldA` (read_write, GUESS)
- `this+0x00000008` `int channelFieldB` (read_write, GUESS)
- `this+0x0000000C` `int channelFieldC` (read_write, GUESS)
- `this+0x00000018` `int channelFieldD` (read_write, GUESS)
- `this+0x0000001C` `int channelFieldE` (read_write, GUESS)
- `this+0x00000020` `int channelFieldF` (read_write, GUESS)
- `this+0x00000024` `int lastState` (read_write, GUESS)
- `this+0x00000028` `int stateFieldZeroed` (write, GUESS)
- `this+0x0000002C` `int stateFieldZeroed` (write, GUESS)
- `this+0x00000030` `int stateFieldZeroed` (write, GUESS)
- `this+0x00000034` `int stateFieldZeroed` (write, GUESS)
- `this+0x00000038` `int stateFieldZeroed` (write, GUESS)
- `this+0x0000003C` `int stateFieldZeroed` (write, GUESS)
- `this+0x00000040` `float floatState` (read_write, GUESS)

### ModeStateObject

Device wrapper that stores the active mode at this+0x13A0, reads its device pointer at this+0x1100 and dispatches property 14 through the device vtable slot +0xC8, caching the dispatch result at this+0x0.

Methods: `0x00554BE0`

- `this+0x00000000` `int lastDispatchResult` (read_write, GUESS)
- `this+0x00001100` `void* deviceObjectPtr` (read, GUESS)
- `this+0x000013A0` `int modeState` (read_write, GUESS)
- `*(this+0x1100)+0x000000C8` `void*(*)(void*, int, int) propertyDispatchSlot` (read, GUESS)

### TimerStateObject

Timed entity state advanced by flags and a high-resolution QPC handle at this+0x0: audio-reset and timer-active flag paths, elapsed query and cap enforcement against the cap structure behind this+0x1C, then dispatch to entity state application.

Methods: `0x005514C0`

- `this+0x00000000` `void* qpcHandle` (read, GUESS)
- `this+0x00000004` `uint timerFlags` (read_write, GUESS)
- `this+0x00000008` `uint accumulator` (read_write, GUESS)
- `this+0x00000010` `float elapsedTime` (read_write, GUESS)
- `this+0x0000001C` `void* capStructPtr` (read, GUESS)
- `*(this+0x1C)+0x00000008` `float maxDuration` (read, GUESS)

### AnimationNodeListOwner

Owns a linked list of animation/scrolling nodes anchored at this+0x204; each method walks the node list and updates per-track values referencing an animation data entry, incrementing or decrementing by the entry step.

Methods: `0x005505A0`, `0x00550620`

- `this+0x00000204` `void* animationNodeListHead` (read, GUESS)

### NamedNodeListOwner

Owns a singly linked list of named nodes anchored at this+0x13C; provides name lookup by walking the list and comparing each node's name string.

Methods: `0x00551830`

- `this+0x0000013C` `void* namedNodeListHead` (read, GUESS)

### TextureObject

Texture creation entry point: validates power-of-two dimensions, associates the texture name, initializes the texture data through the pointer at this+0x54 and cleans up on failure.

Methods: `0x0054FEC0`

- `this+0x00000054` `void* textureDataOwner` (read, GUESS)

### TexturePathParser

Parses a texture file path, dispatches on the loader pixel format, copies the base file name and computes texture-coordinate scale factors (1/width, 1/height) plus the key color.

Methods: `0x00552F20`

- `this+0x00000000` `float scaleX` (write, GUESS)
- `this+0x00000004` `float scaleY` (write, GUESS)
- `this+0x00000014` `char[] fileNameBuffer` (write, GUESS)
- `this+0x0000002C` `uint keyColor` (read, GUESS)
- `this+0x00000064` `void* loaderObjectPtr` (read, GUESS)
- `*(this+0x64)+0x0000001C` `int loaderWidth` (read, GUESS)
- `*(this+0x64)+0x00000020` `int loaderHeight` (read, GUESS)
- `*(this+0x64)+0x00000030` `int pixelFormat` (read, GUESS)
- `*(this+0x64)+0x00000034` `uint keyColorTarget` (write, GUESS)

### HashTableEntryObject

Hash/string-table entry constructed by zero-filling and installing 26 default literal fields; called only by sub_53CFE0.

Methods: `0x005523E0`

- `this+0x00000000` `float defaultOneA` (write, GUESS)
- `this+0x00000004` `float defaultOneB` (write, GUESS)
- `this+0x00000008` `int zeroField` (write, GUESS)
- `this+0x0000000C` `int zeroField` (write, GUESS)
- `this+0x00000010` `int zeroField` (write, GUESS)
- `this+0x00000014` `byte zeroByte` (write, GUESS)
- `this+0x00000024` `int default0x10000` (write, GUESS)
- `this+0x00000028` `int zeroField` (write, GUESS)
- `this+0x0000002C` `int zeroField` (write, GUESS)
- `this+0x00000030` `int zeroField` (write, GUESS)
- `this+0x00000034` `int oneField` (write, GUESS)
- `this+0x00000038` `int oneField` (write, GUESS)
- `this+0x0000003C` `int oneField` (write, GUESS)
- `this+0x00000040` `int oneField` (write, GUESS)
- `this+0x00000044` `int zeroField` (write, GUESS)
- `this+0x00000048` `float minus8Float` (write, GUESS)
- `this+0x0000004C` `int zeroField` (write, GUESS)
- `this+0x00000050` `int default192` (write, GUESS)
- `this+0x00000054` `int default65538` (write, GUESS)
- `this+0x00000058` `int default127` (write, GUESS)
- `this+0x0000005C` `float defaultOneC` (write, GUESS)
- `this+0x00000060` `float defaultOneD` (write, GUESS)
- `this+0x00000064` `int zeroField` (write, GUESS)
- `this+0x00000868` `int tailField` (write, GUESS)
- `this+0x0000086C` `int tailField` (write, GUESS)
- `this+0x00000870` `int tailField` (write, GUESS)

## Compatibility contracts

- **TexturePowerOfTwoDimensionCheck** — Texture creation rejects any width or height outside the power-of-two set 1..4096; on rejection it formats the error 'Texture %s size not power of 2' (format string at 0x5DBFEC) via StringFormatWithBufferOverflowCheck and reports it through sub_53C590(-1, buffer) before returning -1.
- **AudioEnabledGlobalFlag** — dword_8B6AC4 holds a normalized BOOL (0/1) controlling the audio subsystem; writes normalize any nonzero input to 1 and return the stored BOOL.
- **DeviceStateVtableNotification** — State changes on device-state objects are pushed to the global GameDeviceObject 0x008B89A0 through vtable slot +252 (rarely +244) with (device, objectId, field selector, value); a replacement executable must preserve this dispatch contract so external consumers observe the same state.
- **ModeStatePropertyDispatch** — Mode switches dispatch property 14 through vtable slot +0xC8 on the device pointer stored at this+0x1100, with value 1 or 0 selected by the mode argument; the dispatch result is cached at this+0x0 and returned.
- **VertexBufferDescriptorSubmission** — Vertex buffers are submitted to the global render device 0x008B78A0 via descriptor validation (sub_540DF0), buffer lock/allocation with element size 96 (sub_540F00) and finalization (sub_540F90); the vertex layout is 28-byte or 24-byte selected by mode/flag bits.
- **QpcElapsedTimeWithCap** — Elapsed time is read from a high-resolution QPC handle at this+0x0 (sub_5565B0) and capped at the maximum stored in the cap structure behind this+0x1C at offset +8; the capped value at this+0x10 is applied to entity state through sub_551210.

## Unresolved

- The object type at this+0x54 (texture) is only evidenced as a pass-through to UtilityFunction_2950; the ownership class of the texture remains unconfirmed.
- The success/failure convention of UtilityFunction_2950 (0 = success vs non-zero = failure) is inferred from the control flow, not independently confirmed.
- The exact role of sub_54FE50 (filename association vs emitter setup) is unresolved.
- The list-node structures walked by LinkedListAnimationTimerDecrement (0x005505A0) and ScrollingDataOffsetAcrossLinkedEntries (0x00550620) have no packet field evidence; node slots i[4]/i[70]/i[71] and the 148-byte record and 16-byte entry strides belong to external structures.
- Fields this+0x224, this+0x32C, this+0x330 and this+0x364 are listed by the fact table for the list-owner object but are not referenced in the packet raw sources and cannot be assigned to an operation.
- The *(this+0x160) base used for the named-list node fields (node+28, node+36) does not literally match the raw source of 0x00551830, which reads the node from this+0x13C; that derivation is unproven.
- flt_59E43C appears in the packet global set but is not referenced in any raw body.
- The raw flow of FontStringMeasure overwrites the accumulated width at *a3 with CRTFtol(scale) after the summing loop; the intended width transform is ambiguous.
- The meaning of the v14 float bit patterns (1059256707, 1038323257, 1065353216, -1137308831) written by 0x00553700 is unresolved; they likely encode colour/scale constants.
- The identity of the hash/string-table entry object (0x005523E0) beyond its ABI lead name is unconfirmed; the semantics of defaults 1.0/-8.0/0x10000/192/65538/127 and of the tail fields 0x868/0x86C/0x870 are unknown.
- The 24-byte vs 28-byte vertex layout semantics and the meaning of the buffer element-size 96 in BufferLockAllocate are inferred, not confirmed.
- The pixel-format values (5/6 vs 7/8) dispatched by 0x00552F20 and the meaning of loader field +0x34 are not established by the packet.
- The grouping of 0x00553FC0 and 0x00554660 with 0x00553E10 into DeviceStateObject is DERIVED from the shared dword_8B89A0 notify pattern; independent class ownership of those two functions is unconfirmed.
- The mode-state enum semantics (a2 values 0..12) and the meaning of the three mode fields this+0x4/+0x8/+0xC in 0x00553FC0 are not established from evidence.
- The a2 == this+0x24 check in 0x00553FC0 implies a cached-state optimization; whether this+0x24 is also a re-entry guard is unclear.
- The cap structure behind this+0x1C is evidenced only through its +8 field; its full layout is unknown.
- The render-path and timer flag bits (0x1000 audio reset, 0x8000 timer active, 0x10000 clip path, 0x20000 cascade mode) are DERIVED from the fill annotations, not independently evidenced.
- The roles of sub_540DF0 vs ArithmeticComparison_0f90 (validation vs commit) depend on their callees, not visible in this packet.
- The 36-byte object constructed by 0x00553980 is identified as a render-buffer object through its sub_553370 call, but the exact field layout written by each setter (0x00553620, 0x00553630) is unconfirmed.
- Whether this+0x8/0xC/0x10 in 0x00553700 are audio format parameters or vertex format parameters is ambiguous from this function alone.
- The semantics of dword_8B6AC4 beyond 'audio global flag' and the identity of its consumer are not established.
