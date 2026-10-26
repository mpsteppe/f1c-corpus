// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046DA20
// Canonical corpus name: DispatchChainWithVTableCalls
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DispatchChainWithVTableCalls_0046da20.c

void UnknownObject::DispatchChainWithVTableCalls()
{
    // Straight-line session/UI/input dispatch chain: sets a session type flag via sub_42D210, creates a UI element with id 30 through a vtable slot on this[16], activates it via sub_46BF10, calls the input/force-feedback helper sub_4D2450 with dword_8ACEE0, then invokes a vtable callback at slot 14 on this with parameter 1.
    // CALL: Set the session type flag: call sub_42D210 on dword_7C569C by reference with value 1 [callee:0x0042D210, global:0x007C569C, source:raw]
    // CALL: Call the vtable slot at 0x1C of the object at this[16] with id 30 to obtain a UI element object [field:*(this+0x40):0x0000001C, field:this:0x00000040]
    // CALL: Activate the obtained UI object by calling sub_46BF10 with parameter 1 [callee:0x0046BF10]
    // CALL: Call the input/force-feedback helper sub_4D2450 passing the global dword_8ACEE0 [callee:0x004D2450, global:0x008ACEE0]
    // CALL: Invoke the vtable callback at slot 14 (byte offset 0x38) on the this object vtable with parameter 1 [field:obj:0x00000038, field:this:0x00000000]
    // RETURN: Return 0 [source:raw, function:0x0046DA20]

    // Conservative worker pseudocode:
    //   sub_42D210(&dword_7C569C, 1);
    //   ui = this->vtable[16]->slot(0x1C)(this[16], 30);
    //   sub_46BF10(ui, 1);
    //   sub_4D2450(dword_8ACEE0);
    //   this->vtable[14](this, 1);
    //   return 0;
    // UNRESOLVED: The concrete type of the this object and of the UI object returned by the vtable slot call is unknown.
    // UNRESOLVED: Semantics of dword_7C569C beyond a session-type flag and of dword_8ACEE0 beyond an input/force-feedback base are not confirmed.
}
