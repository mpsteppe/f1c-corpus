// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F5F0
// Canonical corpus name: CursorResourceCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CursorResourceCleanup_0044f5f0.c

void UnknownObject::CursorResourceCleanup()
{
    // Cursor resource teardown. Clears the active cursor via SetCursor(0), then iterates six handle slots starting at this+0x30 (20-byte stride), destroying each non-null handle through DestroyCursor and zeroing the slot. Finally resets the cursor count/index at this[42] (offset 0xA8) to 0 and returns the last destroyed or held handle. Called from HWInput_Exit and sub_4963D0.
    // CALL: Clear the active cursor: SetCursor(0) [global:0x0059E2B0, source:raw]
    // LOOP: Walk six handle slots starting at this[12] (offset 0x30), advancing the pointer by 20 bytes (5 dwords) per iteration [field:this:0x00000030, source:raw]
    // GUARD: Destroy a slot only when its handle value is non-null [field:this:0x00000030, global:0x0059E2AC]
    // CALL: Destroy the slot's handle via DestroyCursor and zero the slot entry [field:this:0x00000030, global:0x0059E2AC, source:raw]
    // ASSIGNMENT: Reset the cursor count/index: this[42] (offset 0xA8) = 0 [field:this:0x000000A8]
    // RETURN: Returns the accumulated handle value (last destroyed handle, or the last slot value when null); called from the input-exit path HWInput_Exit and from sub_4963D0 [function:0x0044F5F0, caller:0x00455F00, caller:0x004963D0]

    // Conservative worker pseudocode:
    //   SetCursor(0);
    //   v2 = this + 12;
    //   for (v3 = 6; v3 != 0; --v3) {
    //     result = *v2;
    //     if (*v2) {
    //       result = DestroyCursor(*v2);
    //       *v2 = 0;
    //     }
    //     v2 += 5;
    //   }
    //   this[42] = 0;
    //   return result;
    // UNRESOLVED: The cursor-manager object type and the exact layout of the six 20-byte handle slots are not evidenced beyond the raw offsets
    // UNRESOLVED: Semantics of the slot 20-byte stride (only the first dword handle is used) are not asserted
    // UNRESOLVED: The meaning of the returned HCURSOR value to callers is not evidenced
}
