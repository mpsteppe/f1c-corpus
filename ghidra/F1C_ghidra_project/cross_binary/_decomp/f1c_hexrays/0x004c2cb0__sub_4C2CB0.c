// f1c  0x004c2cb0  size=126
void __thiscall sub_4C2CB0(int this, int a2)
{
  int v2; // eax
  double v3; // st7
  double v4; // st6
  double v5; // st7
  double v6; // st7
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c2
  float v10; // [esp+Ch] [ebp+4h]

  v2 = *(_DWORD *)(this + 40);
  if ( v2 <= 1 )
  {
    if ( v2 == 1 )
      v3 = *(float *)(this + 72);
    else
      v3 = *(float *)&a2;
  }
  else
  {
    v3 = (double)(v2 - 1) * *(float *)(this + 72);
  }
  v4 = (double)a2;
  v5 = v3 + v4;
  if ( v2 <= 0 )
  {
    v10 = v4;
    *(float *)(this + 72) = v10;
  }
  v6 = v5 / (double)v2;
  *(float *)(this + 72) = v6;
  if ( v8 | v9 )
  {
    *(_DWORD *)(this + 72) = 1065353216;
  }
  else if ( v6 > 22.0 )
  {
    *(_DWORD *)(this + 72) = 1102053376;
  }
}
