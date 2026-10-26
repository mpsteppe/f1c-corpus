int __userpurge sub_5DC7E0@<eax>(int a1@<ecx>, int a2@<ebp>, const char *ArgList, _DWORD *Block)
{
  void *v5; // eax
  void *v6; // ebx
  char *v7; // ebp
  int v8; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // eax
  int i; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // ebx
  int v16; // [esp-Ch] [ebp-258h]
  size_t Size; // [esp+Ch] [ebp-240h] BYREF
  _DWORD *v19; // [esp+10h] [ebp-23Ch]
  int v20; // [esp+14h] [ebp-238h]
  void *v21; // [esp+18h] [ebp-234h]
  int v22; // [esp+1Ch] [ebp-230h]
  char v23[16]; // [esp+20h] [ebp-22Ch] BYREF
  char v24[16]; // [esp+30h] [ebp-21Ch] BYREF
  char String1[520]; // [esp+40h] [ebp-20Ch] BYREF
  int v26; // [esp+248h] [ebp-4h]

  LOBYTE(v20) = 0;
  Size = 0;
  v5 = (void *)sub_5E0740(ArgList, 0);
  v6 = v5;
  v21 = v5;
  if ( !v5 )
  {
    sub_5D8C80(a1, (char *)0xFFFFFFFF, "Error loading mesh file %s to memory", (char)ArgList);
    return off_16C92E0(ArgList, Block);
  }
  sub_5DEC60(&Size, v5, 4);
  sub_5DEC10(v6, 8, 0);
  sub_5DEC60(v24, v6, 16);
  sub_5EA600(v24, v23);
  sub_5DEC10(v6, 4, 0);
  if ( strcmp(v23, "GMOTOR_GMT_2.10") )
  {
    if ( strcmp(v23, "GMOTOR_GMT_2.02") )
    {
      sub_5D8C80(a1, (char *)0xFFFFFFFF, "Wrong GMT version (%.16s -- %.16s) for file %s", (char)v24);
      sub_5D8CE0();
      return off_16C92E0(ArgList, Block);
    }
    LOBYTE(v20) = 1;
  }
  v7 = (char *)operator new(Size);
  memset(v7, 0, Size);
  v8 = sub_5DEC60(v7, v6, Size);
  if ( v8 != Size )
  {
    if ( v7 )
    {
      `eh vector destructor iterator'(v7, 0x210u, *((_DWORD *)v7 - 1), j_nullsub_7);
      j__free(v7 - 4);
    }
    sub_5D8C80(a1, (char *)0xFFFFFFFF, "Error reading mesh from GMT file %s", (char)ArgList);
    sub_5D8CE0();
    return off_16C92E0(ArgList, Block);
  }
  v9 = Block;
  if ( !Block )
  {
    v22 = sub_5DEC50(v6);
    v10 = operator new(0x54u);
    v19 = v10;
    v26 = 0;
    if ( v10 )
      v9 = (_DWORD *)sub_5EA4A0(v10);
    v26 = -1;
    v19 = v9;
    if ( sub_5EA410((int)v9, 0, (int)v6, v20, 0) != -1 )
    {
      if ( (**(_DWORD **)(a1 + 620) & 0x10000000) != 0 )
      {
        for ( i = 0; i < v9[12]; ++i )
        {
          v16 = dword_FB27B0;
          v12 = sub_5E9300(i);
          if ( !sub_5E9070(v12, v16, 0) )
          {
            v13 = sub_5E9300(i);
            sub_5E9650(v13, 1);
          }
        }
        v6 = v21;
        goto LABEL_21;
      }
      sub_5DEC10(v6, v22, 0);
      if ( sub_5EA410((int)&unk_FB27F8, 0, (int)v6, v20, ~(**(_DWORD **)(a1 + 620) >> 10) & 0x40000) != -1 )
      {
LABEL_21:
        v9 = v19;
        goto LABEL_22;
      }
      sub_5E9D20(1);
      if ( v9 )
      {
        sub_5DA430((__int32)v9, a2);
        j__free(v9);
      }
    }
    sub_5DF6E0(v6);
    sub_5D8CE0();
    sub_5D8C80(a1, (char *)0xFFFFFFFF, "Error reading material lib from GMT file %s", (char)ArgList);
    return off_16C92E0(ArgList, Block);
  }
LABEL_22:
  sub_5DF6E0(v6);
  *((_DWORD *)v7 + 98) = a1;
  v14 = sub_5EB3A0((int)v7, (int)v9, 0);
  sub_5D8EF0((int)String1, ArgList, 511);
  sub_5E89B0(String1);
  if ( _stricmp(String1, v7 + 400) )
    sub_5DA6B0(v7, String1);
  if ( !Block )
  {
    sub_5E9D20(((**(_DWORD **)(a1 + 620) >> 28) & 1) == 0);
    if ( v9 )
    {
      sub_5DA430((__int32)v9, a2);
      j__free(v9);
    }
  }
  if ( v14 )
  {
    sub_5EC660(v7);
    j__free(v7);
  }
  else
  {
    sub_5DB2B0(
      (_DWORD *)a1,
      *((_DWORD *)v7 + 81),
      *((_DWORD *)v7 + 82),
      *((_DWORD *)v7 + 83),
      *((float *)v7 + 84),
      *((float *)v7 + 85),
      *((float *)v7 + 86));
    sub_5FDFB0(v7, 0);
  }
  return off_16C92E0(ArgList, Block);
}
