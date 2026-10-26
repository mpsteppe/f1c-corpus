int __stdcall sub_4D2260(int a1, int a2)
{
  _DWORD *v2; // esi
  int result; // eax
  int v4; // [esp+0h] [ebp-Ch]

  v2 = (_DWORD *)dword_8AAE64;
  if ( dword_83EE60 < 1023 )
  {
    ++dword_83EE60;
    dword_8AAE64 += 432;
  }
  *(float *)&v4 = dbl_8AFEA0;
  ProgressBarEventEncode(v2, 4, 21, 8, 255, v4, 1);
  result = a1;
  v2[2] = a1;
  v2[3] = a2;
  return result;
}

