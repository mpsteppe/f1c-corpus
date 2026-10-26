// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004979E0
// Canonical corpus name: SimpleSetter_79e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SimpleSetter_79e0_004979e0.c

void UnknownObject::clearField20()
{
    // Trivial void thiscall that unconditionally writes 0 to the DWORD at this+0x20 (float-array index 8). Acts as a reset/clear for a UI state field. Invoked by UIWidgetVisibilityToggle at 0x0048B91A.
    // ASSIGNMENT: Write 0 to the field at this+0x20 (this[8]), resetting a UI state/flag field unconditionally. [field:this:0x00000020, function:0x004979E0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4979E0(_DWORD* this) {
    //     this[8] = 0;
    //   }
    // UNRESOLVED: Semantics of the field at this+0x20 are unknown; only that it is cleared to 0 by this function.
    // UNRESOLVED: Caller UIWidgetVisibilityToggle (0x0048B91A) context not reconstructed; caller evidence preserved below.
}
