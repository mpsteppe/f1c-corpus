// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00413B60
// Canonical corpus name: SeasonSpecificTeamIDLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonSpecificTeamIDLookup_00413b60.c

void UnknownObject::SeasonSpecificTeamIDLookup()
{
    // Maps a team index a3 (1-17) to a season-specific team id by probing the resolved season database path against four GDB filename literals (F11999.GDB, F12000.GDB, F12001.GDB, F12002.GDB) and dispatching through one of four jump-table switch tables with base ids 333, 334, 335 or 336 (each stepping by 4 per entry). On a mapped case it writes the team id to a1+8 and the result of sub_414180(1) to a1+12 and returns 1; otherwise it returns -1. The mapping runs only when a2 equals 1 and the flag a4 is zero.
    // GUARD: The mapping runs only when a2 equals 1 and the flag a4 is zero; the result starts at -1. [source:raw]
    // ASSIGNMENT: Resolves the season database path as dword_7D0434, or byte_5EA438 when that pointer is null. [global:0x007D0434, global:0x005EA438, source:raw]
    // GUARD: sub_588410 compares the resolved path against the F11999.GDB filename literal; when it does not match the function falls through and returns -1. [callee:0x00588410, global:0x005BF994, source:raw]
    // GUARD: The path is probed against the F12000.GDB filename literal; a non-match selects the team-id table with base 334. [callee:0x00588410, global:0x005BF988, source:raw]
    // GUARD: The path is probed against the F12001.GDB filename literal; a non-match selects the team-id table with base 335. [callee:0x00588410, global:0x005BF97C, source:raw]
    // GUARD: The path is probed against the F12002.GDB filename literal; absence of a match selects the table with base 333 while a match selects the table with base 336. [callee:0x00588410, global:0x005BF970, source:raw]
    // CALCULATION: Switch on a3 dispatches through one of the four compiler jump tables (0x00413EFC, 0x00413F40, 0x00413F84, 0x00413FC8); for cases 1-17 the resulting team id is the selected base (333, 334, 335 or 336) plus 4 times (a3 minus 1); the default case returns -1. [global:0x00413EFC, global:0x00413F40, global:0x00413F84, global:0x00413FC8, source:raw]
    // CALL: On a mapped case, evaluates sub_414180 with argument 1. [callee:0x00414180, source:raw]
    // ASSIGNMENT: Writes the mapped team id to a1+8 and the sub_414180 result to a1+12, and sets the function result to 1. [field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Returns 1 after a successful mapping; returns -1 for an unmatched season path, an out-of-range team index, or an absent F11999.GDB. [source:raw]

    // Conservative worker pseudocode:
    //   result = -1;
    //   if (a2 == 1 && !a4) {
    //       path = dword_7D0434 ? dword_7D0434 : byte_5EA438;
    //       if (sub_588410(path, F11999.GDB)) {
    //           if (sub_588410(path, F12000.GDB)) {
    //               if (sub_588410(path, F12001.GDB)) {
    //                   base = sub_588410(path, F12002.GDB) ? 336 : 333;
    //               } else base = 335;
    //           } else base = 334;
    //           switch (a3) case 1..17: team_id = base + 4 * (a3 - 1);
    //           a1 + 8 = team_id; a1 + 12 = sub_414180(1); result = 1;
    //       }
    //   }
    //   return result;
    // UNRESOLVED: The mapping of the four jump-table globals (0x00413EFC, 0x00413F40, 0x00413F84, 0x00413FC8) to the four season-file switch tables is not asserted; only the selected base ids (333/334/335/336) are confirmed from the case literals.
}
