char __thiscall sub_50FD00(int this, int a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // edx
  int v6; // ecx
  int v7; // edi
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  unsigned __int8 v21; // al
  unsigned __int8 v22; // cl
  unsigned __int8 v23; // dl
  int v24; // edx
  int v25; // eax
  int v26; // ecx
  int v27; // ecx
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // ecx
  int v32; // edx

  if ( a2 < 1 || a2 >= 9 )
    return 0;
  v3 = *(_DWORD *)(this + 11756);
  v4 = *(_DWORD *)(this + 11760);
  *(_DWORD *)(this + 11748) = a2;
  if ( a2 >= v3 )
  {
    if ( a2 > v4 )
      *(_DWORD *)(this + 11748) = v4;
  }
  else
  {
    *(_DWORD *)(this + 11748) = v3;
  }
  v5 = *(_DWORD *)(this + 2120);
  v6 = *(_DWORD *)(this + 36 * a2 + 2108);
  v7 = this + 36 * a2;
  v8 = *(_DWORD *)(this + 2116);
  *(_DWORD *)(this + 2108) = v6;
  if ( v6 >= v8 )
  {
    if ( v6 > v5 )
      *(_DWORD *)(this + 2108) = v5;
  }
  else
  {
    *(_DWORD *)(this + 2108) = v8;
  }
  v9 = *(_DWORD *)(this + 2824);
  *(_DWORD *)(this + 2816) = *(_DWORD *)(v7 + 2816);
  v10 = *(_DWORD *)(this + 2816);
  v11 = *(_DWORD *)(this + 2828);
  if ( v10 >= v9 )
  {
    if ( v10 > v11 )
      *(_DWORD *)(this + 2816) = v11;
  }
  else
  {
    *(_DWORD *)(this + 2816) = v9;
  }
  v12 = *(_DWORD *)(this + 3152);
  *(_DWORD *)(this + 3140) = *(_DWORD *)(v7 + 3140);
  v13 = *(_DWORD *)(this + 3148);
  v14 = *(_DWORD *)(this + 3140);
  if ( v14 >= v13 )
  {
    if ( v14 > v12 )
      *(_DWORD *)(this + 3140) = v12;
  }
  else
  {
    *(_DWORD *)(this + 3140) = v13;
  }
  sub_409B80((float *)(this + 3660), (float *)(v7 + 3680));
  v15 = *(_DWORD *)(this + 4012);
  *(_DWORD *)(this + 4004) = *(_DWORD *)(v7 + 4004);
  v16 = *(_DWORD *)(this + 4004);
  v17 = *(_DWORD *)(this + 4016);
  if ( v16 >= v15 )
  {
    if ( v16 > v17 )
      *(_DWORD *)(this + 4004) = v17;
  }
  else
  {
    *(_DWORD *)(this + 4004) = v15;
  }
  v18 = *(_DWORD *)(this + 4340);
  *(_DWORD *)(this + 4328) = *(_DWORD *)(v7 + 4328);
  v19 = *(_DWORD *)(this + 4336);
  v20 = *(_DWORD *)(this + 4328);
  if ( v20 >= v19 )
  {
    if ( v20 > v18 )
      *(_DWORD *)(this + 4328) = v18;
  }
  else
  {
    *(_DWORD *)(this + 4328) = v19;
  }
  v21 = *(_BYTE *)(this + 4654);
  *(_BYTE *)(this + 4652) = *(_BYTE *)(this + 24 * a2 + 4652);
  v22 = *(_BYTE *)(this + 4652);
  v23 = *(_BYTE *)(this + 4655);
  if ( v22 >= v21 )
  {
    if ( v22 > v23 )
      *(_BYTE *)(this + 4652) = v23;
  }
  else
  {
    *(_BYTE *)(this + 4652) = v21;
  }
  v24 = *(_DWORD *)(this + 12212);
  *(_DWORD *)(this + 12200) = *(_DWORD *)(v7 + 12200);
  v25 = *(_DWORD *)(this + 12208);
  v26 = *(_DWORD *)(this + 12200);
  if ( v26 >= v25 )
  {
    if ( v26 > v24 )
      *(_DWORD *)(this + 12200) = v24;
  }
  else
  {
    *(_DWORD *)(this + 12200) = v25;
  }
  v27 = *(_DWORD *)(v7 + 12524);
  v28 = *(_DWORD *)(this + 12532);
  v29 = *(_DWORD *)(this + 12536);
  *(_DWORD *)(this + 12524) = v27;
  if ( v27 >= v28 )
  {
    if ( v27 > v29 )
      *(_DWORD *)(this + 12524) = v29;
  }
  else
  {
    *(_DWORD *)(this + 12524) = v28;
  }
  v30 = *(_DWORD *)(this + 12856);
  *(_DWORD *)(this + 12848) = *(_DWORD *)(v7 + 12848);
  v31 = *(_DWORD *)(this + 12848);
  v32 = *(_DWORD *)(this + 12860);
  if ( v31 >= v30 )
  {
    if ( v31 > v32 )
      *(_DWORD *)(this + 12848) = v32;
  }
  else
  {
    *(_DWORD *)(this + 12848) = v30;
  }
  sub_409B80((float *)(this + 13152), (float *)(v7 + 13172));
  return off_16C953C(a2);
}
