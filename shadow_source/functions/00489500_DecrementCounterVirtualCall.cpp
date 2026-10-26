// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489500
// Canonical corpus name: DecrementCounterVirtualCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DecrementCounterVirtualCall_00489500.c

void UnknownObject::DecrementCounterVirtualCall()
{
    // UI scroll/selection index decrement. Dispatches the virtual notification slot at vtable offset 0x2C (vtable pointer at this+0x0) with the argument 1, decrements the selection counter at this+0x14C, then refreshes the list state via sub_489D00 and converts the internal float position via FloatToIntConversion. Always returns 0.
    // CALL: Dispatches the virtual notification handler at vtable offset 0x2C (vtable pointer read from this+0x0) with the argument 1 [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Decrements the counter/selection index at offset 0x14C (this[83]) [field:this:0x0000014C, source:raw]
    // CALL: Calls sub_489D00 to refresh the scroll-list visual state [callee:0x00489D00, source:raw]
    // CALL: Calls FloatToIntConversion to convert the internal float position to an integer [callee:0x00489E90, source:raw]
    // RETURN: Returns 0 [function:0x00489500, source:raw]
    // STATE_TRANSITION: Invoked as a decrement path by UIScrollbarThumbDragHandler and UIScrollListUpdate [caller:0x0048A650, caller:0x0048A8D0, source:raw]

    // Conservative worker pseudocode:
    //   int DecrementCounterVirtualCall(void* this) {
    //     (*(void (__thiscall**)(void*, int))(*(int*)this + 0x2C))(this, 1);
    //     this->counter--;                    // this+0x14C
    //     sub_489D00(this);
    //     FloatToIntConversion(this);
    //     return 0;
    //   }
    // UNRESOLVED: The virtual slot at vtable offset 0x2C is a notification/change handler per the analysis fill; its exact interface is defined by the vtable owner, outside this packet
    // UNRESOLVED: The counter at offset 0x14C (a selection index) and any post-decrement clamping/minimum behavior are defined outside this packet
}
