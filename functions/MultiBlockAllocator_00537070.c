int __fastcall sub_537070(int a1, int a2, int a3)
{
  int result; // eax
  _DWORD *v6; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // eax

  result = (*(int (__fastcall **)(_DWORD, int, int))(a1 + 32))(*(_DWORD *)(a1 + 40), 1, 64);
  v6 = (_DWORD *)result;
  if ( result )
  {
    v7 = (*(int (__fastcall **)(_DWORD, int, int))(a1 + 32))(*(_DWORD *)(a1 + 40), 8, 1440);
    v6[9] = v7;
    v8 = *(_DWORD *)(a1 + 40);
    if ( v7 )
    {
      v9 = (*(int (__fastcall **)(int, int, int))(a1 + 32))(v8, 1, a3);
      v6[10] = v9;
      if ( v9 )
      {
        v6[11] = a3 + v9;
        v6[14] = a2;
        *v6 = 0;
        StateResetWithCallback(v6, a1, 0);
        return (int)v6;
      }
      else
      {
        (*(void (__fastcall **)(_DWORD, _DWORD))(a1 + 36))(*(_DWORD *)(a1 + 40), v6[9]);
        (*(void (__fastcall **)(_DWORD, _DWORD *))(a1 + 36))(*(_DWORD *)(a1 + 40), v6);
        return 0;
      }
    }
    else
    {
      (*(void (__fastcall **)(int, _DWORD *))(a1 + 36))(v8, v6);
      return 0;
    }
  }
  return result;
}
