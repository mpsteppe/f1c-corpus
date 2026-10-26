int __fastcall sub_5630D0(int a1, u_short a2, int a3, __int16 a4)
{
  u_short v4; // si
  u_short v6; // ax
  SOCKET v7; // ecx
  struct sockaddr to; // [esp+Ch] [ebp-10h] BYREF

  v4 = a2;
  to.sa_family = 2;
  for ( *(_DWORD *)&to.sa_data[2] = -1; v4 <= a3; v4 += a4 )
  {
    v6 = htons(v4);
    v7 = *(_DWORD *)(a1 + 136);
    *(_WORD *)to.sa_data = v6;
    sendto(v7, aStatus, 8, 0, &to, 16);
  }
  AudioValueSetterCall(a1, 2);
  *(_DWORD *)(a1 + 140) = GetTickCount();
  return 0;
}
