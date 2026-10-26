// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC2F0
// Canonical corpus name: CloudSceneObjectRandomSelector
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CloudSceneObjectRandomSelector_004fc2f0.c

void UnknownObject::SelectRandomCloudSceneObjects()
{
    // Iterates a set of cloud scene objects, partitions candidates into two groups by matching their 6-character name against the aClouds and aCloudr patterns, then randomly selects one object from each group via the LCG and copies 31 bytes from it into an output slot (this+80 and this+132). Clears per-slot flags at this 0x6F and 0xA3 after each copy.
    // GUARD: Reads the object count at a2+280; if it is not greater than 0 the whole partition-and-select pass is skipped. [source:raw]
    // LOOP: Iterates count times, advancing the object pointer by 256 bytes per entry (a2+296 base) and collecting candidate object pointers into two lists. [source:raw]
    // CALL: Compares the candidate name at v5+20 against the aClouds 6-char pattern via sub_588640; a non-match makes the object eligible for the first (aClouds) group. [callee:0x00588640, global:0x005D6F08]
    // ASSIGNMENT: Stores the candidate pointer into first-group list slot v12[v4] and increments v4, bounded by the v4 < 256 guard. [source:raw, global:0x005D6F08]
    // CALL: Compares the candidate name at v5+20 against the aCloudr 6-char pattern via sub_588640; a non-match makes the object eligible for the second (aCloudr) group. [callee:0x00588640, global:0x005D6F30]
    // ASSIGNMENT: Stores the candidate pointer into second-group list slot v12[v9 + 256] and increments v9, bounded by the v9 < 256 guard. [source:raw, global:0x005D6F30]
    // GUARD: If first-group list is empty (v4 <= 0), the first random selection is skipped. [source:raw]
    // CALL: Calls the LCG random number generator to pick the first-group selection. [callee:0x005884ED]
    // CALCULATION: Binds the LCG result to the list size via modulo v4 to select an index into the first-group list. [source:raw]
    // CALL: Copies 31 bytes from the selected first-group object (selected + 20) into the output slot at this+80 via sub_587DD0. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Clears the this 0x6F flag/state byte for the first selected cloud after the copy. [field:this:0x0000006F]
    // GUARD: If second-group list is empty (v9 <= 0), the second random selection is skipped. [source:raw]
    // CALL: Calls the LCG random number generator and reduces the result by modulo v9 to select an index into the second-group list. [callee:0x005884ED]
    // CALL: Copies 31 bytes from the selected second-group object (selected + 20) into the output slot at this+132 via sub_587DD0. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Clears the this 0xA3 flag/state byte for the second selected cloud after the copy. [field:this:0x000000A3]
    // RETURN: Returns the result of the last sub_587DD0 copy (or the initial count read when the pass was skipped). [source:raw, function:0x004FC2F0]

    // Conservative worker pseudocode:
    //   count = *(a2 + 280);
    //   cloudsCount = 0; cloudrCount = 0;
    //   if (count > 0) {
    //     stride = 0;
    //     do {
    //       cand = stride + *(a2 + 296);
    //       if (!CompareName(cand + 20, aClouds, 6) && cloudsCount < 256) clouds[cloudsCount++] = cand;
    //       if (!CompareName(cand + 20, aCloudr, 6) && cloudrCount < 256) cloudr[cloudrCount++] = cand;
    //       stride += 256;
    //     } while (--count);
    //     if (cloudsCount > 0) {
    //       idx = LCG() % cloudsCount;
    //       CopyBlock(this + 80, clouds[idx] + 20, 31);
    //       this[111] = 0;
    //     }
    //     if (cloudrCount > 0) {
    //       idx = LCG() % cloudrCount;
    //       CopyBlock(this + 132, cloudr[idx] + 20, 31);
    //       this[163] = 0;
    //     }
    //   }
    //   return lastResult;
    // UNRESOLVED: LCG is invoked with an uninitialized-looking argument register; its exact signature is unproven.
    // UNRESOLVED: The identity of the a2 container (object list owner) and of the this object is unknown.
    // UNRESOLVED: Byte strides 256 and +20 access points inside child objects whose layout is not established.
    // UNRESOLVED: Semantics of the this 0x6F / 0xA3 flags beyond 'reset after selection' are unknown.
}
