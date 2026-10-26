int __stdcall sub_6DF6FE(unsigned int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6, int a7, int a8, int a9)
{
  int v11; // eax
  int v12; // edi
  int v13; // [esp+30h] [ebp+28h]

  v13 = (*(int (__stdcall **)(_DWORD, int, int))(a9 + 32))(*(_DWORD *)(a9 + 40), 288, 4);
  if ( !v13 )
    return -4;
  v11 = sub_6DF306();
  if ( v11 )
  {
    if ( v11 == -3 )
    {
      *(_DWORD *)(a9 + 24) = "oversubscribed literal/length tree";
      goto LABEL_20;
    }
    if ( v11 == -4 )
      goto LABEL_20;
LABEL_18:
    *(_DWORD *)(a9 + 24) = "incomplete literal/length tree";
    goto LABEL_19;
  }
  if ( !*a4 )
    goto LABEL_18;
  v11 = sub_6DF306();
  if ( v11 )
  {
    switch ( v11 )
    {
      case -3:
        *(_DWORD *)(a9 + 24) = "oversubscribed distance tree";
        break;
      case -5:
        *(_DWORD *)(a9 + 24) = "incomplete distance tree";
LABEL_19:
        v11 = -3;
        break;
      case -4:
        break;
      default:
LABEL_14:
        *(_DWORD *)(a9 + 24) = "empty distance tree with lengths";
        goto LABEL_19;
    }
LABEL_20:
    v12 = v11;
    goto LABEL_21;
  }
  if ( !*a5 && a1 > 0x101 )
    goto LABEL_14;
  v12 = 0;
LABEL_21:
  (*(void (__cdecl **)(_DWORD, int))(a9 + 36))(*(_DWORD *)(a9 + 40), v13);
  return v12;
}
