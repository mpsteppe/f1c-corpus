int __stdcall sub_6B6DC0(int *a1, char a2)
{
  int result; // eax
  _BYTE *v3; // ecx
  int v5; // eax

  result = a1[6];
  v3 = *(_BYTE **)result;
  *v3 = a2;
  *(_DWORD *)result = v3 + 1;
  if ( (*(_DWORD *)(result + 4))-- == 1 )
  {
    result = (*(int (__stdcall **)(int *))(result + 12))(a1);
    if ( !result )
    {
      v5 = *a1;
      *(_DWORD *)(v5 + 20) = 24;
      return (*(int (__stdcall **)(int *))v5)(a1);
    }
  }
  return result;
}
