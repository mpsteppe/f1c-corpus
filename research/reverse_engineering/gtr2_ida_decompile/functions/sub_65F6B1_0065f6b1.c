int __thiscall sub_65F6B1(_DWORD *this, int a2)
{
  const char *v3; // edx
  int result; // eax
  char v5; // cl
  char *v6; // esi
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  unsigned int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  unsigned int v13; // [esp+8h] [ebp-4h]

  v3 = *(const char **)(a2 + 8);
  result = 0;
  if ( v3 )
  {
    v5 = *v3;
    if ( *v3 )
    {
      v6 = *(char **)(a2 + 8);
      while ( 1 )
      {
        if ( v5 > 119 )
        {
          v11 = v5 - 120;
          if ( v11 )
          {
            v12 = v11 - 1;
            if ( !v12 )
            {
LABEL_20:
              v10 = 1;
              result |= 0x20000u;
              goto LABEL_11;
            }
            if ( v12 != 1 )
              goto LABEL_21;
LABEL_19:
            v10 = 2;
            result |= 0x40000u;
            goto LABEL_11;
          }
        }
        else
        {
          if ( v5 == 119 || (v7 = v5 - 97) == 0 )
          {
            v10 = 3;
            result |= 0x80000u;
            goto LABEL_11;
          }
          v8 = v7 - 1;
          if ( !v8 )
            goto LABEL_19;
          v9 = v8 - 5;
          if ( !v9 )
            goto LABEL_20;
          if ( v9 != 11 )
            goto LABEL_21;
        }
        v10 = 0;
        result |= 0x10000u;
LABEL_11:
        if ( v6 != v3 && v10 <= v13 )
        {
LABEL_21:
          sub_65DD1F((_DWORD *)*this, a2, 2003, "invalid mask '%s'", v3);
          this[19] = 1;
          return 0;
        }
        ++v6;
        v13 = v10;
        v5 = *v6;
        if ( !*v6 )
          return result;
      }
    }
  }
  return 983040;
}
