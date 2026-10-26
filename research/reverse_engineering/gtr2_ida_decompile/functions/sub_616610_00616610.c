int __thiscall sub_616610(_DWORD *this, int a2)
{
  int result; // eax

  for ( result = this[2]; result; --a2 )
  {
    if ( a2 <= 0 )
      break;
    result = *(_DWORD *)(result + 4);
  }
  return result;
}
