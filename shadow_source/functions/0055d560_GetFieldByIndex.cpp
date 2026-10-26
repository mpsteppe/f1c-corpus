// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D560
// Canonical corpus name: FieldGetterByIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldGetterByIndex_0055d560.c

void UnknownObject::GetFieldByIndex()
{
    // Reads one of three fields of the this object selected by an integer index a2 (1, 2 or 3) and writes it to caller-provided output pointer a3: index 1 reads this[5] (+0x14), index 2 reads this[9] (+0x24), index 3 reads this[13] (+0x34). The write happens only when a3 is non-null; index values outside 1..3 write nothing. Returns a3. Invoked by sub_558E70 (0x00558E70).
    // GUARD: If output pointer a3 is null the function returns a3 without writing [source:raw]
    // GUARD: Dispatch on index a2: only cases 1, 2 and 3 perform a write; any other value leaves a3 untouched [source:raw]
    // ASSIGNMENT: Case 1: *a3 = this[5] (byte offset +0x14) [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Case 2: *a3 = this[9] (byte offset +0x24) [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Case 3: *a3 = this[13] (byte offset +0x34) [field:this:0x00000034, source:raw]
    // RETURN: Returns a3 (the output pointer); the function is invoked by sub_558E70 (0x00558E70) [function:0x0055D560, caller:0x00558E70, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   if (!a3) return a3;
    //   switch (a2) {
    //     case 1: *a3 = this+0x14; break;
    //     case 2: *a3 = this+0x24; break;
    //     case 3: *a3 = this+0x34; break;
    //   }
    //   return a3;
    // UNRESOLVED: The semantic purpose of the three selected fields (+0x14/+0x24/+0x34) is not determinable from this packet; the skeleton fill labels them alpha/scale factors for three color groups, which is not verifiable from the raw source alone
}
