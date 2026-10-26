void __thiscall sub_501DE0(_DWORD *this, char a2, char a3)
{
  int v4; // eax
  int v5; // ecx

  if ( this[2937] == 5 )
  {
    v4 = 1 << a2;
    v5 = this[3974];
    if ( a3 )
      this[3974] = v4 | v5;
    else
      this[3974] = ~v4 & v5;
  }
}
