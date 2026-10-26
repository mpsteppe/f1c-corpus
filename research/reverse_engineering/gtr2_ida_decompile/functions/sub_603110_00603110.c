int __stdcall sub_603110(int *a1, int a2, int a3)
{
  int result; // eax

  result = a3;
  if ( !a3 )
    result = *a1;
  if ( (*a1 & 0x2000) != 0 || (result & 0xC) != 0 )
    return (*(int (__stdcall **)(int))(*(_DWORD *)a2 + 8))(a2);
  return result;
}
