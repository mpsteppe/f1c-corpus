// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494470
// Canonical corpus name: UIDestructorWithSelfFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIDestructorWithSelfFree_00494470.c

void UnknownObject::UIDestructorWithSelfFree()
{
    // UI object destructor with optional self-free. Always installs the vtable pointer off_5AC830 at this+0x0 and runs the base UI destructor sub_485EB0. If the flag parameter has bit 0 set, additionally frees the object allocation via FreeWrapper_7bcf. Returns this.
    // ASSIGNMENT: Install the object vtable: *this = &off_5AC830 (write to field this+0x0). [field:this:0x00000000, global:0x005AC830, source:raw]
    // CALL: Call the base UI object destructor sub_485EB0(this). [callee:0x00485EB0, source:raw]
    // GUARD: Guard on (a2 & 1) != 0; when set, the object allocation is freed (self-free). [source:raw]
    // CALL: Call FreeWrapper_7bcf(this) to release the object allocation. [callee:0x00587BCF, source:raw]
    // RETURN: Return this (the pointer to the (possibly freed) object). [source:raw]

    // Conservative worker pseudocode:
    //   LPVOID* UIDestructorWithSelfFree(LPVOID* this, char flags) {
    //     *this = &off_5AC830;
    //     sub_485EB0(this);
    //     if (flags & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Role of the vtable at off_5AC830 and which UI class this destructor belongs to are unknown; owner is not identified.
    // UNRESOLVED: Returning this after a conditional self-free implies the caller may rely on the pointer regardless of free.
}
