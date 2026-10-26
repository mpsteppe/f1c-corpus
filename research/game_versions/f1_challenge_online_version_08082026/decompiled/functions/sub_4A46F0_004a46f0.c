int __thiscall sub_4A46F0(_DWORD *this, int a2, char a3, int a4)
{
  int result; // eax
  int v5; // edx

  result = a2;
  v5 = *(_DWORD *)(a2 + 4);
  if ( a3 )
    this[v5] = a2;
  else
    this[v5] = 0;
  return result;
}
