// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040B450
// Canonical corpus name: LookupWithOptionalCallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LookupWithOptionalCallback_0040b450.c

void UnknownObject::LookupWithOptionalCallback()
{
    // Searches for a2 in the stride-0xA0 array via LinearSearchWithStride0xA0; on a match, records the found index through BoundedIndexSetter and, when the a3 flag is set, invokes the virtual callback dispatched at vtable+0x10 via the vtable pointer stored at this+0x0. Returns 1 on success, 0 when a2 is null or no match is found.
    // GUARD: Guard on a2: if a2 is zero the function returns 0 without performing a lookup. [source:raw, function:0x0040B450]
    // CALL: LinearSearchWithStride0xA0(this, a2) searches the stride-0xA0 array for a2 and stores the match index in v4. [callee:0x0040AD60, source:raw]
    // GUARD: Guard on v4: if the search result is negative (no match), return 0. [source:raw, function:0x0040B450]
    // CALL: BoundedIndexSetter(this, v4) records the found index in the object. [callee:0x0040AD90, source:raw]
    // CALL: When a3 is set, call the virtual callback: read the vtable pointer at this+0x0 and dispatch the function pointer stored at vtable offset 0x10. [field:this:0x00000000, source:raw]
    // RETURN: Return 1 after a successful lookup. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_40B450(_DWORD *this, int a2, char a3) {
    //     if (a2 == 0) return 0;
    //     int v4 = LinearSearchWithStride0xA0(this, a2);
    //     if (v4 < 0) return 0;
    //     BoundedIndexSetter(this, v4);
    //     if (a3) (*(void (**)(void))(*this + 16))();
    //     return 1;
    //   }
    // UNRESOLVED: Read of obj+0x10 (evidence field:obj:0x00000010) is not visible in the raw decompilation; its exact role in this frame is unclear, possibly an array base or member read that occurs inside a callee.
    // UNRESOLVED: Semantics of the optional vtable+0x10 callback and the meaning of the a3 flag are caller-specific.
    // UNRESOLVED: Element type and identity of the stride-0xA0 array searched by LinearSearchWithStride0xA0 are not established here.
}
