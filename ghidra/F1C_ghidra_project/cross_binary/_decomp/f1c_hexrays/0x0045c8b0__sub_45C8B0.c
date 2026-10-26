// f1c  0x0045c8b0  size=51
int __thiscall sub_45C8B0(_DWORD *this, char a2)
{
  int i; // esi
  int result; // eax

  *this = 0;
  if ( a2 )
  {
    this[1] = 0;
    this[2] = 0;
    this[3] = 0;
    this[4] = 0;
  }
  for ( i = 0; i < 104; ++i )
    result = sub_45C850(this, i);
  return result;
}
