// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00488180
// Canonical corpus name: UITextDisplayConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UITextDisplayConstructor_00488180.c

void UnknownObject::UITextDisplayConstructor()
{
    // UI text display object constructor. Calls base setup ShortComputation_5e30, initializes the sub-object at this+0xE0 via sub_499B10, installs the text display vtable (off_5ABB78) at this+0x0, sets the enable/visible flag at this+0x114 to 1, and returns this. Called by UIObjectConstructor_7ea0, UIObjectConstructor_8e10, ObjectInitWithVTable and sub_493FC0.
    // CALL: Invoke base setup ShortComputation_5e30 on this [callee:0x00485E30, source:raw]
    // CALL: Initialize the sub-object at this+0xE0 via sub_499B10 [callee:0x00499B10, source:raw]
    // ASSIGNMENT: Set vtable pointer at this+0x0 to &off_5ABB78 (text display vtable) [field:this:0x00000000, global:0x005ABB78, source:raw]
    // ASSIGNMENT: Set the enable/visible flag byte at this+0x114 to 1 (active) [field:this:0x00000114, source:raw]
    // RETURN: Return this as the constructed object [function:0x00488180, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall UITextDisplayConstructor(void* this) {
    //     ShortComputation_5e30(this);
    //     sub_499B10((char*)this + 0xE0);
    //     *(void**)this = &off_5ABB78;
    //     *(char*)(this + 0x114) = 1;
    //     return this;
    //   }
    // UNRESOLVED: The identity and purpose of the sub-object initialized at this+0xE0 by sub_499B10 are not established (no field evidence ref exists for 0xE0 in this packet).
    // UNRESOLVED: The concrete class of the text display object is not established.
}
