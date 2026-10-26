// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00502BF4
// Canonical corpus name: DualVTableDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualVTableDestructor_00502bf4.c

void UnknownObject::DualVTableDestructor()
{
    // Destructor dispatcher for an object owning two vtable-backed children. Reads the secondary child pointer from this+4; if non-NULL, calls the child's vtable entry 0 with argument 1 (deleting destructor) and keeps the return value. Then, if the primary child pointer *this is non-NULL, calls its vtable entry 0 with argument 1 and returns that result; otherwise returns the stored secondary result.
    // ASSIGNMENT: Load secondary child pointer: v2 = this[1] (value at this+0x4). [field:this:0x00000004, source:raw]
    // GUARD: Guard on the secondary child pointer v2 being non-NULL. [field:this:0x00000004, source:raw]
    // CALL: Indirect call through the secondary child vtable entry 0, (*v2[0])(v2, 1): destructor call with flag 1. [field:*(this+0x4):0x00000000, source:raw]
    // GUARD: Guard on the primary child pointer *this being non-NULL. [field:this:0x00000000, source:raw]
    // CALL: Indirect call through the primary child object's vtable pointer *this, dispatching to vtable entry 0 as (**this)(*this, 1): destructor call with flag 1; its result is returned. [field:obj:0x00000000, field:*(obj+0x0):0x00000000, source:raw]
    // RETURN: Return the primary child destructor result, or the secondary child destructor result when the primary child is NULL. [field:*(obj+0x0):0x00000000, field:*(this+0x4):0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int sub_502BF4(_DWORD* this) {
    //     _DWORD* second = this[1];
    //     int result;
    //     if (second) result = (*(int (__thiscall **)(_DWORD, int))second)(second, 1);
    //     if (*this) return (*(int (__thiscall **)(_DWORD, int))*this)(*this, 1);
    //     return result;
    //   }
    // UNRESOLVED: Identity of the two child object types and their vtable layouts is unknown.
    // UNRESOLVED: The value 1 passed as the second destructor argument is a flag whose meaning is unconfirmed (likely 'delete').
    // UNRESOLVED: No direct callee is statically recorded; both calls are indirect vtable dispatch.
}
