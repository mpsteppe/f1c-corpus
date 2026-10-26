_DWORD *__stdcall sub_679080(int a1)
{
  _DWORD *result; // eax
  _DWORD *v2; // ecx
  int v3; // edx

  result = (_DWORD *)(**(int (__stdcall ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 172);
  *(_DWORD *)(a1 + 444) = result;
  *result = sub_679040;
  result[1] = sub_678BA0;
  result[2] = sub_678EB0;
  result[7] = sub_678940;
  result[24] = 0;
  v2 = result + 25;
  v3 = 16;
  do
  {
    *(v2 - 17) = sub_678940;
    *v2++ = 0;
    --v3;
  }
  while ( v3 );
  result[8] = sub_6787F0;
  result[22] = sub_6787F0;
  *(_DWORD *)(a1 + 220) = 0;
  *(_DWORD *)(a1 + 148) = 0;
  *(_DWORD *)(a1 + 420) = 0;
  result[3] = 0;
  result[4] = 0;
  result[6] = 0;
  result[41] = 0;
  return result;
}
