int __thiscall sub_5400C0(int *this, int a2, int a3, int a4)
{
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int result; // eax
  _DWORD v10[2]; // [esp+10h] [ebp-8h] BYREF

  v5 = 0;
  LOBYTE(v6) = a4;
  if ( !a4 )
    v6 = *(_DWORD *)(a2 + 24);
  if ( (a4 & 0x100) != 0 )
    v5 = 16;
  if ( (v6 & 1) != 0 )
  {
    v7 = *(_DWORD *)(a2 + 8);
  }
  else
  {
    if ( (v6 & 2) == 0 )
      goto LABEL_13;
    v7 = *(_DWORD *)(a2 + 12);
  }
  if ( v7 )
  {
    v8 = (*(int (__stdcall **)(int, _DWORD *, _DWORD, int))(*(_DWORD *)v7 + 36))(v7, v10, 0, v5);
    goto LABEL_11;
  }
LABEL_13:
  if ( (v6 & 4) == 0 )
    return 0;
  v8 = (*(int (__stdcall **)(_DWORD, int, _DWORD *, _DWORD, int))(**(_DWORD **)(a2 + 16) + 64))(
         *(_DWORD *)(a2 + 16),
         a3,
         v10,
         0,
         v5);
LABEL_11:
  *this = v8;
  if ( !v8 )
  {
    result = v10[1];
    *(_DWORD *)(a2 + 40) = v10[0];
    return result;
  }
  return 0;
}

