// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FDEB0
// Canonical corpus name: AudioADSREnvelope
// Owner: AudioADSREnvelope [DERIVED]
// Raw source: functions/AudioADSREnvelope_004fdeb0.c

void AudioADSREnvelope::ComputeADSREnvelope()
{
    // Advances an ADSR audio envelope: walks a linked list of envelope keyframe nodes (current node held at this+0x38, table base at this+0x44, next link at node+12), interpolates the two node parameters for phase a3, applies per-sample decay to two internal envelope state values using rate a2 and a ramp factor a4 with a floor clamp, calls RangeInterpolationTable, then combines the states into a final output value at this+0x34 with sample-rate-dependent smoothing when a2 is below the smoothing threshold.
    // LOOP: Walk the envelope keyframe chain from the current node pointer stored at this+0x38: while the next link (node+12) is non-null and phase a3 is not below the next node's threshold, advance the current node pointer to the next node. [field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040]
    // GUARD: When the current node has no next link, take the node's parameters directly from the node reached through the table base at this+0x44 without interpolating. [field:this:0x00000044, field:*(this+0x44):0x00000000]
    // CALCULATION: Linearly interpolate the two node parameters between the current node and its next node using fraction (a3 - currentThreshold) / (nextThreshold - currentThreshold); the parameters are the node fields at offsets 4 and 8 beneath the table base. [field:*(this+0x44):0x00000004, field:*(this+0x44):0x00000008, source:raw]
    // CALL: Feed the interpolated second parameter into sub_4FDE00 on 'this'. [callee:0x004FDE00]
    // ASSIGNMENT: Store the interpolated first parameter into an envelope state slot (this+0x30). [source:raw]
    // GUARD: Clamp the envelope state at this+0x28 down to the floor value this+0x24 when below it; otherwise decay it by (a4 * 0.000011574074 + clamped this+0x34 * 0.0000011574074 + 0.000011574074) * a2, again clamped to the floor. [source:raw]
    // CALCULATION: Decay the second envelope state at this+0x2C by (clamped this+0x34 * 0.0000011574074 + 0.000011574074) * a2 when above the floor value, clamping at the floor. [source:raw]
    // CALL: Apply RangeInterpolationTable to the envelope state. [callee:0x004FD6F0]
    // CALCULATION: Compute the final output as a weighted combination of the two envelope states (this+0x2C and this+0x28), the interpolated second parameter, and a4, then write it to the output slot at this+0x34; when a2 is below 499.99997 the output is smoothed toward the prior output by a2 * 0.0020000001. [source:raw]

    // Conservative worker pseudocode:
    //   void ComputeADSREnvelope(AudioADSREnvelope *this, float rate, float phase, int ramp) {
    //     float node = this->currentNode;
    //     while (true) {
    //       next = node->next;
    //       if (!next) { first = node->p1; second = node->p2; break; }
    //       if (phase < next->threshold) break;
    //       this->currentNode = next; node = next;
    //     }
    //     t = (phase - node->threshold) / (next->threshold - node->threshold);
    //     first = lerp(node->p1, next->p1, t); second = lerp(node->p2, next->p2, t);
    //     sub_4FDE00(this, second);
    //     this->state0x30 = first;
    //     decayAndClamp(&this->state0x28, rate, ramp, this->output0x34);
    //     decayAndClamp(&this->state0x2C, rate, 0, this->output0x34);
    //     RangeInterpolationTable(this);
    //     out = (this->state0x2C + this->state0x28) * 0.5 * -3.0 + 2.0 + (1.0 - second) * 7.0 + ramp * 0.1 + this->state0x30;
    //     if (rate < 499.99997) out = (out - this->output0x34) * rate * 0.0020000001 + this->output0x34;
    //     this->output0x34 = out;
    //   }
    // UNRESOLVED: Relationship between the this+0x44 table base, the current-node pointer at this+0x38 and the extraction-listed fields at this+0x3C/this+0x40 is ambiguous against the raw node-walk code.
    // UNRESOLVED: The float global constants listed in the packet (flt_59E43C..flt_5AD318) are not directly referenced in the raw C source; their role in the audio path is unknown here.
    // UNRESOLVED: Whether a4 is a raw ramp/parameter or a time-scaled factor is not resolved from the packet.
}
