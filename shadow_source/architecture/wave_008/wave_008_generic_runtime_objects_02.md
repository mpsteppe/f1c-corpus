# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

This packet is a grab-bag of 77 small runtime helpers. 62 are empty no-op stubs (nullsub/NullStub/EmptyFunction) that return void immediately; three return fixed constants (0x00454D96 returns 1; 0x004579B0, 0x0047AA70, 0x0048B024 return 0); one is a pass-through identity (0x00461CC3). A coherent byte-at-offset-94 accumulation pattern appears in four unrelated functions (0x0044F062, 0x004636E6, 0x0047E384, 0x00486EC8) whose object bases are not proven shared, so they are not merged. A small number of functions carry real behavior: the NetComm session-peer slot setter (0x0045E5D0, owner DERIVED from callers 0x0045D890/0x00460520), the path filename-extraction utility (0x004618D0, caller 0x00461610), two EntityVisibilityGridManager helpers (0x00464AE0 byte-range predicate and 0x00464F90 threshold-to-rank classifier, caller 0x00465460), the guarded string copy (0x004761A0, buffer at this+80), the single-call passthrough (0x00478E80, caller 0x004793EC, delegate FUN_00499b80), and three fixed-displacement offset accessors (0x00466B10, 0x0046B310, 0x0046B829). Two functions decompile to corrupted/empty bodies under flagged positive stack deltas (0x0047F006, 0x0046624E) and are treated as unknowable. The proposal deliberately keeps most owners as UnknownObject rather than inventing classes from bare offsets.

## Function roles

- `0x0044DC20` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044DC80` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044DCE0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044DD40` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044DDA0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044DE00` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044DE60` **UnknownObject** — Empty void stub with no operations; placeholder, patched-out target, or dead-code-removal residue.
- `0x0044DEC0` **UnknownObject** — Empty void stub with no operations; placeholder, patched-out target, or dead-code-removal residue.
- `0x0044DF20` **UnknownObject** — Empty void stub with no operations; placeholder, patched-out target, or dead-code-removal residue.
- `0x0044DF80` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044DFE0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E040` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E0A0` **UnknownObject** — Empty no-op stub (nullsub); likely a call-table or virtual-dispatch placeholder slot.
- `0x0044E100` **UnknownObject** — Empty no-op stub (nullsub); likely a call-table or virtual-dispatch placeholder slot.
- `0x0044E160` **UnknownObject** — Empty no-op stub (nullsub); likely a call-table or virtual-dispatch placeholder slot.
- `0x0044E1C0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E220` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E280` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E2E0` **UnknownObject** — Empty no-op stub (nullsub); likely a call-table or virtual-dispatch placeholder slot.
- `0x0044E340` **UnknownObject** — Empty no-op stub (nullsub); likely a call-table or virtual-dispatch placeholder slot.
- `0x0044E3A0` **UnknownObject** — Empty no-op stub (nullsub); likely a call-table or virtual-dispatch placeholder slot.
- `0x0044E400` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E460` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E4C0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E520` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E580` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E5E0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E640` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E6A0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E700` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E760` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E7C0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E820` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E880` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E8E0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E940` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044E9A0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044EA00` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044EA60` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044EAC0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044EB20` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044EB80` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044EBE0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044EC40` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044ECA0` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044ED00` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0044F062` **UnknownObject** — Byte accumulator over an unidentified object: adds byte argument a1 into the byte at offset 94 of the buffer pointed to by a2 and returns the constant -1; userpurge ABI is flagged for a positive stack adjustment, so the parameter layout is MEDIUM trust.
- `0x0044F6E6` **UnknownObject** — Empty __stdcall stub taking one unused int argument (nullsub_82); returns void immediately with no state change.
- `0x00454D96` **UnknownObject** — Constant stub returning the value 1 unconditionally; both parameters are accepted but never used; no side effects, calls, fields, or globals.
- `0x00455258` **UnknownObject** — ret-only no-op stub; the MK_FP(return-address) expression is a decompiler artifact of a bare ret body, not a real indirect call.
- `0x004579B0` **UnknownObject** — Constant stub returning the value 0 unconditionally; all five parameters are accepted but never used; no side effects.
- `0x00458498` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x0045E5D0` **NetCommSessionPeer** — Value-returning setter on session-peer state: writes a3 into DWORD-array slot this[a2 + 117] and returns a3 unchanged; a2 is a peer/session-slot index. Callers: NetCommSessionMessageDispatcher (0x0045D890) and NetComm_SetSelfAsReady (0x00460520).
- `0x004618D0` **UnknownObject** — Free-function path utility: returns a pointer past the last backslash (ASCII 92) of a NUL-terminated path string, or the string start when no backslash is present. Called once by SessionConfigBuilder (0x00461610).
- `0x00461CC3` **UnknownObject** — Pass-through identity: returns its first argument unchanged; no side effects, globals, or callees.
- `0x00462156` **UnknownObject** — Empty __stdcall stub taking five unused int arguments (nullsub_85); callback placeholder retained to satisfy a call-site convention.
- `0x004627B8` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x00462CD4` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x004636E6` **UnknownObject** — Increments the byte at offset 94 of the object pointed to by a2 by the value of a1 and returns a1 unchanged; __userpurge ABI (a1 in BL, a2 in EDI), a3 unused; legacy ABI name Byte_Field_Increment.
- `0x00463E14` **UnknownObject** — Empty no-op stub (nullsub); returns void immediately; no side effects, calls, globals, or fields.
- `0x00464AE0` **UnknownObject** — Predicate over a byte array at this[a2]: returns true iff the byte has its sign bit clear and its 0x7F-masked value is >= threshold a3. Sole caller: EntityVisibilityGridManager (0x00465460).
- `0x00464F90` **UnknownObject** — Pure classifier mapping integer a1 into one of five ranks via ascending thresholds (0 for a1<=1487, 1 for a1<=2975, 2 in the default band, 3 for a1<=28800, 4 above); ranked quantity unknown. Sole caller: EntityVisibilityGridManager (0x00465460).
- `0x0046624E` **UnknownObject** — Empty decompiled body under a flagged positive stack-pointer delta; likely a thunk, padding stub, or decompiler-failed function tail; no operations are grounded.
- `0x00466B10` **UnknownObject** — Offset accessor returning this + 0x104 (260 bytes); referenced sub-object type and purpose unknown; no calls, fields, globals, or guards.
- `0x0046890D` **UnknownObject** — Empty __stdcall stub taking four unused int arguments (nullsub_89); typical of a removed handler or a callback placeholder retained for a stable call site.
- `0x0046B310` **UnknownObject** — Offset accessor returning this + 0x174 (372 bytes); legacy ABI label Offset_Accessor; referenced sub-object type and purpose unknown.
- `0x0046B829` **UnknownObject** — Trivial __thiscall accessor returning this + 304 bytes; neither reads nor validates the offset; field meaning unknown.
- `0x0046C6E5` **UnknownObject** — ret-only no-op stub (nullsub_90); the MK_FP(return-address) expression is a decompiler artifact of a bare ret body, not a real call.
- `0x00473B68` **UnknownObject** — Empty __stdcall stub taking one unused int argument (nullsub_91); returns void immediately; argument meaning unknown.
- `0x00476070` **UnknownObject** — Empty __stdcall stub taking two unused int arguments (nullsub_92); no observable operation before returning.
- `0x004761A0` **UnknownObject** — Guarded string copy on an unidentified object: if source pointer a2 is non-null, delegates to StringCopyWithBufferRealloc targeting the object's string buffer at offset 80 and returns its result; otherwise returns the null source unchanged.
- `0x00478E80` **UnknownObject** — Single-call passthrough: forwards its one argument a1 unchanged to ObjectFieldInitWithIndirectLookup (legacy ABI label FUN_00499b80) and returns that result. Invoked by FilePathResolverWithExtensionAppend (0x004793EC) on a file-path resolution path.
- `0x0047AA70` **UnknownObject** — No-argument stub returning the integer constant 0 unconditionally; no side effects, fields, globals, or calls.
- `0x0047E384` **UnknownObject** — Register-passed byte accumulator: adds byte value a1 (BL) into the byte at offset 94 of the object pointer a2 (EDI); legacy ABI name ByteAccumAdd (LEGACY trust).
- `0x0047F006` **UnknownObject** — Corrupted thunk flagged by the decompiler (positive sp): decoded byte-add targets the artifact address (a2 - 963967804) and returns result (AL) unchanged; the real accumulation target is unknowable from the raw source.
- `0x00486EC8` **UnknownObject** — Field-mutating helper: adds signed char a1 (BL) into the byte at offset 0x5E (94) of the object pointed to by a2; unused userpurge parameters a3/a4.
- `0x0048B024` **UnknownObject** — No-parameter stub returning the integer constant 0; no side effects, calls, or locals.

## Proposed classes

### NetCommSessionPeer

Per-peer session state in the NetComm session path; exposes a DWORD-array of per-index slots addressed through `this` by a peer/session index. Owner identity is DERIVED only from the two recorded callers (0x0045D890, 0x00460520); no layout evidence beyond the single write site exists. No field: evidence refs exist in this packet, so no class field is declared.

Methods: `0x0045E5D0`


## Compatibility contracts

- **FixedConstantReturns** — Constant-return stubs must keep returning their fixed values at their call sites: 0x00454D96 returns 1; 0x004579B0, 0x0047AA70, and 0x0048B024 return 0. A replacement must preserve these return values wherever the referencing call sites are retained.
- **Byte94AccumulatorSemantics** — Four functions (0x0044F062, 0x004636E6, 0x0047E384, 0x00486EC8) accumulate a byte argument into the byte at offset 94 of an object pointer. They differ in return behavior: 0x0044F062 returns -1 while the others return the argument. A replacement preserving these call sites must keep the byte-at-offset-94 accumulation and each function's own return value.
- **NetCommSessionPeerSlotSetter** — 0x0045E5D0 writes its value argument into DWORD-array slot this[a2 + 117] of the session-peer object and returns that value. Session code at 0x0045D890 and 0x00460520 depends on this write-and-return contract.
- **PathFilenameExtraction** — 0x004618D0 returns a pointer past the last backslash of the input path string, or the string start when no backslash is present. SessionConfigBuilder (0x00461610) consumes the returned filename pointer.
- **NoopStubRetention** — The nullsub stubs are observable only as no-op call targets. If any are referenced by vtable or call tables, a replacement must keep an equivalent no-op slot at those call sites or rewire the referencing tables; otherwise table semantics change.
- **OffsetAccessorStability** — Offset accessors return fixed sub-object pointers relative to their object: 0x00466B10 returns this + 0x104, 0x0046B310 returns this + 0x174, 0x0046B829 returns this + 304. A replacement must preserve these layout displacements or rewire the call sites that consume them.

## Unresolved

- Owners of the byte-at-offset-94 accumulator objects (0x0044F062, 0x004636E6, 0x0047E384, 0x00486EC8) are unidentified. The equal offset 0x5E is not merged into a single class because the packet does not prove common ownership of the four object bases.
- Purpose and call sites of the no-op nullsub stubs are not evidenced; they cannot be distinguished as vtable placeholders, disabled callbacks, or dead-code-removal residue.
- NetCommSessionPeer (0x0045E5D0) is DERIVED only from the two caller names (0x0045D890, 0x00460520); no field or class layout evidence beyond the single write site is present. The DWORD-array slot at this[a2 + 117] implies a per-peer slot whose byte offset (0x1D4 at index 0) cannot be confirmed; no field: evidence ref exists in the packet, so the slot is recorded here rather than as a class field.
- ByteCounterIncrement (0x0044F062) carries a flagged positive stack adjustment; the userpurge parameter layout and the -1 return are MEDIUM trust and may be wrong.
- CorruptedThunk_f006 (0x0047F006) and sub_46624E (0x0046624E) decompile to corrupted/empty bodies under a positive sp warning; their real behavior is unknowable from the raw source.
- The sub-object types behind offset accessors 0x00466B10 (0x104), 0x0046B310 (0x174), and 0x0046B829 (304) are unknown.
- StringCopyWithBufferRealloc (callee of 0x004761A0) and the object holding the string buffer at offset 80 are outside this packet; signature, allocation policy, and failure behavior are unresolved.
- FUN_00499b80 (delegate of 0x00478E80) is a LEGACY ABI label with no prototype; delegate semantics are unresolved.
- extractFilenameFromPath (0x004618D0) returns the string start when no backslash is present; whether that boundary behavior matches SessionConfigBuilder expectations is unconfirmed.
- ThresholdToRankClassifier (0x00464F90) classifies by thresholds 1487/2975/7200/28800; the ranked quantity and the meaning of the five ranks are unknown.
- The MK_FP(return-address) expressions in 0x00455258 and 0x0046C6E5 are decompiler artifacts of bare ret bodies, not genuine indirect calls.
- ReturnTrueStub (0x00454D96) and ReturnZeroStub (0x004579B0) have no caller evidence; whether their fixed values are booleans, status codes, or enumeration constants is unresolved.
