int __thiscall sub_4BBF20(int *this)
{
  _DWORD *v2; // ecx
  int v4; // [esp+0h] [ebp-Ch]

  if ( dword_83EE60 >= 1023 )
  {
    v2 = (_DWORD *)dword_8AAE64;
  }
  else
  {
    ++dword_83EE60;
    v2 = (_DWORD *)dword_8AAE64;
    dword_8AAE64 += 432;
  }
  *(float *)&v4 = dbl_8AFEA0;
  ProgressBarEventEncode(v2, 4, 24, 0, this[1], v4, 0);
  return this[17];
}
