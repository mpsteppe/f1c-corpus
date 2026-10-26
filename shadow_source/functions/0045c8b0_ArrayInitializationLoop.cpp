// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C8B0
// Canonical corpus name: ArrayInitializationLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayInitializationLoop_0045c8b0.c

void UnknownObject::ArrayInitializationLoop()
{
    // Array/aggregate initializer. Always zeroes the first element (this+0x0); when the a2 init flag is non-zero, also zeroes this+0x4 through this+0x10. Then loops 104 times invoking PerElementArrayReset(this, i) per element and returns the last reset call's result.
    // ASSIGNMENT: Zero the first aggregate element at this+0x0 unconditionally. [abi:lead, field:this:0x00000000, source:raw]
    // GUARD: When the a2 init flag is non-zero, clear the following four fields this+0x4 .. this+0x10. [source:raw]
    // ASSIGNMENT: Clear the field at this+0x4 to 0. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Clear the field at this+0x8 to 0. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Clear the field at this+0xC to 0. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Clear the field at this+0x10 to 0. [field:this:0x00000010, source:raw]
    // LOOP: Loop 104 times with index i from 0 to 103, resetting each element in turn. [source:raw]
    // CALL: Invoke PerElementArrayReset (0x0045C850) on this with the current index i each iteration; the last call's return value is retained as result. [callee:0x0045C850, source:raw]
    // RETURN: Return the result of the final PerElementArrayReset call. [function:0x0045C8B0, source:raw]
    // CALL: Invoked by WrapperWithConstant (0x0045C750), RunCollisionDetectionLoop (0x0045F390), and SynchronizeWithServer (0x00464290). [caller:0x0045C750, caller:0x0045F390, caller:0x00464290, source:raw]

    // Conservative worker pseudocode:
    //   int sub_45C8B0(DWORD *this, char a2) {
    //     int result;
    //     this[0] = 0;
    //     if (a2) {
    //       this[1] = 0;
    //       this[2] = 0;
    //       this[3] = 0;
    //       this[4] = 0;
    //     }
    //     for (int i = 0; i < 104; ++i)
    //       result = PerElementArrayReset(this, i);
    //     return result;
    //   }
    // UNRESOLVED: The type of the 104-element aggregate and the meaning of the a2 init flag are not grounded by this packet.
    // UNRESOLVED: The behavior of PerElementArrayReset (0x0045C850) is not documented in this packet.
}
