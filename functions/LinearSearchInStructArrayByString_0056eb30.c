int __thiscall sub_56EB30(int *this, int a2)
{
  int v3; // edi
  int i; // ebx

  v3 = 0;
  if ( this[6] <= 0 )
    return 0;
  for ( i = 0; !*(_DWORD *)(i + this[7]) || sub_588410(a2, *(_DWORD *)(i + this[7])); i += 72 )
  {
    if ( ++v3 >= this[6] )
      return 0;
  }
  return this[7] + 72 * v3;
}
