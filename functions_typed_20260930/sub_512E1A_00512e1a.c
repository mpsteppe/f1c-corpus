int __cdecl sub_512E1A(int *a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  unsigned __int8 v7; // cl
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  _BYTE *v11; // edx
  bool v12; // zf
  int v13; // ecx
  _BYTE *v14; // edx
  int v15; // ecx
  _BYTE *v16; // edx
  unsigned __int8 *v17; // edx
  int v18; // ebx
  _BYTE *v19; // ecx
  _BYTE *v20; // ecx
  _BYTE *v21; // ecx
  _BYTE *v22; // ecx
  int v23; // [esp+4h] [ebp-8h]
  int v24; // [esp+4h] [ebp-8h]
  int v25; // [esp+4h] [ebp-8h]
  int v26; // [esp+4h] [ebp-8h]
  int v27; // [esp+4h] [ebp-8h]
  _BYTE *v28; // [esp+8h] [ebp-4h]
  _BYTE *v29; // [esp+8h] [ebp-4h]
  _BYTE *v30; // [esp+8h] [ebp-4h]
  int v31; // [esp+14h] [ebp+8h]
  int v32; // [esp+14h] [ebp+8h]
  int v33; // [esp+14h] [ebp+8h]
  int v34; // [esp+14h] [ebp+8h]
  int v35; // [esp+14h] [ebp+8h]

  result = *a1;
  if ( *((_BYTE *)a1 + 8) == 3 )
  {
    v7 = *((_BYTE *)a1 + 9);
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
            v28 = (_BYTE *)(result + a2 - 1);
            LOBYTE(v10) = 4 * (result & 1);
            v11 = (_BYTE *)(a2 + ((unsigned int)(result - 1) >> 1));
            v31 = 4 * (*a1 & 1);
            if ( result )
            {
              v23 = result;
              do
              {
                *v28 = (*v11 >> v10) & 0xF;
                if ( v31 == 4 )
                {
                  v10 = 0;
                  --v11;
                }
                else
                {
                  v10 = v31 + 4;
                }
                --v28;
                v12 = v23-- == 1;
                v31 = v10;
              }
              while ( !v12 );
            }
          }
        }
        else
        {
          v29 = (_BYTE *)(result + a2 - 1);
          LOBYTE(v13) = 2 * (3 - ((result - 1) & 3));
          v14 = (_BYTE *)(a2 + ((unsigned int)(result - 1) >> 2));
          v32 = 2 * (3 - (((_BYTE)result - 1) & 3));
          if ( result )
          {
            v24 = result;
            do
            {
              *v29 = (*v14 >> v13) & 3;
              if ( v32 == 6 )
              {
                v13 = 0;
                --v14;
              }
              else
              {
                v13 = v32 + 2;
              }
              --v29;
              v12 = v24-- == 1;
              v32 = v13;
            }
            while ( !v12 );
          }
        }
      }
      else
      {
        v30 = (_BYTE *)(result + a2 - 1);
        LOBYTE(v15) = 7 - ((result - 1) & 7);
        v16 = (_BYTE *)(a2 + ((unsigned int)(result - 1) >> 3));
        v33 = 7 - (((_BYTE)result - 1) & 7);
        if ( result )
        {
          v25 = result;
          do
          {
            *v30 = (*v16 >> v15) & 1;
            if ( v33 == 7 )
            {
              v15 = 0;
              --v16;
            }
            else
            {
              v15 = v33 + 1;
            }
            --v30;
            v12 = v25-- == 1;
            v33 = v15;
          }
          while ( !v12 );
        }
      }
      *((_BYTE *)a1 + 9) = 8;
      *((_BYTE *)a1 + 11) = 8;
      a1[1] = result;
    }
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      v17 = (unsigned __int8 *)(result + a2 - 1);
      if ( a4 )
      {
        v18 = 4 * result;
        v26 = 4 * result;
        v19 = (_BYTE *)(4 * result + a2 - 1);
        if ( result )
        {
          v34 = result;
          result = a3;
          do
          {
            if ( *v17 < a5 )
              *v19 = *(_BYTE *)(*v17 + a4);
            else
              *v19 = -1;
            v20 = v19 - 1;
            *v20-- = *(_BYTE *)(*v17 + a3 + 2 * *v17 + 2);
            *v20-- = *(_BYTE *)(*v17 + a3 + 2 * *v17 + 1);
            *v20 = *(_BYTE *)(*v17 + a3 + 2 * *v17);
            v19 = v20 - 1;
            --v17;
            --v34;
          }
          while ( v34 );
          v18 = v26;
        }
        *((_BYTE *)a1 + 11) = 32;
        *((_BYTE *)a1 + 8) = 6;
        *((_BYTE *)a1 + 10) = 4;
      }
      else
      {
        v18 = 3 * result;
        v27 = 3 * result;
        v21 = (_BYTE *)(3 * result + a2 - 1);
        if ( result )
        {
          v35 = result;
          result = a3;
          do
          {
            *v21 = *(_BYTE *)(*v17 + a3 + 2 * *v17 + 2);
            v22 = v21 - 1;
            *v22-- = *(_BYTE *)(*v17 + a3 + 2 * *v17 + 1);
            *v22 = *(_BYTE *)(*v17 + a3 + 2 * *v17);
            v21 = v22 - 1;
            --v17;
            --v35;
          }
          while ( v35 );
          v18 = v27;
        }
        *((_BYTE *)a1 + 11) = 24;
        *((_BYTE *)a1 + 8) = 2;
        *((_BYTE *)a1 + 10) = 3;
      }
      *((_BYTE *)a1 + 9) = 8;
      a1[1] = v18;
    }
  }
  return result;
}

