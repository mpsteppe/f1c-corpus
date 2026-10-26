int __thiscall sub_56EAD0(int *this, int a2)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( *this <= 0 )
    return 0;
  for ( i = 0; sub_588410(a2, *(_DWORD *)(i + this[1])); i += 580 )
  {
    if ( ++v3 >= *this )
      return 0;
  }
  return this[1] + 580 * v3;
}

