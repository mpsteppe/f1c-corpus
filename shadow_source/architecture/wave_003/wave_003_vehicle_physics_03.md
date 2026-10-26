# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

DERIVED proposal for the vehicle_physics scope. The packet contains 50 functions: 44 trivial lifecycle stubs (30 registration-styled, 14 teardown-styled) that each read a nullsub placeholder function pointer and return BooleanToIntConversion (0x00587B3E) applied to that address - the legacy names suggest collision registration/teardown hook points, but every body is behaviorally identical and wraps a no-op, so the real handlers and the consumers of the returned status are unknown. Six real functions carry the actual collision logic: CollisionNodePropertySetter writes a byte at (a2+636), CollisionDataFill memset32s 256 bytes at offset 636, CollisionProxyUnregister maintains the active proxy-id word list at +0xC88 and per-proxy state, CollisionParameterClampAndStore clamps three floats and stores them at per-index offsets, ConditionalCollisionDispatch gates CollisionNodePropertySetter on a guard field at +0x0, and CollisionResultProcessing resolves a typed collision result into activation (+0x24) and magnitude (+0x28) outputs. All 50 required functions are covered exactly once; every callee, field and global is reported verbatim from the packet. Owners remain UnknownObject in the packet; the class/interface organization is a conservative GUESS layer on top, with uncertain structure left in unresolved rather than forced.

## Function roles

- `0x0044D6D0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044D6E0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044D790` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044D7A0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044D7F0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044D800, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044D970` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044D980, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044DAF0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044DB00, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044DB50` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044DB60, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044DC10` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044DC20, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044DC70` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044DC80, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044DCD0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044DCE0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044DD30` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044DD40, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044DE50` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044DE60, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044DF10` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044DF20, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044DF70` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044DF80, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E0F0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E100, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E270` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E280, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E2D0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E2E0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E390` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E3A0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E3F0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E400, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E450` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E460, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E4B0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E4C0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E5D0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E5E0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E690` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E6A0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E6F0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E700, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E870` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044E880, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044E9F0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044EA00, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044EA50` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044EA60, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044EB10` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044EB20, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044EB70` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044EB80, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044EBD0` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044EBE0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044EC30` **CollisionRegistrationHooks** — Legacy collision-registration stub: reads the placeholder nullsub function pointer at 0x0044EC40, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-registration behavior, so the result is a constant non-zero status.
- `0x0044D610` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044D620, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044D8B0` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044D8C0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044DA90` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044DAA0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044DBB0` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044DBC0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044DD90` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044DDA0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044DEB0` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044DEC0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044E030` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044E040, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044E210` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044E220, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044E330` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044E340, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044E510` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044E520, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044E7B0` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044E7C0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044E990` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044E9A0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044EAB0` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044EAC0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044EC90` **CollisionTeardownHooks** — Legacy collision-teardown stub: reads the placeholder nullsub function pointer at 0x0044ECA0, routes it through BooleanToIntConversion (0x00587B3E) and returns the converted integer; the wrapped no-op supplies no real collision-teardown behavior, so the result is a constant non-zero status.
- `0x0044F050` **CollisionNodePropertyRegion** — Byte-property setter (thiscall): writes the caller-supplied byte a3 into the object at byte offset (a2 + 636) and returns a3; invoked by SwapAndReinit (0x00452740), ConditionalCollisionDispatch (0x004527C0) and CameraViewportConfigBatch (0x00453560).
- `0x0044F070` **CollisionNodePropertyRegion** — Block fill (fastcall): builds a three-byte-lane fill pattern from byte a3 (value|value<<8|value<<16) and memset32s 0x40 dwords (256 bytes) at offset 636 of the object; invoked by HWInput_Post (0x00455E70).
- `0x0044F0E0` **CollisionProxy** — Proxy-slot unregister: clears the active-flag byte at this+0x37C, scans the active proxy-id word list at this+0xC88 (up to 256 entries) and clears the matched entry, and resets the per-proxy dword at this+0x87C+4*a2 to 0.0 or dbl_8AFEA8+a3 depending on the sign of a3.
- `0x0044FC20` **CollisionParameterStore** — Collision parameter clamp-and-store: clamps a4/a5 into [0.0, 1.0] and a3 at a 0.0 lower bound, then stores them at float index a2+8 (byte 0x20+4*a2), a2+190 (byte 0x2F8+4*a2) and a2 (byte 4*a2); returns the D3DTextureStage (0x0044F8F0) result on both branches.
- `0x004527C0` **CollisionDispatch** — Conditional collision-node property dispatch: when the guard dword at this+0x0 is zero, calls CollisionNodePropertySetter (0x0044F050) with byte_7CA594, this[1] and this[2] and returns its result; the non-zero guard path returns without dispatching.
- `0x00453100` **CollisionResultProcessor** — Collision result processing selected by the type field at this+0x0: early zero-output when ConditionalFlagReturn(&dword_5EA43C) is set and dword_7C569C equals 5; type 0 reads a packed flag via PackedFlagRead(byte_7CA594, this[1]); type 1 reads activation from *(this+0x1C)+0x10; type 2 takes the absolute value of the float at *(this+0x20)+4 as the magnitude and derives a 0/1 activation state from a 0.5 threshold. Writes activation at +0x24 and magnitude at +0x28.

## Proposed classes

### CollisionRegistrationHooks

Semantic grouping (GUESS) of the 30 legacy collision-registration stubs (CollisionCallbackRegistration*, CollisionModuleRegister*, CollisionStaticDataRegistration*, CollisionDataRegistrationBlock*, CollisionInitRegistration/Wrapper/Delegator, ThunkCollisionInit*, CollisionConstructorThunk*, CollisionCallbackRegister*). Every member reads a nullsub placeholder function pointer and returns BooleanToIntConversion (0x00587B3E) applied to that address; no registration side effect is visible. Packet owners are UnknownObject; class boundaries are not proven.

Methods: `0x0044D6D0`, `0x0044D790`, `0x0044D7F0`, `0x0044D970`, `0x0044DAF0`, `0x0044DB50`, `0x0044DC10`, `0x0044DC70`, `0x0044DCD0`, `0x0044DD30`, `0x0044DE50`, `0x0044DF10`, `0x0044DF70`, `0x0044E0F0`, `0x0044E270`, `0x0044E2D0`, `0x0044E390`, `0x0044E3F0`, `0x0044E450`, `0x0044E4B0`, `0x0044E5D0`, `0x0044E690`, `0x0044E6F0`, `0x0044E870`, `0x0044E9F0`, `0x0044EA50`, `0x0044EB10`, `0x0044EB70`, `0x0044EBD0`, `0x0044EC30`


### CollisionTeardownHooks

Semantic grouping (GUESS) of the 14 legacy collision-teardown stubs (CollisionDataTeardown*, CollisionDataFree, CollisionSoundUnregister*, CollisionGridFree*, CollisionResourceRelease*). Every member reads a nullsub placeholder function pointer and returns BooleanToIntConversion (0x00587B3E) applied to that address; no teardown side effect is visible. Packet owners are UnknownObject; class boundaries are not proven.

Methods: `0x0044D610`, `0x0044D8B0`, `0x0044DA90`, `0x0044DBB0`, `0x0044DD90`, `0x0044DEB0`, `0x0044E030`, `0x0044E210`, `0x0044E330`, `0x0044E510`, `0x0044E7B0`, `0x0044E990`, `0x0044EAB0`, `0x0044EC90`


### CollisionNodePropertyRegion

Functions addressing a byte-indexed property region whose base lies at offset 636 (0x27C) of a caller-supplied object: CollisionNodePropertySetter writes one byte at (index + 636) and CollisionDataFill fills 256 bytes at 636 with a uniform pattern. The two functions never occur in the same frame path in this packet, so common ownership of the 636-offset region is GUESS.

Methods: `0x0044F050`, `0x0044F070`


### CollisionProxy

Collision proxy-slot bookkeeping (single evidenced method): CollisionProxyUnregister clears the active-flag byte, removes the proxy id from the active word list at +0xC88 and resets the per-proxy dword. The +0x37C and +0x87C offsets are DERIVED from behavior and not struct-confirmed.

Methods: `0x0044F0E0`

- `this+0x00000C88` `uint16[256] active_proxy_id_words` (read_write, DERIVED)

### CollisionParameterStore

Stores clamped per-index float collision parameters at float indices a2, a2+8 and a2+190 (byte offsets 4*a2, 0x20+4*a2, 0x2F8+4*a2). The D3DTextureStage call in the body is treated as a likely decompiler artifact; the clamp-and-store role is the evidenced core.

Methods: `0x0044FC20`


### CollisionDispatch

Conditional dispatch that forwards a byte collision-node property to CollisionNodePropertySetter when the guard field at this+0x0 is zero.

Methods: `0x004527C0`

- `this+0x00000000` `int32 dispatch_guard` (read, DERIVED)
- `this+0x00000004` `int32 property_index` (read, GUESS)
- `this+0x00000008` `int32 property_value` (read, GUESS)

### CollisionResultProcessor

Collision result resolution: selects a result type at this+0x0 (0=packed flag, 1=object field, 2=axis), computes an activation value and magnitude, and stores them at this+0x24 and this+0x28. Field names are DERIVED from usage; the type-enum values are unproven.

Methods: `0x00453100`

- `this+0x00000000` `int32 result_type` (read, DERIVED)
- `this+0x00000004` `int32 packed_flag_param` (read, GUESS)
- `this+0x0000001C` `void* object_field_ref` (read, GUESS)
- `this+0x00000020` `void* axis_ref` (read, GUESS)
- `this+0x00000024` `float activation_state` (write, DERIVED)
- `this+0x00000028` `float magnitude` (write, DERIVED)
- `*(this+0x1C)+0x00000010` `int32 object_activation` (read, GUESS)
- `*(this+0x20)+0x00000004` `float axis_float` (read, GUESS)

## Compatibility contracts

- **CollisionNodePropertyRegion** — CollisionNodePropertySetter (0x0044F050) writes one byte at byte offset (a2+636) of a caller object and CollisionDataFill (0x0044F070) fills 256 bytes (0x40 dwords) at offset 636 with a three-lane pattern derived from one byte. Callers SwapAndReinit (0x00452740), ConditionalCollisionDispatch (0x004527C0), CameraViewportConfigBatch (0x00453560) and HWInput_Post (0x00455E70) depend on this region; a replacement must preserve the region offset and byte semantics.
- **CollisionResultOutputs** — CollisionResultProcessing (0x00453100) writes an activation value at result+0x24 and a magnitude at result+0x28, selected by the type field at result+0x0, and reads the packed-flag parameter at +0x4, an object reference at +0x1C and an axis reference at +0x20. A replacement must reproduce the same result outputs and type dispatch.
- **CollisionProxyActiveIdList** — CollisionProxyUnregister (0x0044F0E0) maintains an active proxy-id word list at object+0xC88 (up to 256 entries), a per-proxy active-flag byte at +0x37C and a per-proxy dword at +0x87C+4*a2; unregistering clears the matching list entry and resets the dword to 0.0 or dbl_8AFEA8+a3. A replacement must preserve the list and flag semantics. Offsets +0x37C/+0x87C are DERIVED from usage.
- **CollisionLifecycleHookStatus** — The 44 registration/teardown stubs return the integer produced by BooleanToIntConversion (0x00587B3E) applied to a nullsub function pointer. Because the wrapped routines are no-ops, the returned status is a constant non-zero value; a replacement that materializes these lifecycle hooks must keep the int(void) signature, but the status semantics are not evidenced.

## Unresolved

- All 44 registration/teardown stubs wrap nullsub (no-op) placeholder routines through BooleanToIntConversion (0x00587B3E); the real handlers they stand for, and the consumers of the returned status, are unknown and no callers are recorded.
- The exact semantics of BooleanToIntConversion (registration vs status conversion) are not established by this packet; every stub only forwards whatever integer the helper produces.
- Common ownership of the 636-offset (0x27C) byte region by CollisionNodePropertySetter and CollisionDataFill is GUESS: the two functions operate on caller-supplied objects and do not co-occur in a shared frame path in this packet.
- The D3DTextureStage (0x0044F8F0) call inside CollisionParameterClampAndStore is treated as a likely decompiler artifact; the clamp-and-store role is the evidenced core, but the call's true role is unresolved.
- The type-enum values (0=packed flag, 1=object field, 2=axis) in CollisionResultProcessing and the magic session value 5 in dword_7C569C are not established by this packet.
- CollisionProxyUnregister offsets +0x37C (active flag) and +0x87C+4*a2 (per-proxy dword) are DERIVED from behavior and are not present as allowed field refs; their struct identity is unconfirmed.
- global:0x0059E880 is listed for CollisionResultProcessing but does not appear in the raw decompiled source; it may back the 0.5 threshold or related physics data, but its role is unresolved.
- byte_7CA594 is read by ConditionalCollisionDispatch and CollisionResultProcessing but its type and role are resolved elsewhere; it is consumed here as an opaque argument.
- Legacy ABI names (registration/teardown/init/sound-unregister/grid-free/resource-release variants) are UNKNOWN-trust labels from the corpus and are not verified against body evidence; the 44 stubs are behaviorally identical.
- No genuine state machine is evidenced: CollisionResultProcessing's type dispatch is a selector, not a stateful transition graph, so state_machines is left empty.
