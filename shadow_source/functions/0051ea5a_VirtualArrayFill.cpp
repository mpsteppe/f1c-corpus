// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051EA5A
// Canonical corpus name: VirtualArrayFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VirtualArrayFill_0051ea5a.c

void UnknownObject::VirtualArrayFill()
{
    // Fills an array of virtual objects through a vtable dispatch. Loads the base of the output buffer from a1[105] (offset 0x1A4), computes a size argument v3 = 2 * a1[23] + 4 (offset 0x5C), and when the element count a1[25] (offset 0x64) is positive, loops a1[25] times calling the vtable method located at *(a1[1] + 4) (vtable pointer at offset 0x4, method slot +4) with (a1, 1, v3). Each call result is stored into the buffer at base + 68, advancing by one DWORD per iteration. Returns the last stored result. Called by CodecModeSelect and ObjectSetupWithBoundsCheck.
    // ASSIGNMENT: Load result = a1[105], the output buffer base pointer at offset 0x1A4. [field:this:0x000001A4, source:raw]
    // ASSIGNMENT: Initialize the loop counter v2 = 0. [source:raw]
    // CALCULATION: Compute v3 = 2 * a1[23] + 4 = 2 * (offset 0x5C value) + 4, the size argument for the vtable call. [field:this:0x0000005C, source:raw]
    // GUARD: Guard: the fill loop runs only while the element count a1[25] (offset 0x64) is greater than 0. [guard:0, field:this:0x00000064, source:raw]
    // LOOP: Loop from v2 = 0 up to v2 < a1[25], the element count at offset 0x64. [guard:0, field:this:0x00000064, source:raw]
    // CALL: Indirect vtable call: method at *(a1[1] + 4) (vtable pointer at offset 0x4, slot +4) invoked with (a1, 1, v3); its result becomes the value stored in the buffer. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store the vtable call result at *v4 (buffer base + 68) and advance v4 by one DWORD and v2 by one each iteration. [field:this:0x000001A4, source:raw]
    // RETURN: Return the last vtable call result (uninitialized undefined if the loop never ran). [source:raw]
    // CALL: Called by CodecModeSelect and ObjectSetupWithBoundsCheck. [caller:0x0051EA90, caller:0x0051EB6E, source:raw]

    // Conservative worker pseudocode:
    //   int VirtualArrayFill(DWORD *a1) {
    //     int result = a1[105];
    //     int v2 = 0;
    //     int v3 = 2 * a1[23] + 4;
    //     if (a1[25] > 0) {
    //       int *v4 = (int *)(result + 68);
    //       do {
    //         result = (*(int (__cdecl **)(DWORD *, int, int))(a1[1] + 4))(a1, 1, v3);
    //         *v4 = result;
    //         ++v2;
    //         ++v4;
    //       } while (v2 < a1[25]);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The vtable method being invoked (creation/registration of a virtual object) is unknown; its purpose is inferred only from the fill pattern.
    // UNRESOLVED: The store base offset +68 within the buffer is derived from the raw code (a1[105] + 68) and has no independent evidence ref.
    // UNRESOLVED: The return value is undefined when the loop is skipped (a1[25] <= 0).
    // UNRESOLVED: The object class owning the vtable and array metadata is unknown.
}
