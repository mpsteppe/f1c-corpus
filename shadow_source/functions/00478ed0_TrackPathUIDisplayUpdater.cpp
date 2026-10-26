// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478ED0
// Canonical corpus name: sub_478ED0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_478ED0_00478ed0.c

void UnknownObject::TrackPathUIDisplayUpdater()
{
    // Updates the track-path display in the UI. Resolves the stored path at this[87] (falling back to the default path byte_5EA438 when null), compares it with the current track path dword_7CE5D0, and when the stored path is null, empty or mismatched, pushes the current path through the vtable +176 callback. When session mode dword_7C569C and dword_7D0410 both equal 5 (championship server) and this[84] is set, it invokes the vtable +60 callback and raises byte_7CFF48. Ends with HitTest.
    // CALL: Resolve the stored path this[87] with fallback to byte_5EA438 when null, and compare it against the current track path dword_7CE5D0 (also defaulted) via sub_588410. [field:this:0x0000015C, callee:0x00588410, global:0x005EA438, global:0x007CE5D0, source:raw]
    // GUARD: When the stored path is null or empty, or does not match the current track path, fall through to the path-update callback. [source:raw]
    // CALL: Update the displayed track path by invoking the vtable +176 callback with the resolved current track path. [field:this:0x00000000, global:0x007CE5D0, source:raw]
    // GUARD: Championship-server condition: dword_7C569C == 5 and dword_7D0410 == 5 and this[84] (offset 0x150) is set. [field:this:0x00000150, global:0x007C569C, global:0x007D0410, source:raw]
    // CALL: When the championship-server condition holds, invoke the vtable +60 callback with argument 1 to raise the notification. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set the flag byte_7CFF48 to 1 alongside the championship-server notification. [global:0x007CFF48, source:raw]
    // CALL: HitTest(this) runs the UI hit test on the object. [callee:0x00479320, source:raw]
    // RETURN: The function returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_478ED0(int *this) {
    //     const char *stored = (const char*)this[87]; if (!stored) stored = byte_5EA438;
    //     if (strlen(stored)) {
    //       char *cur = dword_7CE5D0; if (!cur) cur = byte_5EA438;
    //       char *p = (char*)this[87]; if (!p) p = byte_5EA438;
    //       if (!sub_588410(p, cur)) return HitTest(this), 0;
    //     }
    //     char *cur = dword_7CE5D0; if (!cur) cur = byte_5EA438;
    //     ((void (__thiscall*)(int*, char*))*this[0])(this, cur);
    //     if (dword_7C569C == 5 && dword_7D0410 == 5 && this[84]) {
    //       ((void (__thiscall*)(int*, int))*this[0])(this, 1);
    //       byte_7CFF48 = 1;
    //     }
    //     HitTest(this);
    //     return 0;
    //   }
    // UNRESOLVED: obj fields at offsets 0x3C and 0xB0 are listed as read by this function in the deterministic facts but do not appear in the raw decompiled text; their role is unresolved.
    // UNRESOLVED: The vtable +176 and +60 callbacks and the meaning of the dword_7D0410 value 5 are inherited from existing analysis, not independently verified here.
}
