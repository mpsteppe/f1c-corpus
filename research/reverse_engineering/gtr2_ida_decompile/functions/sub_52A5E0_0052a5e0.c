char __thiscall sub_52A5E0(_DWORD *this)
{
  char result; // al
  float v2; // [esp+0h] [ebp-4h]

  if ( *(_DWORD *)dword_B72314 == 7 && this[1] == 1 )
  {
    result = byte_B6413C;
    if ( !byte_B6413C )
    {
      v2 = dbl_FB1D18;
      return sub_528C70(this[7], COERCE_FLOAT(&dword_82F4A0), (int)&unk_9204A0, v2, 0);
    }
  }
  return result;
}
