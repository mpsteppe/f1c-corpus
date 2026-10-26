// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005196B8
// Canonical corpus name: BufferedDataStreamWrite
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferedDataStreamWrite_005196b8.c

void UnknownObject::BufferedDataStreamWrite()
{
    // Writes data to a buffered output stream through two interface vtables. Loads a descriptor object from this+0x180; when its one-time init flag (byte at descriptor offset 48) is clear it calls the init entry (vtable at this+0x184, entry +12) and returns early if that call reports failure. Records the buffer size limit from this+0x114 and dispatches the payload through the write entry (vtable at this+0x188, entry +4). When the descriptor fill counter at offset 52 reaches the size limit it resets both the init flag and the fill counter, then returns the size limit value.
    // ASSIGNMENT: Load the stream descriptor object pointer into v5 from this[96] (offset 0x180). [field:this:0x00000180, source:raw]
    // GUARD: Guard on the descriptor init flag (byte at descriptor offset 48): only when it is zero does the one-time initialization path run. [field:this:0x000001B0, source:raw]
    // CALL: Call the interface init entry (vtable at this+0x184, entry +12) with (this, descriptor buffer at offset 8); guard on its return: a zero result is returned immediately without further writes. [field:this:0x00000184, source:raw]
    // ASSIGNMENT: Set the descriptor init flag (offset 48) to 1 after successful initialization. [field:this:0x000001B0, source:raw]
    // ASSIGNMENT: Load the buffer size limit into v7 from this[69] (offset 0x114). [field:this:0x00000114, source:raw]
    // CALL: Dispatch the write through the interface write entry (vtable at this+0x188, entry +4) with (this, descriptor buffer at offset 8, fill counter at offset 52, the size limit, and the three caller arguments). [field:this:0x00000188, field:this:0x00000114, source:raw]
    // STATE_TRANSITION: When the fill counter (descriptor offset 52) reaches or passes the size limit, reset the init flag to 0 and the fill counter to 0 so the buffer restarts its fill cycle. [field:this:0x000001B0, field:this:0x000001B4, field:this:0x00000114, source:raw]
    // RETURN: Return v7, the recorded buffer size limit. [source:raw]

    // Conservative worker pseudocode:
    //   v5 = this[0x180];
    //   if (*(byte*)(v5 + 48) == 0) {
    //     if (!(*(this[0x184] + 12))(this, v5 + 8)) return 0;
    //     *(byte*)(v5 + 48) = 1;
    //   }
    //   v7 = this[0x114];
    //   (*(this[0x188] + 4))(this, v5 + 8, v5 + 52, this[0x114], a2, a3, a4);
    //   if (*(dword*)(v5 + 52) >= v7) {
    //     *(byte*)(v5 + 48) = 0;
    //     *(dword*)(v5 + 52) = 0;
    //   }
    //   return v7;
    // UNRESOLVED: Fields this+0x18C and this+0x190 are adjacent pointer cells recorded as fields but not dereferenced by this function; whether they are further interface entries or additional descriptors is unknown.
    // UNRESOLVED: The stream descriptor object type and the two interface vtables are not identified by packet evidence.
    // UNRESOLVED: The exact meaning of the fill counter reaching the size limit (flush versus discard) is not established.
}
