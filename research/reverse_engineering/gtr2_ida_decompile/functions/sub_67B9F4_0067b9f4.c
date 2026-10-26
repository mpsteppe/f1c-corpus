unsigned int __stdcall sub_67B9F4(int a1, int a2, unsigned int a3, char a4)
{
  char v4; // cl
  unsigned int result; // eax
  unsigned int v6; // ebx
  char v7; // cl
  _BYTE *v8; // ecx
  _BYTE *v9; // edi
  _BYTE *v10; // edi
  bool v11; // zf
  _BYTE *v12; // edi
  _BYTE *v14; // ecx
  _BYTE *v15; // edi
  _BYTE *v16; // ecx
  _BYTE *v17; // edi
  _BYTE *v18; // ecx
  char *v19; // edi
  char v20; // cl
  char *v21; // edi
  char v22; // cl
  _BYTE *v23; // edi
  _BYTE *v24; // ecx
  _BYTE *v25; // ecx
  _BYTE *v26; // edi
  char v27; // bl
  _BYTE *v28; // edi
  _BYTE *v29; // ecx
  _BYTE *v30; // edi
  _BYTE *v31; // ecx
  _BYTE *v32; // ecx
  _BYTE *v33; // edi
  char v34; // bl
  _BYTE *v35; // ecx
  _BYTE *v36; // ecx
  _BYTE *v37; // edi
  _BYTE *v38; // ecx
  _BYTE *v39; // edi
  unsigned int v40; // [esp+18h] [ebp+Ch]
  unsigned int v41; // [esp+18h] [ebp+Ch]
  unsigned int v42; // [esp+18h] [ebp+Ch]
  char *v43; // [esp+18h] [ebp+Ch]
  char *v44; // [esp+18h] [ebp+Ch]
  unsigned int v45; // [esp+18h] [ebp+Ch]
  unsigned int v46; // [esp+18h] [ebp+Ch]
  unsigned int v47; // [esp+18h] [ebp+Ch]
  unsigned int v48; // [esp+18h] [ebp+Ch]
  _BYTE *v49; // [esp+20h] [ebp+14h]
  unsigned int v50; // [esp+20h] [ebp+14h]

  v4 = *(_BYTE *)(a1 + 8);
  result = *(_DWORD *)a1;
  v6 = a3 >> 8;
  if ( v4 )
  {
    if ( v4 != 2 )
      return result;
    v22 = *(_BYTE *)(a1 + 9);
    if ( v22 == 8 )
    {
      v23 = (_BYTE *)(result + a2 + 2 * result);
      v24 = &v23[result];
      if ( a4 >= 0 )
      {
        if ( result )
        {
          v46 = *(_DWORD *)a1;
          do
          {
            v28 = v23 - 1;
            v29 = v24 - 1;
            *v29 = *v28--;
            *--v29 = *v28;
            v23 = v28 - 1;
            *--v29 = *v23;
            v24 = v29 - 1;
            v11 = v46-- == 1;
            *v24 = a3;
          }
          while ( !v11 );
        }
      }
      else
      {
        if ( result > 1 )
        {
          v45 = result - 1;
          do
          {
            v25 = v24 - 1;
            *v25 = a3;
            v26 = v23 - 1;
            *--v25 = *v26;
            v27 = *--v26;
            --v25;
            v23 = v26 - 1;
            *v25 = v27;
            v24 = v25 - 1;
            v11 = v45-- == 1;
            *v24 = *v23;
          }
          while ( !v11 );
        }
        *(v24 - 1) = a3;
      }
      *(_BYTE *)(a1 + 11) = 32;
      result *= 4;
    }
    else
    {
      if ( v22 != 16 )
        return result;
      if ( a4 >= 0 )
      {
        v36 = (_BYTE *)(result + a2 + 2 * result);
        v37 = &v36[result];
        if ( result )
        {
          v48 = *(_DWORD *)a1;
          do
          {
            v38 = v36 - 1;
            v39 = v37 - 1;
            *v39 = *v38--;
            *--v39 = *v38--;
            *--v39 = *v38--;
            *--v39 = *v38--;
            *--v39 = *v38;
            v36 = v38 - 1;
            *--v39 = *v36;
            *--v39 = BYTE1(a3);
            v37 = v39 - 1;
            v11 = v48-- == 1;
            *v37 = a3;
          }
          while ( !v11 );
        }
      }
      else
      {
        v30 = (_BYTE *)(result + a2 + 2 * result);
        v31 = &v30[result];
        if ( result > 1 )
        {
          v47 = result - 1;
          do
          {
            v32 = v31 - 1;
            *v32-- = BYTE1(a3);
            *v32 = a3;
            v33 = v30 - 1;
            *--v32 = *v33--;
            *--v32 = *v33--;
            *--v32 = *v33--;
            *--v32 = *v33;
            v34 = *--v33;
            --v32;
            v30 = v33 - 1;
            *v32 = v34;
            v31 = v32 - 1;
            v11 = v47-- == 1;
            *v31 = *v30;
          }
          while ( !v11 );
          LOBYTE(v6) = BYTE1(a3);
        }
        v35 = v31 - 1;
        *v35 = v6;
        *(v35 - 1) = a3;
      }
      *(_BYTE *)(a1 + 11) = 64;
      result *= 8;
    }
    *(_BYTE *)(a1 + 10) = 4;
  }
  else
  {
    v7 = *(_BYTE *)(a1 + 9);
    if ( v7 == 8 )
    {
      v8 = (_BYTE *)(result + a2);
      v9 = (_BYTE *)(result + a2 + result);
      if ( a4 >= 0 )
      {
        if ( result )
        {
          v41 = *(_DWORD *)a1;
          do
          {
            --v8;
            v12 = v9 - 1;
            *v12 = *v8;
            v9 = v12 - 1;
            v11 = v41-- == 1;
            *v9 = a3;
          }
          while ( !v11 );
        }
      }
      else
      {
        if ( result > 1 )
        {
          v40 = result - 1;
          do
          {
            v10 = v9 - 1;
            --v8;
            *v10 = a3;
            v9 = v10 - 1;
            v11 = v40-- == 1;
            *v9 = *v8;
          }
          while ( !v11 );
        }
        *(v9 - 1) = a3;
      }
      *(_BYTE *)(a1 + 10) = 2;
      *(_BYTE *)(a1 + 11) = 16;
      result *= 2;
    }
    else
    {
      if ( v7 != 16 )
        return result;
      if ( a4 >= 0 )
      {
        v43 = (char *)(result + a2);
        v19 = (char *)(result + result + a2);
        if ( result )
        {
          v50 = *(_DWORD *)a1;
          do
          {
            v44 = v43 - 1;
            v20 = *v44;
            v21 = v19 - 1;
            v43 = v44 - 1;
            *v21-- = v20;
            *v21-- = *v43;
            *v21 = BYTE1(a3);
            v19 = v21 - 1;
            v11 = v50-- == 1;
            *v19 = a3;
          }
          while ( !v11 );
        }
      }
      else
      {
        v49 = (_BYTE *)(result + a2);
        v14 = (_BYTE *)(result + result + a2);
        if ( result > 1 )
        {
          v42 = result - 1;
          v15 = v49;
          do
          {
            v16 = v14 - 1;
            *v16-- = v6;
            *v16 = a3;
            v17 = v15 - 1;
            *--v16 = *v17;
            v15 = v17 - 1;
            v14 = v16 - 1;
            v11 = v42-- == 1;
            *v14 = *v15;
            LOBYTE(v6) = BYTE1(a3);
          }
          while ( !v11 );
        }
        v18 = v14 - 1;
        *v18 = v6;
        *(v18 - 1) = a3;
      }
      *(_BYTE *)(a1 + 10) = 2;
      *(_BYTE *)(a1 + 11) = 32;
      result *= 4;
    }
  }
  *(_DWORD *)(a1 + 4) = result;
  return result;
}
