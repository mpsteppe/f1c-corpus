int __thiscall sub_4E73E0(void *this)
{
  const char *v1; // ecx
  const char *v2; // eax
  void *v3; // ebp
  int v4; // esi
  int v5; // edi
  int v6; // esi
  int *v7; // eax
  int v8; // ebp
  _DWORD *v9; // edi
  const char *i; // eax
  const char *v11; // edx
  const char *v12; // ecx
  const char *v13; // eax
  char *v14; // esi
  char Buffer[512]; // [esp+4h] [ebp-200h] BYREF

  sub_578960(&unk_7D7A0C);
  v1 = (const char *)dword_62A0B8;
  if ( !dword_62A0B8 )
    v1 = &byte_629120;
  v2 = *(const char **)dword_62A068;
  if ( !*(_DWORD *)dword_62A068 )
    v2 = &byte_629120;
  sprintf(Buffer, "%s%s", v2, v1);
  sub_578A30(aVeh, 1, Buffer, 1);
  if ( dword_7D6A5C )
  {
    v3 = (void *)(dword_7D6A5C - 4);
    v4 = dword_7D6A5C + 1232 * *(_DWORD *)(dword_7D6A5C - 4);
    if ( *(_DWORD *)(dword_7D6A5C - 4) - 1 >= 0 )
    {
      v5 = *(_DWORD *)(dword_7D6A5C - 4);
      do
      {
        v4 -= 1232;
        sub_4E7620(v4);
        --v5;
      }
      while ( v5 );
    }
    sub_5BE8AE(v3);
  }
  v6 = sub_578A20(&unk_7D7A0C);
  v7 = (int *)operator new(1232 * v6 + 4);
  if ( v7 )
  {
    v8 = (int)(v7 + 1);
    *v7 = v6;
    v9 = v7 + 1;
    if ( v6 - 1 >= 0 )
    {
      do
      {
        sub_4E6480(v9);
        v9 += 308;
        --v6;
      }
      while ( v6 );
    }
    dword_7D6A5C = v8;
  }
  else
  {
    dword_7D6A5C = 0;
  }
  sub_578A00(&unk_7D7A0C);
  for ( i = (const char *)sub_578D80(&unk_7D7A0C); i; i = (const char *)sub_578D80(&unk_7D7A0C) )
  {
    v11 = (const char *)dword_62A0B8;
    if ( !dword_62A0B8 )
      v11 = &byte_629120;
    v12 = *(const char **)dword_62A068;
    if ( !*(_DWORD *)dword_62A068 )
      v12 = &byte_629120;
    sprintf(Buffer, "%s%s%s", v12, v11, i);
    _strupr(Buffer);
    sub_578600(Buffer);
    v13 = (const char *)sub_5789A0(&unk_7D7A0C);
    v14 = (char *)(1232 * dword_7D6A58 + dword_7D6A5C + 136);
    strncpy(v14, v13, 0x1Fu);
    v14[31] = 0;
    if ( sub_4E6570((char *)(dword_7D6A5C + 1232 * dword_7D6A58)) )
    {
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_18, 542) )
        sub_500FE0((int)&unk_7D7920, aFailedReadingD, (char)Buffer);
    }
    else
    {
      ++dword_7D6A58;
    }
    if ( !(unsigned __int8)sub_5789D0(&unk_7D7A0C) )
      break;
  }
  sub_578960(&unk_7D7A0C);
  sub_4E7920(this);
  return dword_7D6A58;
}
