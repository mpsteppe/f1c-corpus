char __thiscall sub_4B81A0(_DWORD *this, const char *a2)
{
  _DWORD *v2; // ebp
  const char *v3; // ebx
  int v4; // eax
  int v5; // esi
  int *v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // edi
  int v14; // esi
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // edi
  int v19; // eax
  int v20; // edx
  int i; // ecx
  int v22; // ecx
  int v24; // [esp-8h] [ebp-68h]
  _BYTE v26[80]; // [esp+10h] [ebp-50h] BYREF

  v2 = this;
  sub_4B8360();
  v3 = a2;
  if ( !a2 || strlen(a2) )
  {
    sub_58815F(v26, "%d", v2[435] + 1);
    v3 = v26;
  }
  v4 = sub_587C03(12);
  v5 = v4;
  if ( v4 )
  {
    *(float *)v4 = *((float *)v2 + 974);
    *(_DWORD *)(v4 + 4) = 0;
    *(_DWORD *)(v4 + 8) = -1;
    sub_566650(v3);
  }
  else
  {
    v5 = 0;
  }
  v6 = v2 + 432;
  if ( v5 )
  {
    v7 = sub_587C03(16);
    if ( v7 )
    {
      *(_DWORD *)v7 = v5;
      *(_DWORD *)(v7 + 4) = 0;
      *(_DWORD *)(v7 + 8) = 0;
      *(_BYTE *)(v7 + 12) = 1;
    }
    else
    {
      v7 = 0;
    }
    if ( *v6 )
    {
      *(_DWORD *)(v2[433] + 4) = v7;
      *(_DWORD *)(v7 + 8) = v2[433];
    }
    else
    {
      *v6 = v7;
      v2[434] = v7;
    }
    v2[433] = v7;
    ++v2[435];
  }
  v8 = 0;
  v9 = *v6;
  if ( !*v6 )
    goto LABEL_18;
  do
  {
    v9 = *(_DWORD *)(v9 + 4);
    ++v8;
  }
  while ( v9 );
  if ( v8 >= 2 )
  {
    v11 = v8 / 2 - 1;
    v12 = *v6;
    if ( v11 > 0 )
    {
      do
      {
        --v11;
        v12 = *(_DWORD *)(v12 + 4);
      }
      while ( v11 );
    }
    v13 = *(_DWORD *)(v12 + 4);
    v24 = *v6;
    *(_DWORD *)(v12 + 4) = 0;
    v14 = sub_4BB2E0(v24);
    v15 = sub_4BB2E0(v13);
    v16 = v15;
    v17 = v14;
    if ( v14 )
    {
      if ( v15 )
      {
        if ( **(float **)v14 >= (double)**(float **)v15 )
        {
          v14 = v15;
          v18 = v15;
          v16 = *(_DWORD *)(v15 + 4);
        }
        else
        {
          v17 = *(_DWORD *)(v14 + 4);
          v18 = v14;
        }
        if ( v17 )
        {
          while ( v16 )
          {
            if ( **(float **)v17 >= (double)**(float **)v16 )
            {
              v19 = v16;
              v16 = *(_DWORD *)(v16 + 4);
            }
            else
            {
              v19 = v17;
              v17 = *(_DWORD *)(v17 + 4);
            }
            v2 = this;
            *(_DWORD *)(v18 + 4) = v19;
            v18 = v19;
            if ( !v17 )
              goto LABEL_32;
          }
          *(_DWORD *)(v18 + 4) = v17;
        }
        else
        {
LABEL_32:
          if ( v16 )
            *(_DWORD *)(v18 + 4) = v16;
          else
            *(_DWORD *)(v18 + 4) = 0;
        }
      }
    }
    else
    {
      v14 = v15;
    }
    v10 = v14;
  }
  else
  {
LABEL_18:
    v10 = *v6;
  }
  v20 = 0;
  *v6 = v10;
  if ( v10 )
  {
    for ( i = *(_DWORD *)(v10 + 4); i; i = *(_DWORD *)(i + 4) )
    {
      *(_DWORD *)(v10 + 8) = v20;
      v20 = v10;
      v10 = i;
    }
    *(_DWORD *)(v10 + 8) = v20;
  }
  v22 = *v6;
  v6[1] = v10;
  v6[2] = v22;
  *((_BYTE *)v2 + 1744) = 1;
  return 1;
}
