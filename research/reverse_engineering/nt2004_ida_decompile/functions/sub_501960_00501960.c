int __thiscall sub_501960(int **this)
{
  int **v2; // esi
  int v3; // edi
  int result; // eax

  v2 = this + 9;
  v3 = 5;
  do
  {
    if ( *v2 )
      result = sub_501600(*v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  this[4] = (int *)-1;
  return result;
}
