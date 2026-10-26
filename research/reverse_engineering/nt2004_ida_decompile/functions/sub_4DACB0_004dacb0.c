int __thiscall sub_4DACB0(void *this)
{
  int result; // eax

  if ( dword_768504 && *(_DWORD *)this == 1 )
    sub_4D9890((_DWORD **)this + 2);
  sub_4D97F0((int *)this + 2);
  sub_4D2780(byte_7D4490);
  result = *((_DWORD *)this + 2);
  *((_BYTE *)this + 4) = 0;
  *(_DWORD *)(result + 2164) = 5;
  return result;
}
