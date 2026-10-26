int __fastcall sub_53BB10(
        unsigned int a1,
        unsigned int a2,
        int *a3,
        unsigned int *a4,
        unsigned int *a5,
        _DWORD *a6,
        _DWORD *a7,
        int a8,
        int a9)
{
  int v10; // ecx
  unsigned int *v11; // eax
  unsigned int *v12; // edi
  int v14; // eax
  int v15; // esi
  int v16; // eax
  int v17; // ecx
  int v18; // ecx
  unsigned int v19; // [esp+10h] [ebp-8h] BYREF
  unsigned int v20; // [esp+14h] [ebp-4h]

  v20 = a2;
  v10 = *(_DWORD *)(a9 + 40);
  v19 = 0;
  v11 = (unsigned int *)(*(int (__fastcall **)(int, int, int))(a9 + 32))(v10, 288, 4);
  v12 = v11;
  if ( !v11 )
    return -4;
  v14 = sub_53B660(a3, a1, 0x101u, (int)&unk_5F22F0, (int)&unk_5F2370, a6, a4, a8, &v19, v11);
  v15 = v14;
  if ( v14 )
  {
    if ( v14 == -3 )
    {
      v18 = *(_DWORD *)(a9 + 40);
      *(_DWORD *)(a9 + 24) = aOversubscribed_1;
      (*(void (__fastcall **)(int, unsigned int *))(a9 + 36))(v18, v12);
      return -3;
    }
    if ( v14 == -4 )
      goto LABEL_20;
LABEL_18:
    *(_DWORD *)(a9 + 24) = aIncompleteLite;
    goto LABEL_19;
  }
  if ( !*a4 )
    goto LABEL_18;
  v16 = sub_53B660(&a3[a1], v20, 0, (int)&unk_5F23F0, (int)&unk_5F2468, a7, a5, a8, &v19, v12);
  v15 = v16;
  switch ( v16 )
  {
    case 0:
      if ( *a5 || a1 <= 0x101 )
      {
        (*(void (__fastcall **)(_DWORD, unsigned int *))(a9 + 36))(*(_DWORD *)(a9 + 40), v12);
        return 0;
      }
      goto LABEL_14;
    case -3:
      v17 = *(_DWORD *)(a9 + 40);
      *(_DWORD *)(a9 + 24) = aOversubscribed_0;
      (*(void (__fastcall **)(int, unsigned int *))(a9 + 36))(v17, v12);
      return -3;
    case -5:
      *(_DWORD *)(a9 + 24) = aIncompleteDist;
LABEL_19:
      v15 = -3;
      goto LABEL_20;
  }
  if ( v16 != -4 )
  {
LABEL_14:
    *(_DWORD *)(a9 + 24) = aEmptyDistanceT;
    goto LABEL_19;
  }
LABEL_20:
  (*(void (__fastcall **)(_DWORD, unsigned int *))(a9 + 36))(*(_DWORD *)(a9 + 40), v12);
  return v15;
}
