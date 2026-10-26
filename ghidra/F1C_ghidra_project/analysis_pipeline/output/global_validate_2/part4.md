# Global Validate Part 4 — Globals 211–285

| DAT_XXXXXXXX | ProposedName | system | type | access | N | purpose |
|---|---|---|---|---|---|---|
| 0x008b5998 | IDCTOutputBuffer | renderer/texture | float | write | 1 | DCT decompression output buffer, written by FUN_00531b50 |
| 0x005b7750 | DCTCoeff9 | audio/compression | float | read | 1 | DCT coefficient for element index 9, used in 16-element DCT filter bank |
| 0x005b776c | DCTCrossCoeff0 | audio/compression | float | read | 1 | DCT cross-term coefficient ((a+b)-(c+d)) scaling factor |
| 0x008b59c0 | IDCTWorkspace | renderer/texture | float | write | 1 | IDCT intermediate workspace buffer, written by FUN_00531b50 |
| 0x005b779c | DCTCoeff15 | audio/compression | float | read | 1 | DCT coefficient for last element index 15/16 in filter bank |
| 0x005da82c | RendererFuncPtrTable | renderer | code** | read | 1 | Pointer table used by renderer init, read by FUN_00535e80 |
| 0x005dbac4 | StrOversubscribed | network | char* | read | 1 | "oversubscribed" string for network connection error message |
| 0x008b8dcc | RendererStateFlag | renderer/state | int | write | 1 | Renderer state initialization flag, zeroed in FUN_0053c360 as part of state block reset |
| 0x005dbec8 | StrNoReflectionMap | renderer | char* | read | 1 | "No reflection map" error string for texture/shader system |
| 0x005dc070 | StrErrorSetting | renderer | char* | read | 1 | "Error while setting..." renderer error format string |
| 0x005dc21c | StrBgmap | renderer | char* | read | 1 | "bgmap" config/command string for background map rendering |
| 0x005dc314 | StrMorphtarget | renderer | char* | read | 1 | "morphtarget" config/command string for vertex morph target |
| 0x005dc3d8 | StrExp | renderer/shader | char* | read | 1 | "exp" shader parameter string for exposure/exponent uniform |
| 0x005dc5a0 | MixerDword3 | audio/mixer | int | read | 1 | Miles Sound System mixer configuration constant (dword param) |
| 0x005dc558 | MixerWordFlag | audio/mixer | short | read | 1 | Miles Sound System mixer flag/mask (16-bit word param) |
| 0x005dc4ec | MixerDword2 | audio/mixer | int | read | 1 | Miles Sound System mixer configuration constant (dword param) |
| 0x005dc4a0 | MixerDword1 | audio/mixer | int | read | 1 | Miles Sound System mixer configuration constant (dword param, base) |
| 0x005e4e80 | StrBroadcastAddr | network | char* | read | 1 | "255.255.255.255" broadcast address string for UDP/networking |
| 0x008cf288 | NetworkPacketBuf | network | byte[] | read | 1 | Byte array buffer for network packet data manipulation |
| 0x005e514c | StrNewlines4 | debug/log | char* | read | 1 | "\n\n\n\n" padding string used in debug logging output |
| 0x005e5204 | StrCom4 | serial/input | char* | read | 1 | "COM4" serial port name string for wheel/controller input |
| 0x005e5358 | StrBody | renderer/mesh | char* | read | 1 | "body" mesh part name string for car body render group |
| 0x008d39d8 | SolverWorkspaceIndex | dynamics/constraint solver | int | read | 1 | Index/offset into constraint solver LDL^T factorization workspace |
| 0x008d0eb0 | SolverPivotD0 | dynamics/constraint solver | double | read | 1 | LDL^T pivot value, diagonal entry read during block sparse factorization |
| 0x008cfdb0 | SolverFactorOutput1 | dynamics/constraint solver | double | write | 1 | LDL^T factorization output, computed double written to solver workspace |
| 0x008d1270 | SolverDiagEntry1 | dynamics/constraint solver | double | read | 1 | Diagonal matrix entry read during block sparse LDL^T step |
| 0x008d13a8 | SolverDiagEntry2 | dynamics/constraint solver | double | read | 1 | Diagonal matrix entry read during block sparse LDL^T step |
| 0x008d0ee8 | SolverPivotD1 | dynamics/constraint solver | double | read | 1 | LDL^T pivot value, diagonal entry in 8D0E... range |
| 0x008d12a0 | SolverDiagEntry3 | dynamics/constraint solver | double | read | 1 | Diagonal matrix entry read during block sparse LDL^T step |
| 0x008d08f8 | SolverRowEntry1 | dynamics/constraint solver | double | read | 1 | Solver matrix row entry read during LDL^T factorization inner loop |
| 0x008d09c8 | SolverRowEntry2 | dynamics/constraint solver | double | read | 1 | Solver matrix row entry read during LDL^T factorization inner loop |
| 0x008d3a90 | SolverRemoteD | dynamics/constraint solver | double | read | 1 | Solver double at distant workspace offset, read during factorization |
| 0x008d39c4 | SolverBlockIndex | dynamics/constraint solver | int | read | 1 | Block/segment index into solver workspace structure |
| 0x008d1c28 | SolverSubdiagEntry1 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| 0x008d0b30 | SolverArrayBase | dynamics/constraint solver | double[] | read | 1 | Solver workspace array base, pointer to double array for LDL^T workspace |
| 0x008d0e18 | SolverWorkspaceD0 | dynamics/constraint solver | double | read | 1 | Solver workspace double read during LDL^T step |
| 0x008d1b58 | SolverSubdiagEntry2 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| 0x008d1308 | SolverDiagEntry4 | dynamics/constraint solver | double | read | 1 | Diagonal matrix entry read during block sparse LDL^T step |
| 0x008d1310 | SolverDiagEntry5 | dynamics/constraint solver | double | read | 1 | Diagonal matrix entry read during block sparse LDL^T step |
| 0x008d0190 | SolverBaseD | dynamics/constraint solver | double | read | 1 | Base workspace double, read as pivot/scaling factor in LDL^T |
| 0x008d1570 | SolverSubdiagEntry3 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| 0x008d18b8 | SolverSubdiagEntry4 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| 0x008d1c80 | SolverSubdiagEntry5 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| 0x008d20c0 | SolverSubdiagEntry6 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| 0x008d19c8 | SolverSubdiagEntry7 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| 0x008d2000 | SolverSubdiagEntry8 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| 0x008d1f38 | SolverSubdiagEntry9 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| 0x008d20f8 | SolverSubdiagEntry10 | dynamics/constraint solver | double | read | 1 | Subdiagonal matrix entry read during LDL^T factorization |
| 0x008d2040 | SolverFactorOutput2 | dynamics/constraint solver | double | write | 1 | LDL^T factorization output double written to solver workspace |
| 0x008d2328 | CholeskyFactorOut1 | dynamics/constraint solver | double | write | 1 | Double written by sub_575BBD (LDL^T Cholesky factor, 13KB) |
| 0x008d2698 | CholeskyFactorOut2 | dynamics/constraint solver | double | write | 1 | Double written by sub_575BBD (LDL^T Cholesky factor, 13KB) |
| 0x008d2a38 | CholeskyWorkspace | dynamics/constraint solver | double[] | read/write | 1 | Cholesky workspace array base, offset by sub_575BBD during factorization |
| 0x008d2eb8 | CholeskyFactorOut3 | dynamics/constraint solver | double | write | 1 | Double written by sub_575BBD during LDL^T factor step |
| 0x008d3080 | CholeskyDiagonalIn | dynamics/constraint solver | double | read | 1 | Double read by sub_575BBD for diagonal comparison/pivot test |
| 0x005ba8c4 | SEHExceptionFilter | runtime/SEH | struct | read | 1 | Exception filter structure used in __try/__except block (0x0057a760) |
| 0x005e5388 | RendererVTablePtr | renderer | void** | read | 1 | Vtable/function pointer table read by FUN_0057bf00 |
| 0x005e6060 | StrSocketLocal | network/socket | char* | read | 1 | "The socket is local" error string for socket address check |
| 0x005e58b8 | StrSocketHasBeen | network/socket | char* | read | 1 | "The socket has been..." status/error string for socket state |
| 0x005e62e0 | StrDropFlagSet | network/socket | char* | read | 1 | "drop flag set" debug/log string for packet drop detection |
| 0x005bae98 | AllocListNode | memory/allocator | struct | read | 1 | Allocation linked list node structure, traversed by FUN_00582a10 during free |
| 0x005e6360 | StrHst | network | char* | read | 1 | "hst" (host) string for network configuration lookup |
| 0x005e6c5a | MathPiOver2 | math/CRT | float10 | read | 1 | Extended-precision constant (PI/2 or similar) used in acos/atan implementation |
| 0x008d3e62 | CachedMonth | time/date | short | read | 1 | Cached SYSTEMTIME wMonth field, part of time-of-day check in FUN_005896ee |
| 0x005e65b0 | PtrExitFunc | CRT/exit | code* | read | 1 | Pointer to __exit function, called by __amsg_exit on fatal error |
| 0x005e6c22 | RoundingConstant | math/CRT | double | read | 1 | Double constant used in floating-point rounding (frndint helper) |
| 0x005e99d0 | IOFunctionPtr | CRT/io | void*** | write | 1 | Function pointer written by sub_58EF83 during CRT IO init |
| 0x008d3f70 | CodePageTablePtr | CRT/codepage | short* | read | 1 | Pointer to codepage translation table, freed during CRT teardown |
| 0x005e74e0 | MathLookupTable | math/CRT | byte[8] | read | 1 | Byte lookup table for fmod/remainder classification (indexed by exponent bits) |
| 0x008d406e | DateCompareParam3 | CRT/time | short | read | 1 | Date comparison parameter word passed to FUN_00592647 for time window check |
| 0x008d4924 | FileHandleTable | CRT/startup | void** | read/write | 1 | CRT file handle table array, dynamically allocated during startup |
| 0x005e99b8 | VtordispVTablePtr | CRT/vtable | struct | read | 1 | Vtordisp vtable pointer/offset table passed to FUN_005953b8 |
| 0x008d41f4 | AtExitFuncPtr | CRT/atexit | code* | read | 1 | atexit handler function pointer, invoked by FUN_00597388 for signal 0xF |
| 0x005b9cd8 | ObjectInitData1 | runtime/init | int | read | 1 | Object initialization constant copied to instance field at offset +8 |
| 0x005bb760 | VTableTable | runtime/vtable | struct | read | 1 | Virtual function table pointer table used by object destructor FUN_0059a86c |
| 0x005b9de0 | CxxExceptionInfo | runtime/SEH | struct | read | 1 | C++ exception raise parameters (8 DWORDs), copied by __CxxThrowException@8 |
