// f1c  0x004b4760  size=59
char __stdcall sub_4B4760(int a1, _DWORD *a2)
{
  bool v2; // zf
  char result; // al

  if ( a1 )
    return 0;
  if ( (*a2 & 0xFC0000) != 0 )
    return 0;
  if ( (unsigned __int8)*a2 >= 0x68u )
    return 0;
  v2 = sub_4B4840(0, (unsigned __int8)*a2, &a1) == 0;
  result = 1;
  if ( v2 )
    return 0;
  return result;
}
