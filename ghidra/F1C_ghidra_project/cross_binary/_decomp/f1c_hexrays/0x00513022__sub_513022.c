// f1c  0x00513022  size=850
int __cdecl sub_513022(int *a1, int a2, _WORD *a3)
{
  char v4; // cl
  int result; // eax
  unsigned __int16 v6; // bx
  unsigned __int8 v7; // cl
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  unsigned __int8 *v11; // edx
  bool v12; // zf
  int v13; // ecx
  unsigned __int8 *v14; // edx
  char v15; // bl
  int v16; // ecx
  _BYTE *v17; // edx
  char v18; // cl
  _BYTE *v19; // ecx
  _BYTE *v20; // edi
  int v21; // edx
  _BYTE *v22; // edi
  int v23; // edx
  _BYTE *v24; // ecx
  _BYTE *v25; // edi
  unsigned __int16 v26; // bx
  _BYTE *v27; // edi
  _BYTE *v28; // edi
  char v29; // cl
  unsigned __int8 v30; // cl
  _WORD *v31; // edx
  char v32; // cl
  _BYTE *v33; // ecx
  _BYTE *v34; // edi
  _BYTE *v35; // edi
  _BYTE *v36; // ecx
  _BYTE *v37; // ecx
  _BYTE *v38; // edi
  __int16 v39; // bx
  __int16 v40; // dx
  __int16 v41; // dx
  _BYTE *v42; // edi
  _BYTE *v43; // edi
  _BYTE *v44; // ecx
  char v45; // cl
  int v46; // [esp+Ch] [ebp-Ch]
  int v47; // [esp+Ch] [ebp-Ch]
  int v48; // [esp+Ch] [ebp-Ch]
  int v49; // [esp+Ch] [ebp-Ch]
  unsigned __int16 v50; // [esp+10h] [ebp-8h]
  _BYTE *v51; // [esp+14h] [ebp-4h]
  _BYTE *v52; // [esp+14h] [ebp-4h]
  _BYTE *v53; // [esp+14h] [ebp-4h]
  int v54; // [esp+20h] [ebp+8h]
  int v55; // [esp+20h] [ebp+8h]
  int v56; // [esp+20h] [ebp+8h]
  int v57; // [esp+20h] [ebp+8h]
  int v58; // [esp+20h] [ebp+8h]
  int v59; // [esp+20h] [ebp+8h]

  v4 = *((_BYTE *)a1 + 8);
  result = *a1;
  if ( v4 )
  {
    if ( v4 == 2 )
    {
      v31 = a3;
      if ( a3 )
      {
        v32 = *((_BYTE *)a1 + 9);
        if ( v32 == 8 )
        {
          v33 = (_BYTE *)(a1[1] + a2 - 1);
          v34 = (_BYTE *)(a2 + 4 * result - 1);
          if ( result )
          {
            v58 = *a1;
            do
            {
              if ( (unsigned __int8)*(v33 - 2) == a3[1]
                && (unsigned __int8)*(v33 - 1) == a3[2]
                && (unsigned __int8)*v33 == a3[3] )
              {
                *v34 = 0;
              }
              else
              {
                *v34 = -1;
              }
              v35 = v34 - 1;
              *v35-- = *v33;
              v36 = v33 - 1;
              *v35-- = *v36;
              *v35 = *--v36;
              v34 = v35 - 1;
              v33 = v36 - 1;
              --v58;
            }
            while ( v58 );
          }
        }
        else if ( v32 == 16 )
        {
          v37 = (_BYTE *)(a1[1] + a2 - 1);
          v38 = (_BYTE *)(a2 + 8 * result - 1);
          if ( result )
          {
            v59 = *a1;
            while ( 1 )
            {
              HIBYTE(v39) = *(v37 - 5);
              LOBYTE(v39) = *(v37 - 4);
              if ( v39 == v31[1]
                && (HIBYTE(v40) = *(v37 - 3), LOBYTE(v40) = *(v37 - 2), v40 == a3[2])
                && (HIBYTE(v41) = *(v37 - 1), LOBYTE(v41) = *v37, v41 == a3[3]) )
              {
                *v38 = 0;
                v42 = v38 - 1;
                *v42 = 0;
              }
              else
              {
                *v38 = -1;
                v42 = v38 - 1;
                *v42 = -1;
              }
              v43 = v42 - 1;
              *v43-- = *v37;
              v44 = v37 - 1;
              *v43-- = *v44;
              *v43-- = *--v44;
              *v43-- = *--v44;
              *v43-- = *--v44;
              *v43 = *--v44;
              v38 = v43 - 1;
              v37 = v44 - 1;
              if ( !--v59 )
                break;
              v31 = a3;
            }
          }
        }
        v45 = *((_BYTE *)a1 + 9);
        *((_BYTE *)a1 + 8) = 6;
        *((_BYTE *)a1 + 10) = 4;
        v30 = 4 * v45;
        goto LABEL_68;
      }
    }
  }
  else
  {
    v6 = 0;
    if ( a3 )
      v6 = a3[4];
    v7 = *((_BYTE *)a1 + 9);
    v50 = v6;
    if ( v7 < 8u )
    {
      v8 = v7 - 1;
      if ( v8 )
      {
        v9 = v8 - 1;
        if ( v9 )
        {
          if ( v9 == 2 )
          {
            v51 = (_BYTE *)(result + a2 - 1);
            v50 = 17 * v6;
            LOBYTE(v10) = 4 - 4 * ((result - 1) & 1);
            v11 = (unsigned __int8 *)(a2 + ((unsigned int)(result - 1) >> 1));
            v54 = 4 - 4 * (((_BYTE)result - 1) & 1);
            if ( result )
            {
              v46 = result;
              do
              {
                *v51 = (*v11 >> v10) & 0xF | (16 * ((*v11 >> v10) & 0xF));
                v10 = 4;
                if ( v54 == 4 )
                {
                  v10 = 0;
                  --v11;
                }
                --v51;
                v12 = v46-- == 1;
                v54 = v10;
              }
              while ( !v12 );
            }
          }
        }
        else
        {
          v50 = 85 * v6;
          v52 = (_BYTE *)(result + a2 - 1);
          v13 = (unsigned __int8)(2 * (3 - ((result - 1) & 3)));
          v14 = (unsigned __int8 *)(a2 + ((unsigned int)(result - 1) >> 2));
          v55 = 2 * (3 - (((_BYTE)result - 1) & 3));
          if ( result )
          {
            v47 = result;
            do
            {
              v15 = (*v14 >> v13) & 3;
              *v52 = v15 | (4 * (v15 | (4 * (v15 | (4 * v15)))));
              if ( v55 == 6 )
              {
                v13 = 0;
                --v14;
              }
              else
              {
                v13 = v55 + 2;
              }
              --v52;
              v12 = v47-- == 1;
              v55 = v13;
            }
            while ( !v12 );
          }
        }
      }
      else
      {
        v50 = 255 * v6;
        v53 = (_BYTE *)(result + a2 - 1);
        v16 = (unsigned __int8)(7 - ((result - 1) & 7));
        v17 = (_BYTE *)(a2 + ((unsigned int)(result - 1) >> 3));
        v56 = 7 - (((_BYTE)result - 1) & 7);
        if ( result )
        {
          v48 = result;
          do
          {
            *v53 = -(((*v17 >> v16) & 1) != 0);
            if ( v56 == 7 )
            {
              v16 = 0;
              --v17;
            }
            else
            {
              v16 = v56 + 1;
            }
            --v53;
            v12 = v48-- == 1;
            v56 = v16;
          }
          while ( !v12 );
        }
      }
      v6 = v50;
      *((_BYTE *)a1 + 9) = 8;
      *((_BYTE *)a1 + 11) = 8;
      a1[1] = result;
    }
    if ( a3 )
    {
      v18 = *((_BYTE *)a1 + 9);
      if ( v18 == 8 )
      {
        v19 = (_BYTE *)(result + a2 - 1);
        v20 = (_BYTE *)(a2 + 2 * result - 1);
        if ( result )
        {
          v21 = result;
          do
          {
            if ( (unsigned __int8)*v19 == v50 )
              *v20 = 0;
            else
              *v20 = -1;
            v22 = v20 - 1;
            *v22 = *v19;
            v20 = v22 - 1;
            --v19;
            --v21;
          }
          while ( v21 );
        }
      }
      else if ( v18 == 16 )
      {
        v23 = a1[1];
        v24 = (_BYTE *)(v23 + a2 - 1);
        v25 = (_BYTE *)(a2 + 2 * v23 - 1);
        if ( result )
        {
          v49 = v6;
          v57 = result;
          do
          {
            HIBYTE(v26) = *(v24 - 1);
            LOBYTE(v26) = *v24;
            if ( v26 == v49 )
            {
              *v25 = 0;
              v27 = v25 - 1;
              *v27 = 0;
            }
            else
            {
              *v25 = -1;
              v27 = v25 - 1;
              *v27 = -1;
            }
            v28 = v27 - 1;
            *v28-- = *v24;
            *v28 = *(v24 - 1);
            v25 = v28 - 1;
            v24 -= 2;
            --v57;
          }
          while ( v57 );
        }
      }
      v29 = *((_BYTE *)a1 + 9);
      *((_BYTE *)a1 + 8) = 4;
      *((_BYTE *)a1 + 10) = 2;
      v30 = 2 * v29;
LABEL_68:
      *((_BYTE *)a1 + 11) = v30;
      a1[1] = (result * (unsigned int)v30) >> 3;
    }
  }
  return result;
}
