int __stdcall UIMessageCompose(int a1, int a2)
{
  int v2; // esi
  int result; // eax
  _BYTE v4[8]; // [esp+8h] [ebp-8h] BYREF

  v2 = 0;
  if ( sub_49B9A0() )
  {
    v4[0] = -126;
    v2 = 1;
  }
  if ( FuelWeightComputation() )
    v4[v2++] = 68;
  result = sub_49BA30();
  if ( result == 1 )
  {
    v4[v2] = -116;
  }
  else
  {
    result = sub_49BA30();
    if ( result != 2 )
      goto LABEL_10;
    v4[v2] = -115;
  }
  ++v2;
LABEL_10:
  if ( v2 > 0 )
  {
    v4[v2] = 0;
    return UITextRenderWithScale((int)v4, a1 + 275, a2, 0xFFFFFF, 1, 3, 2.0, 2.0);
  }
  return result;
}
