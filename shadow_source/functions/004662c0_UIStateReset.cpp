// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004662C0
// Canonical corpus name: UIStateReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIStateReset_004662c0.c

void UnknownObject::UIStateReset()
{
    // Resets part of a UI state object: calls FieldSetterCall(*(_DWORD**)(this+0x40), 0) on the object referenced by the pointer field at this+0x40, then zeroes two byte flags at this+0xF4 and this+0xF5. Returns 0. Prelabeled as a structural twin of FlagClearZeroBytes (00466290).
    // CALL: Call FieldSetterCall on the object referenced by the pointer at this+0x40, passing value 0 [callee:0x004988A0, field:this:0x00000040, source:raw]
    // ASSIGNMENT: Zero the byte flag at this+0xF4 [field:this:0x000000F4, source:raw]
    // ASSIGNMENT: Zero the byte flag at this+0xF5 [field:this:0x000000F5, source:raw]
    // RETURN: Return 0 [function:0x004662C0, source:raw]

    // Conservative worker pseudocode:
    //   FieldSetterCall(*(_DWORD **)(this + 64), 0);
    //   *(_BYTE *)(this + 244) = 0;
    //   *(_BYTE *)(this + 245) = 0;
    //   return 0;
    // UNRESOLVED: The object type behind the pointer field at this+0x40 and FieldSetterCall's contract are not evidenced at this site
    // UNRESOLVED: Whether the two byte flags at this+0xF4 and this+0xF5 are an independent pair or one wider flag is not evidenced here
    // UNRESOLVED: No callers are recorded, so the UI-state reset path is not evidenced
}
