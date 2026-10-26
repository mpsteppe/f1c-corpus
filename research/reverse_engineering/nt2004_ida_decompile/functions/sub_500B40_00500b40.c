int __thiscall sub_500B40(int *this)
{
  int v2; // eax
  const char *v3; // ecx
  int v4; // edi
  const char *v5; // eax
  int v6; // esi
  int *v7; // eax
  _DWORD *v8; // ebp
  _DWORD *v9; // edi
  bool v10; // zf
  const char *v11; // eax
  int v12; // esi
  const char *v13; // edx
  const char *v14; // ecx
  _DWORD *v15; // ecx
  int result; // eax
  int v17; // [esp+Ch] [ebp-204h]
  char Buffer[512]; // [esp+10h] [ebp-200h] BYREF

  sub_500CE0(this);
  v2 = sub_579ED0(512);
  v3 = (const char *)dword_62A0B8;
  v4 = v2;
  v17 = v2;
  if ( !dword_62A0B8 )
    v3 = &byte_629120;
  v5 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v5 = &byte_629120;
  sprintf(Buffer, "%s%s", v5, v3);
  sub_578A30(aTbc, 1, Buffer, 1);
  v6 = sub_578A20(&unk_7D7A0C);
  *this = v6;
  v7 = (int *)operator new(36 * v6 + 4);
  if ( v7 )
  {
    v8 = v7 + 1;
    *v7 = v6;
    v9 = v7 + 1;
    if ( v6 - 1 >= 0 )
    {
      do
      {
        sub_5004B0(v9);
        v9 += 9;
        --v6;
      }
      while ( v6 );
    }
    v4 = v17;
  }
  else
  {
    v8 = 0;
  }
  v10 = *this == 0;
  this[1] = (int)v8;
  if ( (v10 || !v8) && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 1135) )
    sub_500FE0((int)&unk_7D7920, aNoTireBrandsTb, (char)Buffer);
  sub_578A00(&unk_7D7A0C);
  v11 = (const char *)sub_578D80(&unk_7D7A0C);
  if ( v11 )
  {
    v12 = 0;
    do
    {
      v13 = (const char *)dword_62A0B8;
      if ( !dword_62A0B8 )
        v13 = &byte_629120;
      v14 = *(const char **)dword_62A068;
      if ( !*(_DWORD *)dword_62A068 )
        v14 = &byte_629120;
      sprintf(Buffer, "%s%s%s", v14, v13, v11);
      v15 = (_DWORD *)(v12 + this[1]);
      v12 += 36;
      sub_5005A0(v15, Buffer);
      if ( !(unsigned __int8)sub_5789D0(&unk_7D7A0C) )
        break;
      v11 = (const char *)sub_578D80(&unk_7D7A0C);
    }
    while ( v11 );
  }
  result = sub_578960(&unk_7D7A0C);
  if ( v4 != 512 )
    return sub_579F10(v4);
  return result;
}
