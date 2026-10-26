int __thiscall sub_540FC0(int *this, int *a2)
{
  int v3; // edx
  int v4; // eax
  int v5; // eax

  v3 = 0;
  if ( a2 )
  {
    v4 = *a2;
    if ( (*a2 & 2) != 0 )
      v3 = 8;
    if ( (v4 & 0x10) != 0 )
      v3 |= 8u;
    if ( (v4 & 0x20) != 0 )
      v3 |= 0x200u;
    v5 = (*(int (__stdcall **)(int, int, int, int, _DWORD, int *))(*(_DWORD *)this[1088] + 96))(
           this[1088],
           2 * a2[1],
           v3,
           101,
           0,
           a2 + 6);
    *this = v5;
    if ( v5 )
    {
      sub_53C590(-1, aErrorCreatingI);
      return -1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    sub_53C590(-1, aInvalidParamet);
    return -1;
  }
}
