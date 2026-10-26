// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587370
// Canonical corpus name: CopyBufferHeaderFieldsCallInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CopyBufferHeaderFieldsCallInit_00587370.c

void UnknownObject::CopyBufferHeaderFields()
{
    // Buffer/header copy initializer: calls BufferWriteWithParams with a pointer 4 bytes into the source object a2, then copies four header fields from a2 to this (dwords at 0x10 and 0x14, bytes at 0x18 and 0x19). Returns this.
    // CALL: Call BufferWriteWithParams with source pointer at a2+4 to write buffer data before the field copy. [callee:0x00587620, source:raw]
    // ASSIGNMENT: Copy dword field this+0x10 from a2+0x10. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Copy dword field this+0x14 from a2+0x14. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Copy byte field this+0x18 from a2+0x18. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Copy byte field this+0x19 from a2+0x19. [field:this:0x00000019, source:raw]
    // RETURN: Return this pointer. [function:0x00587370, source:raw]

    // Conservative worker pseudocode:
    //   BufferWriteWithParams(a2 + 4);
    //   this->field_0x10 = a2->field_0x10;
    //   this->field_0x14 = a2->field_0x14;
    //   this->field_0x18 = a2->field_0x18;
    //   this->field_0x19 = a2->field_0x19;
    //   return this;
    // UNRESOLVED: The buffer format written by BufferWriteWithParams and the owning struct of the copied header fields are not evidenced by the packet.
}
