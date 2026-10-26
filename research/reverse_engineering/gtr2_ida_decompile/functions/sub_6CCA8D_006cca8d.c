int __thiscall sub_6CCA8D(_DWORD *this, int a2, int a3)
{
  int *v4; // ecx
  int v5; // edi
  unsigned int v6; // edi
  _DWORD *v7; // edx
  int v8; // eax
  int v9; // ecx
  _DWORD *v11; // [esp+Ch] [ebp-20h] BYREF
  _DWORD *v12; // [esp+10h] [ebp-1Ch] BYREF
  _DWORD *v13; // [esp+14h] [ebp-18h] BYREF
  _DWORD *v14; // [esp+18h] [ebp-14h]
  int v15; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+20h] [ebp-Ch]
  unsigned int v17; // [esp+24h] [ebp-8h]
  _DWORD *v18; // [esp+28h] [ebp-4h]
  unsigned int i; // [esp+38h] [ebp+Ch]

  v4 = (int *)this[64];
  v15 = v4[3];
  v5 = *v4;
  v14 = (_DWORD *)v4[4];
  v6 = v5 & 0xFFFFF;
  sub_680D41(v4, 0, &v11);
  sub_680D41((_DWORD *)this[64], 1, &v12);
  sub_680D41((_DWORD *)this[64], 2, &v13);
  v16 = 0;
  if ( a3 )
  {
    for ( i = 0; i < 3; ++i )
    {
      if ( v16 )
        break;
      v7 = (&v11)[i];
      if ( v7 )
      {
        v17 = 0;
        if ( v6 )
        {
          v8 = this[5];
          v9 = 0;
          v18 = v7;
          while ( (*(_BYTE *)(v9 + *(_DWORD *)(v8 + 4 * *v18) + 3) & 1) == 0 )
          {
            ++v17;
            ++v18;
            v9 += 128;
            if ( v17 >= v6 )
              goto LABEL_11;
          }
          v16 = 1;
        }
      }
LABEL_11:
      ;
    }
  }
  return sub_6CB29C(this, a2, v14, v15, v11, v12, v13, v6, 0, 0, 0, v16);
}
