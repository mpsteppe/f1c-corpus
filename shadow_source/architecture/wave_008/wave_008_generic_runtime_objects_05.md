# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

This packet is a grab-bag of generic runtime objects rather than a coherent subsystem. Of the 39 functions, 14 are empty no-op stubs (nullsub_*) with no behavior and no recorded callers, 5 are sentinel/constant stubs (return -1, 0, 1024, 16-bit -1), and 4 are forwarding thunks or trampolines whose targets are named only in raw source text. The only evidence-backed structure is three small clusters sharing callers: (1) a file-data processing path where FileDataProcessor (0x00567FB0) invokes two forwarding thunks (0x00567AF0, 0x00567B00) and a character-class predicate (0x005678F0) is used by the forwarded target sub_567B10; (2) a complementary bit-mask translation pair (0x005950A3, 0x00595135) both invoked by BitFieldMaskMerge (0x00595058); and (3) CRT floating-point formatting helpers (0x0059086E, 0x00590703, 0x0059567D) invoked by CRT float-display and locale-aware formatting callers. These three clusters are proposed as GUESS classes; all other functions are left with UnknownObject ownership and their contracts recorded as concrete observable constants.

## Function roles

- `0x00566B14` **UnknownObject** — Empty no-op stub (nullsub_118); no behavior, no callers.
- `0x005678F0` **FileDataProcessingHelpers** — Character-class predicate: returns TRUE when argument <= 0x20 (whitespace/terminator class); used by caller 0x00567B10 on the file-data processing path.
- `0x005679B7` **UnknownObject** — Empty no-op stub (nullsub_9) accepting one unused integer argument.
- `0x00567AF0` **FileDataProcessingHelpers** — Forwarding thunk to sub_567B10 (target named only in raw text); invoked by FileDataProcessor (0x00567FB0).
- `0x00567B00` **FileDataProcessingHelpers** — Forwarding thunk to sub_567AF0 (target named only in raw text); invoked by FileDataProcessor (0x00567FB0).
- `0x00567BA2` **UnknownObject** — Trampoline stub: unconditional call through a cast-to-function-pointer to locret_587C99; decompiler reports unreliable stack balance, likely an aliasing entry point.
- `0x00568314` **UnknownObject** — Empty stub (nullsub_119); no behavior, no recorded callers.
- `0x0056A23A` **UnknownObject** — Compiler-artifact call thunk: builds a far pointer from the saved return address and calls through it; static target unresolvable.
- `0x0056F0F3` **UnknownObject** — Empty no-op stub (nullsub_120); placeholder for a callable slot.
- `0x0056F80B` **UnknownObject** — Predicate: returns TRUE when its argument equals 40; LEGACY ABI name Node_Count_Check.
- `0x00575875` **UnknownObject** — Predicate: returns TRUE when its argument equals 34; consistent with enumeration-value validation.
- `0x0057A0E6` **UnknownObject** — Corrupted partial decompilation; stack model unreliable and the byte accumulation into a bogus huge offset is an artifact. Not usable as behavioral evidence.
- `0x0057A229` **UnknownObject** — Helper writing a common byte value into two adjacent byte fields at object offsets 0x2B and 0x2C; base object unknown.
- `0x0057A908` **UnknownObject** — Thiscall trampoline forwarding this unchanged to the single-argument delegation wrapper SingleFunctionCallWrapper_a910.
- `0x0057EC03` **UnknownObject** — Empty no-op stub (nullsub_122) accepting two unused arguments.
- `0x005853A8` **UnknownObject** — Empty no-op stub (nullsub_123) accepting two unused arguments.
- `0x00585543` **UnknownObject** — Empty stub (nullsub_124) accepting one unused integer argument.
- `0x00587890` **UnknownObject** — Constant getter returning 1024; sole caller is the unanalyzed SingleFunctionCallWrapper_a750 (0x0057A750).
- `0x0058792A` **UnknownObject** — Constant getter returning 1024; no recorded callers.
- `0x0058A2EE` **UnknownObject** — Empty stub (nullsub_125); no behavior, no recorded callers.
- `0x0058A7E8` **UnknownObject** — Empty stub (nullsub_126) with no instructions; placeholder for an unimplemented or compiled-out routine.
- `0x0058DC29` **UnknownObject** — Single-write setter raising the byte flag at (base - 144) to 1; base object unknown.
- `0x0058DD75` **UnknownObject** — Tail-transfer stub: unconditional jump out to 0x58DD9D; actual error-handling logic is outside this packet.
- `0x00590703` **CRTFloatFormatting** — Frame-local flag helper: clears bit 0 of the byte at frame offset a1 - 712, delegates to sub_59070A; sits on the CRT float-display path.
- `0x0059086E` **CRTFloatFormatting** — CRT double loader/validator (CRT___fload, LEGACY): returns the input double unchanged unless its exponent field is all-ones (NaN/Inf pattern), then recomposes the double; on the CRT float-display path.
- `0x005910A0` **UnknownObject** — Empty function (nullsub_127); no behavior.
- `0x005950A3` **BitMaskTranslation** — Bit-mask translation: maps input bits {0,2,3,4,5} to output values {16,8,4,2,1} (input bit 1 ignored); invoked by BitFieldMaskMerge (0x00595058).
- `0x00595135` **BitMaskTranslation** — Bit-mask translation: maps input bits {4,3,2,1,0,19} to output values {1,4,8,16,32,2}; near-inverse of bitMaskRemapA over the shared low bits; invoked by BitFieldMaskMerge (0x00595058).
- `0x0059567D` **CRTFloatFormatting** — Double-to-80-bit extended precision conversion: significand assembly, exponent rebasing, and left-shift normalization; called by LocaleAwareStringFormat (0x00595621).
- `0x00598CCF` **UnknownObject** — Sentinel stub returning -1 unconditionally (failure sentinel); argument ignored.
- `0x00598CD5` **UnknownObject** — Sentinel stub returning 0 unconditionally (success sentinel).
- `0x00598CD8` **UnknownObject** — Sentinel stub returning -1 unconditionally; identical body to 0x00598CCF.
- `0x00598E2B` **UnknownObject** — Empty no-op stub (nullsub_128) accepting one unused argument.
- `0x00599D25` **UnknownObject** — Sentinel stub returning 16-bit -1; argument ignored.
- `0x00599D2C` **UnknownObject** — Sentinel stub returning 16-bit -1; identical body to adjacent sub_599D25.
- `0x00599E61` **UnknownObject** — Thiscall identity/accessor returning the this pointer unchanged; arguments unused.
- `0x0059AAA2` **UnknownObject** — Empty no-op stub (nullsub_129); LEGACY ABI label Empty_Stub_59aaa2.
- `0x008D8A7C` **UnknownObject** — Empty no-op stub (nullsub_132); no behavior.
- `0x008D8C2C` **UnknownObject** — Empty stub (nullsub_133); no behavior, no recorded callers.

## Proposed classes

### FileDataProcessingHelpers

Forwarding thunks and a character-class predicate on the file-data processing path. FileDataProcessor (0x00567FB0) invokes the two thunks directly (0x00567AF0 forwards to sub_567B10, 0x00567B00 forwards to sub_567AF0); the predicate 0x005678F0 is used by caller sub_567B10, the forwarded target. Grouping is by shared caller evidence, not proven ownership.

Methods: `0x005678F0`, `0x00567AF0`, `0x00567B00`


### BitMaskTranslation

Complementary pair of bit-mask layout translation helpers invoked by BitFieldMaskMerge (0x00595058). They remap individual bit positions between two mask layouts and are a near-inverse over the shared low bits (bit 1 is ignored by one direction).

Methods: `0x005950A3`, `0x00595135`


### CRTFloatFormatting

Helpers on CRT floating-point formatting paths: double load/validation (CRTFloatLoad, 0x0059086E), frame-flag clearing before delegation (0x00590703), and double-to-extended-precision conversion (0x0059567D) used by a locale-aware string formatter. The first two share the CRT float-display callers; the third sits on a separate formatting caller path and is grouped here only as a GUESS.

Methods: `0x00590703`, `0x0059086E`, `0x0059567D`


## Compatibility contracts

- **MaskTranslationContract** — The two bit-mask translation helpers must preserve the observed bit mappings: bitMaskRemapA maps input bits 0,2,3,4,5 to output values 16,8,4,2,1 (input bit 1 ignored); bitMaskRemapB maps input bits 4,3,2,1,0,19 to output values 1,4,8,16,32,2. The pair is a near-inverse over the shared low bits.
- **ConstantGetters1024** — Two callables return the fixed integer 1024 with no arguments and no side effects. A replacement must preserve this constant for consumers such as the wrapper at 0x0057A750.
- **StatusSentinelStubs** — Stubs return fixed status sentinels: GetFailureCode variants return -1 (0x00598CCF, 0x00598CD8), GetSuccessCode returns 0 (0x00598CD5), and sub_599D25/sub_599D2C return 16-bit -1. A replacement preserving these callable slots must keep the sentinel values.
- **CharacterClassPredicate** — A predicate returns TRUE exactly when its unsigned byte argument is <= 0x20 (control/whitespace class); used by caller 0x00567B10 on the file-data processing path.
- **NoOpCallbackSlots** — Multiple callable slots exist as empty no-ops that return with no side effects. A replacement must preserve these callable slots as side-effect-free: 0x00566B14, 0x005679B7, 0x00568314, 0x0056F0F3, 0x0057EC03, 0x005853A8, 0x00585543, 0x0058A2EE, 0x0058A7E8, 0x005910A0, 0x00598E2B, 0x0059AAA2, 0x008D8A7C, 0x008D8C2C.

## Unresolved

- Owner and purpose of the vast majority of these functions are unknown; the packet provides no caller, callee, field, or subsystem evidence for most of them.
- The three proposed classes are GUESS groupings by shared caller evidence, not proven ownership. Equal callers do not prove a common class.
- The forwarding chain FileDataProcessor (0x00567FB0) -> 0x00567B00 -> sub_567AF0 -> sub_567B10 -> CharacterClassCheck (0x005678F0) is textual: sub_567AF0 and sub_567B10 are named only in raw source and have no address evidence in the packet.
- Trampoline targets locret_587C99 (0x00567BA2) and SingleFunctionCallWrapper_a910 (0x0057A908) are named only in raw text; the actual delegated functions are unconfirmed.
- FPUStatusErrorHandler (0x0058DD75) jumps out to 0x58DD9D whose code is outside this packet; whether it is a jump-table case, tail call, or shared block is unknown.
- ClearFrameFlagAndDelegate (0x00590703) calls sub_59070A, which is absent from the packet callee evidence; its identity, arguments, and return contract are unresolved.
- DualAdjacentByteWrite (0x0057A229) writes sibling byte fields at object offsets 0x2B and 0x2C, but the base object is unknown; the fields are therefore not assigned to any class.
- SetByteFlag (0x0058DC29) writes byte 1 at (base - 144), a negative offset relative to an unknown base object; the offset cannot be represented as a positive field offset and the owner struct is unknown.
- PARTIALCorruptedDecompilation (0x0057A0E6) has an unreliable stack model ('positive sp value'); the byte accumulation at a2 + 1583287492 is treated as a decompilation artifact, not a real field.
- callThroughReturnAddress (0x0056A23A) is likely a compiler artifact or custom call thunk; the far-pointer target constructed from the saved return address cannot be resolved statically.
- Two identical GetFailureCode stubs (0x00598CCF, 0x00598CD8) and the adjacent sentinel pair sub_599D25/sub_599D2C: whether they are independent stubs or aliases to one intent is not established.
- The semantic meaning of the constant 1024 (buffer size, allocation quantum, count) returned by 0x00587890 and 0x0058792A is unknown.
- NodeCountCheck (0x0056F80B) validates its argument against 40, and EnumValueCheck (0x00575875) against 34, but the node collection and the enumeration are unidentified.
- convertDoubleToExtended80 (0x0059567D): the legacy ABI labels imply an 80-bit to 64-bit direction, but the raw code reads a 64-bit double and writes a 10-byte extended value; the direction discrepancy is unresolved.
- CRTFloatLoad (0x0059086E): the all-ones exponent special path (NaN/Inf re-normalization) purpose is unconfirmed and the CRT___fload ABI lead is LEGACY trust only.
- CharacterClassCheck (0x005678F0): whether the class is whitespace, control, or terminator is inferred from the 0x20 bound only; the exact class is unconfirmed.
- The __userpurge/EBX and __fastcall argument conventions used by some functions are assumed from decompiler prototypes; register placement is not verified.
