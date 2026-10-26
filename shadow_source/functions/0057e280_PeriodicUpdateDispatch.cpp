// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057E280
// Canonical corpus name: sub_57E280
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57E280_0057e280.c

void UnknownObject::PeriodicUpdateDispatch()
{
    // Timer-driven periodic update: decrements the countdown timer this+0xAA8 by the delta argument a2 and, when it expires (<= 0.0), resets it to 0.125f and performs one update pass. The pass acquires the mutex at this+0xAD8 (waiting up to the timeout this+0xADC), fetches the managed-object count through the vtable at this+0x0, iterates the objects calling a vtable fetch (offset 172) into a temporary wrapper, processes each entry (filtered by the v18 condition and sub_587220(v16) == 2) via sub_585870 on the value read by ReadFieldAtOffset0x14, drains pending callbacks via MutexCallbackDispatch, and finally releases the mutex.
    // CALCULATION: Decrement the countdown timer this+0xAA8 by the delta a2 and store the remainder back. [field:this:0x00000AA8, source:raw]
    // GUARD: Enter the update pass when the timer remainder is zero or negative (FPU below/equal flags 0x4100). [field:this:0x00000AA8, source:raw]
    // ASSIGNMENT: Reset the timer this+0xAA8 to 0.125f (float literal 1040187392). [field:this:0x00000AA8, source:raw]
    // CALL: Call MutexProtectedPointerReadRelease(this); the comparison against 4 defines v18 (whether the sub_587220 filter applies). [callee:0x00585D20, source:raw]
    // GUARD: If the mutex handle at this+0xAD8 is non-null, wait on it with the timeout at this+0xADC. [field:this:0x00000AD8, field:this:0x00000ADC, source:raw]
    // CALL: Call WaitForSingleObject(handle, timeout) on the mutex before iterating. [callee:0x0057E3A0, global:0x0059E1A0, field:this:0x00000AD8, field:this:0x00000ADC, source:raw]
    // CALL: Fetch the managed-object count v11 via the vtable pointer at this+0x0, dispatching at vtable offset 164 (0xA4). [field:this:0x00000000, field:obj:0x000000A4, source:raw]
    // LOOP: Iterate i from 0 while i < v11, processing each managed object. [source:raw]
    // CALL: Initialize the per-iteration wrapper v16 with ObjectInitWithVTableFieldSet(v16, 0, 0, 0). [callee:0x0057B780, source:raw]
    // GUARD: Fetch object i into v16 via the vtable pointer at this+0x0 (offset 172); when v18 is set, additionally require sub_587220(v16) == 2. [field:this:0x00000000, callee:0x00587220, source:raw]
    // CALL: Call sub_587220(v16) to check the entry condition when the filter is active. [callee:0x00587220, source:raw]
    // CALL: Read v14 = ReadFieldAtOffset0x14(v16) and process the matched entry with sub_585870(v14, 0). [callee:0x005871F0, callee:0x00585870, source:raw]
    // CALL: Tear down the wrapper with VTablePointerInit(v16) at the end of each iteration. [callee:0x0057B7F0, source:raw]
    // CALL: Call MutexCallbackDispatch(this) to drain the pending callback queue after the iteration. [callee:0x0057E3A0, source:raw]
    // GUARD: If the mutex handle at this+0xAD8 is non-null, release it. [field:this:0x00000AD8, source:raw]
    // CALL: Call ReleaseMutex(handle) on the mutex. [global:0x0059E1A4, field:this:0x00000AD8, source:raw]
    // RETURN: Return the last computed result (MutexCallbackDispatch return, or the ReleaseMutex return when the mutex was held). [function:0x0057E280, source:raw]

    // Conservative worker pseudocode:
    //   v3 = *((float *)this + 682) - a2;
    //   *((float *)this + 682) = v3;
    //   if (v3 <= 0.0f) {
    //     *((_DWORD *)this + 682) = 1040187392;
    //     v9 = MutexProtectedPointerReadRelease(this) == 4;
    //     v18 = !v9;
    //     v10 = *((_DWORD *)this + 694);
    //     if (v10) WaitForSingleObject(v10, *((_DWORD *)this + 695));
    //     v11 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 164))(this);
    //     for (i = 0; i < v11; ++i) {
    //       ObjectInitWithVTableFieldSet(v16, 0, 0, 0);
    //       if ((*(int (__thiscall **)(void *, int, _DWORD *))(*(_DWORD *)this + 172))(this, i, v16)
    //           && (!v18 || sub_587220(v16) == 2)) {
    //         v14 = ReadFieldAtOffset0x14(v16);
    //         sub_585870(v14, 0);
    //       }
    //       VTablePointerInit(v16);
    //     }
    //     result = MutexCallbackDispatch(this);
    //     v15 = *((_DWORD *)this + 694);
    //     if (v15) return ReleaseMutex(v15);
    //   }
    //   return result;
    // UNRESOLVED: SEH_57E280 (0x0059C9F8) is the structured exception handler registration for this function; it does not appear in the raw function body.
    // UNRESOLVED: flt_59E440 (0x0059E440) is listed as a read global but does not appear in the raw function body; its role here is unknown.
    // UNRESOLVED: Called from AudioUpdateWrapper (0057ea10) and NetworkFileTransferAcceptHandler (0058119a); no frame-path evidence for this function.
    // UNRESOLVED: The managed object type, the vtable offset 172 fetch contract and the sub_587220(v16) == 2 filter are DERIVED from the call sites; the exact semantics of the 4 comparison from MutexProtectedPointerReadRelease are unresolved.
    // UNRESOLVED: The literal 1040187392 is the float bit pattern 0.125f, the reset value of the countdown timer.
}
