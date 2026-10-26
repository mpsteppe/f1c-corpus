# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Four functions reconstructed as two worker-proposed objects. IOFormatWrapper (0x0059BDE9) reads a 16-bit value from an opaque stream/format handle under a critical section, acquiring the section, delegating to the underlying read (sub_59BE0C), and releasing the section. The remaining three functions form an MSVC exception string object lifecycle: two copy constructors (0x0059BF19 deep-copy-only, 0x0059BF56 copy-mode flag selecting deep copy vs shared pointer) and a destructor (0x0059BFA0) that frees the owned buffer when the ownership flag is set. Both constructors install the exception vftable (0x005B9DC0) at +0, hold the string pointer at +4, and track ownership/refcount at +8.

## Function roles

- `0x0059BDE9` **IOStreamReader** — Thread-safe 16-bit stream read wrapper: acquire stream critical section, delegate read to sub_59BE0C, release section, return the read value.
- `0x0059BF19` **MSVCExceptionString** — Exception string copy constructor: install exception vftable, measure source string, allocate length+1 buffer, copy string data when allocation succeeded, mark ownership flag set.
- `0x0059BF56` **MSVCExceptionString** — Exception string copy constructor with copy-mode flag: install exception vftable, copy source ownership flag; deep-copy the source string when the flag is non-zero, else share the source string pointer without allocation.
- `0x0059BFA0` **MSVCExceptionString** — Exception string destructor: restore exception vftable, free the owned string buffer at +4 via the free wrapper when the ownership flag at +8 is non-zero, skip the free when the flag is zero (shared/borrowed string).

## Proposed classes

### IOStreamReader

Reads 16-bit values from a stream buffer via sub_59BE0C while holding the stream critical section, guaranteeing atomicity of the read relative to other stream accessors.

Methods: `0x0059BDE9`


### MSVCExceptionString

MSVC exception string object carrying the exception vftable (??_7exception@@6B@) at +0, a string buffer pointer at +4, and an ownership/refcount flag at +8. Copy construction allocates a length+1 heap copy when the source flag is non-zero, or shares the source pointer when zero; destruction frees the owned buffer only when the flag is non-zero.

Methods: `0x0059BF19`, `0x0059BF56`, `0x0059BFA0`

- `this+0x00000000` `const void* (vftable) vftable_ptr` (read_write, DERIVED)
- `this+0x00000004` `char* string_buffer` (read_write, DERIVED)
- `this+0x00000008` `int owns_string_flag` (read_write, DERIVED)

## Compatibility contracts

- **LockedStreamRead16** — A 16-bit stream read is performed only while holding the stream critical section: acquire the section, delegate the read to the underlying stream reader, release the section, then return the read value. A replacement executable must preserve the acquire/read/release ordering and must not read the stream without holding the section.
- **ExceptionStringOwnership** — Exception string objects expose vftable at +0, string buffer pointer at +4, and an ownership flag at +8. Non-zero flag: copy construction allocates length+1 bytes via the new wrapper and copies the source string, and destruction frees the buffer via the free wrapper. Zero flag: the source string pointer is shared without allocation and the destructor skips the free. A replacement must preserve the ownership decision and the vftable identity.

## Unresolved

- sub_59BE0C (0x0059BE0C) is the actual 16-bit read implementation for IOStreamReader and is not analyzed in this packet.
- The a1 handle of IOFormatWrapper is an opaque stream/format handle; its meaning is not established.
- The single caller of IOFormatWrapper, sub_59A103 (0x0059A103), is not analyzed; the callers of the exception-string functions (0x0059A69A, 0x0059ADA3, 0x0059A781, 0x0059AE7D) are not analyzed.
- sub_58FCA0 is a jump thunk; the actual string copy/init routine is reached through that transfer, outside this packet.
- The specific exception type owning the vftable ??_7exception@@6B@ (0x005B9DC0) is not established by this packet alone.
- The precise semantics of the +8 flag (refcount vs explicit copy-mode selector) are inferred from branch behavior and not independently grounded.
- The exact copy behavior of sub_58FCA0 (whether it copies from the source string pointer) is not verified within this packet.
- The owning class of the exception-string object is opaque in the packet (owner trust UNKNOWN); MSVCExceptionString is a worker-proposed name, not recovered source.
- MSVCExceptionDestructor on the borrowed/flag-zero path returns an uninitialized value in the decompiled form.
- IOStreamReader and MSVCExceptionString are worker-named class proposals derived from shared vftable and field evidence; a replacement must not treat them as recovered original source names.
