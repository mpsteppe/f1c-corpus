void __thiscall sub_535080(int this, int a2)
{
  double v3; // st7
  int v4; // eax
  double v5; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c2
  float v9; // [esp+Ch] [ebp+4h]

  sub_5335D0((_DWORD *)(this + 156), a2);
  v3 = (double)a2;
  v4 = *(_DWORD *)(this + 40);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      *(float *)(this + 68) = v3;
    }
    else
    {
      v9 = (double)(v4 - 1) * *(float *)(this + 68) + v3;
      v5 = v9 / (double)*(int *)(this + 40);
      *(float *)(this + 68) = v5;
      if ( v7 | v8 )
      {
        *(_DWORD *)(this + 68) = 1065353216;
      }
      else if ( v5 > 22.0 )
      {
        *(_DWORD *)(this + 68) = 1102053376;
      }
    }
  }
}
