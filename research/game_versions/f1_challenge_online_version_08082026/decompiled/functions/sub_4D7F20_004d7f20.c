_DWORD *__stdcall sub_4D7F20(int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *result; // eax

  result = (_DWORD *)sub_4D7FA0(a4);
  if ( result )
  {
    sub_5531F0(a1, &a4, &a1, 0);
    result = a3;
    *a3 = a2 - a4 / 2;
  }
  return result;
}
