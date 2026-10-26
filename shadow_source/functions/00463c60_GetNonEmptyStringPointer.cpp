// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463C60
// Canonical corpus name: sub_463C60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_463C60_00463c60.c

void UnknownObject::GetNonEmptyStringPointer()
{
    // Getter with a string guard: loads the object pointer from this+0, forms the string pointer at object+364, and returns it only when strlen reports a non-empty string; otherwise returns null (0).
    // ASSIGNMENT: Load the object pointer from this+0. [field:this:0x00000000, source:raw]
    // CALCULATION: Compute the candidate string pointer as the object pointer plus 364. [source:raw]
    // CALL: strlen is applied to the candidate string pointer to test whether it addresses a non-empty string. [source:raw]
    // GUARD: If strlen is non-zero the function returns the string pointer; otherwise it returns null. [source:raw]
    // RETURN: Returns the object+364 string pointer when it names a non-empty string, else null (0). [source:raw]

    // Conservative worker pseudocode:
    //   obj = *(_DWORD *)this;
    //   return strlen((const char *)(obj + 364)) != 0 ? obj + 364 : 0;
    // UNRESOLVED: The object type, the purpose of the string stored at object+364, and why a non-empty string pointer is guarded while an empty one yields null are unresolved. Caller sub_463BC0 context has not been analyzed.
}
