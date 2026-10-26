char __stdcall sub_4861A0(int a1, int a2)
{
  char result; // al
  int v3; // [esp+8h] [ebp-8h] BYREF
  int v4; // [esp+Ch] [ebp-4h] BYREF

  if ( (_BYTE)a1 )
  {
    TwinFieldGetter(&a1, &v3);
    if ( a1 > 0 && v3 > 0 )
      PositionUpdate(a1, v3);
  }
  result = a2;
  if ( (_BYTE)a2 )
  {
    TwoChannel16BitReader(&a1, &v4, &v3, &a2);
    result = a1;
    if ( a1 || v4 || v3 || a2 )
      return MultiFieldStructWriter(a1, v4, v3, a2);
  }
  return result;
}

