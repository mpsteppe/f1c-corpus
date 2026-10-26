// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00554660
// Canonical corpus name: FloatStateSetterWithChangeNotification
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatStateSetterWithChangeNotification_00554660.c

void UnknownObject::FloatStateSetterWithChangeNotification()
{
    // Setter for the float state field this+0x40 (this[16]). If a2 differs from the current value, it stores a2 and dispatches a change notification through the global object at dword_8B89A0: an indirect stdcall to that object's vtable slot +252, passing the object id from this+0, the constant 19 as the state selector, and the new value this[16] reinterpreted as int. No notification and no write occur when the value is unchanged.
    // GUARD: Compare a2 against the stored float this[16] (this+0x40); proceed only if they differ. [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Store the new value: this[16] = a2. [field:this:0x00000040, source:raw]
    // CALL: Indirectly call the vtable slot +252 of the global object dword_8B89A0 (stdcall), passing dword_8B89A0, the object id read from this+0, the constant 19, and the new state value this[16] as int - the change notification. [global:0x008B89A0, field:this:0x00000000, field:this:0x00000040, source:raw]

    // Conservative worker pseudocode:
    //   void sub_554660(float* this, float a2) {
    //     if (a2 != this[16]) {
    //       this[16] = a2;
    //       (vtable[252])(dword_8B89A0, *(int*)this, 19, (int)this[16]);
    //     }
    //   }
    // UNRESOLVED: The meaning of the constant 19 (state selector) and the identity and contract of the vtable+252 callback on dword_8B89A0 are unknown.
    // UNRESOLVED: dword_8B89A0 is named GameDeviceObject only in prose (DERIVED); this packet carries no type evidence for the global.
}
