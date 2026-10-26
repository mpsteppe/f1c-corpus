// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418EE0
// Canonical corpus name: AITargetDriverSelection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AITargetDriverSelection_00418ee0.c

void UnknownObject::ClassifyDriverTargets()
{
    // Iterates vehicle entries (unk_5F0CF8 base, 4656-byte stride) and writes a per-slot classification dword into the this output array: 0 default, -1 for retired/invalid entries, 1 for the player vehicle, 2 for a teammate. In race mode only, applies scoring and position-delta checks to pick a scoring/overtake target and promotes one selected slot to classification 3, returning its index (or -1 when none).
    // ASSIGNMENT: Initialize candidate trackers: best position delta v10 and best scoring delta v11 to 0x7FFFFFFF, best delta v1 to 0x7FFFFFFF, fallback slot indices v12/v13 to -1, and slot counter v2 to 0. [source:raw]
    // LOOP: Iterate vehicle entries starting at unk_5F0CF8 with a 4656-byte stride until the entry pointer reaches dword_7C9AF8; the per-slot vehicle pointer is reached by adding the delta dword_7C54F0 - this to the slot pointer. Each iteration classifies one output dword and increments the slot counter. [global:0x005F0CF8, global:0x007C54F0, global:0x007C9AF8, source:raw]
    // ASSIGNMENT: Write default classification 0 into the current slot of the this output array (one dword per slot). [field:this:0x00000000, source:raw]
    // GUARD: If dword_7D0410 == 2 (championship/standings mode), skip this slot entirely, leaving the default classification 0. [global:0x007D0410, source:raw]
    // GUARD: If the current vehicle entry's sentinel field (entry pointer minus 1238 dwords) is -1, classify the slot as -1 (retired/invalid) and skip. [source:raw]
    // GUARD: If dword_7C54E8 (player vehicle pointer) is nonzero and equals this slot's vehicle pointer, classify the slot as 1 (player) and skip. [global:0x007C54E8, source:raw]
    // GUARD: If the player vehicle's team field at +18592 equals this slot's vehicle team field at +18592, classify the slot as 2 (teammate) and skip. [global:0x007C54E8, source:raw]
    // GUARD: If dword_7D0410 != 4 (not race mode), skip the scoring-target classification for this slot, leaving the current default. [global:0x007D0410, source:raw]
    // CALL: Call AIEntrantLookupByName for the current vehicle entry to gate the scoring-target classification. [callee:0x0041E890, source:raw]
    // CALL: Call NestedDataSectionFieldAccessor and AIEntrantLookupByName to check the entry's position band (NestedDataSectionFieldAccessor * (1.0 - 0.1) lower bound and * (0.1 + 1.0) upper bound) for scoring-target viability. [callee:0x0041E840, callee:0x0041E890, source:raw]
    // GUARD: Require sub_4C2990(&dword_7D2DB0) >= 3, i.e. at least three entries present in the standings/classification sort buffer, before selecting a scoring target. [callee:0x004C2990, global:0x007D2DB0, source:raw]
    // CALCULATION: Compute position delta v6 = entry position (element 60 of the entry) minus the player vehicle position (+18192); track the improving (minimum) positive-delta slot in v10/v12. [global:0x007C54E8, source:raw]
    // CALCULATION: Compute scoring delta v8 = NestedDataSectionFieldAccessor() - AIEntrantLookupByName() for the entry and track the best scoring candidate slot in v11/v13. [callee:0x0041E840, callee:0x0041E890, source:raw]
    // RETURN: After the loop, promote the selected target slot (v12 if it is valid, otherwise v13) to classification 3 (scoring/overtake target) by writing 3 at this + 4*index, and return the selected slot index (or -1 when no slot was selected). [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_418EE0(_BYTE* this)
    //   {
    //     int bestPosDelta = 0x7FFFFFFF, bestScoreDelta = 0x7FFFFFFF;
    //     int bestPosSlot = -1, bestScoreSlot = -1;
    //     int delta = dword_7C54F0 - this;
    //     int* entry = (int*)&unk_5F0CF8;
    //     int* out = (int*)this;
    //     for (int slot = 0; entry < dword_7C9AF8; entry += 4656, slot++, out++) {
    //       *out = 0;
    //       if (dword_7D0410 == 2) continue;
    //       if (entry[-1238] == -1) { *out = -1; continue; }
    //       if (dword_7C54E8 && dword_7C54E8 == *(void**)((char*)out + delta)) { *out = 1; continue; }
    //       if (*(int*)(dword_7C54E8 + 18592) == *(int*)(*(void**)((char*)out + delta) + 18592)) { *out = 2; continue; }
    //       if (dword_7D0410 != 4) continue;
    //       /* race-mode scoring-target selection with NestedDataSectionFieldAccessor(), AIEntrantLookupByName() and sub_4C2990(&dword_7D2DB0) >= 3 * /
    //     }
    //     int sel = bestPosSlot;
    //     if (sel < 0) { sel = bestScoreSlot; if (sel < 0) return -1; }
    //     *(int*)&this[4 * sel] = 3;
    //     return sel;
    //   }
    // UNRESOLVED: flt_59E43C and flt_59E7F4 are declared as referenced globals in the packet, but neither appears in the decompiled body; their exact role in the scoring threshold comparison is unresolved.
    // UNRESOLVED: Semantics of the entry sentinel field at (entry - 1238*4) and the team/position fields at +18592/+18192 depend on the vehicle struct layout, which is not fully known here.
    // UNRESOLVED: Return types of NestedDataSectionFieldAccessor and AIEntrantLookupByName are untyped in the source; the 0.9x/1.1x position band is literal arithmetic in the body.
}
