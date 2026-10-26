int __thiscall sub_5BA970(SOCKET *this)
{
  int result; // eax
  int v3; // eax
  int fromlen; // [esp+4h] [ebp-14h] BYREF
  struct sockaddr from; // [esp+8h] [ebp-10h] BYREF

  fromlen = 16;
  result = this[47];
  if ( result )
  {
    while ( 1 )
    {
      result = sub_5BDC00(*this);
      if ( !result )
        break;
      v3 = recvfrom(*this, buf, 255, 0, &from, &fromlen);
      if ( v3 != -1 )
      {
        buf[v3] = 0;
        sub_5BACC0(v3, &from);
      }
    }
  }
  return result;
}
