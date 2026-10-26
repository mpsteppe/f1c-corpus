// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00516959
// Canonical corpus name: sub_516959
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_516959_00516959.c

void UnknownObject::CleanupAndResetState()
{
    // Cleanup-and-reset routine. Reads the pointer at this+0x4; if it is non-null, invokes its callback at offset 0x28 (a cdecl function pointer) passing this as the argument, and keeps the callback's return value as the function result. Regardless of the guard outcome, clears both this+0x4 and this+0x10 to 0. Returns the callback return value when the sub-object was present, otherwise 0.
    // GUARD: Reads the pointer at this+0x4 and proceeds to the cleanup callback only when it is non-null [field:this:0x00000004, source:raw]
    // CALL: When this+0x4 is non-null, calls the cdecl function pointer at offset 0x28 of the sub-object with this as its argument; the return value becomes result [field:*(this+0x4):0x00000028, source:raw]
    // ASSIGNMENT: Clears this+0x4 to 0 after the cleanup step [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Clears this+0x10 to 0 after the cleanup step [field:this:0x00000010, source:raw]
    // RETURN: Returns the callback return value if the sub-object existed, otherwise 0 (the value of this+0x4 when it was null) [source:raw]
    // CALL: Invoked by ArithmeticComparison_166b (0051166B) [caller:0x0051166B, source:raw]

    // Conservative worker pseudocode:
    //   result = *(this + 0x4);
    //   if (result) {
    //     result = (*(int (**)(int))(result + 0x28))(this);
    //   }
    //   *(this + 0x4) = 0;
    //   *(this + 0x10) = 0;
    //   return result;
    // UNRESOLVED: The receiver type and the sub-object type (with a cdecl function pointer at +0x28) are unknown
    // UNRESOLVED: The cleanup callback's purpose and the meaning of its return value are unestablished
    // UNRESOLVED: Whether the callback at +0x28 is a vtable slot or a plain member function pointer is unknown
}
