// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497AD0
// Canonical corpus name: sub_497AD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_497AD0_00497ad0.c

void UnknownObject::LoadAndRegisterSurfaceResource()
{
    // Loads and registers a surface resource by name a2. Rejects a null name, then checks the existing cache via sub_497BA0(a2) and returns the cached result if present. Otherwise resolves the string ID via HashTableIDResolution(a2); when resolution fails it either returns 0 (a3 clear) or formats "Unable to load surface \"%s\"" into unk_7CDE38 and reports it via sub_4986D0 (a3 set). A 20-byte node is allocated and initialized (byte flag 1 at +0, +4/+8/+12/+16 cleared with +8 set to -1, resolved ID stored at +12). The node is appended to the singly linked list rooted at this+0x104 (walking the +16 next links to the tail), the counter at this+0x108 is incremented, and the node pointer is returned. Used by menu/profile/UI bitmap loading paths.
    // GUARD: If a2 is null, return 0 immediately. [source:raw]
    // CALL: Check the existing cache: result = sub_497BA0(a2). [callee:0x00497BA0]
    // GUARD: Proceed only on a cache miss (result == 0); a hit returns the cached result directly. [source:raw]
    // CALL: Resolve the name to an ID: v10 = HashTableIDResolution(a2). [callee:0x00495890]
    // GUARD: If resolution failed (v10 null): return 0 when a3 is clear, otherwise format "Unable to load surface \"%s\"" into &unk_7CDE38 via StringFormatWithBufferOverflowCheck and pass it to sub_4986D0. [callee:0x0058815F, global:0x007CDE38, global:0x005CCA5C, callee:0x004986D0]
    // ASSIGNMENT: Read the list head v7 = this[65] (offset 0x104). [field:this:0x00000104]
    // CALL: Allocate a 20-byte node: v8 = OperatorNewNhMallocWrapper(20). [callee:0x00587C03]
    // ASSIGNMENT: Initialize the 20-byte node: byte flag 1 at +0, +4 set to 0, +8 set to -1, +12 set to 0, +16 set to 0; v4 = v8. [source:raw]
    // ASSIGNMENT: Store the resolved ID at node +12, then copy the name via StringCopyWithBufferRealloc(a2). [callee:0x00566650]
    // LOOP: Append the node: if the head v7 is non-null, walk the next links at node offset +16 (read via *(*(this+0x114)+0x10) base) to the tail and set tail's next to v4; otherwise install v4 as the new head this[65] (offset 0x104). [field:*(*(this+0x114)+0x10):0x00000010, field:this:0x00000104]
    // ASSIGNMENT: Increment the registered-surface counter at offset 0x108 (++this[66]) and return the node pointer v4. [field:this:0x00000108]
    // RETURN: On cache hit, return the cached result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return 0;
    //   result = sub_497BA0(a2);
    //   if (!result) {
    //     v10 = HashTableIDResolution(a2);
    //     if (!v10) {
    //       if (!a3) return 0;
    //       StringFormatWithBufferOverflowCheck(&unk_7CDE38, "Unable to load surface \"%s\"", a2);
    //       sub_4986D0(&unk_7CDE38);
    //     }
    //     v7 = this[65];
    //     v8 = OperatorNewNhMallocWrapper(20);
    //     if (v8) {
    //       *(byte*)v8 = 1; *(dword*)(v8+4) = 0; *(dword*)(v8+8) = -1; *(dword*)(v8+12) = 0; *(dword*)(v8+16) = 0;
    //       v4 = v8;
    //     }
    //     *(dword*)(v4 + 12) = v10;
    //     StringCopyWithBufferRealloc(a2);
    //     if (v7) {
    //       for (i = *(dword*)(v7 + 16); i; i = *(dword*)(i + 16)) v7 = i;
    //       *(dword*)(v7 + 16) = v4;
    //     } else {
    //       this[65] = v4;
    //     }
    //     ++this[66];
    //     return v4;
    //   }
    //   return result;
    // UNRESOLVED: Field this+0x114 appears in the packet field list but is never read directly in the reconstructed source; it is the base used by the extraction for the node next-link access (*(*(this+0x114)+0x10)), so its object-level meaning is unknown here.
    // UNRESOLVED: The this+0x108 counter is classified R (read) in the packet while the source performs ++this[66] (read-modify-write); the increment is evidenced by the source text.
    // UNRESOLVED: sub_497BA0 (cache lookup), HashTableIDResolution, sub_4986D0 (error reporting) and StringCopyWithBufferRealloc are evidenced only by their call signatures here; their exact contracts are not in this packet.
}
