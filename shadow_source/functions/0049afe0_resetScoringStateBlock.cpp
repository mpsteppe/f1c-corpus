// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049AFE0
// Canonical corpus name: MultiCallSequence
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiCallSequence_0049afe0.c

void UnknownObject::resetScoringStateBlock()
{
    // Resets five consecutive global data structures by calling sub_49E8F0 on each (0x7CE0B8, 0x7CE104, 0x7CE150, 0x7CE19C, 0x7CE1E8), then zeroes dword_7CE058 and the 96-byte global block from 0x7CE058 through 0x7CE0B4. Returns 0. Unconditional sequence with no guards.
    // CALL: Call sub_49E8F0 on global structure at 0x7CE0B8 for per-struct reset/initialization. [callee:0x0049E8F0, global:0x007CE0B8]
    // CALL: Call sub_49E8F0 on global structure at 0x7CE104 for per-struct reset/initialization. [callee:0x0049E8F0, global:0x007CE104]
    // CALL: Call sub_49E8F0 on global structure at 0x7CE150 for per-struct reset/initialization. [callee:0x0049E8F0, global:0x007CE150]
    // CALL: Call sub_49E8F0 on global structure at 0x7CE19C for per-struct reset/initialization. [callee:0x0049E8F0, global:0x007CE19C]
    // CALL: Call sub_49E8F0 on global structure at 0x7CE1E8 for per-struct reset/initialization. [callee:0x0049E8F0, global:0x007CE1E8]
    // ASSIGNMENT: Zero dword_7CE058 and the contiguous block of unk_7CE05C..unk_7CE0B4 (96 bytes total from 0x7CE058 to 0x7CE0B4), clearing global reset state. [global:0x007CE058, source:raw]
    // RETURN: Return 0 as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   sub_49E8F0(&unk_7CE0B8);
    //   sub_49E8F0(&unk_7CE104);
    //   sub_49E8F0(&unk_7CE150);
    //   sub_49E8F0(&unk_7CE19C);
    //   sub_49E8F0(&unk_7CE1E8);
    //   for (i = 0; i < 96; i++) unk_7CE058[i] = 0;
    //   return 0;
    // UNRESOLVED: The exact nature of the five per-struct reset calls (what sub_49E8F0 does) is not established.
    // UNRESOLVED: The per-offset role of each zeroed member in the 0x7CE058..0x7CE0B4 block is unnamed; the raw source zeroes 24 dwords but only dword_7CE058 has a deterministic global entry in this packet.
}
