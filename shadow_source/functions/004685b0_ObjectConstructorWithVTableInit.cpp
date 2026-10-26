// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004685B0
// Canonical corpus name: FunctionCallWrapper_85b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_85b0_004685b0.c

void UnknownObject::ObjectConstructorWithVTableInit()
{
    // Constructor-style initializer for a heap object created by SeasonDatabaseObjectFactory. Calls base initializer sub_4893C0, zeroes a command/state field (this[93], +0x174), sets a subtype/ID field (this[94], +0x178) to the -1 sentinel, installs the vtable pointer off_59F718 at offset 0, resets a byte via ByteSetterAt0xe0, and returns this.
    // CALL: Invoke the base initializer sub_4893C0 on the object being constructed. [callee:0x004893C0]
    // ASSIGNMENT: Zero the command/state field this[93] at byte offset 0x174. [field:this:0x00000174]
    // ASSIGNMENT: Set the sub-type/ID field this[94] at byte offset 0x178 to the -1 sentinel (UINT_MAX in the unsigned dword view). [field:this:0x00000178]
    // ASSIGNMENT: Install the vtable pointer: *this = &off_59F718. [field:this:0x00000000, global:0x0059F718]
    // CALL: Reset a byte in some global/context to 0 via ByteSetterAt0xe0. [callee:0x0048A3B0]
    // RETURN: Return the constructed object pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_4685B0(_DWORD *this) {
    //     sub_4893C0();
    //     this[93] = 0;
    //     this[94] = -1;
    //     *this = &off_59F718;
    //     ByteSetterAt0xe0(0);
    //     return this;
    //   }
    // UNRESOLVED: Class identity and the meaning of the +0x174 and +0x178 fields are not established; the -1 sentinel's semantics depend on the enclosing subsystem.
    // UNRESOLVED: Which global/context ByteSetterAt0xe0 resets is not visible in the raw source.
}
