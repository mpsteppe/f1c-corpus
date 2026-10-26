int __thiscall sub_545250(_DWORD *this, _DWORD *a2)
{
  int v2; // edx
  int result; // eax
  int v5; // ecx

  v2 = a2[15] | 8;
  a2[19] = 0;
  a2[15] = v2;
  result = TreeNodeAccumulator(this, (int)a2);
  v5 = this[66];
  if ( v5 )
  {
    for ( result = *(_DWORD *)(v5 + 76); result; result = *(_DWORD *)(result + 76) )
      v5 = result;
    *(_DWORD *)(v5 + 76) = a2;
    a2[18] = v5;
  }
  else
  {
    this[66] = a2;
    a2[18] = 0;
  }
  return result;
}
