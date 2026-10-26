// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00546230
// Canonical corpus name: sub_546230
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_546230_00546230.c

void UnknownObject::StoreGlobalCallbackPair()
{
    // Configuration entry-point that persists a callback function pointer (a1) and an associated integer argument (a2) into two adjacent globals, dword_8B8F00 and dword_8B8EFC, and returns the original callback pointer. Called from VidMan_Init (0x004FA320), so it registers a video-management callback pair.
    // ASSIGNMENT: Seed result with a1 so the function returns the stored callback pointer unchanged. [source:raw]
    // ASSIGNMENT: Store the callback pointer a1 into global dword_8B8F00. [source:raw, global:0x008B8F00]
    // ASSIGNMENT: Store the associated integer argument a2 into global dword_8B8EFC. [source:raw, global:0x008B8EFC]
    // RETURN: Return the original callback pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   void* sub_546230(void* (*cb)(void*, void*), int arg) {
    //     dword_8B8F00 = cb;
    //     dword_8B8EFC = arg;
    //     return cb;
    //   }
    // UNRESOLVED: Semantic purpose of globals dword_8B8F00 / dword_8B8EFC and the callback they pair is caller- (VidMan_Init) defined; unknown here.
    // UNRESOLVED: Meaning of the integer argument a2 stored alongside the callback pointer.
}
