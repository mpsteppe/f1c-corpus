int __thiscall sub_4BE340(int this, int a2, float *a3, float a4)
{
  int v5; // eax
  int v6; // ebp
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int v13; // ecx
  _DWORD *v14; // ebp
  int v15; // esi
  bool v16; // zf
  int v17; // eax
  int result; // eax
  char v19; // [esp+Bh] [ebp-Dh]
  int v20; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  int v22; // [esp+14h] [ebp-4h]
  _DWORD *v23; // [esp+24h] [ebp+Ch]

  v19 = 0;
  v5 = CRTFtol((*a3 - a4 - *(float *)(this + 2340)) * *(float *)(this + 2344));
  v6 = v5;
  if ( v5 >= 0 )
  {
    if ( v5 < 8 )
      goto LABEL_6;
    v6 = 7;
  }
  else
  {
    v6 = 0;
  }
  v19 = 1;
LABEL_6:
  v7 = CRTFtol((a4 + *a3 - *(float *)(this + 2340)) * *(float *)(this + 2344));
  v8 = v7;
  if ( v7 >= 0 )
  {
    if ( v7 < 8 )
      goto LABEL_11;
    v8 = 7;
  }
  else
  {
    v8 = 0;
  }
  v19 = 1;
LABEL_11:
  v9 = CRTFtol((a3[2] - a4 - *(float *)(this + 2348)) * *(float *)(this + 2352));
  v21 = v9;
  if ( v9 >= 0 )
  {
    if ( v9 < 8 )
      goto LABEL_16;
    v21 = 7;
  }
  else
  {
    v21 = 0;
  }
  v19 = 1;
LABEL_16:
  v10 = CRTFtol((a4 + a3[2] - *(float *)(this + 2348)) * *(float *)(this + 2352));
  v11 = v10;
  v20 = v10;
  if ( v10 >= 0 )
  {
    if ( v10 < 8 )
      goto LABEL_21;
    v20 = 7;
  }
  else
  {
    v20 = 0;
  }
  v11 = v20;
  v19 = 1;
LABEL_21:
  if ( v6 <= v8 )
  {
    v13 = v21;
    v23 = (_DWORD *)(this + 36 * (v21 + 8 * v6));
    v22 = v8 - v6 + 1;
    do
    {
      if ( v13 <= v11 )
      {
        v14 = v23;
        v15 = v11 - v13 + 1;
        do
        {
          ProximityCheckWithTagUpdate(v14, *(_DWORD *)(this + 2356), a2, (int)a3, a4);
          v14 += 9;
          --v15;
        }
        while ( v15 );
        v13 = v21;
        v11 = v20;
      }
      v16 = v22 == 1;
      v23 += 72;
      --v22;
    }
    while ( !v16 );
  }
  v17 = *(_DWORD *)(this + 2356);
  if ( v19 )
  {
    ProximityCheckWithTagUpdate((_DWORD *)(this + 2304), v17, a2, (int)a3, a4);
    v17 = *(_DWORD *)(this + 2356);
  }
  result = v17 + 1;
  *(_DWORD *)(this + 2356) = result;
  return result;
}
