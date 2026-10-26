// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005506A0
// Canonical corpus name: sub_5506A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5506A0_005506a0.c

void UnknownObject::LinkedListTimerValueAssign()
{
    // Walks the linked tracker list rooted at this+0x204 (this[129], next link at node+16) and conditionally writes the incoming value a2 into array elements stored on each tracker. Each tracker holds a count at node+280 and an element-array base at node+284; array elements are 64 bytes wide (pointer-advanced 16 dwords) with an owner pointer at element+4 and a writable value slot at element+52. When a3 is non-zero it addresses one sub-object directly ((a3+168) + 148*a4) and writes only elements whose owner equals a3; when a3 is zero it dereferences each element's owner pointer (+168) and writes every element whose sub-object passes the guard (count at +72 above 1 and a2 below the threshold at +80).
    // GUARD: Branch on the a3 owner selector: non-zero addresses one specific sub-object; zero runs the all-elements pass over every tracker's array [source:raw]
    // CALCULATION: In the a3 branch, derive the per-index sub-object pointer v8 as *(a3+168) + 148*a4 [source:raw]
    // GUARD: The a3 branch only proceeds when the sub-object count at v8+72 is greater than 1 [source:raw]
    // LOOP: Walk the linked tracker list rooted at this+0x204 (this[129]) following the next pointer at node+16 until null [field:this:0x00000204, source:raw]
    // GUARD: Each tracker is processed only when its element count at node+280 (i[70]) is non-zero [source:raw]
    // LOOP: Iterate the tracker's element array at node+284 (i[71]) starting 52 bytes into the first element, advancing 16 dwords (64 bytes) per element until the count is exhausted [source:raw]
    // ASSIGNMENT: In the a3 branch, when the element's owner at element+4 equals a3 and a2 is below the threshold at v8+80, write a2 to the element value slot at element+52 [source:raw]
    // CALCULATION: In the all-elements pass, read each element's owner pointer at element+4 and derive the sub-object as *(owner+168) [source:raw]
    // ASSIGNMENT: In the all-elements pass, when the sub-object count at +72 is greater than 1 and a2 is below the threshold at +80, write a2 to the element value slot at element+52 [source:raw]
    // RETURN: No return value; invoked by VehicleSceneLoadAndPositionTires, AudioEffectTrigger, sub_4A3390, ArithmeticComparison_0ec0, VehicleGraphicsSceneLoader, VehicleRespawnReset, VehicleStateUpdate_19d0 and VibrationStateMachine [function:0x005506A0, caller:0x004681B0, caller:0x0049E4E0, caller:0x004A3390, caller:0x004D0EC0, caller:0x004DFCE0, caller:0x004E0800, caller:0x004E19D0, caller:0x004E2230, source:raw]

    // Conservative worker pseudocode:
    //   if (a3) {
    //     v8 = *(a3 + 168) + 148*a4;
    //     if (*(v8 + 72) > 1) {
    //       for (t = this[129]; t; t = t[4]) {
    //         count = t[70];
    //         for (e = t[71] + 52; count--; e += 64) {
    //           if (*(e - 48) == a3 && a2 < *(v8 + 80)) *(e) = a2;
    //         }
    //       }
    //     }
    //   } else {
    //     for (t = this[129]; t; t = t[4]) {
    //       count = t[70];
    //       for (e = t[71] + 52; count--; e += 64) {
    //         sub = *(*(e - 48) + 168);
    //         if (*(sub + 72) > 1 && a2 < *(sub + 80)) *(e) = a2;
    //       }
    //     }
    //   }
    // UNRESOLVED: The element stride of 64 bytes and the element+4 owner / element+52 value layout are derived from the decompiler's pointer arithmetic and are not independently attested
    // UNRESOLVED: The semantics of the sub-object fields at +72 (count) and +80 (threshold) and the 148-byte per-index stride inside the a3 target object are undocumented here
    // UNRESOLVED: Four fields of this (0x224, 0x32C, 0x330, 0x364) are flagged by packet facts but never appear in the raw decompiled source
    // UNRESOLVED: The prelabel names this a structural twin of LinkedListAnimationTimerDecrement (005505a0); the write of a2 here is consistent with a timer value assignment but not proven
}
