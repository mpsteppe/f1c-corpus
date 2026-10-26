int __thiscall sub_4E6020(_DWORD *this, char a2)
{
  int result; // eax
  int v3; // ebp
  int v4; // ebp
  int v5; // ebp

  result = dword_91E084 + 14824;
  if ( *(_DWORD *)(dword_91E084 + 14932) )
  {
    this[1] = 1;
  }
  else
  {
    do
    {
      v3 = this[1];
      if ( a2 )
      {
        v4 = v3 - 1;
        this[1] = v4;
        if ( v4 < 0 )
          this[1] = 9;
      }
      else
      {
        v5 = v3 + 1;
        this[1] = v5;
        if ( v5 >= 10 )
          this[1] = 0;
      }
    }
    while ( *(int *)(result + (this[1] << 6) + 40) <= 1 );
  }
  return result;
}
