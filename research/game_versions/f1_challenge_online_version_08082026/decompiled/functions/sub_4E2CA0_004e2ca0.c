void __thiscall sub_4E2CA0(int this, float a2)
{
  int v3; // ecx
  double v4; // st7
  int v5; // eax
  float v6; // [esp+0h] [ebp-4h]

  if ( a2 != *(float *)(this + 2416) )
  {
    v3 = *(_DWORD *)(this + 4);
    v4 = a2 / *(float *)(this + 2416);
    *(float *)(this + 2416) = a2;
    v6 = v4;
    sub_4E2A00(v3, v6, 0);
    v5 = *(_DWORD *)(*(_DWORD *)(this + 4) + 68);
    if ( v5 )
      sub_4E2A00(v5, v6, 1);
  }
}
