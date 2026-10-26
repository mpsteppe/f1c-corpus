int __thiscall sub_462B30(_DWORD *this)
{
  int result; // eax
  int v3; // edi
  _DWORD *v4; // ebx
  _DWORD *v5; // [esp+8h] [ebp-4h]

  result = this[1628];
  v3 = 0;
  if ( result > 0 )
  {
    v4 = this + 1580;
    v5 = this + 188;
    do
    {
      if ( !(unsigned __int8)sub_462C60(2) )
        sub_464350(*v4);
      result = this[1628];
      ++v3;
      ++v4;
      v5 += 29;
    }
    while ( v3 < result );
  }
  return result;
}
