// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FC7D
// Canonical corpus name: sub_50FC7D
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50FC7D_0050fc7d.c

void UnknownObject::DetectMmxSupportWithRegistryOverride()
{
    // MMX capability detection with an HKLM registry override. Opens the registry key Software\Microsoft\Direct3D via RegOpenKeyA; if open succeeds it queries the value "DisableMMX" via RegQueryValueExA, and when that value is present as REG_DWORD (type 4) with a non-zero payload it closes the key and forces the cached state dword_5D7994 to 0 (MMX disabled), returning 0. Otherwise it closes the key and, only when the cached state dword_5D7994 is negative (uninitialized), runs CPU feature detection via sub_50FC58, emits the EMMS instruction (_m_empty) when MMX is available, and stores 1 (MMX enabled) or 0 into dword_5D7994. Returns the cached enable state dword_5D7994. Called from texture/render initialization paths.
    // GUARD: Guard: open HKLM subkey "Software\Microsoft\Direct3D" (SubKey) via RegOpenKeyA; proceed only when the call succeeds. [global:0x0059E044, global:0x005ADE4C, source:raw]
    // ASSIGNMENT: Preset cbData = 4, the size of a REG_DWORD value, before querying. [source:raw]
    // CALL: Call RegQueryValueExA(phkResult, ValueName "DisableMMX", 0, &Type, Data, &cbData) to read the override value. [global:0x0059E004, global:0x005ADE68, source:raw]
    // GUARD: Guard: when the query succeeds AND Type == 4 (REG_DWORD) AND the Data DWORD is non-zero, treat MMX as forcibly disabled. [source:raw]
    // CALL: Close the registry key via RegCloseKey(phkResult) on the forced-disable path. [global:0x0059E008, source:raw]
    // ASSIGNMENT: Store dword_5D7994 = 0 to cache the forced MMX-disabled state. [global:0x005D7994, source:raw]
    // RETURN: Return 0 (MMX disabled) immediately after the registry-forced disable. [source:raw]
    // CALL: On the non-forced path close the opened registry key via RegCloseKey(phkResult). [global:0x0059E008, source:raw]
    // GUARD: Guard: run CPU detection only when the cached state dword_5D7994 is negative (uninitialized). [global:0x005D7994, source:raw]
    // ASSIGNMENT: Seed dword_5D7994 = 0 before detection so the state is no longer uninitialized. [global:0x005D7994, source:raw]
    // CALL: Call sub_50FC58() to run CPU MMX feature detection. [callee:0x0050FC58, source:raw]
    // CALL: When detection reports MMX available, emit the EMMS instruction via the _m_empty() intrinsic. [source:raw]
    // ASSIGNMENT: Store dword_5D7994 = 1 to cache the MMX-enabled state after successful detection. [global:0x005D7994, source:raw]
    // RETURN: Return the cached state dword_5D7994 (0 disabled, 1 enabled). [global:0x005D7994, source:raw]
    // CALL: Called from texture/render initialization paths: ImageTextureDecompressor, FunctionPointerSwitch, and RenderFeatureDispatch. [caller:0x00501722, caller:0x00503888, caller:0x005038C0, source:raw]

    // Conservative worker pseudocode:
    //   int DetectMmxSupportWithRegistryOverride() {
    //     if (RegOpenKeyA(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Direct3D", &phkResult) == 0) {
    //       cbData = 4;
    //       if (RegQueryValueExA(phkResult, "DisableMMX", 0, &Type, Data, &cbData) == 0 && Type == 4 && *(DWORD*)Data != 0) {
    //         RegCloseKey(phkResult);
    //         dword_5D7994 = 0;
    //         return 0;
    //       }
    //       RegCloseKey(phkResult);
    //     }
    //     if (dword_5D7994 < 0) {
    //       dword_5D7994 = 0;
    //       if (sub_50FC58()) {
    //         _m_empty();
    //         dword_5D7994 = 1;
    //       }
    //     }
    //     return dword_5D7994;
    //   }
    // UNRESOLVED: _m_empty() is an MSVC intrinsic (EMMS instruction) with no discrete callee address, so it cannot carry a callee evidence ref.
    // UNRESOLVED: The exact CPU feature check performed by sub_50FC58 is not visible in this function.
    // UNRESOLVED: The owning rendering object that caches the MMX state in dword_5D7994 is unknown.
}
