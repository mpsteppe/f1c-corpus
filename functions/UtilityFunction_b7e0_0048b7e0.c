char __thiscall sub_48B7E0(int *this, int a2, int a3)
{
  int v3; // eax

  if ( a2 && a3 > 0 )
  {
    this[190] = a3;
    v3 = *this;
    this[188] = a2;
    (*(void (__stdcall **)(int))(v3 + 168))(1);
  }
  return 0;
}
