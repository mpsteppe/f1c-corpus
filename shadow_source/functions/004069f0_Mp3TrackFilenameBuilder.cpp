// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004069F0
// Canonical corpus name: sub_4069F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4069F0_004069f0.c

void UnknownObject::Mp3TrackFilenameBuilder()
{
    // Builds an MP3 track filename for a music slot. If the slot handle this[23] (offset 0x5C) is already active (!= -1), frees the previous resource via sub_406A70 before overwriting. Formats a new string handle a2 with StringFormatWith0x40Size (0x8000, 256) and stores it at this[23]; on success, calls sub_58C724 with a3, then formats the track filename "%s%d,%d.mp3" from global asc_5BE820, this[23] and track index this[7], and copies the buffer via StringCopyWithBufferRealloc. Returns whether the slot handle is now active (this[23] != -1).
    // GUARD: Guard on slot activity: if this[23] (offset 0x5C) != -1, call sub_406A70(this) to free the previous slot resource before overwriting. [guard:0, field:this:0x0000005C, callee:0x00406A70]
    // CALL: v4 = StringFormatWith0x40Size(a2, 0x8000, 256) creates a formatted string handle from input string a2. [callee:0x00595AE2]
    // ASSIGNMENT: Store the new formatted string handle in the slot: this[23] = v4. [field:this:0x0000005C]
    // GUARD: Guard on format success: proceed only when v4 != -1. [source:raw]
    // CALL: Call sub_58C724(v4, a3, 0) operating on the formatted string resource handle with the a3 parameter. [callee:0x0058C724]
    // CALL: Format the track filename into local buffer v6 via StringFormatWithBufferOverflowCheck with pattern "%s%d,%d.mp3", reading global asc_5BE820, slot handle this[23] and track index this[7] (offset 0x1C). [callee:0x0058815F, global:0x005BE820, field:this:0x0000005C, field:this:0x0000001C]
    // CALL: Copy/realloc the built filename buffer via StringCopyWithBufferRealloc(v6). [callee:0x00566650]
    // RETURN: Return whether the slot handle is now active: this[23] != -1. [field:this:0x0000005C]

    // Conservative worker pseudocode:
    //   BOOL Mp3TrackFilenameBuilder(_DWORD *this, const CHAR *a2, LONG a3) {
    //     if (this[23] != -1)
    //       sub_406A70(this);
    //     int v4 = StringFormatWith0x40Size(a2, 0x8000, 256);
    //     this[23] = v4;
    //     if (v4 != -1) {
    //       sub_58C724(v4, a3, 0);
    //       _BYTE v6[32];
    //       StringFormatWithBufferOverflowCheck(v6, "%s%d,%d.mp3", asc_5BE820, this[23], this[7]);
    //       StringCopyWithBufferRealloc(v6);
    //     }
    //     return this[23] != -1;
    //   }
    // UNRESOLVED: Meaning of the format parameters 0x8000 and 256 passed to StringFormatWith0x40Size (capacity/tag/encoding roles unknown).
    // UNRESOLVED: Purpose of the a3 argument forwarded to sub_58C724.
    // UNRESOLVED: Global aSDDMp3 (0x005BE854) is adjacent to the format-string constant asc_5BE820 but is not referenced in the raw source text; its relationship to the "%s%d,%d.mp3" pattern is unresolved.
}
