// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E960
// Canonical corpus name: AudioStateInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioStateInit_0044e960.c

void UnknownObject::AudioStateInit()
{
    // Unconditional audio-state initializer: writes tag 92 into dword_7CCA14, zeroes the four following fields (dword_7CCA18 through dword_7CCA24), sets dword_7CCA28 = 18000, and returns 0. No branches, calls, or struct fields. The canonical/abi name assigns it to audio state (LEGACY); the semantic role of each global is not established from this packet.
    // ASSIGNMENT: dword_7CCA14 = 92 (block tag). [global:0x007CCA14, source:raw]
    // ASSIGNMENT: dword_7CCA18 = 0. [global:0x007CCA18, source:raw]
    // ASSIGNMENT: dword_7CCA1C = 0. [global:0x007CCA1C, source:raw]
    // ASSIGNMENT: dword_7CCA20 = 0. [global:0x007CCA20, source:raw]
    // ASSIGNMENT: dword_7CCA24 = 0. [global:0x007CCA24, source:raw]
    // ASSIGNMENT: dword_7CCA28 = 18000. [global:0x007CCA28, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int AudioStateInit() {
    //     dword_7CCA14 = 92;
    //     dword_7CCA18 = 0; dword_7CCA1C = 0; dword_7CCA20 = 0; dword_7CCA24 = 0;
    //     dword_7CCA28 = 18000;
    //     return 0;
    //   }
    // UNRESOLVED: The semantic role of each 0x7CCA14-region global is not recoverable from this packet; existing analysis labels dword_7CCA14 AudioStatePtr, dword_7CCA24 CollisionMiscFloat and dword_7CCA28 UIElementState (all DERIVED).
    // UNRESOLVED: No static callers are recorded and the function is not on the frame path, so where this state init runs is unverified.
}
