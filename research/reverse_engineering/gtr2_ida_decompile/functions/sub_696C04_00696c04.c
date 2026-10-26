int __thiscall sub_696C04(int *this, int a2, _DWORD *a3)
{
  int v3; // esi
  int v5; // ebx

  v3 = *(_DWORD *)(a2 + 16);
  if ( (v3 & 0x200) != 0 )
    sub_694F9B(this, (int)a3, 1);
  if ( a3 && a3[1] == 9 && a3[4] == 2 )
  {
    if ( (v3 & 0xC00) == 0 )
      v3 |= *(_DWORD *)(this[1] + 56);
    if ( (v3 & 0xC00) == 0 )
    {
      v5 = *this;
      if ( (v5 & 8) != 0 )
      {
        LOWORD(v3) = v3 | 0x400;
      }
      else if ( (v5 & 0x10) != 0 )
      {
        LOWORD(v3) = v3 | 0x800;
      }
    }
    if ( (v3 & 0x400) != 0 )
      a3[8] = a3[8] & 0xFFFFF3FF | 0x400;
    if ( (v3 & 0x800) != 0 )
      a3[8] = a3[8] & 0xFFFFF3FF | 0x800;
    return 0;
  }
  if ( (v3 & 0xC00) == 0 )
    return 0;
  sub_694B97((int)this, (int)(this + 8), 3077, "non-matrix types cannot be declared 'row_major' or 'column_major'");
  return -2147467259;
}
