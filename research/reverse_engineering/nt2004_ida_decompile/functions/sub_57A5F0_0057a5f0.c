int __thiscall sub_57A5F0(FILE **this, int Offset)
{
  FILE *v2; // eax
  FILE *v3; // ecx

  v2 = this[4];
  v3 = *this;
  if ( v2 )
    return sub_5369D0((int)v3, Offset, 1);
  else
    return fseek(v3, Offset, 1);
}
