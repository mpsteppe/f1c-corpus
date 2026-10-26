int __fastcall sub_5BC6D0(int *a1, u_short a2, u_short a3, int a4)
{
  int v6; // eax
  SOCKET v7; // eax
  u_short v9; // bx
  char optval[4]; // [esp+Ch] [ebp-1Ch] BYREF
  char v11[8]; // [esp+10h] [ebp-18h] BYREF
  struct sockaddr to; // [esp+18h] [ebp-10h] BYREF

  v6 = *a1;
  *(_DWORD *)optval = 1;
  v11[0] = -2;
  v11[1] = -3;
  v11[2] = 2;
  v11[3] = 0;
  v11[4] = 0;
  v11[5] = 0;
  v11[6] = 0;
  v11[7] = 0;
  if ( v6 != 1 )
    sub_5BC800(a1);
  v7 = socket(2, 2, 17);
  a1[296] = v7;
  if ( v7 == -1 )
    return 1;
  if ( setsockopt(v7, 0xFFFF, 32, optval, 4) )
    return 1;
  to.sa_family = 2;
  v9 = a3;
  *(_DWORD *)&to.sa_data[2] = -1;
  if ( a3 - a2 > 500 )
    v9 = a2 + 500;
  for ( ; a2 <= v9; ++a2 )
  {
    *(_WORD *)to.sa_data = htons(a2);
    if ( a4 == 1 )
      sendto(a1[296], v11, 8, 0, &to, 16);
    else
      sendto(a1[296], aEchoTest, 10, 0, &to, 16);
  }
  *a1 = 0;
  a1[297] = GetTickCount();
  return 0;
}
