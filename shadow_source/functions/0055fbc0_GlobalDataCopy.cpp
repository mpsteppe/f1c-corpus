// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055FBC0
// Canonical corpus name: GlobalDataCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalDataCopy_0055fbc0.c

void UnknownObject::GlobalDataCopy()
{
    // Copies a fixed 0xA0 (160) byte block from the global dword_8B8F04 (0x008B8F04) into the caller-supplied destination a1 (qmemcpy). Returns void.
    // CALL: qmemcpy a1 from global dword_8B8F04: copy 0xA0 (160) bytes from the global data block to the destination pointer. [global:0x008B8F04, source:raw]
    // CALL: Called by sub_556260 (0x00556260). [caller:0x00556260]

    // Conservative worker pseudocode:
    //   void GlobalDataCopy(void *a1) {
    //     qmemcpy(a1, (const void *)dword_8B8F04, 0xA0);  // 160 bytes
    //   }
    // UNRESOLVED: The structure and meaning of the 160-byte block at global dword_8B8F04 (0x008B8F04) are not established by this packet.
    // UNRESOLVED: The destination type of a1 and how the caller consumes the copied block are unknown.
}
