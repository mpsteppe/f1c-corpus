// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C78F0
// Canonical corpus name: NationalityDriverInfoLoader
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/NationalityDriverInfoLoader_004c78f0.c

void F1CVehicle::NationalityDriverInfoLoader()
{
    // Nationality/career driver-info loader operating on the F1CVehicle driver region. For driver index a2, it indexes the nationality data array (dword_8AC394 + 1060 * a2), sets the driver full name via SetDriverName from the entry, fills the 23-byte nationality string buffer at this + 18016 (defaulting to byte_5EA438 and, when AudioChannelStop(this + 17952) succeeds, to the aNationality data entry via StringKeyedLinkedListSearch + DataEntryAccessor), copies the short description (this + 18040) and long description (this + 18104), sets the abbreviation code via ShortStringSet, copies the nationality flag path into this + 18196, and stores the driver index at this + 18584. Returns the ShortStringSet result.
    // CALCULATION: Index the nationality data array for driver a2: v2 = (const char**)(dword_8AC394 + 1060 * a2); each entry is 1060 bytes. [global:0x008AC394, source:raw]
    // CALL: Set the driver full name from entry offset 47: SetDriverName(this, v2 + 47). [callee:0x004C6980, source:raw]
    // CALL: Seed the 23-byte nationality buffer with the default string: sub_587DD0(this + 18016, byte_5EA438, 23). [callee:0x00587DD0, global:0x005EA438, source:raw]
    // ASSIGNMENT: Null-terminate the nationality buffer: *(BYTE*)(this + 18039) = 0 (field 0x4677). [field:this:0x00004677, source:raw]
    // GUARD: Guard on AudioChannelStop(this + 17952) being true before looking up the nationality string. [callee:0x00568210, source:raw]
    // CALL: Look up the nationality node: v4 = StringKeyedLinkedListSearch(aNationality). [callee:0x005679C0, global:0x005C73B8, source:raw]
    // GUARD: If the lookup returned a node (v4 != 0), fetch its data entry. [source:raw]
    // CALL: Fetch the nationality display string v5 = DataEntryAccessor(v4), copy it into this + 18016 via sub_587DD0(this + 18016, v5, 23), and null-terminate at this + 18039 (field 0x4677). [callee:0x00567970, callee:0x00587DD0, field:this:0x00004677, source:raw]
    // CALL: Copy the short description from entry offset 63 into this + 18040: sub_587DD0(this + 18040, v2 + 63, 63). [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Null-terminate the short description: *(BYTE*)(this + 18103) = 0 (field 0x46B7). [field:this:0x000046B7, source:raw]
    // CALL: Copy the long description from entry offset 31 into this + 18104: sub_587DD0(this + 18104, v2 + 31, 63). [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: Null-terminate the long description: *(BYTE*)(this + 18167) = 0 (field 0x46F7). [field:this:0x000046F7, source:raw]
    // CALL: Set the abbreviation code: result = ShortStringSet(this, v2 + 29). [callee:0x004C69B0, source:raw]
    // GUARD: Fallback for the flag-path string: v7 = *v2, and when *v2 is null use byte_5EA438. [global:0x005EA438, source:raw]
    // CALL: Copy the nationality flag path into this + 18196 via an unbounded strcpy. [source:raw]
    // ASSIGNMENT: Store the driver index: *(DWORD*)(this + 18584) = a2 (field 0x4898). [field:this:0x00004898, source:raw]
    // RETURN: Return the ShortStringSet result. [source:raw]

    // Conservative worker pseudocode:
    //   const char** v2 = (const char**)(dword_8AC394 + 1060 * a2);
    //   SetDriverName(this, v2 + 47);
    //   sub_587DD0(this + 18016, byte_5EA438, 23);
    //   *(BYTE*)(this + 18039) = 0;
    //   if (AudioChannelStop(this + 17952)) {
    //     int v4 = StringKeyedLinkedListSearch(aNationality);
    //     if (v4) {
    //       int v5 = DataEntryAccessor(v4);
    //       sub_587DD0(this + 18016, v5, 23);
    //       *(BYTE*)(this + 18039) = 0;
    //     }
    //   }
    //   sub_587DD0(this + 18040, v2 + 63, 63); *(BYTE*)(this + 18103) = 0;
    //   sub_587DD0(this + 18104, v2 + 31, 63); *(BYTE*)(this + 18167) = 0;
    //   int result = ShortStringSet(this, v2 + 29);
    //   const char* v7 = *v2 ? *v2 : byte_5EA438;
    //   strcpy(this + 18196, v7);
    //   *(DWORD*)(this + 18584) = a2;
    //   return result;
    // UNRESOLVED: Global dword_8AD3B4 is listed in the packet but does not appear in the raw source; its role here is unknown.
    // UNRESOLVED: Why the nationality lookup is gated on AudioChannelStop(this + 17952) is unresolved; the call name is a corpus label, not proof of audio semantics.
    // UNRESOLVED: byte_5EA438 serves as the default for both the 23-byte nationality buffer and the flag-path fallback; its exact content is unknown.
    // UNRESOLVED: The strcpy into this + 18196 is unbounded, unlike the sub_587DD0 copies; whether the destination is long enough is unverified.
    // UNRESOLVED: Entry field indices 29/31/47/63 are relative to the 1060-byte entry stride; their semantic meaning (abbreviation, descriptions, name) is DERIVED from the existing analysis.
}
