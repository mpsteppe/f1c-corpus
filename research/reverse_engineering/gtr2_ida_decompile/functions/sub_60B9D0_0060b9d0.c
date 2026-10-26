unsigned int __thiscall sub_60B9D0(unsigned int *this)
{
  unsigned int result; // eax
  unsigned int v3; // ecx

  result = this[7];
  if ( result && *(char *)this < 0 )
  {
    result = (*(int (__stdcall **)(unsigned int))(*(_DWORD *)result + 48))(result);
    if ( !result )
    {
      v3 = this[4];
      this[8] = 0;
      result = *this & 0xFFFFFF7F;
      this[4] = v3 - 1;
      *this = result;
    }
  }
  return result;
}
