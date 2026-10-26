# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposes a generic runtime-objects subsystem of nine classes across six clusters directly evidenced by the packet: (1) Packed96BitFloat primitives that copy, zero, shift, add and multiply a 96-bit extended float (3 mantissa DWORDs + sign/exponent WORD at +0xA), (2) ExtendedFloatFormatting orchestration that converts extended floats/doubles to IEEE-32/64 or BCD decimal strings via those primitives and lookup-table scaling, (3) StringFormatParseHelpers, (4) MemoryValidityWrappers plus an SEHExceptionFilter, (5) CrtStringCollation, (6) WinsockImportThunks, (7) StreamVtableFixup and LocaleStreamLifecycle for std::istream/ostream construction/teardown. Every packet owner is UnknownObject, so all class groupings are DERIVED/GUESS proposals; field layouts, import targets and status semantics are taken directly from packet field/global/callee references.

## Function roles

- `0x005952E9` **Packed96BitFloat** — Primitive 16-byte (4 DWORD) block copy used to save and restore extended-float mantissa words; returns source advanced 4 DWORDs.
- `0x00595304` **Packed96BitFloat** — Unconditional zero-initializer for a 12-byte (3 DWORD) working struct; always returns 0.
- `0x0059532B` **Packed96BitFloat** — In-place right shift of a 3-limb big integer by an arbitrary bit count (whole-word + bit-shift passes).
- `0x005953B8` **ExtendedFloatFormatting** — Converts an internal 80-bit extended float into a 32- or 64-bit IEEE-style output through the output pointer, returning status 0 (normal/zero), 1 (range-exceeded) or 2 (underflow/denormal).
- `0x00595550` **StringFormatParseHelpers** — Fills a 6-element u16 format buffer via sub_596245 then parses it through StringParseViaDelegate.
- `0x0059557D` **StringFormatParseHelpers** — Builds a 6-element u16 buffer via sub_596245 then delegates to DelegationWithStaticData; likely string parse with format descriptor.
- `0x00596BF3` **StringFormatParseHelpers** — Integer-to-string dispatch: signed base-10 negatives take the signed mode of UintToStringConversion; all other values take the unsigned mode.
- `0x005972BD` **SEHExceptionFilter** — SEH exception filter matching the MSVC C++ exception signature (0xE06D7363, param[0]==3, param[1]==0x19930520); on match dispatches to the C++ handler wrapper, otherwise calls the validated global handler.
- `0x00597321` **MemoryValidityWrappers** — Negated IsBadReadPtr readability predicate: TRUE when the given range is readable.
- `0x0059733D` **MemoryValidityWrappers** — Negated IsBadWritePtr writability predicate: TRUE when the given range is writable.
- `0x00597359` **MemoryValidityWrappers** — Negated IsBadCodePtr code-pointer validity predicate: TRUE when the pointer is a valid readable code address.
- `0x00597547` **Packed96BitFloat** — Unsigned overflow-checked addition: writes the wrapping sum through the output pointer and returns 1 on carry, 0 otherwise.
- `0x005975C6` **Packed96BitFloat** — Left-shifts a 96-bit value (three DWORDs) by exactly one bit with bit-31 carry propagation.
- `0x005975F4` **Packed96BitFloat** — Right-shifts an in-place 96-bit value by one bit with inter-DWORD carry propagation; returns the pointer.
- `0x00597621` **ExtendedFloatFormatting** — Parses ASCII digits into a 96-bit fixed-point accumulator (multiply-by-10, add-digit) and normalizes it, storing and returning the exponent word at a3+10.
- `0x005976E8` **ExtendedFloatFormatting** — Formats a double into a fixed-width decimal string via 96-bit packed BCD arithmetic, handling zero, NaN/Inf/Ind/SNaN, scaling and rounding.
- `0x00597AA0` **Packed96BitFloat** — Multiplies two packed 96-bit floating-point-like values, normalizes and rounds the mantissa, and returns the product exponent.
- `0x00597CC0` **ExtendedFloatFormatting** — Scales a packed 96-bit value by a table-driven factor derived from the exponent, consuming 3 bits (one octal digit) per iteration.
- `0x00597F6D` **CrtStringCollation** — Byte-count, case-insensitive CRT string collation (_mbsnbicoll pattern) mapping CompareString-style 1/2/3 status to signed -1/0/+1 with a 0x7FFFFFFF error sentinel.
- `0x00598648` **WinsockImportThunks** — Import thunk forwarding socket(af, type, protocol) to the Winsock2 IAT slot.
- `0x0059864E` **WinsockImportThunks** — Import thunk forwarding recvfrom(s, buf, len, flags, from, fromlen) to the Winsock2 IAT slot.
- `0x00598654` **WinsockImportThunks** — Import thunk forwarding select(nfds, readfds, writefds, exceptfds, timeout) to the Winsock2 IAT slot.
- `0x0059866C` **WinsockImportThunks** — Import thunk forwarding htons(hostshort) to the Winsock2 IAT slot.
- `0x0059867E` **WinsockImportThunks** — Import thunk forwarding send(s, buf, len, flags) to the Winsock2 IAT slot.
- `0x00598684` **WinsockImportThunks** — Import thunk forwarding recv(s, buf, len, flags) to the Winsock2 IAT slot.
- `0x00598690` **WinsockImportThunks** — Import thunk tail-calling WSAFDIsSet(fd, fd_set) through the IAT slot; opaque system API wrapper.
- `0x005986A2` **WinsockImportThunks** — Import thunk tail-calling WSACleanup() through the IAT slot; no game-side logic.
- `0x00598731` **StreamVtableFixup** — std::istream construction helper: installs the istream vftable (0x005B9BA4) at this + vtable[1], then chains to the shared init routine.
- `0x00598750` **LocaleStreamLifecycle** — Fixed-argument (0,1) delegation stub forwarding to LocaleStreamObjectConstructSimplified.
- `0x00598775` **StreamVtableFixup** — Restores the std::ostream vftable (0x005B9BAC) into the stream object at the vtable[1]-derived slot, then chains to the shared init routine.
- `0x005987C1` **LocaleStreamLifecycle** — Fixed-argument (0,1) delegation stub forwarding to LocaleStreamObjectConstructSimplified; consistent with a factory entry point.
- `0x005987F0` **LocaleStreamLifecycle** — Fixed-argument (0,1) delegation stub forwarding to LocaleStreamObjectConstructSimplified; locale wrapper entry point.
- `0x00598AA0` **LocaleStreamLifecycle** — Virtual status check on a vtable-derived sub-object; on failure ORs error flag 4 into the sub-object state and dispatches via sub_59A5FE.
- `0x00598E2E` **StreamVtableFixup** — Writes the vtable pointer 0x005B9BCC at this+0 and returns this; second parameter unused.
- `0x0059925D` **StreamVtableFixup** — Deleting-destructor trampoline: re-bases the pointer back 4 bytes, invokes VtableFixupWithDestructor, then conditionally frees the object.
- `0x005992B7` **LocaleStreamLifecycle** — Deleting-destructor: runs SetLocaleVTableCall cleanup then conditionally frees the object when the low flag bit is set.

## Proposed classes

### Packed96BitFloat

96-bit extended-precision packed float: three 32-bit mantissa DWORDs (low, mid, high) plus a sign/exponent WORD at +0xA. Low-level helpers copy, zero, shift, add and multiply this value.

Methods: `0x005952E9`, `0x00595304`, `0x0059532B`, `0x00597547`, `0x005975C6`, `0x005975F4`, `0x00597AA0`

- `this+0x00000000` `uint32 mantissa_low_dword` (read_write, DERIVED)
- `this+0x00000002` `uint16 mantissa_word1` (read, GUESS)
- `this+0x00000004` `uint32 mantissa_mid_dword` (read_write, DERIVED)
- `this+0x00000006` `uint16 mantissa_word3` (read, GUESS)
- `this+0x00000008` `uint32 mantissa_high_dword` (read_write, DERIVED)
- `this+0x0000000A` `uint16 sign_and_exponent_word` (read_write, DERIVED)

### ExtendedFloatFormatting

Orchestrates conversion of internal extended-precision floats and doubles into IEEE-32/64 outputs or fixed-width BCD decimal strings, using the Packed96BitFloat primitives, lookup-table scaling, and normalization helpers.

Methods: `0x005953B8`, `0x00597621`, `0x005976E8`, `0x00597CC0`


### StringFormatParseHelpers

CRT-style __cdecl helpers that build a 6-word format descriptor buffer and delegate parsing/formatting: signed base-10 special case, format-buffer fill via sub_596245, and parse delegates.

Methods: `0x00595550`, `0x0059557D`, `0x00596BF3`


### MemoryValidityWrappers

Positive memory-access predicates built on the Win32 IsBadReadPtr/IsBadWritePtr/IsBadCodePtr imports: each negates the import result so TRUE means the range or code pointer is valid.

Methods: `0x00597321`, `0x0059733D`, `0x00597359`


### SEHExceptionFilter

SEH exception filter that recognizes the MSVC C++ exception signature (record code 0xE06D7363, parameter[0]==3, parameter[1]==0x19930520) and dispatches to a validated global handler otherwise.

Methods: `0x005972BD`

- `obj+0x00000000` `EXCEPTION_RECORD* exception_record_ptr` (read, DERIVED)
- `obj+0x00000010` `uintptr_t exception_parameter0` (read, DERIVED)
- `obj+0x00000014` `uintptr_t exception_parameter1` (read, DERIVED)

### CrtStringCollation

Byte-count, case-insensitive CRT string collation following the _mbsnbicoll pattern, mapping CompareString-style status to signed comparison order with an error sentinel.

Methods: `0x00597F6D`


### WinsockImportThunks

Thin forwarding thunks to Winsock2 (ws2_32) IAT slots: socket, recvfrom, select, htons, send, recv, WSAFDIsSet, WSACleanup. No local logic; each is a pure import forward.

Methods: `0x00598648`, `0x0059864E`, `0x00598654`, `0x0059866C`, `0x0059867E`, `0x00598684`, `0x00598690`, `0x005986A2`


### StreamVtableFixup

C++ standard stream object construction/teardown helpers that install or restore std::istream/ostream vtable pointers at a slot offset derived from vtable[1], plus a deleting-destructor trampoline.

Methods: `0x00598731`, `0x00598775`, `0x00598E2E`, `0x0059925D`

- `this+0x00000000` `void** vtable_ptr` (read_write, DERIVED)
- `obj+0x00000004` `int vtable_slot_offset` (read, DERIVED)

### LocaleStreamLifecycle

Factory/cleanup/status surface for the locale stream object: fixed-argument construction delegates, virtual status check with error dispatch, and deleting-destructor teardown with conditional free.

Methods: `0x00598750`, `0x005987C1`, `0x005987F0`, `0x00598AA0`, `0x005992B7`


## Compatibility contracts

- **ExtendedFloatToIEEEStatusCodes** — ExtendedFloatToOutputFormat must return 0 (normal/zero), 1 (range-exceeded) or 2 (underflow/denormal) and write the 32- or 64-bit IEEE-style result to the output pointer, with the exponent shifted into the position given by byte 12 of the format array.
- **WinsockImportForwarding** — The eight thunk addresses 0x00598648-0x005986A2 must forward unchanged to the Winsock2 IAT slots socket/recvfrom/select/htons/send/recv/WSAFDIsSet/WSACleanup.
- **SEHFilterSignatureMatch** — The SEH filter must recognize the MSVC C++ exception signature (record code 0xE06D7363, parameter[0]==3, parameter[1]==0x19930520) before dispatching to the C++ handler wrapper, and validate the fallback global handler with CodePointerValidation before invoking it.
- **StreamVtableSlotDerivation** — Stream construction/teardown reads the dword at this+4 (vtable[1]) as a byte offset and installs the std::istream (0x005B9BA4) or std::ostream (0x005B9BAC) vtable pointer at this+offset.
- **CollationResultMapping** — Byte-count case-insensitive collation maps CompareString-style status (1=less, 2=equal, 3=greater) to signed -1/0/+1 and returns 0x7FFFFFFF as the collation-error sentinel when the helper reports failure.

## Unresolved

- Every packet owner is UnknownObject; all nine class groupings are GUESS/DERIVED architectural proposals inferred from shared helper pools and call relationships, not recovered original classes.
- Helpers with no bodies in the packet: sub_595304 (0x00595304), ArrayOf3ZeroCheck (0x00595310), BitArrayClearBitAndZeroFillSubsequentWords (0x0059525D), sub_596245, UintToStringConversion (0x00596C20), StringParseViaDelegate (0x00595524), DelegationWithStaticData (0x0059553A), sub_58FCA0 (special-value string selection), and sub_598A41 (locale stream construction); their contracts are inferred from call sites.
- The exact semantics of the a3 format-control array in ExtendedFloatToOutputFormat (thresholds a3[0]/a3[1], bit position a3[2], shifts a3[3]/a3[5], width a3[4], byte-12 exponent placement) are only partially derivable.
- The consumer role of the 96-bit value (timestamp/counter) and the exact numeric transform of the lookup tables at 0x005E9C38 and 0x005E9D98 (including the extended-encoding path with first word >= 0x8000) are not evidenced.
- The meaning of locale globals dword_8D48E4 and dword_8D46BC (locale/codepage handles) used by the collation helper is not determinable from this packet.
- Packet facts report reads of globals 0x008D4210, 0x008D42A0 and 0x008D43C8 (exception-type descriptors / locale-management struct) that do not appear in the decompiled bodies of the delegation stubs; their role is unresolved.
- VtableSetSubCall_8aea (stream init chain) and SEHWrapperDispatchingToHandlerFunction are named only in raw source with no callee evidence refs; their addresses and contracts are unknown.
- External callers outside the packet (sub_58BD8F, sub_58FD90, sub_5934E1, sub_5939F9, sub_5939F9/0052 caller sites, LocaleAwareStringFormat 0x00595621, sub_596245, and the number-formatting caller) define the consuming context but are not evidenced here.
