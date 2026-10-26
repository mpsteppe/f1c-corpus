// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9AC0
// Canonical corpus name: sub_4B9AC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B9AC0_004b9ac0.c

void UnknownObject::LookupAndDispatchAudioSample()
{
    // Audio sample dispatch by position/state. Fetches a current float when the caller passes the sentinel value -9.9999997e37, finds a matching audio entry in the linked list at this+0x0 via LinkedListTraversalWithFilter, then selects one of three playback paths based on the state fields at entry+36: a passthrough wrapper over entry+146, direct pitch-modulated stereo playback, or a passthrough wrapper over entry+38. Returns 0 when no entry is found.
    // GUARD: When the position parameter a4 equals the sentinel value -9.9999997e37, replace it with the current float obtained from FloatGetter(this+0x0) as a fallback fetch. [source:raw, global:0x005ACD04, callee:0x004B8790, field:this:0x00000000]
    // CALL: Traverse the audio data linked list at this+0x0 with LinkedListTraversalWithFilter(this+0x0, a2, a4), filtering by the position/distance parameter, and keep the returned node pointer. [callee:0x004B72A0, field:this:0x00000000]
    // GUARD: Guard: if the traversal returned null, no matching entry exists and the function returns 0. [source:raw]
    // GUARD: Guard on the node's state fields at +36: when FieldCompareConstant(node+36) is true AND FloatComparisonCheck(node+36) is false, take the first passthrough path. [callee:0x005001D0, callee:0x005001F0]
    // CALL: Call PassthroughWrapper_00c0(a4, node+146, a3), passing the node field at +146 to the audio sample passthrough. [callee:0x005000C0]
    // GUARD: Guard on the node's state fields at +36: when FieldCompareConstant(node+36) is true OR FloatComparisonCheck(node+36) is false, take the direct playback path. [callee:0x005001D0, callee:0x005001F0]
    // CALL: Call AudioSamplePlaybackWithPitchModulationAndStereoP(a4, a3) to play the sample with pitch modulation and stereo positioning. [callee:0x00500210]
    // CALL: Fallback path: call PassthroughWrapper_00c0(a4, node+38, a3), passing the node field at +38 to the audio sample passthrough. [callee:0x005000C0]
    // RETURN: Return the chosen playback call result, or 0 when no list entry matched. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B9AC0(ListHead* list, int filter, int arg3, float pos) {
    //     if (pos == -9.9999997e37f) pos = FloatGetter(*list);
    //     Entry* e = LinkedListTraversalWithFilter(*list, filter, pos);
    //     if (!e) return 0;
    //     if (FieldCompareConstant(e + 36) && !FloatComparisonCheck(e + 36))
    //       return PassthroughWrapper_00c0(pos, (int)(e + 146), arg3);
    //     if (FieldCompareConstant(e + 36) || !FloatComparisonCheck(e + 36))
    //       return AudioSamplePlaybackWithPitchModulationAndStereoP(pos, arg3);
    //     return PassthroughWrapper_00c0(pos, (int)(e + 38), arg3);
    //   }
    // UNRESOLVED: Meaning of the node state fields at +36, +38 and +146 and how they select the playback path is not packet-confirmed.
    // UNRESOLVED: Role of parameters a2 (list filter) and a3 (sample argument) is not established.
    // UNRESOLVED: The link between global flt_5ACD04 and the -9.9999997e37 sentinel is DERIVED from existing analysis, not present in the raw source.
    // UNRESOLVED: Caller sub_4F0430 context for this dispatch is unknown.
}
