# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

This packet contains 54 generic runtime functions. The dominant patterns are (1) bare JUMPOUT forwarding thunks whose real bodies live at targets outside the packet, and (2) empty nullsub placeholders. The remaining functions are small self-contained helpers: 16.16 fixed-point multiply/divide and float-to-int conversion, 16-bit and 32-bit pixel fill/blit routines, a relative-offset string copy, an n-th backslash scanner, a CRC-style checksum, a min-heap sift-down, a bit-reversal helper, and an x87 power helper. Three functions carry decompiler 'positive sp value' warnings and are treated as unreliable (0x00554E04, 0x005631C4, 0x0056498E); two others are probable inline-asm decompiler artifacts (0x0055685A, and the MK_FP bare-return stubs 0x0052D294/0x0052D2A4). Ownership of every function is unknown from the packet; class assignments are GUESS-level behavioral groupings, and each jump thunk's target is unresolved.

## Function roles

- `0x0051F890` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x0051F8A1 forwarding four __stdcall arguments unchanged; target not in packet.
- `0x0051F980` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x0051F991 forwarding three __stdcall arguments unchanged; target not in packet.
- `0x0051FB10` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x0051FB21 forwarding two __stdcall arguments unchanged; target not in packet.
- `0x0051FD20` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x0051FD31 forwarding two __stdcall arguments unchanged; target not in packet.
- `0x0051FEB0` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x0051FEC1 forwarding four __stdcall arguments unchanged; target not in packet.
- `0x0051FF80` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x0051FF91 forwarding three __stdcall arguments unchanged; target not in packet.
- `0x00520040` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520051 forwarding three __stdcall arguments unchanged; target not in packet.
- `0x00520140` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520151 forwarding three __stdcall arguments unchanged; target not in packet.
- `0x00520200` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520211 forwarding three __stdcall arguments unchanged; target not in packet.
- `0x00520350` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520361 forwarding two __stdcall arguments unchanged; target not in packet.
- `0x00520420` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520431 forwarding two __stdcall arguments unchanged; target not in packet.
- `0x00520500` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520511 forwarding three __stdcall arguments unchanged; target not in packet.
- `0x005207C0` **TailJumpThunk** — Unconditional tail-jump thunk: JUMPOUT to 0x005207D1; four declared arguments unused in the body and forwarded implicitly; target not in packet.
- `0x00520870` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520881 forwarding two __stdcall arguments unchanged; target not in packet.
- `0x005208F0` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520901 forwarding two __stdcall arguments unchanged; target not in packet.
- `0x00520980` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520991 forwarding four __stdcall arguments unchanged; target not in packet.
- `0x00520A70` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520A81 forwarding three __stdcall arguments unchanged; target not in packet.
- `0x00520C00` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520C11 forwarding two __stdcall arguments unchanged; target not in packet.
- `0x00520E00` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x00520E11 forwarding four __stdcall arguments unchanged; target not in packet.
- `0x005645F0` **TailJumpThunk** — Unconditional tail-jump forwarding thunk: JUMPOUT to 0x005645B0; control transfers instead of returning; target not in packet.
- `0x00527F21` **UnknownObject** — CRC-style checksum over a byte buffer using two 16-bit accumulators seeded from a1, folded modulo 0xFFF1 in chunks of at most 5552 bytes, returning (high << 16) | low; returns 1 when the data pointer is null. Signature (seed, data, length) comes from the raw source; the legacy ABI label FAIL_527f21 carries no prototype.
- `0x0052D214` **NullSubroutine** — Empty no-op stub (nullsub_105): void body with no operations, no side effects; placeholder callback or vtable slot with no recorded callers.
- `0x0052D224` **NullSubroutine** — Empty no-op stub (nullsub_106): void body with no operations, no side effects; placeholder callback or vtable slot with no recorded callers.
- `0x0052D294` **NullSubroutine** — Bare-return stub (nullsub_107): the raw MK_FP indirect far call through the saved return address is a Hex-Rays artifact of a bare retn; performs no real work and returns to its caller.
- `0x0052D2A4` **NullSubroutine** — Bare-return stub (nullsub_108): the raw MK_FP indirect far call through the saved return address is a Hex-Rays artifact of a bare retn; performs no real work and returns to its caller.
- `0x0052E1C0` **UnknownObject** — thiscall forwarding thunk: forwards the this pointer unchanged to CConstructor(this) and propagates its char return value; whether a vtable flag check precedes the call is not visible in the thunk body.
- `0x005385E0` **UnknownObject** — Binary min-heap sift-down (__fastcall): bubbles an element down while a child has a smaller 16-bit key (or equal key with lower tie-break byte); heap count read at a1+5190, element array at a1+4*idx+2898, tie-break bytes at a1+elem+5198; invoked by sub_5383D0.
- `0x00539670` **UnknownObject** — Bit reversal of the low a2 bits of a1 via successive LSB extraction; called by FrequencyTableConstruction (0x005388D0) with a caller-supplied count.
- `0x0053B110` **UnknownObject** — x87 float power a1^a2 computed as a2*log2(a1) via __FYL2X__, then 2^z-1 via __F2XM1__ with a trailing +1.0 to cancel the F2XM1 bias; returns the result as double.
- `0x0053B590` **NullSubroutine** — Empty no-op stub (nullsub_109): void __stdcall body accepting three int arguments that are never read; placeholder callback or vtable slot.
- `0x0053B5A0` **NullSubroutine** — Empty no-op stub (nullsub_110): void __stdcall body accepting three int arguments that are never read; placeholder callback or vtable slot.
- `0x0053BB20` **NullSubroutine** — Empty no-op stub (nullsub_111): void body with no parameters, no operations, no side effects; placeholder callback or vtable slot.
- `0x00540240` **UnknownObject** — Constant-zero stub: __stdcall body returning 0 unconditionally while ignoring three arguments; single recorded caller sub_560FE0.
- `0x0054632D` **NullSubroutine** — Empty no-op stub (nullsub_112): void __stdcall body accepting two int arguments that are never read; no recorded callers.
- `0x005472B0` **StringScanHelpers** — strcpy-style relative-offset string copy: copies source a2 into destination 'this' using the relative offset this-a2 as a byte displacement, through and including the NUL terminator; returns the source cursor pointing at the copied terminator.
- `0x00548DF4` **NullSubroutine** — Empty no-op stub (NullStub): void body with no operations, no side effects; placeholder callback or vtable slot with no recorded callers.
- `0x0054A574` **NullSubroutine** — Empty no-op stub (NullStub): void body ignoring a single int parameter a1; placeholder callback or vtable slot with no recorded callers.
- `0x00554E04` **UnknownObject** — Suspect byte accumulation: increments the byte at (a2 + 1586460159) by the al byte and returns it unchanged. Flagged by the decompiler with a positive-sp warning, so the signature, a2 meaning, and the large offset are all unreliable.
- `0x00556790` **FixedPointArithmetic** — 16.16 fixed-point multiply with rounding: signed 64-bit product, add 0x8000 (half of 2^16), shift right 16, return the 32-bit result.
- `0x005567A9` **FixedPointArithmetic** — 16.16 fixed-point divide with explicit sign handling: absolute value of numerator, shift left 16, integer divide by divisor, re-apply original sign; division by zero is unguarded.
- `0x005567D3` **FixedPointArithmetic** — Truncating float-to-int conversion: plain C cast of a single-precision argument to int (truncation toward zero); no round-half semantics, no out-of-range or NaN handling evidenced.
- `0x0055685A` **UnknownObject** — Trivial helper: resets the x87 FPU via FNINIT, then returns the boolean (a1 == 0) where a1 arrives in the FPU status word per __usercall; likely a decompiler artifact of a single inline-asm sequence.
- `0x0055C7A6` **NullSubroutine** — Empty no-op stub (nullsub_115): void __stdcall body ignoring a single argument; placeholder satisfying a caller that expects a callable (vtable slot, callback, or override placeholder).
- `0x005604C0` **PixelFillPrimitives** — Pixel blit copying a rectangular region from a 16-bit source buffer to a 32-bit destination buffer, expanding each 16-bit pixel into a 32-bit word and skipping pixels equal to the reference color a11 (color-key); address arithmetic built from flat base/stride/count parameters.
- `0x00561970` **PixelFillPrimitives** — 16-bit pixel fill with a Bresenham-style error accumulator: stores a fixed 16-bit value into a run of pixels, advancing to the next scanline via a byte row stride whenever the error term crosses zero; returns the fill value.
- `0x005619AF` **PixelFillPrimitives** — 16-bit pixel fill with a per-pixel stride step plus a Bresenham-style conditional scanline advance: stores a fixed 16-bit value, steps the pointer by a small byte stride each pixel, and adds a larger row stride when the error accumulator crosses zero.
- `0x00561AF8` **PixelFillPrimitives** — 32-bit dword pixel fill with stride: writes constant dword a3 to a2 pixels starting at byte address 4*a1+a5, advancing 4*a4 bytes per write, returning a3; used by DrawRectangle (0x00553D70) to paint a scanline or row.
- `0x005631C4` **UnknownObject** — Suspect __userpurge helper (positive-sp warning): increments the byte at a2 by byte 5 of a 64-bit result value, executes an inline rcr on a byte addressed through caller register edi, and returns the original 64-bit result; reconstruction flagged unreliable.
- `0x00563A70` **StringScanHelpers** — Scans a byte buffer from a1 for a2 bytes looking for the n-th backslash (0x5C), n = a3; returns the offset after the n-th backslash, 0 when n is zero, -1 when fewer than n backslashes exist; called by sub_563870.
- `0x00563FFA` **NullSubroutine** — Empty no-op stub (NullStub): void body with no operations, no side effects; placeholder callback or vtable slot with no recorded callers.
- `0x0056498E` **UnknownObject** — Empty stub flagged by the decompiler (positive-sp warning); the body renders as a no-op but the reconstruction is unreliable, suggesting misdecoded data or a fragment rather than a live function.
- `0x005665A4` **NullSubroutine** — Empty no-op stub (nullsub_117): void body with no statements; no ABI recorded, no callers, callees, fields, globals, or strings to anchor a semantic role.
- `0x005666AE` **UnknownObject** — Single-call delegation wrapper: returns sub_5666B0(a1, a2, a3) directly with all three arguments forwarded unchanged; the callee has no address entry in the packet.
- `0x005668EC` **NullSubroutine** — Empty no-op stub (sub_5668EC): void body with no statements; no ABI recorded, no callers, callees, fields, globals, or strings to anchor a semantic role.

## Proposed classes

### TailJumpThunk

Forwarding thunks whose entire body is an unconditional tail jump (JUMPOUT) to a target address outside the packet, forwarding all declared __stdcall arguments unchanged without returning to the caller. Grouped by identical control shape; the real behavior lives at each target and the owning class is unknown.

Methods: `0x0051F890`, `0x0051F980`, `0x0051FB10`, `0x0051FD20`, `0x0051FEB0`, `0x0051FF80`, `0x00520040`, `0x00520140`, `0x00520200`, `0x00520350`, `0x00520420`, `0x00520500`, `0x005207C0`, `0x00520870`, `0x005208F0`, `0x00520980`, `0x00520A70`, `0x00520C00`, `0x00520E00`, `0x005645F0`


### NullSubroutine

Empty no-op placeholder stubs: void bodies (some rendered as bare-return artifacts) that perform no work, touch no memory, and have no observable effect when called. Existence is inferred to be a referenced placeholder such as a callback, vtable slot, or deliberately disabled hook; no callers are recorded in the packet.

Methods: `0x0052D214`, `0x0052D224`, `0x0052D294`, `0x0052D2A4`, `0x0053B590`, `0x0053B5A0`, `0x0053BB20`, `0x0054632D`, `0x00548DF4`, `0x0054A574`, `0x0055C7A6`, `0x00563FFA`, `0x005665A4`, `0x005668EC`


### FixedPointArithmetic

Small numeric primitives clustered at adjacent addresses: 16.16 fixed-point multiply with half-unit rounding, 16.16 fixed-point divide with sign re-application, and a truncating float-to-int conversion. The fixed-point scale is implied by the sibling multiply/divide pair, not independently stated in the packet.

Methods: `0x00556790`, `0x005567A9`, `0x005567D3`


### PixelFillPrimitives

Low-level pixel buffer routines: a 16-bit to 32-bit expanding blit with color-key skip, two 16-bit Bresenham-style pixel fills, and a 32-bit dword fill with stride used by DrawRectangle. Buffer layouts are flat base/stride/count parameters rather than surface structs.

Methods: `0x005604C0`, `0x00561970`, `0x005619AF`, `0x00561AF8`


### StringScanHelpers

Byte-level string/buffer scanning routines: a relative-offset strcpy-style copy and an n-th backslash locator. Both operate on flat byte buffers without class state.

Methods: `0x005472B0`, `0x00563A70`


## Compatibility contracts

- **TailJumpThunkForwarding** — Each of the 20 JUMPOUT thunks must transfer control to its recorded target with the declared __stdcall arguments passed through unchanged and without returning to the caller. A replacement must preserve the target addresses (0x0051F8A1, 0x0051F991, 0x0051FB21, 0x0051FD31, 0x0051FEC1, 0x0051FF91, 0x00520051, 0x00520151, 0x00520211, 0x00520361, 0x00520431, 0x00520511, 0x005207D1, 0x00520881, 0x00520991, 0x00520A81, 0x00520C11, 0x00520E11, 0x005645B0) and the argument counts recorded per thunk.
- **CrcChecksumCalculation** — Function 0x00527F21 computes a 32-bit checksum over a byte buffer: two 16-bit accumulators seeded from the seed argument, folded modulo 0xFFF1 in chunks of up to 5552 bytes, combined as (high << 16) | low; a null data pointer returns 1. The calling convention and prototype are only partially evidenced (legacy FAIL label, raw-source signature).
- **NullSubroutineNoOp** — The 14 nullsub/placeholder stubs must remain callable no-ops: any caller reaching these addresses observes no state change, no memory access, and an immediate return. Their acceptance of various declared arguments (0 to 3) is not behaviorally significant.
- **FixedPoint1616Semantics** — 0x00556790 must return the 16.16 fixed-point product of its two operands with half-unit rounding ((a1*a2 + 0x8000) >> 16); 0x005567A9 must return the fixed-point quotient with sign re-application ((abs(a1) << 16) / a2, sign restored). Any replacement arithmetic must preserve these exact rounding and sign behaviors.
- **PixelFillAndBlitBufferContract** — Pixel routines operate on flat base/stride/count parameters: 0x005604C0 expands 16-bit source pixels into 32-bit destination dwords (two writes per source word) skipping the reference/color-key value; 0x00561970 and 0x005619AF fill 16-bit pixels with Bresenham error-accumulator scanline advance; 0x00561AF8 writes dword pixels with a byte stride and is used by DrawRectangle (0x00553D70). Exact surface semantics are unproven.
- **MinHeapSiftDownLayout** — 0x005385E0 maintains a binary min-heap whose owning object stores the count at +5190, a dword element array at +2898 (element index by 4 bytes), and per-element tie-break bytes at +5198; a parallel 16-bit key array is supplied by the caller. These offsets are read from the raw source and are not independently confirmed.

## Unresolved

- The JUMPOUT targets of all 20 forwarding thunks (e.g. 0x0051F8A1 through 0x005645B0) are not recorded as callees in the packet; their identity, behavior, and the meaning of each thunk's forwarded arguments are unknown.
- The owning class of every function in this packet is unknown; the five class groupings (TailJumpThunk, NullSubroutine, FixedPointArithmetic, PixelFillPrimitives, StringScanHelpers) are behavioral proposals, not confirmed source structure.
- The min-heap object layout at 0x005385E0 (count at +5190, elements at +2898, tie-break at +5198) and the parallel key array layout are derived from the raw source only and are unconfirmed.
- The CRC checksum 0x00527F21 carries a legacy FAIL ABI label with no prototype; the (seed, data, length) signature and the 0xFFF1 modulus semantics come from the raw source only, and the 'positive sp' style warnings elsewhere in the packet lower confidence in ABI details.
- Functions 0x00554E04, 0x005631C4, and 0x0056498E are flagged by the decompiler with 'positive sp value has been detected' warnings; their bodies are unreliable and may reflect misdecoded data, fragments, or inline-asm artifacts rather than real routines.
- 0x0055685A (FNINIT then a1==0) and the MK_FP bare-return stubs 0x0052D294 / 0x0052D2A4 are probable Hex-Rays artifacts of inline-asm or bare-retn sequences; their true source shape is not recoverable from this packet.
- 0x005666AE forwards to sub_5666B0 which has no address or callee entry in the packet, so the delegation target's identity and semantics are unknown.
- The pixel blit/fill routines (0x005604C0, 0x00561970, 0x005619AF, 0x00561AF8) use flat base/stride/count parameters; whether the 16-to-32-bit expansion double-write at 0x005604C0 targets one or two interleaved destination buffers is undetermined.
- 0x00540240 ReturnZero's caller sub_560FE0 expects a constant-zero result, but the reason and the caller's contract are not evidenced in the packet.
- The empty stub placeholders (0x0052D214, 0x0052D224, 0x0052D294, 0x0052D2A4, 0x0053B590, 0x0053B5A0, 0x0053BB20, 0x0054632D, 0x00548DF4, 0x0054A574, 0x0055C7A6, 0x00563FFA, 0x005665A4, 0x005668EC) have no recorded callers, so whether they are vtable slots, callback placeholders, or disabled hooks cannot be determined.
- The exact geometric primitives rendered by the Bresenham-style 16-bit fills (0x00561970, 0x005619AF) and the a3/a4 error-accumulator increment roles are inferred, not caller-confirmed.
