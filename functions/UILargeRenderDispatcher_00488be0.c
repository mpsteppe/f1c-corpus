int __thiscall sub_488BE0(int this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  const char *v6; // edi
  int v7; // eax
  char v8; // cl
  const char *v9; // ecx
  char *v10; // eax
  char v11; // al
  int v12; // edx
  int v13; // ebx
  int v14; // ebp
  int result; // eax
  bool v16; // cc
  char *v17; // edi
  char *v19; // edi
  int v20; // edi
  int v21; // edi
  char v22; // al
  int v23; // eax
  char v24; // cl
  int v25; // eax
  int v26; // ebp
  int v27; // ecx
  int v28; // ecx
  int v29; // [esp-4h] [ebp-ACh]
  int v30; // [esp+10h] [ebp-98h] BYREF
  int v31; // [esp+14h] [ebp-94h] BYREF
  int v32; // [esp+18h] [ebp-90h]
  int v33; // [esp+1Ch] [ebp-8Ch]
  int v34; // [esp+20h] [ebp-88h]
  int v35; // [esp+24h] [ebp-84h]
  char v36[128]; // [esp+28h] [ebp-80h] BYREF

  if ( *(_BYTE *)(this + 232) )
  {
    v6 = *(const char **)(this + 176);
    if ( !v6 )
      v6 = byte_5EA438;
    if ( BinarySearchInStringTable(byte_5EC4C0, v6, byte_5EC4CC) )
    {
      if ( v6 )
        strcpy(byte_5EC4CC, v6);
      else
        byte_5EC4CC[0] = 0;
    }
    v7 = 0;
    do
    {
      v8 = byte_5EC4CC[v7];
      v36[v7++] = v8;
    }
    while ( v8 );
  }
  else
  {
    v9 = *(const char **)(this + 176);
    if ( !v9 )
      v9 = byte_5EA438;
    strcpy(v36, v9);
  }
  v10 = *(char **)(this + 184);
  if ( !v10 )
    v10 = byte_5EA438;
  v11 = sub_589A35(*v10);
  switch ( v11 )
  {
    case 'C':
      *(_DWORD *)(this + 224) = 2;
      break;
    case 'L':
      *(_DWORD *)(this + 224) = 1;
      break;
    case 'R':
      *(_DWORD *)(this + 224) = 3;
      break;
  }
  v12 = *(_DWORD *)(this + 8);
  v13 = *(_DWORD *)(this + 4);
  v14 = *(_DWORD *)(this + 16);
  v32 = *(_DWORD *)(this + 12);
  result = 0;
  v33 = v12;
  if ( strlen(v36) )
  {
    v16 = *(_DWORD *)(this + 228) <= 0;
    v31 = 0;
    v30 = 0;
    if ( v16 )
    {
      v21 = v14 - v32;
      v35 = v12 - v13;
      v22 = *(_BYTE *)(this + 232);
      v34 = v14 - v32;
      if ( v22 )
      {
        if ( BinarySearchInStringTable(byte_5EC4C0, v36, byte_5EC4CC) )
        {
          v23 = 0;
          do
          {
            v24 = v36[v23];
            byte_5EC4CC[v23++] = v24;
          }
          while ( v24 );
        }
        TextRenderToSurface(byte_5EC4CC, &v30, &v31, 1);
      }
      else
      {
        TextRenderToSurface(v36, &v30, &v31, 1);
      }
      if ( v21 < v30 || v35 < v31 )
      {
        v25 = *(_DWORD *)(this + 224);
        v33 = v13;
        v20 = v31 + v13;
        if ( v25 == 2 )
        {
          v26 = v14 - CRTFtol((double)v34 * 0.5 + 0.5);
          v27 = v26 - CRTFtol((double)v30 * 0.5 + 0.5);
          v14 = v27 + v30;
        }
        else if ( v25 == 3 )
        {
          v27 = v14 - v30;
        }
        else
        {
          v27 = v32;
          v14 = v30 + v32;
        }
        v34 = v31 / 2;
        if ( v35 / 2 > v31 / 2 )
          v33 = v13 + v35 / 2 - v31 / 2;
        v13 = v33;
        v32 = v27;
        ShortComputation_a9c0(v33, v20, v27, v14);
        goto LABEL_31;
      }
    }
    else
    {
      TextRenderToSurface(v36, &v30, &v31, 1);
      if ( v30 > *(_DWORD *)(this + 228) )
      {
        v17 = v36;
        if ( v36[0] )
        {
          while ( *++v17 )
            ;
        }
        v19 = v17 - 1;
        *v19 = 0;
        TextRenderToSurface(v36, &v30, &v31, 1);
        while ( v30 > *(_DWORD *)(this + 228) )
        {
          if ( v36 == v19 )
            break;
          *--v19 = 0;
          TextRenderToSurface(v36, &v30, &v31, 1);
        }
      }
    }
    v20 = v33;
LABEL_31:
    v29 = *(unsigned __int8 *)(this + 232);
    if ( *(_DWORD *)(this + 224) == 2 )
    {
      BitmapDraw(v36, v13, v20, v32, v14, v29);
    }
    else if ( *(_DWORD *)(this + 224) == 3 )
    {
      BitmapDrawWithAlpha(v36, v13, v20, v32, v14, v29);
    }
    else
    {
      BitmapDraw_81f0(v36, v13, v20, v32, v14, v29);
    }
    *a2 = v13;
    v28 = v32;
    *a3 = v20;
    *a4 = v28;
    *a5 = v14;
    return 0;
  }
  return result;
}
