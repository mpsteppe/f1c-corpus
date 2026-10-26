// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042ED70
// Canonical corpus name: sub_42ED70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_42ED70_0042ed70.c

void UnknownObject::FormatPathStringBuilder()
{
    // Constructs formatted resource-path strings into the target object using string components resolved through BinarySearchInStringTable against the global table byte_5EC4C0, with byte_5EC4CC as the working buffer. Always resolves the base component off_5C3774 into this+40. When the format selector at this+4 is nonzero, stores components at this+8 and this+24, builds "%s/%s" at this+56 and "%s/%s/%s" at this+72, and copies off_5C373C to this+88. When the selector is zero, uses the alternate component set (off_5C3770, byte_5C376C, aN, aMm, aM, aS_2, byte_5C3748) to build the same two formatted paths at this+56 and this+72 plus a single string at this+88.
    // CALL: Resolve the base path component via BinarySearchInStringTable(byte_5EC4C0, &off_5C3774, byte_5EC4CC); when a match is found it is copied into the working buffer. [callee:0x00423A00, global:0x005EC4C0, global:0x005C3774, global:0x005EC4CC]
    // ASSIGNMENT: Copy the resolved base component from byte_5EC4CC to this+40 (always, before the format-selector branch). [global:0x005EC4CC, source:raw]
    // GUARD: Branch on the format selector flag at this+4: nonzero selects the first template set, zero selects the alternate set. [field:this:0x00000004]
    // CALL: Resolve off_5C3744 via BinarySearchInStringTable and copy the result to this+8. [callee:0x00423A00, global:0x005EC4C0, global:0x005C3744, global:0x005EC4CC]
    // CALL: Resolve byte_5C3740 via BinarySearchInStringTable and copy the result to this+24. [callee:0x00423A00, global:0x005EC4C0, global:0x005C3740, global:0x005EC4CC]
    // CALL: Resolve off_5C3700 via BinarySearchInStringTable and copy the result into local buffer v47. [callee:0x00423A00, global:0x005EC4C0, global:0x005C3700, global:0x005EC4CC]
    // CALL: Resolve byte_5C3740 into local buffer v46 via StringCopyWithReturn and strcpy. [callee:0x0042F140, global:0x005C3740]
    // CALL: Format the two-component path into this+56 with StringFormatWithBufferOverflowCheck using the "%s/%s" template aSSS and components v47, v46. [callee:0x0058815F, global:0x005C374C]
    // CALL: Resolve aS_2 into local buffer v48 via StringCopyWithReturn and strcpy. [callee:0x0042F140, global:0x005C3758]
    // CALL: Format the three-component path into this+72 with StringFormatWithBufferOverflowCheck using the "%s/%s/%s" template aSS_1 and components v47, v46, v48. [callee:0x0058815F, global:0x005C3760]
    // ASSIGNMENT: Copy the resolved off_5C373C string into this+88 via StringCopyWithReturn and strcpy. [callee:0x0042F140, global:0x005C373C]
    // CALL: Alternate set: resolve off_5C3770 via BinarySearchInStringTable and copy the result to this+8. [callee:0x00423A00, global:0x005EC4C0, global:0x005C3770, global:0x005EC4CC]
    // CALL: Alternate set: resolve byte_5C376C via BinarySearchInStringTable and copy the result to this+24. [callee:0x00423A00, global:0x005EC4C0, global:0x005C376C, global:0x005EC4CC]
    // CALL: Alternate set: resolve aN via BinarySearchInStringTable and copy the result into local buffer v47. [callee:0x00423A00, global:0x005EC4C0, global:0x005C36FC, global:0x005EC4CC]
    // CALL: Alternate set: resolve aMm via BinarySearchInStringTable and copy the result into local buffer v46. [callee:0x00423A00, global:0x005EC4C0, global:0x005C3768, global:0x005EC4CC]
    // CALL: Alternate set: format the two-component path into this+56 with the "%s/%s" template aSSS and components v47, v46. [callee:0x0058815F, global:0x005C374C]
    // CALL: Alternate set: resolve aM via BinarySearchInStringTable and copy the result back into local buffer v46. [callee:0x00423A00, global:0x005EC4C0, global:0x005C375C, global:0x005EC4CC]
    // CALL: Alternate set: resolve aS_2 via BinarySearchInStringTable and copy the result into local buffer v48. [callee:0x00423A00, global:0x005EC4C0, global:0x005C3758, global:0x005EC4CC]
    // CALL: Alternate set: format the three-component path into this+72 with the "%s/%s/%s" template aSS_1 and components v47, v46, v48. [callee:0x0058815F, global:0x005C3760]
    // CALL: Alternate set: resolve byte_5C3748 via BinarySearchInStringTable and copy the result to this+88. [callee:0x00423A00, global:0x005EC4C0, global:0x005C3748, global:0x005EC4CC]
    // RETURN: Return the final copied string pointer (result), which points into the working buffer byte_5EC4CC on the alternate branch. [global:0x005EC4CC, source:raw]

    // Conservative worker pseudocode:
    //   char* FormatPathStringBuilder(int this) {
    //     byte_5EC4CC[0] = 0;
    //     if (BinarySearchInStringTable(byte_5EC4C0, &off_5C3774, byte_5EC4CC))
    //       strcpy((char*)(this + 40), byte_5EC4CC);
    //     if (*(DWORD*)(this + 4)) {
    //       ... resolve off_5C3744 -> this+8, byte_5C3740 -> this+24,
    //           off_5C3700 -> v47, byte_5C3740 -> v46 ...
    //       StringFormatWithBufferOverflowCheck(this + 56, "%s/%s", v47, v46);
    //       ... v48 = StringCopyWithReturn(aS_2) ...
    //       StringFormatWithBufferOverflowCheck(this + 72, "%s/%s/%s", v47, v46, v48);
    //       strcpy((char*)(this + 88), StringCopyWithReturn(&off_5C373C));
    //     } else {
    //       ... resolve off_5C3770 -> this+8, byte_5C376C -> this+24,
    //           aN -> v47, aMm -> v46 ...
    //       StringFormatWithBufferOverflowCheck(this + 56, "%s/%s", v47, v46);
    //       ... aM -> v46, aS_2 -> v48 ...
    //       StringFormatWithBufferOverflowCheck(this + 72, "%s/%s/%s", v47, v46, v48);
    //       ... resolve byte_5C3748 -> this+88 ...
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The exact byte contents of the template globals aSSS and aSS_1 are not stated in the raw source; matching them to the "%s/%s" and "%s/%s/%s" format literals is DERIVED from the StringFormatWithBufferOverflowCheck argument order and address adjacency, not directly evidenced.
    // UNRESOLVED: Semantic roles of the component strings at this+8, this+24, this+40 and the meaning of the format-selector flag at this+4 depend on the owning session/configuration object.
    // UNRESOLVED: The first branch also leaves the last resolved component (off_5C3700) in the working buffer, but the returned pointer is only observable from the alternate branch in the decompilation; return-value behavior of the nonzero branch is not fully modeled.
}
