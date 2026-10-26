int __thiscall sub_434150(int this)
{
  double v3; // st7
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c3
  double v6; // st7
  _DWORD *v7; // edi
  int v8; // ebx
  int v9; // ebp
  int v10; // edi
  int v11; // ebx
  int v12; // edi
  double v13; // st7
  double v14; // st7
  double v15; // st6
  double v16; // st7
  int i; // eax
  int v18; // ebx
  int v19; // ebp
  double v20; // st7
  double v21; // st7
  double v22; // st7
  int v23; // ebp
  int *v24; // edi
  int result; // eax
  int v26; // ebx
  long double v27; // st7
  int v28; // ecx
  int v29; // ecx
  double v30; // [esp+18h] [ebp-388h]
  double v31; // [esp+18h] [ebp-388h]
  double v32; // [esp+18h] [ebp-388h]
  double v33; // [esp+18h] [ebp-388h]
  int v34; // [esp+24h] [ebp-37Ch]
  double *v35; // [esp+24h] [ebp-37Ch]
  double v36; // [esp+28h] [ebp-378h]
  int v37; // [esp+28h] [ebp-378h]
  double v38[44]; // [esp+30h] [ebp-370h]
  double v39[66]; // [esp+190h] [ebp-210h] BYREF

  v30 = (*(float *)(this + 7340) - 0.5) * 0.5 + *(float *)(this + 7336);
  sub_430B30((_DWORD *)(this + 4720), v30);
  sub_430B30((_DWORD *)(this + 3568), v30);
  sub_430B30((_DWORD *)(this + 3632), v30);
  v3 = *(float *)(this + 7340) * 0.15000001;
  if ( v4 | v5 )
    v6 = v3 + 0.42500001;
  else
    v6 = 0.57499999 - v3;
  sub_430B30((_DWORD *)(this + 4848), v6);
  sub_430B30((_DWORD *)(this + 4784), (0.5 - *(float *)(this + 7340)) * 0.5 + *(float *)(this + 7336));
  sub_430B30((_DWORD *)(this + 4976), *(float *)(this + 7340));
  sub_430B30((_DWORD *)(this + 3312), (1.0 - *(float *)(this + 7340) + *(float *)(this + 7344)) * 0.5);
  sub_430B30((_DWORD *)(this + 3376), (*(float *)(this + 7344) + *(float *)(this + 7340)) * 0.5);
  v7 = (_DWORD *)(this + 496);
  v8 = 4;
  do
  {
    sub_430B30(v7 - 16, *(float *)(this + 7344));
    sub_430B30(v7, *(float *)(this + 7344));
    sub_430B30(v7 + 16, *(float *)(this + 7344));
    sub_430B30(v7 + 32, *(float *)(this + 7344));
    sub_430B30(v7 + 48, *(float *)(this + 7344));
    v7 += 176;
    --v8;
  }
  while ( v8 );
  v9 = 44;
  *(_DWORD *)(this + 5700) = *(_DWORD *)(this + 5704);
  v34 = 44;
  v10 = 44;
  v11 = this + 5828;
  do
  {
    *(_DWORD *)v11 = *(_DWORD *)(v11 + 4);
    v39[v10 + 11] = sub_431A00((int *)this, v10);
    if ( *(_BYTE *)(v11 + 8) )
    {
      v34 = v10;
      v9 = v10;
    }
    ++v10;
    v11 += 64;
  }
  while ( v10 <= 50 );
  v12 = 0;
  *(_DWORD *)(this + 5700) = 0;
  *(_DWORD *)(this + 5828) = 0;
  v13 = sub_431A00((int *)this, 44);
  *(_DWORD *)(this + 5700) = *(_DWORD *)(this + 5696) - 1;
  *(_DWORD *)((v9 << 6) + this + 3012) = *(_DWORD *)(((v9 + 47) << 6) + this) - 1;
  if ( *(float *)(this + 7348) < 0.5 )
  {
    v15 = v13;
    v16 = *(float *)(this + 7348) + *(float *)(this + 7348);
    v14 = v16 + v15 / v39[55] * (1.0 - v16);
  }
  else
  {
    v31 = *(float *)(this + 7348) + *(float *)(this + 7348) - 1.0;
    v14 = sub_431A00((int *)this, v9) / v39[v9 + 11] * v31 + 1.0 - v31;
  }
  for ( i = 0; i <= 6; v38[i + 43] = v14 * v39[i + 54] )
    ++i;
  v18 = *(_DWORD *)(this + 5704);
  v32 = 1.797693134862316e308;
  if ( *(int *)(this + 5696) > 0 )
  {
    v19 = -v18;
    do
    {
      v36 = 0.0;
      *(_DWORD *)(this + 5700) = v12;
      v20 = sub_431A00((int *)this, 44);
      if ( v20 < v39[0] )
        v36 = v39[0] - v20;
      v21 = sub_431A00((int *)this, v34);
      if ( v21 > v38[v34] )
      {
        v22 = v21 - v38[v34];
        if ( v36 < v22 )
          v36 = v22;
      }
      if ( v36 == v32 )
      {
        if ( (int)abs32(v19) < (int)abs32(v18 - *(_DWORD *)(this + 5704)) )
        {
          v32 = v36;
LABEL_27:
          v18 = v12;
        }
      }
      else if ( v36 < v32 )
      {
        v32 = v36;
        goto LABEL_27;
      }
      ++v12;
      ++v19;
    }
    while ( v12 < *(_DWORD *)(this + 5696) );
  }
  *(_DWORD *)(this + 5700) = v18;
  v23 = 44;
  v35 = v39;
  v24 = (int *)(this + 5824);
  do
  {
    result = 0;
    v26 = 0;
    v37 = 0;
    v33 = 1.797693134862316e308;
    if ( *v24 > 0 )
    {
      do
      {
        v24[1] = v26;
        v27 = fabs(sub_431A00((int *)this, v23) - *v35);
        if ( v27 < v33 )
        {
          v33 = v27;
          v37 = v26;
        }
        ++v26;
      }
      while ( v26 < *v24 );
      result = v37;
    }
    v24[1] = result;
    if ( v23 > 44 )
    {
      v28 = *(v24 - 15);
      if ( v28 >= result )
      {
        result = *v24;
        v29 = v28 + 1;
        if ( v29 >= *v24 )
          v24[1] = --result;
        else
          v24[1] = v29;
      }
    }
    ++v23;
    v24 += 16;
    ++v35;
  }
  while ( v23 <= 50 );
  return result;
}
