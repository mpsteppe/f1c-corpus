int __thiscall sub_4D8AB0(_DWORD *this)
{
  int v2; // edi
  const char *v3; // eax
  int v5; // [esp+8h] [ebp-A4h] BYREF
  _BYTE v6[32]; // [esp+Ch] [ebp-A0h] BYREF
  _BYTE v7[128]; // [esp+2Ch] [ebp-80h] BYREF

  v2 = 1;
  if ( dword_8AD388 )
    sub_4D8FB0();
  v3 = (const char *)dword_5EC408;
  v5 = 0;
  if ( !dword_5EC408 )
    v3 = byte_5EA438;
  sub_58815F(v7, "%s%s", v3, off_5D4A5C);
  sub_53CBC0(&v5, v7);
  if ( v5 )
  {
    sub_58815F(v6, "%s%s", off_5D4A48[0], (const char *)off_5D4A58);
    sub_53CFE0(&dword_8AD388, v6, 133120);
    if ( dword_8AD388 )
    {
      sub_552FD0(0, 192);
      *(_DWORD *)(dword_8AD388 + 92) = this[57];
      *(_DWORD *)(dword_8AD388 + 96) = this[58];
    }
    sub_58815F(v6, "%s%s", off_5D4A4C[0], (const char *)off_5D4A58);
    sub_53CFE0(&dword_8AD38C, v6, 133120);
    if ( dword_8AD38C )
    {
      sub_552FD0(0, 192);
      *(_DWORD *)(dword_8AD38C + 92) = this[57];
      *(_DWORD *)(dword_8AD38C + 96) = this[58];
    }
    sub_58815F(v6, "%s%s", off_5D4A50[0], (const char *)off_5D4A58);
    sub_53CFE0(&dword_8AD390, v6, 133120);
    if ( dword_8AD390 )
    {
      sub_552FD0(0, 192);
      *(_DWORD *)(dword_8AD390 + 92) = this[57];
      *(_DWORD *)(dword_8AD390 + 96) = this[58];
    }
    sub_58815F(v6, "%s%s", off_5D4A54, (const char *)off_5D4A58);
    v2 = sub_53CFE0(&dword_8AD394, v6, 133120);
    if ( dword_8AD394 )
    {
      sub_552FD0(0, 192);
      *(_DWORD *)(dword_8AD394 + 92) = this[57];
      *(_DWORD *)(dword_8AD394 + 96) = this[58];
    }
    sub_53CE40(v5);
  }
  return v2;
}
