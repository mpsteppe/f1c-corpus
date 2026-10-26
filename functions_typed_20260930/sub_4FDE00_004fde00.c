void __thiscall sub_4FDE00(int this, float a2)
{
  double v3; // st7
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c3

  if ( a2 > 0.60000002 )
  {
    v3 = a2;
    if ( v4 | v5 )
    {
      *(_DWORD *)(this + 36) = 0;
      *(float *)(this + 32) = (v3 - 0.60000002) * 20.000019;
    }
    else if ( v3 > 0.69999999 )
    {
      *(_DWORD *)(this + 32) = 1065353216;
      if ( a2 > 1.0 )
        *(_DWORD *)(this + 36) = 1065353216;
      else
        *(float *)(this + 36) = (a2 - 0.69999999) * 3.3333333;
    }
    else
    {
      *(_DWORD *)(this + 32) = 1065353216;
      *(_DWORD *)(this + 36) = 0;
    }
  }
  else
  {
    *(_DWORD *)(this + 32) = 0;
    *(_DWORD *)(this + 36) = 0;
  }
}

