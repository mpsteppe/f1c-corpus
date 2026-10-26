int __thiscall sub_475BF0(int *this)
{
  int result; // eax

  result = *this;
  if ( *(_BYTE *)(*this + 2153) )
  {
    *(_BYTE *)(result + 2153) = 0;
    dword_B698E8 = *(_DWORD *)(result + 2224);
    return sub_461600((char *)&dword_B69668);
  }
  return result;
}
