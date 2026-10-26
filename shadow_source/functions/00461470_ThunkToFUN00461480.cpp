// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461470
// Canonical corpus name: ThunkToFUN00461480
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN00461480_00461470.c

void UnknownObject::ThunkToFUN00461480()
{
    // Initializer thunk: calls StructFieldZeroInitWithDefaults(this) to initialize this object's fields with default values, then returns this unchanged to support chained initialization. Called from many network/session/input/render paths.
    // CALL: Call StructFieldZeroInitWithDefaults(this), passing the object pointer as the __thiscall receiver. [callee:0x00461480, source:raw]
    // RETURN: Return this (the object pointer) unchanged. [source:raw, function:0x00461470]

    // Conservative worker pseudocode:
    //   void* sub_461470(void* this) {
    //     StructFieldZeroInitWithDefaults(this);
    //     return this;
    //   }
    // UNRESOLVED: The receiver object type and the exact field defaults applied by StructFieldZeroInitWithDefaults are unknown.
    // UNRESOLVED: Whether this thunk only forwards or adds initialization state beyond the callee cannot be determined from this packet.
}
