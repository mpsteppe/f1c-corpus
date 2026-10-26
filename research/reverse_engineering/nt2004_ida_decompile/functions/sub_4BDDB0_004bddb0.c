int __thiscall sub_4BDDB0(_DWORD *this)
{
  int result; // eax
  const char *v3; // ecx
  const char *v4; // eax
  const char *v5; // ecx
  const char *v6; // eax
  int *v7; // eax
  int v8; // esi
  int v9; // eax
  int *v10; // eax
  int v11; // [esp+Ch] [ebp-224h] BYREF
  int v12; // [esp+10h] [ebp-220h] BYREF
  int v13; // [esp+14h] [ebp-21Ch] BYREF
  float v14[3]; // [esp+18h] [ebp-218h] BYREF
  char v15[12]; // [esp+24h] [ebp-20Ch] BYREF
  char Buffer[253]; // [esp+30h] [ebp-200h] BYREF
  __int16 v17; // [esp+12Dh] [ebp-103h]
  char v18; // [esp+12Fh] [ebp-101h]
  char ArgList[253]; // [esp+130h] [ebp-100h] BYREF
  __int16 v20; // [esp+22Dh] [ebp-3h]
  char v21; // [esp+22Fh] [ebp-1h]

  result = 0;
  ArgList[0] = byte_629120;
  memset(&ArgList[1], 0, 0xFCu);
  v20 = 0;
  v21 = 0;
  if ( dword_7DA9B8 )
  {
    result = this[51];
    if ( result )
    {
      Buffer[0] = byte_629120;
      memset(&Buffer[1], 0, 0xFCu);
      v17 = 0;
      v18 = 0;
      v12 = 0;
      v11 = 0;
      v13 = 0;
      sub_5924D0(dword_7DA988, (int)&v12, (int)aPitsMas);
      v3 = (const char *)dword_62A0B8;
      if ( !dword_62A0B8 )
        v3 = &byte_629120;
      v4 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v4 = &byte_629120;
      sprintf(Buffer, "%s%s%s", v4, v3, aCdbMas);
      sub_5924D0(dword_7DA988, (int)&v11, (int)Buffer);
      v5 = (const char *)dword_62A0B8;
      if ( !dword_62A0B8 )
        v5 = &byte_629120;
      v6 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v6 = &byte_629120;
      sprintf(Buffer, "%s%s%s", v6, v5, aCmapsMas);
      sub_5924D0(dword_7DA988, (int)&v13, (int)Buffer);
      sub_5974A0(this[51]);
      if ( sub_596220(dword_7DA9B8) )
      {
        sub_591C90(0, ArgList);
        if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_12, 794) )
          sub_500FE0((int)&unk_7D7920, aUnableToSetupA, (char)ArgList);
      }
      sub_4BE390(this);
      if ( sub_42DBC0() )
      {
        sub_4F8F10(dword_75AACC, v14, v15);
        sub_404ED0(&flt_628F60, *(_DWORD *)(dword_75AACC + 25264), v14, 0);
        sub_4BEA40(v14, v15);
      }
      sub_59ECC0(1, 0, 0, 0);
      *this = 1;
      sub_4BEC30(this);
      v7 = (int *)this[46];
      this[48] = v7;
      if ( v7 )
      {
        v8 = *v7;
        if ( *v7 )
        {
          do
          {
            if ( *(_DWORD *)(v8 + 100) )
            {
              sub_59E050(*(_DWORD *)(v8 + 76), *(_DWORD *)(v8 + 80), *(_DWORD *)(v8 + 84));
              sub_59E0F0(*(float *)(v8 + 88), *(float *)(v8 + 92), *(float *)(v8 + 96));
            }
            v9 = this[48];
            if ( !v9 )
              break;
            v10 = *(int **)(v9 + 4);
            this[48] = v10;
            if ( !v10 )
              break;
            v8 = *v10;
          }
          while ( *v10 );
        }
      }
      if ( v12 )
        sub_592750(v12);
      if ( v11 )
        sub_592750(v11);
      result = v13;
      if ( v13 )
        return sub_592750(v13);
    }
  }
  return result;
}
