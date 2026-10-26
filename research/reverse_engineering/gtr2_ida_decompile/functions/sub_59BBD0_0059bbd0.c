const char *__usercall sub_59BBD0@<eax>(int Error@<eax>)
{
  const char *result; // eax

  if ( Error == -1 )
    Error = WSAGetLastError();
  switch ( Error )
  {
    case 10004:
      result = "A blocking Windows Sockets 1.1 call was canceled through WSACancelBlockingCall.";
      break;
    case 10009:
      result = "For Windows CE AF_IRDA sockets only: the shared serial port is busy.";
      break;
    case 10013:
      result = "The requested address is a broadcast address, but the appropriate flag was not set. Call setsockopt with "
               "the SO_BROADCAST parameter to allow the use of the broadcast address. ";
      break;
    case 10014:
      result = "The name or the namelen parameter is not a valid part of the user address space, the namelen parameter is"
               " too small, or the name parameter contains incorrect address format for the associated address family.";
      break;
    case 10022:
      result = "error code = WSAEINVAL";
      break;
    case 10024:
      result = "No more socket descriptors are available.";
      break;
    case 10035:
      result = "The socket is marked as nonblocking and the requested operation would block.";
      break;
    case 10036:
      result = "A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.";
      break;
    case 10037:
      result = "A nonblocking connect call is in progress on the specified socket. Note In order to preserve backward com"
               "patibility, this error is reported as WSAEINVAL to Windows Sockets 1.1 applications that link to either W"
               "insock.dll or Wsock32.dll.";
      break;
    case 10038:
      result = "The descriptor is not a socket.";
      break;
    case 10039:
      result = "A destination address is required.";
      break;
    case 10040:
      result = "The socket is message oriented, and the message is larger than the maximum supported by the underlying transport.";
      break;
    case 10041:
      result = "The specified protocol is the wrong type for this socket.";
      break;
    case 10043:
      result = "The specified protocol is not supported.";
      break;
    case 10044:
      result = "The specified socket type is not supported in this address family.";
      break;
    case 10045:
      result = "MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not suppo"
               "rted in the communication domain associated with this socket, or the socket is unidirectional and support"
               "s only receive operations.";
      break;
    case 10047:
      result = "The specified address family is not supported.";
      break;
    case 10048:
      result = "The socket's local address is already in use and the socket was not marked to allow address reuse with SO"
               "_REUSEADDR. This error usually occurs when executing bind, but could be delayed until this function if th"
               "e bind was to a partially wildcard address (involving ADDR_ANY) and if a specific address needs to be com"
               "mitted at the time of this function.";
      break;
    case 10049:
      result = "The remote address is not a valid address (such as ADDR_ANY).";
      break;
    case 10050:
      result = "The network subsystem or the associated service provider has failed.";
      break;
    case 10051:
      result = "The network cannot be reached from this host at this time.";
      break;
    case 10052:
      result = "The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. ";
      break;
    case 10053:
      result = "The virtual circuit was terminated due to a time-out or other failure. The application should close the s"
               "ocket as it is no longer usable.";
      break;
    case 10054:
      result = "The virtual circuit was reset by the remote side executing a hard or abortive close. For UDP sockets, the"
               " remote host was unable to deliver a previously sent UDP datagram and responded with a \"Port Unreachable"
               "\" ICMP packet. The application should close the socket as it is no longer usable.";
      break;
    case 10055:
      result = "No buffer space is available. The socket cannot be created.";
      break;
    case 10057:
      result = "The socket is not connected (connection-oriented sockets only).";
      break;
    case 10058:
      result = "The socket has been shut down; it is not possible to sendto on a socket after shutdown has been invoked w"
               "ith how set to SD_SEND or SD_BOTH.";
      break;
    case 10060:
      result = "The connection has been dropped, because of a network failure or because the system on the other end went"
               " down without notice.";
      break;
    case 10061:
      result = "The attempt to connect was forcefully rejected.";
      break;
    case 10065:
      result = "The remote host cannot be reached from this host at this time. ";
      break;
    case 10093:
      result = "A successful WSAStartup call must occur before using this function";
      break;
    default:
      result = "WSAGetLastError() returned an unknown value.";
      break;
  }
  return result;
}
