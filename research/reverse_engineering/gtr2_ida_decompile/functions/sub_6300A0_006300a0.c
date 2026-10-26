int __fastcall sub_6300A0(unsigned int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6, int a7, int a8, int a9)
{
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  int v14; // eax
  int v15; // esi
  int v16; // eax
  int v17; // ecx
  int v18; // ecx
  int v19; // [esp+30h] [ebp-8h] BYREF
  int v20; // [esp+34h] [ebp-4h]

  v20 = a2;
  v10 = *(_DWORD *)(a9 + 40);
  v19 = 0;
  v11 = (*(int (__fastcall **)(int, int, int))(a9 + 32))(v10, 288, 4);
  v12 = v11;
  if ( !v11 )
    return -4;
  v14 = ((int (__thiscall *)(int, unsigned int, int, void *, void *, int, int, int *, int))dword_62FB10)(
          a3,
          a1,
          257,
          &unk_72FE68,
          &unk_72FEE8,
          a6,
          a8,
          &v19,
          v11);
  v15 = v14;
  if ( v14 )
  {
    if ( v14 == -3 )
    {
      v18 = *(_DWORD *)(a9 + 40);
      *(_DWORD *)(a9 + 24) = "oversubscribed literal/length tree";
      (*(void (__fastcall **)(int, int))(a9 + 36))(v18, v12);
      return -3;
    }
    if ( v14 == -4 )
      goto LABEL_20;
LABEL_18:
    *(_DWORD *)(a9 + 24) = "incomplete literal/length tree";
    goto LABEL_19;
  }
  if ( !*a4 )
    goto LABEL_18;
  v16 = ((int (__thiscall *)(unsigned int, int, _DWORD, void *, void *, int, int, int *, int))dword_62FB10)(
          a3 + 4 * a1,
          v20,
          0,
          &unk_72FF68,
          &unk_72FFE0,
          a7,
          a8,
          &v19,
          v12);
  v15 = v16;
  switch ( v16 )
  {
    case 0:
      if ( *a5 || a1 <= 0x101 )
      {
        (*(void (__fastcall **)(_DWORD, int))(a9 + 36))(*(_DWORD *)(a9 + 40), v12);
        return 0;
      }
      goto LABEL_14;
    case -3:
      v17 = *(_DWORD *)(a9 + 40);
      *(_DWORD *)(a9 + 24) = "oversubscribed distance tree";
      (*(void (__fastcall **)(int, int))(a9 + 36))(v17, v12);
      return -3;
    case -5:
      *(_DWORD *)(a9 + 24) = "incomplete distance tree";
LABEL_19:
      v15 = -3;
      goto LABEL_20;
  }
  if ( v16 != -4 )
  {
LABEL_14:
    *(_DWORD *)(a9 + 24) = "empty distance tree with lengths";
    goto LABEL_19;
  }
LABEL_20:
  (*(void (__fastcall **)(_DWORD, int))(a9 + 36))(*(_DWORD *)(a9 + 40), v12);
  return v15;
}
