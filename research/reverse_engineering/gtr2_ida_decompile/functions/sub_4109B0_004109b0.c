char __thiscall sub_4109B0(_DWORD *this, int a2)
{
  char result; // al

  result = 1;
  if ( *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468) != *(_DWORD *)(*(&dword_91E088 + dword_91E080) + 22468) )
  {
    if ( !byte_B71B34 && dword_91E07C[15572] && a2 == 3 )
      return 0;
    else
      this[7] = -1;
  }
  return result;
}
