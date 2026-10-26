// f1c  0x004b7a00  size=131
char __thiscall sub_4B7A00(int *this)
{
  int **v2; // eax
  int *v3; // eax
  int **v4; // eax
  char result; // al

  sub_566D70(this + 441);
  while ( sub_4B7860(this, 1) )
    ;
  if ( this[456] <= 0 )
  {
    this[972] = 0;
    this[973] = 0;
    return 0;
  }
  else
  {
    v2 = (int **)this[453];
    this[455] = (int)v2;
    if ( v2 )
      v3 = *v2;
    else
      v3 = 0;
    this[972] = *v3;
    v4 = (int **)this[454];
    this[455] = (int)v4;
    if ( v4 )
    {
      this[973] = **v4;
      return 0;
    }
    else
    {
      result = 0;
      this[973] = MEMORY[0];
    }
  }
  return result;
}
