void __thiscall sub_4CE720(_DWORD *this, char a2, char a3)
{
  int v4; // eax
  int v5; // ecx

  if ( this[2427] == 5 )
  {
    v4 = 1 << a2;
    v5 = this[3408];
    if ( a3 )
      this[3408] = v4 | v5;
    else
      this[3408] = ~v4 & v5;
  }
}
