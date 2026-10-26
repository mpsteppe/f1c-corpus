_DWORD *__fastcall sub_62E780(int a1, int a2, int a3)
{
  _DWORD *v5; // esi
  int v6; // eax
  int v7; // ecx
  int v9; // eax

  v5 = (_DWORD *)(*(int (__fastcall **)(_DWORD, int, int))(a1 + 32))(*(_DWORD *)(a1 + 40), 1, 64);
  if ( !v5 )
    return 0;
  v6 = (*(int (__fastcall **)(_DWORD, int, int))(a1 + 32))(*(_DWORD *)(a1 + 40), 8, 1440);
  v5[9] = v6;
  v7 = *(_DWORD *)(a1 + 40);
  if ( !v6 )
  {
    (*(void (__fastcall **)(int, _DWORD *))(a1 + 36))(v7, v5);
    return 0;
  }
  v9 = (*(int (__fastcall **)(int, int, int))(a1 + 32))(v7, 1, a3);
  v5[10] = v9;
  if ( v9 )
  {
    v5[11] = a3 + v9;
    v5[14] = a2;
    *v5 = 0;
    sub_62E710(v5, a1, 0);
    return v5;
  }
  else
  {
    (*(void (__fastcall **)(_DWORD, _DWORD))(a1 + 36))(*(_DWORD *)(a1 + 40), v5[9]);
    (*(void (__fastcall **)(_DWORD, _DWORD *))(a1 + 36))(*(_DWORD *)(a1 + 40), v5);
    return 0;
  }
}
