// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005626B0
// Canonical corpus name: StackBufferZeroInitWithCallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StackBufferZeroInitWithCallback_005626b0.c

void UnknownObject::StackBufferZeroInitWithCallback()
{
    // Path/file-name helper (thiscall): builds a 1400-byte stack buffer whose first byte is copied from the global byte_5EA438 and whose remaining 1399 bytes are zeroed, then invokes a callback held at this + 0xC8 passing the buffer, its length 1400, and the argument stored at this + 0x100 so the callback populates the buffer. The populated buffer is then handed to sub_562710 which composes the final path into the output buffer buf. Called by the file-path name lookup path.
    // ASSIGNMENT: Seed the stack buffer's first byte from byte_5EA438[0]. [global:0x005EA438, source:raw]
    // ASSIGNMENT: Zero the remaining 1399 bytes of the 1400-byte stack buffer via memset. [source:raw]
    // CALL: Call the indirect callback at this + 0xC8 with (buffer, 1400, *(this + 0x100)) to fill the buffer. [field:this:0x000000C8, field:this:0x00000100, source:raw]
    // CALL: Delegate to sub_562710(buf, buffer) to compose the final path into the caller-supplied output buffer. [callee:0x00562710, source:raw]
    // RETURN: Return the result of sub_562710. [source:raw]
    // CALL: Called by FilePathNameLookup (0x005622C0) to resolve a path using the this-object's resolver callback. [caller:0x005622C0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5626B0(int this, char *out) {
    //     char buf[1400];
    //     buf[0] = byte_5EA438[0];
    //     memset(&buf[1], 0, 1399);
    //     (*(void (__fastcall **)(char*, int, int))(this + 0xC8))(buf, 1400, *(int*)(this + 0x100));
    //     return sub_562710(out, buf);
    //   }
    // UNRESOLVED: Meaning of global byte_5EA438 (its first byte seeds the buffer) is not established.
    // UNRESOLVED: Purpose of the callback at this + 0xC8 and the argument at this + 0x100 depend on the owning object type.
    // UNRESOLVED: What path composition sub_562710 performs is only known by name.
}
