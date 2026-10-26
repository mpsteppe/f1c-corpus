int (__thiscall *__fastcall sub_5BB7F0(_DWORD *a1, int a2, int a3))(int, _DWORD)
{
  int v4; // ecx
  int (__thiscall *result)(int, _DWORD); // eax
  u_long v6; // eax
  _BYTE v7[8]; // [esp+10h] [ebp-8h] BYREF

  v7[0] = -3;
  v7[1] = -4;
  v7[2] = 30;
  v7[3] = 102;
  v7[4] = 106;
  v7[5] = -78;
  if ( a3 >= 10 )
  {
    v4 = 0;
    while ( v7[v4 + a2 - (_DWORD)v7] == v7[v4] )
    {
      if ( ++v4 >= 6 )
      {
        result = (int (__thiscall *)(int, _DWORD))a1[40];
        if ( result )
        {
          v6 = ntohl(*(_DWORD *)(a2 + 6));
          return (int (__thiscall *)(int, _DWORD))((int (__fastcall *)(u_long, _DWORD))a1[40])(v6, a1[65]);
        }
        return result;
      }
    }
  }
  result = (int (__thiscall *)(int, _DWORD))a1[41];
  if ( result )
    return (int (__thiscall *)(int, _DWORD))result(a2, a1[65]);
  return result;
}
