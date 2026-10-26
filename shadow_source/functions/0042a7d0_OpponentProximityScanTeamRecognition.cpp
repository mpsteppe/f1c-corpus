// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042A7D0
// Canonical corpus name: OpponentProximityScanTeamRecognition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OpponentProximityScanTeamRecognition_0042a7d0.c

void UnknownObject::OpponentProximityScanTeamRecognition()
{
    // Per-frame opponent awareness update. Resets the 5 proximity slots and 5 team slots, then either registers the nearest vehicle (FindNearestVehicle) or scans every active vehicle (dword_7C54F0 list, bound by dword_5C329C) computing planar squared distance from self position, applying team/direction heuristics (sub_4C7BD0, 625.0 squared threshold, dword_7C56A4==7, lap comparison at +0x403C) that set an overtake target at +0x45FC and a direction sign at +0x4420, then sorted-inserts candidates into the 5-slot nearest list (distances at +0x41A8/+0x41EC/+0x4230/+0x4274/+0x42B8, vehicle ids at +0x4174/+0x41B8/+0x41FC/+0x4240/+0x4284). After the scan, matches each proximity slot's opponent team id (offset 0x4894) against the 5 team slots at +0x42D0, fills unused team slots, and consumes a one-shot flag at +0x4578 by re-seeding all team-slot distance fields to 500.0f.
    // LOOP: 5-iteration reset loop: for each proximity slot k (base this+0x4174+0x44*k): distance at +0x41A8 = 1232348144 (999999.0f), team flag at +0x42CC+0x1C*k = 0, slot id at +0x41B4 = -1, active flag at +0x4174 = 0. [field:this:0x00004174, field:this:0x000041A8, field:this:0x000041B4, field:this:0x000042CC, function:0x0042A7D0, source:raw]
    // CALL: v5 = FindNearestVehicle(this+0x4): query the nearest opponent vehicle given this vehicle's pointer. [callee:0x004A4710, field:this:0x00000004, function:0x0042A7D0, source:raw]
    // ASSIGNMENT: If v5 nonzero: proximity slot 0 distance at +0x41A8 = 1065353216 (1.0f) and slot 0 id at +0x4174 = *v5 (nearest vehicle registered directly). [field:this:0x000041A8, field:this:0x00004174, function:0x0042A7D0, source:raw]
    // LOOP: Else branch: scan i over [0, dword_5C329C) reading v7 = dword_7C54F0[i], the active vehicle pointer array. [global:0x005C329C, global:0x007C54F0, function:0x0042A7D0, source:raw]
    // GUARD: Skip self: proceed only when this+0x0 (self vehicle id) != v7. [field:this:0x00000000, function:0x0042A7D0, source:raw]
    // CALCULATION: Read opponent world position (X at +0x34E0, Z at +0x34E8) and lap counter; subtract self position so v42/v43 hold deltas, then v41 = deltaZ*deltaZ + deltaX*deltaX (planar squared distance). [field:this:0x000034E0, field:this:0x000034E8, field:this:0x0000403C, function:0x0042A7D0, source:raw]
    // GUARD: Proceed only when opponent lap counter (read at opponent +0x4550) is less than dword_5EA2CC (race-lap threshold). [global:0x005EA2CC, function:0x0042A7D0, source:raw]
    // CALL: sub_4C7BD0(v7): opponent team/class check; when it returns true, apply the recognition heuristics below. [callee:0x004C7BD0, function:0x0042A7D0, source:raw]
    // GUARD: Overtake-candidate gate: v41 < 625.0 && dword_7C56A4 == 7. [global:0x007C56A4, function:0x0042A7D0, source:raw]
    // GUARD: Proceed when opponent lap (at opponent +0x403C) exceeds self lap at this+0x403C (opponent is a lap ahead). [field:this:0x0000403C, function:0x0042A7D0, source:raw]
    // ASSIGNMENT: this+0x45FC = opponent pointer (overtake/target slot recorded). [field:this:0x000045FC, function:0x0042A7D0, source:raw]
    // CALCULATION: Cross-product sign test: (oppZ - selfZ)*this+0x448C - (oppX - selfX)*this+0x4494; when <= 0.0 set this+0x4420 = -1071644672 (-1.0f) else 1075838976 (2.0f). Records on which side the opponent is for overtake direction. [field:this:0x0000448C, field:this:0x00004494, field:this:0x00004420, function:0x0042A7D0, source:raw]
    // CALCULATION: Sorted insertion of the candidate into the 5-slot nearest list: distances at +0x41A8 (slot 0), +0x41EC (slot 1), +0x4230 (slot 2), +0x4274 (slot 3), +0x42B8 (slot 4) with matching vehicle ids at +0x4174, +0x41B8, +0x41FC, +0x4240, +0x4284; shift entries down and insert v41 / dword_7C54F0[i] at the first slot whose distance is larger. Uses F_2DVectorDirectionProjection on this+0x448C (heading vector) vs the candidate delta to gate whether the candidate is ahead (-5.5 threshold). [callee:0x00423AD0, field:this:0x000041A8, field:this:0x000041B4, field:this:0x000041B8, field:this:0x000041EC, field:this:0x000041FC, field:this:0x00004230, field:this:0x00004240, field:this:0x00004274, field:this:0x00004284, field:this:0x000042B8, field:this:0x0000448C, function:0x0042A7D0, source:raw]
    // LOOP: Team matching pass over the 5 proximity slots (base +0x4174, stride 0x44): for a slot with an active pointer and distance field < 999998.0, scan the 5 team slots at +0x42D0 (stride 0x1C) for a value equal to the opponent team id (read at opponent offset 0x4894). [field:this:0x00004174, field:this:0x000041A8, field:this:0x000042D0, field:*(this+0x4174):0x00004894, function:0x0042A7D0, source:raw]
    // ASSIGNMENT: When a matching team slot v30 is found: set the team flag at +0x42CC+v30*0x1C = 1 and store the team index v30 into the proximity slot id field at +0x41B4+0x44*k. [field:this:0x000042CC, field:this:0x000041B4, function:0x0042A7D0, source:raw]
    // LOOP: Team slot fill pass over the 5 proximity slots (base +0x41B4, stride 0x44): for a slot whose distance at +0x41A8 is <= 999998.0 and whose id at +0x41B4 is still -1, read the opponent team id at offset 0x4894 from the active pointer at +0x4174. [field:this:0x000041A8, field:this:0x000041B4, field:this:0x00004174, field:*(this+0x4174):0x00004894, function:0x0042A7D0, source:raw]
    // GUARD: Guard (packet guard:0): distance at +0x41A8 <= 999998.0 && slot id at +0x41B4 == -1 (slot not yet assigned to a team). [guard:0, field:this:0x000041A8, field:this:0x000041B4, function:0x0042A7D0, source:raw]
    // ASSIGNMENT: Find the first free team slot v35 (flag at +0x42CC+0x1C*v35 is zero) and populate its fields: +0x42CC = 1 (matched flag), +0x42D0 = team id, +0x42DC = 0, plus the -971228160 (-1000.0f) and -1 sentinel fields of the team-slot block; then store v35 into the proximity slot id at +0x41B4+0x44*k. [field:this:0x000042CC, field:this:0x000042D0, field:this:0x000042DC, field:this:0x000041B4, function:0x0042A7D0, source:raw]
    // GUARD: Final one-shot: proceed when the byte at this+0x4578 is nonzero. [field:this:0x00004578, function:0x0042A7D0, source:raw]
    // ASSIGNMENT: Consume the flag: this+0x4578 (byte) = 0. [field:this:0x00004578, function:0x0042A7D0, source:raw]
    // LOOP: 5-iteration loop re-seeding each team slot's distance field at +0x42DC+0x1C*k to 1140457472 (500.0f). [field:this:0x000042DC, function:0x0042A7D0, source:raw]
    // RETURN: Return the previous value of the one-shot flag byte at +0x4578. [field:this:0x00004578, function:0x0042A7D0, source:raw]

    // Conservative worker pseudocode:
    //   reset5ProximitySlotsAndTeamFlags();
    //   nearest = FindNearestVehicle(this->selfPtr);
    //   if (nearest) { slot0.distance = 1.0f; slot0.id = nearest; }
    //   else {
    //       for (i = 0; i < dword_5C329C; i++) {
    //           v7 = dword_7C54F0[i];
    //           if (this->id == v7) continue;
    //           v41 = planarSqDist(this->pos, oppPos(v7));
    //           if (oppLap(v7) < dword_5EA2CC) {
    //               if (sub_4C7BD0(v7)) {
    //                   if (v41 < 625.0 && dword_7C56A4 == 7) {
    //                       if (oppLap(v7) > this->lap) {
    //                           this->overtakeTarget = v7;
    //                           this->direction = crossSign(...) <= 0.0 ? -1.0f : 2.0f;
    //                       }
    //                   }
    //               }
    //               insertIntoSortedProximitySlots(v41, v7);
    //           }
    //       }
    //   }
    //   matchProximitySlotsToTeams();
    //   fillUnassignedTeamSlots();
    //   if (this->rearmFlag) { this->rearmFlag = 0; seedTeamSlotDistances(500.0f); }
    //   return (char)rearmFlag;
    // UNRESOLVED: The outer guard on the sorted-insertion chain reads as `v41 >= farthest-slot OR heading projection >= -5.5` and yet the chain itself only inserts when v41 < a slot distance; the two conditions appear inverted and the true control flow is ambiguous (possible decompiler artifact).
    // UNRESOLVED: Globals flt_59E440, flt_59E980, flt_59E984, flt_59E988 and unk_7CE2F0 are listed as read in the packet but do not appear in the raw source text; their roles are unknown (likely consumed inside callees such as F_2DVectorDirectionProjection).
    // UNRESOLVED: Team-slot block includes sentinel fields at +0x42C8 and +0x42D8 (values -1 and -1000.0f) that are written but not listed as packet fields.
    // UNRESOLVED: The owner object is unidentified; the structure matches the AI-driver context (proximity/team slots at +0x4174/+0x42CC) but the containing class is not proven.
}
