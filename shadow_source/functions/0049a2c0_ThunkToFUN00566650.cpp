// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A2C0
// Canonical corpus name: ThunkToFUN00566650
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN00566650_0049a2c0.c

void UnknownObject::ThunkToFUN00566650()
{
    // __thiscall forwarding thunk to StringCopyWithBufferRealloc (FUN 00566650). Passes both arguments through unchanged (the this pointer as the destination and a2 as the source string) and returns the callee's result directly. Invoked by ResourceLookupOrCreate (0049A3B0), so it is a string-copy helper used while resolving/creating resources.
    // CALL: StringCopyWithBufferRealloc(this, a2): forwards both arguments unchanged to the thunked target FUN 00566650 [source:raw]
    // RETURN: returns the result of StringCopyWithBufferRealloc directly [function:0x0049A2C0, source:raw]
    // CALL: Invoked by ResourceLookupOrCreate (0049A3B0) [caller:0x0049A3B0]

    // Conservative worker pseudocode:
    //   return StringCopyWithBufferRealloc(this, a2);
    // UNRESOLVED: The object type behind the this pointer and the exact destination buffer StringCopyWithBufferRealloc writes into are unknown; the thunk itself provides no field evidence
    // UNRESOLVED: Why this thunk exists alongside the direct StringCopyWithBufferRealloc call used elsewhere is unknown
}
