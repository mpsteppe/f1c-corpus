// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048C0E0
// Canonical corpus name: WindowControlTypeDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WindowControlTypeDetection_0048c0e0.c

void UnknownObject::WindowControlTypeFromPath()
{
    // Determines a window control type (0, 1 or 2) stored at this+0x30C by comparing the path string at this+0xB8 (falling back to the default path byte_5EA438 when null) against three reference strings via sub_588410. All three comparisons run sequentially and the last write wins; returns 0.
    // ASSIGNMENT: Read the path string pointer at this+0xB8; when it is null use the default path byte_5EA438. [field:this:0x000000B8, global:0x005EA438, source:raw]
    // CALL: Compare the path pointer against reference string byte_5CC21C via sub_588410; when the comparison returns zero, write control type 0 to this+0x30C. [field:this:0x0000030C, callee:0x00588410, global:0x005CC21C, source:raw]
    // CALL: Compare the path pointer against reference string aR via sub_588410; when the comparison returns zero, write control type 1 to this+0x30C. [field:this:0x0000030C, callee:0x00588410, global:0x005C36F0, source:raw]
    // CALL: Compare the path pointer against reference string aC_0 via sub_588410; when the comparison returns zero, write control type 2 to this+0x30C. [field:this:0x0000030C, callee:0x00588410, global:0x005CC210, source:raw]
    // RETURN: Return 0 after all three sequential comparisons; the value left at this+0x30C is the last matching case (or unchanged if no comparison wrote it). [function:0x0048C0E0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_48C0E0(int* this) {
    //     char* p = (char*)this[46];
    //     if (!p) p = (char*)byte_5EA438;
    //     if (!sub_588410(p, byte_5CC21C)) this[195] = 0;
    //     if (!sub_588410(p, aR)) this[195] = 1;
    //     if (!sub_588410(p, aC_0)) this[195] = 2;
    //     return 0;
    //   }
    // UNRESOLVED: Return convention of sub_588410 is not established here: whether a zero return means the strings match or do not match must be corroborated at 0x00588410.
    // UNRESOLVED: Actual string contents behind the labels aR and aC_0 are not present in this packet; the fill labels them 'R' and 'c' from external context.
    // UNRESOLVED: Exact meaning of control types 0, 1 and 2 is not defined by this packet.
    // UNRESOLVED: Identity of the owning window-control object is unknown.
}
