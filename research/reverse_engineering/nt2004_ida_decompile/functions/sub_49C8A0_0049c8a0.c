char __stdcall sub_49C8A0(int a1, int a2)
{
  char result; // al
  int v3; // [esp+8h] [ebp-8h] BYREF
  int v4; // [esp+Ch] [ebp-4h] BYREF

  if ( (_BYTE)a1 )
  {
    sub_4B0F00(&a1, &v3);
    if ( a1 > 0 && v3 > 0 )
      sub_4B14A0(a1, v3);
  }
  result = a2;
  if ( (_BYTE)a2 )
  {
    sub_4B0F20(&a1, &v4, &v3, &a2);
    result = a1;
    if ( a1 || v4 || v3 || a2 )
      return sub_4B1440(a1, v4, v3, a2);
  }
  return result;
}
