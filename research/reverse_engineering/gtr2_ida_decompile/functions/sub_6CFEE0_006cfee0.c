int __stdcall sub_6CFEE0(_DWORD *a1, int a2)
{
  int v3; // eax
  _DWORD *v4; // edi
  int result; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // esi
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // esi
  int v16; // edx
  int v17; // edx
  _DWORD *v18; // esi
  int v19; // edx
  _DWORD *v20; // ebx
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // [esp+8h] [ebp-40h]
  int v25; // [esp+Ch] [ebp-3Ch]
  int v26; // [esp+10h] [ebp-38h]
  int v27; // [esp+14h] [ebp-34h]
  int v28; // [esp+18h] [ebp-30h]
  unsigned __int8 *v29; // [esp+1Ch] [ebp-2Ch] BYREF
  int v30; // [esp+20h] [ebp-28h]
  int v31; // [esp+24h] [ebp-24h]
  int v32; // [esp+28h] [ebp-20h]
  _DWORD *v33; // [esp+2Ch] [ebp-1Ch]
  _WORD *v34; // [esp+30h] [ebp-18h]
  int v35; // [esp+34h] [ebp-14h]
  int v36; // [esp+38h] [ebp-10h]
  _DWORD *v37; // [esp+3Ch] [ebp-Ch]
  _DWORD *v38; // [esp+40h] [ebp-8h]
  int v39; // [esp+44h] [ebp-4h]
  int v40; // [esp+50h] [ebp+8h]

  v35 = a1[104];
  v3 = a1[70];
  v4 = (_DWORD *)a1[112];
  v37 = v4;
  if ( !v3 || v4[10] || (result = sub_6CFE70()) != 0 )
  {
    if ( !v4[2] )
    {
      v6 = a1[6];
      v33 = a1;
      v29 = *(unsigned __int8 **)v6;
      v30 = *(_DWORD *)(v6 + 4);
      v7 = v4[3];
      v24 = v4[5];
      v25 = v4[6];
      v26 = v4[7];
      v8 = v4[8];
      v28 = v4[9];
      v9 = a1[90];
      v40 = v7;
      v10 = v4[4];
      v27 = v8;
      v39 = 0;
      if ( v9 > 0 )
      {
        v38 = a1 + 91;
        do
        {
          v34 = *(_WORD **)(a2 + 4 * v39);
          v36 = *v38;
          v11 = v4[*(_DWORD *)(a1[v36 + 84] + 20) + 11];
          if ( v10 >= 8 )
            goto LABEL_11;
          if ( !sub_6CF670(&v29, v40, v10, 0) )
            return 0;
          v10 = v32;
          v40 = v31;
          if ( v32 >= 8 )
          {
LABEL_11:
            v13 = (unsigned __int8)(v40 >> (v10 - 8));
            v14 = *(_DWORD *)(v11 + 4 * v13 + 144);
            if ( v14 )
            {
              v15 = *(unsigned __int8 *)(v13 + v11 + 1168);
              v10 -= v14;
              goto LABEL_16;
            }
            v12 = 9;
          }
          else
          {
            v12 = 1;
          }
          v15 = sub_6CF790((int)&v29, v40, v10, v11, v12);
          if ( v15 < 0 )
            return 0;
          v10 = v32;
          v40 = v31;
LABEL_16:
          if ( v15 )
          {
            if ( v10 < v15 )
            {
              if ( !sub_6CF670(&v29, v40, v10, v15) )
                return 0;
              v10 = v32;
              v40 = v31;
            }
            v10 -= v15;
            v16 = (v40 >> v10) & ((1 << v15) - 1);
            v4 = v37;
            if ( v16 >= dword_747D68[v15] )
              v15 = (v40 >> v10) & ((1 << v15) - 1);
            else
              v15 = v16 + dword_747DA8[v15];
          }
          v17 = v15 + *(&v25 + v36);
          v18 = v38;
          *(&v25 + v36) = v17;
          v38 = v18 + 1;
          *v34 = v17 << v35;
          v19 = a1[90];
          ++v39;
        }
        while ( v39 < v19 );
      }
      v20 = (_DWORD *)a1[6];
      *v20 = v29;
      v20[1] = v30;
      v21 = v25;
      v4[4] = v10;
      v4[5] = v24;
      v22 = v27;
      v4[6] = v21;
      v23 = v28;
      v4[3] = v40;
      v4[7] = v26;
      v4[8] = v22;
      v4[9] = v23;
    }
    --v4[10];
    return 1;
  }
  return result;
}
