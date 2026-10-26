int __thiscall sub_5932C0(int this, char a2)
{
  int result; // eax
  float *v4; // ebp
  void *v5; // edi
  double v6; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st4
  double v10; // st5
  double v11; // st5
  int v12; // [esp+8h] [ebp-10h]
  double v13; // [esp+8h] [ebp-10h]
  double v14; // [esp+10h] [ebp-8h]

  result = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)dword_7E8E58 + 44))(dword_7E8E58, this + 348, this + 412);
  if ( (a2 & 4) != 0 )
  {
    sub_590140(2, 0);
    v4 = (float *)(this + 476);
    v5 = (void *)(this + 476);
    if ( (a2 & 0x10) != 0 )
    {
      v12 = *(_DWORD *)(this + 84) / *(_DWORD *)(this + 88);
      v6 = 2.0 / ((double)v12 + (double)v12);
      v7 = 1.0 / (*(float *)(this + 8) - *(float *)(this + 4));
      v8 = *(float *)(this + 4);
      v9 = v8 - *(float *)(this + 8);
      memset(v5, 0, 0x40u);
      *v4 = 1.0;
      *(_DWORD *)(this + 520) = 0;
      *(_DWORD *)(this + 536) = 1065353216;
      v13 = v8 / v9;
    }
    else
    {
      v14 = 1.0 / *(float *)(this + 28);
      v6 = 1.0 / *(float *)(this + 32);
      v7 = *(float *)(this + 8) / (*(float *)(this + 8) - *(float *)(this + 4));
      v10 = *(float *)(this + 4) * v7;
      memset(v5, 0, 0x40u);
      v13 = -v10;
      if ( (*(_BYTE *)(this + 128) & 0x10) != 0 )
        v11 = -v14;
      else
        v11 = v14;
      *v4 = v11;
      *(_DWORD *)(this + 520) = 1065353216;
      *(_DWORD *)(this + 536) = 0;
    }
    *(float *)(this + 496) = v6;
    *(float *)(this + 516) = v7;
    *(float *)(this + 532) = v13;
    sub_590140(1, 0);
    result = sub_5B4C70(4, this + 476);
  }
  if ( (a2 & 2) != 0 )
    result = sub_5B4C70(2, this + 348);
  if ( (a2 & 8) != 0 )
    return sub_5B4E60(this);
  return result;
}
