// positive sp value has been detected, the output may be wrong!
int __usercall sub_491888@<eax>(int a1@<eax>)
{
  int v1; // eax
  int *v2; // esi
  CHAR *v3; // eax
  int v4; // eax
  int v5; // edx
  int v7; // [esp-34h] [ebp-44h]
  char v8[8]; // [esp-30h] [ebp-40h] BYREF
  _DWORD v9[3]; // [esp-28h] [ebp-38h] BYREF
  char v10; // [esp-1Ch] [ebp-2Ch]
  _BYTE v11[27]; // [esp-1Bh] [ebp-2Bh] BYREF

  v10 = aNA_1[4];
  v9[2] = a1;
  memset(v11, 0, 0x38u);
  v1 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( v1 )
  {
    v2 = *(int **)(v1 + 28);
    if ( v2 )
    {
      v3 = dword_765324;
      if ( !dword_765324 )
        v3 = &byte_629120;
      v7 = (int)v3;
      v4 = (*(int (__thiscall **)(int *))(*v2 + 104))(v2);
      if ( v4 )
      {
        v5 = *v2;
        v9[0] = 0;
        (*(void (__thiscall **)(int *, int, _DWORD, _DWORD *))(v5 + 116))(v2, v4, 0, v9);
        sub_40FF80(v7, v8, 63);
      }
    }
  }
  sub_49EC60(v8);
  return 0;
}
