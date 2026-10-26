int __thiscall sub_548620(_DWORD *this, const char *a2)
{
  int v3; // esi
  int v5; // ebx
  const char *v6; // edi
  int v7; // esi
  int v8; // esi
  int v9; // edi
  char v11[256]; // [esp+14h] [ebp-100h] BYREF

  v3 = sub_587DB0(a2, aRb);
  if ( v3 )
  {
    if ( sub_548190(this, 0) )
    {
      sub_587D02(v3);
      return -1;
    }
    sub_587D02(v3);
    return 0;
  }
  v5 = 0;
  if ( dword_8B8E30 > 0 )
  {
    v6 = byte_8B5A3C;
    while ( 1 )
    {
      sub_58815F(v11, "%s\\%s", v6, a2);
      v7 = sub_587DB0(v11, aRb);
      if ( v7 )
        break;
      ++v5;
      v6 += 132;
      if ( v5 >= dword_8B8E30 )
        goto LABEL_14;
    }
    if ( sub_548190(this, 0) )
    {
      sub_587D02(v7);
      return -1;
    }
    sub_587D02(v7);
  }
LABEL_14:
  if ( v5 == dword_8B8E30 )
  {
    v8 = dword_8B8F14;
    v9 = 0;
    if ( dword_8B8F14 )
    {
      while ( sub_560230(a2) )
      {
        v8 = *(_DWORD *)(v8 + 304);
        ++v9;
        if ( !v8 )
          goto LABEL_22;
      }
      if ( sub_548190(this, 0) )
        return -1;
    }
  }
  else
  {
    v9 = -1;
  }
LABEL_22:
  if ( v9 != dword_8B6AC0 )
    return 0;
  sub_58815F(v11, "Unable to locate material lib %s", a2);
  sub_53C590(-1, v11);
  return -1;
}
