// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BF56
// Canonical corpus name: StrlenAllocCopyConstructorPattern
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StrlenAllocCopyConstructorPattern_0059bf56.c

void UnknownObject::StrlenAllocCopyConstructorPattern()
{
    // Copy constructor for an exception string object. Sets the object vtable, copies the source copy-mode/refcount flag from a2+8, then either deep-copies the source string (Strlen + new + string copy into an allocated buffer) when that flag is non-zero, or shares the source string pointer without copying when it is zero. Returns this.
    // ASSIGNMENT: Set the vtable pointer at this+0x0 to the MSVC exception vtable ??_7exception@@6B@ (0x005B9DC0). [abi:lead, field:this:0x00000000, global:0x005B9DC0, source:raw]
    // ASSIGNMENT: Copy the source copy-mode/refcount flag from a2+8 into this[2] (this+0x8). [field:this:0x00000008, source:raw]
    // GUARD: When the source flag at a2+8 is non-zero, take the deep-copy path; otherwise fall through to the shared-pointer path. [field:this:0x00000008, source:raw]
    // CALL: Compute the source string length with Strlen (0x0058E1B0) from the string pointer at a2+4. [callee:0x0058E1B0, source:raw]
    // CALL: Allocate a length+1 byte buffer with OperatorNewNhMallocWrapper (0x00587C03) for the string copy. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the freshly allocated buffer pointer into this[1] (this+0x4). [field:this:0x00000004, source:raw]
    // GUARD: When the allocation returned a non-null buffer, initialize/copy the string data into it via sub_58FCA0. [source:raw]
    // CALL: Invoke sub_58FCA0 (0x0058FCA0) to initialize/copy the string contents into the new buffer. [callee:0x0058FCA0, source:raw]
    // ASSIGNMENT: Else branch: when the source flag is zero, share the source string pointer from a2+4 directly into this[1] (this+0x4) without allocating. [field:this:0x00000004, source:raw]
    // RETURN: Return this as the constructed object. [function:0x0059BF56, source:raw]
    // CALL: Invoked as a copy-constructor by ExceptionObjectConstructor (0x0059A781) and CObjectConstructorWithVtable (0x0059AE7D). [caller:0x0059A781, caller:0x0059AE7D, source:raw]

    // Conservative worker pseudocode:
    //   StrlenAllocCopyConstructorPattern *sub_59BF56(StrlenAllocCopyConstructorPattern *this, const ExceptionString *a2) {
    //     this->vftable = &exception::`vftable';
    //     this->copyMode = a2->copyMode;
    //     if (this->copyMode) {
    //       int len = Strlen(a2->string);
    //       this->string = OperatorNewNhMallocWrapper(len + 1);
    //       if (this->string)
    //         sub_58FCA0();
    //     } else {
    //       this->string = a2->string;
    //     }
    //     return this;
    //   }
    // UNRESOLVED: The precise semantics of the a2+8 flag (refcount vs explicit copy-mode selector) are inferred from the branch behavior and not independently grounded.
    // UNRESOLVED: The exact copy behavior of sub_58FCA0 (whether it copies from the source string at a2+4) is not verified within this packet.
    // UNRESOLVED: The owning class of the exception-string object is unknown (this pointer type is opaque).
}
