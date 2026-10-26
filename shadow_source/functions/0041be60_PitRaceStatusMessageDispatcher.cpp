// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041BE60
// Canonical corpus name: PitRaceStatusMessageDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitRaceStatusMessageDispatcher_0041be60.c

void UnknownObject::PitRaceStatusMessageDispatcher()
{
    // Dispatches pit/race status driver-table messages (IDs 506-513) when the race is active (dword_7D0308) and the track-condition state (flt_7CF3C8) is non-zero. Computes a classification v0 via sub_4FF130(&unk_8AFEC0) and an audio filter parameter v1 via AudioFilterParameterCalculation(&unk_8AFEC0), then switches on v0 to record and insert driver-table entries, gated by a temperature threshold (flt_8AFEF0 > 30.0) and a track-grip-average check ((flt_8AFEE8 + flt_8AFEEC) * 0.5 > 0.7). Called from sub_40DE60 (0x0040DE60).
    // GUARD: Guard on dword_7D0308 being nonzero and flt_7CF3C8 != 0.0; the whole dispatch body runs only while the race is active and the track-condition state is non-zero. [global:0x007D0308, global:0x007CF3C8, source:raw]
    // CALL: Initialize the local driver-table entry buffer v2 with sentinel/default values via StructInitWithSentinelValues(v2). [callee:0x004144D0, source:raw]
    // CALL: Compute the classification v0 = sub_4FF130(&unk_8AFEC0) from the pit-condition structure. [callee:0x004FF130, global:0x008AFEC0, source:raw]
    // CALL: Compute the audio filter parameter v1 = AudioFilterParameterCalculation(&unk_8AFEC0) from the same structure. [callee:0x004FF1D0, global:0x008AFEC0, source:raw]
    // STATE_TRANSITION: Dispatch on v0 through the jump table jpt_41BEB4 (0x0041C07C) with cases 2, 3, 4, 5 and a default return. [global:0x0041C07C, function:0x0041BE60, source:raw]
    // STATE_TRANSITION: Case 2: when v1 != 2 fall through to the default entry 512; otherwise record message 506 via DriverDataTableLookupAndTimeConversion and insert it with InsertDriverTableEntry(flt_5EA618, v2). [callee:0x004144F0, callee:0x00418560, global:0x005EA618, source:raw]
    // GUARD: Within case 2, when flt_8AFEF0 > 30.0 record the follow-up message 507 and insert it as well. [global:0x008AFEF0, callee:0x004144F0, callee:0x00418560, global:0x005EA618, source:raw]
    // STATE_TRANSITION: Case 3: record message 509 when v1 is 3 or 2, otherwise record message 512; then the shared grip-average check may record message 513. [callee:0x004144F0, source:raw]
    // CALCULATION: Shared track-grip-average threshold (flt_8AFEE8 + flt_8AFEEC) * 0.5 > 0.7 that gates recording and inserting message 513. [global:0x008AFEE8, global:0x008AFEEC, callee:0x004144F0, callee:0x00418560, global:0x005EA618, source:raw]
    // STATE_TRANSITION: Case 4: when v1 is 4 or 5 record message 510 and insert it, otherwise fall through to the default message 512 path. [callee:0x004144F0, callee:0x00418560, global:0x005EA618, source:raw]
    // STATE_TRANSITION: Case 5: when v1 is 4 or 5 record message 511 and insert it, and the shared grip-average check may then record message 513; otherwise record message 512 and insert it. [callee:0x004144F0, callee:0x00418560, global:0x005EA618, source:raw]
    // RETURN: Default case and the final case-2 path return without recording a message. [function:0x0041BE60, source:raw]
    // CALL: Invoked from sub_40DE60 (0x0040DE60) in the pit/session message path. [caller:0x0040DE60]

    // Conservative worker pseudocode:
    //   void PitRaceStatusMessageDispatcher() {
    //     if (!dword_7D0308 || flt_7CF3C8 == 0.0) return;
    //     StructInitWithSentinelValues(v2);
    //     v0 = sub_4FF130(&unk_8AFEC0);
    //     v1 = AudioFilterParameterCalculation(&unk_8AFEC0);
    //     switch (v0) {
    //       case 2:
    //         if (v1 == 2) { record(506); insert(flt_5EA618, v2);
    //           if (flt_8AFEF0 > 30.0) { record(507); insert(flt_5EA618, v2); } }
    //         else record_default_and_insert();
    //         break;
    //       case 3:
    //         if (v1 == 3 || v1 == 2) record(509); else record(512);
    //         if (avg_grip() > 0.7) { record(513); insert(flt_5EA618, v2); }
    //         break;
    //       case 4:
    //         if (v1 == 4 || v1 == 5) { record(510); insert(flt_5EA618, v2);
    //           if (avg_grip() > 0.7) { record(513); insert(flt_5EA618, v2); } }
    //         else record_default_and_insert();
    //         break;
    //       case 5:
    //         if (v1 == 4 || v1 == 5) { record(511); insert(flt_5EA618, v2);
    //           if (avg_grip() > 0.7) { record(513); insert(flt_5EA618, v2); } }
    //         else { record(512); insert(flt_5EA618, v2); }
    //         break;
    //       default: return;
    //     }
    //   }
    // UNRESOLVED: The read-only floats flt_59E440, flt_59E450, flt_59E468 and dbl_59E830 are read per the deterministic fact table but do not appear in the decompiled body; likely constants folded into the classification/audio-filter path.
    // UNRESOLVED: The precise meaning of the v0 switch cases and the v1 values 2/3/4/5 is not established here; the correspondence between classification codes and message IDs 506-513 is inferred from the call sites only.
}
