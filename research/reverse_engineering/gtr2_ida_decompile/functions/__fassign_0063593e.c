_DWORD *__cdecl _fassign(int a1, _DWORD *a2, int a3)
{
  _DWORD *result; // eax
  _DWORD v4[2]; // [esp+0h] [ebp-8h] BYREF

  if ( a1 )
  {
    sub_640977(v4, a3);
    result = a2;
    *a2 = v4[0];
    result[1] = v4[1];
  }
  else
  {
    sub_6409B4(&a1, a3);
    result = a2;
    *a2 = a1;
  }
  return result;
}
