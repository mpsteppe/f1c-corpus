// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005179A2
// Canonical corpus name: sub_5179A2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5179A2_005179a2.c

void UnknownObject::CleanupResourceWithCallback()
{
    // Validates the owner object a1 and its resource sub-object, then performs an optional cleanup handoff into sub_527EED and a final callback-based release. Returns 0 on success and -2 whenever the owner, the sub-object pointer, or the callback slot is null.
    // GUARD: Null check on a1; returns -2 when the owner object is missing. [source:raw]
    // ASSIGNMENT: Load the resource sub-object pointer v1 from a1[7] (this+0x1C). [field:this:0x0000001C, source:raw]
    // GUARD: Guard returning -2 when v1 is null or the callback slot a1[9] (this+0x24) is null. [field:this:0x0000001C, field:this:0x00000024, source:raw]
    // CALCULATION: Read v2 = *(sub_object + 20); used only as a conditional trigger for the cleanup path. [source:raw]
    // GUARD: When v2 is non-null, call sub_527EED(v2, a1) to perform the optional sub-object cleanup. [callee:0x00527EED, source:raw]
    // CALL: Invoke the callback at a1[9] (this+0x24) with arguments (a1[10] at this+0x28, v1 at this+0x1C). [field:this:0x00000024, field:this:0x00000028, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Clear the sub-object pointer a1[7] (this+0x1C) to 0 after the callback. [field:this:0x0000001C, source:raw]
    // RETURN: Return 0 to signal successful release. [source:raw]

    // Conservative worker pseudocode:
    //   int CleanupResourceWithCallback(void* a1) {
    //     if (!a1) return -2;
    //     sub = a1[7];
    //     if (!sub || !a1[9]) return -2;
    //     trigger = *(sub + 20);
    //     if (trigger) sub_527EED(trigger, a1);
    //     a1[9](a1[10], a1[7]);
    //     a1[7] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Field this+0x30 appears in the deterministic field facts but is absent from the decompiled source body; it may be the data pointer feeding sub_527EED, but that is not grounded in this packet.
    // UNRESOLVED: The object type of a1 and the exact role of the callback are caller-supplied and cannot be determined from this function alone.
}
