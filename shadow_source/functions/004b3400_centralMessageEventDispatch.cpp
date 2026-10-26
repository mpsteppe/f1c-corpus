// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B3400
// Canonical corpus name: sub_4B3400
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B3400_004b3400.c

void UnknownObject::centralMessageEventDispatch()
{
    // Central message/event packet dispatcher. Reads a 32-bit header at this+0 and routes on major type (bits 29-31): type 1 vehicle input/control, type 2 vehicle state/position, type 3 UI/sound, type 4 session/race control, type 6 AI/motion. Each major type decodes a sub-type (bits 18-23) and a vehicle index (low byte, bounds-checked below 0x68) and forwards the payload to domain handlers including collision dispatch, wheel input decoding, scoring, lap completion, pit-timer and pit-crew state, grid reordering, MIDI parsing, audio and AI state dispatch. Called from BufferReset, consistent with network/replay event processing.
    // CALCULATION: Reads the 32-bit message header at this+0 and computes the major type as bits 29-31, selected through the switch jump table jpt_4B341A; the ABI lead names this function the central message/event dispatcher, invoked by BufferReset. [field:this:0x00000000, global:0x004B39E8, abi:lead, caller:0x004B3B40, source:raw]
    // GUARD: Major type 1 (vehicle input/control), sub-types 0 and 7: if the vehicle index (low byte, < 0x68) has slot state 2 in the vehicle array at unk_5EC6D8 (+3250 dword), calls CollisionParameterDispatch, then ShortComputation_2b00 on the payload at this+2 and PropertySetter on the result. [callee:0x00463D10, callee:0x004B2B00, callee:0x004C7BF0, global:0x005EC6D8, global:0x004B3A00, source:raw]
    // CALL: Major type 1 sub-types 1-6: if dword_5EF9A0 slot for the vehicle index equals 2, decodes wheel controller input via WheelControllerInputDecoder(dword_5EA560, this). [callee:0x00410BC0, global:0x005EA560, global:0x005EF9A0, source:raw]
    // CALL: Major type 2 sub-type 0: for a vehicle slot (< 0x68) applies ScoringGateValueSelect to the vehicle struct then RandomParameterDispatch on the per-slot area; the sub-type switch uses the jump table jpt_4B34CF. [callee:0x004E2C70, callee:0x004F8A70, global:0x005EC6D8, global:0x004B3A10, source:raw]
    // ASSIGNMENT: Major type 2 sub-type 2: for an active slot (slot state >= 2) copies the 16-byte plus word position payload from this+8..this+0xB into the vehicle struct at offset +4136; if the sub-type bits (v2 & 0x3FF00) equal 0x600 it also clears this[0xE] and the dword at this+0x10. [field:this:0x00000008, field:this:0x00000009, field:this:0x0000000A, field:this:0x0000000B, field:this:0x0000000E, field:this:0x00000010, global:0x005EC6D8, source:raw]
    // CALL: Major type 2 sub-types 4 and 5: forwards the event to CarPositionTargetCheck and StringNameMatching respectively. [callee:0x004FE060, callee:0x004FC700, source:raw]
    // ASSIGNMENT: Major type 2 sub-type 6: stores a normalized value flt_8AFEDC = (double)(byte)this[8] * 0.0039215689. [field:this:0x00000008, global:0x008AFEDC, source:raw]
    // CALCULATION: Major type 2 sub-type 7: scales the packed byte position fields at this+8..this+0xD into float vectors (factors 0.0078740157 with 1.5 and 3.5 multipliers) and applies RepeatedPositionOffsetTransform with the int32 read at this+0xE. [field:this:0x00000008, field:this:0x00000009, field:this:0x0000000A, field:this:0x0000000B, field:this:0x0000000C, field:this:0x0000000D, field:this:0x0000000E, callee:0x004E3940, source:raw]
    // CALL: Major type 2 sub-type 8: runs VehicleWheelCountIterator on the payload dword at this+8 for the vehicle slot. [callee:0x004E3A10, field:this:0x00000008, source:raw]
    // CALL: Major type 3 (UI/sound) sub-type 6: calls ListSearchWithGlobalMatch(&flt_8AC4B0) then updates flt_8AC4B0 from the float payload at this+4. [callee:0x004C81A0, global:0x008AC4B0, field:this:0x00000004, source:raw]
    // CALL: Major type 3 sub-type 7: if byte_7CE254 is clear, picks a random sound slot via RandLCGRandomNumberGenerator(0) % 3 + 5 and plays it with SoundEffectLoadPlay. [callee:0x004C8DE0, callee:0x005884ED, global:0x007CE254, source:raw]
    // LOOP: Major type 4 sub-type 7 (grid reorder): loops over ((v2 >> 8) & 0x3FF) - 12 entries; per entry calls ConditionalFieldSetter and rewires the previous/next vehicle pointers in the unk_5F070C grid array (offsets +39/+40, 18624-byte stride) using the slot byte this[v19+20], copies the this+8 float triplet into the first entry when v19 == 0, and records the slot byte into byte_8AD008. The sub-type switch uses the jump table jpt_4B3764. [callee:0x004BC2F0, global:0x005F070C, global:0x008AD008, global:0x004B3A34, field:this:0x00000014, field:this:0x00000008, source:raw]
    // CALL: Major type 4 sub-type 8 (lap completion): if the vehicle slot state is 2 or 3, calls LapCompletion with the float and int16 payload at this+4, this+8, this+0xC and this+0xE. [callee:0x004BC4E0, global:0x005EC6D8, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x0000000E, source:raw]
    // CALL: Major type 4 sub-types 10/11: parses a MIDI bitstream via ParseMidiBitstream(this). [callee:0x004D1A50, source:raw]
    // CALL: Major type 4 sub-type 20: if dword_8AB6E4 != 2, initializes the pit timer via PitTimerStateInit(this). [callee:0x004D23D0, global:0x008AB6E4, source:raw]
    // CALL: Major type 4 sub-types 21/23/24/26/27: forwards to FieldSetterWithInit, AccumulatorWithFixedArray, ArrayShiftConditionalDispatch (on the unk_5F070C slot), and PitCrewStateMachine respectively. [callee:0x004D22C0, callee:0x004BBED0, callee:0x004BBF70, callee:0x004BBFC0, global:0x005F070C, source:raw]
    // ASSIGNMENT: Major type 4 sub-type 28: writes slot state 3 into dword_5F073C[4656 * vehicle_index]; sub-types 33/34 set or clear byte_8ACFE4 (1 or 0). [global:0x005F073C, global:0x008ACFE4, source:raw]
    // CALL: Major type 6 (AI/motion) sub-type 0: for a slot (< 0x68) applies ActorMotionPostProcessingUpdate to the vehicle struct and UIElementMultiDispatch on the payload dword at this+8. [callee:0x004ED030, callee:0x004E39D0, field:this:0x00000008, source:raw]
    // CALL: Major type 6 sub-type 1: if the vehicle slot AI state is 2, dispatches to AIStateMachineWithModeDispatch on the slot area. [callee:0x004A5D10, global:0x005EC6D8, source:raw]
    // RETURN: Returns the last dispatch result byte v3; unhandled major types and unhandled sub-types return v3 unchanged. [function:0x004B3400, source:raw]

    // Conservative worker pseudocode:
    //   header = *(uint32*)this;
    //   major = header >> 29;
    //   switch (major) {
    //     case 1: sub = (header >> 18) & 0x3F;
    //       switch (sub) {
    //         case 0: case 7: if (idx < 0x68 && vehicle[idx].state == 2) { CollisionParameterDispatch(idx, this); PropertySetter(ShortComputation_2b00((uint32*)this + 2)); } break;
    //         case 1..6: if (dword_5EF9A0[4656*idx] == 2) WheelControllerInputDecoder(dword_5EA560, this); break;
    //         default: return sub; } break;
    //     case 2: sub = (header >> 18) & 0x3F;
    //       switch (sub) {
    //         case 0: if (idx < 0x68) { ScoringGateValueSelect(slot+1776); RandomParameterDispatch(slot+20); } break;
    //         case 2: if (idx < 0x68 && slot.state >= 2) { if ((header & 0x3FF00) == 0x600) { this[14]=0; *(uint32*)(this+4)=0; } copy16(this+8, slot+4136); copyw(this+16, slot+4144); } break;
    //         case 4: CarPositionTargetCheck(this); break;
    //         case 5: StringNameMatching(this); break;
    //         case 6: flt_8AFEDC = (double)this[8] * 0.0039215689; break;
    //         case 7: if (idx < 0x68) RepeatedPositionOffsetTransform(*(uint32*)(this+14), scaled_vec, offset_vec); break;
    //         case 8: if (idx < 0x68) VehicleWheelCountIterator(*(uint32*)(this+2)); break;
    //         default: return sub; } break;
    //     case 3: v16 = ((header >> 18) & 0x3F) - 6;
    //       if (v16 == 0) { ListSearchWithGlobalMatch(&flt_8AC4B0); flt_8AC4B0 = *(float*)(this+4); }
    //       else if (v16 == 1) { if (!byte_7CE254) SoundEffectLoadPlay(RandLCG(0) % 3 + 5, ...); } break;
    //     case 4: sub = (header >> 18) & 0x3F;
    //       switch (sub) {
    //         case 7: for (i = 0; i < ((header >> 8) & 0x3FF) - 12; i++) reorder_grid_entry(i); break;
    //         case 8: if (idx < 0x68 && (slot_state==2 || slot_state==3)) LapCompletion(...); break;
    //         case 10: case 11: ParseMidiBitstream(this); break;
    //         case 20: if (dword_8AB6E4 != 2) PitTimerStateInit(this); break;
    //         case 21: FieldSetterWithInit(this); break;
    //         case 23: AccumulatorWithFixedArray(this); break;
    //         case 24: ArrayShiftConditionalDispatch(slot); break;
    //         case 26: case 27: PitCrewStateMachine(this); break;
    //         case 28: dword_5F073C[4656*idx] = 3; break;
    //         case 33: byte_8ACFE4 = 1; break;
    //         case 34: byte_8ACFE4 = 0; break;
    //         default: return sub; } break;
    //     case 6: sub = (header >> 18) & 0x3F;
    //       if (sub == 0) { if (idx < 0x68) { ActorMotionPostProcessingUpdate(slot+12); UIElementMultiDispatch(*(uint32*)(this+2)); } }
    //       else if (sub == 1) { if (slot.state == 2) AIStateMachineWithModeDispatch(slot+3251, this); } break;
    //     default: break; }
    //   return result;
    // UNRESOLVED: Thirteen packet-listed globals do not appear in the raw body and their exact role is unverified: jump-table-adjacent byte_4B3A08 and byte_4B3A68, float constants flt_59E440, flt_59E460, flt_59E8A4, flt_5ACCE8, flt_5ACCEC, and the objects unk_5ECDC8, dword_7CD25C, byte_8AC494, dword_8ACEE0, unk_8AFEC0, unk_8AFFC8.
    // UNRESOLVED: field:this+0x18 is listed as read but no this+0x18 access appears in the raw body; it is likely read inside a callee such as LapCompletion or PitTimerStateInit.
    // UNRESOLVED: Exact semantics of the slot-state values (2, 3) and the sub-type constants depend on caller/protocol context not present in the packet.
}
