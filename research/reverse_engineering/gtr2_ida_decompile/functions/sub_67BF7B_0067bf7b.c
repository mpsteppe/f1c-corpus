int __stdcall sub_67BF7B(int *a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  unsigned __int8 v7; // cl
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  _BYTE *v12; // edx
  bool v13; // zf
  int v14; // ecx
  _BYTE *v15; // edx
  int v16; // ecx
  _BYTE *v17; // edx
  unsigned __int8 *v18; // edx
  int v19; // ebx
  _BYTE *v20; // ecx
  _BYTE *v21; // ecx
  _BYTE *v22; // ecx
  _BYTE *v23; // ecx
  int v24; // [esp+4h] [ebp-4h]
  int v25; // [esp+4h] [ebp-4h]
  int v26; // [esp+4h] [ebp-4h]
  int v27; // [esp+10h] [ebp+8h]
  int v28; // [esp+10h] [ebp+8h]
  int v29; // [esp+10h] [ebp+8h]
  int v30; // [esp+10h] [ebp+8h]
  int v31; // [esp+10h] [ebp+8h]
  _BYTE *v32; // [esp+14h] [ebp+Ch]
  _BYTE *v33; // [esp+14h] [ebp+Ch]
  _BYTE *v34; // [esp+14h] [ebp+Ch]
  int v35; // [esp+14h] [ebp+Ch]
  int v36; // [esp+1Ch] [ebp+14h]

  result = *a1;
  if ( *((_BYTE *)a1 + 8) == 3 )
  {
    v7 = *((_BYTE *)a1 + 9);
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
            v32 = (_BYTE *)(result + a2 - 1);
            LOBYTE(v11) = 4 * (result & 1);
            v12 = (_BYTE *)(a2 + ((unsigned int)(result - 1) >> 1));
            v27 = 4 * (*a1 & 1);
            if ( result )
            {
              v24 = result;
              do
              {
                *v32 = (*v12 >> v11) & 0xF;
                if ( v27 == 4 )
                {
                  v11 = 0;
                  --v12;
                }
                else
                {
                  v11 = v27 + 4;
                }
                --v32;
                v13 = v24-- == 1;
                v27 = v11;
              }
              while ( !v13 );
            }
          }
        }
        else
        {
          v33 = (_BYTE *)(result + a2 - 1);
          LOBYTE(v14) = 2 * (3 - ((result - 1) & 3));
          v15 = (_BYTE *)(a2 + ((unsigned int)(result - 1) >> 2));
          v28 = 2 * (3 - (((_BYTE)result - 1) & 3));
          if ( result )
          {
            v25 = result;
            do
            {
              *v33 = (*v15 >> v14) & 3;
              if ( v28 == 6 )
              {
                v14 = 0;
                --v15;
              }
              else
              {
                v14 = v28 + 2;
              }
              --v33;
              v13 = v25-- == 1;
              v28 = v14;
            }
            while ( !v13 );
          }
        }
      }
      else
      {
        v34 = (_BYTE *)(result + a2 - 1);
        LOBYTE(v16) = 7 - ((result - 1) & 7);
        v17 = (_BYTE *)(a2 + ((unsigned int)(result - 1) >> 3));
        v29 = 7 - (((_BYTE)result - 1) & 7);
        if ( result )
        {
          v26 = result;
          do
          {
            *v34 = (*v17 >> v16) & 1;
            if ( v29 == 7 )
            {
              v16 = 0;
              --v17;
            }
            else
            {
              v16 = v29 + 1;
            }
            --v34;
            v13 = v26-- == 1;
            v29 = v16;
          }
          while ( !v13 );
        }
      }
      *((_BYTE *)a1 + 9) = 8;
      *((_BYTE *)a1 + 11) = 8;
      a1[1] = result;
    }
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      v18 = (unsigned __int8 *)(result + a2 - 1);
      if ( a4 )
      {
        v19 = 4 * result;
        v35 = 4 * result;
        v20 = (_BYTE *)(4 * result + a2 - 1);
        if ( result )
        {
          v30 = result;
          result = a3;
          do
          {
            if ( *v18 < a5 )
              *v20 = *(_BYTE *)(*v18 + a4);
            else
              *v20 = -1;
            v21 = v20 - 1;
            *v21-- = *(_BYTE *)(*v18 + a3 + 2 * *v18 + 2);
            *v21-- = *(_BYTE *)(*v18 + a3 + 2 * *v18 + 1);
            *v21 = *(_BYTE *)(*v18 + a3 + 2 * *v18);
            v20 = v21 - 1;
            --v18;
            --v30;
          }
          while ( v30 );
          v19 = v35;
        }
        *((_BYTE *)a1 + 11) = 32;
        *((_BYTE *)a1 + 8) = 6;
        *((_BYTE *)a1 + 10) = 4;
      }
      else
      {
        v19 = 3 * result;
        v31 = 3 * result;
        v22 = (_BYTE *)(3 * result + a2 - 1);
        if ( result )
        {
          v36 = result;
          result = a3;
          do
          {
            *v22 = *(_BYTE *)(*v18 + a3 + 2 * *v18 + 2);
            v23 = v22 - 1;
            *v23-- = *(_BYTE *)(*v18 + a3 + 2 * *v18 + 1);
            *v23 = *(_BYTE *)(*v18 + a3 + 2 * *v18);
            v22 = v23 - 1;
            --v18;
            --v36;
          }
          while ( v36 );
          v19 = v31;
        }
        *((_BYTE *)a1 + 11) = 24;
        *((_BYTE *)a1 + 8) = 2;
        *((_BYTE *)a1 + 10) = 3;
      }
      *((_BYTE *)a1 + 9) = 8;
      a1[1] = v19;
    }
  }
  return result;
}
