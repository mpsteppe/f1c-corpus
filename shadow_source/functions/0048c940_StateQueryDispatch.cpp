// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048C940
// Canonical corpus name: StateQueryDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateQueryDispatch_0048c940.c

void UnknownObject::StateQueryDispatch()
{
    // State-dependent dispatch. If ByteFieldGetterAt100 returns nonzero, calls vtable entry 16 (offset 0x40) with argument 5; otherwise, if ShortComputation_6720 returns 5, calls vtable entry 16 with argument 0. vtable entry 43 (offset 0xAC) is always called afterward on both paths. Returns 0 in both paths.
    // GUARD: If ByteFieldGetterAt100(this) returns nonzero, take the true dispatch path [callee:0x00486710, field:this:0x00000000, source:raw]
    // CALL: Virtual dispatch through vtable entry 16 (offset 0x40 on obj) with argument 5 (stdcall, no this) [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: Virtual dispatch through vtable entry 43 (offset 0xAC on obj) with this [field:obj:0x000000AC, field:this:0x00000000, source:raw]
    // RETURN: Returns 0 on the true path [function:0x0048C940, source:raw]
    // GUARD: On the false path, if ShortComputation_6720(v2) equals 5, take the secondary dispatch [callee:0x00486720, source:raw]
    // CALL: Virtual dispatch through vtable entry 16 (offset 0x40 on obj) with this and argument 0 [field:obj:0x00000040, field:this:0x00000000, source:raw]
    // CALL: Virtual dispatch through vtable entry 43 (offset 0xAC on obj) with this [field:obj:0x000000AC, field:this:0x00000000, source:raw]
    // RETURN: Returns 0 on the false path [function:0x0048C940, source:raw]

    // Conservative worker pseudocode:
    //   if (ByteFieldGetterAt100(this)) {
    //       (*(this->vtable[16]))(5);
    //       (*(this->vtable[43]))(this);
    //       return 0;
    //   } else {
    //       if (ShortComputation_6720(v2) == 5)
    //           (*(this->vtable[16]))(this, 0);
    //       (*(this->vtable[43]))(this);
    //       return 0;
    //   }
    // UNRESOLVED: ShortComputation_6720 receives the decompiler register variable v2 that is never assigned in this function; its effective input is unknown
    // UNRESOLVED: The state flag read by ByteFieldGetterAt100 is not present in this packet's field list, so its owning object offset is not asserted here
}
