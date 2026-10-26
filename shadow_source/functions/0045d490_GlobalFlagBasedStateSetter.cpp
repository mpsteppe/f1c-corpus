// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045D490
// Canonical corpus name: GlobalFlagBasedStateSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalFlagBasedStateSetter_0045d490.c

void UnknownObject::GlobalFlagBasedStateSetter()
{
    // Checks the game module state via StateCheckWrapper on global dword_7CD25C; when it passes, updates the object state by calling sub_45CD70(this), then sets the byte flag at this+1 to the value of global byte_7D0F94 (1 or 0). Returns the state-check result (0 when the check fails) or the global flag value on the success path. Called by 0x00463F70.
    // CALL: result = StateCheckWrapper(dword_7CD25C); validate game module state before proceeding [callee:0x00461DC0, global:0x007CD25C]
    // GUARD: if StateCheckWrapper returned nonzero (state valid) [callee:0x00461DC0]
    // CALL: sub_45CD70(this); update object state on the this pointer [callee:0x0045CD70]
    // ASSIGNMENT: result = byte_7D0F94; load the global boolean flag [global:0x007D0F94]
    // GUARD: branch on global byte_7D0F94 being nonzero [global:0x007D0F94]
    // ASSIGNMENT: if byte_7D0F94 nonzero, set the byte at this+1 to 1 [field:this:0x00000001, global:0x007D0F94]
    // ASSIGNMENT: else set the byte at this+1 to 0 [field:this:0x00000001]
    // RETURN: return result; 0 when state check failed, otherwise the value of byte_7D0F94 [global:0x007D0F94, callee:0x00461DC0]

    // Conservative worker pseudocode:
    //   result = StateCheckWrapper(dword_7CD25C);
    //   if (result) {
    //       sub_45CD70(this);
    //       result = byte_7D0F94;
    //       if (byte_7D0F94) *(_BYTE*)(this + 1) = 1;
    //       else *(_BYTE*)(this + 1) = 0;
    //   }
    //   return result;
    // UNRESOLVED: Role of the byte at this+1 and the semantics of sub_45CD70 are not established; the object type is unnamed
}
