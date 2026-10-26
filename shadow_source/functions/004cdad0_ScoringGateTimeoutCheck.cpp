// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CDAD0
// Canonical corpus name: ScoringGateTimeoutCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScoringGateTimeoutCheck_004cdad0.c

void UnknownObject::ScoringGateTimeoutCheck()
{
    // Gated by a global scoring flag equal to 2: delegate into the scoring system, then iterate the object's particle array (count at this+0x64, element pointer array at this+0x68), removing every element whose float at element+8 is greater than the caller-supplied current time (st0). Returns the last observed particle count.
    // GUARD: Only run when scoring gate flag dword_8AB6E4 equals 2; otherwise skip the whole block and return. [global:0x008AB6E4]
    // CALL: Delegate to the scoring system, passing the address of dword_8AB6EC. [callee:0x004B9CE0, global:0x008AB6EC]
    // ASSIGNMENT: Read particle count from this+0x64 (a1[25]) into result as the loop bound. [field:this:0x00000064, source:raw]
    // LOOP: Iterate i from 0 while i < particle count; each iteration computes the element pointer as *(int*)(this+0x68 + 4*i), i.e. this+0x68 holds an array of pointers. [field:this:0x00000068, field:this:0x00000064]
    // GUARD: Copy caller-supplied time (st0, passed as a2) to v6 and remove the element when v6 < (double)*(float*)(element_ptr + 8). [source:raw]
    // CALL: Remove the timed-out element pointer from the object's array via ArrayElementRemoval. [callee:0x004CB5A0, source:raw]
    // STATE_TRANSITION: Decrement the loop index after a removal so the same slot is re-examined next iteration. [source:raw]
    // ASSIGNMENT: Reload particle count from this+0x64 every iteration (the count may have changed after a removal). [field:this:0x00000064]
    // RETURN: Return result, the last particle count read from this+0x64. [source:raw, function:0x004CDAD0]

    // Conservative worker pseudocode:
    //   if (scoring_gate_flag == 2) {
    //       scoring_delegate(&scoring_data);
    //       count = this->particle_count;  // this+0x64
    //       for (i = 0; i < count; ++i) {
    //           elem = *(this->particle_array + 4 * i);  // this+0x68
    //           if (current_time < (double)*(float *)(elem + 8)) {
    //               remove_array_element(this, elem);
    //               --i;
    //           }
    //           count = this->particle_count;
    //       }
    //   }
    //   return count;
    // UNRESOLVED: Semantic role of the float at element+8 (existing analysis reads it as birth time: elements whose stored time exceeds current time are removed) is inferred, not independently proven.
    // UNRESOLVED: Meaning of dword_8AB6E4 == 2 and structure of dword_8AB6EC passed to Delegation are not proven; only the read references are deterministic.
    // UNRESOLVED: This object's class is unknown; a1 offsets 0x64/0x68 are treated as count/array on an UnknownObject with no class identity.
}
