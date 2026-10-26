int __thiscall sub_54FAA0(_DWORD *this)
{
  int v3; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h] BYREF

  sub_5DA960(&v3, 2048);
  sub_5DA960(&v4, 2048);
  if ( v3 < 104 && !dword_923E84[5654 * v3] && (*(_DWORD *)dword_B640C8 != 6 || dword_B64134 == 5) )
    sub_41D240();
  sub_5ED990(this[5]);
  return 0;
}
