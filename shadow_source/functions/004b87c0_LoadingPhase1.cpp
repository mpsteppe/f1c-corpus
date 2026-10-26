// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B87C0
// Canonical corpus name: LoadingPhase1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LoadingPhase1_004b87c0.c

void UnknownObject::LoadingPhase1()
{
    // First phase of session loading: pops the session queue, returns early when the range width (upper minus lower angle bound) is not positive, resolves a loading resource, then iterates the vehicle array to initialise per-vehicle effect tables and state/visibility bytes. Afterwards sets angle clamp mode, marks the loading-phase flag, and runs state-trigger checks in a loop bounded by a 0.75 accumulator. Returns 1 on success, 0 when the range width check fails.
    // CALL: Pop one entry from the session loading queue at entry. [callee:0x004B7A00, source:raw]
    // GUARD: Return 0 when the range width, computed as the upper bound at +0xF34 minus the lower bound at +0xF30, is not positive. [field:this:0x00000F30, field:this:0x00000F34, source:raw]
    // RETURN: Return 0 on the failed-width path. [source:raw]
    // ASSIGNMENT: Resolve the loading resource and store its handle into the field at +0xF40. [callee:0x00566E20, field:this:0x00000F40, source:raw]
    // ASSIGNMENT: Set the clamp-mode byte at +0xF81 to 1. [field:this:0x00000F81, source:raw]
    // LOOP: Iterate over the vehicle pointer array (dword_7C54F0) for the vehicle count given by dword_5C329C. [global:0x007C54F0, global:0x005C329C, source:raw]
    // CALL: Remove multi-object effects for the current session range bound. [callee:0x004E3A50, source:raw]
    // CALL: Initialise effect data tables for the current vehicle (vehicle pointer plus 1776). [callee:0x004E1970, source:raw]
    // ASSIGNMENT: Store the vehicle+13000 DWORD into the per-vehicle slot at field +0x734. [field:this:0x00000734, source:raw]
    // ASSIGNMENT: Copy the vehicle+4189 byte into the driver state slot 104 bytes before the array headed at field +0x93C. [field:this:0x0000093C, source:raw]
    // ASSIGNMENT: Write the boolean (vehicle+18620 bit 2 is set) into the per-vehicle array slot at field +0x93C. [field:this:0x0000093C, source:raw]
    // CALL: Transition the session state machine to state 3. [callee:0x004EF5A0, source:raw]
    // CALL: Apply angle clamping/wrapping driven by dbl_8AFEA0 via AngleClampWrap. [callee:0x004B86E0, global:0x008AFEA0, source:raw]
    // CALL: Set the conditional index via ConditionalIndexSetter(0). [callee:0x004D8840, source:raw]
    // ASSIGNMENT: Set the loading-phase byte at +0xF80 to 1. [field:this:0x00000F80, source:raw]
    // CALCULATION: Accumulate dbl_8AFE90 into a loop value used as the iteration bound. [global:0x008AFE90, source:raw]
    // CALL: Run ReciprocalWithSignCheck on flt_5EA4E8 with the value 0.75. [callee:0x00408420, global:0x005EA4E8, source:raw]
    // LOOP: Loop calling StateTriggerCheck while the accumulated value stays below 0.75. [callee:0x004B8AE0, source:raw]
    // RETURN: Return 1 on success. [source:raw]

    // Conservative worker pseudocode:
    //   bool LoadingPhase1(int this) {
    //     QueuePop(this);
    //     if (this.f32[0xF34] - this.f32[0xF30] <= 0.0f) return false;
    //     this.dword[0xF40] = ResourceLookupDispatcher(this + 1764);
    //     this.byte[0xF81] = 1;
    //     int count = dword_5C329C;
    //     for (int i = 0; i < count; ++i) {
    //       veh = dword_7C54F0[i];
    //       MultiObjectRemove(this.f32[0xF30]);
    //       EffectDataTableInitialization(veh + 1776);
    //       this.dword[0x734 + 4*i] = veh.dword[13000];
    //       this.byte[0x93C - 104 + i] = veh.byte[4189];
    //       this.byte[0x93C + i] = (veh.dword[18620] & 2) != 0;
    //       SessionStateTransition(3, 0);
    //     }
    //     AngleClampWrap(this, dbl_8AFEA0);
    //     ConditionalIndexSetter(0);
    //     this.byte[0xF80] = 1;
    //     ReciprocalWithSignCheck(&flt_5EA4E8, 0.75);
    //     for (float acc = 0.0f; acc < 0.75f; acc += dbl_8AFE90) {
    //       int one = 1; StateTriggerCheck(&one);
    //     }
    //     return true;
    //   }
    // UNRESOLVED: Packet lists globals flt_59E440, flt_5ACD1C and dword_8AD298 but the raw source shows no direct use; the prose names (ZeroThreshold, AIFollowDistThreshold, SessionModeIdentifier) are not verifiable from this packet.
    // UNRESOLVED: The driver state slot 104 bytes before the field +0x93C array has no packet field reference.
    // UNRESOLVED: Identity and purpose of the resource handle resolved from this+1764 is not derivable here.
    // UNRESOLVED: Meaning of the accumulated dbl_8AFE90 value and its 0.75 threshold is not explained by this packet.
}
