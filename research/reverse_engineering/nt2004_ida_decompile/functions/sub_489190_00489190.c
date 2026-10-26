char __fastcall sub_489190(_DWORD *a1, int a2, int a3)
{
  char result; // al
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = (int)a1;
  result = sub_489020(a1, &v4);
  if ( result )
  {
    result = v4;
    if ( v4 > 0 )
    {
      if ( (dword_769920 & v4) != 0 )
      {
        result = ~(_BYTE)v4;
        dword_769920 &= ~v4;
      }
      else
      {
        dword_769920 |= v4;
      }
    }
  }
  return result;
}
