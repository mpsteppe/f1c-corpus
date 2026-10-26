int __thiscall sub_4AB490(int this)
{
  int v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  FILE *v4; // eax
  int v6; // [esp+0h] [ebp-308h]
  char v7[256]; // [esp+8h] [ebp-300h] BYREF
  char Buffer[512]; // [esp+108h] [ebp-200h] BYREF

  if ( *(_DWORD *)(this + 276) == 853 )
  {
    v1 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48), 53);
    if ( v1 )
    {
      v2 = (const char *)sub_4CE170(v1);
      if ( v2 )
      {
        if ( strlen(v2) )
        {
          sub_617930(256);
          v3 = *(const char **)dword_BE121C;
          if ( !*(_DWORD *)dword_BE121C )
            v3 = WindowName;
          sprintf(Buffer, "%s%s%s", v3, v7, (const char *)&stru_6F59D0.ExceptionRecord);
          v4 = fopen(Buffer, "rb");
          if ( v4 )
          {
            fclose(v4);
            sub_617680(Buffer);
            sub_497320();
            if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 857) )
              sub_4D0AC0(v6);
          }
        }
      }
    }
  }
  return 0;
}
