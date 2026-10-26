// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00494470
// Canonical corpus name: UIDestructorWithSelfFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIDestructorWithSelfFree_00494470.c

void UnknownObject::UIDestructorWithSelfFree()
{
    // UI object destructor: installs the vtable pointer off_5AC830 into the object, calls the base UI destructor sub_485EB0, and optionally frees the object allocation via FreeWrapper_7bcf when flag a2 has bit 0 set. No static callers on the tick path.
    // ASSIGNMENT: Install the vtable/interface pointer: *this = &off_5AC830. [field:this:0x00000000, global:0x005AC830, source:raw]
    // CALL: Call the base UI object destructor sub_485EB0(this). [callee:0x00485EB0, source:raw]
    // GUARD: When (a2 & 1) != 0 the object allocation is freed; otherwise the object is left for the caller to manage. [source:raw]
    // CALL: Call FreeWrapper_7bcf(this) to release the object allocation. [callee:0x00587BCF, source:raw]
    // RETURN: Return the object pointer. [source:raw]

    // Conservative worker pseudocode:
    //   *this = &off_5AC830;
    //   sub_485EB0(this);
    //   if ((a2 & 1) != 0) FreeWrapper_7bcf(this);
    //   return this;
}
