void __thiscall sub_4C88A0(int this, float a2)
{
  if ( *(_BYTE *)(this + 16) && dword_8AC4C8 && *(float *)(dword_8AC4C8 + 4) >= 0.0 )
  {
    *(_DWORD *)(this + 20) = 2;
    if ( a2 <= 0.0 )
      *(float *)(this + 24) = flt_7CF380;
    else
      *(float *)(this + 24) = *(float *)(dword_8AC4C8 + 4) / a2;
  }
}

