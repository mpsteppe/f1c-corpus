// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051AD93
// Canonical corpus name: ArrayProcessingWithValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayProcessingWithValidation_0051ad93.c

void UnknownObject::ArrayProcessingWithValidation()
{
    // Validates receiver configuration fields (0x168/0x16C/0x170/0x174 must be 0/63/0/0), then iterates the sprite object array at this+0x124 and, per object, reads two channel indices (sprite+0x14, sprite+0x18), validates each index (must be < 4 and have a non-null buffer at this+0xA0/0xB0 region), copies both channel buffers into per-object decode-state slots via sub_51A5EA, and zeroes each state slot. Finally resets the decode state fields at state+8/+12/+16/+20/+24 and state+32, writes state+48 = this[0xFC], and returns that value.
    // GUARD: Configuration validation: if a1[90] || a1[91] != 63 || a1[92] || a1[93] (fields this+0x168, +0x16C, +0x170, +0x174), the receiver is rejected. [field:this:0x00000168, field:this:0x0000016C, field:this:0x00000170, field:this:0x00000174, guard:1, source:raw]
    // ASSIGNMENT: On configuration validation failure, write error code 118 into the vtable error-code field at obj+0x14. [field:obj:0x00000014, source:raw]
    // CALL: On configuration validation failure, dispatch the error handler through vtable slot at obj+0x4 with arguments (a1, -1); reads the vtable pointer at obj/this+0x0. [field:obj:0x00000004, field:obj:0x00000000, field:this:0x00000000, source:raw]
    // ASSIGNMENT: v2 = a1[101]: read the decode state pointer from field this+0x194. [field:this:0x00000194, source:raw]
    // GUARD: Loop guard: process objects only while a1[72] (this+0x120, object count) is > 0. [field:this:0x00000120, guard:0, source:raw]
    // LOOP: Iterate the sprite object array starting at a1[73] (this+0x124). Per object, read channel index A at sprite+0x14 and channel index B at sprite+0x18. [field:this:0x00000124, field:*(this+0x124):0x00000014, field:*(this+0x124):0x00000018, source:raw]
    // GUARD: Channel-A validity check: v3 >= 4, or the indexed buffer a1[v3+40] (this+0xA0 region) is null. [field:*(this+0x124):0x00000014, source:raw]
    // ASSIGNMENT: On channel-A failure, write error code 49 into obj+0x14 and the offending channel index v3 into obj+0x18. [field:obj:0x00000014, field:obj:0x00000018, source:raw]
    // CALL: On channel-A failure, dispatch the error handler through the vtable slot at obj+0x0 with argument (a1); reads the vtable pointer at obj/this+0x0. [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // GUARD: Channel-B validity check: v6 >= 4, or the indexed buffer a1[v6+44] (this+0xB0 region) is null. [field:*(this+0x124):0x00000018, source:raw]
    // ASSIGNMENT: On channel-B failure, write error code 49 into obj+0x14 and the offending channel index v6 into obj+0x18. [field:obj:0x00000014, field:obj:0x00000018, source:raw]
    // CALL: On channel-B failure, dispatch the error handler through the vtable slot at obj+0x0 with argument (a1); reads the vtable pointer at obj/this+0x0. [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // CALL: sub_51A5EA(a1, a1[v3+40], state + 52 + 4*v3): copy the channel-A buffer into the per-object destination slot in the decode state. [callee:0x0051A5EA, source:raw]
    // CALL: sub_51A5EA(a1, a1[v6+44], state + 68 + 4*v6): copy the channel-B buffer into the per-object destination slot in the decode state. [callee:0x0051A5EA, source:raw]
    // ASSIGNMENT: Zero the per-object decode-state slot: *v8 = 0 where v8 walks the state+32 array (field this+0x1B4). [field:this:0x000001B4, source:raw]
    // ASSIGNMENT: Reset decode-state counters: state+8, +12, +16, +20 are all zeroed (fields this+0x19C, +0x1A0, +0x1A4, +0x1A8). [field:this:0x0000019C, field:this:0x000001A0, field:this:0x000001A4, field:this:0x000001A8, source:raw]
    // ASSIGNMENT: Zero the decode-state byte at state+24 (field this+0x1AC). [field:this:0x000001AC, source:raw]
    // ASSIGNMENT: Write state+48 = a1[63] (field this+0x1C4 = field this+0xFC); this copies the receiver reference value into the decode state. [field:this:0x000000FC, field:this:0x000001C4, source:raw]
    // RETURN: Return a1[63] (this+0xFC), the same value just copied into the decode state. [field:this:0x000000FC, source:raw]

    // Conservative worker pseudocode:
    //   int ArrayProcessingWithValidation(DWORD* a1) {
    //       DWORD* state = (DWORD*)a1[101];
    //       if (a1[90] || a1[91] != 63 || a1[92] || a1[93]) {
    //           *(DWORD*)(*a1 + 20) = 118;
    //           ((void(__cdecl*)(DWORD*,int))*((DWORD*)*a1 + 1))(a1, -1);
    //       }
    //       for (int i = 0; i < a1[72]; i++) {
    //           DWORD* sprite = (DWORD*)a1[73 + i];
    //           DWORD chA = *(DWORD*)(sprite + 20);
    //           DWORD chB = *(DWORD*)(sprite + 24);
    //           if (chA >= 4 || !a1[chA + 40]) {
    //               *(DWORD*)(*a1 + 20) = 49; *(DWORD*)(*a1 + 24) = chA;
    //               ((void(__cdecl*)(DWORD*))*a1)(a1);
    //           }
    //           if (chB >= 4 || !a1[chB + 44]) {
    //               *(DWORD*)(*a1 + 20) = 49; *(DWORD*)(*a1 + 24) = chB;
    //               ((void(__cdecl*)(DWORD*))*a1)(a1);
    //           }
    //           sub_51A5EA(a1, a1[chA + 40], state + chA + 13);
    //           sub_51A5EA(a1, a1[chB + 44], state + chB + 17);
    //           *(DWORD*)((BYTE*)state + 32 + 4*i) = 0;
    //       }
    //       *(BYTE*)((BYTE*)state + 24) = 0;
    //       *(DWORD*)((BYTE*)state + 20) = 0;
    //       *(DWORD*)((BYTE*)state + 8) = 0;
    //       *(DWORD*)((BYTE*)state + 12) = 0;
    //       *(DWORD*)((BYTE*)state + 16) = 0;
    //       *(DWORD*)((BYTE*)state + 48) = a1[63];
    //       return a1[63];
    //   }
    // UNRESOLVED: The indexed channel buffer arrays a1[v3+40] and a1[v6+44] (this+0xA0 / this+0xB0 regions) have no field evidence refs; only their consumers are known.
    // UNRESOLVED: The per-object decode-state destination arrays at state+52 and state+68 have no field evidence refs.
    // UNRESOLVED: The three vtable error dispatches assume obj and this alias the same a1 pointer; the alias is inferred, not evidenced.
    // UNRESOLVED: No callers recorded; frame-path relationship unknown.
}
