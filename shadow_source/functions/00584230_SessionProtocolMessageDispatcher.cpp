// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00584230
// Canonical corpus name: sub_584230
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_584230_00584230.c

void UnknownObject::SessionProtocolMessageDispatcher()
{
    // Multiplayer session-protocol message dispatcher. Decodes a bitmask of pending connection/handshake IDs from the packet entry table a2 (base a2[7]+4*a2[14], count a2[14], caller mask a2[5]), then switches on the decoded bitmask v46 to route one of 15 message types (connection request, ping/latency, HST/clock, node added/removal, data transfer, clock sync) through this-object vtable slots, with mutex-guarded shared fields (this+0x5C4, this+0x618). Unhandled bitmask values return 0; every handled case returns the success flag 1.
    // ASSIGNMENT: Initialize the success flag v49=1, clear the bitmask accumulators v46/v45, and base the packet entry table read at a2[7] + 4*a2[14]. [source:raw]
    // CALCULATION: Read the first entry word and the entry count v47 from the table; derive the last-entry index v50 = count + first_word - 1. [source:raw]
    // LOOP: Iterate the table entries; for each index call IndexToBitmaskConversion and OR 1<<idx into v46 when the caller-supplied mask a2[5] has that bit set. [field:obj:0x00000014, callee:0x00585E80, source:raw]
    // STATE_TRANSITION: Dispatch on the decoded bitmask v46 through jump table jpt_5842F3 into the 15 message-type handlers; the default case returns 0. [global:0x00584C28, source:raw]
    // CALL: Case 1 (connection request): after the vtable+64 gate and StatusCheckViaVTableDispatch, compare the UtilityFunction_6a90(a2) payload against 16 bytes at this+11 via F_16ByteMemoryComparisonForEquality; read the incoming node id via vtable 120, write it via vtable 196, post sub_586800(0,2,0,1,-1), serialize the node via vtable 16 and SingleFunctionCallWrapper_6a00; build the node-name string (fallback aUnknownNode) and append the sender id triple {dword_5E6380, dword_5E6384, byte_5E6388} when the reply flag is clear; push the name through FieldGetter_5cc0 target vtable 28 and call EmptyStub_0170. [callee:0x00585220, callee:0x00586A90, callee:0x0057A0C0, callee:0x00586800, callee:0x00586A00, callee:0x00585CC0, callee:0x004B0170, field:this:0x00000000, global:0x005E638C, global:0x005E6380, global:0x005E6384, global:0x005E6388, source:raw]
    // CALL: Case 2 (ping/latency): read the peer id via vtable 132 and open the session via vtable 120; copy the packet via SingleFunctionCallWrapper_6a80 + BoundedMemoryCopyWithSizeValidation; compute round-trip latency as (MutexGuardedTimerRead(this) - stored) * 0.5 into the session buffer; log the 'Unknown Address' name (aUnknownAddress, vtable 4 with fallback), emit it through FieldGetter_5cc0 target vtable 12, call EmptyStub_0170 and vtable 52. [callee:0x00586A80, callee:0x00586A10, callee:0x00584F90, global:0x005E6370, callee:0x00585CC0, callee:0x004B0170, field:this:0x00000000, source:raw]
    // CALL: Case 3 (HST/clock): gate on StatusCheckViaVTableDispatch; when set, compare the ArithmeticComparison_5020(this) token against the 16-byte identity built by sub_587DD0(v52, byte_5EA438, 16); on mismatch post sub_586800(0,5,1,1,-1); on match post sub_586800(0,4,1,1,-1), push the node via vtable 144/140 and sub_585870, emit through SingleFunctionCallWrapper_6a00 and VTableDispatchWithConditionalCall. [callee:0x00585220, callee:0x00585020, callee:0x00587DD0, global:0x005EA438, callee:0x00586800, callee:0x00586A00, callee:0x00585870, callee:0x00585380, field:this:0x00000000, source:raw]
    // CALL: Case 4 (node added): read the 2-byte node id via BoundedMemoryCopyWithSizeValidation; when present write it via MutexProtectedFieldWrite and vtable 152; log the aAddedNode name via vtable 4 (fallback aUnknownNode) and FieldGetter_5cc0 target vtable 16; call EmptyStub_0170 and ThreadSafeWriteWithMutex(3). [callee:0x00586A10, callee:0x005857C0, global:0x005E6364, global:0x005E638C, callee:0x00585CC0, callee:0x004B0170, callee:0x00585CD0, field:this:0x00000000, source:raw]
    // CALL: Case 5 (HST): ThreadSafeWriteWithMutex(0); read a 2-byte value via BoundedMemoryCopyWithSizeValidation; WaitForSingleObject(this[390]=this+0x618, 5); when not a timeout write this[369]=this+0x5C4 with the value; ReleaseMutex(this[390]); log the aHst name (fallback aUnknownNode) through FieldGetter_5cc0 target vtable 16; call EmptyStub_0170. [callee:0x00585CD0, callee:0x00586A10, global:0x0059E1A0, field:this:0x00000618, field:this:0x000005C4, global:0x0059E1A4, global:0x005E6360, global:0x005E638C, callee:0x00585CC0, callee:0x004B0170, field:this:0x00000000, source:raw]
    // RETURN: Case 6: no-op; immediately return the success flag v49. [source:raw]
    // CALL: Case 7 (clock sync): read a double via vtable 8 and, when non-zero, forward its low dword through vtable 148. [field:this:0x00000000, source:raw]
    // LOOP: Case 8 (data transfer): repeatedly read up to 768 bytes via BoundedMemoryCopyWithSizeValidation until a size less than 4 is returned; classify direction with MutexProtectedPointerReadRelease()==4 and forward the buffer via vtable 176. [callee:0x00586A10, callee:0x00585D20, field:this:0x00000000, source:raw]
    // CALL: Case 9: read a 4-byte payload via BoundedMemoryCopyWithSizeValidation; on success forward it through vtable 148. [callee:0x00586A10, field:this:0x00000000, source:raw]
    // CALL: Case 10 (node lookup): open the session via vtable 120; resolve the payload via vtable 20 with UtilityFunction_6a90(a2); deliver through vtable 192 and FieldGetter_5cc0 target vtable 40; call EmptyStub_0170 and close via vtable 124. [callee:0x00586A90, callee:0x00585CC0, callee:0x004B0170, field:this:0x00000000, source:raw]
    // CALL: Case 11 (ping request): post sub_586800(0,12,0,2,-1); send the literal -1082130432 (used as a float) via BoundedMemoryCopyWithSizeValidation and SingleFunctionCallWrapper_6a00; format 'Ping Request from %s' with StringFormatWithBufferOverflowCheck using the aPingRequestFro format string; emit through FieldGetter_5cc0 target vtable 24; call EmptyStub_0170. [callee:0x00586800, callee:0x00586A10, callee:0x00586A00, callee:0x0058815F, global:0x005E6348, callee:0x00585CC0, callee:0x004B0170, field:this:0x00000000, source:raw]
    // CALL: Case 12 (clock data): send the literal -1082130432 (used as a float); read the timer via MutexGuardedTimerRead, convert it with CRTFtol, and forward half the value through vtable 20. [callee:0x00586A10, callee:0x00584F90, callee:0x00587BDC, field:this:0x00000000, source:raw]
    // CALL: Case 13 (data transfer): read a2[1], obtain the payload via SingleFunctionCallWrapper_6a80(a2) and UtilityFunction_6a90(a2), and forward the triple through BufferCopyViaVirtualTypeDispatch. [field:obj:0x00000004, callee:0x00586A80, callee:0x00586A90, callee:0x00587930, source:raw]
    // CALL: Case 14 (HST/clock message): read a double via BoundedMemoryCopyWithSizeValidation; build the 8-byte message {0x20000000, -942485805} with the value; call FieldGetter_5cc0 target vtable 8 with payload and name buffers; call EmptyStub_0170; on success post sub_586800(0,15,0,3,-1) and emit via SingleFunctionCallWrapper_6a00. [callee:0x00586A10, callee:0x00585CC0, callee:0x004B0170, callee:0x00586800, callee:0x00586A00, field:this:0x00000000, source:raw]
    // CALL: Case 15 (clock): initialize a record {v53=-1, v54=-9.999999680285692e37, v55=0}, read 268 bytes via BoundedMemoryCopyWithSizeValidation, read the timer via MutexGuardedTimerRead, and assemble the record into this+1616 through sub_583700. [callee:0x00586A10, callee:0x00584F90, callee:0x00583700, source:raw]
    // RETURN: Unhandled bitmask values return 0; every handled case returns the success flag v49=1. Invoked as a message dispatcher by VTableDispatchWithConditionalBranch (00585400). [caller:0x00585400, function:0x00584230, source:raw]

    // Conservative worker pseudocode:
    //   char SessionProtocolMessageDispatcher(this, a2) {
    //     success = 1; mask = 0;
    //     tbl = a2[7] + 4*a2[14]; count = tbl[1]; end = tbl[0] + count - 1;
    //     for (idx = 0; idx < count; ++idx)
    //       if (bitmask(test(idx)) & a2[5]) mask |= 1 << idx;
    //     switch (mask) {
    //       case 1:  /* connection request: verify, register node id, announce * /
    //       case 2:  /* ping/latency: copy payload, compute round-trip * /
    //       case 3:  /* HST: token check, node push * /
    //       case 4:  /* node added: store id, announce * /
    //       case 5:  /* HST: mutex-guarded id write this+0x5C4 * /
    //       case 7:  /* clock sync: forward read * /
    //       case 8:  /* data transfer: chunked read + direction forward * /
    //       case 9:  /* forward 4-byte payload * /
    //       case 10: /* node lookup: resolve + deliver * /
    //       case 11: /* ping request: broadcast 'Ping Request from <name>' * /
    //       case 12: /* clock data: send half-timer * /
    //       case 13: /* data transfer: copy triple * /
    //       case 14: /* clock message: build + emit * /
    //       case 15: /* clock: assemble record via sub_583700 * /
    //       default: return 0;
    //     }
    //     return success;
    //   }
    // UNRESOLVED: SEH scope handler SEH_584230, float constant flt_59E450, and double constant dbl_59ECC8 are flagged by packet facts but do not appear in the raw decompiled source.
    // UNRESOLVED: Sixteen read-only packet fields on obj (a2[0], a2[2], a2[13], a2[16], a2[22], a2[23], a2[30], a2[31], a2[33], a2[35], a2[36], a2[37], a2[38], a2[44], a2[48], a2[49]) are not referenced by the visible raw source; they are consumed indirectly inside the dispatch helpers or other message handlers.
    // UNRESOLVED: The exact wire format of each of the 15 message payloads is not recoverable from this function alone.
}
