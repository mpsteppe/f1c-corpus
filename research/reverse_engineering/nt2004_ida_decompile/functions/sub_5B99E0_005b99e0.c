_DWORD *__fastcall sub_5B99E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *result; // eax
  _DWORD *v10; // esi

  result = malloc(0x620u);
  v10 = result;
  if ( result )
  {
    result[390] = a7;
    result[391] = a8;
    result[387] = 0;
    sub_5BC150(a2, a3, a4, sub_5B9A60, result);
    sub_5BBAC0(a6, sub_5B9BC0, v10);
    return v10;
  }
  return result;
}
