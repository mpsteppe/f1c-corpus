_DWORD *__thiscall sub_618A70(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // esi
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // ebp
  int v10; // edi
  int v11; // edx
  int v12; // edx
  int v13; // ebx
  int v14; // ecx
  int v15; // edi
  _DWORD *v16; // esi
  int v17; // edx
  int *v18; // ebx
  int v19; // eax
  int v20; // ebp
  int v21; // [esp+8h] [ebp-44h]
  int v22; // [esp+Ch] [ebp-40h]
  int v23; // [esp+10h] [ebp-3Ch]
  int v24; // [esp+18h] [ebp-34h]
  int v25; // [esp+1Ch] [ebp-30h]
  int v26; // [esp+20h] [ebp-2Ch]
  int v27; // [esp+24h] [ebp-28h]
  int v28; // [esp+28h] [ebp-24h]
  int v29; // [esp+2Ch] [ebp-20h]
  _DWORD *v30; // [esp+30h] [ebp-1Ch]
  int v31; // [esp+34h] [ebp-18h]
  int v32; // [esp+38h] [ebp-14h]
  int v33; // [esp+3Ch] [ebp-10h]
  int v34; // [esp+40h] [ebp-Ch]
  int v35; // [esp+44h] [ebp-8h]
  int v36; // [esp+48h] [ebp-4h]

  result = this;
  v3 = this[140];
  v4 = this[142];
  v5 = v4 + v3 + result[144];
  v6 = v4 + v3;
  v7 = 0;
  v30 = result;
  v28 = v3;
  v36 = v5;
  v29 = v6;
  v27 = 0;
  if ( v5 > 0 )
  {
    v8 = -136 * v3;
    v9 = 0;
    v10 = -88 * v6;
    v35 = 0;
    v34 = -136 * v3;
    v33 = v10;
    while ( 1 )
    {
      if ( v7 >= v3 )
      {
        if ( v7 >= v29 )
        {
          v11 = *(_DWORD *)(result[145] + v10 + 48);
          v22 = 1;
        }
        else
        {
          v11 = *(_DWORD *)(result[143] + v8 + 124);
          v22 = 2;
        }
      }
      else
      {
        v11 = *(_DWORD *)(result[141] + v9 + 48);
        v22 = 3;
      }
      v23 = v11;
      v12 = v7;
      v32 = v7;
      if ( v7 < v5 )
      {
        v24 = v8;
        v13 = v22;
        v26 = v9;
        v25 = v10;
        do
        {
          if ( v12 >= v28 )
          {
            if ( v12 >= v29 )
            {
              v21 = *(_DWORD *)(result[145] + v25 + 48);
              v14 = 1;
            }
            else
            {
              v21 = *(_DWORD *)(result[143] + v24 + 124);
              v14 = 2;
            }
          }
          else
          {
            v21 = *(_DWORD *)(result[141] + v26 + 48);
            v14 = 3;
          }
          v15 = 8 * v23;
          v16 = (_DWORD *)(a2 + 4 * v23);
          v31 = v13;
          do
          {
            v17 = 8 * v21;
            v18 = (int *)(a2 + 4 * v21);
            v19 = v14;
            do
            {
              *(double *)(v17 + *v16) = 1.0;
              v20 = *v18;
              v17 += 8;
              ++v18;
              *(double *)(v15 + v20) = 1.0;
              --v19;
            }
            while ( v19 );
            result = v30;
            ++v16;
            v15 += 8;
            --v31;
          }
          while ( v31 );
          v5 = v36;
          v13 = v22;
          v10 = v33;
          v7 = v27;
          v24 += 136;
          v25 += 88;
          v12 = v32 + 1;
          v32 = v12;
          v26 += 56;
        }
        while ( v12 < v36 );
        v8 = v34;
        v9 = v35;
      }
      ++v7;
      v10 += 88;
      v8 += 136;
      v9 += 56;
      v27 = v7;
      v33 = v10;
      v34 = v8;
      v35 = v9;
      if ( v7 >= v5 )
        break;
      v3 = v28;
    }
  }
  return result;
}
