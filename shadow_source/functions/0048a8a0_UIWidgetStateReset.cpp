// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048A8A0
// Canonical corpus name: UIWidgetStateReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIWidgetStateReset_0048a8a0.c

void UnknownObject::UIWidgetStateReset()
{
    // Resets widget UI state: zeros the three byte flags at this+0x144, this+0x145, this+0x146 and the dword state field this+0x148, then calls vtable method at obj+0x40 (offset 64) via stdcall with argument 0 and vtable method at obj+0x9C (offset 156) via thiscall on this; returns that call's result. Proposed name taken from the legacy ABI lead and the existing analysis fill.
    // ASSIGNMENT: Zero the three byte fields this+0x144, this+0x145 and this+0x146 (byte indexes 324-326). [field:this:0x00000144, field:this:0x00000145, field:this:0x00000146, source:raw]
    // CALL: Read the vtable pointer from this+0x0 and call vtable method at obj+0x40 (offset 64) with stdcall convention and argument 0. [field:this:0x00000000, field:obj:0x00000040, source:raw]
    // ASSIGNMENT: Zero the dword state field this+0x148 (this[82]). [field:this:0x00000148, source:raw]
    // CALL: Re-read the vtable pointer from this+0x0 and call vtable method at obj+0x9C (offset 156) with thiscall convention passing this; the return value of this call becomes the function result. [field:this:0x00000000, field:obj:0x0000009C, function:0x0048A8A0, source:raw]
    // RETURN: Return the result of the vtable call at obj+0x9C. [function:0x0048A8A0, source:raw]

    // Conservative worker pseudocode:
    //   this[324] = 0; this[325] = 0; this[326] = 0;
    //   ((void(__stdcall*)(int))(this->vtbl[0x40/4]))(0);
    //   this[82] = 0;
    //   return ((int(__thiscall*)(void*))(this->vtbl[0x9C/4]))(this);
    // UNRESOLVED: The purposes of the vtable methods at obj+0x40 (called with 0) and obj+0x9C (refresh-like) are only described by the existing analysis fill; they are not independently evidenced.
    // UNRESOLVED: The owning widget class is unknown; no caller or class evidence exists in the packet.
    // UNRESOLVED: The proposed name rests on the legacy ABI lead, which is not independently confirmed.
}
