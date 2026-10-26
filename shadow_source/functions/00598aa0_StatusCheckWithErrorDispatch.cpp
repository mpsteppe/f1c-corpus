// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598AA0
// Canonical corpus name: StatusCheckWithErrorDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StatusCheckWithErrorDispatch_00598aa0.c

void UnknownObject::StatusCheckWithErrorDispatch()
{
    // Virtual status check on an object's sub-object followed by conditional error dispatch. Reads the vtable pointer from this[0], derives a sub-object offset from the vtable entry at +4, locates the sub-object, and tests its status byte against mask 6 plus a virtual status method dispatched at vtable+44 of the sub-object's vtable that must not return -1. When the check fails, the error flag (value 4) is ORed with the dword at the sub-object dword index 1, the low byte is additionally ORed with value 4 when the sub-object's dword index 10 is null, and sub_59A5FE(combined_flags, 0) dispatches the error notification. Returns this.
    // CALCULATION: Locate the sub-object: read the vtable pointer at this[0], read the offset dword at vtable+4, and compute v3 = this + offset. [field:this:0x00000000, field:obj:0x00000004, source:raw]
    // GUARD: Test the status byte at v3[4]: when (status & 6) == 0 the failure path is armed. [source:raw]
    // CALL: Invoke the virtual status method from the sub-object's vtable at +44, passing the sub-object; when it returns -1 the failure path is armed. [source:raw]
    // STATE_TRANSITION: Set the error flag v2 = 4 when both conditions hold (status byte flags clear AND virtual status method returned -1). [source:raw]
    // GUARD: Only proceed when the error flag v2 is non-zero. [source:raw]
    // ASSIGNMENT: Combine error flags: v5 = v2 | dword at the sub-object's dword index 1 (byte offset 4). [source:raw]
    // GUARD: When the sub-object's dword at index 10 (byte offset 40) is null, OR the low byte of the combined flags with value 4. [source:raw]
    // CALL: Dispatch the error notification via sub_59A5FE(v5, 0). [callee:0x0059A5FE, source:raw]
    // RETURN: Return this (the original object pointer). [source:raw]

    // Conservative worker pseudocode:
    //   char *StatusCheckWithErrorDispatch(char *this) {
    //     int error = 0;
    //     char *sub = this + *(int*)(*(int*)this + 4);
    //     if ((sub[4] & 6) == 0 && virtual_status_method(sub) == -1)
    //       error = 4;
    //     sub = this + *(int*)(*(int*)this + 4);
    //     if (error) {
    //       int combined = error | *(int*)(sub + 4);
    //       if (*(int*)(sub + 40) == 0)
    //         LOBYTE(combined) = combined | 4;
    //       sub_59A5FE(combined, 0);
    //     }
    //     return this;
    //   }
    // UNRESOLVED: Meaning of the status byte bits (mask 6) and of the virtual status method returning -1 at vtable+44.
    // UNRESOLVED: Semantics of the flag bits combined into v5 and of sub_59A5FE's second argument 0.
    // UNRESOLVED: The relationship between the this[0] vtable and the sub-object (offset stored at vtable[1]) is per-object; callers are RefCountDecrementWithCleanup and RefCountDecrementWithCheck.
}
