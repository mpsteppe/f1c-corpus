// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041C4C0
// Canonical corpus name: PositionBasedMessageDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PositionBasedMessageDisplay_0041c4c0.c

void UnknownObject::PositionBasedMessageDisplay()
{
    // Dispatches a position-based race status message. Guards on the race-active flag and track-condition state; when active, initializes a driver-table-entry struct with sentinel values, computes the standings position plus two via the sort buffer, selects timing parameters based on a boolean flag (live: -1.0/0.0, else sentinels -2.0/-2.0), derives a message ID, populates the entry through the shared driver data table, and inserts it.
    // GUARD: Proceed only when race-active flag dword_7D0308 is non-zero and track-condition float flt_7CF3C8 is non-zero; otherwise return without dispatching. [global:0x007D0308, global:0x007CF3C8, source:raw]
    // CALL: Initialize local driver-table-entry struct v6 with sentinel/default values via StructInitWithSentinelValues. [callee:0x004144D0, source:raw]
    // CALCULATION: Query standings sort buffer at &dword_7D2DB0 for current position and add 2 (v1 = sub_4C2990(&dword_7D2DB0) + 2). [callee:0x004C2990, global:0x007D2DB0, source:raw]
    // GUARD: Branch on boolean parameter a1: non-zero selects live timing params, zero selects default sentinels. [source:raw]
    // ASSIGNMENT: a1 non-zero: set timing params v5 = -1.0 and v4 = 0.0. [source:raw]
    // ASSIGNMENT: a1 zero: set timing params v5 = -2.0 and v4 = -2.0. [source:raw]
    // ASSIGNMENT: Copy position plus two into v3 (v3 = v1). [source:raw]
    // CALL: Compute message ID for position-based race status (v2 = ThunkToFUN004201e0()). [callee:0x004203D0, source:raw]
    // CALL: Populate v6 via DriverDataTableLookupAndTimeConversion with message ID v2, position+2 v3, three default -1 arguments, and float params v4/v5. [callee:0x004144F0, source:raw]
    // CALL: Insert populated entry v6 into shared driver data table anchored at flt_5EA618 via InsertDriverTableEntry. [callee:0x00418560, global:0x005EA618, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7D0308 != 0 && flt_7CF3C8 != 0.0f) {
    //       StructInitWithSentinelValues(&entry);
    //       position = sub_4C2990(&dword_7D2DB0) + 2;
    //       if (a1) { v4 = 0.0f; v5 = -1.0f; }
    //       else    { v4 = -2.0f; v5 = -2.0f; }
    //       v3 = position;
    //       v2 = ThunkToFUN004201e0();
    //       DriverDataTableLookupAndTimeConversion(&entry, v2, v3, -1, -1, -1, v4, v5);
    //       InsertDriverTableEntry(flt_5EA618, &entry);
    //   }
    // UNRESOLVED: No confirmed owner; ABI name Position_based_Message_Display is a LEGACY label, so owner stays UnknownObject/UNKNOWN.
    // UNRESOLVED: Global 0x0059E440 (flt_59E440) is listed in deterministic facts as read by this function but does not appear in the raw source text; its role here is unconfirmed.
    // UNRESOLVED: Meaning of the three default -1 arguments to DriverDataTableLookupAndTimeConversion is not resolved; assumed sentinel/default indices.
    // UNRESOLVED: Callers are sub_40DE60 and sub_4F9480; function is not on a frame path from the tick root (on_frame_path false), so call frequency is unknown.
}
