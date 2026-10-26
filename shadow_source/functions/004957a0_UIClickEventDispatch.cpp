// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004957A0
// Canonical corpus name: UIClickEventDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIClickEventDispatch_004957a0.c

void UnknownObject::UIClickEventDispatch()
{
    // UI event dispatch: iterates a2 WORD-sized event codes at a3. Event 1 resolves a handler string through the chain this+0x18 -> this+0x68 -> +0x60; event 28 resolves the handler string through the same chain to +0x58. A null handler string falls back to global byte_5EA438, then sub_4988D0 is invoked with the resolved string. Finally forwards (this, a2, a3, a4) to virtual slot 8 (vtable offset 32) of the widget.
    // LOOP: Loop over i in [0, a2), reading each event as a WORD at a3 + 2*i. [source:raw]
    // GUARD: Guard: event code == 1 selects the left-click/select handler path. [source:raw]
    // GUARD: Guard: event code == 28 selects the alternate handler path. [source:raw]
    // ASSIGNMENT: Read v9 = this[6] (pointer at this+0x18) as the intermediate handler object. [field:this:0x00000018]
    // GUARD: Guard on the intermediate handler pointer v9 being non-null. [source:raw]
    // ASSIGNMENT: Read v10 = *(v9 + 80), the manager/handler pointer held at this+0x68. [field:this:0x00000068]
    // GUARD: Guard on the manager/handler pointer v10 being non-null. [source:raw]
    // ASSIGNMENT: Event 1 path: v8 = *(v10 + 96), the handler string at *(this+0x68)+0x60. [field:*(this+0x68):0x00000060]
    // ASSIGNMENT: Event 28 path: v8 = *(v7 + 88), the handler string at *(this+0x68)+0x58. [field:*(this+0x68):0x00000058]
    // ASSIGNMENT: Fallback: if the resolved handler string v8 is null, use global byte_5EA438. [global:0x005EA438]
    // CALL: Dispatch the resolved handler string: sub_4988D0(v8). [callee:0x004988D0]
    // CALL: Forward (this, a2, a3, a4) through virtual slot 8: (*(*this + 32))(this, a2, a3, a4); the slot is read from the vtable pointer at this+0x0 (field obj+0x20). [field:obj:0x00000020, field:this:0x00000000]
    // RETURN: Return the result of the forwarded virtual call. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4957A0(_DWORD *this, int a2, int a3, int a4) {
    //     for (int i = 0; i < a2; ++i) {
    //       int ev = *(WORD*)(a3 + 2*i);
    //       char *v8 = 0;
    //       int handler = this[6];
    //       if (ev == 1 && handler) {
    //         int mgr = *(DWORD*)(handler + 80);
    //         if (mgr) { v8 = *(char**)(mgr + 96); if (!v8) v8 = byte_5EA438; sub_4988D0(v8); }
    //       } else if (ev == 28 && handler) {
    //         int mgr = *(DWORD*)(handler + 80);
    //         if (mgr) { v8 = *(char**)(mgr + 88); if (!v8) v8 = byte_5EA438; sub_4988D0(v8); }
    //       }
    //     }
    //     return ((int (__thiscall *)(_DWORD*, int, int, int))*this + 32)(this, a2, a3, a4);
    //   }
    // UNRESOLVED: Meaning of event codes 1 and 28 is caller-side; the exact UI behavior performed by sub_4988D0 with the resolved string is not derivable here.
    // UNRESOLVED: The vtable slot-8 virtual forwarding target and the owner widget class are unresolved.
}
