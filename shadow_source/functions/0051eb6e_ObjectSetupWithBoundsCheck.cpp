// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051EB6E
// Canonical corpus name: ObjectSetupWithBoundsCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectSetupWithBoundsCheck_0051eb6e.c

void UnknownObject::ObjectSetupWithBoundsCheck()
{
    // Allocates a sub-object via a factory/allocation callback at this+0x4 called with (this, 1, 88), stores the returned pointer at this+0x1A4, and initializes its function pointers: CodecModeSelect at obj+0x0, nullsub_4 at obj+0x8, VirtualCallWithIntegerSet at obj+0xC, with obj+0x34 and obj+0x44 zeroed. Then conditionally clamps two bound/dimension fields of the object referenced through this+0x0: when this+0x64 > 4 it writes 54 to obj+0x14 and 4 to obj+0x18 and dispatches a virtual call; when this+0x54 > 256 it writes 56 to obj+0x14 and 256 to obj+0x18 and dispatches a virtual call. Finally calls ImageBufferStrideFill and sub_51E3E7; if this+0x4C == 2 returns the result of VirtualArrayFill instead. Called by sub_516C7B.
    // CALL: Invoke factory/allocation function pointer at this+0x4 with (this, 1, 88) and store the returned object pointer at this+0x1A4. [field:this:0x00000004, field:this:0x000001A4]
    // ASSIGNMENT: Set obj+0x0 to CodecModeSelect (codec mode function pointer). [field:obj:0x00000000, global:0x0051EA90]
    // ASSIGNMENT: Set obj+0x8 to nullsub_4 (no-op callback). [global:0x0051DFCA, source:raw]
    // ASSIGNMENT: Set obj+0xC to VirtualCallWithIntegerSet. [global:0x0051EB5A, source:raw]
    // ASSIGNMENT: Zero obj+0x34 and obj+0x44. [source:raw]
    // GUARD: If this+0x64 > 4, write 54 to obj+0x14 and 4 to obj+0x18, then dispatch through the object's first vtable entry (*(*a1))(a1). [guard:2, field:this:0x00000064, field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000000]
    // GUARD: If this+0x54 > 256, write 56 to obj+0x14 and 256 to obj+0x18, then dispatch through the object's first vtable entry (*(*a1))(a1). [guard:1, field:this:0x00000054, field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000000]
    // CALL: Call ImageBufferStrideFill(this) to fill image-buffer stride state. [callee:0x0051E2BA]
    // CALL: Call sub_51E3E7(this) and keep its result as the default return value. [callee:0x0051E3E7]
    // GUARD: If this+0x4C == 2, call VirtualArrayFill(this) and return its result instead of the default. [guard:0, field:this:0x0000004C, callee:0x0051EA5A]
    // RETURN: Return either the VirtualArrayFill result (when this+0x4C == 2) or the result of sub_51E3E7. [function:0x0051EB6E]

    // Conservative worker pseudocode:
    //   child = factory(this+4)(this, 1, 88);
    //   this[0x1A4] = child;
    //   child[0] = CodecModeSelect; child[0x8] = nullsub_4; child[0xC] = VirtualCallWithIntegerSet; child[0x34] = 0; child[0x44] = 0;
    //   if (this[0x64] > 4) { child[0x14] = 54; child[0x18] = 4; (*child)[0](this); }
    //   if (this[0x54] > 256) { child[0x14] = 56; child[0x18] = 256; (*child)[0](this); }
    //   ImageBufferStrideFill(this);
    //   result = sub_51E3E7(this);
    //   return (this[0x4C] == 2) ? VirtualArrayFill(this) : result;
    // UNRESOLVED: Semantics of the factory call: unknown object type and meaning of literal parameters 1 and 88.
    // UNRESOLVED: Meaning of the clamp writes 54/4 and 56/256 to obj+0x14/obj+0x18 (bound/dimension fields) and of the dispatched virtual call through *a1.
    // UNRESOLVED: Interpretation of this+0x64 (>4) and this+0x54 (>256) guards as height/width per the existing analysis is unproven.
    // UNRESOLVED: The packet folds the allocated child (stored at this+0x1A4) and the object referenced via this+0x0 under one 'obj' base; whether they are the same object is unconfirmed.
    // UNRESOLVED: Zeroed fields obj+0x34 and obj+0x44 have no dedicated evidence refs; grounded in raw source only.
}
