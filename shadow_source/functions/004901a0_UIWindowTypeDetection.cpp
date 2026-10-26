// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004901A0
// Canonical corpus name: UIWindowTypeDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIWindowTypeDetection_004901a0.c

void UnknownObject::UIWindowTypeDetection()
{
    // Classifies a UI window by building a 63-byte local copy of its name/path (this+0xB8, falling back to byte_5EA438 when null) and comparing it against three tokens, storing a numeric window type 0/1/2 in this+0xE4. Returns the outcome of the final comparison.
    // ASSIGNMENT: Initialize local 63-byte buffer v4: first byte from default path byte_5EA438, remaining 60 bytes zeroed by memset. [global:0x005EA438, source:raw]
    // GUARD: v2 = window name/path pointer at this+0xB8; when v2 is null, substitute default path byte_5EA438. [field:this:0x000000B8, global:0x005EA438, source:raw]
    // CALL: sub_587DD0 copies at most 63 bytes from v2 into local buffer v4. [callee:0x00587DD0, source:raw]
    // STATE_TRANSITION: If sub_588410(v4, byte_5CC21C) returns zero, write window type 0 to this+0xE4. [callee:0x00588410, global:0x005CC21C, field:this:0x000000E4, source:raw]
    // STATE_TRANSITION: If sub_588410(v4, aC_0) returns zero, write window type 1 to this+0xE4. [callee:0x00588410, global:0x005CC210, field:this:0x000000E4, source:raw]
    // STATE_TRANSITION: result = sub_588410(v4, aR); if result is zero, write window type 2 to this+0xE4. [callee:0x00588410, global:0x005C36F0, field:this:0x000000E4, source:raw]
    // RETURN: Return result, the outcome of the final sub_588410(v4, aR) comparison. [callee:0x00588410, source:raw]

    // Conservative worker pseudocode:
    //   copy_local(v4, byte_5EA438);
    //   v2 = this+0xB8 ? this+0xB8 : byte_5EA438;
    //   sub_587DD0(v4, v2, 63);
    //   if (!sub_588410(v4, byte_5CC21C)) this+0xE4 = 0;
    //   if (!sub_588410(v4, aC_0)) this+0xE4 = 1;
    //   result = sub_588410(v4, aR);
    //   if (!result) this+0xE4 = 2;
    //   return result;
    // UNRESOLVED: sub_588410 exact semantics (equality test vs prefix/suffix match) not established from this packet.
    // UNRESOLVED: Meaning of the three stored window type values (0, 1, 2) and their downstream effect not visible here.
    // UNRESOLVED: The three comparison tokens (byte_5CC21C, aC_0, aR) are read as raw bytes; their literal text content is not proven.
}
