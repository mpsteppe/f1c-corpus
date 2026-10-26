int __thiscall sub_52BDE0(int *this)
{
  _DWORD *v2; // ecx
  int v4; // [esp+0h] [ebp-Ch]

  if ( dword_82F4A0 >= 1023 )
  {
    v2 = (_DWORD *)off_9034A4;
  }
  else
  {
    ++dword_82F4A0;
    v2 = (_DWORD *)off_9034A4;
    off_9034A4 += 848;
  }
  *(float *)&v4 = dbl_FB1D18;
  sub_51B2A0(v2, 4, 23, 0, this[1], v4, 3);
  return this[32];
}
