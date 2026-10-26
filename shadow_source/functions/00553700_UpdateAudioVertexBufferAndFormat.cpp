// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553700
// Canonical corpus name: sub_553700
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_553700_00553700.c

void UnknownObject::UpdateAudioVertexBufferAndFormat()
{
    // Per-frame audio/render buffer update and format dispatch. When the element count (this+0x4) is positive and the dirty flag (byte 1 of this+0x0, bit 0x80) is set, clears the pending-update bit (AND with the mask 0xFFFF7FFF) in the flags and copies count elements from the source pointer (this+0x18) into a locked buffer (BufferLockAllocate on global dword_8B78A0 with handle this+0x14) using either a 24-byte stride (flag bit 0) or 28-byte stride (flag bit 1) vertex layout. Then conditionally re-fetches vtables, rebuilds UI/format state when the caller-supplied a2 differs from global dword_8B8DC8, initializes a local audio state struct when dword_8B8CEC > 1, configures the audio buffer format via AudioBufferFormatSetup using the fields at this+0x8/0xC/0x10, and finally applies vtable-driven UI text updates when the state changed.
    // GUARD: Process only when the element count at this+0x4 is greater than 0. [guard:0, field:this:0x00000004, source:raw]
    // GUARD: Proceed with buffer copy only when bit 0x80 in byte 1 of the flags at this+0x0 is set (pending update). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the pending-update bit of the flags at this+0x0 by ANDing with the mask 0xFFFF7FFF to mark the pending update handled. [field:this:0x00000000, source:raw]
    // CALL: When flag bit 0 is set, lock a buffer via BufferLockAllocate(dword_8B78A0, this+0x14, 96, 0, 0). [callee:0x00540F00, global:0x008B78A0, field:this:0x00000014, source:raw]
    // LOOP: Copy element_count (this+0x4) elements from source pointer this+0x18 into the locked buffer at offset +8 using the 24-byte stride layout (6 dwords: 0, 4, 8, 12, 16, 20 reordered to 0, 4, 8, 12, 16, 20). [field:this:0x00000004, field:this:0x00000018, source:raw]
    // CALL: Else-when flag bit 1 is set, lock a second buffer via BufferLockAllocate(dword_8B78A0, this+0x14, 96, 0, 0). [callee:0x00540F00, global:0x008B78A0, field:this:0x00000014, source:raw]
    // LOOP: Copy element_count (this+0x4) elements from source pointer this+0x18 into the buffer at offset +8 using the 28-byte stride layout (7 dwords: 0, 4, 8, 12, 16, 20, 24). [field:this:0x00000004, field:this:0x00000018, source:raw]
    // CALL: After either copy branch, call ArithmeticComparison_0f90(dword_8B78A0, this+0x14) to finalize the locked buffer. [callee:0x00540F90, global:0x008B78A0, field:this:0x00000014, source:raw]
    // CALL: When global dword_8B8DF0 is zero, refresh the vtable via VTableGetterWrapper(dword_8B78A0). [global:0x008B8DF0, global:0x008B78A0, callee:0x005550A0, source:raw]
    // GUARD: When the caller argument a2 differs from global dword_8B8DC8, rebuild format/UI state. [global:0x008B8DC8, source:raw]
    // CALL: Re-query the object's vtables via TripleVtableQueryAndStore(dword_8B78A0). [callee:0x0055CDF0, global:0x008B78A0, source:raw]
    // CALL: Initialize a local float struct via F_10FloatStructInitializer. [callee:0x0053B130, source:raw]
    // CALL: Dispatch enum 2 through EnumToVTableCallMapper into the 16-dword local argument array v14. [callee:0x0055CA40, source:raw]
    // ASSIGNMENT: Fill v14 with float bit patterns: 1059256707, 1059256707, 1038323257, 1065353216, -1137308831, 0 at the remaining slots. [source:raw]
    // CALL: Dispatch enum 4 through EnumToVTableCallMapper into v14. [callee:0x0055CA40, source:raw]
    // CALL: Call sub_55CA90 with (a2, 1) to register the new state. [callee:0x0055CA90, source:raw]
    // CALL: Call EmptyStub_b160 (no-op / placeholder). [callee:0x0053B160, source:raw]
    // GUARD: When global dword_8B8CEC is greater than 1, initialize a local audio/render state struct. [global:0x008B8CEC, source:raw]
    // CALL: Initialize the local struct via ConstructorInit. [callee:0x005418B0, source:raw]
    // CALL: Populate the local struct via sub_542200 with flt_8B8CF0, 0.0, flt_8B8CF4, 1.0, 0. [callee:0x00542200, global:0x008B8CF0, global:0x008B8CF4, source:raw]
    // CALL: Apply the local struct through sub_55CC20. [callee:0x0055CC20, source:raw]
    // CALL: Call EmptyStub_7470 with the local struct. [callee:0x00557470, source:raw]
    // CALL: Configure the audio buffer format via AudioBufferFormatSetup(dword_8B78A0, dword_8B8F28, this+0x14, 0, this+0x4, this+0x10, this+0x8, this+0xC, 3, 2). [callee:0x00541120, global:0x008B78A0, global:0x008B8F28, field:this:0x00000014, field:this:0x00000004, field:this:0x00000010, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALL: When global dword_8B8DF0 is zero, refresh the dispatch vtable via VTableDispatchGetter(dword_8B78A0). [global:0x008B8DF0, global:0x008B78A0, callee:0x005550C0, source:raw]
    // RETURN: If a2 still differs from global dword_8B8DC8, call sub_55CA90(dword_8B8DC8, 1) and return the result of SetUITextFieldsViaVtableCalls(dword_8B78A0); otherwise return dword_8B8DC8. [global:0x008B8DC8, global:0x008B78A0, callee:0x0055CA90, callee:0x0055CE50, source:raw]

    // Conservative worker pseudocode:
    //   int UpdateAudioVertexBufferAndFormat(unsigned int* this, int a2) {
    //     int result = this[1];
    //     if (result > 0) {
    //       if ((BYTE1(*this) & 0x80) != 0) {
    //         *this &= 0xFFFF7FFF;
    //         if ((*this & 1) != 0) {
    //           int* dst = BufferLockAllocate(dword_8B78A0, this[5], 96, 0, 0) + 8;
    //           for (int i = 0; i < this[1]; ++i)   // 24-byte stride copy
    //             copy6dwords(dst + i*6, this[6] + i*24);
    //         } else if ((*this & 2) != 0) {
    //           int* dst = BufferLockAllocate(dword_8B78A0, this[5], 96, 0, 0) + 8;
    //           for (int i = 0; i < this[1]; ++i)   // 28-byte stride copy
    //             copy7dwords(dst + i*7, this[6] + i*28);
    //         }
    //         ArithmeticComparison_0f90(dword_8B78A0, this[5]);
    //       }
    //       if (!dword_8B8DF0) VTableGetterWrapper(dword_8B78A0);
    //       if (a2 != dword_8B8DC8) {
    //         TripleVtableQueryAndStore(dword_8B78A0);
    //         // F_10FloatStructInitializer + EnumToVTableCallMapper(2/4, v14)
    //         // v14 = float bit patterns incl. 1059256707, 1038323257, 1065353216, -1137308831
    //         sub_55CA90(a2, 1);
    //         EmptyStub_b160();
    //       }
    //       if (dword_8B8CEC > 1) {
    //         ConstructorInit(v15);
    //         sub_542200(v15, flt_8B8CF0, 0.0, flt_8B8CF4, 1.0, 0);
    //         sub_55CC20(v15); EmptyStub_7470(v15);
    //       }
    //       AudioBufferFormatSetup(dword_8B78A0, dword_8B8F28, this[5], 0, this[1], this[4], this[2], this[3], 3, 2);
    //       if (!dword_8B8DF0) VTableDispatchGetter(dword_8B78A0);
    //       if (a2 != dword_8B8DC8) {
    //         sub_55CA90(dword_8B8DC8, 1);
    //         return SetUITextFieldsViaVtableCalls(dword_8B78A0);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the 24-byte vs 28-byte vertex layouts (which attributes each dword maps to) are unknown.
    // UNRESOLVED: Meaning of the float bit patterns written into v14 (1059256707, 1038323257, 1065353216, -1137308831) is not resolved; they likely encode colour/scale constants for a render call.
    // UNRESOLVED: The owner object type is unknown; the mix of vertex copies and audio format calls suggests a shared UI/render node but no class is named.
    // UNRESOLVED: Whether this+0x8/0xC/0x10 are audio format parameters or vertex format parameters is ambiguous from this function alone.
}
