// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E9E0
// Canonical corpus name: UIStructInit_e9e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIStructInit_e9e0_0048e9e0.c

void UnknownObject::UIStructInit()
{
    // Constructor-style initializer for a base UI control struct. Stores a vtable pointer (off_5A443C) at offset 0, sets a -1 sentinel at offset 8, zeroes offset 4 and offsets 0xC..0x28, then calls StringCopyWithBufferRealloc on the global buffer byte_5EA438 (default directory string) and returns this.
    // ASSIGNMENT: Initialize this+0x4 to 0 [field:this:0x00000004]
    // ASSIGNMENT: Initialize this+0x8 to sentinel -1 (unset index) [field:this:0x00000008]
    // ASSIGNMENT: Install vtable pointer off_5A443C at this+0x0 [field:this:0x00000000, global:0x005A443C]
    // ASSIGNMENT: Zero this+0xC (initialized rectangle/dimension field) [field:this:0x0000000C]
    // ASSIGNMENT: Zero this+0x10 [field:this:0x00000010]
    // ASSIGNMENT: Zero this+0x14 [field:this:0x00000014]
    // ASSIGNMENT: Zero this+0x18 [field:this:0x00000018]
    // ASSIGNMENT: Zero this+0x1C [field:this:0x0000001C]
    // ASSIGNMENT: Zero this+0x20 [field:this:0x00000020]
    // ASSIGNMENT: Zero this+0x24 [field:this:0x00000024]
    // ASSIGNMENT: Zero this+0x28 [field:this:0x00000028]
    // CALL: Copy default directory string from global buffer byte_5EA438, reallocating the destination buffer via StringCopyWithBufferRealloc [callee:0x00566650, global:0x005EA438]
    // RETURN: Return this (fluent constructor-style return) [source:raw]

    // Conservative worker pseudocode:
    //   this->vtable = off_5A443C;
    //   this->field4 = 0;
    //   this->field8 = -1;
    //   this->fieldC = 0;
    //   this->field10 = 0;
    //   this->field14 = 0;
    //   this->field18 = 0;
    //   this->field1C = 0;
    //   this->field20 = 0;
    //   this->field24 = 0;
    //   this->field28 = 0;
    //   StringCopyWithBufferRealloc(byte_5EA438);
    //   return this;
    // UNRESOLVED: Semantics of the string copied from byte_5EA438 and the meaning of the zeroed rectangle-like field block are not determined
    // UNRESOLVED: Return value of StringCopyWithBufferRealloc is discarded; its contract is unknown
}
