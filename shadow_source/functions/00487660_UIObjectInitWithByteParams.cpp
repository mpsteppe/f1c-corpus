// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487660
// Canonical corpus name: UIObjectInitWithByteParams
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIObjectInitWithByteParams_00487660.c

void UnknownObject::UIObjectInitWithByteParams()
{
    // UI list-box node initialization. Calls base setup ShortComputation_5e30, stores two byte parameters a2 and a3 at this+0xE0 and this+0xE1, and installs the ListBoxNode vtable (off_5ABA18) at this+0x0. Returns this. Called by sub_493FC0.
    // CALL: Invoke initial setup ShortComputation_5e30 on this [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Store byte parameter a2 (state/enable flag) at this+0xE0 [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Set vtable pointer at this+0x0 to &off_5ABA18 (ListBoxNode vtable) [field:this:0x00000000, global:0x005ABA18, source:raw]
    // ASSIGNMENT: Store byte parameter a3 (additional state flag) at this+0xE1 [field:this:0x000000E1, source:raw]
    // RETURN: Return this as the initialized object [function:0x00487660, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall UIObjectInitWithByteParams(void* this, char a2, char a3) {
    //     ShortComputation_5e30(this);
    //     *(char*)(this + 0xE0) = a2;
    //     *(void**)this = &off_5ABA18;
    //     *(char*)(this + 0xE1) = a3;
    //     return this;
    //   }
    // UNRESOLVED: Exact class of the UI list-box node and the meaning of the two byte parameters are not established.
    // UNRESOLVED: The role of ShortComputation_5e30 within this node's base class is not grounded here.
}
