int __usercall sub_6B6460@<eax>(int *a1@<eax>)
{
  int v2; // eax
  _BYTE *v3; // ecx
  bool v4; // zf
  int v5; // eax
  int v6; // eax
  _BYTE *v7; // ecx
  int v8; // eax
  int v9; // eax
  _BYTE *v10; // ecx
  int v11; // ebx
  int v12; // eax
  int result; // eax
  _BYTE *v14; // ecx
  int v15; // ecx
  int v16; // eax

  sub_6B60A0(a1, 221);
  v2 = a1[6];
  v3 = *(_BYTE **)v2;
  *v3 = 0;
  *(_DWORD *)v2 = v3 + 1;
  v4 = (*(_DWORD *)(v2 + 4))-- == 1;
  if ( v4 && !(*(int (__stdcall **)(int *))(v2 + 12))(a1) )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 24;
    (*(void (__stdcall **)(int *))v5)(a1);
  }
  v6 = a1[6];
  v7 = *(_BYTE **)v6;
  *v7 = 4;
  *(_DWORD *)v6 = v7 + 1;
  v4 = (*(_DWORD *)(v6 + 4))-- == 1;
  if ( v4 && !(*(int (__stdcall **)(int *))(v6 + 12))(a1) )
  {
    v8 = *a1;
    *(_DWORD *)(v8 + 20) = 24;
    (*(void (__stdcall **)(int *))v8)(a1);
  }
  v9 = a1[6];
  v10 = *(_BYTE **)v9;
  v11 = a1[50];
  *v10 = BYTE1(v11);
  *(_DWORD *)v9 = v10 + 1;
  v4 = (*(_DWORD *)(v9 + 4))-- == 1;
  if ( v4 && !(*(int (__stdcall **)(int *))(v9 + 12))(a1) )
  {
    v12 = *a1;
    *(_DWORD *)(v12 + 20) = 24;
    (*(void (__stdcall **)(int *))v12)(a1);
  }
  result = a1[6];
  v14 = *(_BYTE **)result;
  *v14 = v11;
  *(_DWORD *)result = v14 + 1;
  v15 = *(_DWORD *)(result + 4) - 1;
  *(_DWORD *)(result + 4) = v15;
  if ( !v15 )
  {
    result = (*(int (__stdcall **)(int *))(result + 12))(a1);
    if ( !result )
    {
      v16 = *a1;
      *(_DWORD *)(v16 + 20) = 24;
      return (*(int (__stdcall **)(int *))v16)(a1);
    }
  }
  return result;
}
