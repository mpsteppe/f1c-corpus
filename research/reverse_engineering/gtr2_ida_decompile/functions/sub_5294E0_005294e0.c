char __thiscall sub_5294E0(_DWORD *this)
{
  int v1; // ecx
  char result; // al
  float v3; // [esp+0h] [ebp-4h]

  if ( *this == 1 )
  {
    v1 = this[2];
    result = *(_BYTE *)(v1 + 2892961);
    if ( !result && (*(_DWORD *)dword_B72314 != 8 || (result = byte_B6F118) == 0) )
    {
      v3 = dbl_FB1D18;
      return sub_528C70(v1, COERCE_FLOAT(&dword_75B490), 0, v3, 0);
    }
  }
  return result;
}
