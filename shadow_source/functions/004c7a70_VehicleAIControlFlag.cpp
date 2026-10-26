// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7A70
// Canonical corpus name: VehicleAIControlFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleAIControlFlag_004c7a70.c

void UnknownObject::VehicleAIControlFlag()
{
    // Read-modify-write of the AI control flag bitset at this+0x48BC (this[4655]): when a2 is nonzero, set bit 0 (value OR 1) to mark the vehicle AI-controlled; when zero, clear bit 0 (value AND 0xFFFFFFFE). Stores the result back at +0x48BC and returns it. Invoked from CollisionContactIteration (0x00460DD0) to release (0) or retain (1) AI override during collision contact handling.
    // ASSIGNMENT: Load the current AI control flag: v2 = this[4655] (int at this+0x48BC) [field:this:0x000048BC, source:raw]
    // GUARD: Branch on a2: nonzero selects the set-bit path, zero selects the clear-bit path [source:raw]
    // CALCULATION: Set path: result = v2 | 1, forcing bit 0 to 1 (AI-controlled) [field:this:0x000048BC, source:raw]
    // CALCULATION: Clear path: result = v2 & 0xFFFFFFFE, forcing bit 0 to 0 (AI released) [field:this:0x000048BC, source:raw]
    // ASSIGNMENT: Store the computed value back: this[4655] = result at +0x48BC [field:this:0x000048BC, source:raw]
    // RETURN: Return the updated flag value [source:raw]
    // CALL: Called by CollisionContactIteration (0x00460DD0) during collision contact response to toggle the AI override flag [caller:0x00460DD0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = this[+0x48BC];
    //   if (a2) result = v2 | 1;
    //   else    result = v2 & 0xFFFFFFFE;
    //   this[+0x48BC] = result;
    //   return result;
}
