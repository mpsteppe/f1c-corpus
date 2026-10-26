int __thiscall sub_4AECB0(_DWORD **this)
{
  unsigned int v1; // kr00_4
  __int32 v2; // eax
  int v4; // ebp
  int *v5; // edi
  char *v6; // eax
  char v7; // cl
  const char *v8; // eax
  void *v9; // eax
  sbdt::PlayerFile *v10; // esi
  int v11; // ebp
  char *v12; // eax
  int v13; // eax
  __int32 v15; // [esp+0h] [ebp-24h] BYREF
  char *v16; // [esp+4h] [ebp-20h]
  unsigned int v17; // [esp+14h] [ebp-10h]
  int v18; // [esp+20h] [ebp-4h]

  v4 = -1;
  v5 = (int *)(*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 60);
  if ( v5 )
  {
    v6 = &byte_B6DC17[strlen(&byte_B6DC18)];
    if ( *v6 == 32 )
    {
      do
      {
        *v6 = 0;
        v7 = *--v6;
      }
      while ( v7 == 32 );
    }
    v17 = strlen(&byte_B6DC18);
    if ( v17 && (v16 = &byte_B6DC18, (unsigned __int8)sub_4A6130()) )
    {
      if ( byte_B763D5 )
      {
        v8 = dword_91CB00;
        if ( !dword_91CB00 )
          v8 = WindowName;
        sprintf(byte_B6DB18, "%s%s", v8, "PlayerNameNeverUsed");
        sub_4E23F0(byte_B6DB18);
        byte_B763D5 = 0;
      }
      (*(void (__thiscall **)(int *))(*v5 + 152))(v5);
      if ( v5[37] > 0 )
        sub_510770(&byte_B6F530, 0);
      sub_6178E0(&byte_B6DC18);
      v9 = operator new(0x6EB0u);
      v17 = (unsigned int)v9;
      v18 = 0;
      if ( v9 )
        v10 = (sbdt::PlayerFile *)sub_514F20(v9);
      else
        v10 = 0;
      v18 = -1;
      if ( sbdt::PlayerFile::Create(v10, &byte_B6DC18) != -1 )
      {
        sub_4A5F80();
        v4 = 0;
      }
      if ( v10 )
      {
        sub_510C90(v10);
        j__free(v10);
      }
      sub_519B50(&byte_B6F530);
      sub_4EA860(&unk_B6F135);
    }
    else
    {
      v11 = *this[12];
      v12 = sub_41D840(&byte_91CC38, "Profile already exists");
      v13 = (*(int (__thiscall **)(_DWORD *, char *))(v11 + 4))(this[12], v12);
      v16 = 0;
      v15 = v13;
      v1 = __readeflags();
      v2 = dword_16C6C90 + 1996553869;
      __writeeflags(v1);
      _InterlockedExchange(&v15, v2);
      sub_4E1810(v15, v16);
      v4 = -1;
    }
    (*(void (__thiscall **)(int *))(*v5 + 152))(v5);
  }
  return v4;
}
