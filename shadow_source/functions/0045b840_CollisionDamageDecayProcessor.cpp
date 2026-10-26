// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B840
// Canonical corpus name: CollisionDamageDecayProcessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionDamageDecayProcessor_0045b840.c

void UnknownObject::CollisionDamageDecayProcessor()
{
    // Processes collision damage decay across up to 4 per-frame active channels. Reads a rotating start index from this+0x31C, clears the active-damage flag byte this+0x320, renders the selection rectangle via UICursorSelectionRectangleRenderWithInterpolatio, computes a text-line advance from the screen width, scans up to 8 slots (92-byte stride) for a damage value greater than 0.0 at slot+144, renders damage text at slot+60 with the value at slot+140, subtracts the global cooling rate dbl_8AFE90 from the damage, sets the active flag if damage remains or resets the channel via PerIndexStructFieldResetter otherwise, and repeats up to 4 times.
    // CALL: FloatArrayThresholdSearch() runs an initialization threshold/count search before the decay loop. [callee:0x0045BB00]
    // ASSIGNMENT: Read the rotating scan start index from this+0x31C into v2 and clear the active-damage flag byte this+0x320 to 0. [field:this:0x0000031C, field:this:0x00000320]
    // CALL: UICursorSelectionRectangleRenderWithInterpolatio((float*)this) renders the cursor selection rectangle each frame. [callee:0x0045B660]
    // CALL: TwinFieldGetter_cf30(&v12, 0) retrieves a value used later for text positioning. [callee:0x004DCF30]
    // CALCULATION: Compute the text-line advance v13 = CRTFtol(dword_5D6D64 * 0.035), converting the scaled screen width to an integer. [callee:0x00587BDC, global:0x005D6D64]
    // LOOP: Scan loop: for v5 in 0..7, slot index v6 = (v5 + start) % 8, slot address v7 = 92 * v6 + this; stop when a slot's damage at v7+144 is greater than 0.0 or return when all 8 slots have been checked. [source:raw]
    // GUARD: Break out of the scan when *(float*)(v7+144) > 0.0, and return early once v5 reaches 8 with no active damage slot. [source:raw]
    // CALL: TextRenderDispatcher(v7+60, v12/2, 0, *(v7+140), 2, -1.0, -1.0, 0) renders the damage text at the slot's screen position using the value stored at slot+140. [callee:0x004DD030]
    // CALCULATION: Decay the slot damage: v8 = *(float*)(v7+144) - dbl_8AFE90, then store v8 back to v7+144. [global:0x008AFE90]
    // STATE_TRANSITION: If the remaining damage v8 is greater than 0.0 set the active-damage flag this+0x320 to 1; otherwise reset the channel at index v6 via PerIndexStructFieldResetter((_DWORD*)this, v6). [field:this:0x00000320, callee:0x0045B430]
    // LOOP: Accumulate v3 += v13 and repeat the scan/decay pass while the pass counter v9 is less than 4, resuming the slot scan from v10. [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionDamageDecayProcessor(void *this) {
    //     FloatArrayThresholdSearch();
    //     int start = *(int*)(this + 0x31C);
    //     *(byte*)(this + 0x320) = 0;
    //     UICursorSelectionRectangleRenderWithInterpolatio((float*)this);
    //     int textVal; TwinFieldGetter_cf30(&textVal, 0);
    //     int lineAdvance = CRTFtol((double)dword_5D6D64 * 0.035);
    //     int next = 0;
    //     for (int pass = 0; pass < 4; ++pass) {
    //       for (int v5 = next; v5 < 8; ++v5) {
    //         int slot = 92 * ((v5 + start) % 8) + (int)this;
    //         if (*(float*)(slot + 144) <= 0.0) { next = v5 + 1; continue; }
    //         TextRenderDispatcher(slot + 60, textVal / 2, 0, *(int*)(slot + 140), 2, -1.0, -1.0, 0);
    //         float remaining = *(float*)(slot + 144) - dbl_8AFE90;
    //         *(float*)(slot + 144) = remaining;
    //         if (remaining > 0.0) *(byte*)(this + 0x320) = 1;
    //         else PerIndexStructFieldResetter((_DWORD*)this, (v5 + start) % 8);
    //         next = v5 + 1;
    //         break;
    //       }
    //     }
    //   }
    // UNRESOLVED: Owner object identity is unknown; the this-pointer carries both damage-channel state and UI rendering state.
    // UNRESOLVED: The physical meaning of the slot data at stride 92 and the damage value at slot+144 is inferred, not runtime-proven.
    // UNRESOLVED: flt_59E440 and flt_59F078 appear only in legacy analysis as physics thresholds; they have no raw-source grounding here.
    // UNRESOLVED: The exact text content, color and formatting arguments passed to TextRenderDispatcher are caller/UI-determined.
}
