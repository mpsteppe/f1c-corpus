// f1c  0x0048ea60  size=52
bool __thiscall sub_48EA60(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int v4; // eax
  bool result; // al

  v3 = this[5];
  result = 0;
  if ( a2 > v3 && a2 < v3 + this[3] )
  {
    v4 = this[6];
    if ( a3 > v4 && a3 < v4 + this[4] )
      return 1;
  }
  return result;
}
