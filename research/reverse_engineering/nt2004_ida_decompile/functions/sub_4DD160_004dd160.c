bool __thiscall sub_4DD160(_DWORD *this, int a2)
{
  int v2; // eax

  v2 = this[14];
  return (v2 != 1 && v2 != 3 || dword_767310 < a2 && v2 != 3 && dword_75CBB0 == 5)
      && dword_767310 >= a2
      && dword_75CBA8 == 5
      && (dword_75CBB4 == 5 || dword_75CBB4 == 6 || dword_75CBB4 == 8);
}
