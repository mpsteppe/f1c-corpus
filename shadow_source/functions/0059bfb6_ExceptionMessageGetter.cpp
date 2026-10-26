// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BFB6
// Canonical corpus name: ExceptionMessageGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ExceptionMessageGetter_0059bfb6.c

void UnknownObject::ExceptionMessageGetter()
{
    // Exception 'what()'-style getter (__thiscall): returns the string pointer stored at this+0x4 when non-null, otherwise returns the global 'Unknown exception' fallback string (0x005B9DC8).
    // GUARD: Read this+0x4 (const char*). If it is null, return the global 'Unknown exception' string at 0x005B9DC8. [field:this:0x00000004, global:0x005B9DC8]
    // RETURN: When this+0x4 is non-null, return it as the exception message string pointer. [field:this:0x00000004]

    // Conservative worker pseudocode:
    //   const char *ExceptionMessageGetter(_DWORD *this)
    //   {
    //     const char *result = (const char *)this[1];
    //     if (!result)
    //       return "Unknown exception";
    //     return result;
    //   }
    // UNRESOLVED: Owning class of 'this' is unidentified; field at +0x4 is read-only here.
    // UNRESOLVED: Whether the global string at 0x005B9DC8 is an owned static or a shared literal is not evidenced.
}
