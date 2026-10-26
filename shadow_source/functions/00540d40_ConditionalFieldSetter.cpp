// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00540D40
// Canonical corpus name: ConditionalFieldSetter_0d40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFieldSetter_0d40_00540d40.c

void UnknownObject::ConditionalFieldSetter()
{
    // Flag-driven lock acquisition on a graphics/resource object (__stdcall, called by sub_557670 and sub_558310). No-op when a1 is null. When flag bit 4 of a2 is set, allocates a buffer lock via BufferLockAllocate(a1[7], a2, a1[11], a1[2]) and stores the result at a1[8]. When flag bit 8 of a2 is set, allocates a surface blit lock via SurfaceBlitLockWithFlagCheck(a1[9], a2, a1[12], a1[4]) and stores the result at a1[10]. The two branches are independent and may both execute for the same call.
    // GUARD: If a1 is null the function is a no-op; otherwise evaluate the flag mask. [function:0x00540D40, source:raw]
    // GUARD: When (a2 & 4) != 0, perform the buffer lock allocation. [function:0x00540D40, source:raw]
    // CALL: Call BufferLockAllocate(a1[7], a2, a1[11], a1[2]) using the stored buffer pointer, the flag mask, and the sizing/control fields at a1[11] and a1[2]. [callee:0x00540F00, field:this:0x0000001C, field:this:0x0000002C, field:this:0x00000008, function:0x00540D40, source:raw]
    // ASSIGNMENT: Store the BufferLockAllocate result into the buffer-lock field a1[8]. [field:this:0x00000020, function:0x00540D40, source:raw]
    // GUARD: When (a2 & 8) != 0, perform the surface blit lock allocation. [function:0x00540D40, source:raw]
    // CALL: Call SurfaceBlitLockWithFlagCheck(a1[9], a2, a1[12], a1[4]) using the stored surface pointer, the flag mask, and the control fields at a1[12] and a1[4]. [callee:0x00541090, field:this:0x00000024, field:this:0x00000030, field:this:0x00000010, function:0x00540D40, source:raw]
    // ASSIGNMENT: Store the SurfaceBlitLockWithFlagCheck result into the surface-lock field a1[10]. [field:this:0x00000028, function:0x00540D40, source:raw]
    // RETURN: Return from the void function; invoked by sub_557670 (00557670) and sub_558310 (00558310). [function:0x00540D40, caller:0x00557670, caller:0x00558310, source:raw]

    // Conservative worker pseudocode:
    //   void sub_540D40(_DWORD *a1, int a2) {
    //     if (a1 == 0) return;
    //     if ((a2 & 4) != 0)
    //       a1[8] = BufferLockAllocate(a1[7], a2, a1[11], a1[2]);
    //     if ((a2 & 8) != 0)
    //       a1[10] = SurfaceBlitLockWithFlagCheck(a1[9], a2, a1[12], a1[4]);
    //   }
    // UNRESOLVED: The meaning of the flag bits (4 = buffer lock, 8 = surface blit lock) and of the other bits in a2 is not documented in this packet.
    // UNRESOLVED: The owning object type and the relationship between the a1[2]/a1[4] control fields and the lock allocations is unidentified.
    // UNRESOLVED: Whether the two lock paths are mutually exclusive in practice or expected to be requested together is unknown.
}
