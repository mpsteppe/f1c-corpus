// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9B80
// Canonical corpus name: sub_4B9B80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B9B80_004b9b80.c

void UnknownObject::TimedAudioWithVehicleUpdateDispatch()
{
    // Orders a timed-audio event range into ascending (start, end) endpoints read from the object field at +0xF3C, plays events in that range via TimedAudioEventPlayback, resets the audio ring buffer, then re-scales both endpoints by 40.0 and converts to integers. If the two integer buckets differ, it iterates all vehicles (count from dword_5C329C, pointer array dword_7C54F0), calling sub_4EE2D0 per vehicle and MultiObjectRemove for the supplied position.
    // GUARD: If a2 equals the sentinel value -9.9999997e37, fall back to FloatGetter(*this) to obtain the current float value. [source:raw, callee:0x004B8790, field:this:0x00000000]
    // ASSIGNMENT: Read the start-of-range value from object field *this + 0xF3C into v10. [source:raw, field:obj:0x00000F3C]
    // ASSIGNMENT: Initialize v11 = a2 (end of range) and v12 = 1 (ordered flag). [source:raw]
    // GUARD: If a2 < v10, swap so v11 = field +0xF3C value, v10 = a2, and mark v12 = 0 (range was reversed). [source:raw, field:obj:0x00000F3C]
    // CALL: Call TimedAudioEventPlayback(*this, v10, v11, v12) to process audio events between the ordered time endpoints. [source:raw, callee:0x004B9510]
    // CALL: Call BufferReset(&dword_83EE60) to clear the audio ring buffer counter. [source:raw, callee:0x004B3B40, global:0x0083EE60]
    // CALCULATION: Scale the first endpoint: v3 = v10 * 40.0. [source:raw]
    // CALL: Call sub_5895A2(v3) to synchronize the audio buffer at the scaled start position. [source:raw, callee:0x005895A2]
    // CALL: Convert the scaled start value with CRTFtol (float-to-int) into v4. [source:raw, callee:0x00587BDC]
    // CALCULATION: Scale the second endpoint: v5 = v11 * 40.0. [source:raw]
    // CALL: Call sub_5895A2(v5) to synchronize the audio buffer at the scaled end position. [source:raw, callee:0x005895A2]
    // CALL: Convert the scaled end value with CRTFtol (float-to-int) into result. [source:raw, callee:0x00587BDC]
    // GUARD: If the two integer buckets differ (v6 != result), the range crosses a bucket boundary. [source:raw]
    // ASSIGNMENT: Read the vehicle count from dword_5C329C into v8. [source:raw, global:0x005C329C]
    // LOOP: Loop i over all vehicles in [0, v8). [source:raw]
    // CALL: Call sub_4EE2D0(dword_7C54F0[i] + 12) on each vehicle pointer from the active-vehicle array. [source:raw, callee:0x004EE2D0, global:0x007C54F0]
    // CALL: Call MultiObjectRemove(a2) inside the loop and store its result. [source:raw, callee:0x004E3A50]
    // RETURN: Return result (the last MultiObjectRemove result, or the CRTFtol bucket value when the loop is skipped). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B9B80(float **self, float end) {
    //     if (end == -9.9999997e37f) end = FloatGetter(*self);
    //     float start = *(float *)(*self + 0xF3C);
    //     float end2 = end; char ordered = 1;
    //     if (end < start) { end2 = start; start = end; ordered = 0; }
    //     TimedAudioEventPlayback(*self, start, end2, ordered);
    //     BufferReset(&dword_83EE60);
    //     int a = CRTFtol(start * 40.0); sub_5895A2(start * 40.0);
    //     int b = CRTFtol(end2 * 40.0); sub_5895A2(end2 * 40.0);
    //     int result = b;
    //     if (a != b) {
    //       for (int i = 0; i < dword_5C329C; ++i) {
    //         sub_4EE2D0(dword_7C54F0[i] + 12);
    //         result = MultiObjectRemove(end);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Role of float globals flt_59E86C and flt_5ACD04: read by this function but not named in the decompiled source text; likely consumed by the inlined CRTFtol float-to-int conversion.
    // UNRESOLVED: Purpose and argument semantics of the sub_5895A2 sync calls.
    // UNRESOLVED: Meaning of the +12 offset applied to each vehicle pointer passed to sub_4EE2D0.
    // UNRESOLVED: Semantics of a2 passed unchanged to MultiObjectRemove (likely a time or world position).
}
