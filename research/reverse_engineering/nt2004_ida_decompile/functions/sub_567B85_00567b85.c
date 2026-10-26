int __cdecl sub_567B85(
        unsigned int a1,
        unsigned int a2,
        _DWORD *a3,
        unsigned int *a4,
        unsigned int *a5,
        _DWORD *a6,
        _DWORD *a7,
        int a8,
        int a9)
{
  unsigned int *v10; // eax
  int v12; // eax
  int v13; // edi
  unsigned int v14; // [esp+4h] [ebp-4h] BYREF
  unsigned int *v15; // [esp+30h] [ebp+28h]

  v14 = 0;
  v10 = (unsigned int *)(*(int (__cdecl **)(_DWORD, int, int))(a9 + 32))(*(_DWORD *)(a9 + 40), 288, 4);
  v15 = v10;
  if ( !v10 )
    return -4;
  v12 = sub_567781(a4, a3, a1, 0x101u, (int)&unk_5F5E18, (int)&unk_5F5E98, a6, a8, &v14, v10);
  if ( v12 )
  {
    if ( v12 == -3 )
    {
      *(_DWORD *)(a9 + 24) = "oversubscribed literal/length tree";
      goto LABEL_20;
    }
    if ( v12 == -4 )
      goto LABEL_20;
LABEL_18:
    *(_DWORD *)(a9 + 24) = "incomplete literal/length tree";
    goto LABEL_19;
  }
  if ( !*a4 )
    goto LABEL_18;
  v12 = sub_567781(a5, &a3[a1], a2, 0, (int)&unk_5F5F18, (int)&unk_5F5F90, a7, a8, &v14, v15);
  if ( v12 )
  {
    switch ( v12 )
    {
      case -3:
        *(_DWORD *)(a9 + 24) = "oversubscribed distance tree";
        break;
      case -5:
        *(_DWORD *)(a9 + 24) = "incomplete distance tree";
LABEL_19:
        v12 = -3;
        break;
      case -4:
        break;
      default:
LABEL_14:
        *(_DWORD *)(a9 + 24) = "empty distance tree with lengths";
        goto LABEL_19;
    }
LABEL_20:
    v13 = v12;
    goto LABEL_21;
  }
  if ( !*a5 && a1 > 0x101 )
    goto LABEL_14;
  v13 = 0;
LABEL_21:
  (*(void (__cdecl **)(_DWORD, unsigned int *))(a9 + 36))(*(_DWORD *)(a9 + 40), v15);
  return v13;
}
