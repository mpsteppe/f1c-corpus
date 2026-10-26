// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485690
// Canonical corpus name: sub_485690
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_485690_00485690.c

void UnknownObject::Dtor_5A9870()
{
    // Scalar-deleting destructor for an object of an unknown class whose vtable is off_5A9870. Writes this+0x0 to the vtable pointer &off_5A9870, calls the common cleanup dispatcher InitWithVTableCleanup (0x00487250) with this as the __thiscall receiver, then when the deleting flag a2 has bit 0 set releases the object memory via FreeWrapper_7bcf (0x00587BCF). Returns this unchanged, matching the MSVC scalar-deleting-destructor convention.
    // ASSIGNMENT: Write the class vtable pointer &off_5A9870 into this+0x0 (the object's vtable slot). [field:this:0x00000000, global:0x005A9870, source:raw]
    // CALL: Call InitWithVTableCleanup (0x00487250) with this as the __thiscall receiver to run the common destructor/cleanup path, resetting the vtable and releasing sub-objects. [callee:0x00487250, field:this:0x00000000, abi:lead, source:raw]
    // GUARD: Guard on the deleting flag a2: when (a2 & 1) != 0 the object memory is freed; otherwise this is returned without freeing. [source:raw]
    // CALL: Call FreeWrapper_7bcf (0x00587BCF) with this to release the object allocation when the deleting flag is set. [callee:0x00587BCF, abi:lead, source:raw]
    // RETURN: Return this, keeping the object pointer valid as required by the scalar-deleting destructor convention. [function:0x00485690, source:raw]

    // Conservative worker pseudocode:
    //   void* Dtor_5A9870(void* this, char a2) {
    //     *(void**)this = &off_5A9870;
    //     InitWithVTableCleanup(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The object class owning vtable off_5A9870 is not evidenced in this packet; owner remains UnknownObject.
    // UNRESOLVED: InitWithVTableCleanup's internal per-class cleanup work is outside this function and not described by packet evidence.
}
