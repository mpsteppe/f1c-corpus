// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583690
// Canonical corpus name: SingleFunctionCallWrapper_3690
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_3690_00583690.c

void UnknownObject::updateTimerDelta()
{
    // Thiscall wrapper that forwards the object pointer to HighResolutionTimerDelta at this+4, updating a high-resolution timer delta stored in the object.
    // CALCULATION: Computes pointer (this+4), presumed to address the timer-delta member of the object, to pass as the argument. [source:raw]
    // CALL: Calls HighResolutionTimerDelta with the pointer to this+4 and returns nothing. [callee:0x00568CF0, source:raw]

    // Conservative worker pseudocode:
    //   void updateTimerDelta(F1CObject *this) {
    //     HighResolutionTimerDelta((double *)(this + 4));
    //   }
    // UNRESOLVED: The object type and the meaning of the this+4 member are unknown; the member is read as a double* by HighResolutionTimerDelta.
    // UNRESOLVED: HighResolutionTimerDelta semantics beyond 'updates a timer delta' are not established from this packet.
}
