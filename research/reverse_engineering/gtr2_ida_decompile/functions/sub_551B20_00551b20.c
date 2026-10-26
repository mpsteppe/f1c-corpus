int __stdcall sub_551B20(int a1, int a2)
{
  _DWORD *v2; // esi
  int result; // eax
  int v4; // [esp+0h] [ebp-Ch]

  v2 = (_DWORD *)off_9034A4;
  if ( dword_82F4A0 < 1023 )
  {
    ++dword_82F4A0;
    off_9034A4 += 848;
  }
  *(float *)&v4 = dbl_FB1D18;
  sub_51B2A0(v2, 4, 19, 8, 255, v4, 3);
  result = a1;
  v2[2] = a1;
  v2[3] = a2;
  return result;
}
