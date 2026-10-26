int __fastcall sub_630000(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // [esp+10h] [ebp-4h] BYREF

  v7 = *(_DWORD *)(a5 + 40);
  v14 = 0;
  v8 = (*(int (__fastcall **)(int, int, int))(a5 + 32))(v7, 19, 4);
  v9 = v8;
  if ( !v8 )
    return -4;
  v11 = ((int (__thiscall *)(int, int, int, _DWORD, _DWORD, int, int, int *, int))dword_62FB10)(
          a1,
          19,
          19,
          0,
          0,
          a3,
          a4,
          &v14,
          v8);
  v12 = v11;
  if ( v11 == -3 )
  {
    v13 = *(_DWORD *)(a5 + 40);
    *(_DWORD *)(a5 + 24) = "oversubscribed dynamic bit lengths tree";
    (*(void (__fastcall **)(int, int))(a5 + 36))(v13, v9);
    return -3;
  }
  else
  {
    if ( v11 == -5 || !*a2 )
    {
      *(_DWORD *)(a5 + 24) = "incomplete dynamic bit lengths tree";
      v12 = -3;
    }
    (*(void (__fastcall **)(_DWORD, int))(a5 + 36))(*(_DWORD *)(a5 + 40), v9);
    return v12;
  }
}
