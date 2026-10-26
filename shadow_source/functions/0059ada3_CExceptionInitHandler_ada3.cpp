// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059ADA3
// Canonical corpus name: CExceptionInitHandler_ada3
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CExceptionInitHandler_ada3_0059ada3.c

void UnknownObject::CExceptionInitHandler_ada3()
{
    // Exception object initializer for std::logic_error. Registers the SEH frame, seeds the object's string buffer from global byte_5EA438 via StringCopyConstructor, copies the first byte of a caller-provided buffer into the object at +0xC, releases the previous reference-counted sub-object at this+0xC via ReferenceCountDecrementWithConditionalFree, copies a subrange from the caller buffer into the object's string buffer via sub_59A9CA(this+0xC, buffer, 0, 0xFFFFFFFF), then installs the std::logic_error vtable and returns the new object.
    // CALL: SEHHandlerInit registers the SEH handler for this frame; the landing pad is loc_59D560. [callee:0x0058A5D8, global:0x0059D560]
    // ASSIGNMENT: Store the exception object pointer v2 into the frame slot at a1-20. [source:raw]
    // ASSIGNMENT: Seed the string-construction slot at a1-16 with the pointer to global byte_5EA438. [global:0x005EA438]
    // CALL: StringCopyConstructor(a1-16) copies the string at byte_5EA438 into the embedded exception string buffer. [callee:0x0059BF19]
    // ASSIGNMENT: Load the caller-provided buffer pointer v4 from the frame slot at a1+8 (this+0x8). [field:this:0x00000008]
    // ASSIGNMENT: Clear the frame slot at a1-4 to 0. [source:raw]
    // ASSIGNMENT: Copy the first byte of the caller buffer into the new object at this+0xC (byte dereference of *(this+0x8)+0). [field:*(this+0x8):0x00000000]
    // CALL: ReferenceCountDecrementWithConditionalFree(this+0xC, 0) releases the previous reference-counted sub-object at this+0xC. [callee:0x005993AF]
    // CALL: sub_59A9CA(this+0xC, v4, 0, 0xFFFFFFFF) copies a subrange from the caller buffer into the object's string buffer. [callee:0x0059A9CA]
    // ASSIGNMENT: Install the std::logic_error vtable (??_7logic_error@std@@6B@) as the object vtable. [global:0x005B9D7C]
    // RETURN: Return the constructed exception object v3. [source:raw]

    // Conservative worker pseudocode:
    //   void* CExceptionInitHandler_ada3(void* frame, void* obj, void* arg) {
    //     SEHHandlerInit();
    //     void* result = obj;
    //     *(void**)(frame - 20) = obj;
    //     *(const void**)(frame - 16) = &byte_5EA438;
    //     StringCopyConstructor(frame - 16);
    //     const void* buf = *(const void**)(frame + 8);
    //     *(int*)(frame - 4) = 0;
    //     *(byte*)((char*)result + 12) = *(byte*)buf;
    //     ReferenceCountDecrementWithConditionalFree((char*)result + 12, 0);
    //     sub_59A9CA((char*)result + 12, buf, 0, 0xFFFFFFFF);
    //     *(void**)result = &std::logic_error::vftable;
    //     return result;
    //   }
    // UNRESOLVED: Role of global dword_5B9C38 (SetupConstantValue) is not visible in this function's raw body.
    // UNRESOLVED: Exact semantics of sub_59A9CA(dest, src, 0, 0xFFFFFFFF) depend on its callee; the literal arguments are preserved verbatim from the source.
    // UNRESOLVED: String length used by StringCopyConstructor is resolved inside the callee, not visible here.
}
