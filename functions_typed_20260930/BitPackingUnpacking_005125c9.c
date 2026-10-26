void __cdecl sub_5125C9(int *a1, int a2)
{
  int *v2; // ebx
  unsigned __int8 v3; // cl
  int v4; // eax
  int v5; // ecx
  int v6; // ecx
  _BYTE *v7; // esi
  _BYTE *v8; // edi
  int v9; // edx
  _BYTE *v10; // esi
  _BYTE *v11; // edi
  int v12; // edx
  _BYTE *v13; // esi
  _BYTE *v14; // edi
  int v15; // edx
  unsigned __int8 v16; // dl
  int v17; // [esp+4h] [ebp-4h]
  int v18; // [esp+4h] [ebp-4h]
  int v19; // [esp+4h] [ebp-4h]

  v2 = a1;
  v3 = *((_BYTE *)a1 + 9);
  if ( v3 < 8u )
  {
    v4 = *a1;
    v5 = v3 - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        if ( v6 != 2 )
          goto LABEL_26;
        v7 = (_BYTE *)(a2 + ((unsigned int)(v4 - 1) >> 1));
        v8 = (_BYTE *)(v4 + a2 - 1);
        v9 = 4 - 4 * ((v4 - 1) & 1);
        if ( !v4 )
          goto LABEL_26;
        v17 = *a1;
        do
        {
          *v8 = (*v7 >> v9) & 0xF;
          if ( v9 == 4 )
          {
            v9 = 0;
            --v7;
          }
          else
          {
            v9 = 4;
          }
          --v8;
          --v17;
        }
        while ( v17 );
        goto LABEL_25;
      }
      v10 = (_BYTE *)(a2 + ((unsigned int)(v4 - 1) >> 2));
      v11 = (_BYTE *)(v4 + a2 - 1);
      v12 = 6 - 2 * ((v4 - 1) & 3);
      if ( v4 )
      {
        v18 = *a1;
        do
        {
          *v11 = (*v10 >> v12) & 3;
          if ( v12 == 6 )
          {
            v12 = 0;
            --v10;
          }
          else
          {
            v12 += 2;
          }
          --v11;
          --v18;
        }
        while ( v18 );
LABEL_25:
        v2 = a1;
      }
    }
    else
    {
      v13 = (_BYTE *)(a2 + ((unsigned int)(v4 - 1) >> 3));
      v14 = (_BYTE *)(v4 + a2 - 1);
      v15 = 7 - ((v4 - 1) & 7);
      if ( v4 )
      {
        v19 = *a1;
        do
        {
          *v14 = (*v13 >> v15) & 1;
          if ( v15 == 7 )
          {
            v15 = 0;
            --v13;
          }
          else
          {
            ++v15;
          }
          --v14;
          --v19;
        }
        while ( v19 );
        goto LABEL_25;
      }
    }
LABEL_26:
    v16 = *((_BYTE *)v2 + 10);
    *((_BYTE *)v2 + 9) = 8;
    *((_BYTE *)v2 + 11) = 8 * v16;
    v2[1] = v4 * v16;
  }
}

