// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463BC0
// Canonical corpus name: sub_463BC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_463BC0_00463bc0.c

void UnknownObject::EnterMultiplayerOrCircuitSelection()
{
    // Entry handler that, when the enable flag byte at obj+0xC5 is non-zero, sets championship mode (dword_7D0410) to 5 with overrides from dword_7D0418/dword_7D041C, sets global flag byte_7D0F94 to 1, invokes SingleFunctionCallWrapper_a920 on the sub-object at obj+0x3FB8, then dispatches the 'Select Circuit' or 'Multiplayer Create' prompt via LookupDispatch depending on sub_463C60. Returns 1 on the taken path, 0 when the enable flag is clear. Called by sub_485B90.
    // ASSIGNMENT: Initialize the default result to 0. [source:raw]
    // GUARD: Read the enable flag byte at obj+0xC5 (197) through the primary pointer at this+0x0; if zero the function returns 0 immediately. [field:this:0x00000000, field:obj:0x000000C5, abi:lead, source:raw]
    // ASSIGNMENT: Set championship mode dword_7D0410 to 5. [global:0x007D0410, source:raw]
    // GUARD: Clamp the mode value: if dword_7D0418 <= 5 then take dword_7D041C when it is < 5 (otherwise leave 5); else take dword_7D0418 as the override. [global:0x007D0410, global:0x007D0418, global:0x007D041C, source:raw]
    // ASSIGNMENT: Set global flag byte_7D0F94 to 1. [global:0x007D0F94, source:raw]
    // CALL: Call SingleFunctionCallWrapper_a920 with the sub-object pointer stored at obj+0x3FB8 (16312), reached through the primary pointer at this+0x0. [callee:0x0057A920, field:obj:0x00003FB8, field:this:0x00000000, source:raw]
    // CALL: When sub_463C60(this) returns non-zero, call LookupDispatch(aSelectcircuitp, -1) to show the 'Select Circuit' prompt. [callee:0x00463C60, callee:0x00497940, global:0x005C65EC, source:raw]
    // CALL: When sub_463C60(this) returns zero, call LookupDispatch(aMultiplayerCre, -1) to show the 'Multiplayer Create' prompt. [callee:0x00497940, global:0x005C6600, source:raw]
    // RETURN: Return 1 after entering the mode; caller sub_485B90 consumes the outcome. [function:0x00463BC0, caller:0x00485B90, source:raw]

    // Conservative worker pseudocode:
    //   char EnterMultiplayerOrCircuitSelection(void* this) {
    //     if (!*(BYTE*)(*(DWORD*)this + 197)) return 0;
    //     dword_7D0410 = 5;
    //     if (dword_7D0418 <= 5) { if (dword_7D041C < 5) dword_7D0410 = dword_7D041C; }
    //     else dword_7D0410 = dword_7D0418;
    //     byte_7D0F94 = 1;
    //     SingleFunctionCallWrapper_a920(*(DWORD*)(*(DWORD*)this + 16312));
    //     if (sub_463C60(this)) LookupDispatch(aSelectcircuitp, -1);
    //     else LookupDispatch(aMultiplayerCre, -1);
    //     return 1;
    //   }
    // UNRESOLVED: Meaning of the enable flag at obj+0xC5 and identity of the object class are unknown.
    // UNRESOLVED: dword_7D0418 / dword_7D041C are timeout or mode override sources whose exact semantics are not established here.
    // UNRESOLVED: dword_7CD8C0 appears in the packet globals as read but is not directly referenced in the raw source text; likely consumed transitively by LookupDispatch.
    // UNRESOLVED: Sub-object semantics of obj+0x3FB8 and behavior of sub_463C60 are not visible in this packet.
}
