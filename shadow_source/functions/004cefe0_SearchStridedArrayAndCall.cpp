// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CEFE0
// Canonical corpus name: StridedArraySearchAndCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StridedArraySearchAndCall_004cefe0.c

void UnknownObject::SearchStridedArrayAndCall()
{
    // Searches a strided array owned by this for an element whose second dword (offset +4 within the element) equals a2. The element count is this[4] (byte offset 0x10) and the array base is this[5] (byte offset 0x14); each element is 27 dwords (108 bytes). On a match, calls sub_4CD8D0 with the matched element pointer and a3. Returns the number of elements examined (the matched index), or the count v3 when no element matches; when the count is not positive it returns 0 immediately.
    // ASSIGNMENT: Read the element count into v3 from this[4] (byte offset 0x10) and initialize the search result to 0. [field:this:0x00000010, source:raw]
    // GUARD: Guard: only search when v3 > 0; otherwise return the initial result 0. [source:raw]
    // LOOP: Linear scan from the array base this[5] (byte offset 0x14), advancing 27 dwords (108 bytes) per element, comparing each element's second dword (i[1]) against a2. [field:this:0x00000014, source:raw]
    // GUARD: Inside the scan, when the incremented search counter result reaches v3, return v3 (no match found). [source:raw]
    // CALL: On a match, call sub_4CD8D0(matched_element, a3) and return its result. [callee:0x004CD8D0, source:raw]
    // RETURN: Return the matched element index, the count v3 when no match was found, or 0 when the array was empty; the function is invoked by sub_4FCEE0 (004FCEE0). [caller:0x004FCEE0, source:raw]

    // Conservative worker pseudocode:
    //   int SearchStridedArrayAndCall(_DWORD* this, int a2, float a3) {
    //     int v3 = this[4];
    //     int result = 0;
    //     if (v3 > 0) {
    //       for (i = (_DWORD*)this[5]; i[1] != a2; i += 27) {
    //         if (++result >= v3) return result;
    //       }
    //       return sub_4CD8D0(i, a3);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the key compared at i[1] and the 27-dword (108-byte) element layout are unknown; the strided element type is not identified.
    // UNRESOLVED: The action of sub_4CD8D0 on the matched element (rendering by a particle color-fade per the skeleton fill) is not evidenced in this packet.
}
