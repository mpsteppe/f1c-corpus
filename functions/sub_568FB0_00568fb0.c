_DWORD *__thiscall sub_568FB0(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  int v3; // ecx
  int v4; // ebx
  int v5; // esi
  int v6; // edx
  int v7; // ecx
  int v8; // edi
  int v9; // ecx
  int v10; // ebx
  int v11; // ecx
  int v12; // edi
  int v13; // esi
  int *v14; // ebx
  int v15; // eax
  int *v16; // edx
  int v17; // ecx
  int v18; // ecx
  int v19; // [esp+Ch] [ebp-44h]
  int v20; // [esp+10h] [ebp-40h]
  int v21; // [esp+14h] [ebp-3Ch]
  int v22; // [esp+18h] [ebp-38h]
  int v23; // [esp+1Ch] [ebp-34h]
  int v24; // [esp+20h] [ebp-30h]
  int v25; // [esp+24h] [ebp-2Ch]
  int v26; // [esp+28h] [ebp-28h]
  int v27; // [esp+2Ch] [ebp-24h]
  int v28; // [esp+30h] [ebp-20h]
  int v29; // [esp+34h] [ebp-1Ch]
  int v30; // [esp+38h] [ebp-18h]
  int v31; // [esp+3Ch] [ebp-14h]
  int v32; // [esp+40h] [ebp-10h]
  int v33; // [esp+44h] [ebp-Ch]
  _DWORD *v34; // [esp+48h] [ebp-8h]
  int v35; // [esp+4Ch] [ebp-4h]

  result = this;
  v3 = this[141];
  v4 = result[139];
  v5 = v3 + v4 + result[143];
  v6 = 0;
  v7 = v4 + v3;
  v34 = result;
  v27 = v4;
  v35 = v5;
  v28 = v7;
  v32 = 0;
  if ( v5 > 0 )
  {
    v8 = -132 * v4;
    v9 = -88 * v7;
    v20 = 0;
    v26 = -132 * v4;
    v33 = v9;
    while ( 1 )
    {
      if ( v6 >= v4 )
      {
        if ( v6 >= v28 )
        {
          v10 = *(_DWORD *)(result[144] + v9 + 48);
          v19 = 1;
        }
        else
        {
          v10 = *(_DWORD *)(result[142] + v8 + 124);
          v19 = 2;
        }
      }
      else
      {
        v10 = *(_DWORD *)(result[140] + v20 + 48);
        v19 = 3;
      }
      v23 = v10;
      v30 = v6;
      if ( v6 < v5 )
      {
        v25 = v20;
        v31 = v9;
        v24 = v26;
        do
        {
          if ( v6 >= v27 )
          {
            if ( v6 >= v28 )
            {
              v11 = *(_DWORD *)(result[144] + v9 + 48);
              v12 = 1;
            }
            else
            {
              v11 = *(_DWORD *)(result[142] + v24 + 124);
              v12 = 2;
            }
          }
          else
          {
            v11 = *(_DWORD *)(result[140] + v25 + 48);
            v12 = 3;
          }
          v21 = v11;
          v22 = v12;
          v13 = 8 * v10;
          v14 = (int *)(a2 + 4 * v10);
          v29 = v19;
          do
          {
            v15 = 8 * v11;
            v16 = (int *)(a2 + 4 * v11);
            do
            {
              v17 = *v14;
              *(_DWORD *)(v15 + v17) = 0;
              *(_DWORD *)(v15 + v17 + 4) = 1072693248;
              v18 = *v16;
              *(_DWORD *)(v13 + v18) = 0;
              v15 += 8;
              ++v16;
              --v12;
              *(_DWORD *)(v13 + v18 + 4) = 1072693248;
            }
            while ( v12 );
            result = v34;
            v11 = v21;
            v12 = v22;
            ++v14;
            v13 += 8;
            --v29;
          }
          while ( v29 );
          v10 = v23;
          v5 = v35;
          v24 += 132;
          v6 = v30 + 1;
          v9 = v31 + 88;
          v30 = v6;
          v31 += 88;
          v25 += 56;
        }
        while ( v6 < v35 );
        v6 = v32;
        v9 = v33;
      }
      ++v6;
      v9 += 88;
      v8 = v26 + 132;
      v32 = v6;
      v33 = v9;
      v26 += 132;
      v20 += 56;
      if ( v6 >= v5 )
        break;
      v4 = v27;
    }
  }
  return result;
}
