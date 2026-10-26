char __thiscall sub_4AF4C0(_DWORD *this, int a2, char a3)
{
  char result; // al
  int v4; // edi
  int v6; // ebp
  float v7; // ebx
  _DWORD *v8; // eax
  CHAR *v9; // eax
  _DWORD *v10; // ecx
  int v11; // eax
  int v12; // eax

  result = a2;
  v4 = 0;
  if ( a2 )
  {
    this[15] = a2;
    v6 = *(_DWORD *)(a2 + 20);
    v7 = *(float *)(a2 + 24);
    v8 = operator new(0x1Cu);
    if ( v8 )
    {
      *v8 = 0;
      v8[1] = 0;
      v8[2] = -1;
      v8[5] = 0;
      v8[6] = -1;
    }
    else
    {
      v8 = 0;
    }
    this[16] = v8;
    sub_4AFE40(1);
    v9 = *(CHAR **)this[15];
    if ( !v9 )
      v9 = &byte_629120;
    sub_578600(v9);
    sub_4AFF20(this[3], this[1]);
    sub_4B0090(v6, v7);
    result = a3;
    if ( a3 )
    {
      v10 = (_DWORD *)this[17];
      v11 = v10[4] - v10[3];
      if ( v11 > 0 )
        v4 = v11 + 1;
      if ( v10[2] - v10[1] <= 0 )
        v12 = 0;
      else
        v12 = v10[2] - v10[1] + 1;
      return sub_4B1540(v4 / 2 - v6 / 2 - this[3], v12 / 2 - SLODWORD(v7) / 2 - this[1]);
    }
  }
  return result;
}
