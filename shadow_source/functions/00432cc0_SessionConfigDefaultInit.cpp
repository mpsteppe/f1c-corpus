// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432CC0
// Canonical corpus name: SessionConfigDefaultInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionConfigDefaultInit_00432cc0.c

void UnknownObject::SessionConfigDefaultInit()
{
    // Initializes a session configuration structure to defaults: copies the default application-directory string into the global buffer byte_5EA438 three times via StringCopyWithBufferRealloc and sets the field at this+0x10 to the literal 7. Unconditional; no guard branches.
    // CALL: First copy of the default directory string via StringCopyWithBufferRealloc(&byte_5EA438). [callee:0x00566650, global:0x005EA438]
    // CALL: Second copy of the default directory string via StringCopyWithBufferRealloc(&byte_5EA438). [callee:0x00566650, global:0x005EA438]
    // ASSIGNMENT: Set the field at this+0x10 to the literal 7 (session config flag/counter default). [field:this:0x00000010]
    // CALL: Third copy of the default directory string via StringCopyWithBufferRealloc(&byte_5EA438), whose result becomes the return value. [callee:0x00566650, global:0x005EA438]
    // RETURN: Return the result of the final StringCopyWithBufferRealloc call. [source:raw]

    // Conservative worker pseudocode:
    //   int SessionConfigDefaultInit(unsigned int *self) {
    //     StringCopyWithBufferRealloc(&byte_5EA438);
    //     StringCopyWithBufferRealloc(&byte_5EA438);
    //     self[4] = 7;
    //     return StringCopyWithBufferRealloc(&byte_5EA438);
    //   }
    // UNRESOLVED: The meaning of the value 7 at this+0x10 and the purpose of the repeated buffer copy are not evidenced here.
    // UNRESOLVED: Reason the copy is performed three times rather than once is unresolved.
}
