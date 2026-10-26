int __thiscall sub_561E30(SOCKET *this)
{
  int result; // eax
  SOCKET v3; // eax
  int v4; // eax
  int fromlen; // [esp+8h] [ebp-120h] BYREF
  timeval timeout; // [esp+Ch] [ebp-11Ch] BYREF
  struct sockaddr from; // [esp+14h] [ebp-114h] BYREF
  fd_set readfds; // [esp+24h] [ebp-104h] BYREF

  fromlen = 16;
  timeout.tv_sec = 0;
  result = this[57];
  timeout.tv_usec = 0;
  if ( result )
  {
    v3 = *this;
    readfds.fd_count = 1;
    readfds.fd_array[0] = v3;
    while ( 1 )
    {
      result = select(64, &readfds, 0, 0, &timeout);
      if ( result == -1 || !result )
        break;
      v4 = recvfrom(*this, buf, 255, 0, &from, &fromlen);
      if ( v4 != -1 )
      {
        buf[v4] = 0;
        sub_5622C0(v4, &from);
      }
    }
  }
  return result;
}
