// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047DBE0
// Canonical corpus name: TelemetryDisplaySwitch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TelemetryDisplaySwitch_0047dbe0.c

void UnknownObject::TelemetryModeSwitchDisplay()
{
    // Dispatches telemetry data to a UI text element based on a mode selector field at this+0xEC. Mode 0x1E0 formats the indexed vehicle list entry, mode 0x1E1 formats the difference between the current delegation value and the vehicle lifetime average, mode 0x1E2 formats the range width, and mode 0x1E3 renders an engine/RPM status string built from a post-process data pointer (falling back to a static string when the pointer is null or the count is non-positive). Every formatted result is handed to UIStringComparison and the function returns 0 on every path.
    // GUARD: Switch dispatch on the mode selector field this[59] (offset 0xEC) via the jump table at jpt_47DBFA: 0x1E0 vehicle list, 0x1E1 delta time, 0x1E2 range width, 0x1E3 engine status; the default case returns 0. [field:this:0x000000EC, global:0x0047DCF4, source:raw]
    // CALL: Mode 0x1E0: VehicleDataAccessor(&dword_8AB6EC) reads the vehicle data root, UIListIndexedAccessor selects the indexed list entry, and UIStringComparison(v2) pushes the resulting text to the UI element; then return 0. [callee:0x00487010, callee:0x00488B40, callee:0x004B9E30, global:0x008AB6EC, source:raw]
    // CALCULATION: Mode 0x1E1: v8 = Delegation(&dword_8AB6EC) gives the current value and v4 = VehicleLifetimeAverageAccessor(&dword_8AB6EC) gives the lifetime average; the displayed delta is v8 - v4. [callee:0x004B9CB0, callee:0x004B9CE0, global:0x008AB6EC, source:raw]
    // CALL: Mode 0x1E1 and 0x1E2: StringFormatWithBufferOverflowCheck formats the float value with the "%1.3f" format string at a13f, then UIStringComparison pushes the formatted text and the function returns 0. [callee:0x00488B40, callee:0x0058815F, global:0x005C5BCC, source:raw]
    // CALL: Mode 0x1E2: v5 = RangeWidthGetter(&dword_8AB6EC) reads the range width, which is then formatted and displayed as in mode 0x1E1. [callee:0x004B9C80, global:0x008AB6EC, source:raw]
    // GUARD: Mode 0x1E3: when dword_7C54E0 (post-process data pointer) is null, fall back to the static engine-status string asc_5C7370 and display it directly (LABEL_9). [global:0x005C7370, global:0x007C54E0, source:raw]
    // CALCULATION: Mode 0x1E3, valid pointer path: v6 = *(dword_7C54E0 + 16480) reads the status count and v7 = (dword_7C54E0 + 17952) is the status text pointer within the engine-status structure. [global:0x007C54E0, source:raw]
    // GUARD: Mode 0x1E3: when the count v6 is not positive, display the base text pointer v7 directly (LABEL_9); otherwise StringFormatWithBufferOverflowCheck builds "(%d) %s" from the count and text using the format string at aDS_7, then UIStringComparison displays it. [callee:0x00488B40, callee:0x0058815F, global:0x005C7374, global:0x007C54E0, source:raw]
    // RETURN: Every dispatch path returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   switch (this[59]) {
    //     case 0x1E0: UIStringComparison(UIListIndexedAccessor(VehicleDataAccessor(&dword_8AB6EC))); break;
    //     case 0x1E1: fmt("%1.3f", Delegation(&dword_8AB6EC) - VehicleLifetimeAverageAccessor(&dword_8AB6EC)); break;
    //     case 0x1E2: fmt("%1.3f", RangeWidthGetter(&dword_8AB6EC)); break;
    //     case 0x1E3: if (!dword_7C54E0) { text = asc_5C7370; } else { count = *(dword_7C54E0 + 16480); text = dword_7C54E0 + 17952; if (count > 0) fmt("(%d) %s", count, text); }
    //     default: return 0;
    //   }
    //   UIStringComparison(formatted);
    //   return 0;
    // UNRESOLVED: The exact semantic roles of dword_8AB6EC and dword_7C54E0 are labeled in the existing analysis as scoring-data and post-process data pointers at DERIVED trust; those names are not independently evidenced in the packet.
    // UNRESOLVED: The byte offsets 16480 and 17952 within the dword_7C54E0 structure are not covered by any packet field entry, so their meaning (count vs text offset) is inferred from usage.
    // UNRESOLVED: The displayed modes (vehicle list, delta time, range width, engine status) are interpretations from the fill's field usage, not confirmed by runtime evidence.
}
