// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FBFC
// Canonical corpus name: sub_50FBFC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50FBFC_0050fbfc.c

void UnknownObject::QueryDirect3DRegistryValue()
{
    // Queries a named registry value under HKLM\Software\Microsoft\Direct3D. Opens the Direct3D subkey, reads the value lpValueName into lpData, closes the key, and returns TRUE only when the open and query both succeed (ERROR_SUCCESS) and the stored registry type Type equals the expected type parameter a1; otherwise returns FALSE.
    // ASSIGNMENT: Initialize phkResult = 0 and result = 0. [function:0x0050FBFC, source:raw]
    // GUARD: Call RegOpenKeyA(HKEY_LOCAL_MACHINE, SubKey, &phkResult); only if it returns ERROR_SUCCESS (0) continue into the query path, otherwise skip to the final return of result (FALSE). [global:0x0059E044, global:0x005ADE4C, function:0x0050FBFC, source:raw]
    // CALL: RegQueryValueExA(phkResult, lpValueName, 0, &Type, lpData, &cbData); store the LSTATUS result in v4. [global:0x0059E004, function:0x0050FBFC, source:raw]
    // CALL: RegCloseKey(phkResult) after the value query completes. [global:0x0059E008, function:0x0050FBFC, source:raw]
    // GUARD: If v4 == ERROR_SUCCESS (0) and Type == a1, return 1 (TRUE). [function:0x0050FBFC, source:raw]
    // RETURN: Return result, which is 0 (FALSE) unless the success and type-match guard passed. [function:0x0050FBFC, source:raw]

    // Conservative worker pseudocode:
    //   phkResult = 0;
    //   result = 0;
    //   if (RegOpenKeyA(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Direct3D", &phkResult) == 0) {
    //     v4 = RegQueryValueExA(phkResult, lpValueName, 0, &Type, lpData, &cbData);
    //     RegCloseKey(phkResult);
    //     if (v4 == 0 && Type == a1)
    //       return 1;
    //   }
    //   return result;
    // UNRESOLVED: The caller sub_50FEA7 (0x0050FEA7) uses this query, but the owning object and the set of registry values the caller reads are not established by this packet.
    // UNRESOLVED: Parameter a1 is the expected registry type only; the intended type constant and the meaning of the queried value are caller-side and unresolved here.
}
