// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556900
// Canonical corpus name: AddFloatToAnimationChannels
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AddFloatToAnimationChannels_00556900.c

void UnknownObject::AddFloatToAnimationChannels()
{
    // Iterates the linked list of animation channel nodes whose head is read through the pointer stored at this+0x110 (effective head address this+0x138). For each node, loads the channel-data pointer stored at node+0x54; when the flags dword at channel+0x18 has bit 0x400 set, adds argument a2 to the float accumulator at channel+0x38. Advances through the next pointer at node+0x5C. Returns the list traversal terminator (0 when the head is null).
    // LOOP: Walk the animation channel linked list: start from the head dereferenced through the pointer at this+0x110 plus 0x28 (effective this+0x138), and advance each iteration through the next pointer at node+0x5C. [field:this:0x00000110, field:this:0x00000138, field:*(*(this+0x138)+0x5C):0x0000005C, source:raw]
    // CALCULATION: Load the channel-data pointer v3 from the current list node at node+0x54. [field:*(*(this+0x138)+0x5C):0x00000054, source:raw]
    // GUARD: Test the channel flags dword at v3+0x18 for bit 0x400; only flagged channels have the float applied. [field:*(*(*(this+0x138)+0x5C)+0x54):0x00000018, source:raw]
    // CALCULATION: Add a2 to the float accumulator at v3+0x38: *(float*)(v3+56) = a2 + *(float*)(v3+56). [field:*(*(*(this+0x138)+0x5C)+0x54):0x00000038, source:raw]
    // RETURN: Return the result of the list traversal (the null terminator; 0 when the head is null). [function:0x00556900, source:raw]

    // Conservative worker pseudocode:
    //   result = *(int*)(*(int*)(this + 0x110) + 0x28); /* list head * /
    //   while (result) {
    //       v3 = *(int*)(result + 0x54);
    //       if (*(int*)(v3 + 0x18) & 0x400)
    //           *(float*)(v3 + 0x38) = a2 + *(float*)(v3 + 0x38);
    //       result = *(int*)(result + 0x5C);
    //   }
    //   return result;
    // UNRESOLVED: this+0x110 holds a pointer whose +0x28 sub-field is dereferenced for the list head; the field tags this:0x110 and this:0x138 alias this single effective access chain, so the two tags describe one address, not two independent fields.
    // UNRESOLVED: The concrete channel and owner class names, the meaning of flag bit 0x400, and the semantic role of the accumulator at +0x38 are not established by this function alone.
    // UNRESOLVED: Called by sub_557120; no frame path confirmed.
}
