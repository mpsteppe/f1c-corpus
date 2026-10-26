void __thiscall sub_551970(int this)
{
  int i; // ebp
  int v3; // esi
  void *v4; // ecx
  double v5; // st7

  if ( dword_B64134 == 3 && *(float *)(this + 220) + 4.0 < dbl_FB1D18 )
  {
    for ( i = 0; i < dword_757C10; ++i )
    {
      v3 = *(&dword_91E088 + i);
      if ( *(_BYTE *)(v3 + 15572) && (unsigned __int8)sub_54F270((void *)(this + 480), *(&dword_91E088 + i)) )
      {
        sub_54F160(v4, v3);
        *(_DWORD *)(this + 476) = 0;
      }
    }
  }
  v5 = *(float *)(this + 476) - dbl_FB1D10;
  *(float *)(this + 476) = v5;
  if ( v5 <= 0.0 )
  {
    *(_DWORD *)(this + 476) = 1065353216;
    sub_54F340(this + 480);
  }
}
