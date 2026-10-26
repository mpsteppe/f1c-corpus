int __thiscall sub_538940(int this)
{
  int result; // eax

  sub_5389B0(*(_DWORD *)(this + 2834));
  sub_5389B0(*(_DWORD *)(this + 2846));
  sub_5383D0(this, (int *)(this + 2854));
  for ( result = 18; result >= 3; --result )
  {
    if ( *(_WORD *)(this + 4 * (unsigned __int8)byte_5B7DEC[result] + 2676) )
      break;
  }
  *(_DWORD *)(this + 5787) += 3 * result + 17;
  return result;
}
