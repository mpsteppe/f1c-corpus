int __thiscall sub_556930(_DWORD *this, int a2)
{
  int result; // eax

  do
  {
    result = this[14];
    if ( result && (dword_8B8E34 & result & *(_DWORD *)(a2 + 132)) != result )
      break;
    AnimationDispatchWithSkipFlag(a2);
    if ( this[17] )
      RecursiveStateTraversalWithFlagCheck(a2);
    result = this[16];
    if ( !result )
      break;
    this = (_DWORD *)this[19];
  }
  while ( this );
  return result;
}

