// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C92B0
// Canonical corpus name: ObjectPropertySetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectPropertySetter_004c92b0.c

void UnknownObject::ObjectPropertySetter()
{
    // thiscall setter: stores a2 into this[7] (this+0x1C), then obtains an object from StateIndexedFieldGetter (0x004C9260). When the object is non-null, zeroes a local 3-dword buffer and dispatches an indirect thiscall through vtable slot +4 with arguments (object, 2, v4+8, zeroed buffer, a3, 1065353216, 1), returning its result; otherwise returns the null object.
    // ASSIGNMENT: Store a2 into this[7] at offset 0x1C [field:this:0x0000001C, source:raw]
    // CALL: Call StateIndexedFieldGetter (0x004C9260) on this and capture the returned object pointer [callee:0x004C9260, source:raw]
    // GUARD: Guard on the returned object: when null, return it immediately [function:0x004C92B0, source:raw]
    // ASSIGNMENT: Read the object's vtable pointer as the first dword of the StateIndexedFieldGetter result [function:0x004C92B0, source:raw]
    // ASSIGNMENT: Zero the local 3-dword buffer v6 with memset [source:raw]
    // CALL: Indirect thiscall through vtable slot +4 with arguments (result, 2, v4+8, v6, a3, 1065353216, 1) [source:raw]
    // RETURN: Return the result of the indirect vtable call on the non-null path [function:0x004C92B0, source:raw]

    // Conservative worker pseudocode:
    //   int *__thiscall sub_4C92B0(_DWORD *this, int a2, int a3) {
    //     this[7] = a2;
    //     int *result = StateIndexedFieldGetter(this);
    //     if (result) {
    //       _DWORD v6[3] = {0};
    //       return (*(vtable_slot(result, 4)))(result, 2, v4 + 8, v6, a3, 1065353216, 1);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Indirect call target at vtable slot +4 cannot be resolved statically; the role of the second argument 2 and of literal 1065353216 is unknown.
    // UNRESOLVED: v4 is uninitialized in the decompilation yet flows into the indirect-call argument 'v4 + 8'; its value is not recoverable from this packet.
    // UNRESOLVED: ABI legacy name 'Object_Property_Setter' and the prelabel 'structural twin of FieldSetterTrigger (0049ed00)' are DERIVED, not confirmed by this packet.
}
