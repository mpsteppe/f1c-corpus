int __thiscall sub_491350(__int16 *this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // esi
  int v7; // ebx
  int v8; // ebp
  int v9; // esi
  int i; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  _BYTE *v16; // edi
  int v17; // eax
  int v18; // ecx
  int v19; // esi
  bool v20; // dl
  bool v21; // cl
  int v22; // ebp
  int v23; // edi
  int v24; // edx
  int v25; // ecx
  int v26; // esi
  int v27; // ebx
  int v28; // eax
  _BYTE *v29; // edi
  int v30; // eax
  int v31; // edx
  int j; // ecx
  int v34; // [esp+10h] [ebp-50h]
  int v35; // [esp+14h] [ebp-4Ch]
  int v36; // [esp+18h] [ebp-48h]
  int v37; // [esp+1Ch] [ebp-44h]
  int v38; // [esp+20h] [ebp-40h]
  int v39; // [esp+24h] [ebp-3Ch]
  int v40; // [esp+28h] [ebp-38h]
  int v41; // [esp+2Ch] [ebp-34h]
  _BYTE v43[12]; // [esp+34h] [ebp-2Ch] BYREF
  int v44; // [esp+40h] [ebp-20h]
  _DWORD v45[3]; // [esp+44h] [ebp-1Ch]
  int v46; // [esp+50h] [ebp-10h]
  _DWORD v47[3]; // [esp+54h] [ebp-Ch]
  _BYTE *v48; // [esp+64h] [ebp+4h]
  int v49; // [esp+68h] [ebp+8h]
  int v50; // [esp+6Ch] [ebp+Ch]
  int v51; // [esp+70h] [ebp+10h]
  int v52; // [esp+70h] [ebp+10h]

  v5 = *this;
  v6 = this[1];
  v7 = v5 + this[2];
  v37 = v5;
  v8 = v6 + this[3];
  v47[0] = a3;
  v39 = v6;
  v46 = v6;
  v34 = 0;
  v36 = v8;
  v35 = v7;
  v41 = a3 + a5;
  v40 = a2 + a4;
  v47[1] = v8;
  v47[2] = a3 + a5;
  v44 = v5;
  v45[0] = a2;
  v45[1] = v7;
  v45[2] = a2 + a4;
  v9 = 3;
  do
  {
    for ( i = 0; i < 3; ++i )
    {
      v11 = v45[i - 1];
      v12 = v45[i];
      if ( v11 > v12 )
      {
        v45[i - 1] = v12;
        v45[i] = v11;
      }
      v13 = v47[i - 1];
      v14 = v47[i];
      if ( v13 > v14 )
      {
        v47[i - 1] = v14;
        v47[i] = v13;
      }
    }
    --v9;
  }
  while ( v9 );
  v15 = 0;
  v38 = 0;
  v16 = v43;
  while ( 1 )
  {
    v17 = 0;
    v51 = v45[v15 - 1];
    v50 = v45[v15];
    while ( 1 )
    {
      v18 = v47[v17 - 1];
      v19 = v47[v17];
      v20 = v51 >= v37 && v50 <= v7 && v18 >= v39 && v19 <= v8;
      v21 = v51 >= a2 && v50 <= v40 && v18 >= a3 && v19 <= v41;
      v16[v17++] = !v20 || v21;
      if ( v17 >= 3 )
        break;
      v7 = v35;
      v8 = v36;
    }
    v15 = v38 + 1;
    v16 += 3;
    if ( ++v38 >= 3 )
      break;
    v7 = v35;
    v8 = v36;
  }
  v22 = 0;
  v52 = 0;
  do
  {
    v23 = 0;
    v49 = 0;
    v48 = &v43[2 * v22 + v22];
    do
    {
      if ( !v48[v23] )
      {
        v24 = v47[v23 - 1];
        v25 = v45[v22 - 1];
        v26 = v45[v22];
        v27 = v47[v23] - v24;
        if ( v27 <= 0 || v26 - v25 <= 0 )
        {
          v48[v23] = 1;
        }
        else
        {
          if ( v22 < 2 )
          {
            v28 = v22 + 1;
            if ( v22 + 1 < 3 )
            {
              v29 = &v43[2 * v28 + v23 + v28];
              do
              {
                if ( *v29 )
                  break;
                v26 = v45[v28];
                *v29 = 1;
                ++v28;
                v29 += 3;
              }
              while ( v28 < 3 );
              v22 = v52;
              v23 = v49;
            }
          }
          v30 = ResourcePoolNodeAllocDealloc(v25, v24, v26 - v25, v27);
          *(_WORD *)(v30 + 8) = this[4];
          v31 = v34;
          if ( v34 )
          {
            for ( j = *(_DWORD *)(v34 + 12); j; j = *(_DWORD *)(j + 12) )
              v31 = j;
            *(_DWORD *)(v31 + 12) = v30;
          }
          else
          {
            v34 = v30;
          }
        }
      }
      v49 = ++v23;
    }
    while ( v23 < 3 );
    v52 = ++v22;
  }
  while ( v22 < 3 );
  return v34;
}
