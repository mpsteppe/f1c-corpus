int __thiscall sub_55FC40(int this, char *a2)
{
  char *v2; // eax
  int v4; // edx
  char v5; // cl
  int v6; // eax
  int v7; // ebp
  const char *v8; // edi
  int v9; // eax
  int v11; // eax
  int v12; // [esp-34h] [ebp-240h]
  _BYTE v13[256]; // [esp+Ch] [ebp-200h] BYREF
  char v14[256]; // [esp+10Ch] [ebp-100h] BYREF

  v2 = a2;
  if ( !a2 || !*a2 )
    return -1;
  v4 = this + 20 - (_DWORD)a2;
  do
  {
    v5 = *v2;
    v2[v4] = *v2;
    ++v2;
  }
  while ( v5 );
  sub_589901((LPCSTR)(this + 20));
  v6 = sub_587DB0(this + 20, aRb);
  *(_DWORD *)(this + 16) = v6;
  if ( !v6 )
  {
    v7 = 0;
    if ( dword_8B8E30 > 0 )
    {
      v8 = byte_8B5A3C;
      do
      {
        sub_58815F(v13, "%s\\%s", v8, (const char *)(this + 20));
        v9 = sub_587DB0(v13, aRb);
        *(_DWORD *)(this + 16) = v9;
        if ( v9 )
          break;
        ++v7;
        v8 += 132;
      }
      while ( v7 < dword_8B8E30 );
    }
    if ( v7 == dword_8B8E30 )
    {
      sub_58815F(v14, "Error opening MAS file %s", (const char *)(this + 20));
      sub_53C590(-2, v14);
      return -2;
    }
  }
  sub_58803F(this, 1, 12, *(_DWORD *)(this + 16));
  if ( strcmp((const char *)this, aCubemas410)
    && strcmp((const char *)this, aCubemas400)
    && strcmp((const char *)this, aCubemas401) )
  {
    sub_587D02(*(_DWORD *)(this + 16));
    sub_53C590(-1, aIncorrectMasFi);
    return -1;
  }
  sub_58803F(this + 276, 1, 4, *(_DWORD *)(this + 16));
  sub_58803F(this + 280, 1, 4, *(_DWORD *)(this + 16));
  sub_58803F(this + 288, 1, 4, *(_DWORD *)(this + 16));
  v12 = *(_DWORD *)(this + 280) << 8;
  *(_DWORD *)(this + 284) = v12;
  v11 = sub_587C03(v12);
  *(_DWORD *)(this + 296) = v11;
  if ( !v11 )
  {
    sub_587D02(*(_DWORD *)(this + 16));
    sub_53C590(-1, aUnableToAlloca);
    return -1;
  }
  sub_58803F(v11, 1, *(_DWORD *)(this + 284), *(_DWORD *)(this + 16));
  *(_DWORD *)(this + 284) += 24;
  return 0;
}
