// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C5920
// Canonical corpus name: TrackNameReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackNameReader_004c5920.c

void UnknownObject::TrackNameReader()
{
    // stdcall wrapper that copies the global track-name buffer (aTrackname) into a caller-provided destination via StringCopyWithValidation, passing the read-only global as the source and a zero constant as the final argument. Returns the copy helper's result unchanged. Called from server session, game-filter and two unnamed setup paths.
    // CALL: Invoke StringCopyWithValidation(a1, a2, (int)aTrackname, 0), copying from the read-only global track-name buffer aTrackname (at 0x005C6984) into the caller destination a1 using source a2. [callee:0x004C58A0, global:0x005C6984, source:raw]
    // RETURN: Return the StringCopyWithValidation result unchanged. [source:raw]
    // CALL: Invoked by session/server setup paths (ServerOpenTrackSignal, ServerOpenedClosedNotification, GameFilterSetup) and two unnamed callers to read or refresh the track name during track open and notification handling. [caller:0x00460E90, caller:0x00461190, caller:0x00477830, caller:0x004BA460, caller:0x004F9480]

    // Conservative worker pseudocode:
    //   int sub_4C5920(char *dst, const char *src) {
    //     return StringCopyWithValidation(dst, src, (int)gTrackName, 0);
    //   }
    // UNRESOLVED: Meaning of the final StringCopyWithValidation argument (0) is unknown; likely a length cap or formatting flag.
    // UNRESOLVED: The owner of the global track-name buffer is unknown.
}
