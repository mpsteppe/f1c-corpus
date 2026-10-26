// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051A968
// Canonical corpus name: AudioBufferReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioBufferReset_0051a968.c

void UnknownObject::AudioBufferReset()
{
    // Resets audio decode buffer state: accumulates the pending byte count (decode state +20, at this+0x1A8) divided by 8 into the output total (*(a1[100]+88), at this+0x1E8), then zeroes that byte counter. Invokes the output buffer's callback at *(a1[100]+8) passing a1; on success zeroes a per-channel DWORD array at decode state +32 (this+0x1B4) for this+0x120 elements, copies the reference value this+0xFC into decode state +48 (this+0x1C4), clears the ready byte at decode state +24 (this+0x1AC), and returns 1; otherwise returns the callback's falsy result.
    // CALCULATION: Accumulate (v1+20)/8 into the output total at *(a1[100]+88), moving the pending byte count from decode state +20 (this+0x1A8) into the caller's total (this+0x1E8). [field:this:0x00000194, field:this:0x000001A8, field:this:0x00000190, field:this:0x000001E8, source:raw]
    // ASSIGNMENT: Set the byte counter at decode state +20 (this+0x1A8) to 0 after accumulating it. [field:this:0x000001A8, source:raw]
    // CALL: Call the callback function pointer at *(a1[100]+8) (output buffer at this+0x190) with a1 as its argument; its truthy result gates the reset work. [field:this:0x00000190, source:raw]
    // GUARD: If the callback result is truthy and the channel count at this+0x120 is greater than 0, zero the per-channel array. [guard:0, field:this:0x00000120, source:raw]
    // LOOP: Zero v3 DWORDs starting at decode state +32 (this+0x1B4), one per channel, while v3 < a1[72] (channel count at this+0x120). [field:this:0x000001B4, field:this:0x00000120, source:raw]
    // ASSIGNMENT: Set decode state +48 (this+0x1C4) to the reference value a1[63] (this+0xFC). [field:this:0x000001C4, field:this:0x000000FC, source:raw]
    // ASSIGNMENT: Clear the ready byte at decode state +24 (this+0x1AC) to 0. [field:this:0x000001AC, source:raw]
    // RETURN: Return 1 on the success path after resetting decode state. [function:0x0051A968, source:raw]
    // RETURN: Return the callback's falsy result unchanged when the callback did not succeed. [function:0x0051A968, source:raw]

    // Conservative worker pseudocode:
    //   int AudioBufferReset(_DWORD *a1) {
    //       _DWORD *state = (_DWORD *)a1[101];
    //       *(int *)(a1[100] + 88) += *(int *)(state + 5) / 8;
    //       *(int *)(state + 5) = 0;
    //       int result = (*(int (__cdecl **)(_DWORD *))(a1[100] + 8))(a1);
    //       if (result) {
    //           for (int i = 0; i < a1[72]; ++i) state[8 + i] = 0;
    //           state[12] = a1[63];
    //           *(BYTE *)((BYTE *)state + 24) = 0;
    //           return 1;
    //       }
    //       return result;
    //   }
    // UNRESOLVED: The callback target at *(a1[100]+8) is an indirect call through the output buffer; its concrete function address is not evidenced in this packet.
    // UNRESOLVED: Field this+0x198 is read (per the packet field table) but not referenced in the decompiled source; its use is unknown.
    // UNRESOLVED: The caller context (0x0051A9C6) is recorded in the packet but this function contains no direct call to it; the relationship is caller-side only.
    // UNRESOLVED: Whether the division by 8 implies byte-per-sample or a fixed block size is not evidenced; no type information confirms the unit of the accumulated total.
}
