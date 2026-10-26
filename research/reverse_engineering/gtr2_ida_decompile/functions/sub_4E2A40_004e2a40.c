int __thiscall sub_4E2A40(int *this, int a2)
{
  int result; // eax

  if ( !a2 )
    return -1;
  result = *this;
  if ( *this )
  {
    for ( ; *(_DWORD *)(result + 104); result = *(_DWORD *)(result + 104) )
      ;
    *(_DWORD *)(result + 104) = a2;
    return 0;
  }
  else
  {
    *this = a2;
  }
  return result;
}
