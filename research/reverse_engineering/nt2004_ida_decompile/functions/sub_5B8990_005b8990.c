int __thiscall sub_5B8990(int this, int a2, int a3)
{
  _DWORD *v4; // edi
  int v5; // ebp
  int v6; // eax
  int v7; // eax
  int v9; // eax
  long double v10; // st7
  double v11; // st7
  _DWORD *v12; // eax
  int v13; // eax
  int v14; // eax
  float v15; // [esp+0h] [ebp-34h]
  int v16; // [esp+4h] [ebp-30h]
  float v17; // [esp+4h] [ebp-30h]
  int v18; // [esp+8h] [ebp-2Ch]
  float v19; // [esp+8h] [ebp-2Ch]
  float v20; // [esp+18h] [ebp-1Ch]
  float v21; // [esp+1Ch] [ebp-18h] BYREF
  float v22; // [esp+20h] [ebp-14h] BYREF
  float v23; // [esp+24h] [ebp-10h] BYREF
  float v24; // [esp+28h] [ebp-Ch] BYREF
  float v25; // [esp+2Ch] [ebp-8h] BYREF
  float v26; // [esp+30h] [ebp-4h] BYREF

  v4 = **(_DWORD ***)(this + 16);
  v5 = 0;
  if ( (*(_BYTE *)(this + 40) & 8) != 0 )
    goto LABEL_25;
  if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 28) + 312) + 60) & 2) != 0 )
  {
    v5 = -2;
    goto LABEL_25;
  }
  if ( !sub_5B4BE0(dword_7E6B48) )
  {
    v6 = v4[92];
LABEL_8:
    *(_DWORD *)(this + 20) = v6;
    goto LABEL_9;
  }
  if ( (*(_BYTE *)(this + 40) & 4) == 0 )
  {
    v6 = v4[92] + 96 * *(_DWORD *)(this + 44);
    goto LABEL_8;
  }
  *(_DWORD *)(this + 20) = v4[92]
                         + 96
                         * *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 28) + 312) + 64) + 560)
                                     + 44);
LABEL_9:
  v7 = *(_DWORD *)(*(_DWORD *)(this + 20) + 16);
  if ( !v7 )
    return -2;
  if ( (*(_DWORD *)(v7 + 56) & 0x40000) == 0 )
    return -2;
  sub_593F30(*(int **)(this + 16), v7);
  v9 = *(_DWORD *)(this + 28);
  if ( (*(_BYTE *)(v9 + 20) & 5) != 0 || *(_DWORD *)(this + 48) )
  {
    if ( (*(_BYTE *)(this + 40) & 4) != 0 )
    {
      sub_5B3E20((int)dword_7E6B48, 0, this, 0);
    }
    else if ( *(_DWORD *)(this + 12) )
    {
      v10 = fabs(atan2(*(float *)(v9 + 24) * 1.2, flt_61C20C));
      v20 = v10 + v10;
      sub_593820(*(_DWORD *)(this + 16), v20, v20, 1);
      v11 = *(float *)(*(_DWORD *)(this + 28) + 24) + *(float *)(*(_DWORD *)(this + 28) + 24);
      *(float *)&v18 = flt_61C20C + v11;
      *(float *)&v16 = flt_61C20C - v11;
      sub_593D20(*(_DWORD *)(this + 16), v16, v18);
      sub_5B8910((_DWORD *)this, &v24, &v25, &v26);
      sub_5B3D50(dword_7E6B48, this);
      v12 = (_DWORD *)sub_597AE0(v4, 0);
      sub_5B5C30(v12, &v21, &v22, &v23);
      v19 = flt_61C20C * v23 - v26;
      v17 = flt_61C20C * v22 - v25;
      v15 = flt_61C20C * v21 - v24;
      sub_5934E0(*(_DWORD *)(this + 16), v15, v17, v19);
      sub_5932C0(*(_DWORD *)(this + 16), dword_61C210);
      sub_5931C0(*(float **)(this + 16));
      if ( (*(_BYTE *)(*(_DWORD *)(this + 28) + 20) & 5) != 0 )
        sub_5B3E20((int)dword_7E6B48, 0, this, 0);
      v13 = *(_DWORD *)(this + 48);
      *(_DWORD *)(this + 40) |= 8u;
      if ( v13 )
        v5 = -2;
    }
  }
  v14 = *(_DWORD *)(*(_DWORD *)(this + 16) + 604);
  if ( (*(_BYTE *)(v14 + 56) & 2) != 0 )
  {
    sub_5A72C0(v14, 2, 4);
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 604) + 56) &= ~0x400u;
  }
LABEL_25:
  if ( *(_DWORD *)(this + 48) )
    sub_5B8990(a2, 1);
  if ( *(_DWORD *)(this + 56) )
  {
    if ( a3 )
      sub_5B8990(a2, 1);
  }
  return v5;
}
