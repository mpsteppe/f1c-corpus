int __userpurge sub_6B60A0@<eax>(int *a1@<esi>, char a2)
{
  int v2; // eax
  _BYTE *v3; // ecx
  bool v4; // zf
  int v5; // eax
  int result; // eax
  _BYTE *v7; // ecx
  int v8; // eax

  v2 = a1[6];
  v3 = *(_BYTE **)v2;
  *v3 = -1;
  *(_DWORD *)v2 = v3 + 1;
  v4 = (*(_DWORD *)(v2 + 4))-- == 1;
  if ( v4 && !(*(int (__stdcall **)(int *))(v2 + 12))(a1) )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 24;
    (*(void (__stdcall **)(int *))v5)(a1);
  }
  result = a1[6];
  v7 = *(_BYTE **)result;
  *v7 = a2;
  *(_DWORD *)result = v7 + 1;
  v4 = (*(_DWORD *)(result + 4))-- == 1;
  if ( v4 )
  {
    result = (*(int (__stdcall **)(int *))(result + 12))(a1);
    if ( !result )
    {
      v8 = *a1;
      *(_DWORD *)(v8 + 20) = 24;
      return (*(int (__stdcall **)(int *))v8)(a1);
    }
  }
  return result;
}
