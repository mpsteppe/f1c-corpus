// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00414160
// Canonical corpus name: GlobalFieldSelectorByIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalFieldSelectorByIndex_00414160.c

void UnknownObject::GlobalFieldSelectorByIndex()
{
    // Selects a global value by an integer selector: selector 0 returns dword_5BF8C8, selector 1 returns dword_5BF8D0, and any other selector value returns -1. Pure read-only dispatch with no side effects.
    // RETURN: If a1 is 0, return the value of global dword_5BF8C8. [global:0x005BF8C8, source:raw]
    // RETURN: If a1 is 1, return the value of global dword_5BF8D0. [global:0x005BF8D0, source:raw]
    // RETURN: For any a1 other than 0 or 1, return the default value -1. [source:raw]

    // Conservative worker pseudocode:
    //   if (selector == 0) return dword_5BF8C8;
    //   if (selector == 1) return dword_5BF8D0;
    //   return -1;
    // UNRESOLVED: What dword_5BF8C8 and dword_5BF8D0 represent (e.g. cached font/character render state selected by the caller FontCharacterRenderDispatcher) is not established by the packet.
    // UNRESOLVED: Why non-matching selectors return -1 (sentinel/error) vs a default value is unknown.
    // UNRESOLVED: The two globals are close in address space; whether they are distinct fields or array elements of a single object is not resolvable from this function alone.
}
