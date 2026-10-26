// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495110
// Canonical corpus name: GlobalGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalGetter_00495110.c

void UnknownObject::GlobalGetter()
{
    // Trivial global read: returns the value of dword_8B8DC8 (0x008B8DC8). No arguments and no side effects. Its only recorded caller is UIScrollViewRender (0x00486AC0), suggesting the global is consumed by UI scroll-view rendering.
    // ASSIGNMENT: Read the current value of global dword_8B8DC8 (0x008B8DC8). [global:0x008B8DC8, source:raw]
    // RETURN: Return the read global value as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   int GlobalGetter() {
    //     return dword_8B8DC8;
    //   }
    // UNRESOLVED: Meaning and type of dword_8B8DC8 are unknown; it is only observed to be read (R) by this getter and consumed by UIScrollViewRender.
    // UNRESOLVED: Who writes dword_8B8DC8 is not in this packet.
}
