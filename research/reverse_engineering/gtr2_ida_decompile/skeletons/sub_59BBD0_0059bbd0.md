## sub_59BBD0_0059bbd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_59C960 (0059c960), sub_5A19D0 (005a19d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059bcb8 | jpt_59BBF0 | R | [LLM] |
| 0059bd38 | byte_59BD38 | R | [LLM] |
| 006f15bc | WSAGetLastError | R | [LLM] |
| 00725294 | aWsagetlasterro_0 | R | [LLM] |
| 007252c8 | aTheConnectionH_0 | R | [LLM] |
| 00725348 | aTheNetworkCann | R | [LLM] |
| 00725384 | aADestinationAd | R | [LLM] |
| 007253a8 | aTheVirtualCirc_0 | R | [LLM] |
| 007254d0 | aTheVirtualCirc | R | [LLM] |
| 00725560 | aTheRemoteHostC | R | [LLM] |
| 007255a0 | aTheSocketIsMes | R | [LLM] |
| 00725618 | aTheSocketIsMar | R | [LLM] |
| 00725668 | aTheSocketHasBe | R | [LLM] |
| 007256f8 | aMsgOobWasSpeci | R | [LLM] |
| 007257e8 | aTheDescriptorI | R | [LLM] |
| 00725808 | aTheSocketIsNot | R | [LLM] |
| 00725848 | aTheConnectionH | R | [LLM] |
| 007258c0 | aABlockingWindo_0 | R | [LLM] |
| 00725910 | aTheRequestedAd | R | [LLM] |
| 007259c0 | aForWindowsCeAf | R | [LLM] |
| 00725a08 | aTheSpecifiedSo | R | [LLM] |
| 00725a4c | aTheSpecifiedPr_0 | R | [LLM] |
| 00725a88 | aErrorCodeWsaei | R | [LLM] |
| 00725aa0 | aTheNameOrTheNa | R | [LLM] |
| 00725b70 | aTheAttemptToCo | R | [LLM] |
| 00725ba0 | aTheSpecifiedPr | R | [LLM] |
| 00725bcc | aNoBufferSpaceI | R | [LLM] |
| 00725c08 | aNoMoreSocketDe | R | [LLM] |
| 00725c34 | aTheRemoteAddre | R | [LLM] |
| 00725c78 | aANonblockingCo | R | [LLM] |
| 00725d68 | aABlockingWindo | R | [LLM] |
| 00725de0 | aTheSpecifiedAd | R | [LLM] |
| 00725e10 | aTheSocketSLoca | R | [LLM] |
| 00725f70 | aTheNetworkSubs | R | [LLM] |
| 00725fb8 | aASuccessfulWsa | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `WSAGetLastError() returned an unknown value.`
- `The connection has been dropped, because of a network failure or because the system on the other end went down without notice.`
- `The network cannot be reached from this host at this time.`
- `A destination address is required.`
- `The virtual circuit was reset by the remote side executing a hard or abortive close. For UDP sockets, the remote host was unable to deliver a previously sent UDP datagram and responded with a "Port Unreachable" ICMP packet. The application should close the socket as it is no longer usable.`
- `The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable.`
- `The remote host cannot be reached from this host at this time. `
- `The socket is message oriented, and the message is larger than the maximum supported by the underlying transport.`
- `The socket is marked as nonblocking and the requested operation would block.`
- `The socket has been shut down; it is not possible to sendto on a socket after shutdown has been invoked with how set to SD_SEND or SD_BOTH.`
- `MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only receive operations.`
- `The descriptor is not a socket.`
- `The socket is not connected (connection-oriented sockets only).`
- `The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. `
- `A blocking Windows Sockets 1.1 call was canceled through WSACancelBlockingCall.`
- `The requested address is a broadcast address, but the appropriate flag was not set. Call setsockopt with the SO_BROADCAST parameter to allow the use of the broadcast address. `
- `For Windows CE AF_IRDA sockets only: the shared serial port is busy.`
- `The specified socket type is not supported in this address family.`
- `The specified protocol is the wrong type for this socket.`
- `error code = WSAEINVAL`
- … +12 more
