char __thiscall sub_4A1A90(int *this, int a2, int a3)
{
  int v3; // eax

  if ( a2 && a3 > 0 )
  {
    this[201] = a3;
    v3 = *this;
    this[199] = a2;
    (*(void (__stdcall **)(int))(v3 + 160))(1);
  }
  return 0;
}
