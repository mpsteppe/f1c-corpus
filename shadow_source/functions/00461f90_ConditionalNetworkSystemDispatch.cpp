// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461F90
// Canonical corpus name: ConditionalNetworkSystemDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalNetworkSystemDispatch_00461f90.c

void UnknownObject::ConditionalNetworkSystemDispatch()
{
    // Queries the network system pointer stored at this+0x1B79C and, only when it is non-null and sub_563E70 reports the network/system as capable, sets a flag on that network system pointer. Returns the flag result in that branch, otherwise the unchanged early result (the this-pointer value).
    // ASSIGNMENT: Seed result = *this (dereference the this pointer). [field:this:0x00000000, source:raw]
    // GUARD: Guard on the network system pointer at this + 0x1B79C being non-null; if null, skip the dispatch body. [field:obj:0x0001B79C, source:raw]
    // CALL: sub_563E70() queries whether the network/system is capable of initialization. [callee:0x00563E70, source:raw]
    // GUARD: Guard on the capability result being non-zero; proceed to flag-setting only when capable. [source:raw]
    // STATE_TRANSITION: Set the flag on the network system pointer (SetFlagIfPointerNonNull on this+0x1B79C) and return its result. [source:raw, field:obj:0x0001B79C]
    // RETURN: Fall-through return of the early result when either guard fails. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_461F90(int *this) {
    //     int result = *this;
    //     int *net = *(int **)(*this + 0x1B79C);
    //     if (net) {
    //       if (sub_563E70())
    //         return SetFlagIfPointerNonNull(net);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: SetFlagIfPointerNonNull appears in the raw source but has no packet callee entry; likely a macro or inlined helper.
    // UNRESOLVED: Meaning of the 112540 decimal literal (0x1B79C) as an object offset is taken from the packet's field entry.
    // UNRESOLVED: Identity of the network system object type at this+0x1B79C.
}
