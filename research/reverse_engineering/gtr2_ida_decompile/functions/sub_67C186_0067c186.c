int __stdcall sub_67C186(int *a1, int a2, _WORD *a3)
{
  char v4; // cl
  int result; // eax
  unsigned __int16 v6; // bx
  unsigned __int8 v7; // cl
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  unsigned __int8 *v12; // edx
  bool v13; // zf
  int v14; // ecx
  unsigned __int8 *v15; // edx
  char v16; // bl
  int v17; // ecx
  _BYTE *v18; // edx
  char v19; // cl
  _BYTE *v20; // ecx
  _BYTE *v21; // edi
  int v22; // edx
  _BYTE *v23; // edi
  int v24; // edx
  _BYTE *v25; // ecx
  _BYTE *v26; // edi
  unsigned __int16 v27; // bx
  _BYTE *v28; // edi
  _BYTE *v29; // edi
  char v30; // cl
  unsigned __int8 v31; // cl
  _WORD *v32; // edx
  char v33; // cl
  _BYTE *v34; // ecx
  _BYTE *v35; // edi
  _BYTE *v36; // edi
  _BYTE *v37; // ecx
  _BYTE *v38; // ecx
  _BYTE *v39; // edi
  __int16 v40; // bx
  __int16 v41; // dx
  __int16 v42; // dx
  _BYTE *v43; // edi
  _BYTE *v44; // edi
  _BYTE *v45; // ecx
  char v46; // cl
  int v47; // [esp+Ch] [ebp-8h]
  int v48; // [esp+Ch] [ebp-8h]
  int v49; // [esp+Ch] [ebp-8h]
  unsigned __int16 v50; // [esp+10h] [ebp-4h]
  _BYTE *v51; // [esp+1Ch] [ebp+8h]
  _BYTE *v52; // [esp+1Ch] [ebp+8h]
  _BYTE *v53; // [esp+1Ch] [ebp+8h]
  int v54; // [esp+20h] [ebp+Ch]
  int v55; // [esp+20h] [ebp+Ch]
  int v56; // [esp+20h] [ebp+Ch]
  int v57; // [esp+20h] [ebp+Ch]
  int v58; // [esp+20h] [ebp+Ch]
  int v59; // [esp+24h] [ebp+10h]
  int v60; // [esp+24h] [ebp+10h]

  v4 = *((_BYTE *)a1 + 8);
  result = *a1;
  if ( v4 )
  {
    if ( v4 == 2 )
    {
      v32 = a3;
      if ( a3 )
      {
        v33 = *((_BYTE *)a1 + 9);
        if ( v33 == 8 )
        {
          v34 = (_BYTE *)(a1[1] + a2 - 1);
          v35 = (_BYTE *)(a2 + 4 * result - 1);
          if ( result )
          {
            v60 = *a1;
            do
            {
              if ( (unsigned __int8)*(v34 - 2) == v32[1]
                && (unsigned __int8)*(v34 - 1) == v32[2]
                && (unsigned __int8)*v34 == v32[3] )
              {
                *v35 = 0;
              }
              else
              {
                *v35 = -1;
              }
              v36 = v35 - 1;
              *v36-- = *v34;
              v37 = v34 - 1;
              *v36-- = *v37;
              *v36 = *--v37;
              v35 = v36 - 1;
              v34 = v37 - 1;
              --v60;
            }
            while ( v60 );
          }
        }
        else if ( v33 == 16 )
        {
          v38 = (_BYTE *)(a1[1] + a2 - 1);
          v39 = (_BYTE *)(a2 + 8 * result - 1);
          if ( result )
          {
            v58 = *a1;
            while ( 1 )
            {
              HIBYTE(v40) = *(v38 - 5);
              LOBYTE(v40) = *(v38 - 4);
              if ( v40 == v32[1]
                && (HIBYTE(v41) = *(v38 - 3), LOBYTE(v41) = *(v38 - 2), v41 == a3[2])
                && (HIBYTE(v42) = *(v38 - 1), LOBYTE(v42) = *v38, v42 == a3[3]) )
              {
                *v39 = 0;
                v43 = v39 - 1;
                *v43 = 0;
              }
              else
              {
                *v39 = -1;
                v43 = v39 - 1;
                *v43 = -1;
              }
              v44 = v43 - 1;
              *v44-- = *v38;
              v45 = v38 - 1;
              *v44-- = *v45;
              *v44-- = *--v45;
              *v44-- = *--v45;
              *v44-- = *--v45;
              *v44 = *--v45;
              v39 = v44 - 1;
              v38 = v45 - 1;
              if ( !--v58 )
                break;
              v32 = a3;
            }
          }
        }
        v46 = *((_BYTE *)a1 + 9);
        *((_BYTE *)a1 + 8) = 6;
        *((_BYTE *)a1 + 10) = 4;
        v31 = 4 * v46;
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
      v9 = v7 - 1;
      if ( v9 )
      {
        v10 = v9 - 1;
        if ( v10 )
        {
          if ( v10 == 2 )
          {
            v50 = 17 * v6;
            v51 = (_BYTE *)(result + a2 - 1);
            LOBYTE(v11) = 4 - 4 * ((result - 1) & 1);
            v12 = (unsigned __int8 *)(a2 + ((unsigned int)(result - 1) >> 1));
            v54 = 4 - 4 * (((_BYTE)result - 1) & 1);
            if ( result )
            {
              v47 = result;
              do
              {
                *v51 = (*v12 >> v11) & 0xF | (16 * ((*v12 >> v11) & 0xF));
                v11 = 4;
                if ( v54 == 4 )
                {
                  v11 = 0;
                  --v12;
                }
                --v51;
                v13 = v47-- == 1;
                v54 = v11;
              }
              while ( !v13 );
            }
          }
        }
        else
        {
          v50 = 85 * v6;
          v52 = (_BYTE *)(result + a2 - 1);
          v14 = (unsigned __int8)(2 * (3 - ((result - 1) & 3)));
          v15 = (unsigned __int8 *)(a2 + ((unsigned int)(result - 1) >> 2));
          v55 = 2 * (3 - (((_BYTE)result - 1) & 3));
          if ( result )
          {
            v48 = result;
            do
            {
              v16 = (*v15 >> v14) & 3;
              *v52 = v16 | (4 * (v16 | (4 * (v16 | (4 * v16)))));
              if ( v55 == 6 )
              {
                v14 = 0;
                --v15;
              }
              else
              {
                v14 = v55 + 2;
              }
              --v52;
              v13 = v48-- == 1;
              v55 = v14;
            }
            while ( !v13 );
          }
        }
      }
      else
      {
        v50 = 255 * v6;
        v53 = (_BYTE *)(result + a2 - 1);
        v17 = (unsigned __int8)(7 - ((result - 1) & 7));
        v18 = (_BYTE *)(a2 + ((unsigned int)(result - 1) >> 3));
        v56 = 7 - (((_BYTE)result - 1) & 7);
        if ( result )
        {
          v49 = result;
          do
          {
            *v53 = -(((*v18 >> v17) & 1) != 0);
            if ( v56 == 7 )
            {
              v17 = 0;
              --v18;
            }
            else
            {
              v17 = v56 + 1;
            }
            --v53;
            v13 = v49-- == 1;
            v56 = v17;
          }
          while ( !v13 );
        }
      }
      v6 = v50;
      *((_BYTE *)a1 + 9) = 8;
      *((_BYTE *)a1 + 11) = 8;
      a1[1] = result;
    }
    if ( a3 )
    {
      v19 = *((_BYTE *)a1 + 9);
      if ( v19 == 8 )
      {
        v20 = (_BYTE *)(result + a2 - 1);
        v21 = (_BYTE *)(a2 + 2 * result - 1);
        if ( result )
        {
          v22 = result;
          do
          {
            if ( (unsigned __int8)*v20 == v50 )
              *v21 = 0;
            else
              *v21 = -1;
            v23 = v21 - 1;
            *v23 = *v20;
            v21 = v23 - 1;
            --v20;
            --v22;
          }
          while ( v22 );
        }
      }
      else if ( v19 == 16 )
      {
        v24 = a1[1];
        v25 = (_BYTE *)(v24 + a2 - 1);
        v26 = (_BYTE *)(a2 + 2 * v24 - 1);
        if ( result )
        {
          v57 = v6;
          v59 = result;
          do
          {
            HIBYTE(v27) = *(v25 - 1);
            LOBYTE(v27) = *v25;
            if ( v27 == v57 )
            {
              *v26 = 0;
              v28 = v26 - 1;
              *v28 = 0;
            }
            else
            {
              *v26 = -1;
              v28 = v26 - 1;
              *v28 = -1;
            }
            v29 = v28 - 1;
            *v29-- = *v25;
            *v29 = *(v25 - 1);
            v26 = v29 - 1;
            v25 -= 2;
            --v59;
          }
          while ( v59 );
        }
      }
      v30 = *((_BYTE *)a1 + 9);
      *((_BYTE *)a1 + 8) = 4;
      *((_BYTE *)a1 + 10) = 2;
      v31 = 2 * v30;
LABEL_68:
      *((_BYTE *)a1 + 11) = v31;
      a1[1] = (result * (unsigned int)v31) >> 3;
    }
  }
  return result;
}
