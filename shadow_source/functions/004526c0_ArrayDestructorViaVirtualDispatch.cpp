// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004526C0
// Canonical corpus name: ArrayDestructorViaVirtualDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayDestructorViaVirtualDispatch_004526c0.c

void UnknownObject::ArrayDestructorViaVirtualDispatch()
{
    // Destroys an array of 10 vtable-backed objects: first zeroes the count field this[261] (+0x414), then iterates the object-pointer array starting at this+25 (+0x64) with a stride of 26 dwords. For each non-null entry it invokes the object's vtable slot +44 method (stop/release-style call), then its vtable slot +8 method (refcount-release style), and clears the array slot to null. The last vtable-slot result is returned. Called once from HWInput_Post (0x00455E70).
    // ASSIGNMENT: Zero this[261] (+0x414), the object count/reset field, before the array walk [field:this:0x00000414, source:raw]
    // LOOP: Walk exactly 10 entries of the object-pointer array at this+25 (+0x64), advancing the cursor v1 by 26 dwords (0x68 bytes) per iteration [field:this:0x00000064, source:raw]
    // GUARD: Each array entry is processed only while its pointer *v1 is non-null [field:this:0x00000064, source:raw]
    // CALL: For a live entry, read the object's vtable pointer at *(*v1)+0 and call the method at vtable slot +44 (offset 0x2C) on it (stop/release-style teardown) [field:*(this+0x64):0x00000000, field:*(*(this+0x64)+0x0):0x0000002C, source:raw]
    // CALL: For a live entry, call the method at vtable slot +8 (offset 0x8) on it (refcount-release style), storing its result [field:*(this+0x64):0x00000000, field:*(*(this+0x64)+0x0):0x00000008, source:raw]
    // ASSIGNMENT: Clear the processed array slot *v1 to null after the two vtable calls [field:this:0x00000064, source:raw]
    // RETURN: Return the result of the last vtable slot +8 call after the 10-iteration loop completes [source:raw]
    // CALL: Invoked by HWInput_Post (0x00455E70), consistent with a cleanup/destructor role on an input-object array [caller:0x00455E70, source:raw]

    // Conservative worker pseudocode:
    //   this[261] = 0;
    //   v1 = this + 25;
    //   v2 = 10;
    //   do {
    //       result = *v1;
    //       if (result) {
    //           (*(*(DWORD*)result + 44))(*v1);
    //           result = (*(*(DWORD*)*v1 + 8))(*v1);
    //           *v1 = 0;
    //       }
    //       v1 += 26;
    //       --v2;
    //   } while (v2);
    //   return result;
    // UNRESOLVED: The vtable slot +44 and +8 method semantics (stop vs release, COM-style refcount) are inferred from the HWInput cleanup caller and the call-after-call pattern, not evidenced in this packet
    // UNRESOLVED: The meaning of the +0x414 count field and the object type behind the array are not evidenced here
}
