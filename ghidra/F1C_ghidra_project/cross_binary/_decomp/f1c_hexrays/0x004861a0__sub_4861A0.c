// f1c  0x004861a0  size=151
char __stdcall sub_4861A0(int a1, int a2)
{
  char result; // al
  int v3; // [esp+8h] [ebp-8h] BYREF
  int v4; // [esp+Ch] [ebp-4h] BYREF

  if ( (_BYTE)a1 )
  {
    sub_499EE0(&a1, &v3);
    if ( a1 > 0 && v3 > 0 )
      sub_49AA70(a1, v3);
  }
  result = a2;
  if ( (_BYTE)a2 )
  {
    sub_499F00(&a1, &v4, &v3, &a2);
    result = a1;
    if ( a1 || v4 || v3 || a2 )
      return sub_49AA10(a1, v4, v3, a2);
  }
  return result;
}
