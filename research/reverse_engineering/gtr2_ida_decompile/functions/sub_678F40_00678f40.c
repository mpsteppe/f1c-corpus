int __stdcall sub_678F40(int *a1, int a2)
{
  int v2; // eax
  int v3; // esi
  char v4; // di
  int v5; // edi
  int v6; // eax
  int v7; // edi
  int v8; // edi

  v2 = *a1;
  v3 = a1[105];
  v4 = a2;
  *(_DWORD *)(v2 + 20) = 121;
  *(_DWORD *)(v2 + 24) = v3;
  *(_DWORD *)(v2 + 28) = a2;
  (*(void (__stdcall **)(int *, int))(v2 + 4))(a1, -1);
  while ( 1 )
  {
    if ( v3 < 192 )
    {
LABEL_3:
      v5 = 2;
      goto LABEL_12;
    }
    if ( v3 < 208 || v3 > 215 || v3 == ((v4 + 1) & 7) + 208 || v3 == ((v4 + 2) & 7) + 208 )
    {
      v5 = 3;
    }
    else
    {
      if ( v3 == ((v4 - 1) & 7) + 208 || v3 == ((v4 - 2) & 7) + 208 )
        goto LABEL_3;
      v5 = 1;
    }
LABEL_12:
    v6 = *a1;
    *(_DWORD *)(v6 + 20) = 97;
    *(_DWORD *)(v6 + 24) = v3;
    *(_DWORD *)(v6 + 28) = v5;
    (*(void (__stdcall **)(int *, int))(v6 + 4))(a1, 4);
    v7 = v5 - 1;
    if ( !v7 )
      break;
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 == 1 )
        return 1;
      v4 = a2;
    }
    else
    {
      if ( !sub_6789F0(a1) )
        return 0;
      v3 = a1[105];
      v4 = a2;
    }
  }
  a1[105] = 0;
  return 1;
}
