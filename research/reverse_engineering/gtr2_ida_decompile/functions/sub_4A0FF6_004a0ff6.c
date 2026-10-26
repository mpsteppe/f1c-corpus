int __thiscall sub_4A0FF6(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ecx
  const char *v5; // esi
  const char *v6; // eax
  int v7; // edi
  int v8; // esi
  int v9; // eax
  void *v10; // eax
  int v11; // esi
  _UNKNOWN *retaddr; // [esp+18h] [ebp+0h]

  result = this[39];
  v4 = *(_DWORD *)(a2 + 156);
  if ( result && v4 )
  {
    v5 = *(const char **)(result + 36);
    if ( !v5 )
      v5 = WindowName;
    v6 = *(const char **)(v4 + 36);
    if ( !v6 )
      v6 = WindowName;
    result = strcmp(v6, v5);
    if ( !result )
    {
      v7 = this[74];
      v8 = 0;
      if ( v7 <= 0 )
      {
LABEL_12:
        v10 = operator new(0x38u);
        retaddr = v10;
        if ( v10 )
          v11 = sub_4D2F60(v10, this);
        else
          v11 = 0;
        sub_4D2FA0(a2);
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v11 + 24))(v11, 0);
        sub_4D50A0(v11, 1);
        return sub_4D7D70(this);
      }
      else
      {
        while ( 1 )
        {
          v9 = sub_49EE60();
          if ( v9 )
          {
            if ( *(_DWORD *)(v9 + 52) == a2 )
              return sub_4D2FA0(a2);
          }
          if ( ++v8 >= v7 )
            goto LABEL_12;
        }
      }
    }
  }
  return result;
}
