char __thiscall sub_4B0C00(int this)
{
  int v2; // edx
  int v3; // eax
  int *v4; // ecx
  int v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  int v10; // edx
  unsigned __int8 v11; // dl
  int v12; // edx
  int v13; // edx
  int v14; // edx
  float v15; // edx
  int v16; // edx
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // eax
  int v24; // ecx
  int v25; // edx
  int v27; // [esp-4h] [ebp-8h]
  int v28; // [esp-4h] [ebp-8h]
  int v29; // [esp-4h] [ebp-8h]
  int v30; // [esp-4h] [ebp-8h]
  int v31; // [esp-4h] [ebp-8h]
  int v32; // [esp-4h] [ebp-8h]
  int v33; // [esp-4h] [ebp-8h]
  int v34; // [esp-4h] [ebp-8h]
  int v35; // [esp-4h] [ebp-8h]
  float v36; // [esp-4h] [ebp-8h]
  int v37; // [esp-4h] [ebp-8h]

  v2 = *(_DWORD *)(this + 1632);
  v3 = *(_DWORD *)(this + 18796);
  v4 = (int *)(this + 1620);
  v27 = v2;
  v5 = *(_DWORD *)(this + 1628);
  *v4 = v3;
  ClampByRange(v4, v5, v27);
  v28 = *(_DWORD *)(this + 2196);
  v6 = *(_DWORD *)(this + 2192);
  *(_DWORD *)(this + 2184) = *(_DWORD *)(this + 18800);
  ClampByRange((int *)(this + 2184), v6, v28);
  v29 = *(_DWORD *)(this + 2448);
  v7 = *(_DWORD *)(this + 2444);
  *(_DWORD *)(this + 2436) = *(_DWORD *)(this + 18804);
  ClampByRange((int *)(this + 2436), v7, v29);
  v30 = *(_DWORD *)(this + 2700);
  v8 = *(_DWORD *)(this + 2696);
  *(_DWORD *)(this + 2688) = *(_DWORD *)(this + 18808);
  ClampByRange((int *)(this + 2688), v8, v30);
  v31 = *(_DWORD *)(this + 2952);
  v9 = *(_DWORD *)(this + 2948);
  *(_DWORD *)(this + 2940) = *(_DWORD *)(this + 18812);
  ClampByRange((int *)(this + 2940), v9, v31);
  v32 = *(_DWORD *)(this + 3204);
  v10 = *(_DWORD *)(this + 3200);
  *(_DWORD *)(this + 3192) = *(_DWORD *)(this + 18816);
  ClampByRange((int *)(this + 3192), v10, v32);
  v11 = *(_BYTE *)(this + 3399);
  *(_BYTE *)(this + 3396) = *(_BYTE *)(this + 18820);
  ByteClamp((unsigned __int8 *)(this + 3396), *(_BYTE *)(this + 3398), v11);
  v33 = *(_DWORD *)(this + 8360);
  v12 = *(_DWORD *)(this + 8356);
  *(_DWORD *)(this + 8348) = *(_DWORD *)(this + 18824);
  ClampByRange((int *)(this + 8348), v12, v33);
  v34 = *(_DWORD *)(this + 8612);
  v13 = *(_DWORD *)(this + 8608);
  *(_DWORD *)(this + 8600) = *(_DWORD *)(this + 18828);
  ClampByRange((int *)(this + 8600), v13, v34);
  v35 = *(_DWORD *)(this + 8864);
  v14 = *(_DWORD *)(this + 8860);
  *(_DWORD *)(this + 8852) = *(_DWORD *)(this + 18832);
  ClampByRange((int *)(this + 8852), v14, v35);
  v15 = *(float *)(this + 9112);
  v36 = *(float *)(this + 9116);
  *(float *)(this + 9104) = *(float *)(this + 18836);
  FloatClamp((float *)(this + 9104), v15, v36);
  v37 = *(_DWORD *)(this + 9620);
  v16 = *(_DWORD *)(this + 9616);
  *(_DWORD *)(this + 9608) = *(_DWORD *)(this + 18840);
  ClampByRange((int *)(this + 9608), v16, v37);
  v17 = *(_DWORD *)(this + 10088);
  *(_DWORD *)(this + 10076) = *(_DWORD *)(this + 18844);
  v18 = *(_DWORD *)(this + 10084);
  v19 = *(_DWORD *)(this + 10076);
  if ( v19 >= v18 )
  {
    if ( v19 > v17 )
      *(_DWORD *)(this + 10076) = v17;
  }
  else
  {
    *(_DWORD *)(this + 10076) = v18;
  }
  v20 = *(_DWORD *)(this + 18848);
  v21 = *(_DWORD *)(this + 10336);
  v22 = *(_DWORD *)(this + 10340);
  *(_DWORD *)(this + 10328) = v20;
  if ( v20 >= v21 )
  {
    if ( v20 > v22 )
      *(_DWORD *)(this + 10328) = v22;
  }
  else
  {
    *(_DWORD *)(this + 10328) = v21;
  }
  v23 = *(_DWORD *)(this + 9364);
  *(_DWORD *)(this + 9356) = *(_DWORD *)(this + 18852);
  v24 = *(_DWORD *)(this + 9356);
  v25 = *(_DWORD *)(this + 9368);
  if ( v24 >= v23 )
  {
    if ( v24 > v25 )
      *(_DWORD *)(this + 9356) = v25;
    return 1;
  }
  else
  {
    *(_DWORD *)(this + 9356) = v23;
    return 1;
  }
}

