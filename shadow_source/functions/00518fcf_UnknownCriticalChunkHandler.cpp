// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00518FCF
// Canonical corpus name: sub_518FCF
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_518FCF_00518fcf.c

void UnknownObject::UnknownCriticalChunkHandler()
{
    // Handles an unknown critical PNG chunk. First evaluates the chunk against the control byte at this+0x10C via sub_517FD0; when bit 5 (0x20) of that byte is clear it calls DoubleBufferInit with the 'unknown critical chunk' string and the processing block runs when a2 is non-zero. Inside the block it conditionally sets the done bit 0x8 on the flag register at this+0x58 (only when bit 0x4 is already set) and runs the CRC error check sub_518828 before returning.
    // CALL: Call sub_517FD0(a1, (uint8_t*)(a1 + 0x10C)) to evaluate the chunk type flags against the control byte at this+0x10C [callee:0x00517FD0, field:this:0x0000010C, source:raw]
    // GUARD: Guard: read the control byte at this+0x10C; when bit 5 (0x20) is clear, DoubleBufferInit(a1, 'unknown critical chunk') is evaluated into result and the processing block runs when a2 is non-zero [field:this:0x0000010C, callee:0x0051189C, global:0x005AFF58, source:raw]
    // GUARD: Guard: read the flag register dword at this+0x58; the done bit 0x8 is only set when bit 0x4 is already set [field:this:0x00000058, source:raw]
    // ASSIGNMENT: When the guard passes, write the flag register back to this+0x58 with bit 0x8 set (v4 | 8) [field:this:0x00000058, source:raw]
    // CALL: Run the CRC error check sub_518828(a1, a3); its return value is returned as the function result [callee:0x00518828, source:raw]
    // RETURN: Return: when the guard fails, return the DoubleBufferInit result; called from sub_5119E9 (0x005119E9) [callee:0x0051189C, caller:0x005119E9, function:0x00518FCF, source:raw]

    // Conservative worker pseudocode:
    //   int UnknownCriticalChunkHandler(int a1, int a2, unsigned int a3) {
    //     sub_517FD0(a1, (uint8_t*)(a1 + 0x10C));
    //     uint8_t ctrl = *(uint8_t*)(a1 + 0x10C);
    //     int result;
    //     if (!(ctrl & 0x20))
    //       result = DoubleBufferInit(a1, "unknown critical chunk");
    //     if ((ctrl & 0x20) || a2) {
    //       uint32_t flags = *(uint32_t*)(a1 + 0x58);
    //       if (flags & 0x4)
    //         *(uint32_t*)(a1 + 0x58) = flags | 0x8;
    //       return sub_518828(a1, a3);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The semantics of bit 5 (0x20) at this+0x10C (interpreted as a skip-error-dispatch flag from the guard structure) is DERIVED, not independently proven.
    // UNRESOLVED: sub_517FD0's exact role (chunk-type flag evaluation writing the result to this+0x10C) is inferred from the call site and its target operand.
    // UNRESOLVED: The origin and meaning of a2 (only tested for non-zero after the double-buffer guard call) are not established.
}
