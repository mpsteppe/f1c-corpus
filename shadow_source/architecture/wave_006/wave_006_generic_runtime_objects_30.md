# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime-object layer from thirty validated functions. The dominant cluster is GameSpy network plumbing: UDP bind-and-connect to the master server (0x00561BF0), TCP connect (0x00562D90), UDP broadcast socket setup (0x00563080), heartbeat sending (0x00562AC0, DERIVED owner NetworkHeartbeatSender), host/port parsing (0x005642B0), keyed string dispatch (0x00564530) and address resolution (0x005644B0), plus plain Winsock/Sleep/GetTickCount import thunks. A second cluster holds generic helpers: a 24-byte descriptor allocator (0x00564810), base64 encoder (0x00564B80), RC4 cipher (0x00564C70), callback-driven lookup (0x005647D0), comparator binary search (0x00564B10), and two thin delegation wrappers (0x00564A00, 0x00564960). The third cluster is vehicle-physics support: impulse/torque accumulation (0x00569670, 0x00569A20, 0x00569AD0), pre-constraint velocity update (0x0056A240), matrix rotation + Euler extraction (0x00567340), cross-product/normal (0x0056C540), triangle normal (0x0056C640), sparse triangular solve (0x0056CD70), and two-body relative velocity (0x0056D1C0). Two GUESS classes are proposed: NetworkSocket (socket handle at +0x88, from 0x00562D90 and 0x00563080) and RigidBodyState (momentum/inertia/torque block shared by the four impulse/constraint functions). Owner identity is largely UNKNOWN; several field-semantics contradictions are documented rather than forced. No state-machine evidence was found.

## Function roles

- `0x00561BF0` **UnknownObject** — UDP master-server connect: creates a UDP datagram socket (AF_INET/SOCK_DGRAM/IPPROTO_UDP) after NetworkStartup (0x00564660), builds the sockaddr per candidate port via 0x00562010, zeroes the address field when the resolved host is loopback, binds to the first available port in [hostshort, hostshort+100], prepares the socket object via 0x00561D40, and completes the master connection via 0x00561FF0. Returns 1 on socket-creation failure, 2 on bind/getsockname failure; caller 0x0045CD70.
- `0x00562AC0` **NetworkHeartbeatSender** — UDP heartbeat sender: composes the header '\heartbeat\%d\gamename\%s' (format 0x005E4ED8) from game id at this+228 and game name at this+8, appends '\statechanged\%d' (format 0x005E4EC4) when flagged, sends via sendto (0x00598672) through the socket at this+4 against the peer sockaddr at this+236, then records GetTickCount() (0x00564640) at this+216 and returns it; invoked by 0x00561ED0 for inactivity/timeout handling.
- `0x00562C80` **UnknownObject** — Trivial forwarding stub: calls DeviceInitializationWithStateSetup (0x00562C90) with constant arguments 0 and 5 and returns its result; called by StartNetworkUpdate (0x00461DE0).
- `0x00562D90` **NetworkSocket** — TCP socket connect: builds an AF_INET sockaddr for the host string at 0x005E4EF8 on port 0x70E4 (28900) via htons/inet_addr with a gethostbyname (0x00598660) fallback, creates a TCP stream socket storing the handle at this+0x88, and connects; returns 0 success, 1 socket failure, 2 resolution failure, 3 connect failure (socket closed first); called by DeviceInitializationWithStateSetup (0x00562C90).
- `0x00563080` **NetworkSocket** — UDP broadcast socket setup: creates a UDP datagram socket (AF_INET/SOCK_DGRAM/IPPROTO_UDP), stores the handle at this+0x88, and enables SO_BROADCAST via setsockopt(0xFFFF, 32, optval=1, 4) (0x0059868A); returns 1 when socket() returns -1 or setsockopt fails, else 0; invoked in the initialization chain by 0x00563020.
- `0x00564220` **UnknownObject** — Stateful single-byte-delimiter tokenizer (strtok-like) over shared scan-state global dword_8CFAE4: a non-null a1 becomes the new scan state, else the prior position is reloaded; scans to the delimiter or string end, overwrites the delimiter with NUL, advances the saved state past it, and returns the token pointer (NULL when the scan never advanced); shared by callers 0x00564110 and 0x00564390.
- `0x005642B0` **UnknownObject** — Host:port address parser: locates ':' via 0x00589DB0, null-terminates the string to split host and port, stores inet_addr(host) into the dword at a1 and the low word of the parsed port (via 0x00587F59) into the word at a1+4; returns the parsed port, or the null delimiter result when no ':' is present; invoked by 0x00564110.
- `0x00564410` **UnknownObject** — String-membership check against the two string globals aQueryid (0x005E505C, 'queryid') and aFinal_0 (0x005E5054, 'final'): returns 0 when the argument equals either entry, 1 when it matches neither; called by AudioMixerPollingUpdateLoop (0x00564390).
- `0x00564490` **UnknownObject** — Thin inet_ntoa (0x00598696) wrapper: reads the 4-byte in_addr at this+0x0 by value and returns the dotted-quad char*; no other fields touched; callers SendJoinRequest (0x00462C00), 0x00563AB0 and 0x005644B0.
- `0x005644B0` **UnknownObject** — Address/hostname-to-string resolver: when the name equals the aHostaddr literal (0x005E5064) formats the in_addr via IPAddressToString (0x00564490); otherwise resolves through DoubleCallWrapper (0x005644F0) and returns the char* at result+4, falling back to argument a3 when the result is null; callers 0x00564000 and 0x00564090.
- `0x00564530` **UnknownObject** — String-keyed dispatch: if the key equals the 'ping' literal (0x005C61EC) returns ShortToIntFieldGetter(a1) (0x00564480); otherwise dispatches through DoubleCallWrapper (0x005644F0) and returns SingleFunctionCallWrapper_7f59(v4[1]) (0x00587F59), falling back to default a3 when the wrapper returns null; used by SendJoinRequest (0x00462C00) and 0x00563F20.
- `0x00564640` **UnknownObject** — Compiler-generated import thunk for the Win32 GetTickCount API, forwarding through IAT slot __imp_GetTickCount (0x0059E0D4); used for elapsed-time measurement by 0x00561ED0, 0x00562AC0, 0x005630D0, 0x00563410 and 0x00563AB0.
- `0x00564650` **UnknownObject** — Thin wrapper forwarding its dwMilliseconds argument to the imported Sleep function (0x0059E0DC); no state of its own.
- `0x00564680` **UnknownObject** — Forwarding thunk (__stdcall) calling the Winsock WSACleanup() library routine and returning its result; provides a stable binary-local indirection point for teardown callers.
- `0x005647D0` **UnknownObject** — Callback-driven lookup helper: invokes the callback stored at a1+12 (fastcall) with a2 and the dword at a1+4, uses the integer result as an index into the dword table at a1[0], computes a buffer index via BufferIndexComputation(*(a1+16), 0, 0) (0x00564A20), and returns LinearInterpolation (0x005648B0) of the selected entry and that index; returns 0 when the buffer-index computation fails.
- `0x00564810` **UnknownObject** — Descriptor + inner-buffer allocator: allocates a 24-byte descriptor via MallocWrapperForNhMalloc (0x0058A935), defaults element size a2 to 8 when zero, stores element count a1 at dword index 2 (+0x8), zeroes index 0, stores a2 at indices 1 and 3, a3 at index 4 (+0x10), and the a2*a1-byte inner buffer pointer at index 5 (+0x14); used by 0x00562B50, 0x00563E00 and 0x005646D0.
- `0x00564960` **AudioStackBufferPool** — Struct-buffer copy into a destination located by LinearInterpolation(a1, a3) (0x005648B0), with the copy length read from a struct field at offset +8 of an implicit pointer (v4/ecx); returns the byte count; owner prelabeled AudioStackBufferPool (DERIVED); callers 0x005648D0 and 0x005649D0.
- `0x00564A00` **UnknownObject** — Thin delegation reading DWORD fields at indexes 0, 2 and 5 of argument a1 and forwarding them plus a2 to sub_5890AA (0x005890AA), returning its result unchanged.
- `0x00564B10` **UnknownObject** — Binary search over a3 elements at pointer a2 with stride a4 using callback comparator a5(element, a1): the found-flag at *a6 starts 0 and is set to 1 on an exact match; negative comparator results move the lower bound above the midpoint, zero/positive results move the upper bound below it; returns a2 + a4*v7 at the terminal lower-bound index.
- `0x00564B80` **UnknownObject** — Base64 encoder of up to a2 bytes from input a1 into output a3: consumes bytes in groups of three, zero-pads a partial trailing group, converts each 6-bit index via Base64IndexToCharEncoding (0x00564C40), null-terminates the output, and returns the last produced character; called by 0x00562E30.
- `0x00564C70` **UnknownObject** — RC4 stream cipher: initializes a 256-byte S-box to identity, runs the key-scheduling algorithm over key a1 of length a2, generates keystream and XORs it into buffer a3 for a4 bytes, returning a4; the swap primitive is ByteSwap at 0x005622B0; neighbor of caller 0x00562E30.
- `0x00567340` **UnknownObject** — Matrix rotation + Euler extraction: right-multiplies a 3x3 row-major float matrix (this) by an X-axis rotation (sin/cos of a2; column 0 unchanged at 0x0/0xC/0x18), applies FloatConvertWrapper (0x00588570) in place, then extracts Euler angles into a3; the gimbal-lock branch (fabs(this[5] at +0x14) == 1.0, constant 0x0059E420) writes zero at a3+8 plus atan2(-this[6], this[0]); the regular branch writes atan2 values from elements [0][2]/[2][2] (0x8/0x20) and [1][0]/[1][1] (0xC/0x10); a3+0 receives the negative pre-conversion this[5].
- `0x00569670` **RigidBodyState** — Contact impulse accumulation into rigid-body state: scales impulse a2 by this+0xB4 and adds it into linear momentum (+0x64/+0x6C/+0x74), accumulates the cross-product terms of a2 with contact offset a3 into angular momentum (+0x94/+0x9C/+0xA4), then recomputes torque (+0x7C/+0x84/+0x8C) as world inertia (3x3 at +0xEC..+0x12C) times angular momentum; returns the a2 impulse pointer; invoked per contact by CollisionContactImpulse (0x004599C0).
- `0x00569A20` **RigidBodyState** — Impulse + torque application: accumulates impulse a3 into linear momentum (+0x134/+0x13C/+0x144), computes the lever arm as the difference between application point a2 and body position (+0x4/+0xC/+0x14), forms torque as the cross product of the lever arm and the impulse, and accumulates it into angular momentum (+0x14C/+0x154/+0x15C); returns the impulse vector pointer; no branches, globals or calls.
- `0x00569AD0` **RigidBodyState** — Angular-momentum accumulation: adds impulse a3 into linear momentum (+0x134/+0x13C/+0x144) and accumulates the mixed-sign cross-product components of lever-arm a2 and impulse a3 into angular momentum (+0x14C/+0x154/+0x15C); returns the impulse vector pointer a3.
- `0x0056A240` **RigidBodyState** — Pre-constraint velocity update (per-frame, called by 0x0056ECF0): computes the gyroscopic torque as the cross of angular velocity (+0x7C/+0x84/+0x8C) and angular momentum (+0x94/+0x9C/+0xA4), subtracts it from applied torque (+0x14C/+0x154/+0x15C), multiplies the net torque by the world inverse inertia (+0xEC..+0x12C) for the angular-velocity delta, derives linear velocity as inverse mass (+0xB4) times linear momentum (+0x134/+0x13C/+0x144), then feeds both into constraint-prep helpers 0x0056A390, 0x0056A5D0, 0x0056A840, 0x0056AA60 and 0x0056B5D0; returns ConstraintStiffnessMatrixAssembly (0x0056BAF0).
- `0x0056C540` **UnknownObject** — Cross-product + rescale: computes a1 x a2 into a3 (doubles at this+0x0/+0x8/+0x10), then rescales a3 by dot(a1,a2)/|a3| with the dot product clamped to 1.0 (boundary constants 0x0059E420/0x0059E430); the rescale is skipped entirely when the cross product is zero; FloatFunctionPassThrough (0x005894A0) is called but has no visible effect.
- `0x0056C640` **UnknownObject** — Triangle face-normal computation: computes (a1 - a2) x (a3 - a2) into three doubles at a4 and normalizes by 1/sqrt(norm-squared); on degenerate input (norm-squared <= 0.0, zero sentinel 0x0059E430) writes the double pattern 0.0, 1.0, 0.0 (1.0 as dword 1072693248) and returns -1, else 0; used for collision contact face-normal computation on the frame path.
- `0x0056CD70` **UnknownObject** — Sparse triangular solver: forward substitution over rows 0..a4-1 followed by backward substitution from row a4-2 down to 0; row metadata is reached through the two pointer arrays at this+0x0 (forward) and this+0x4 (backward); each row subtracts the scaled contributions of its nonzero off-diagonal (byte-index/double-pair) entries from the workspace and divides by the diagonal (reciprocal numerator constant 0x0059E420); called by 0x0056ECF0 on the per-frame path.
- `0x0056D1C0` **UnknownObject** — Two-body relative-velocity magnitude: transforms each body's local velocity (3 doubles) into world space through its 3x3 rotation matrix plus translation (body A transform ptr this+0x4, velocity this+0x8; body B transform ptr this+0xC, velocity this+0x10; matrix rows read at this+0x28/0x30/0x38, +0x50/0x58/0x60, +0x68), takes the Euclidean norm of the world-space velocity difference with sqrt, and writes the magnitude into both bodies' velocity buffers at +56 (this-relative writes +0x40 and +0x48); returns the body B velocity pointer.

## Proposed classes

### NetworkSocket

Socket-handle holder at this+0x88 shared by the TCP connect path (0x00562D90) and the UDP broadcast-socket setup path (0x00563080); both create a Winsock socket and store the handle at +0x88. Merging the two is GUESS: both evidence the same this+0x88 socket field, but the packet does not prove a common owning class.

Methods: `0x00562D90`, `0x00563080`

- `this+0x00000088` `dword (SOCKET) socket_handle` (read_write, GUESS)

### NetworkHeartbeatSender

UDP heartbeat message sender (packet DERIVED owner of 0x00562AC0): composes and sends the heartbeat/statechanged message through the socket at +4 against the peer sockaddr at +236 and records the last-send tick at +216. Only the +4 socket field is representable as an allowed field ref; the +216/+228/+236 offsets are not in the packet's allowed field-ref set and are described textually.

Methods: `0x00562AC0`

- `this+0x00000004` `dword (SOCKET) socket_handle` (read, GUESS)

### RigidBodyState

Rigid-body dynamics state shared by the impulse/constraint accumulator functions: body position, linear and angular momentum accumulators, angular velocity/torque, world (inverse) inertia tensor, inverse mass/impulse scale, and applied torque. Field naming is GUESS - inferred from the arithmetic shape of 0x00569670, 0x00569A20, 0x00569AD0 and 0x0056A240; the packet does not name these fields and several offsets carry contradictory interpretations across functions.

Methods: `0x00569670`, `0x00569A20`, `0x00569AD0`, `0x0056A240`

- `this+0x00000004` `double position_x` (read, GUESS)
- `this+0x0000000C` `double position_y` (read, GUESS)
- `this+0x00000014` `double position_z` (read, GUESS)
- `this+0x00000064` `double linear_momentum_accum_a_x` (read_write, GUESS)
- `this+0x0000006C` `double linear_momentum_accum_a_y` (read_write, GUESS)
- `this+0x00000074` `double linear_momentum_accum_a_z` (read_write, GUESS)
- `this+0x0000007C` `double angular_velocity_or_torque_x` (read_write, GUESS)
- `this+0x00000084` `double angular_velocity_or_torque_y` (read_write, GUESS)
- `this+0x0000008C` `double angular_velocity_or_torque_z` (read_write, GUESS)
- `this+0x00000094` `double angular_momentum_x` (read_write, GUESS)
- `this+0x0000009C` `double angular_momentum_y` (read_write, GUESS)
- `this+0x000000A4` `double angular_momentum_z` (read_write, GUESS)
- `this+0x000000B4` `double inverse_mass_or_impulse_scale` (read, GUESS)
- `this+0x000000EC` `double world_inertia_0_0` (read, GUESS)
- `this+0x000000F4` `double world_inertia_0_1` (read, GUESS)
- `this+0x000000FC` `double world_inertia_0_2` (read, GUESS)
- `this+0x00000104` `double world_inertia_1_0` (read, GUESS)
- `this+0x0000010C` `double world_inertia_1_1` (read, GUESS)
- `this+0x00000114` `double world_inertia_1_2` (read, GUESS)
- `this+0x0000011C` `double world_inertia_2_0` (read, GUESS)
- `this+0x00000124` `double world_inertia_2_1` (read, GUESS)
- `this+0x0000012C` `double world_inertia_2_2` (read, GUESS)
- `this+0x00000134` `double linear_momentum_b_x` (read_write, GUESS)
- `this+0x0000013C` `double linear_momentum_b_y` (read_write, GUESS)
- `this+0x00000144` `double linear_momentum_b_z` (read_write, GUESS)
- `this+0x0000014C` `double angular_momentum_or_torque_x` (read_write, GUESS)
- `this+0x00000154` `double angular_momentum_or_torque_y` (read_write, GUESS)
- `this+0x0000015C` `double angular_momentum_or_torque_z` (read_write, GUESS)

## Compatibility contracts

- **UdpSocketBindAndConnect** — A replacement must create a UDP socket (AF_INET/SOCK_DGRAM/IPPROTO_UDP), bind it to the first available port in [hostshort, hostshort+100] (zeroing the sockaddr address field when the resolved host is loopback), prepare the socket object via 0x00561D40, complete the master-server connection via 0x00561FF0(socket, master-openspy, 27900, object+236), and return 1 on socket-creation failure or 2 on bind/getsockname failure.
- **TcpSocketConnectToMaster** — A replacement must create a TCP stream socket (AF_INET/SOCK_STREAM/IPPROTO_TCP) to the host at 0x005E4EF8 on port 0x70E4 (28900), resolving via inet_addr with gethostbyname fallback, storing the handle at this+0x88, and returning 0 on success, 1 on socket failure, 2 on resolution failure, 3 on connect failure (closing the socket first).
- **HeartbeatMessageFormat** — A replacement must send a UDP heartbeat built as '\heartbeat\%d\gamename\%s' (game id at +228, game name at +8) through the socket at +4 to the peer sockaddr at +236, optionally appending '\statechanged\%d' when flagged, then record GetTickCount() at +216.
- **RigidBodyImpulseAccumulation** — A replacement must accumulate a scaled contact impulse into linear momentum, accumulate cross-product (impulse x contact offset) terms into angular momentum, and recompute torque as world-inertia times angular-momentum at the documented offsets (linear +0x64/+0x6C/+0x74 or +0x134/+0x13C/+0x144, angular +0x94/+0x9C/+0xA4, torque +0x7C/+0x84/+0x8C, world inertia +0xEC..+0x12C, scale +0xB4); invoked per contact by 0x004599C0.
- **PreConstraintVelocityUpdate** — A replacement on the per-frame constraint path must compute net torque = applied torque (+0x14C/+0x154/+0x15C) minus gyroscopic cross(angular velocity +0x7C/+0x84/+0x8C, angular momentum +0x94/+0x9C/+0xA4), derive the angular-velocity delta via world inverse inertia (+0xEC..+0x12C), derive linear velocity as inverse mass (+0xB4) times linear momentum (+0x134/+0x13C/+0x144), feed both into the constraint-prep helpers 0x0056A390/0x0056A5D0/0x0056A840/0x0056AA60/0x0056B5D0, and return ConstraintStiffnessMatrixAssembly (0x0056BAF0).
- **RC4StreamCipher** — A replacement must implement standard RC4: initialize a 256-byte S-box to identity, run key scheduling over the key, then XOR the keystream into the data buffer for a4 bytes, returning a4.

## Unresolved

- Owner identity remains UNKNOWN for 0x00561BF0, 0x00562C80, 0x00564220, 0x005642B0, 0x00564410, 0x00564490, 0x005644B0, 0x00564530, 0x00564640, 0x00564650, 0x00564680, 0x005647D0, 0x00564810, 0x00564A00, 0x00564B10, 0x00564B80, 0x00564C70, 0x00567340, 0x0056C540, 0x0056C640, 0x0056CD70, 0x0056D1C0; no packet evidence constrains their owning classes.
- Contradiction: offset +0x7C/+0x84/+0x8C is written as recomputed torque by AccumulateContactImpulse (0x00569670) but read as angular velocity by PreConstraintVelocityUpdate (0x0056A240); the field name angular_velocity_or_torque records the unresolved dual interpretation.
- Contradiction: two distinct linear-momentum accumulator groups are evidenced - +0x64/+0x6C/+0x74 (0x00569670) and +0x134/+0x13C/+0x144 (0x00569A20, 0x00569AD0, 0x0056A240); whether they are the same body at different states or two separate accumulators is not established.
- The 3x3 at +0xEC..+0x12C is read as world inertia by 0x00569670 and as world inverse inertia by 0x0056A240; the physical meaning is not independently proven.
- SendHeartbeat fields at +216 (last-send tick), +228 (game id), +236 (peer sockaddr) and UdpSocketBindAndConnect's +236 field are evidenced only by call usage; those offsets are not in the packet's allowed field-ref set and are not represented as class fields.
- StringTokenizer's global dword_8CFAE4 is shared tokenizer state; the owning object that resets it between sessions is unknown.
- The two high-address byte writes global:0xFF00000000005430 and global:0xFF00000000005431 appear in packet evidence but never in the rendered raw source; their purpose is unresolved.
- 0x00567340's canonical name says Y-axis rotation but the observed math right-multiplies about the X axis; the naming discrepancy is unresolved.
- 0x00564B80's canonical name 'PadOutputWithSpacesUpToLengthLimit' describes space padding while the observed logic is base64 encoding; the output-consumer contract (caller 0x00562E30) decides which framing applies.
- 0x005647D0's callback/table layout (callback at +12, argument dword at +4, buffer-index source at +16, dword table at a1[0]) is caller-specific with no field names.
- 0x00564810's five descriptor dword roles are only structurally inferred; the meaning of the a2-to-8 default is unexplained.
- 0x0056CD70's sparse row-metadata layout behind *this and this[1] (nonzero-count byte at +1, entry pointer at +4) is only implied by the decompiled addressing.
- 0x00564960's v4 (ecx) is uninitialized in the decompiled body; the copy-length source at v4+8 cannot be pinned to a declared parameter or field.
- 0x0056D1C0's translation components and matrix row-2 y/z elements have no dedicated field evidence refs; fields 0x18/0x20 are read but map to no arithmetic.
- 0x00562D90's stored socket handle at +0x88 later use, and 0x00563080's broadcast-socket consumer, are established by callers (0x00562C90, 0x00563020), not by this packet.
- 0x0056C640's degenerate-branch output is interpreted by existing analysis as an identity quaternion, but the written byte pattern is doubles 0.0, 1.0, 0.0; component ordering is not established.
