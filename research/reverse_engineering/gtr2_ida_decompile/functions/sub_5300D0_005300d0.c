char __thiscall sub_5300D0(int this, int a2, float *a3, float a4)
{
  unsigned __int64 v5; // rax
  int v6; // ebp
  unsigned __int64 v7; // rax
  int v8; // esi
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  int v12; // ecx
  _DWORD *v13; // ebp
  int v14; // esi
  bool v15; // zf
  char result; // al
  char v17; // [esp+Bh] [ebp-Dh]
  int v18; // [esp+Ch] [ebp-Ch]
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h]
  _DWORD *v21; // [esp+24h] [ebp+Ch]

  v17 = 0;
  v5 = (unsigned __int64)((*a3 - a4 - *(float *)(this + 2340)) * *(float *)(this + 2344));
  v6 = v5;
  if ( (v5 & 0x80000000) == 0LL )
  {
    if ( (int)v5 < 8 )
      goto LABEL_6;
    v6 = 7;
  }
  else
  {
    v6 = 0;
  }
  v17 = 1;
LABEL_6:
  v7 = (unsigned __int64)((a4 + *a3 - *(float *)(this + 2340)) * *(float *)(this + 2344));
  v8 = v7;
  if ( (v7 & 0x80000000) == 0LL )
  {
    if ( (int)v7 < 8 )
      goto LABEL_11;
    v8 = 7;
  }
  else
  {
    v8 = 0;
  }
  v17 = 1;
LABEL_11:
  v9 = (unsigned __int64)((a3[2] - a4 - *(float *)(this + 2348)) * *(float *)(this + 2352));
  v19 = v9;
  if ( (v9 & 0x80000000) == 0LL )
  {
    if ( (int)v9 < 8 )
      goto LABEL_16;
    v19 = 7;
  }
  else
  {
    v19 = 0;
  }
  v17 = 1;
LABEL_16:
  v10 = (unsigned __int64)((a4 + a3[2] - *(float *)(this + 2348)) * *(float *)(this + 2352));
  HIDWORD(v10) = v10;
  v18 = (unsigned __int64)((a4 + a3[2] - *(float *)(this + 2348)) * *(float *)(this + 2352));
  if ( (v10 & 0x80000000) == 0LL )
  {
    if ( (int)v10 < 8 )
      goto LABEL_21;
    v18 = 7;
  }
  else
  {
    v18 = 0;
  }
  HIDWORD(v10) = v18;
  v17 = 1;
LABEL_21:
  if ( v6 <= v8 )
  {
    v12 = v19;
    v21 = (_DWORD *)(this + 36 * (v19 + 8 * v6));
    v20 = v8 - v6 + 1;
    do
    {
      if ( v12 <= SHIDWORD(v10) )
      {
        v13 = v21;
        v14 = HIDWORD(v10) - v12 + 1;
        do
        {
          sub_52F7A0(v13, *(_DWORD *)(this + 2356), a2, a3, a4);
          v13 += 9;
          --v14;
        }
        while ( v14 );
        v12 = v19;
        HIDWORD(v10) = v18;
      }
      v15 = v20 == 1;
      v21 += 72;
      --v20;
    }
    while ( !v15 );
  }
  result = v17;
  if ( v17 )
    result = sub_52F7A0((_DWORD *)(this + 2304), *(_DWORD *)(this + 2356), a2, a3, a4);
  ++*(_DWORD *)(this + 2356);
  return result;
}
