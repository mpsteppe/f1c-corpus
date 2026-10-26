unsigned int __cdecl sub_512894(int a1, int a2, unsigned int a3, char a4)
{
  char v4; // dl
  char v6; // cl
  unsigned int result; // eax
  unsigned int v8; // ebx
  char v9; // cl
  _BYTE *v10; // ecx
  _BYTE *v11; // edi
  _BYTE *v12; // edi
  bool v13; // zf
  _BYTE *v14; // edi
  _BYTE *v15; // ecx
  _BYTE *v16; // edi
  _BYTE *v17; // ecx
  _BYTE *v18; // edi
  _BYTE *v19; // ecx
  char *v20; // edi
  char v21; // cl
  char *v22; // edi
  char v23; // cl
  _BYTE *v24; // ecx
  _BYTE *v25; // edi
  _BYTE *v26; // edi
  _BYTE *v27; // ecx
  char v28; // bl
  _BYTE *v29; // edi
  _BYTE *v30; // ecx
  _BYTE *v31; // edi
  _BYTE *v32; // ecx
  _BYTE *v33; // edi
  _BYTE *v34; // ecx
  _BYTE *v35; // ecx
  _BYTE *v36; // edi
  char v37; // bl
  _BYTE *v38; // ecx
  _BYTE *v39; // edi
  _BYTE *v40; // ecx
  unsigned int v41; // [esp+18h] [ebp+8h]
  unsigned int v42; // [esp+18h] [ebp+8h]
  char *v43; // [esp+18h] [ebp+8h]
  char *v44; // [esp+18h] [ebp+8h]
  unsigned int v45; // [esp+18h] [ebp+8h]
  unsigned int v46; // [esp+18h] [ebp+8h]
  char v47; // [esp+1Bh] [ebp+Bh]
  unsigned int v48; // [esp+20h] [ebp+10h]
  unsigned int v49; // [esp+20h] [ebp+10h]
  unsigned int v50; // [esp+20h] [ebp+10h]
  unsigned int v51; // [esp+20h] [ebp+10h]

  v4 = a3;
  v6 = *(_BYTE *)(a1 + 8);
  result = *(_DWORD *)a1;
  v8 = a3 >> 8;
  v47 = BYTE1(a3);
  if ( v6 )
  {
    if ( v6 != 2 )
      return result;
    v23 = *(_BYTE *)(a1 + 9);
    if ( v23 == 8 )
    {
      if ( a4 >= 0 )
      {
        v29 = (_BYTE *)(a2 + 2 * result + result);
        v30 = &v29[result];
        if ( result )
        {
          v46 = result;
          do
          {
            v31 = v29 - 1;
            v32 = v30 - 1;
            *v32 = *v31--;
            *--v32 = *v31;
            v29 = v31 - 1;
            *--v32 = *v29;
            v30 = v32 - 1;
            v13 = v46-- == 1;
            *v30 = a3;
          }
          while ( !v13 );
        }
      }
      else
      {
        v24 = (_BYTE *)(a2 + 2 * result + result);
        v25 = &v24[result];
        if ( result > 1 )
        {
          v45 = result - 1;
          do
          {
            v26 = v25 - 1;
            *v26 = a3;
            v27 = v24 - 1;
            *--v26 = *v27;
            v28 = *--v27;
            --v26;
            v24 = v27 - 1;
            *v26 = v28;
            v25 = v26 - 1;
            v13 = v45-- == 1;
            *v25 = *v24;
          }
          while ( !v13 );
        }
        *(v25 - 1) = a3;
      }
      *(_BYTE *)(a1 + 11) = 32;
      result *= 4;
    }
    else
    {
      if ( v23 != 16 )
        return result;
      v33 = (_BYTE *)(a2 + 2 * result + result);
      v34 = &v33[result];
      if ( a4 >= 0 )
      {
        if ( result )
        {
          v51 = result;
          do
          {
            v39 = v33 - 1;
            v40 = v34 - 1;
            *v40 = *v39--;
            *--v40 = *v39--;
            *--v40 = *v39--;
            *--v40 = *v39--;
            *--v40 = *v39;
            v33 = v39 - 1;
            *--v40 = *v33;
            *--v40 = v47;
            v34 = v40 - 1;
            v13 = v51-- == 1;
            *v34 = v4;
          }
          while ( !v13 );
        }
      }
      else
      {
        if ( result > 1 )
        {
          v50 = result - 1;
          do
          {
            v35 = v34 - 1;
            *v35-- = v47;
            *v35 = v4;
            v36 = v33 - 1;
            *--v35 = *v36--;
            *--v35 = *v36--;
            *--v35 = *v36--;
            *--v35 = *v36;
            v37 = *--v36;
            --v35;
            v33 = v36 - 1;
            *v35 = v37;
            v34 = v35 - 1;
            v13 = v50-- == 1;
            *v34 = *v33;
          }
          while ( !v13 );
          LOBYTE(v8) = v47;
        }
        v38 = v34 - 1;
        *v38 = v8;
        *(v38 - 1) = v4;
      }
      *(_BYTE *)(a1 + 11) = 64;
      result *= 8;
    }
    *(_BYTE *)(a1 + 10) = 4;
  }
  else
  {
    v9 = *(_BYTE *)(a1 + 9);
    if ( v9 == 8 )
    {
      v10 = (_BYTE *)(result + a2);
      v11 = (_BYTE *)(result + a2 + result);
      if ( a4 >= 0 )
      {
        if ( result )
        {
          v42 = result;
          do
          {
            --v10;
            v14 = v11 - 1;
            *v14 = *v10;
            v11 = v14 - 1;
            v13 = v42-- == 1;
            *v11 = a3;
          }
          while ( !v13 );
        }
      }
      else
      {
        if ( result > 1 )
        {
          v41 = result - 1;
          do
          {
            v12 = v11 - 1;
            --v10;
            *v12 = a3;
            v11 = v12 - 1;
            v13 = v41-- == 1;
            *v11 = *v10;
          }
          while ( !v13 );
        }
        *(v11 - 1) = a3;
      }
      *(_BYTE *)(a1 + 10) = 2;
      *(_BYTE *)(a1 + 11) = 16;
      result *= 2;
    }
    else
    {
      if ( v9 != 16 )
        return result;
      if ( a4 >= 0 )
      {
        v43 = (char *)(result + a2);
        v20 = (char *)(result + result + a2);
        if ( result )
        {
          v49 = result;
          do
          {
            v44 = v43 - 1;
            v21 = *v44;
            v22 = v20 - 1;
            v43 = v44 - 1;
            *v22-- = v21;
            *v22-- = *v43;
            *v22 = v8;
            v20 = v22 - 1;
            v13 = v49-- == 1;
            *v20 = v4;
          }
          while ( !v13 );
        }
      }
      else
      {
        v15 = (_BYTE *)(result + result + a2);
        if ( result > 1 )
        {
          v48 = result - 1;
          v16 = (_BYTE *)(result + a2);
          do
          {
            v17 = v15 - 1;
            *v17-- = v8;
            *v17 = v4;
            v18 = v16 - 1;
            *--v17 = *v18;
            v16 = v18 - 1;
            v15 = v17 - 1;
            v13 = v48-- == 1;
            *v15 = *v16;
            LOBYTE(v8) = v47;
          }
          while ( !v13 );
        }
        v19 = v15 - 1;
        *v19 = v8;
        *(v19 - 1) = v4;
      }
      *(_BYTE *)(a1 + 10) = 2;
      *(_BYTE *)(a1 + 11) = 32;
      result *= 4;
    }
  }
  *(_DWORD *)(a1 + 4) = result;
  return result;
}

