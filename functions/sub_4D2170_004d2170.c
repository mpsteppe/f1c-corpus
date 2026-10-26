char __thiscall sub_4D2170(float *this)
{
  int v1; // esi

  if ( this[45] + 30.0 <= dbl_8AFEA0 )
  {
    v1 = 0;
    if ( dword_5C329C <= 0 )
      return 1;
    while ( sub_4BC9B0((int *)(dword_7C54F0[v1] + 16436), 0, 0) )
    {
      if ( ++v1 >= dword_5C329C )
        return 1;
    }
  }
  return 0;
}
