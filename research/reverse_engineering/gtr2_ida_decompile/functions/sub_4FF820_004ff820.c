int __thiscall sub_4FF820(int this)
{
  int result; // eax
  int v2; // esi
  float v3; // [esp+0h] [ebp-10h]

  result = *(_DWORD *)(this + 752);
  if ( !result || result == 4 )
  {
    *(float *)(this + 760) = dbl_FB1D18;
    v2 = off_9034A4;
    if ( dword_82F4A0 < 1023 )
    {
      ++dword_82F4A0;
      off_9034A4 += 848;
    }
    v3 = dbl_FB1D18;
    sub_51B2A0(6, 5, 1, *(_DWORD *)(this + 4), LODWORD(v3), 0);
    *(_BYTE *)(v2 + 8) = 1;
    return sub_4FD580();
  }
  return result;
}
