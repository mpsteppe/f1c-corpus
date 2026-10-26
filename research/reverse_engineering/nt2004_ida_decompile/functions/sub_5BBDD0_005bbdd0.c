int __thiscall sub_5BBDD0(_DWORD *this)
{
  int result; // eax
  int v3; // edx
  int fromlen; // [esp+Ch] [ebp-848h] BYREF
  struct sockaddr from; // [esp+10h] [ebp-844h] BYREF
  char buf[2100]; // [esp+20h] [ebp-834h] BYREF

  fromlen = 16;
LABEL_2:
  while ( 1 )
  {
    result = sub_5BDC00(this[8]);
    if ( !result )
      return result;
    result = recvfrom(this[8], buf, 2099, 0, &from, &fromlen);
    if ( result == -1 )
      return result;
    v3 = this[2];
    buf[result] = 0;
    if ( v3 )
    {
      while ( (*(_DWORD *)v3 != *(_DWORD *)&from.sa_data[2] || *(_WORD *)(v3 + 4) != *(_WORD *)from.sa_data)
           && (*(_DWORD *)v3 != this[9]
            || (*(_BYTE *)(v3 + 21) & 2) == 0
            || *(_DWORD *)(v3 + 8) != *(_DWORD *)&from.sa_data[2]
            || *(_WORD *)(v3 + 12) != *(_WORD *)from.sa_data) )
      {
        v3 = *(_DWORD *)(v3 + 32);
        if ( !v3 )
          goto LABEL_2;
      }
      if ( *this == 1 )
        sub_5BBE90(buf, result);
      else
        sub_5BBFB0(buf, result);
    }
  }
}
