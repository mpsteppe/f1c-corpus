int __thiscall sub_4E3350(_WORD *this, int a2, int a3)
{
  int result; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ecx

  result = 1;
  v5 = 0;
  if ( a2 > 1 )
  {
    do
      result = 1 << ++v5;
    while ( a2 > 1 << v5 );
  }
  LOWORD(v6) = 1;
  v7 = 0;
  if ( a3 > 1 )
  {
    do
      v6 = 1 << ++v7;
    while ( a3 > 1 << v7 );
  }
  this[7] = result;
  this[8] = v6;
  return result;
}
