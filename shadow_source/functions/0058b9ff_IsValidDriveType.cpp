// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058B9FF
// Canonical corpus name: sub_58B9FF
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58B9FF_0058b9ff.c

void UnknownObject::IsValidDriveType()
{
    // Drive-path validation. Builds a drive-root path string from the RootPathName argument (low byte of RootPathName + 64 as the letter, then ":\\" appended via strcpy), calls GetDriveTypeA on it, and returns 0 when the reported drive type is below 2. Returns 1 immediately when RootPathName is zero. Called from sub_58B92A.
    // ASSIGNMENT: Initialize result to 1 (default valid). [source:raw, function:0x0058B9FF]
    // GUARD: If RootPathName is zero, skip drive validation and return the default result. [source:raw]
    // ASSIGNMENT: Build the path buffer: first byte = low byte of RootPathName + 64 (maps the drive index to its ASCII letter, e.g. 1 -> 'A'). [source:raw]
    // CALL: strcpy appends the ":\\" suffix after the drive letter byte. [source:raw]
    // GUARD: Call GetDriveTypeA on the constructed drive-root path; if the returned drive type is < 2, return 0 (invalid drive). [global:0x0059E180, source:raw]
    // RETURN: Return result (1 when the drive type is valid, or when no root path was given). [source:raw, function:0x0058B9FF]

    // Conservative worker pseudocode:
    //   result = 1;
    //   if (RootPathName) {
    //     path[0] = (char)(RootPathName + 64);
    //     strcpy(path + 1, ":\\");
    //     if (GetDriveTypeA(path) < 2) return 0;
    //   }
    //   return result;
    // UNRESOLVED: Semantic role of the +64 letter offset is inferred from the arithmetic; the caller-side meaning of RootPathName (drive index vs letter) is not evidenced here.
    // UNRESOLVED: GetDriveTypeA is an imported API exposed as a global in the packet; its exact import thunk is not evidenced.
}
