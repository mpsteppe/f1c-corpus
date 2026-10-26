// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B16B0
// Canonical corpus name: TrackConfigurationNameBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackConfigurationNameBuilder_004b16b0.c

void UnknownObject::TrackConfigurationNameBuilder()
{
    // Builds a track-configuration name path for the object. Reads the track name pointer at this+0x2D50 (defaulting to byte_5EA438 when null); if non-empty, runs NameCompareAndFormat on it and copies the default directory string. Then reads the config name at this+0x2D6C (defaulting to byte_5EA438); if non-empty, copies three object-held path strings (this+0x2D5C, this+0x2D64, this+0x2D6C) plus the default directory into reallocated buffers and returns the final copy result; otherwise returns 0.
    // ASSIGNMENT: Load the track name pointer from this+0x2D50; use the byte_5EA438 default directory string when the pointer is null [field:this:0x00002D50, global:0x005EA438, source:raw]
    // GUARD: Track-name block runs only when strlen(track name) is non-zero; otherwise the whole block is skipped [field:this:0x00002D50, source:raw]
    // CALL: NameCompareAndFormat(this, track name) compares/formats the track name, loading season data and audio; track name re-read from this+0x2D50, defaulting to byte_5EA438 when null [callee:0x004B1410, field:this:0x00002D50, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc(byte_5EA438) copies the default directory string into a reallocated buffer [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Load the config name pointer from this+0x2D6C; use the byte_5EA438 default directory string when the pointer is null; initialize the result to 0 [field:this:0x00002D6C, global:0x005EA438, source:raw]
    // GUARD: Config-path block runs only when strlen(config name) is non-zero; otherwise the function returns the initial result 0 [field:this:0x00002D6C, source:raw]
    // CALL: StringCopyWithBufferRealloc of the first config path string read at this+0x2D5C (defaulting to byte_5EA438 when null) [callee:0x00566650, field:this:0x00002D5C, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc of the second config path string read at this+0x2D64 (defaulting to byte_5EA438 when null) [callee:0x00566650, field:this:0x00002D64, global:0x005EA438, source:raw]
    // CALL: StringCopyWithBufferRealloc of the config name string re-read at this+0x2D6C (defaulting to byte_5EA438 when null) [callee:0x00566650, field:this:0x00002D6C, global:0x005EA438, source:raw]
    // RETURN: Return the result of StringCopyWithBufferRealloc(byte_5EA438), the final default-directory copy; when the config name was empty the function instead returns 0 [callee:0x00566650, global:0x005EA438, source:raw]
    // CALL: Invoked by SessionStateByte7CE25FSetter (00464600) as part of session-state processing [caller:0x00464600, source:raw]

    // Conservative worker pseudocode:
    //   trackName = this[0x2D50/4];
    //   if (trackName == 0) trackName = byte_5EA438;
    //   if (strlen(trackName)) {
    //     p = this[0x2D50/4];
    //     if (p == 0) p = byte_5EA438;
    //     NameCompareAndFormat(this, p);
    //     StringCopyWithBufferRealloc(byte_5EA438);
    //   }
    //   configName = this[0x2D6C/4];
    //   if (configName == 0) configName = byte_5EA438;
    //   result = 0;
    //   if (strlen(configName)) {
    //     StringCopyWithBufferRealloc(this[0x2D5C/4] or byte_5EA438);
    //     StringCopyWithBufferRealloc(this[0x2D64/4] or byte_5EA438);
    //     StringCopyWithBufferRealloc(this[0x2D6C/4] or byte_5EA438);
    //     return StringCopyWithBufferRealloc(byte_5EA438);
    //   }
    //   return result;
    // UNRESOLVED: The semantic role of byte_5EA438 (default application directory) is DERIVED from the skeleton fill and not verifiable from this packet
    // UNRESOLVED: The exact meaning of the returned buffer-copy result (buffer pointer vs count) is not documented in this function
}
