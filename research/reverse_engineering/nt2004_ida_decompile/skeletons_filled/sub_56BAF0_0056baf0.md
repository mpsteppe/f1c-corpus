## sub_56BAF0_0056baf0 — NetworkMultiplayerMessageDispatcher

**Summary:** Dispatches incoming network multiplayer messages by parsing a prefix-keyed protocol: handles server-advertise responses, connection-request handshakes, and session-state changes, creating UDP sockets, sending response datagrams, and updating local multiplayer state via mutex-protected operations.

**Called by:** sub_56C740 (0056c740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x58 | R | — | vtable function pointer: called to get multiplayer context object |
| this | 0x0 | R | — | vtable pointer for virtual dispatch |
| this | 0x5D | R | — | byte flag: determines response variant (affects value sent as v12) |
| this | 0x5C4 | RW | 1 | mutex handle for thread-safe state access |
| this | 0x5C8 | RW | 0 | mutex handle for thread-safe state access |
| this | 0x618 | R | — | pointer to linked-list or object used for node removal |
| this | 0x61C | R | — | related pointer for linked-list operations |
| this | 0x640 | R | — | pointer to string or object identifier |
| this | 0x644 | R | — | related pointer for identifier operations |
| this | 0x910 | R | — | UDP socket descriptor for send operations (offset 0x2364) |
| this | 0x938 | R | — | socket descriptor for getsockname (offset 0x2360) |
| this | 0x93C | R | — | local port base value for dynamic port binding (offset 0x2320) |
| this | 0xBE4 | R | — | mutex handle for state protection (offset 0x3052) |
| this | 0xBEC | RW | 0 | mutex timeout/duration value (offset 0x3056) |
| this | 0xBF0 | R | — | pointer to connection state/object (offset 0x305A) |

**Written-by note (persistence):**
- this 0x5C4: conditionally written during connect; external poke may be overwritten by subsequent connect
- this 0x5C8: conditionally written during connect; external poke may be overwritten by subsequent connect
- this 0xBEC: written once (set to 0); external poke would survive until next init

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0056c388 | jpt_56C308 | R | jump table for switch-case dispatch on message type |
| 005d3b59 | SEH_56BAF0 | R | structured exception handler registration |
| 005d513c | Sleep | R | Win32 Sleep import for retry delay |
| 005d516c | WaitForSingleObject | R | Win32 mutex wait |
| 005d5170 | ReleaseMutex | R | Win32 mutex release |
| 005d5368 | __imp_htonl | R | Winsock host-to-network long |
| 005d536c | __imp_getsockname | R | Winsock get local socket address |
| 005d5370 | getpeername | R | Winsock get remote peer address |
| 005d5374 | __imp_ntohs | R | Winsock network-to-host short |
| 005d537c | WSAGetLastError | R | Winsock error code |
| 005d5380 | __imp_connect | R | Winsock TCP connect |
| 005d5384 | __imp_sendto | R | Winsock UDP sendto |
| 005d5398 | __imp_htons | R | Winsock host-to-network short |
| 0060217c | aSSD | R | "%s%s%d" format string |
| 0061a1ec | off_61A1EC | R | message prefix string #1 (server-advertise/list prefix) |
| 0061a1f4 | off_61A1F4 | R | message sub-prefix for request-match type |
| 0061a1f8 | off_61A1F8 | R | message prefix string #2 (connect-request prefix) |
| 0061a1fc | off_61A1FC | R | message prefix string #3 (session-state-change prefix) |
| 0061a25c | aD_5 | R | "%d %[^" format string for sscanf |
| 0061a268 | aDDDDDD | R | format string with IP:port parsing |
| 0061a27c | aSSDDDDDD | R | "%s%s %d %d.%d.%d.%d:%d" format string |
| 0061a294 | aS_11 | R | " (%s)" format string for display name |
| 007e0600 | byte_7E0600 | RW | cached-flag: bit 0 set after first strlen of off_61A1EC |
| 007e0604 | dword_7E0604 | RW | cached length of off_61A1EC prefix string |
| ff00000000005e85 | byte_FF00000000005E85 | W | unknown — written in some path |
| ff00000000005e86 | byte_FF00000000005E86 | RW | unknown — read/written in message handling |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414470 | ShortComputation_a780 [exact] | initializes/resets a 16-byte struct at connection state |
| 0056acd0 | NetworkPacketConstructor [structural] | builds a network packet and queues it for sending |
| 0056b260 | F_16ByteStructCopy [exact] | copies 16 bytes (socket address struct) |
| 0056b280 | PointerAdvance [exact] | returns a pointer into the connection object at computed offset |
| 0056b2a0 | Setter [exact] | stores the socket descriptor into the connection state |
| 0056bad0 | NetworkSocketCreate [exact] | creates a new UDP/TCP socket |
| 0056c3a0 | SocketBindPortScan [exact] | binds socket to a specific port with scanning logic |
| 0056c4d0 | SocketGracefulClose [exact] | gracefully closes a socket |
| 0056dc20 | sub_56DC20 | activates/registers the new connection with event handlers |
| 00571810 | LinkedListNodeRemovalByValue [structural] | removes a node from a linked list by pointer value |
| 00572ea0 | LinkedListNodeRemovalWithCleanupCallback [structural] | removes and cleans up a node from linked list |
| 005730b0 | sub_5730B0 | allocates/initializes a new connection node (operator new wrapper) |
| 00573530 | sub_573530 | initializes a newly allocated connection node |
| 00574ce0 | ThreadSafeCallWithMutex [structural] | dispatches a call through a mutex-protected context |
| 00575090 | ArithmeticComparison_5020 [exact] | comparison/status check on network state |
| 00575290 | StatusCheckViaVTableDispatch [exact] | checks session state via virtual dispatch |
| 00575d40 | ThreadSafeWriteWithMutex [exact] | writes a value to shared state under mutex protection |
| 00575d90 | MutexProtectedPointerReadRelease [exact] | reads a value from shared state and releases mutex |
| 00576880 | sub_576880 | sends a network event/message with type and parameters |
| 00576a80 | sub_576A80 | sends address data over network |
| 00577170 | FieldResetWithSubCall [structural] | resets a field and calls a sub-function on shared state |
| 005be8e3 | ??2@YAPAXI@Z | C++ operator new |
| 005beab0 | _strncpy | copies string with length limit |
| 005bee90 | _strncmp | compares strings with length limit |
| 005beec8 | _sprintf | formats output strings |
| 005bf71b | _sscanf | parses formatted input strings |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x5D | != | 0 | byte flag: when non-zero, response variant value is 4 - flag_value; when zero, response variant is 2 |

**Guard interpretation:** The byte at `this+0x5D` acts as a mode selector for outbound response messages. When the flag is non-zero (true), the response code sent to the server is `4 - flag` (i.e., 3 when flag=1). When the flag is zero (false), the response code defaults to 2. This affects what state the remote server transitions to after receiving the response.

Additional guards: `strncmp` prefix checks route messages to three handlers based on matching `off_61A1F4`, `off_61A1F8`, or `off_61A1FC` prefixes. `sub_575D90(this) == 4` for the first handler, `== 1` for the second and third. The connect loop retries on `WSAGetLastError() == 10048` (address in use) up to 50 times with 10ms sleep between attempts.

**String literals referenced (deterministic):**

- `%s%s%d`
- `%d %[^`
- ` %d %d.%d.%d.%d:%d`
- `%s%s %d %d.%d.%d.%d:%d`
- ` (%s)`
