void __thiscall sub_4E61F0(int this, int a2)
{
  int v2; // eax
  double v3; // st7
  double v4; // st7
  float v5; // [esp+8h] [ebp+4h]

  v2 = *(_DWORD *)(this + 40);
  v3 = (double)a2;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      *(float *)(this + 68) = v3;
    }
    else
    {
      v5 = (double)(v2 - 1) * *(float *)(this + 68) + v3;
      v4 = v5 / (double)*(int *)(this + 40);
      *(float *)(this + 68) = v4;
      if ( v4 < 1.0 )
        *(_DWORD *)(this + 68) = 1065353216;
    }
  }
}
