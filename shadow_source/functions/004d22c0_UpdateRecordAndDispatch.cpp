// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D22C0
// Canonical corpus name: FieldSetterWithInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldSetterWithInit_004d22c0.c

void UnknownObject::UpdateRecordAndDispatch()
{
    // Field-update then dispatch: zeroes the byte flag at this+0xC1, stores the float global dbl_8AFEA0 into this+0xB0, copies a dword from source a2+12 into this+0xB4, then calls sub_42D140 with &dword_7C569C and a dword from source a2+8, returning its result. All writes are unconditional; there are no guards. dbl_8AFEA0 is labeled current session time and dword_7C569C SessionType in existing_analysis (DERIVED, not confirmable from raw source alone).
    // ASSIGNMENT: Zero the byte flag at this+0xC1 unconditionally. [field:this:0x000000C1]
    // ASSIGNMENT: Store the float read from global dbl_8AFEA0 into this+0xB0. [field:this:0x000000B0, global:0x008AFEA0]
    // ASSIGNMENT: Copy the dword at source a2+12 into this+0xB4. [field:this:0x000000B4, source:raw]
    // CALL: Dispatch to sub_42D140 with &dword_7C569C and the dword at source a2+8; capture its return value. [global:0x007C569C, source:raw]
    // RETURN: Return the dispatch result from sub_42D140. [function:0x004D22C0, source:raw]

    // Conservative worker pseudocode:
    //   *(uint8_t*)(this + 0xC1) = 0;
    //   *(float*)(this + 0xB0) = dbl_8AFEA0;
    //   *(uint32_t*)(this + 0xB4) = *(uint32_t*)(a2 + 12);
    //   return sub_42D140(&dword_7C569C, *(uint32_t*)(a2 + 8));
    // UNRESOLVED: The dispatch target sub_42D140 appears in the raw source but is absent from the packet's callee list, so its identity is unresolved here.
    // UNRESOLVED: dword_7C569C passed by address is a session-state global; the existing_analysis label SessionType5 (5=server) is DERIVED and not confirmable from this packet.
    // UNRESOLVED: dbl_8AFEA0 is labeled current session time in existing_analysis (DERIVED); raw source only shows it read as a float.
    // UNRESOLVED: Semantics of source fields a2+8 and a2+12 are unknown; the source object type is not established.
}
