int __stdcall sub_6B6D30(int *a1, char a2, unsigned int a3)
{
  int v3; // eax
  int v4; // eax
  _BYTE *v5; // ecx
  bool v6; // zf
  int v7; // eax
  int result; // eax
  _BYTE *v9; // ecx
  int v10; // ecx
  int v11; // eax

  if ( a3 > 0xFFFD )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 11;
    (*(void (__stdcall **)(int *))v3)(a1);
  }
  sub_6B60A0(a1, a2);
  v4 = a1[6];
  v5 = *(_BYTE **)v4;
  *v5 = (unsigned __int16)(a3 + 2) >> 8;
  *(_DWORD *)v4 = v5 + 1;
  v6 = (*(_DWORD *)(v4 + 4))-- == 1;
  if ( v6 && !(*(int (__stdcall **)(int *))(v4 + 12))(a1) )
  {
    v7 = *a1;
    *(_DWORD *)(v7 + 20) = 24;
    (*(void (__stdcall **)(int *))v7)(a1);
  }
  result = a1[6];
  v9 = *(_BYTE **)result;
  *v9 = a3 + 2;
  *(_DWORD *)result = v9 + 1;
  v10 = *(_DWORD *)(result + 4) - 1;
  *(_DWORD *)(result + 4) = v10;
  if ( !v10 )
  {
    result = (*(int (__stdcall **)(int *))(result + 12))(a1);
    if ( !result )
    {
      v11 = *a1;
      *(_DWORD *)(v11 + 20) = 24;
      return (*(int (__stdcall **)(int *))v11)(a1);
    }
  }
  return result;
}
