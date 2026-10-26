// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047A080
// Canonical corpus name: ParameterValueClampingAcrossArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParameterValueClampingAcrossArray_0047a080.c

void UnknownObject::ParameterValueClampingAcrossArray()
{
    // Initializes the display formatter, then fetches a source object through the dword_7CD8C0 dispatch interface (slot +0x1C, command 8). If the source exists and the enable flag byte at this+0x100 is set, retrieves a value through the this vtable (slot +0xB4) and, after ZeroCheckGetter validates the source, iterates a global array from unk_7D1448 up to (but not including) flt_7D17A8, writing the retrieved value into each element's first dword and clamping it against bounds held in the element's third and fourth dwords. Always returns 0.
    // CALL: Call SetupValueDisplayFormatter on this to initialize display/dispatch state. [callee:0x00466910, source:raw]
    // CALL: Fetch source object through virtual accessor at slot +0x1C of the dword_7CD8C0 dispatch interface, passing command 8. [global:0x007CD8C0, source:raw]
    // GUARD: Guard: proceed only if the source object is non-null. [source:raw]
    // GUARD: Guard: proceed only if the enable flag byte at this+0x100 is non-zero. [field:this:0x00000100, source:raw]
    // CALL: Retrieve the value to clamp through the this vtable slot +0xB4 and dereference the returned pointer into v7. [field:this:0x00000000, field:obj:0x000000B4, source:raw]
    // GUARD: Guard: proceed with the array loop only if ZeroCheckGetter validates the source object. [callee:0x00490190, source:raw]
    // LOOP: do-while loop over the global array starting at unk_7D1448, advancing 27 dwords per element, ending once the pointer reaches flt_7D17A8. [global:0x007D1448, global:0x007D17A8, source:raw]
    // ASSIGNMENT: Write the retrieved value v7 into the current element's first dword. [global:0x007D1448, source:raw]
    // CALCULATION: Clamp the element value: if the element's third dword (lower bound) is at most the value, clamp down to the fourth dword (upper bound) when the value exceeds it; otherwise set the value to the third dword. [global:0x007D1448, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_47A080(int this) {
    //     SetupValueDisplayFormatter((int *)this);
    //     int *src = (*(int (**)(int, int))(*(void **)dword_7CD8C0 + 28))(dword_7CD8C0, 8);
    //     if (src && *(_BYTE *)(this + 256)) {
    //       int v7 = *(int *)(*(int (**)(int))(*(void **)this + 180))(this);
    //       if (ZeroCheckGetter(src)) {
    //         float *p = (float *)&unk_7D1448;
    //         do {
    //           float lo = p[2]; float hi = p[3];
    //           *(int *)p = v7;
    //           if (lo <= *p) { if (*p > (double)hi) *p = hi; } else { *p = lo; }
    //           p += 27;
    //         } while ((int)p < (int)&flt_7D17A8);
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Element structure of the unk_7D1448 array is unknown beyond stride 27 dwords; the meaning of the third and fourth dwords as clamp bounds is inferred from the comparison order only.
    // UNRESOLVED: The dword_7CD8C0 interface identity and the object type returned by command 8 are unknown.
    // UNRESOLVED: What the vtable slot +0xB4 value represents and which parameter it clamps across the array are unknown.
}
