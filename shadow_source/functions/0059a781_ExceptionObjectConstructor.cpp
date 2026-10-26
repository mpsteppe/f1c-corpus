// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A781
// Canonical corpus name: ExceptionObjectConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ExceptionObjectConstructor_0059a781.c

void UnknownObject::ExceptionObjectConstructor()
{
    // Exception-object constructor (std::runtime_error family, per the vtable write). Installs an SEH handler frame, reads the source object pointer from *(this+0x8), records the new-object pointer into a stack slot, copies the source string via StrlenAllocCopyConstructorPattern, transfers a byte flag from source offset 0xC into the new object at offset 0xC, releases the reference count at new+3 with a conditional free, copies a subrange of the source buffer via sub_59A9CA, and sets the runtime_error vftable at offset 0x0. Called from CThrowWithException (0059A70B) and sub_59A854.
    // CALL: Calls SEHHandlerInit to install the SEH handler frame; the skeleton fill links it to the continuation landing pad loc_59D4A0 (DERIVED) [callee:0x0058A5D8, global:0x0059D4A0, source:raw]
    // CALCULATION: Reads the source object pointer into v2 from field this+0x8 (source renders *(a1 + 8)) [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Saves the new-object pointer v3 into the stack slot *(this-16) (source renders *(a1 - 16)) [source:raw]
    // CALL: Calls StrlenAllocCopyConstructorPattern(v2) to allocate a buffer and copy the source string [callee:0x0059BF56, source:raw]
    // ASSIGNMENT: Reads the source flag byte v5 from offset 0xC of the object at *(this+0x8) (packet field *(this+0x8):0xC) [field:*(this+0x8):0x0000000C, source:raw]
    // ASSIGNMENT: Clears the stack slot *(this-4) to 0 (source renders *(a1 - 4) = 0) [source:raw]
    // ASSIGNMENT: Copies the source flag byte v5 into the new object at offset 0xC (source renders *((_BYTE *)v4 + 12) = v5) [source:raw]
    // CALL: Calls ReferenceCountDecrementWithConditionalFree(v4 + 3, 0) to release the reference count at new-object DWORD index 3 (offset 0xC) with literal 0 and a conditional free [callee:0x005993AF, source:raw]
    // CALL: Calls sub_59A9CA(v2 + 12, 0, -1) to copy a subrange from the source buffer offset 12 with literals 0 and -1 [callee:0x0059A9CA, source:raw]
    // ASSIGNMENT: Writes the std::runtime_error vftable (global 0x5B9D28) into the new object at offset 0x0 (source renders *v4 = &std::runtime_error::`vftable') [global:0x005B9D28, source:raw]
    // RETURN: Returns the constructed exception-object pointer in EAX [function:0x0059A781, source:raw]

    // Conservative worker pseudocode:
    //   SEHHandlerInit();
    //   v2 = *(this + 8);
    //   *(this - 16) = v3;
    //   StrlenAllocCopyConstructorPattern(v2);
    //   v5 = *(_BYTE *)(v2 + 12);
    //   *(this - 4) = 0;
    //   *((_BYTE *)v4 + 12) = v5;
    //   ReferenceCountDecrementWithConditionalFree(v4 + 3, 0);
    //   sub_59A9CA(v2 + 12, 0, -1);
    //   *v4 = &std::runtime_error::`vftable';
    //   return v4;
    // UNRESOLVED: The new-object write at offset 0xC (flag byte copy) is present in the raw source, but the packet field list exposes only the source-side read; the semantic role of the transferred flag is unknown
    // UNRESOLVED: dword_5B9C38 is flagged as read by packet facts but never appears in the raw decompiled source; the skeleton fill labels it a setup constant (DERIVED), unverifiable from this packet
    // UNRESOLVED: v3 (the new object pointer, received via ECX) is uninitialized in the decompiler output, so the allocation of the exception object happens outside this function
}
