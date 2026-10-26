// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485510
// Canonical corpus name: ConstructorWithVTableAndSubInit_5510
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithVTableAndSubInit_5510_00485510.c

void UnknownObject::ConstructorWithVTableAndSubInit()
{
    // Destructor/cleanup for an unknown object with vtable off_5AB4A0. Sets this[0] to the vtable, runs common vtable/cleanup handling via InitWithVTableCleanup, then frees the object memory through FreeWrapper_7bcf when the deleting flag a2 has bit 0 set. Returns this unchanged.
    // ASSIGNMENT: Write the object vtable pointer off_5AB4A0 into this[0] (offset 0x0). [field:this:0x00000000, global:0x005AB4A0, source:raw]
    // CALL: Call InitWithVTableCleanup with this as the __thiscall receiver to run the common vtable/cleanup handling. [callee:0x00487250, source:raw]
    // GUARD: Guard on the deleting flag a2: when (a2 & 1) != 0 the object memory is freed; otherwise this is returned without freeing. [source:raw]
    // CALL: Call FreeWrapper_7bcf with this to release the object allocation when the deleting flag is set. [callee:0x00587BCF]
    // RETURN: Return this, keeping the object pointer valid as required by the scalar-deleting-destructor convention. [function:0x00485510, source:raw]

    // Conservative worker pseudocode:
    //   LPVOID* ConstructorWithVTableAndSubInit(LPVOID* this, char a2) {
    //     *this = &off_5AB4A0;
    //     InitWithVTableCleanup(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The object class that owns vtable off_5AB4A0 is not evidenced in this packet; the owner is UnknownObject.
    // UNRESOLVED: The exact teardown performed inside InitWithVTableCleanup (0x00487250) is not evidenced here.
}
