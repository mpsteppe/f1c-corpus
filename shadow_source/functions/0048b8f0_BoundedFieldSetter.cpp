// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048B8F0
// Canonical corpus name: BoundedFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundedFieldSetter_0048b8f0.c

void UnknownObject::BoundedFieldSetter()
{
    // Bounded setter: writes unsigned a2 into the dword field at this+0x2F8 (this[190]) only when a2 < 0x100 (clamped to max 0xFF). Otherwise leaves the field unchanged. Always returns 0. Callers are UI/text related (UITextFieldInitialization, ConstructorWithStringCopy), and prior analysis proposes this+0x2F8 is a buffer-size/max-edit-length limit, but the owner class and exact field meaning are not confirmed.
    // GUARD: Guard: write happens only when a2 < 0x100; values >= 0x100 are blocked and the field is left unchanged. [source:raw, function:0x0048B8F0]
    // ASSIGNMENT: Store a2 into the dword at this+0x2F8 (this[190]) when the guard passes. [source:raw, function:0x0048B8F0, field:this:0x000002F8]
    // RETURN: Return 0 regardless of whether the write occurred. [source:raw, function:0x0048B8F0]

    // Conservative worker pseudocode:
    //   int __thiscall BoundedFieldSetter(_DWORD* this, unsigned int a2) {
    //     if (a2 < 0x100)
    //       this[190] = a2;
    //     return 0;
    //   }
    // UNRESOLVED: The owning class is unknown (UnknownObject); the dword at this+0x2F8 is untyped.
    // UNRESOLVED: Existing prose proposes this+0x2F8 is a buffer-size/max-edit-length limit for text fields; not confirmed by this function alone.
    // UNRESOLVED: The caller EngineTemperatureDebugDisplay does not fit the text-field reading, so the field may be reused for different purposes across owner contexts.
}
