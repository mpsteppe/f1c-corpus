// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556980
// Canonical corpus name: AnimationDispatchWithSkipFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AnimationDispatchWithSkipFlag_00556980.c

void UnknownObject::AnimationDispatchWithSkipFlag()
{
    // Animation-node dispatch with a skip flag. First calls sub_54B570(this, a2, 0) and caches its result in v4. Unless the skip byte at this+0x3C has bit 4 set, walks the animation-node linked list rooted at *(this+0x204) through each node's next pointer (i[4]); for every node it reads the flags dword (i[5]), clears bits 0x20000028 when v4 is non-zero, and when the pre-mask flags lack bit 0x200000 dispatches an update through SceneNodeStateUpdateWithTransform when the node capability field (i[79]) is non-zero, otherwise through sub_556B10.
    // CALL: result = sub_54B570(this, a2, 0); the value is cached in v4 and controls later flag clearing. [callee:0x0054B570, source:raw]
    // GUARD: When (*(BYTE*)(this + 0x3C) & 4) != 0, skip the entire dispatch loop and return; otherwise process the list. [field:this:0x0000003C, source:raw]
    // LOOP: Walk the linked list starting at *(this+0x204); advance with i = i[4] (next pointer) until null. [field:this:0x00000204, source:raw]
    // CALCULATION: Read node flags (i[5]); when v4 is non-zero, rewrite them as flags & 0xDFFFFFD7, clearing bits 0x20000028. [field:*(this+0x204):0x00000020, field:*(this+0x204):0x00000024, source:raw]
    // GUARD: When (flags & 0x200000) == 0, dispatch the node update; otherwise leave the node untouched. [field:*(this+0x204):0x00000020, source:raw]
    // CALL: When the node capability field (i[79]) is non-zero, result = SceneNodeStateUpdateWithTransform(a2, i); otherwise result = sub_556B10(a2, i). [field:*(this+0x204):0x0000014C, callee:0x005569F0, callee:0x00556B10, source:raw]
    // RETURN: Return the final result (last assigned node update result, or the initial sub_54B570 result when the list was skipped). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_556980(int this, float* a2) {
    //     int result = sub_54B570(this, a2, 0);
    //     int v4 = result;
    //     if ((*(BYTE*)(this + 0x3C) & 4) == 0) {
    //       for (DWORD* i = *(DWORD**)(this + 0x204); i; i = (DWORD*)i[4]) {
    //         int flags = i[5];
    //         if (v4) i[5] = flags & 0xDFFFFFD7;
    //         if ((flags & 0x200000) == 0) {
    //           if (i[79]) result = SceneNodeStateUpdateWithTransform(a2, i);
    //           else result = sub_556B10(a2, i);
    //         }
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The IDB-annotated node field offsets (flags read at *(this+0x204)+0x20, flags write at *(this+0x204)+0x24, capability at *(this+0x204)+0x14C) do not match the decompiled source's dword indices for the same node (i[5] -> byte 0x14, i[79] -> byte 0x13C, i[4] -> byte 0x10); the annotation-vs-source mapping is unverified.
    // UNRESOLVED: Caller RecursiveStateTraversalWithFlagCheck (00556930) is recorded; frame-path membership is NOT_FOUND.
    // UNRESOLVED: The precise meaning of flag bits 0x200000 (skip dispatch) and the cleared 0x20000028 group, and the role of sub_54B570, rest on the existing analysis.
}
