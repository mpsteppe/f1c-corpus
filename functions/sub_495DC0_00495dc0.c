int __userpurge sub_495DC0@<eax>(_DWORD *a1@<ecx>, double a2@<st0>, float a3)
{
  int v4; // eax
  int result; // eax
  double v6; // st7
  double v7; // st7
  int v8; // ecx
  int v9; // ebx
  int v10; // esi
  int v11; // eax
  int v12; // ebp
  int v13; // esi
  int v14; // ebx
  int v15; // eax
  int v16; // ebp
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  double v20; // st7
  int v21; // eax
  int v22; // esi
  int v23; // ebp
  int v24; // edx
  int v25; // ebx
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  int v29; // [esp-Ch] [ebp-38h]
  int v30; // [esp-Ch] [ebp-38h]
  int v31; // [esp-8h] [ebp-34h]
  int v32; // [esp-8h] [ebp-34h]
  float v33; // [esp+0h] [ebp-2Ch]
  int i; // [esp+14h] [ebp-18h]
  int v35; // [esp+18h] [ebp-14h]
  int v36; // [esp+24h] [ebp-8h]
  int v37; // [esp+28h] [ebp-4h]
  int v38; // [esp+30h] [ebp+4h]

  v4 = a1[1374];
  if ( v4 )
  {
    result = v4 - 1;
    if ( !result )
    {
      for ( i = 0; i < 80; ++i )
      {
        v6 = (double)i * 0.050000001 + 1.0;
        v33 = v6;
        CollisionNoiseGenerator(a3, v33);
        v7 = 1.0 - v6;
        v8 = *(_DWORD *)(*(_DWORD *)(a1[1375] + 76) + 12);
        v9 = a1[1376];
        v10 = *(_DWORD *)(v8 + 28) / 80;
        v37 = v10;
        v35 = *(_DWORD *)(v8 + 32);
        v11 = CRTFtol(v7);
        v12 = a1[1377];
        v13 = v11 + v9 + i * v10;
        v14 = v12 + CRTFtol(v7);
        v15 = v13 < 0 ? 0 : v13;
        v16 = v14 < 0 ? 0 : v14;
        if ( v15 + v37 >= 800 )
          v17 = 800 - v15;
        else
          v17 = v37;
        if ( v16 + v35 >= 600 )
          v18 = 600 - v16;
        else
          v18 = v35;
        v31 = v18;
        v29 = v17;
        v19 = GlobalAccessor_5150();
        F_10ParamForwarder(
          *(_DWORD *)(*(_DWORD *)(a1[1375] + 76) + 12),
          v13,
          v16 - v14,
          v19,
          v13 < 0 ? 0 : v13,
          v14 < 0 ? 0 : v14,
          v29,
          v31,
          0,
          0);
        result = i + 1;
      }
    }
  }
  else
  {
    CollisionNoiseGenerator(a3, -1.0);
    v20 = 1.0 - a2;
    v21 = *(_DWORD *)(*(_DWORD *)(a1[1375] + 76) + 12);
    v36 = *(_DWORD *)(v21 + 28);
    v38 = *(_DWORD *)(v21 + 32);
    v22 = a1[1376] + CRTFtol(v20);
    v23 = a1[1377] + CRTFtol(v20);
    v24 = v36;
    v25 = v22 < 0 ? 0 : v22;
    v26 = v23 < 0 ? 0 : v23;
    if ( v25 + v36 >= 800 )
      v24 = 800 - v25;
    if ( v26 + v38 >= 600 )
      v27 = 600 - v26;
    else
      v27 = v38;
    v32 = v27;
    v30 = v24;
    v28 = GlobalAccessor_5150();
    return F_10ParamForwarder(
             *(_DWORD *)(*(_DWORD *)(a1[1375] + 76) + 12),
             v25 - v22,
             (v23 < 0 ? 0 : v23) - v23,
             v28,
             v22 < 0 ? 0 : v22,
             v23 < 0 ? 0 : v23,
             v30,
             v32,
             0,
             0);
  }
  return result;
}
