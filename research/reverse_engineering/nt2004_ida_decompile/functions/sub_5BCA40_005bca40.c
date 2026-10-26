int __thiscall sub_5BCA40(_DWORD *this)
{
  _DWORD *v2; // edi
  __int64 v3; // rax
  int fromlen; // [esp+8h] [ebp-208h] BYREF
  struct sockaddr from; // [esp+Ch] [ebp-204h] BYREF
  char buf[500]; // [esp+1Ch] [ebp-1F4h] BYREF

  fromlen = 16;
  while ( sub_5BDC00(this[296]) )
  {
    if ( recvfrom(this[296], buf, 499, 0, &from, &fromlen) != -1 && sub_5BD940(*(__int16 *)from.sa_data) == -1 )
    {
      v2 = sub_5BA500((int)this, *(int *)&from.sa_data[2], *(__int16 *)from.sa_data);
      LODWORD(v3) = sub_5BA600(v2);
      if ( (_DWORD)v3 )
        return 5;
      BYTE4(v3) = 17;
      sub_5BA5B0(v3, (int)v2);
      sub_5BD910(this, v2);
    }
  }
  if ( GetTickCount() - this[297] > 0x7D0 )
  {
    closesocket(this[296]);
    this[296] = -1;
    *this = 1;
  }
  return 0;
}
