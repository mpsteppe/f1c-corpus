// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BFA0
// Canonical corpus name: MSVCExceptionDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MSVCExceptionDestructor_0059bfa0.c

void UnknownObject::MSVCExceptionDestructor()
{
    // Destructor for an MSVC exception object. Restores the exception vtable pointer at this+0, checks the ownership flag at this+8, and when the flag is non-zero frees the owned string buffer at this+4 via FreeWrapper_7bcf. When the flag is zero (shared/borrowed string) the free is skipped.
    // ASSIGNMENT: Write the exception::`vftable' address (global ??_7exception@@6B@ at 0x005B9DC0) into this+0, restoring the vtable pointer before destruction. [field:this:0x00000000, global:0x005B9DC0, source:raw]
    // GUARD: Read the ownership flag at this+8; when it equals 0 the string buffer is shared/borrowed and the free is skipped. [field:this:0x00000008, guard:0, source:raw]
    // CALL: When the flag at this+8 is non-zero, FreeWrapper_7bcf(*((LPVOID*)this + 1)) frees the owned string buffer at this+4. [field:this:0x00000004, callee:0x00587BCF, source:raw]
    // RETURN: Return the FreeWrapper_7bcf result on the owned path; on the borrowed path the decompiled form returns an uninitialized value. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_59BFA0(void *this) {
    //     bool borrowed = (*(int*)((char*)this + 8)) == 0;  // ownership flag at this+8
    //     *(int*)this = (int)&exception::`vftable';           // restore vtable at this+0
    //     if (!borrowed) return FreeWrapper_7bcf(*(void**)((char*)this + 4));
    //     return result;  // uninitialized on the borrowed path in the decompiled form
    //   }
    // UNRESOLVED: Exact semantics of the flag at this+8 (owned versus shared/borrowed string) are inferred from prior analysis, not proven in this scope.
    // UNRESOLVED: On the borrowed path the decompiled form returns an uninitialized value.
    // UNRESOLVED: Owning object is UnknownObject; invoked by six exception-cleanup callers (0x0059A728, 0x0059A7DE, 0x0059AE24, 0x0059AEDA, 0x0059AFC2, 0x0059BEFD).
}
