// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005361D0
// Canonical corpus name: sub_5361D0
// Owner: CodecSubObject [DERIVED]
// Raw source: functions/sub_5361D0_005361d0.c

void CodecSubObject::CodecSubObjectTeardown()
{
    // Codec sub-object teardown. Validates the object (this) and the sub-object pointer at this+0x1C, then requires the codec mode tag at *(this+0x1C)+0x4 to be one of 42, 113, or 666. Conditionally invokes the cleanup function pointer stored at this+0x24 (with this+0x28 as its argument) for each non-zero flag at sub-object offsets +0x8, +0x2E, +0x36, +0x3A, then makes one unconditional final cleanup call passing the sub-object itself. Zeroes this+0x1C and returns 0xFD (253) when the mode tag is 113, otherwise 0.
    // GUARD: Return -2 when this is NULL [source:raw]
    // GUARD: Return -2 when the sub-object pointer at this+0x1C is NULL [field:this:0x0000001C, source:raw]
    // GUARD: Return -2 when the codec mode tag at *(this+0x1C)+0x4 is not 42, 113, or 666 [field:*(this+0x1C):0x00000004, source:raw]
    // CALL: When the parameter at *(this+0x1C)+0x8 is non-zero, call the fastcall cleanup function pointer at this+0x24 with (this+0x28, *(this+0x1C)+0x8) [field:*(this+0x1C):0x00000008, field:this:0x00000024, field:this:0x00000028, source:raw]
    // CALL: When the flag at *(this+0x1C)+0x2E is non-zero, call the thiscall cleanup function pointer at this+0x24 with this+0x28 [field:*(this+0x1C):0x0000002E, field:this:0x00000024, field:this:0x00000028, source:raw]
    // CALL: When the flag at *(this+0x1C)+0x36 is non-zero, call the thiscall cleanup function pointer at this+0x24 with this+0x28 [field:*(this+0x1C):0x00000036, field:this:0x00000024, field:this:0x00000028, source:raw]
    // CALL: When the flag at *(this+0x1C)+0x3A is non-zero, call the thiscall cleanup function pointer at this+0x24 with this+0x28 [field:*(this+0x1C):0x0000003A, field:this:0x00000024, field:this:0x00000028, source:raw]
    // CALL: Unconditional final cleanup: call the function pointer at this+0x24 with (this+0x28, this+0x1C) to release the sub-object itself [field:this:0x00000024, field:this:0x00000028, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Zero the sub-object pointer at this+0x1C after teardown (init literal 0) [field:this:0x0000001C, source:raw]
    // RETURN: Return 0xFD (253) when the mode tag is 113, otherwise 0; called from FileHandleDestructorWithModeCheck (0x00534EE0) and sub_535C10 (0x00535C10) [field:*(this+0x1C):0x00000004, caller:0x00534EE0, caller:0x00535C10, function:0x005361D0, source:raw]

    // Conservative worker pseudocode:
    //   if (!this) return -2;
    //   sub = *(this + 0x1C);
    //   if (!sub) return -2;
    //   mode = *(sub + 4);
    //   if (mode != 42 && mode != 113 && mode != 666) return -2;
    //   cleanup = *(this + 0x24); arg = *(this + 0x28);
    //   if (*(sub + 8)) cleanup(arg, *(sub + 8));
    //   if (*(sub + 0x2E)) cleanup(arg);
    //   if (*(sub + 0x36)) cleanup(arg);
    //   if (*(sub + 0x3A)) cleanup(arg);
    //   cleanup(arg, sub);
    //   *(this + 0x1C) = 0;
    //   return (mode == 113) ? 0xFD : 0;
    // UNRESOLVED: The codec identity behind the mode tags 42, 113, and 666, and the meaning of the 0xFD return for mode 113, require the owner contract; this packet has no codec-class evidence
    // UNRESOLVED: The abi:lead entry names the FAIL_5361d0 symbol with LEGACY trust and no prototype, so it cannot corroborate the calling convention or field layout
}
