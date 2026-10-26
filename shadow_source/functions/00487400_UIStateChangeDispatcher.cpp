// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487400
// Canonical corpus name: UIStateChangeDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIStateChangeDispatcher_00487400.c

void UnknownObject::UIStateChangeDispatcher()
{
    // UI state-change dispatcher with change detection: reads the current state byte through ByteFieldGetterAt100; if the incoming state a2 differs, invokes a virtual notification through the object vtable (offset 44) with argument 1, then returns the result of the state-propagation call UIWidgetPropagateState(a2).
    // CALL: Read current UI state byte from object field at +0x2C via ByteFieldGetterAt100(this) [callee:0x00486710, field:obj:0x0000002C, source:raw]
    // GUARD: If (byte)a2 equals the current state value, skip the virtual state-change notification [field:obj:0x0000002C, source:raw]
    // CALL: Invoke virtual state-change notification at vtable offset 44 with argument 1 when the state changed [field:this:0x00000000, source:raw]
    // RETURN: Return the result of the state-propagation call UIWidgetPropagateState(a2) [function:0x00487400, source:raw]

    // Conservative worker pseudocode:
    //   int UIStateChangeDispatcher(this, new_state) {
    //     if ((char)new_state != ByteFieldGetterAt100(this))
    //       this->vtable[44](1);
    //     return UIWidgetPropagateState(new_state);
    //   }
    // UNRESOLVED: UIWidgetPropagateState target function has no callee evidence ref in the packet
    // UNRESOLVED: Semantics of virtual notification argument 1 unknown
    // UNRESOLVED: Relationship between field obj+0x2C and the value returned by ByteFieldGetterAt100 not independently confirmed
}
