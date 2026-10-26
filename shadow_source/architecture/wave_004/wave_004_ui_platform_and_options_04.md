# UIPlatformAndOptions

Scope: `ui_platform_and_options`  
Trust: `DERIVED`

DERIVED architecture proposal for the ui_platform_and_options scope, packet 04. The packet contains a single validated function, 0x0059C127 (worker name ThreadSafeWrapper), a synchronous thread-safe file seek wrapper: it acquires the stream critical section on the stream handle a1 via StreamBufferLockViaCriticalSection (0x0058C1B1), performs the seek by forwarding (a1,a2,a3,a4) to FileSeekWithModeFlagValidation (0x0059C156), releases the critical section via AddressRangeCriticalSectionLeave (0x0058C203), and returns the seek result unchanged. This is the seek counterpart of the thread-safe stream read wrapper (0x0058803F) already grouped in this scope's sibling packets; both reuse the same lock pair. The packet owner is UnknownObject/UNKNOWN and the only caller FileIOForwardingWrapper (0x0059BAE8) is not analyzed, so the class grouping ThreadSafeStreamSeek and the state machine are GUESS/DERIVED synthesis over the lock-seek-unlock sequencing, not recovered original source.

## Function roles

- `0x0059C127` **ThreadSafeStreamSeek** — Synchronous thread-safe seek wrapper: acquires the stream lock via StreamBufferLockViaCriticalSection(a1), performs the seek by forwarding (a1,a2,a3,a4) to FileSeekWithModeFlagValidation (0x0059C156), releases via AddressRangeCriticalSectionLeave(a1), and returns the inner seek result v4 unchanged.

## Proposed classes

### ThreadSafeStreamSeek

Synchronous thread-safe seek primitive over a locked stream: lock the stream handle (0x0058C1B1), forward the seek (a1,a2,a3,a4) to the inner seek implementation (0x0059C156), unlock (0x0058C203), and return the seek result. Seek counterpart of the thread-safe stream read wrapper.

Methods: `0x0059C127`


## Compatibility contracts

- **ThreadSafeStreamSeekContract** — A thread-safe synchronous seek must acquire the stream lock on a1 (0x0058C1B1), forward (a1,a2,a3,a4) to the inner seek (0x0059C156), release the lock on a1 (0x0058C203) and return the inner seek result unchanged. The stream handle a1 is opaque to the wrapper; a2-a4 are seek parameters whose exact semantics (mode flag validation) are not established by this packet.

## Unresolved

- a1 is an opaque stream handle; a2-a4 are seek parameters whose exact semantics (mode flag validation) are not established.
- FileSeekWithModeFlagValidation (0x0059C156) is not analyzed in this packet.
- The caller FileIOForwardingWrapper (0x0059BAE8) is not analyzed; the calls_into dependency from it to 0x0059C127 is GUESS.
- The packet owner is UnknownObject with UNKNOWN trust; the ThreadSafeStreamSeek class grouping is a GUESS aggregation over the evidenced lock-seek-unlock sequence, not a recovered original class.
