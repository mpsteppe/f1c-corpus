// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564650
// Canonical corpus name: SleepWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SleepWrapper_00564650.c

void UnknownObject::SleepWrapper()
{
    // Thin wrapper that forwards its dwMilliseconds argument to the imported Sleep function. No state of its own; exists to decouple the polling loop from the sleep API.
    // CALL: Invoke Sleep(dwMilliseconds), forwarding the caller-supplied millisecond count to the imported Sleep function at 0x0059E0DC. [global:0x0059E0DC, source:raw]
    // RETURN: Function is void; control returns to the caller immediately after the Sleep call returns. [source:raw]
    // UNRESOLVED: The __thiscall convention implies an unused this pointer; no member field is touched, so the object role is unknown.
}
