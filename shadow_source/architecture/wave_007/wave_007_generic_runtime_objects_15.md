# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED grouping of thirty validated functions in the generic_runtime_objects scope. Two are stateless math helpers (plane-from-triangle 0x0050E585, quaternion normalize 0x0050ED19). Three are platform capability probes: a Direct3D registry value query (0x0050FBFC), a cpuid leaf-1 EDX-bit-23 probe (0x0050FC58), and MMX detection with a 'DisableMMX' registry override and a cached state global (0x0050FC7D). Three are thin dispatch/vtable thunks (0x0050EDD2, 0x0050F6F2, 0x00511686). One is a state-machine dispatch wrapper that writes opcodes 18/50 into a vtable-backed target object (0x0050F9AB). One is a stream-based image frame decoder (0x00510012). Three form a callback/serialization layer (0x005117C8 escaped-hex record serializer, 0x00511887 optional callback dispatch, 0x005118C1 two-step delegation). The remaining seventeen are media-surface support helpers all wired through the same caller 0x0050210E: two guarded dispatch routines (0x00511B5C, 0x00511F23), six guard-gated descriptor field readers (0x0051212E, 0x00512144, 0x0051215A, 0x00512183, 0x0051227F, 0x005122B2), PNG width-overflow validation (0x005121AE), four flag/state setters over this+0x60/0x61/0x117 (0x00512319, 0x00512322, 0x00512334, 0x005124D5), a composite state setter (0x00512366), and the packet-format encoder (0x005124DE). Two pixel byte-swap helpers (0x005123B3, 0x005123E0) share a separate caller 0x0051389E. The packet names owners only for 0x005118C1 (CallbackDispatchLayer) and 0x005121AE (PngImageValidation); every other owner is UNKNOWN in the packet, so all remaining classes are proposed GUESS groupings by shared caller and shared field base, not attested source layout.

## Function roles

- `0x0050E585` **MathVectorHelpers** — Plane-from-triangle helper: builds a float[4] plane (normal + offset) from three corners via the cross product of edges (a2-a3) and (a2-a4), writes normal components to offsets 0x0/0x4/0x8, invokes ThunkTo (0x0050C2B3), then writes the offset -dot(normal,a2) to 0xC and returns the output pointer.
- `0x0050ED19` **MathVectorHelpers** — Quaternion normalizer: computes the squared norm of a2, returns a straight copy (or nothing) when FloatRangeCheck(0x0050C042) reports unit length, scales by 1/sqrt(norm) above the 1.1754944e-38 threshold, and zeroes all four outputs at or below it; every path writes all four components of a1.
- `0x0050EDD2` **GenericDispatchThunks** — Sequential thunk wrapper: calls ThunkViaFunctionPointer (0x0050DD3A) with three float arguments and a pointer to a local 4-int stack buffer, then calls ThunkToIndirectCallViaDAT005d7860 (0x0050D857) which dispatches through the function pointer at 005d7860; returns a1 unchanged.
- `0x0050F6F2` **GenericDispatchThunks** — Forwarding thunk: passes its single argument unchanged to sub_516959 and returns that result verbatim; no computation, guard, or field access. Teardown role is inferred only from the canonical name and the caller ImageTextureDecompressor (0x00501722).
- `0x0050F9AB` **StateMachineDispatchController** — State-machine dispatch with extended result handling: reads the state at this+0x10; for states other than 200 and 201 writes opcode 18 to the target object's code slot (obj+0x14) with the state as argument (obj+0x18) and dispatches through the target vtable, then delegates to StateMachineDispatch (0x0050F86A); returns 1 when the inner dispatch returns 1, and on a result of 2 with flag a2 set writes opcode 50, dispatches it, calls VirtualDispatchConditionalValue (0x00516937) and returns 2; other inner results propagate unchanged.
- `0x0050FBFC` **PlatformCapabilityProbe** — Direct3D registry value query: opens HKLM\Software\Microsoft\Direct3D via RegOpenKeyA, queries the named value via RegQueryValueExA, closes the key, and returns TRUE only when both the open and query return ERROR_SUCCESS and the stored registry type equals the expected type parameter a1.
- `0x0050FC58` **PlatformCapabilityProbe** — cpuid feature probe (stdcall): executes cpuid with EAX=1 and returns whether EDX bit 23 (mask 0x800000) is set, i.e. whether the probed feature flag is present.
- `0x0050FC7D` **PlatformCapabilityProbe** — MMX capability detection with registry override: on a successful open of Software\Microsoft\Direct3D, a present 'DisableMMX' REG_DWORD (type 4) with non-zero data forces the cached state dword_5D7994 to 0 and returns 0; otherwise, when the cache is negative (uninitialized), it runs the CPU probe via sub_50FC58, emits EMMS when MMX is available, and stores 1 or 0 into dword_5D7994; returns the cached state.
- `0x00510012` **StreamMediaDecoder** — State-machine-driven frame decoder: consumes a byte stream through a refillable stream object (a2+20), parses an 8-byte big-endian header (length, metadata, width, height, count), decodes count 3-byte elements into 84-byte records, publishes color vectors and status codes (99/57/31/9/100), persists the stream position, and returns 1 on success or 0 on a failed refill; refill callback, vtable handlers, and allocator are indirect.
- `0x00511686` **GenericDispatchThunks** — Vtable dispatch thunk: reads the vtable pointer at this+0, allocates a 200-byte stack buffer, dispatches through vtable entry +0xC with (a1, buffer), and returns the virtual call's result; no other side effects.
- `0x005117C8` **CallbackDispatchLayer** — cdecl text serializer: iterates four bytes at a1+268, escaping bytes outside the printable alphanumeric range as '[' + two hex digits from the byte_5AF210 lookup + ']', otherwise copying them verbatim; when a2 is non-null appends ': ' and a 0x40-byte payload with the 64th byte forced to 0, otherwise appends a null terminator; returns the end-of-buffer pointer.
- `0x00511887` **CallbackDispatchLayer** — Optional callback dispatch: loads the function pointer at this+0x44; when non-null invokes it with (receiver, argument) and returns its result, otherwise returns NULL; no side effects on failure.
- `0x005118C1` **CallbackDispatchLayer** — Two-step delegation wrapper: calls WriteEscapedHexRecord (0x005117C8) with (a1, a2), then calls CallbackDispatch (0x00511887) with (a1, &stack_buffer) and returns the produced function pointer; the 80-byte stack buffer is used only as an output area.
- `0x00511B5C` **MediaSurfaceContext** — Guarded dispatch: when bit 0x40 of the flag byte at this+0x5C is clear, recalculates the audio buffer size via AudioBufferSizeCalc (0x0051868C); always dispatches PacketFieldEncoding (0x005124DE) with (a1, a2) and returns its result.
- `0x00511F23` **MediaSurfaceContext** — Repeated element dispatch: queries the iteration count via FlagBasedSessionModeSelector (0x0051234D), copies the element count from this+0xBC to this+0xC0, and when the selector returns a positive count runs a nested loop calling sub_511B7C(a1, *v5++, 0) over the a2 pointer array; returns the last sub_511B7C result or the selector result when the loops do not run.
- `0x0051212E` **MediaDescriptorState** — Null-guarded field read: returns the dword at *(a2+12) when both a1 and a2 are non-null, otherwise 0; a1 is only tested for non-null. In the caller the value becomes the row stride of a media-surface context.
- `0x00512144` **MediaDescriptorState** — Guard-conditional byte-field reader: returns the unsigned byte at a2+29 when both object pointers a1 and a2 are non-null, otherwise 0; no side effects.
- `0x0051215A` **MediaDescriptorState** — Flag-guarded float-to-double reader: returns 0 unless a1, a2, a3 are non-null and bit 0 of the dword at a2+8 is set; on success writes the float at a2+40 into the caller's double *a3 and returns 1.
- `0x00512183` **MediaDescriptorState** — Flag-guarded byte-field reader with constant success code: returns 0 when a1, a2, or a3 is null or bit 0x800 of the dword at a2+8 is clear; on success writes the unsigned byte at a2+44 into *a3 and returns the constant 2048.
- `0x005121AE` **PngImageValidation** — PNG width-overflow validation: reads width/height and color-description bytes from source struct a2 into output pointers, computes a bytes-per-row factor from the color-type byte, and when the width would overflow 0x7FFFFFFF / ((factor * bitDepth + 7) >> 3) dispatches the aWidthTooLargeF error string via CallbackDispatch (0x00511887); always returns 1 after validation, or 0 when any of a1..a6 is null.
- `0x0051227F` **MediaDescriptorState** — Guard-gated field reader: validates a1, the state pointer a2, enable bit 0x08 of the byte at a2+8, and output pointer a3, then copies the dword at a2+16 into *a3 and the 16-bit field at a2+20 into *a4, returning 8 on success or 0 when any guard fails.
- `0x005122B2` **MediaDescriptorState** — Format-gated media descriptor query: requires a1, a2, and enable bit 0x10 of the byte at a2+8, then branches on the format discriminator byte at a2+25; format 3 exposes the dword at a2+48 into *a3 and sets result 16, other formats zero *a3; both branches write the descriptor pointer a2+52 into *a5; when a4 is present its word at a2+22 is written and the 0x10 bit is OR-ed into the returned result.
- `0x00512319` **MediaSurfaceContext** — Unconditionally ORs bit 0 (0x1) into the flags DWORD at this+0x60 via read-modify-write and returns the this pointer; called by sub_50210E (0x0050210E).
- `0x00512322` **MediaSurfaceContext** — Sets bit 0x10 on the flags DWORD at this+0x60 when the animation-state byte at this+0x117 equals 16; returns the object pointer a1 unchanged.
- `0x00512334` **MediaSurfaceContext** — When the state byte at this+0x117 is below 8, ORs bit 4 (value 4) into the flags DWORD at this+0x60 and writes 8 to the state byte at this+0x118; always returns the input a1.
- `0x00512366` **MediaSurfaceContext** — State-flags setter: sets bit 7 of the flags byte at this+0x61, stores the byte parameter a2 as a WORD at this+0x11E, toggles bit 7 of the flags byte at this+0x5C by the boolean a3, and derives the output state byte at this+0x11B (4 when the state byte at 0x116 equals 2; 2 when it equals 0 and the state byte at 0x117 is >= 8); returns the object pointer.
- `0x005123B3` **PixelFormatByteSwapper** — Conditional adjacent-byte-pair swap: when the enable byte at this+0x9 equals 16 and the product of the dword count at this+0x0 and the stride byte at this+0xA is non-zero, swaps each adjacent byte pair of a2 over count*stride iterations advancing two bytes at a time.
- `0x005123E0` **PixelFormatByteSwapper** — Conditional pixel byte swap gated on bit 1 (mask 2) of the format flags byte at this+0x8: at 8bpp swaps bytes [0] and [2] of each group with stride 3 (flags 2) or 4 (flags 6); at 16bpp swaps bytes [0]<->[4] and [1]<->[5] with stride 6 (flags 2) or 8 (flags 6); the iteration count is the element count at this+0x0.
- `0x005124D5` **MediaSurfaceContext** — Sets bit 4 (mask 0x10) on the flags byte at this+0x61 and returns the object pointer unchanged; unconditional bit-set called by sub_50210E (0x0050210E).
- `0x005124DE` **MediaSurfaceContext** — Packet-format encoder: rewrites the output packet's encoding byte (a2+25) and bit depth byte (a2+24) from session flag bits at this+0x60/0x61 and configuration words at this+0x10A/0x174, copies the camera-rotation DWORD at this+0x130 into the packet when the video flag is set, computes the per-sample stride (a2+29) and bytes-per-sample product (a2+30), and stores the encoded size (a2+12), which it returns.

## Proposed classes

### MathVectorHelpers

Stateless vector/quaternion math helpers that produce a float[4] output buffer: a plane-from-triangle constructor and a quaternion normalizer with a unit-length fast path, a scale path, and a zero path.

Methods: `0x0050E585`, `0x0050ED19`

- `this+0x00000000` `float v0` (write, GUESS)
- `this+0x00000004` `float v1` (write, GUESS)
- `this+0x00000008` `float v2` (write, GUESS)
- `this+0x0000000C` `float v3` (write, GUESS)

### PlatformCapabilityProbe

Static platform capability queries: Direct3D registry value lookup under HKLM\Software\Microsoft\Direct3D, a cpuid leaf-1 EDX-bit-23 probe, and MMX detection that honors a 'DisableMMX' registry override and caches the enabled state in the global dword_5D7994.

Methods: `0x0050FBFC`, `0x0050FC58`, `0x0050FC7D`


### GenericDispatchThunks

Thin dispatch and vtable thunks with no computation of their own: a sequential two-call thunk, a single-argument forwarding thunk, and a vtable-entry dispatch that routes through the object's vtable slot +0xC.

Methods: `0x0050EDD2`, `0x0050F6F2`, `0x00511686`

- `this+0x00000000` `void** vtablePtr` (read, GUESS)
- `obj+0x0000000C` `void* dispatchedVtableEntry` (read, GUESS)

### StateMachineDispatchController

Owns a state-machine dispatch wrapper that reads its own state (this+0x10), writes opcodes into a vtable-backed target object, delegates to an inner state-machine dispatch (0x0050F86A), and handles the extended result-2 completion path.

Methods: `0x0050F9AB`

- `this+0x00000000` `void** stateMachineVtable` (read, GUESS)
- `this+0x00000010` `int state` (read, GUESS)

### CommandDispatchTarget

The vtable-backed object that receives state-machine dispatch writes: an opcode is stored in its code slot (+0x14), an argument in its argument slot (+0x18), and it is invoked through its vtable at +0. Only inferred from StateMachineDispatch_f9ab's writes; the class identity behind the target vtable is unknown.

Methods: 

- `obj+0x00000000` `void** vtable` (read, GUESS)
- `obj+0x00000014` `int opcodeSlot` (write, GUESS)
- `obj+0x00000018` `int argumentSlot` (write, GUESS)

### StreamMediaDecoder

Decodes packed image-frame data from a refillable byte stream: parses an 8-byte big-endian header, allocates an 84-byte-per-element buffer, decodes count 3-byte elements, and publishes header/element status codes and color vectors through the owning object's vtable.

Methods: `0x00510012`


### CallbackDispatchLayer

Callback and serialization helpers: an optional per-object callback slot (this+0x44) dispatched with (receiver, argument), a two-step delegation wrapper over that dispatch, and an escaped-hex text serializer used as a shared record-formatting step.

Methods: `0x005117C8`, `0x00511887`, `0x005118C1`

- `this+0x00000044` `void* callbackFn` (read, GUESS)

### MediaSurfaceContext

Session/media-surface context manipulated by the InitializeMediaSurfaceFromStream helper cluster (shared caller 0x0050210E): format/encoding flag words (this+0x60/0x61), driver/animation state bytes (this+0x116..0x11E), and packet-size/rotation configuration used by the packet-format encoder. Common ownership of the this-based offsets is inferred from the shared caller, not proven.

Methods: `0x00511B5C`, `0x00511F23`, `0x00512319`, `0x00512322`, `0x00512334`, `0x00512366`, `0x005124D5`, `0x005124DE`

- `this+0x0000005C` `unsigned char flagsByte5C` (read_write, GUESS)
- `this+0x00000060` `unsigned int flagsDword60` (read_write, GUESS)
- `this+0x00000061` `unsigned char flagsByte61` (read_write, GUESS)
- `this+0x000000BC` `unsigned int elementCount` (read, GUESS)
- `this+0x000000C0` `unsigned int elementCountCopy` (write, GUESS)
- `this+0x0000010A` `unsigned short encodingConfigWord` (read, GUESS)
- `this+0x00000116` `unsigned char stateByte116` (read, GUESS)
- `this+0x00000117` `unsigned char stateByte117` (read, GUESS)
- `this+0x00000118` `unsigned char driverStateByte118` (write, GUESS)
- `this+0x0000011B` `unsigned char outputStateByte11B` (write, GUESS)
- `this+0x0000011E` `unsigned short paramWord11E` (write, GUESS)
- `this+0x00000130` `unsigned int cameraRotationDword130` (read, GUESS)
- `this+0x00000174` `unsigned int sizeConfigDword174` (read, GUESS)

### MediaDescriptorState

Guard-gated descriptor field accessors over an a2 state/descriptor object: every accessor validates an enable pointer, the state pointer, a flag bit in the state object (bits 0x01/0x08/0x10/0x800 at +8), and output pointers, then copies one or more typed fields and returns a fixed success code (1, 8, 16, or 2048). Equal offsets recur across accessors but common ownership is inferred only from the shared caller 0x0050210E.

Methods: `0x0051212E`, `0x00512144`, `0x0051215A`, `0x00512183`, `0x0051227F`, `0x005122B2`


### PngImageValidation

Validates PNG-style image dimensions read from a source struct: computes a bytes-per-row factor from the color-type byte and guards against row-size overflow, dispatching the 'Width too large for libpng...' message through the callback layer when the width is too large.

Methods: `0x005121AE`


### PixelFormatByteSwapper

Conditional byte-pair swaps over pixel/audio buffers driven by a format descriptor (element count +0x0, flags +0x8, bits-per-pixel +0x9, stride +0xA): an adjacent-pair endianness-style swap and a channel-geometry pixel swap gated on flag bit 1. Caller sub_51389E owns the descriptor layout.

Methods: `0x005123B3`, `0x005123E0`

- `this+0x00000000` `unsigned int elementCount` (read, GUESS)
- `this+0x00000008` `unsigned char formatFlags` (read, GUESS)
- `this+0x00000009` `unsigned char bitsPerPixel` (read, GUESS)
- `this+0x0000000A` `unsigned char strideByte` (read, GUESS)

## Compatibility contracts

- **Direct3DRegistryQuerySemantics** — A replacement must open HKLM\Software\Microsoft\Direct3D with RegOpenKeyA, query a caller-supplied value name with RegQueryValueExA, close the key, and return TRUE only when both the open and the query report ERROR_SUCCESS and the stored registry type equals the expected type argument; otherwise FALSE.
- **DisableMMXRegistryOverride** — When the value 'DisableMMX' is present as REG_DWORD (type 4) with non-zero data under HKLM\Software\Microsoft\Direct3D, MMX must be reported disabled and the cached state dword_5D7994 forced to 0; otherwise, on first call, the cpuid probe result is cached (1 enabled / 0 disabled) and the EMMS instruction is emitted when MMX is available.
- **CpuidLeaf1EdxBit23Probe** — The capability probe must execute cpuid with EAX=1 and expose whether EDX bit 23 (mask 0x800000) is set as a boolean; the specific feature named by that bit is not established.
- **CommandDispatchObjectProtocol** — The state-machine dispatch writes an opcode (18 on the pre-dispatch path, 50 on the extended path) into the target object's code slot at +0x14, its argument at +0x18, and dispatches through the target vtable at +0; a replacement that drives or consumes these objects must preserve that layout, the state bypass values 200/201, and the extended result-2 path (opcode 50 plus VirtualDispatchConditionalValue).
- **PacketFieldEncodingSemantics** — The output packet's encoding byte (values 2, 3, and 6), bit-depth byte (8 or 16, with downgrade rules), per-sample stride byte, and total size DWORD must be computed from the session flag bytes at this+0x60/0x61 and the configuration words at this+0x10A/0x174 as documented; the camera-rotation DWORD at this+0x130 is copied into the packet when the video flag is set. A replacement consumer of these packets must match the encoding and sizing rules.
- **PngWidthOverflowGuard** — PNG width validation must compute the bytes-per-row factor from the color-type byte and reject a width exceeding 0x7FFFFFFF / ((factor * bitDepth + 7) >> 3) by dispatching the 'Width too large for libpng to process image data.' message through the callback dispatch, while still returning 1 after validation; a null among the first six arguments returns 0.
- **GuardedDescriptorAccessorReturnCodes** — Guard-gated descriptor accessors return distinct fixed success codes (1, 8, 16, and 2048) that callers branch on; a replacement must preserve the exact codes, the null guards (enable pointer, state object, output pointers), and the flag-bit gates (bits 0x01/0x08/0x10/0x800 of the state object), because callers distinguish them.

## Unresolved

- All owners except CallbackDispatchLayer (0x005118C1) and PngImageValidation (0x005121AE) are UNKNOWN in the packet; the GUESS classes are per-function groupings by shared caller and shared field base, not attested source layout.
- MediaSurfaceContext groups this-based flag/state helpers that share offsets 0x60/0x61/0x117 but are linked only by the shared caller 0x0050210E; common ownership is inferred, not proven.
- MediaDescriptorState groups a2-based accessors whose equal offsets (notably the flag word at +8 and the 0x10 return bit) recur across functions; whether they share one struct layout is unproven.
- Which of flt_59E43C (0x0059E43C) and flt_5ADE40 (0x005ADE40) backs the 1.0 literal and which backs 1.1754944e-38 in QuaternionNormalize is DERIVED and unproven.
- FloatRangeCheck (0x0050C042) applies epsilon literals defined in that function, which is outside this packet.
- sub_516959 (forwarded by 0x0050F6F2) has no callee evidence ref; its destructor/teardown role is inferred only from the canonical name and the caller ImageTextureDecompressor (0x00501722).
- ThunkTo (0x0050C2B3) is called between the normal writes and the offset write in PlaneFromTriangle; it may be a null/nop thunk or may mutate registers the compiler keeps in live values, and its effect is unknown.
- The stream decoder (0x00510012) refill callback (v3[3]), the vtable handlers at (*(a2)) slot 0 and +4, and the allocator vtable are indirect with no static addresses; the status codes 99/57/31/9/100 are opaque protocol values. The packet summary names its caller CommandDispatchStateMachine (0x0051126A), but that address carries no evidence ref in the packet.
- The 84-byte (21-dword) element record stride in ImageFormatStreamDecoder and the 3-bytes-per-element stream layout are derived from loop arithmetic only; only element indices 0..4 are written and the underlying pixel format is unconfirmed.
- The targets and purposes of TwoThunkWrapper's two thunks (ThunkViaFunctionPointer 0x0050DD3A and the indirect call through function pointer 005d7860) and the meaning of the forwarded float triple are unresolved.
- The specific CPU feature named by cpuid EDX bit 23 (mask 0x800000) is not identified in the packet.
- The registry import globals (0x0059E004 RegQueryValueExA, 0x0059E008 RegCloseKey, 0x0059E044 RegOpenKeyA) and the subkey/value strings at 0x005ADE4C/0x005ADE68 ('Software\Microsoft\Direct3D', 'DisableMMX') are interpreted from raw-source usage; the identity of the owning rendering object that caches MMX state is unknown.
- WriteEscapedHexRecord's buffer base (v2/ecx uninitialized in decompiler output), the meaning of the four bytes at a1+268, and the layout of the 0x40-byte payload copied from a2 are unknown; byte_5AF210 is assumed to be a hex-digit table but its contents are not evidenced.
- The callback slot at this+0x44 has no registration site or owner type in evidence; the exact call convention of the stored callback (receiver as argument vs. implicit this) is unresolved.
- PixelFormatByteSwapper's descriptor layout (count 0x0, flags 0x8, bpp 0x9, stride 0xA) and the true purpose of the 16bpp byte-pair swap (0<->4, 1<->5) are unknown; the RGB<->BGR channel-swap reading is DERIVED from the swap geometry, and caller sub_51389E owns the semantics.
- The media-surface initialization function 0x0050210E (the shared caller of the MediaSurfaceContext and MediaDescriptorState clusters) is outside this packet, so the calling context for those helpers is caller-side and unverified.
- State-machine semantics of the bypass states 200/201 and of opcodes 18 and 50 written to the command target are not in the packet; the class identity behind the target vtable is unknown.
- The 0x40-size flag on this+0x5C and the audio-buffer-size meaning of AudioBufferSizeCalc (0x0051868C) rest on corpus names; their runtime behavior is not verified in this packet.
- Whether the returned normal from PlaneFromTriangle is normalized or unit-scaled is not shown by that function; normalization, if any, must occur elsewhere.
