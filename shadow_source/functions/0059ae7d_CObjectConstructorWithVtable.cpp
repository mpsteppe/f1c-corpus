// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059AE7D
// Canonical corpus name: CObjectConstructorWithVtable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CObjectConstructorWithVtable_0059ae7d.c

void UnknownObject::CObjectConstructorWithVtable()
{
    // Constructor for an exception object of the std::logic_error family. Installs an SEH frame, reads the source pointer from the frame slot at this+0x8, copies the source string via the strlen+alloc+memcpy pattern, transfers a flag byte from source offset +0xC into the new object, drops the reference on the new object's string buffer, rebuilds the buffer via a full-subrange copy through sub_59A9CA, sets the std::logic_error vtable, and returns the constructed object. Called by CThrowWithException_ae07, VTableConstructor, and ObjectInitWithVTable_b038.
    // CALL: Install the SEH handler frame on the stack. [callee:0x0058A5D8]
    // CALCULATION: Load the source argument pointer from the frame slot at this+0x8. [field:this:0x00000008]
    // CALL: Allocate and copy the source string using the strlen+alloc+memcpy pattern (StrlenAllocCopyConstructorPattern). [callee:0x0059BF56]
    // ASSIGNMENT: Copy the flag byte from the source object at +0xC into the new object at +0xC. [field:*(this+0x8):0x0000000C]
    // CALL: Drop the reference on the new object's string buffer (this+3) with a non-freeing decrement via ReferenceCountDecrementWithConditionalFree. [callee:0x005993AF]
    // CALL: Rebuild the string buffer at this+3 from the source string via sub_59A9CA over the full subrange 0..0xFFFFFFFF. [callee:0x0059A9CA]
    // ASSIGNMENT: Set the object vtable to the std::logic_error vftable (??_7logic_error@std@@6B@). [global:0x005B9D7C]
    // RETURN: Return the constructed object pointer. [source:raw]

    // Conservative worker pseudocode:
    //   // Exception object constructor (std::logic_error family).
    //   ExceptionObj* self = this;
    //   const char* src = *(void**)((char*)this + 0x8);
    //   copy_string(src);                                // strlen/alloc/memcpy pattern
    //   self->flag = *(BYTE*)((char*)src + 0xC);         // transfer flag byte
    //   self->stringBuffer.Release(/* no free * /);       // this+3
    //   self->stringBuffer.Assign(srcString, 0, 0xFFFFFFFF);
    //   self->vftable = &std::logic_error_vftable;
    //   return self;
    // UNRESOLVED: dword_5B9C38 (SetupConstantValue) is read on this path but its use is not visible in the raw body.
    // UNRESOLVED: loc_59D588 is the SEH landing pad for this frame; the unwind handler is not shown.
    // UNRESOLVED: The exact object type beyond the std::logic_error vtable assignment is unknown.
}
