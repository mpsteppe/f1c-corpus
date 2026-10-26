int __userpurge sub_64E479@<eax>(int a1@<edi>, int a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  int result; // eax
  int v6; // edi
  int v7; // eax
  unsigned int v8; // ecx
  char *v9; // eax
  char *v10; // edx
  int v12[7]; // [esp+8h] [ebp-38h] BYREF
  unsigned int v13; // [esp+24h] [ebp-1Ch]
  _DWORD v14[2]; // [esp+28h] [ebp-18h] BYREF
  _DWORD v15[2]; // [esp+30h] [ebp-10h] BYREF
  unsigned int v16; // [esp+38h] [ebp-8h]
  unsigned int v17; // [esp+3Ch] [ebp-4h]

  v3 = a2;
  (*(void (__stdcall **)(int, int *))(*(_DWORD *)a2 + 48))(a2, v12);
  v4 = 0;
  result = (*(int (__stdcall **)(int, _DWORD *, _DWORD, _DWORD))(*(_DWORD *)v3 + 52))(v3, v15, 0, 0);
  if ( result >= 0 )
  {
    v6 = a3;
    v7 = (*(int (__stdcall **)(int, _DWORD *, _DWORD, _DWORD, int))(*(_DWORD *)a3 + 52))(a3, v14, 0, 0, a1);
    if ( v7 >= 0 )
    {
      if ( v12[0] == 827611204
        || v12[0] == 844388420
        || v12[0] == 861165636
        || v12[0] == 877942852
        || v12[0] == 894720068 )
      {
        v8 = (v13 + 3) >> 2;
        v13 = v8;
      }
      else
      {
        v8 = v13;
      }
      v16 = v14[0];
      if ( v14[0] >= v15[0] )
        v16 = v15[0];
      v9 = (char *)v15[1];
      v10 = (char *)v14[1];
      v17 = 0;
      if ( v8 )
      {
        do
        {
          qmemcpy(v10, v9, v16);
          v9 += v15[0];
          v10 += v14[0];
          ++v17;
        }
        while ( v17 < v13 );
        v6 = a3;
        v3 = a2;
        v4 = 0;
      }
      (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 56))(v6);
    }
    else
    {
      v4 = v7;
    }
    (*(void (__cdecl **)(int))(*(_DWORD *)v3 + 56))(v3);
    return v4;
  }
  return result;
}
