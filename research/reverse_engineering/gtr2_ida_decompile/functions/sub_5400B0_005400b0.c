int __thiscall sub_5400B0(_BYTE *this)
{
  int result; // eax

  if ( dword_BE1D10 )
    result = (*(int (__thiscall **)(int))(*(_DWORD *)dword_BE1D10 + 12))(dword_BE1D10);
  this[16] = 0;
  return result;
}
