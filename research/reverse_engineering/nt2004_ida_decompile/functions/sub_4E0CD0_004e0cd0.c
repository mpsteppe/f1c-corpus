int __thiscall sub_4E0CD0(int this, int a2, float *a3, float a4)
{
  __int64 v5; // rax
  int v6; // ebp
  __int64 v7; // rax
  int v8; // esi
  __int64 v9; // rax
  __int64 v10; // rax
  int v12; // ecx
  _DWORD *v13; // ebp
  int v14; // esi
  bool v15; // zf
  int v16; // eax
  int result; // eax
  char v18; // [esp+Bh] [ebp-Dh]
  int v19; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+14h] [ebp-4h]
  _DWORD *v22; // [esp+24h] [ebp+Ch]

  v18 = 0;
  v5 = (__int64)((*a3 - a4 - *(float *)(this + 2340)) * *(float *)(this + 2344));
  v6 = v5;
  if ( (int)v5 >= 0 )
  {
    if ( (int)v5 < 8 )
      goto LABEL_6;
    v6 = 7;
  }
  else
  {
    v6 = 0;
  }
  v18 = 1;
LABEL_6:
  v7 = (__int64)((a4 + *a3 - *(float *)(this + 2340)) * *(float *)(this + 2344));
  v8 = v7;
  if ( (int)v7 >= 0 )
  {
    if ( (int)v7 < 8 )
      goto LABEL_11;
    v8 = 7;
  }
  else
  {
    v8 = 0;
  }
  v18 = 1;
LABEL_11:
  v9 = (__int64)((a3[2] - a4 - *(float *)(this + 2348)) * *(float *)(this + 2352));
  v20 = v9;
  if ( (int)v9 >= 0 )
  {
    if ( (int)v9 < 8 )
      goto LABEL_16;
    v20 = 7;
  }
  else
  {
    v20 = 0;
  }
  v18 = 1;
LABEL_16:
  v10 = (__int64)((a4 + a3[2] - *(float *)(this + 2348)) * *(float *)(this + 2352));
  HIDWORD(v10) = v10;
  v19 = (__int64)((a4 + a3[2] - *(float *)(this + 2348)) * *(float *)(this + 2352));
  if ( (int)v10 >= 0 )
  {
    if ( (int)v10 < 8 )
      goto LABEL_21;
    v19 = 7;
  }
  else
  {
    v19 = 0;
  }
  HIDWORD(v10) = v19;
  v18 = 1;
LABEL_21:
  if ( v6 <= v8 )
  {
    v12 = v20;
    v22 = (_DWORD *)(this + 36 * (v20 + 8 * v6));
    v21 = v8 - v6 + 1;
    do
    {
      if ( v12 <= SHIDWORD(v10) )
      {
        v13 = v22;
        v14 = HIDWORD(v10) - v12 + 1;
        do
        {
          sub_4E0300(v13, *(_DWORD *)(this + 2356), a2, (int)a3, a4);
          v13 += 9;
          --v14;
        }
        while ( v14 );
        v12 = v20;
        HIDWORD(v10) = v19;
      }
      v15 = v21 == 1;
      v22 += 72;
      --v21;
    }
    while ( !v15 );
  }
  v16 = *(_DWORD *)(this + 2356);
  if ( v18 )
  {
    sub_4E0300((_DWORD *)(this + 2304), v16, a2, (int)a3, a4);
    v16 = *(_DWORD *)(this + 2356);
  }
  result = v16 + 1;
  *(_DWORD *)(this + 2356) = result;
  return result;
}
