# PlatformAbstraction

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

A single CPU capability probe, CPUID3DNowDetection (0x0050FD16), queries the maximum extended CPUID leaf with EAX = 0x80000000, and when extended leaf 0x80000001 is available issues CPUID with that leaf and reports whether bit 31 of EDX (the 3DNow! support flag) is set. It returns 0 when the extended leaf is unsupported. It is invoked by OSVersionDetection (0x0050FDF3) during OS/CPU capability detection. The packet resolves only this one probe; the surrounding detection framework and any consumption of the reported flag are not in scope.

## Function roles

- `0x0050FD16` **CpuCapabilityProbe** — CPU 3DNow! capability probe: queries CPUID extended leaves 0x80000000/0x80000001 and returns the EDX bit 31 3DNow! support flag as a BOOL, or 0 when the extended leaf is unavailable.

## Proposed classes

### CpuCapabilityProbe

Query CPU instruction-set capability flags via CPUID and report them for platform feature selection. DERIVED grouping; the packet records the owner type as UnknownObject, so this class name is a reconstruction, not an original symbol.

Methods: `0x0050FD16`


## Compatibility contracts

- **Cpu3DNowCapabilityReport** — During OS/CPU capability detection a replacement executable must determine whether the CPU supports 3DNow! (CPUID extended leaf 0x80000001, EDX bit 31) and expose that result so higher-level feature selection can consume it. The probe must return 0 when extended CPUID is unsupported.

## Unresolved

- Only the 3DNow! bit (EDX bit 31) is tested; other extended feature flags are not consumed here.
- The ABI lead FAIL_50fd16 has no named prototype; the BOOL return type comes from the raw source.
- The packet owner type is UnknownObject; class name CpuCapabilityProbe and the OsVersionDetection dependency target are DERIVED groupings, not original symbols.
- How the reported 3DNow! flag is consumed downstream is outside this packet; no consumer function is evidenced.
