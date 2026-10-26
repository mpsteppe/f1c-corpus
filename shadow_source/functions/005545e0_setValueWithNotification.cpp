// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005545E0
// Canonical corpus name: SetterWithNotification
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetterWithNotification_005545e0.c

void UnknownObject::setValueWithNotification()
{
    // __thiscall setter with change notification. Guards on a2: when a2 differs from -1 and from the currently stored value this[11], it dispatches a value-change notification to the global GameDeviceObject through its vtable at +252, passing this object id (*this), field slot 11 and the new value a2, then stores a2 into this[11]. Returns the dispatch result.
    // GUARD: Skip the notification and store when a2 equals -1 (invalid/no-change sentinel) or when a2 equals the previously stored value this[11]. [source:raw, field:this:0x0000002C]
    // CALL: Read this object id from *this and call the __stdcall handler at vtable offset +252 on the GameDeviceObject global dword_8B89A0 with arguments (*this, 11, a2). [source:raw, field:this:0x00000000, global:0x008B89A0]
    // ASSIGNMENT: Store the accepted value into this[11] (byte offset 0x2C), making it the new baseline for the change guard. [source:raw, field:this:0x0000002C]
    // RETURN: Return the result of the vtable+252 dispatch; when the guard fails the uninitialized result is returned instead. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5545E0(_DWORD* this, int a2) {
    //     int result;
    //     if (a2 != -1 && a2 != this[11]) {
    //       result = GameDeviceObject->vtable[252 / 4](GameDeviceObject, *this, 11, a2);
    //       this[11] = a2;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of field slot 11 and of the object selector *this depend on the GameDeviceObject contract, which is not visible here.
    // UNRESOLVED: Return value of the vtable+252 handler is propagated but its meaning is unknown.
}
