// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561940
// Canonical corpus name: FieldCleanupWithNullCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldCleanupWithNullCheck_00561940.c

void UnknownObject::FreeFieldIfSet()
{
    // Field cleanup helper: reads the pointer at this+0x1EC (this[123]); if non-null, passes it to FreeWrapper_7bcf, stores the wrapper's return value as the result, and clears the field to 0. Returns the loaded pointer when the field was null (no free performed), otherwise the FreeWrapper_7bcf return value. Called from SceneGraph (0x0054A770) during cleanup.
    // ASSIGNMENT: Load result = the pointer stored at this+0x1EC (this[123]). [field:this:0x000001EC, source:raw]
    // GUARD: Guard: if the loaded pointer is non-null, free and clear; otherwise skip and return the null value. [source:raw]
    // CALL: Call FreeWrapper_7bcf(this[123]) to free the resource pointer at this+0x1EC. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Store the FreeWrapper_7bcf return value as result. [source:raw]
    // ASSIGNMENT: Clear the field to 0 after freeing: this[123] = 0. [field:this:0x000001EC, source:raw]
    // RETURN: Return result (the FreeWrapper_7bcf return value, or the original null field value when no free occurred). [source:raw]

    // Conservative worker pseudocode:
    //   LPVOID sub_561940(LPVOID *this) {
    //     LPVOID result = this[123];
    //     if (result) {
    //       result = FreeWrapper_7bcf(this[123]);
    //       this[123] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the FreeWrapper_7bcf return value is unknown; the function passes it through to its own caller.
}
