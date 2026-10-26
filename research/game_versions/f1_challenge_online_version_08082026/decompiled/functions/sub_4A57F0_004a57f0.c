int __thiscall sub_4A57F0(_DWORD *this)
{
  int i; // esi
  int result; // eax

  for ( i = 0; ; ++i )
  {
    result = sub_4A5820(i);
    if ( !result && i > 0 )
      break;
  }
  this[42] = i;
  return result;
}
