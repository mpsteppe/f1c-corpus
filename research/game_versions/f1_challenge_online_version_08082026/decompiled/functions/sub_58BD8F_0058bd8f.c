_DWORD *__cdecl sub_58BD8F(int a1, _DWORD *a2, int a3)
{
  _DWORD *result; // eax
  _DWORD v4[2]; // [esp+0h] [ebp-8h] BYREF

  if ( a1 )
  {
    sub_595550(v4, a3);
    result = a2;
    *a2 = v4[0];
    a2[1] = v4[1];
  }
  else
  {
    sub_59557D(&a3, a3);
    result = a2;
    *a2 = a3;
  }
  return result;
}
