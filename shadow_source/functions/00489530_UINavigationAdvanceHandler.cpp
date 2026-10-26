// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489530
// Canonical corpus name: UINavigationAdvanceHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UINavigationAdvanceHandler_00489530.c

void UnknownObject::UINavigationAdvanceHandler()
{
    // UI navigation-advance handler: dispatches a virtual call through vtable entry 11 (offset 0x2C on obj) with argument 1, increments a counter at this+0x14C, then calls sub_489D00 and FloatToIntConversion. Linear, always returns 0. Called by UIScrollbarThumbDragHandler and UIScrollListUpdate.
    // CALL: Virtual dispatch through vtable entry 11 (offset 0x2C on obj) with argument 1; entry is read from the vtable pointer at this+0x0 [field:obj:0x0000002C, field:this:0x00000000, caller:0x0048A650, caller:0x0048A8D0, source:raw]
    // ASSIGNMENT: Increments the counter at this+0x14C (source index this[83]) [field:this:0x0000014C, source:raw]
    // CALL: Calls sub_489D00 with this [callee:0x00489D00, source:raw]
    // CALL: Calls FloatToIntConversion with this [callee:0x00489E90, source:raw]
    // RETURN: Returns 0 [function:0x00489530, source:raw]

    // Conservative worker pseudocode:
    //   (*(this->vtable[11]))(this, 1);
    //   ++this[83];
    //   sub_489D00(this);
    //   FloatToIntConversion(this);
    //   return 0;
    // UNRESOLVED: Semantics of the vtable entry at obj+0x2C (its argument 1) and the purpose of the counter at this+0x14C are not independently confirmed; the canonical name and the cluster_copy prelabel (structural twin of DecrementCounterVirtualCall, 00489500) are DERIVED, not FACT
}
