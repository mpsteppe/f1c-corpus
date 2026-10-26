void __thiscall sub_50E010(int this, float a2)
{
  int v3; // ecx
  double v4; // st7
  int v5; // eax
  float v6; // [esp+0h] [ebp-4h]

  if ( a2 != *(float *)(this + 2880) )
  {
    v3 = *(_DWORD *)(this + 4);
    v4 = a2 / *(float *)(this + 2880);
    *(float *)(this + 2880) = a2;
    v6 = v4;
    sub_50D0D0(v3, v6, 0);
    v5 = *(_DWORD *)(*(_DWORD *)(this + 4) + 68);
    if ( v5 )
      sub_50D0D0(v5, v6, 1);
  }
}
