int __fastcall sub_5BC220(char *a1, const char *a2, const char *a3, u_long hostlong, int a5)
{
  const char *v5; // ebx
  const char *v7; // ebp
  int result; // eax
  u_short v9; // ax
  SOCKET v10; // ecx
  int v11; // eax
  void *v12; // eax
  u_short hostshort[2]; // [esp+10h] [ebp-308h] BYREF
  char *v14; // [esp+14h] [ebp-304h]
  char buf[2]; // [esp+18h] [ebp-300h] BYREF
  char v16; // [esp+1Ah] [ebp-2FEh] BYREF

  v5 = a2;
  if ( !a2 )
    v5 = &byte_629120;
  v7 = a3;
  if ( !a3 )
    v7 = &byte_629120;
  if ( strlen(v5) > 0x100 )
    return 6;
  if ( strlen(v7) > 0x100 )
    return 6;
  result = sub_5BC450(a1);
  if ( !result )
  {
    *((_DWORD *)a1 + 365) = hostlong;
    sub_5BC630(a1);
    *(_DWORD *)hostshort = 2;
    v14 = &v16;
    sub_5BC5B0(hostshort);
    sub_5BC5B0(hostshort);
    sub_5BC5B0(hostshort);
    sub_5BC5D0(hostshort);
    sub_5BC560(hostshort);
    sub_5BC560(hostshort);
    sub_5BC5F0(8, hostshort);
    sub_5BC560(hostshort);
    sub_5BC560(hostshort);
    htonl(hostlong);
    sub_5BC5D0(hostshort);
    if ( (a1[1460] & 8) != 0 )
      sub_5BC5D0(hostshort);
    if ( a1[1460] < 0 )
      sub_5BC5D0(hostshort);
    v9 = htons(hostshort[0]);
    v10 = *((_DWORD *)a1 + 296);
    *(_WORD *)buf = v9;
    if ( send(v10, buf, *(int *)hostshort, 0) <= 0 )
    {
      sub_5BC800(a1);
      return 3;
    }
    v11 = *((_DWORD *)a1 + 29);
    *(_DWORD *)a1 = 3;
    *((_DWORD *)a1 + 366) = 0;
    if ( !v11 )
    {
      v12 = malloc(0x1000u);
      *((_DWORD *)a1 + 29) = v12;
      if ( !v12 )
        return 5;
      *((_DWORD *)a1 + 30) = 0;
    }
    return 0;
  }
  return result;
}
