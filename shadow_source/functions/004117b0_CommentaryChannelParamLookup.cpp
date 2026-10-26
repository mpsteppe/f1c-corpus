// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004117B0
// Canonical corpus name: AudioCommentaryChannelConfiguration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioCommentaryChannelConfiguration_004117b0.c

void UnknownObject::CommentaryChannelParamLookup()
{
    // Looks up audio commentary channel parameters (two DWORD values and two pointers) by channel index. Channel 0 selects the default commentary globals; channel 1 selects the TV commentary globals; any other index returns 1 as an invalid-channel error without writing outputs.
    // ASSIGNMENT: Initialize result to 1 as the invalid-channel error default. [source:raw]
    // GUARD: If the channel index is greater than 1, return 1 immediately without writing any output. [source:raw]
    // GUARD: Within the valid range, branch on the channel index: a non-zero index (1) selects TV commentary parameters, a zero index selects default commentary parameters. [source:raw]
    // ASSIGNMENT: Channel 1 (TV): write dword_5BF8D0 and dword_5BF8D4 to the two output DWORDs and off_5BF8E8 and off_5BF8F0 to the two output pointers. [global:0x005BF8D0, global:0x005BF8D4, global:0x005BF8E8, global:0x005BF8F0]
    // ASSIGNMENT: Channel 0 (default): write dword_5BF8C8 and dword_5BF8CC to the two output DWORDs and off_5BF8D8 and off_5BF8E0 to the two output pointers. [global:0x005BF8C8, global:0x005BF8CC, global:0x005BF8D8, global:0x005BF8E0]
    // RETURN: Return 0 when the channel index was valid, 1 when it was out of range. [source:raw]

    // Conservative worker pseudocode:
    //   result = 1;
    //   if (channelIndex <= 1) {
    //     result = 0;
    //     if (channelIndex) {
    //       *outValue0 = dword_5BF8D0; *outValue1 = dword_5BF8D4;
    //       *outPtr0 = off_5BF8E8; *outPtr1 = off_5BF8F0;
    //     } else {
    //       *outValue0 = dword_5BF8C8; *outValue1 = dword_5BF8CC;
    //       *outPtr0 = off_5BF8D8; *outPtr1 = off_5BF8E0;
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Meaning of the two DWORD values and two pointers per channel is not established; the referenced globals are opaque configuration data.
    // UNRESOLVED: The parameter contract with callers SceneGraphQuery and GlobalVTableDispatchWithQuery is not resolved.
}
