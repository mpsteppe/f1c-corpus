void __thiscall sub_4EFD80(int this, float a2)
{
  if ( *(_BYTE *)(this + 20) && dword_7D6BB4 && *(float *)(dword_7D6BB4 + 4) >= 0.0 )
  {
    *(_DWORD *)(this + 24) = 2;
    if ( a2 <= 0.0 )
      *(float *)(this + 28) = flt_767898;
    else
      *(float *)(this + 28) = *(float *)(dword_7D6BB4 + 4) / a2;
  }
}
