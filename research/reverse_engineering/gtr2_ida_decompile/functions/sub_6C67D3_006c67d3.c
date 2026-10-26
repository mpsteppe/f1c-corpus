int __thiscall sub_6C67D3(_DWORD *this, int a2, int a3)
{
  char *v3; // edi
  bool v4; // zf
  int v6; // ebx
  _DWORD *v7; // eax
  int v8; // ecx
  int v9; // eax
  char *v10; // esi
  int v11; // eax
  const char *v12; // ebx
  const char *v13; // edi
  const char *i; // esi
  unsigned int v15; // eax
  int v16; // [esp+4h] [ebp-18h] BYREF
  int v17; // [esp+8h] [ebp-14h]
  int v18; // [esp+10h] [ebp-Ch]
  char *v19; // [esp+14h] [ebp-8h]
  char *v20; // [esp+18h] [ebp-4h]

  v3 = 0;
  v20 = 0;
  v19 = 0;
  v4 = this[86] == 0;
  v18 = (int)this;
  if ( v4 )
    return 0;
  v6 = *(_DWORD *)(a2 + 48);
  if ( v6 )
  {
    do
    {
      v7 = *(_DWORD **)(v6 + 8);
      if ( v7[1] == 17 )
      {
        v8 = v7[4];
        if ( v8 )
          v8 = *(_DWORD *)(v8 + 24);
        v9 = v7[5];
        if ( v9 )
          v10 = *(char **)(v9 + 24);
        else
          v10 = 0;
        if ( v8 )
        {
          if ( v10 && sub_6460B4((const char *)v8, 0, &v16) >= 0 && sub_635155(*v10) == 99 )
          {
            v11 = *(_DWORD *)(v18 + 200);
            if ( v11 == v17 )
            {
              v3 = v10;
            }
            else if ( ((v17 ^ v11) & 0xFFFF0000) == 0 && !(_WORD)v17 )
            {
              v20 = v10;
            }
          }
        }
        else if ( v10 && sub_635155(*v10) == 99 )
        {
          v19 = v10;
        }
      }
      v6 = *(_DWORD *)(v6 + 12);
    }
    while ( v6 );
    if ( v3 )
      goto LABEL_38;
  }
  v3 = v20;
  if ( v20 || (v3 = v19) != 0 )
  {
LABEL_38:
    if ( sub_635155(*v3) == 99 )
    {
      v12 = v3 + 1;
      if ( isdigit(v3[1]) )
      {
        v13 = v3 + 2;
        for ( i = v13; isdigit(*i); ++i )
          ;
        if ( !*i )
        {
          v15 = j__atol(v12);
          if ( v15 > 0x1FFF )
          {
            sub_686791(v18, 0, 0, "Constant variable '%s' bound to register greater than 8191 (%d requested)", v13, v15);
            return -2147467259;
          }
          *(_WORD *)(a3 + 10) |= (unsigned __int16)(4 * v15) | 2;
        }
      }
    }
  }
  return 0;
}
