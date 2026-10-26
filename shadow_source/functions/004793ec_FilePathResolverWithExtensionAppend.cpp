// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004793EC
// Canonical corpus name: FilePathResolverWithExtensionAppend
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FilePathResolverWithExtensionAppend_004793ec.c

void UnknownObject::FilePathResolverWithExtensionAppend()
{
    // Builds a full file path for a track-style file: extracts the basename from the input path, assembles two extension suffix strings from file-extension globals (0x005C71C0/0x005C71C4/0x005C71C8 and 0x005C7190/0x005C7194/0x005C7196), strips trailing backslashes from the working copy in byte_7CD718, resolves it through sub_497AD0, copies either the resolved path or the default directory fallback byte_5EA438 into the caller buffer, then hands the assembled path to sub_479170 for further parsing.
    // GUARD: Null input path guard: when a2 is null the function returns immediately via SingleCallWrapper_8e80 with argument 0 [callee:0x00478E80, source:raw]
    // CALCULATION: Basename extraction: walk a2 backward from its end to the last backslash character and treat everything after it as the basename start v3 [source:raw]
    // CALL: Copy the basename into local buffer v15 (16 bytes) with sub_587DD0, terminate it, then append track-extension bytes read from globals 0x005C71C0, 0x005C71C4 and 0x005C71C8 [callee:0x00587DD0, global:0x005C71C0, global:0x005C71C4, global:0x005C71C8, source:raw]
    // CALL: Copy the same basename into local buffer v16 (16 bytes) with sub_587DD0, terminate it, then append file-extension bytes read from globals 0x005C7190, 0x005C7194 and 0x005C7196 [callee:0x00587DD0, global:0x005C7190, global:0x005C7194, global:0x005C7196, source:raw]
    // ASSIGNMENT: Copy the input path a2 into the working buffer byte_7CD718 (up to 255 bytes) with sub_587DD0 and write the null terminator flag byte_7CD817 = 0 [callee:0x00587DD0, global:0x007CD718, global:0x007CD817, source:raw]
    // LOOP: Trailing-backslash strip loop over byte_7CD718: overwrite characters with 0 walking backward until a backslash is found or the start of the buffer is reached [global:0x007CD718, source:raw]
    // CALCULATION: Assemble the full path: copy the stripped path into local buffer v17 (256 bytes) with sub_587DD0, strcat the v15 extension suffix onto byte_7CD718, and strcat the v16 extension suffix onto v17 [callee:0x00587DD0, global:0x007CD718, source:raw]
    // ASSIGNMENT: Copy the assembled working path byte_7CD718 into the resolved-path global unk_7CD618 (up to 255 bytes) with sub_587DD0 and write the copy flag byte_7CD717 = 0 [callee:0x00587DD0, global:0x007CD618, global:0x007CD717, source:raw]
    // CALL: Resolve the path: sub_497AD0(byte_7CD718, 0) produces the resolved path, and its result is wrapped by SingleCallWrapper_8e80 [callee:0x00497AD0, callee:0x00478E80, global:0x007CD718, source:raw]
    // ASSIGNMENT: Copy the outcome back to the caller: on a non-zero resolution result StringCopyWithBufferRealloc copies the resolved path into a2, otherwise it copies the default application-directory fallback byte_5EA438 [callee:0x00566650, global:0x005EA438, source:raw]
    // CALL: Parse/use the assembled path: return sub_479170(this, v17), passing the local assembled path buffer to the downstream parser [callee:0x00479170, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return SingleCallWrapper_8e80(0);
    //   v3 = end_of(a2); walk back to the last backslash; v3 = char after it;
    //   sub_587DD0(v15, v3, 4); v15[4] = 0; append globals 0x005C71C0, 0x005C71C4, 0x005C71C8;
    //   sub_587DD0(v16, v3, 4); v16[4] = 0; append globals 0x005C7190, 0x005C7194, 0x005C7196;
    //   sub_587DD0(byte_7CD718, a2, 255); byte_7CD817 = 0;
    //   strip trailing backslashes from byte_7CD718;
    //   sub_587DD0(v17, byte_7CD718, 255);
    //   strcat(byte_7CD718, v15); v17[255] = 0; strcat(v17, v16);
    //   sub_587DD0(unk_7CD618, byte_7CD718, 255); byte_7CD717 = 0;
    //   v13 = sub_497AD0(byte_7CD718, 0); SingleCallWrapper_8e80(v13);
    //   if (v13) StringCopyWithBufferRealloc(a2); else StringCopyWithBufferRealloc(byte_5EA438);
    //   return sub_479170(this, v17);
    // UNRESOLVED: The exact meaning of the two 4/10-byte extension literal groups (0x005C71C0/0x005C71C4/0x005C71C8 and 0x005C7190/0x005C7194/0x005C7196) is not defined here; sub_587DD0's copy semantics (fixed 4 bytes vs length-limited) are inferred only from call sites
    // UNRESOLVED: The return value consumed by the caller of sub_479170 is not visible in this packet
}
