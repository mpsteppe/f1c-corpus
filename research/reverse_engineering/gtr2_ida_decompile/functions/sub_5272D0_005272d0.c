char __thiscall sub_5272D0(int *this)
{
  int **v2; // eax
  int *v3; // eax
  int **v4; // eax

  (*(void (__thiscall **)(int *))(this[445] + 48))(this + 445);
  while ( sub_527120(this, 1) )
    ;
  if ( this[474] <= 0 )
  {
    this[723211] = 0;
    this[723212] = 0;
    return 0;
  }
  else
  {
    v2 = (int **)this[471];
    this[473] = (int)v2;
    if ( v2 )
      v3 = *v2;
    else
      v3 = 0;
    this[723211] = *v3;
    v4 = (int **)this[472];
    this[473] = (int)v4;
    if ( v4 )
      this[723212] = **v4;
    else
      this[723212] = MEMORY[0];
    return 0;
  }
}
