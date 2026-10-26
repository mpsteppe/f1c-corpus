// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042E400
// Canonical corpus name: PenaltyStructInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PenaltyStructInit_0042e400.c

void UnknownObject::PenaltyStructInit()
{
    // Constructor/initializer for a penalty-related sub-structure of a session object. Writes two fields directly (a float at this+7356 = 293.16f / 1133679739 and a byte flag at this+7352 = 1), then runs a 4-iteration loop that writes a repeating pattern: an offset float (293.16f), several byte flags (1, 0), and a triple of equal floats (359.86f / 1135865364) into array fields at this+7384, this+7380 and this+7404 respectively, advancing the three cursors each iteration. Invoked from SessionStructInit (0x0042E320) and sub_4A0030.
    // ASSIGNMENT: Set the dword at this+7356 (0x1CBC) to literal 1133679739 (float 293.16). [field:this:0x00001CBC, source:raw]
    // ASSIGNMENT: Set the byte at this+7352 (0x1CB8) to literal 1. [field:this:0x00001CB8, source:raw]
    // ASSIGNMENT: Seed three cursors: result = this+7380 (0x1CD4), v3 = this+7384 (0x1CD8), v2 = this+7404 (0x1CEC). [field:this:0x00001CD4, field:this:0x00001CD8, field:this:0x00001CEC, source:raw]
    // LOOP: do-while loop that runs 4 iterations, ending when the result cursor has advanced 4 bytes past this+7380. [source:raw]
    // ASSIGNMENT: Each iteration writes the literal 1133679739 (float 293.16) to a dword 5 dwords before the v3 cursor and the literal 1 to a byte 20 bytes before the result cursor. [field:this:0x00001CBC, field:this:0x00001CB8, source:raw]
    // ASSIGNMENT: Each iteration writes 0 to the dword at the v3 cursor, 1 to the byte at the result cursor, and 1 to the byte 20 bytes ahead of the result cursor. [field:this:0x00001CD8, field:this:0x00001CD4, field:this:0x00001CE8, source:raw]
    // ASSIGNMENT: Each iteration writes the literal 1135865364 (float 359.86) to three consecutive dwords starting at the v2 cursor. [field:this:0x00001CEC, field:this:0x00001CF0, field:this:0x00001CF4, source:raw]
    // CALCULATION: Advance the cursors each iteration: v3 += 1 dword, v2 += 3 dwords, result += 1 byte. [source:raw]
    // RETURN: Return the result cursor after the loop (points past the last initialized byte). [source:raw]

    // Conservative worker pseudocode:
    //   void PenaltyStructInit(int this) {
    //     *(float*)(this + 7356) = 293.16f;
    //     *(byte*)(this + 7352) = 1;
    //     byte* result = (byte*)(this + 7380);
    //     dword* v3 = (dword*)(this + 7384);
    //     dword* v2 = (dword*)(this + 7404);
    //     do {
    //       *(v3 - 5) = 1133679739;
    //       *(result - 20) = 1;
    //       *v3 = 0;
    //       *result = 1;
    //       v2[0] = 1135865364; v2[1] = 1135865364; v2[2] = 1135865364;
    //       ++v3;
    //       v2 += 3;
    //       result[20] = 1;
    //       ++result;
    //     } while ((int)&result[-7380 - this] < 4);
    //     return;
    //   }
    // UNRESOLVED: The structure owner is unknown; the this object is a session-related aggregate but no confirmed class is named.
    // UNRESOLVED: The semantic meaning of the repeated floats 293.16 (0x1CBC) and 359.86 (0x1CEC/0x1CF0/0x1CF4) is unknown; the canonical name 'PenaltyStructInit' is a legacy label, not runtime-verified.
    // UNRESOLVED: The static extractor enumerated only the first iteration's target offsets; the loop also writes adjacent offsets not individually listed in the packet.
}
