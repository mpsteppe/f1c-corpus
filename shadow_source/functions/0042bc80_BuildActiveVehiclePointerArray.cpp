// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042BC80
// Canonical corpus name: BuildActiveVehiclePointerArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BuildActiveVehiclePointerArray_0042bc80.c

void UnknownObject::BuildActiveVehiclePointerArray()
{
    // Builds the global active-vehicle pointer array: scans every vehicle slot from unk_5EC6D8 up to byte_7C54D8 and appends each slot whose dword at index 3250 is not -1 into dword_7C54F0 (VehiclePtrArray). If fewer than 104 vehicles were collected, zero-fills the unused array tail, then backfills remaining slots with live vehicles not already listed. Finally records the array indices of two reference vehicle pointers as dword_7C54DC (CurrentPlayerIndex) and dword_7C54E4 (CurrentVehicleIndex). Returns the number of active vehicles.
    // LOOP: Scan the vehicle array from its base unk_5EC6D8 to byte_7C54D8 (VehicleArrayEnd) in steps of 4656 dwords, the vehicle-struct stride. [global:0x005EC6D8, global:0x007C54D8]
    // GUARD: Skip the vehicle when its dword at index 3250 equals -1, i.e. the slot is not live. [global:0x005EC6D8]
    // ASSIGNMENT: Append the active vehicle pointer into dword_7C54F0 (VehiclePtrArray) at index v0 and increment v0. [global:0x007C54F0]
    // GUARD: Only when fewer than 104 vehicles were collected, clear the unused tail of VehiclePtrArray. [global:0x007C5690]
    // CALCULATION: Zero 4 * (104 - v0) bytes starting at 4 * v0 + 8148208, i.e. the empty tail of dword_7C54F0 spanning up to byte_7C5690. [global:0x007C54F0, global:0x007C5690]
    // LOOP: Backfill: for each empty slot rescan every vehicle from unk_5EC6D8 (stride 18624 bytes) up to byte_7C54D8, and skip any pointer already stored in dword_7C54F0, using byte_7C5690 as the scan bound. [global:0x005EC6D8, global:0x007C54D8, global:0x007C54F0, global:0x007C5690]
    // GUARD: Duplicate guard: a vehicle already present in dword_7C54F0 is not appended again; advance to the next vehicle candidate instead. [global:0x007C54F0]
    // ASSIGNMENT: Write the first not-yet-listed vehicle pointer into the empty backfill slot and advance the fill pointer. [global:0x005EC6D8, global:0x007C5690]
    // ASSIGNMENT: Initialize dword_7C54DC and dword_7C54E4 to 0 before the index-matching scan, so a reference pointer not found in the array leaves its index at 0. [global:0x007C54DC, global:0x007C54E4]
    // LOOP: Walk the built array: when entry v5 equals dword_7C54E0 store v5 into dword_7C54DC (CurrentPlayerIndex), and when it equals dword_7C54E8 store v5 into dword_7C54E4 (CurrentVehicleIndex). [global:0x007C54F0, global:0x007C54E0, global:0x007C54DC, global:0x007C54E8, global:0x007C54E4]
    // RETURN: Return v0, the number of active vehicles placed in VehiclePtrArray. [function:0x0042BC80, source:raw]

    // Conservative worker pseudocode:
    //   v0 = 0;
    //   for (v1 = &unk_5EC6D8; v1 < &byte_7C54D8; v1 += 4656) if (v1[3250] != -1) dword_7C54F0[v0++] = (int)v1;
    //   if (v0 < 104) { memset((char*)dword_7C54F0 + 4 * v0, 0, 4 * (104 - v0)); for each empty slot append the first vehicle (from &unk_5EC6D8, stride 18624 bytes) not already in dword_7C54F0; }
    //   dword_7C54DC = 0; dword_7C54E4 = 0;
    //   for (v5 = 0; v5 < v0; v5++) { if (dword_7C54F0[v5] == dword_7C54E0) dword_7C54DC = v5; if (dword_7C54F0[v5] == dword_7C54E8) dword_7C54E4 = v5; }
    //   return v0;
    // UNRESOLVED: Semantic names of the two reference pointers dword_7C54E0 and dword_7C54E8, and their outputs dword_7C54DC and dword_7C54E4, come from existing-analysis labels (postProcessInput / PlayerVehiclePtr / CurrentPlayerIndex / CurrentVehicleIndex), not from this function's code; those names are placeholders pending independent evidence.
    // UNRESOLVED: byte_7C5690 is used in this function purely as the end-of-array sentinel for dword_7C54F0 (capacity 104), although the corpus label for it is InitStateFlag.
    // UNRESOLVED: The backfill loop's `if (v3)` null check appears unreachable in practice within the loop bounds; its intended purpose is uncertain.
    // UNRESOLVED: Both 4656-dword and 18624-byte strides appear in the raw source for the same vehicle-struct walk; they are equivalent, not two different strides.
}
