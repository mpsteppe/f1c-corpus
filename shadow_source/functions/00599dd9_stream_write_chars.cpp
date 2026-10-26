// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599DD9
// Canonical corpus name: sub_599DD9
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_599DD9_00599dd9.c

void UnknownObject::stream_write_chars()
{
    // Writes a3 wide characters from source pointer a2 to a buffered output stream. Fast path: when the double-indirect write-buffer object referenced at this+0x20 is valid (first dword non-zero) and the available-space value read through the pointer stored at this+0x30 is positive, copies as many characters as fit in one chunk and advances the buffer position counter via DoubleIndirectCounterUpdate. Fallback path: writes one character at a time through the virtual single-character write slot (vtable pointer read from this+0, slot at vtable+4), aborting and returning the current total when that call returns 0xFFFF. Returns the total number of wide characters written.
    // ASSIGNMENT: Initialize running total v9 to 0 before the write loop. [field:obj:0x00000004, source:raw]
    // LOOP: Iterate while the remaining count a3 is greater than 0, writing one wide character (or one chunk) per pass from source pointer a2. [function:0x00599DD9, source:raw]
    // ASSIGNMENT: Load the double-indirect write-buffer object pointer stored at this+0x20 and derive the word write cursor v6 from the dword it points at. [field:this:0x00000020, source:raw]
    // GUARD: Fast chunk path requires the buffer object's first dword (reached through the pointer at this+0x20) to be non-zero and the available-space value read through the pointer stored at this+0x30 to be greater than zero. [field:this:0x00000020, field:this:0x00000030, source:raw]
    // CALCULATION: Clamp the chunk length v5 to the smaller of the remaining count a3 and the available space. [source:raw]
    // LOOP: Copy v5 wide characters from source pointer a2 into the write cursor v6, advancing both pointers. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Advance running total v9 by v5, reduce remaining count a3 by v5, and advance source pointer a2 by v5. [field:obj:0x00000004, source:raw]
    // CALL: Update the double-indirect write-buffer position counter by the chunk length v5 after the chunk copy. [callee:0x0059A428, source:raw]
    // ASSIGNMENT: Fallback single-character path: load the next wide character from a2 as the low word of v5. [source:raw]
    // CALL: Fallback: invoke the virtual single-character write slot (vtable pointer read from this+0, slot at vtable+4) with this and the character value. [field:this:0x00000000, source:raw]
    // GUARD: If the virtual single-character write returns 0xFFFF, stop the loop and return the current running total. [field:this:0x00000000, field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Fallback counters: advance source pointer a2, increment running total v9, decrement remaining count a3. [field:obj:0x00000004, source:raw]
    // RETURN: Return the total number of wide characters written (v9). [field:obj:0x00000004, function:0x00599DD9, source:raw]

    // Conservative worker pseudocode:
    //   // total = 0
    //   // while count > 0:
    //   //   if buffer object (pointer at this+0x20) has non-zero first dword and space (read via pointer at this+0x30) > 0:
    //   //     n = min(count, space)
    //   //     copy n wide chars from src to cursor
    //   //     total += n; count -= n; src += n
    //   //     DoubleIndirectCounterUpdate(n)
    //   //   else:
    //   //     ch = *src
    //   //     if virtual_putc(this, ch) == 0xFFFF: break
    //   //     src += 1; total += 1; count -= 1
    //   // return total
    // UNRESOLVED: The buffer object referenced by the pointer at this+0x20 and the space object referenced by the pointer at this+0x30 are double-indirect; their internal member offsets are not named in the packet evidence and are not asserted.
    // UNRESOLVED: The semantic role of the 0xFFFF return value of the virtual single-character write is inferred as end-of-stream; the exact meaning is not evidenced.
    // UNRESOLVED: The owning class of this method is not established; only the vtable dispatch and buffered-writer pattern suggest a stream/writer object.
}
