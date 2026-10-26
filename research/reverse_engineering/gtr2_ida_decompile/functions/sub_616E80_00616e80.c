char __thiscall sub_616E80(_DWORD *this, _DWORD *a2, int a3)
{
  unsigned __int8 *v4; // esi
  char *v5; // eax
  char *v6; // ecx
  unsigned __int8 *v7; // eax
  char *v8; // eax
  char v10; // [esp+Fh] [ebp-401h]
  char Str[512]; // [esp+10h] [ebp-400h] BYREF
  int v12[128]; // [esp+210h] [ebp-200h] BYREF

  v4 = 0;
  memset(v12, 0, sizeof(v12));
  memset(Str, 0, sizeof(Str));
  v10 = 0;
  while ( (*(int (__thiscall **)(_DWORD *, int *, int))(*a2 + 36))(a2, v12, 512) )
  {
    v10 = 1;
    if ( sub_616680((unsigned __int8 *)v12, Str) )
    {
      if ( Str[0] == 123 )
      {
        sub_616E80(a2, v4);
      }
      else
      {
        if ( Str[0] == 125 )
          return v10;
        v5 = strstr(Str, "=");
        if ( v5 )
        {
          *v5 = 0;
          v6 = (char *)a2[2];
          v7 = (unsigned __int8 *)(v5 + 1);
          if ( !v6 )
            v6 = (char *)WindowName;
          v4 = sub_616CA0(this, (unsigned __int8 *)Str, v7, v6, a3);
        }
        else
        {
          v8 = (char *)a2[2];
          if ( !v8 )
            v8 = (char *)WindowName;
          v4 = sub_616CA0(this, (unsigned __int8 *)Str, 0, v8, a3);
        }
      }
    }
  }
  return v10;
}
