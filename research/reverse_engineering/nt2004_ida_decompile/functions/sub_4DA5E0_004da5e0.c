char __usercall sub_4DA5E0@<al>(_DWORD *a1@<ecx>, char a2@<dil>)
{
  int *v3; // esi
  bool v4; // bl
  char *v5; // edi
  char *v6; // eax
  char *v7; // eax
  signed int v8; // eax
  char *v9; // eax
  char result; // al
  int v11; // eax
  int v12; // eax
  int v13; // edi
  _DWORD *v14; // ecx
  float v15; // edx
  float v16; // [esp+4h] [ebp-444h] BYREF
  char *FileName[2]; // [esp+8h] [ebp-440h] BYREF
  _BYTE v18[28]; // [esp+10h] [ebp-438h] BYREF
  _BYTE v19[28]; // [esp+2Ch] [ebp-41Ch] BYREF
  _BYTE Buffer[1024]; // [esp+48h] [ebp-400h] BYREF

  if ( *a1 == 2 )
  {
    v3 = a1 + 2;
    v4 = 0;
    sub_4D9810(a1 + 2);
    if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_15, 6865) )
      sub_500FE0((int)&unk_7D7920, aLoadingVcrFile, a2);
    v5 = *(char **)(*v3 + 2172);
    if ( !v5 )
      v5 = &byte_629120;
    sub_57A080(v19);
    if ( !(unsigned __int8)sub_57A2F0(v5, 0) )
      goto LABEL_23;
    if ( sub_41F230(dword_62A170, aLoadingReplay, Destination) )
    {
      strncpy(Destination, aLoadingReplay, 0x1FFu);
      byte_62A37B = 0;
    }
    sub_4BA730(Destination, 1065353216, 1);
    FileName[0] = (char *)operator new(0x80u);
    *FileName[0] = 0;
    FileName[1] = (char *)128;
    sub_4D9840((int)FileName);
    v6 = FileName[0];
    if ( !FileName[0] )
      v6 = &byte_629120;
    sub_57AF60(v6);
    sub_57A080(v18);
    v7 = FileName[0];
    if ( !FileName[0] )
      v7 = &byte_629120;
    if ( (unsigned __int8)sub_57A110(v7, 0, 0, 1) )
    {
      while ( 1 )
      {
        v8 = sub_57A3D0(Buffer, 0x400u);
        if ( v8 <= 0 )
          break;
        sub_57A3A0(Buffer, v8);
      }
      sub_57A360(v18);
      sub_57A360(v19);
      v9 = FileName[0];
      if ( !FileName[0] )
        v9 = &byte_629120;
      v4 = sub_4D97E0(a1 + 2, v9, 0);
      if ( v4 )
      {
        sub_4D9820((void **)a1 + 2);
        *a1 = 2;
        sub_4D9EF0(a1 + 2, 5);
      }
    }
    sub_57A0A0(v18);
    if ( FileName[0] )
      sub_5BE8AE(FileName[0]);
    if ( v4 )
    {
      v11 = sub_4D9830(a1 + 2);
      sub_42DB60(v11);
      v12 = sub_4D9830(a1 + 2);
      sub_42DC00(v12);
      v13 = *v3;
      v14 = (_DWORD *)*v3;
      v16 = 0.0;
      sub_4D8430(v14, &v16, FileName);
      v15 = v16;
      *(float *)(v13 + 2080) = v16;
      sub_4D82E0(*v3, v15);
      return sub_57A0A0(v19);
    }
    else
    {
LABEL_23:
      *a1 = 0;
      return sub_57A0A0(v19);
    }
  }
  else
  {
    result = sub_405BF0(&dword_629124);
    *a1 = *(_DWORD *)dword_7689CC != 6
       && !result
       && ((result = dword_7684E0, dword_7684E0) || (result = dword_768504, dword_768504));
  }
  return result;
}
