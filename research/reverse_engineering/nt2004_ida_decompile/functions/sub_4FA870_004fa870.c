int __thiscall sub_4FA870(unsigned __int8 *this, int a2)
{
  int result; // eax
  int v3; // eax

  result = this[a2 + 304];
  if ( result == 255 )
    return *(_DWORD *)(dword_75AAD0[0] + 88);
  if ( dword_630030[6326 * result] != -1 )
    return result;
  v3 = 0;
  if ( (int)NumOfElements <= 0 )
    return *(_DWORD *)(dword_75AAD0[0] + 88);
  while ( *(_DWORD *)(dword_75AAD0[v3] + 20884) != a2 + 2 )
  {
    if ( ++v3 >= (int)NumOfElements )
      return *(_DWORD *)(dword_75AAD0[0] + 88);
  }
  return *(_DWORD *)(dword_75AAD0[v3] + 20840);
}
