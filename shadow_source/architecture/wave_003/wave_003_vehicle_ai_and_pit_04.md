# VehicleAIAndPitSubsystem

Scope: `vehicle_ai_and_pit`  
Trust: `DERIVED`

DERIVED proposal for the vehicle_ai_and_pit scope from 16 validated functions. The core is the pit-stop timer state machine 0x004D2E50 (GUESS class PitTimer) gated on the session-phase globals dword_7C56A4 / dword_7C56A8 with the elapsed-time clock dbl_8AFEA0, writing its phase through sub_42D140(&dword_7C569C, n) and advancing a result state at this+0xF4; it dispatches through the jump table at 0x004D3490 and consumes the render target dword_7CD204 and string table byte_5EC4C0/byte_5EC4CC. 0x004ED250 (GUESS class RepairService) is a part-index switch (wheels/wings/bodywork) that writes service state this[0x3D60] and a reason-code slot at *this+0x4068 before forwarding to sub_41AFD0. 0x004D5F70 (GUESS class TireSlipCurve) parses a slip-curve data file and builds a normalized cubic Hermite spline stored at this+0x14 with 32 bytes per segment. 0x004DDAD0 (DERIVED class PitCrewTexturePathsBuilder) assembles the 9 pit-crew texture paths and resolves them via TextureAdjuster. 0x004DB170 (GUESS class DebugTelemetryOverlay) is a flag-gated HUD bar renderer. 0x00500210 (GUESS class AudioPlaybackChannel) interpolates packed color/Euler channels. The dispatch thunks 0x0050C07C / 0x0050C5B0 / 0x0050D84A (GUESS class VersionedDispatchThunk) share the sub_50FEA7(1u) preamble over a version-adaptive function table. 0x0057EE80 and 0x0057DBB0 (GUESS classes TimedWaitQueue / NetworkTimerPacketDispatcher) handle the mutex-guarded network message path, and 0x00598BBC / 0x00599E71 (GUESS class StreambufDerived) are the SEH-framed construct/destruct pair of a streambuf-derived object with vtable states 0x005B9C04/0x005B9BCC/0x005B9C68/0x005B9CA0. All class owners except PitCrewTexturePathsBuilder are GUESS because the packet keeps every function owner UNKNOWN.

## Function roles

- `0x004D2E50` **PitTimer** — Tick-driven pit-stop timer state machine: gated on the session-phase global dword_7C56A4; phases 1..6 run a message-chain update (TimeBasedMessageChain on this+0xB4) plus a substate dispatch on dword_7C56A8, while phase 7 runs a switch on dword_7C56A8 (jump table jpt_4D2E8B at 0x004D3490) with cases 0..5 covering countdown display, pit-lane open/close transitions, time-remaining text rendering and session-phase advancement. Phase changes are written through sub_42D140(&dword_7C569C, n) and the result state is advanced via ArithmeticComparison_0ec0 on this+0xF4; countdown fields this+0xB0/this+0xB4 are read against the global elapsed-time dbl_8AFEA0 and rewritten (dbl_8AFE98 path) on phase transitions; this+0xF4 carries the result state returned to the caller 0x004D4580.
- `0x004D5F70` **TireSlipCurve** — Parses a tire slip-curve definition (header fields Name and Step, then a Data section of slip/force points), builds a cubic Hermite spline through the points with per-segment coefficients stored in an allocated array at this+0x14, finds the peak grip slip angle (stored as a double at this+0x8), and normalizes every coefficient by the peak force. Rejects a non-positive step, fewer than three points, and a non-zero first data point with debug logging; invoked by TireBrandFileParser (0x004D7150).
- `0x004DB170` **DebugTelemetryOverlay** — Gated debug HUD renderer: draws a path/name label string and a 41-segment color-coded bar indicator (white versus red on a threshold). Gated by the flt_5EA4E8 telemetry-enable flag; the bar block additionally requires the packed flag at dword_8AB6EC and flt_5EA4E8 == 1.0. The ABI lead 'Steering_Ackermann_Computation' (LEGACY) does not match the body, which performs no steering-geometry math.
- `0x004DDAD0` **PitCrewTexturePathsBuilder** — Builds full texture file paths for the 9 pit-crew/vehicle texture types (car body, driver, arms, wing, helmet, pit body, pit helmet, lollipop, refueler) by combining a base directory from this+0, team and track config strings, and a track-name-matched linked-list node, then resolves each path with TextureAdjuster. For texture index 0 it may re-derive the selected path from the matched candidate; frees the temporary buffers and the lookup handle before returning. Called by 0x004DDF70 and 0x004E2A60.
- `0x004ED250` **RepairService** — State-switch dispatcher for the repair/pit service subsystem, selected on the detached part index a2 (0-13). Cases 0-3 (wheels) set the reason-code slot at *this+0x4068 to 6 when it is still zero (first-write-wins), run SubslotCleanup(this+1764, a2), write service state this[0x3D60]=2, and - when this[0x32BC] is zero - call WheelCollisionContactFlagSetter(&dbl_7C7428, a2) and forward to sub_41AFD0(*this, a2). Cases 4-5 (front/rear wing) release the per-part resource record, call StateTransition(this+3248, 1), set this[0x3D60]=1 when it is zero, copy this[0x3A80] into this[0x3A70], then run TireBrushModelForceSolver(this, 0) and sub_41AFD0(*this, a2). Cases 6-13 (bodywork) release the record at &this[17*a2 + 750] and fall through to sub_41AFD0(*this, a2).
- `0x00500210` **AudioPlaybackChannel** — Audio sample playback update with pitch modulation and stereo panning: reads a packed control word at this+0x1B8; when its 6-bit mode field is zero it falls back to AudioSampleCrossFadeInterpolation. Otherwise it encodes a progress event via ProgressBarEventEncode, computes a cross-fade blend factor between this+0xC and this+0x1BC driven by the float view of a2, interpolates packed RGB color channels (fields 0x12..0x1C6) and Euler short channels (fields 0x1B..0x1CF), writes the converted RGB through FloatToRGBColorConversion into output+10, clamps and quantizes the three Euler channels into int16 at output+19/+21/+23, copies a short from this+0x1C0 to output+8, and returns 1.
- `0x00502BEA` **ZeroPair** — Initializes a two-field structure by zeroing consecutive DWORDs: this[1] (offset 0x4) then *this (offset 0x0). Returns the this pointer unchanged.
- `0x0050C07C` **VersionedDispatchThunk** — AI-subsystem dispatch thunk: ensures the shared version-adaptive function table is initialized by calling sub_50FEA7(1u), then tail-calls the function pointer stored in the global dispatch slot off_5D780C, forwarding all six arguments (a1..a6) unchanged and returning its result. sub_50FEA7's own body lazily installs an OS-version-dependent table variant on first call, so this wrapper routes the AI entry point through that table's selected implementation.
- `0x0050C5B0` **VersionedDispatchThunk** — Dispatch pair (cdecl, no arguments) on an AI-related path: first calls sub_50FEA7 (0x0050FEA7) with constant argument 1, then calls the function pointer stored at global off_5D77F0 (0x005D77F0) and returns its result.
- `0x0050D84A` **VersionedDispatchThunk** — Dispatch pair (cdecl, no arguments) on an AI-related path: first calls sub_50FEA7 (0x0050FEA7) with constant argument 1, then calls the function pointer stored at global off_5D7860 (0x005D7860) and returns its result.
- `0x00545A10` **UILinkedListCleanup** — Walks a singly linked list starting at head this[87] (byte 0x15C) and calls sub_560C10(this, 0) once per node, advancing through the next-node pointer at node offset +52 (byte 0x34). The loop terminates when the cursor reaches null. Always returns 0. Called by VertexBufferResourceAllocation (00543FA0).
- `0x00553FA0` **StateParameterSetter** — Stores the second argument a2 into the receiver's first dword field (byte offset 0), then chains through sub_553FC0(0) and finally StateParameterSetterWithVirtualDeviceNotify(0), returning the latter's result; the intermediate sub_553FC0 return value is discarded. Called by AudioBufferFormatSetup (00541120), sub_5550E0 and sub_55CF50.
- `0x0057DBB0` **NetworkTimerPacketDispatcher** — Dispatches a timer-driven network packet construction chain: resolves a context object through a vtable getter at vtable+0x58, performs a fixed-parameter system call sub_586800(0, 11, 0, 2, -1), reads a mutex-guarded timer value, wraps it as a 4-byte payload, builds a network packet from the getter result and the a2 parameter, then thread-safely executes the getter result under a mutex and returns its result. Called by sub_57E0A0.
- `0x0057EE80` **TimedWaitQueue** — Thread-safe timed-wait dequeue from a mutex-protected linked list, called from sub_57D6C0. Waits on the mutex at this+0xAD8 for dwMilliseconds; on timeout (258) or failure (-1) it returns 0 without releasing. Otherwise it walks a linked list starting from the head at this+0xAC8 using the cursor at this+0xAD0, comparing each node's data pointer against a2 via NetworkMessageEventComparisonWithShortMasking. On a match it stores ReadFieldAtOffset0x14 of the node data into *a3 and returns 1; on exhaustion it returns 0. Always releases the mutex when it was acquired.
- `0x00598BBC` **StreambufDerived** — Multi-phase constructor of a streambuf-derived object under an SEH frame: registers the SEH handler (descriptor loc_59D2D2), stores the object pointer in the frame slot, acquires a locale reference on sub-object this+13, installs the std::streambuf vtable (0x005B9C04), runs SelfReferentialPointerRingInit, acquires a second locale reference on this+19, reads the buffer pointer from the caller frame at +0x8, advances the vtable to off_5B9BCC, and finishes by calling ObjectInitializationWithBufferBoundsSetup(buffer, 0). Returns the object pointer.
- `0x00599E71` **StreambufDerived** — Teardown of a streambuf-derived object under an SEH frame: registers the SEH handler (code at loc_59D44F), installs the derived vtable off_5B9C68, conditionally runs a cleanup callback when the byte at this+72 is non-zero, then decrements and conditionally frees the buffer pointer at this[17] (this+68) via ReferenceCountDecrementWithConditionalFree and FreeWrapper_7bcf. Performs virtual teardown on sub-objects this+19 and this+13 via NullCheckWithVirtualDispatch, resetting the vtable to the std::basic_streambuf vftable (0x005B9CA0) in between.

## Proposed classes

### PitTimer

Pit-stop timer state machine: countdown fields, a one-shot action flag, the closing-window duration, the result state returned to the caller, and an interrupt byte, driven by the global session-phase/substate globals and the elapsed-time clock.

Methods: `0x004D2E50`

- `this+0x000000B0` `DOUBLE countdownStartTime` (read, GUESS)
- `this+0x000000B4` `DOUBLE countdownDuration` (read_write, GUESS)
- `this+0x000000C2` `BYTE oneShotActionFlag` (read_write, GUESS)
- `this+0x000000D8` `DOUBLE closingWindowDuration` (read, GUESS)
- `this+0x000000F4` `DWORD resultState` (read_write, GUESS)
- `this+0x00000104` `BYTE interruptFlagByte` (read, GUESS)

### TireSlipCurve

Parsed, splined tire slip/force curve: the peak slip angle and peak force doubles, the data-point count, the allocated per-segment cubic coefficient array, and the normalized curve state used by the tire physics.

Methods: `0x004D5F70`

- `this+0x00000008` `DOUBLE peakSlipAngle` (write, GUESS)
- `this+0x0000000C` `DOUBLE peakForce` (write, GUESS)
- `this+0x00000010` `DWORD pointCount` (write, GUESS)
- `this+0x00000014` `void* splineCoefficientArray` (write, GUESS)
- `*(this+0x14)+0x00000000` `DOUBLE segmentCubicCoefficientA` (write, GUESS)
- `*(this+0x14)+0x00000008` `DOUBLE segmentCubicCoefficientB` (write, GUESS)
- `*(this+0x14)+0x00000010` `DOUBLE segmentCubicCoefficientC` (write, GUESS)
- `*(this+0x14)+0x00000018` `DOUBLE segmentCubicCoefficientD` (write, GUESS)

### DebugTelemetryOverlay

Flag-gated debug HUD overlay: holds the display-name string for the label, while the enable gate and bar threshold live in globals (flt_5EA4E8, dword_8AB6EC).

Methods: `0x004DB170`

- `this+0x00000010` `char* displayNameString` (read, GUESS)

### PitCrewTexturePathsBuilder

Builds the 9 pit-crew/vehicle texture file paths from a base directory string, team/track config strings and a track-name-matched linked-list node, resolving each candidate through TextureAdjuster.

Methods: `0x004DDAD0`

- `this+0x00000000` `char* basePathString` (read, DERIVED)

### RepairService

Repair/pit service part dispatch: per-part resource records, the reason-code slot, service state, the contact flag gate, and the forwarded sub_41AFD0 service action selected on the detached part index.

Methods: `0x004ED250`

- `this+0x00000000` `void* objPtr` (read, GUESS)
- `obj+0x00004068` `DWORD reasonCodeSlot` (write, GUESS)
- `this+0x000032BC` `DWORD contactFlagGate` (read, GUESS)
- `this+0x00003A70` `DWORD serviceStateCopyTarget` (write, GUESS)
- `this+0x00003A80` `DWORD serviceStateSource` (read, GUESS)
- `this+0x00003D60` `DWORD serviceState` (write, GUESS)

### AudioPlaybackChannel

Audio sample playback channel: packed control word, cross-fade start/end floats, current and target packed color words and Euler short channels, and the verbatim short copied to the output event object.

Methods: `0x00500210`

- `this+0x0000000C` `FLOAT crossFadeStart` (read, GUESS)
- `this+0x00000012` `SHORT currentRedHigh` (read, GUESS)
- `this+0x00000014` `DWORD currentPackedColor` (read, GUESS)
- `this+0x00000016` `DWORD currentGreenWord` (read, GUESS)
- `this+0x0000001A` `BYTE currentRedLow` (read, GUESS)
- `this+0x0000001B` `SHORT currentEulerPitch` (read, GUESS)
- `this+0x0000001D` `SHORT currentEulerYaw` (read, GUESS)
- `this+0x0000001F` `SHORT currentEulerRoll` (read, GUESS)
- `this+0x000001B8` `DWORD packedControlWord` (read, GUESS)
- `this+0x000001BC` `FLOAT crossFadeEnd` (read, GUESS)
- `this+0x000001C0` `SHORT verbatimOutputShort` (read, GUESS)
- `this+0x000001C2` `SHORT targetRedHigh` (read, GUESS)
- `this+0x000001C4` `DWORD targetPackedColor` (read, GUESS)
- `this+0x000001C6` `DWORD targetGreenWord` (read, GUESS)
- `this+0x000001CA` `BYTE targetRedLow` (read, GUESS)
- `this+0x000001CB` `SHORT targetEulerPitch` (read, GUESS)
- `this+0x000001CD` `SHORT targetEulerYaw` (read, GUESS)
- `this+0x000001CF` `SHORT targetEulerRoll` (read, GUESS)

### ZeroPair

Two-field init structure: the constructor zeroes both consecutive DWORD fields and returns the object pointer.

Methods: `0x00502BEA`

- `this+0x00000000` `DWORD firstDword` (write, GUESS)
- `this+0x00000004` `DWORD secondDword` (write, GUESS)

### VersionedDispatchThunk

Version-adaptive dispatch thunks on the AI path: each ensures the shared function table is initialized via sub_50FEA7(1u) and then tail-calls the selected implementation through a global dispatch slot.

Methods: `0x0050C07C`, `0x0050C5B0`, `0x0050D84A`


### UILinkedListCleanup

Singly-linked-list cleanup iterator: walks the list from the head field and invokes a per-node callback until the cursor reaches null.

Methods: `0x00545A10`

- `this+0x0000015C` `void* listHead` (read, GUESS)
- `*(this+0x190)+0x00000034` `void* nodeNextLink` (read, GUESS)

### StateParameterSetter

State-parameter setter chain: stores the parameter into the first dword field and chains two fixed-argument state callbacks.

Methods: `0x00553FA0`

- `this+0x00000000` `DWORD storedParameter` (write, GUESS)

### NetworkTimerPacketDispatcher

Timer-driven network packet dispatch: resolves the dispatch target through a vtable getter slot, reads a mutex-guarded timer, builds and runs a network packet chain thread-safely.

Methods: `0x0057DBB0`

- `this+0x00000000` `void** vtablePtr` (read, GUESS)
- `obj+0x00000058` `void* vtableGetterSlot` (read, GUESS)

### TimedWaitQueue

Thread-safe timed-wait dequeue: mutex handle, list head and persistent cursor fields, with a short-masking node comparison and a node-data field read into the caller output.

Methods: `0x0057EE80`

- `this+0x00000AC8` `void* listHead` (read, GUESS)
- `this+0x00000AD0` `void* listCursor` (read_write, GUESS)
- `this+0x00000AD8` `void* mutexHandle` (read, GUESS)
- `*(this+0xAC8)+0x00000000` `void* headNodeData` (read, GUESS)
- `*(this+0xAD0)+0x00000004` `void* nextNodeLink` (read, GUESS)
- `*(*(this+0xAD0)+0x4)+0x00000000` `void* nextNodeData` (read, GUESS)

### StreambufDerived

SEH-framed streambuf-derived object lifecycle: constructor installs locale references and the two vtable states, destructor performs conditional cleanup, buffer release, and virtual teardown of the two sub-objects.

Methods: `0x00598BBC`, `0x00599E71`

- `this+0x00000008` `void* callerBuffer` (read, GUESS)

## Compatibility contracts

- **PitTimerRuntimeState** — A replacement executable must preserve the globals gating and driving the pit-stop timer: session phase dword_7C56A4 (phases 1..6 simple path, 7 = full switch dispatch), substate dword_7C56A8, the shared state word dword_7C569C written by sub_42D140, the elapsed-time clock dbl_8AFEA0 and cumulative time dbl_8AFE98, the render target dword_7CD204, the pit-close/extension flags dword_7CED8C and dword_7CEE88, the close-window base dword_7CEC30 and text-enable byte_7CEC78, the time-divisor dword_7CEBF4, the session-check global dword_7CD25C, the player identity dword_7C54E8, the vehicle-slot array dword_7C54F0 with count dword_5C329C, and the string table byte_5EC4C0/byte_5EC4CC.
- **TireSlipCurveDataContract** — The tire slip-curve object stores the peak slip angle as a double at this+0x8, the peak force at this+0xC, the data-point count at this+0x10, and a pointer to an allocated cubic coefficient array at this+0x14 with 32 bytes (4 doubles at offsets 0x0/0x8/0x10/0x18) per segment, normalized so the peak grip force maps to unit magnitude; the header/data file layout is Name, Step, then a Data section of slip/force points.
- **RepairServiceStateContract** — The repair/service object exposes a reason-code slot at *this+0x4068 (first-write-wins value 6 for wheel repair), a contact flag gate at this[0x32BC], a copied service-state pair this[0x3A70] <- this[0x3A80], and the service state this[0x3D60] (1 = wing, 2 = wheel); the per-part resource records for front/rear wing are at this+0xCC8 / this+0xD0C and bodywork records at &this[17*a2 + 750], all ultimately forwarded through sub_41AFD0(*this, a2).
- **AudioPlaybackChannelLayout** — The audio playback channel packs a control word at this+0x1B8 whose 6-bit mode field (bits 18..23) selects cross-fade fallback versus full playback; current/target state spans this+0xC/this+0x1BC (blend), packed color words at this+0x14/this+0x1C4 with channel shorts at 0x12..0x1CA, and Euler short channels at 0x1B..0x1CF; the output event object receives RGB at +10, int16 Euler channels at +19/+21/+23 and a verbatim short at +8.
- **StreambufVtableContract** — The streambuf-derived object transitions through four vtable states: std::streambuf at 0x005B9C04 then off_5B9BCC during construction, off_5B9C68 at teardown entry, and the std::basic_streambuf vftable at 0x005B9CA0 after the sub-object teardowns; locale references are acquired on sub-objects this+13 and this+19 and the buffer pointer is released from this[17] (this+68) with reference-count decrement and free.
- **VersionedAIDispatchContract** — AI-related entry points route through a shared, lazily installed function table: sub_50FEA7(1u) initializes it on first call and the global dispatch slots off_5D780C (six-argument), off_5D77F0 (zero-argument) and off_5D7860 (zero-argument) hold the selected implementations.
- **DebugTelemetryGateContract** — The debug HUD overlay is enabled when the telemetry float flt_5EA4E8 is positive, and the 41-segment bar block additionally requires the packed flag at dword_8AB6EC plus flt_5EA4E8 == 1.0; the label/name is drawn from this+0x10 (or the byte_5EA438 default) through the string table byte_5EC4C0/byte_5EC4CC.
- **PitCrewTexturePathContract** — The pit-crew texture path builder combines the base directory (this+0, with byte_5EA438 fallback), a team-mass config key (aTeamMas at 0x005CD5D8), the TrackName config value (0x005C6984) and a track-name-matched linked-list node, then resolves 9 texture variants (indices 0..8) through TextureAdjuster, falling back to the wc-prefixed variant plus '.bmp' (0x005D4C0C); the variant strings live at 0x005D4C14..0x005D4CB8.
- **TimedWaitQueueContract** — The timed-wait dequeue object holds a mutex handle at this+0xAD8, a list head at this+0xAC8 and a persistent cursor at this+0xAD0; nodes link through offset +4 and carry a data pointer at +0 whose field at +0x14 is returned on a match, with wait results 258 (WAIT_TIMEOUT) and -1 (WAIT_FAILED) mapped to not-found.

## Unresolved

- Class owners are all GUESS except PitCrewTexturePathsBuilder (DERIVED in the packet): the packet keeps every function owner UNKNOWN (UnknownObject), so PitTimer, TireSlipCurve, DebugTelemetryOverlay, RepairService, AudioPlaybackChannel, ZeroPair, VersionedDispatchThunk, UILinkedListCleanup, StateParameterSetter, NetworkTimerPacketDispatcher, TimedWaitQueue and StreambufDerived are grouped on shared responsibility only.
- The read-only float/double constants (0x0059E420, 0x0059E430, 0x0059E43C, 0x0059E440, 0x0059E450, 0x0059E46C, 0x0059E478, 0x0059E714, 0x0059E718, 0x0059E71C, 0x0059E77C, 0x0059E780, 0x0059E7D8, 0x0059E7E0, 0x0059E800, 0x0059E808, 0x0059E80C, 0x0059E828, 0x0059E87C, 0x0059E880, 0x0059E8A0, 0x0059E8D8, 0x0059E968, 0x0059E99C, 0x0059EC10, 0x0059F118, 0x005ACEE4, 0x005ACEF8, 0x005ACEFC) and dword_5EB978 are flagged by the IDB as reads but never appear by name in the raw decompiled bodies; they are likely folded into float/double immediates (300.0, 240.0, 180.0, 120.0, 60.0, 15.0, 33.5, 0.5, 4.0, 3.0, 2.0, 1.0, 1/32768, 1/2048, 15.999, 2048.0) or data-layout constants, and are not grounded beyond deterministic packet evidence.
- The pit-crew texture path builder reads team/track config strings at this+972 (0x3CC), this+980 (0x3D4) and this+984 (0x3D8) that are absent from the packet's deterministic field table, so no field evidence references can be cited for them here.
- Packet-listed read globals 0x008AC368, 0x008AFE64 (BuildPitCrewTexturePaths), 0x005CCEF0 and byte_5EA438 reads in TireSlipCurve do not appear in the raw function texts; their roles are unknown.
- The exact semantics of the shared text globals dword_7CD204 (render target), byte_5EC4C0/byte_5EC4CC (string table + selection buffer) and sub_42D140(&dword_7C569C, n) are inferred from callee usage, not confirmed here.
- Callers named only in prose are absent from the packet's caller evidence list and therefore cannot be cited: sub_4D4580 call frequency (0x004D2E50), sub_57D6C0 (0x0057EE80), VertexBufferResourceAllocation 00543FA0 (0x00545A10), AudioBufferFormatSetup 00541120 / sub_5550E0 / sub_55CF50 (0x00553FA0).
- The base of the linked-list next-node pointer in 0x00545A10 is reported by the packet as *(this+0x190):0x00000034, which does not match the raw source where the next pointer is read from the current node i at offset +52; base discrepancy unresolved.
- The ABI lead 'Steering_Ackermann_Computation' on 0x004DB170 is LEGACY and does not match the rendered body; no steering-geometry operation is present.
- The Hermite basis layout (v85 pointer over the v59 double plus stride-5 offsets) and the internal semantics of sub_5677B0 are only partially recoverable from this packet.
- The resource-record offsets this+0xCC8 (front wing) and this+0xD0C (rear wing) lag the retire-test offsets *this+0xCD4 / *this+0xD18 by a consistent 0xC base gap that is noted but unexplained; the reason-code value 6 and service-state values 1/2 are DERIVED, not proven by this packet.
- The 6-bit audio mode field (v4>>18)&0x3F selects between the cross-fade fallback and the full playback path, but the packet gives no enum of the mode values; the short copied from this+0x1C0 to output+8 is unnamed and the output object layout a3 is only partially established.
- The indirect dispatch targets off_5D780C / off_5D77F0 / off_5D7860 resolve to implementations not identified by this packet; the callee entry callee:0x0050C07C is a self-loop artifact of the dispatch slot, not a genuine recursive call.
- The purpose of sub_586800's fixed arguments (0, 11, 0, 2, -1) and the meaning of the dword at v6 + 72 passed to NetworkPacketConstructor are unknown.
- The match parameter a2, the short-masking comparison, and the node-data field at +0x14 of TimedWaitQueueDequeue are not semantically established; the cursor this+0xAD0 persists between dequeues.
- The object layout of the streambuf-derived class is unknown: this+13/+19 locale sub-objects, the conditional cleanup callback, the second vtable state off_5B9BCC, and the offsets 0x34/0x44/0x48/0x4C named in the skeleton fill have no field evidence references in this packet.
- The owner of the TelemetryBar's threshold semantics (sub_4B9A10, the 0.025 segment scale) and the role of byte_5D4AEC as the '%c' character source are not established by this packet.
