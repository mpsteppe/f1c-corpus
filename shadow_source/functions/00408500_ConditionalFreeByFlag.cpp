// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00408500
// Canonical corpus name: ConditionalFreeByFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFreeByFlag_00408500.c

void UnknownObject::ConditionalFreeByFlag()
{
    // Conditional-free helper: notifies the vtable entry of cleanup via VtableEntryNotifyCleanup, then releases the object memory via FreeWrapper_7bcf only when the low bit (bit 0) of the flag argument is set. Returns the object pointer.
    // CALL: VtableEntryNotifyCleanup(this) — notify the vtable entry of cleanup [callee:0x00408520, source:raw]
    // GUARD: if ((a2 & 1) != 0) — free only when bit 0 of the flag is set [source:raw]
    // CALL: FreeWrapper_7bcf(this) — release the object memory [callee:0x00587BCF, source:raw]
    // RETURN: return this [source:raw]

    // Conservative worker pseudocode:
    //   VtableEntryNotifyCleanup(this);
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: flag bit semantics beyond bit 0 (defer-free) are unknown
    // UNRESOLVED: owner object type unknown; function acts as a vtable-notify plus conditional-free helper
}
