// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057F2B0
// Canonical corpus name: NetworkSessionStart
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkSessionStart_0057f2b0.c

void UnknownObject::NetworkSessionStart()
{
    // Network session start: resolves the sub-object at byte offset 0x940 of the session object, queries it through its vtable entry +12, zeroes a 768-byte config buffer, fills it through the sub-object vtable entry +16, obtains a connection object through the main vtable entry +88, configures socket parameters, executes the single config function, then either sets a default flag (a2 == -1) or dispatches vtable entry +12 on the connection sub-state with a2, and finally returns the result of VTableDispatchWithConditionalCall.
    // ASSIGNMENT: Resolve the sub-object pointer: v3 = this + 592 (byte offset 0x940). [field:this:0x00000940, source:raw]
    // CALL: Query the sub-object through its vtable entry +12 (field at this+0x940 plus 0xC): v4 = (this[592] + 12)(this + 592). [field:this:0x0000094C, source:raw]
    // ASSIGNMENT: Reset the session config state: v9[0] = 0, v8 = 0, v10 = 0. [source:raw]
    // CALL: Fill the config buffer through the sub-object vtable entry +16 (field *(this+0x940) + 0x10): (v5 + 16)(v3, v9, v4, &v8). [field:*(this+0x940):0x00000010, source:raw]
    // CALL: Obtain the connection object through the main vtable entry +88 (field obj + 0x58): v6 = (*this + 88)(this). [field:obj:0x00000058, field:this:0x00000000, source:raw]
    // CALL: Configure connection object socket parameters via sub_586800(v6, 0, 10, 1, 2, -1). [callee:0x00586800, source:raw]
    // CALL: Execute the single session config function via SingleFunctionCallWrapper_6a00((int)v9, v8). [callee:0x00586A00, source:raw]
    // GUARD: Session mode dispatch: when a2 == -1, set the byte at v6[18] + 4 to 1 (default/free mode); otherwise call vtable entry +12 on v6[18] passing a2. [source:raw]
    // CALL: Dispatch the configured session through VTableDispatchWithConditionalCall(this, (int)v6) and return its result. [callee:0x00585380, source:raw]

    // Conservative worker pseudocode:
    //   v3 = this + 592;
    //   v4 = (*(int(__thiscall **)(int*))(this[592] + 12))(this + 592);
    //   v9[0] = 0; v8 = 0; v10 = 0;
    //   (*(void(__thiscall **)(int*, _BYTE*, int, int*))(*v3 + 16))(v3, v9, v4, &v8);
    //   v6 = (_DWORD*)(*(int(__thiscall **)(int*))(*this + 88))(this);
    //   sub_586800(v6, 0, 10, 1, 2, -1);
    //   SingleFunctionCallWrapper_6a00((int)v9, v8);
    //   if (a2 == -1) *(_BYTE*)(v6[18] + 4) = 1;
    //   else (*(void(__thiscall **)(_DWORD, int))(*(_DWORD*)v6[18] + 12))(v6[18], a2);
    //   return VTableDispatchWithConditionalCall(this, (int)v6);
    // UNRESOLVED: SEH_57F2B0 (0x0059CA3B) is flagged by packet facts as read-only but appears nowhere in the raw decompiled source; it is likely SEH registration metadata rather than an explicit data access.
    // UNRESOLVED: Identities of the three indirect vtable callees (+12, +16, +88) are not resolved; only the call sites are asserted.
    // UNRESOLVED: Meaning of the socket parameter tuple (0, 10, 1, 2, -1) passed to sub_586800 is not established here.
}
