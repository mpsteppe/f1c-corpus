# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Forty-three runtime-object helper functions that do not belong to a specific game subsystem. Six functions form an extended-precision x87 floating-point cluster (division with overflow fixup, FPREM-style remainder core, denormal-scaling modulus, double classification, and float display formatting). Eight functions are Winsock2 import thunks forwarding through IAT globals at 0x0059E2CC-0x0059E310. Seven functions are MSVC stream-object internals keyed on the std::ios/std::streambuf vtables (0x005B9BB4, 0x005B9C04) and the buffered-stream layout (vtable +0, get pointer +0x1C, remaining count +0x2C). Fifteen functions are one-line delegation/conversion thunks, most converging on the shared helpers BooleanToIntConversion (0x00587B3E) and VTableInitOnly (0x00598E2E); four more are constructor/vtable-fixup pass-through thunks. Two functions sit on the SEH exception-frame dispatch path. All owners are UnknownObject; class groupings below are DERIVED from call shape, identical wrapper structure, ABI labels, and shared IAT/vtable evidence, not from proven shared ownership.

## Function roles

- `0x0059083B` **FloatFormatting** — Float-to-display-string formatting wrapper: loads the double argument through CRTFload and formats it via Trandisp1, finalizing through sub_590703; display context unknown (no callers recorded).
- `0x005908B0` **ExtendedPrecisionArithmetic** — 80-bit extended-precision division returning a double, with mantissa normalization and lookup-table/scale-constant overflow fixup so the quotient stays within double range.
- `0x005910A1` **ExtendedPrecisionArithmetic** — Wrapper that stores two x87-register doubles into local TBYTE scratch buffers and calls the extended-precision division fixup routine with pointers to them; void return.
- `0x005910B6` **ExtendedPrecisionArithmetic** — Core extended-precision FPREM-style remainder reducer: classifies operands through byte_5E74FC and exponent masks, then reduces via scaled subtraction or direct x87 FPREM depending on the exponent gap; reloads the x87 environment on low flag bits.
- `0x005912BC` **ExtendedPrecisionArithmetic** — Double modulus wrapper: non-zero divisor exponent takes a fast path into the remainder core; otherwise zero/denormal inputs are detected and both operands scaled by dbl_5E7514 with scale flags 2/3.
- `0x00591574` **ExtendedPrecisionArithmetic** — Double-precision classification routine: inspects a2's exponent bits, dispatches to FloatingPointRemainder with mode 0, or scales both operands by dbl_5E7514 and dispatches with mode 2/3; zero a2 returns a low-word combination directly.
- `0x005930E8` **Unresolved** — Runtime introspection helper: validates the running image MZ/e_lfanew headers and copies the PE optional-header Major/MinorLinkerVersion bytes into a two-byte caller buffer; returns the minor version byte on success.
- `0x00593C50` **SehExceptionFrameHelpers** — SEH frame-path helper: runs frame-setup sub_588931, dispatches an indirect frame handler, normalizes a 256 type code to 2, and reruns sub_588931; used by both SEH exception-frame callers.
- `0x00593D53` **SehExceptionFrameHelpers** — Trivial stub returning the constant 1 and ignoring its argument; the packet names LongjmpMSVCCRT as sole caller, suggesting an SEH/longjmp default-handler placeholder, but that purpose is not evidenced.
- `0x0059508D` **Unresolved** — Bit-field merge wrapper: masks the second argument with 0xFFF7FFFF then delegates to the bit-field mask-merge routine.
- `0x0059553A` **Unresolved** — Thin delegation wrapper forwarding a1, a2 and global dword_5E99B8 to sub_5953B8 and returning its result.
- `0x00595621` **FloatFormatting** — Locale/format wrapper: unpacks an 80-bit float via Float80ToFloat64Unpack, formats it through sub_5976E8 into a character buffer, and packs length, first char, buffer value and a forwarded word into a caller-provided _DWORD output record.
- `0x00596DFE` **Unresolved** — Trivial cdecl forwarding wrapper passing its char argument plus fixed constants 0 and 4 to sub_596E0F and returning the result.
- `0x00596E0F` **Unresolved** — Bit-flag predicate: returns 1 when the byte flag intersects byte_8D47E1[a1] or when the word mask intersects word_5E69D2[a1]; used by the ThreeArgCallWrapper delegation path.
- `0x00598630` **Winsock2ImportThunks** — Winsock2 import thunk for ntohs: forwards the u_short argument through __imp_ntohs (0x0059E2CC) and returns its result.
- `0x00598636` **Winsock2ImportThunks** — Winsock import thunk for getsockname: forwards (s, name, namelen) through __imp_getsockname (0x0059E2D0) and returns the error code.
- `0x0059863C` **Winsock2ImportThunks** — Winsock import thunk for bind: forwards (s, name, namelen) through __imp_bind (0x0059E2D4) and returns the error code.
- `0x00598642` **Winsock2ImportThunks** — Winsock import thunk for htonl: forwards the hostlong through __imp_htonl (0x0059E2D8) and returns the network-byte-order result.
- `0x00598660` **Winsock2ImportThunks** — stdcall import thunk for gethostbyname: forwards the host-name string through __imp_gethostbyname (0x0059E2EC) and returns the hostent pointer.
- `0x00598678` **Winsock2ImportThunks** — Winsock2 import thunk for connect: forwards (s, name, namelen) through __imp_connect (0x0059E2FC) and returns its result.
- `0x0059868A` **Winsock2ImportThunks** — Winsock2 import thunk for setsockopt: forwards (s, level, optname, optval, optlen) through __imp_setsockopt (0x0059E308) and returns its result.
- `0x00598696` **Winsock2ImportThunks** — Winsock import thunk for inet_ntoa: converts an in_addr structure to a dotted-quad string through __imp_inet_ntoa (0x0059E310) and returns the string pointer.
- `0x005986B2` **CRTCallbackThunks** — One-line delegation stub calling VTableInitOnly (sub_598E2E) with the fixed constant 0 and returning its result.
- `0x005986BF` **CRTCallbackThunks** — Delegation wrapper passing the address of global PhysicsSolverInitStub (0x005986CB) to BooleanToIntConversion and returning the conversion result.
- `0x005986DF` **CRTCallbackThunks** — One-line delegation stub calling VTableInitOnly (sub_598E2E) with the fixed constant 0 and returning its result.
- `0x005986EC` **CRTCallbackThunks** — Delegation wrapper passing the address of global PhysicsStateWrapper (0x005986F8) to BooleanToIntConversion and returning the conversion result.
- `0x0059870C` **VTableFixupConstructorThunks** — Direct delegation to ObjectConstructorWithSEHVtableInit with literal arguments 0 and 1; a zero-argument convenience constructor supplying a default first argument.
- `0x00598727` **VTableFixupConstructorThunks** — Pass-through thunk forwarding all four arguments unchanged to ConstructorWithVTableFixup (callee address not recorded in the packet) and returning its int result.
- `0x0059876B` **VTableFixupConstructorThunks** — Pure forwarding thunk delegating all four arguments unchanged to VtableFixupWithDestructor and returning its result; callee address not evidenced.
- `0x00598794` **CRTCallbackThunks** — One-line delegation stub calling VTableInitOnly (sub_598E2E) with the fixed constant 0 and returning its result.
- `0x005987A1` **CRTCallbackThunks** — Delegation wrapper reading global PhysicsStateUnkInit (0x005987AD), converting its value to int, passing it to BooleanToIntConversion and returning the result.
- `0x005987D0` **CRTCallbackThunks** — Delegation wrapper reading global StringPrintfThunk (0x005987DC), converting its value to int, passing it to BooleanToIntConversion and returning the result.
- `0x005987DC` **VTableFixupConstructorThunks** — Forwarding wrapper passing the address of global dword_8D43C8 (cast to char*) plus four forwarded arguments to VtableFixupWithDestructor; callee address not evidenced.
- `0x005987FF` **CRTCallbackThunks** — Delegation wrapper reading global PhysicsThunk (0x0059880B), converting its value to int, passing it to BooleanToIntConversion and returning the result.
- `0x00598AEA` **StreamObjectRuntime** — Stream-object constructor tail: writes the std::ios vftable pointer into this+0x0 and tail-jumps to a further initialization routine; invoked during stream-object construction from sub_59927C.
- `0x00598CC1` **StreamObjectRuntime** — Streambuf destructor-stage vtable fixup: writes the std::streambuf vftable into this+0x0 and dispatches a virtual call through the locale sub-object at this+13; invoked from the streambuf destructor chain.
- `0x00598CDC` **StreamObjectRuntime** — Streambuf uflow virtual method: dispatches the vtable slot-4 function (offset 0x10) to refill; on -1 returns immediately, otherwise reads one byte from the get area via MSVCStreambufGninc.
- `0x00599081` **StreamObjectRuntime** — Buffered single-byte read: fast path returns the buffered byte at this+0x1C while the count at this+0x2C is positive; otherwise refills via vtable slot 5 (offset 0x14) and consumes through vtable slot 2 (offset 0x08).
- `0x0059927C` **StreamObjectRuntime** — C++-style destructor wrapper: runs base stream-object initialization via VtableSetSubCall, conditionally frees the object when flag bit 0 of a3 is set, and returns the object pointer.
- `0x00599298` **StreamObjectRuntime** — Userpurge memory wrapper: backs up 8 bytes from the receiver to an offset header, runs ConstructorWithVTableFixup on that header, conditionally frees it via FreeWrapper when flag bit 0 is set, and returns the header pointer.
- `0x0059978A` **CRTCallbackThunks** — Trivial thunk converting the global EmptyStub_9796 value/address to an integer via BooleanToIntConversion and returning the result.
- `0x005997AB` **CRTCallbackThunks** — Thin wrapper converting the address of global PhysicsStateCleanupWrapper to an integer, passing it to BooleanToIntConversion and returning the result.
- `0x005997D5` **CRTCallbackThunks** — Thin wrapper converting the address of global PhysicsStateAccessor to an integer, passing it to BooleanToIntConversion and returning the result.

## Proposed classes

### ExtendedPrecisionArithmetic

Extended-precision (80-bit x87) floating-point math helpers: division with overflow fixup, FPREM-style remainder reduction, and denormal-handling modulus wrappers.

Methods: `0x005908B0`, `0x005910A1`, `0x005910B6`, `0x005912BC`, `0x00591574`


### FloatFormatting

Float-to-text formatting wrappers: CRT display-format path (CRTFload/Trandisp1/sub_590703) and extended-float decimal packing into a caller output record (Float80ToFloat64Unpack/sub_5976E8).

Methods: `0x0059083B`, `0x00595621`


### Winsock2ImportThunks

A contiguous block of Winsock/Winsock2 import-address-table thunks forwarding arguments unchanged to the imported entry points for network byte-order, socket naming, binding, name resolution, connection, options and address formatting.

Methods: `0x00598630`, `0x00598636`, `0x0059863C`, `0x00598642`, `0x00598660`, `0x00598678`, `0x0059868A`, `0x00598696`


### StreamObjectRuntime

MSVC iostream/streambuf stream-object internals: constructor tail that installs the std::ios vftable, destructor-stage vtable fixup with locale dispatch, the uflow/underflow virtual, a buffered single-byte read over the get-area layout, and conditional-free destructor/deallocation wrappers.

Methods: `0x00598AEA`, `0x00598CC1`, `0x00598CDC`, `0x00599081`, `0x0059927C`, `0x00599298`

- `this+0x00000000` `void** vftable` (read_write, DERIVED)
- `this+0x0000001C` `char* getPointer` (read, DERIVED)
- `this+0x0000002C` `int remainingByteCount` (read, DERIVED)
- `*(this+0x1C)+0x00000000` `char bufferedByte` (read, DERIVED)
- `obj+0x00000008` `void* slot2` (unknown, GUESS)
- `obj+0x00000010` `void* slot4` (unknown, GUESS)
- `obj+0x00000014` `void* slot5` (unknown, GUESS)

### CRTCallbackThunks

One-line delegation/conversion thunks, most converging on the shared helpers BooleanToIntConversion (0x00587B3E) or VTableInitOnly (0x00598E2E); the argument is either a fixed constant, a global value/address, or a converted global.

Methods: `0x005986B2`, `0x005986BF`, `0x005986DF`, `0x005986EC`, `0x00598794`, `0x005987A1`, `0x005987D0`, `0x005987FF`, `0x0059978A`, `0x005997AB`, `0x005997D5`


### VTableFixupConstructorThunks

Constructor and vtable-fixup pass-through thunks: convenience constructors and forwarding wrappers whose callees (ObjectConstructorWithSEHVtableInit, ConstructorWithVTableFixup, VtableFixupWithDestructor) are only partially evidenced in the packet.

Methods: `0x0059870C`, `0x00598727`, `0x0059876B`, `0x005987DC`


### SehExceptionFrameHelpers

Helpers on the SEH exception-frame dispatch path: a frame-setup/finalize helper with indirect handler dispatch and type-code normalization, and a constant-1 success stub used by the longjmp/SEH path.

Methods: `0x00593C50`, `0x00593D53`


## Compatibility contracts

- **ExtendedPrecisionDivisionOverflowFixup** — Division of 80-bit extended-precision operands must return a double within double range: mantissas are normalized (scaling by flt_5E74F8) until the integer bit is set, an exponent-class check through the byte_5E74E0 lookup table decides whether overflow fixup is needed, and both operands are scaled by flt_5E74F4 or flt_5E74F0 before dividing when the range is accepted.
- **ExtendedPrecisionRemainder** — FPREM-style remainder over 80-bit operands: operand classification through byte_5E74FC and exponent masks, an exponent-gap decision between scaled subtraction (divisor scaled by dbl_5E752C) and direct x87 FPREM, and a reload of the x87 environment when the caller flag has low bits set. Callers select fast (mode 0) vs denormal-scale (modes 2/3, scaling by dbl_5E7514) paths.
- **FloatDisplayFormatting** — Floating-point values are rendered through CRT display helpers: the CRT float display path loads a double via CRTFload and formats it through Trandisp1, while the locale/format path unpacks an 80-bit float via Float80ToFloat64Unpack and packs a fixed-width decimal string (limit 17) into a _DWORD output record holding length, first character, buffer value and a forwarded word.
- **WinsockImportThunkForwards** — The eight Winsock thunks forward their arguments unchanged through the IAT pointer globals 0x0059E2CC-0x0059E310 to the corresponding imported entry points (ntohs, getsockname, bind, htonl, gethostbyname, connect, setsockopt, inet_ntoa) and return the imported result.
- **StreamObjectLayout** — Stream objects place their vtable pointer at offset 0. Buffered read streams carry a get-area read pointer at +0x1C and a remaining-byte count at +0x2C. Refill is dispatched through vtable slot 5 (offset 0x14); slot 2 (offset 0x08) consumes the refilled byte; the uflow virtual refills through slot 4 (offset 0x10). The std::ios (0x005B9BB4) and std::streambuf (0x005B9C04) vtables are installed at construction/destruction stages.
- **PeLinkerVersionIntrospection** — A runtime helper reads the current process image's PE optional-header MajorLinkerVersion and MinorLinkerVersion (bytes +26/+27) into a two-byte caller buffer after validating the MZ DOS signature and a non-zero e_lfanew; on a non-PE image the low byte of the module base is returned instead.

## Unresolved

- Function owners are uniformly UnknownObject; the seven classes above are DERIVED from call shape, identical wrapper structure, ABI labels, and shared IAT/vtable evidence, not from proven shared ownership. Equal offsets on unrelated objects are not proof of a shared class.
- Globals 0x008D4248, 0x008D42A0, 0x008D42D8, 0x008D4330, 0x008D4370, 0x0058895C and 0x005B99B8 are recorded as read by the wrapper thunks but do not appear in their decompiled bodies; treated as fill/analysis artifacts with no evidenced semantic role.
- The five TEB-range global references (0xFF00000000001692 through 0xFF0000000000169B) recorded for EmptySuccessStub (0x00593D53) are compiler SEH/TEB magic, not semantic fields.
- The floating-point scaling constants flt_5E74F0, flt_5E74F4, flt_5E74F8, dbl_5E7514 and dbl_5E752C have values absent from the packet; confirming the fixup math requires their numeric values. dbl_5E751C (0x005E751C) and tbyte_5E7534 (0x005E7534) are listed by the fact tables but absent from the decompiled bodies.
- The lookup tables byte_5E74E0 (division overflow classification) and byte_5E74FC (remainder operand classification), and the 0xE000000/0x700/0x100 masks, are not fully derivable from packet evidence; x87 FPREM semantics provide only a DERIVED interpretation.
- The virtual dispatch targets (vtable slots 2/4/5 and the locale sub-object dispatch at this+13, offset +52) are not statically resolved in the packet; the uflow/sputc/underflow names are analysis labels only.
- The 'physics', 'locale', 'string' and 'callback' names attached to the globals read by the CRTCallbackThunks are ABI/analysis naming leads, not confirmed semantics; the shared helper BooleanToIntConversion (0x00587B3E) treats the pointer/global argument as a state token or validity signal.
- ReadPEHeaderLinkerVersion (0x005930E8) writes a minor-linker-version byte at caller buffer offset +1; that field:this:0x00000001 reference is placed in unresolved_evidence_refs because it belongs to a caller-provided output buffer, not to any identified class.
- The packet canonical label PEImageBaseAddressDetection for 0x005930E8 is a misnomer; the function reads the linker version, not the image base. PE32/PE32+ is not validated before reading optional-header bytes +26/+27.
