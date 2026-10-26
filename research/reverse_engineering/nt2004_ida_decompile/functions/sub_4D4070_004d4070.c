char __thiscall sub_4D4070(char *Buffer, int a2)
{
  int v2; // edi
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  unsigned __int8 i; // bl
  int v10; // eax
  int v11; // ecx
  int *v12; // ecx
  unsigned __int8 j; // bl
  int v14; // eax
  int v15; // ecx
  int *v16; // ecx
  unsigned __int8 k; // bl
  int v18; // eax
  int v19; // ecx
  char **v20; // ecx
  char *v21; // eax
  bool Buffera; // [esp+Fh] [ebp-5h] BYREF
  int v24; // [esp+10h] [ebp-4h] BYREF

  v2 = a2;
  sub_57A3A0(Buffer, 1u);
  sub_4D3FE0(v2, Buffer + 1);
  sub_57A3A0(Buffer + 65, 0x20u);
  sub_57A3A0(Buffer + 97, 0x20u);
  sub_57A3A0(Buffer + 132, 4u);
  sub_57A3A0(Buffer + 136, 4u);
  Buffera = *((_DWORD *)Buffer + 35) != 0;
  sub_57A3A0(&Buffera, 1u);
  if ( Buffera )
  {
    v4 = (char *)**((_DWORD **)Buffer + 35);
    if ( !v4 )
      v4 = &byte_629120;
    sub_4D3FE0(v2, v4);
    v5 = *(char **)(*((_DWORD *)Buffer + 35) + 8);
    if ( !v5 )
      v5 = &byte_629120;
    sub_4D3FE0(v2, v5);
    v6 = *(char **)(*((_DWORD *)Buffer + 35) + 16);
    if ( !v6 )
      v6 = &byte_629120;
    sub_4D3FE0(v2, v6);
    v7 = *(char **)(*((_DWORD *)Buffer + 35) + 24);
    if ( !v7 )
      v7 = &byte_629120;
    sub_4D3FE0(v2, v7);
    v8 = *(char **)(*((_DWORD *)Buffer + 35) + 32);
    if ( !v8 )
      v8 = &byte_629120;
    sub_4D3FE0(v2, v8);
    LOBYTE(a2) = *(_BYTE *)(*((_DWORD *)Buffer + 35) + 52);
    sub_57A3A0(&a2, 1u);
    for ( i = 0; i < (unsigned __int8)a2; ++i )
    {
      v10 = i;
      if ( i < *(int *)(*((_DWORD *)Buffer + 35) + 52) )
      {
        v11 = *(_DWORD *)(*((_DWORD *)Buffer + 35) + 40);
        if ( i )
        {
          while ( v11 )
          {
            v11 = *(_DWORD *)(v11 + 4);
            if ( --v10 <= 0 )
              goto LABEL_17;
          }
        }
        else
        {
LABEL_17:
          if ( v11 )
          {
            v12 = *(int **)v11;
            goto LABEL_20;
          }
        }
      }
      v12 = 0;
LABEL_20:
      v24 = *v12;
      sub_57A3A0(&v24, 4u);
    }
    LOBYTE(a2) = *(_BYTE *)(*((_DWORD *)Buffer + 35) + 68);
    sub_57A3A0(&a2, 1u);
    for ( j = 0; j < (unsigned __int8)a2; ++j )
    {
      v14 = j;
      if ( j < *(int *)(*((_DWORD *)Buffer + 35) + 68) )
      {
        v15 = *(_DWORD *)(*((_DWORD *)Buffer + 35) + 56);
        if ( j )
        {
          while ( v15 )
          {
            v15 = *(_DWORD *)(v15 + 4);
            if ( --v14 <= 0 )
              goto LABEL_26;
          }
        }
        else
        {
LABEL_26:
          if ( v15 )
          {
            v16 = *(int **)v15;
            goto LABEL_29;
          }
        }
      }
      v16 = 0;
LABEL_29:
      v24 = *v16;
      sub_57A3A0(&v24, 4u);
    }
    LOBYTE(a2) = *(_BYTE *)(*((_DWORD *)Buffer + 35) + 84);
    sub_57A3A0(&a2, 1u);
    for ( k = 0; k < (unsigned __int8)a2; ++k )
    {
      v18 = k;
      if ( k < *(int *)(*((_DWORD *)Buffer + 35) + 84) )
      {
        v19 = *(_DWORD *)(*((_DWORD *)Buffer + 35) + 72);
        if ( k )
        {
          while ( v19 )
          {
            v19 = *(_DWORD *)(v19 + 4);
            if ( --v18 <= 0 )
              goto LABEL_35;
          }
        }
        else
        {
LABEL_35:
          if ( v19 )
          {
            v20 = *(char ***)v19;
            goto LABEL_38;
          }
        }
      }
      v20 = 0;
LABEL_38:
      v21 = *v20;
      if ( !*v20 )
        v21 = &byte_629120;
      sub_4D3FE0(v2, v21);
    }
  }
  return 1;
}
