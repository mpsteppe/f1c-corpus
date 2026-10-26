// f1c  0x004a29a0  size=146
int __thiscall sub_4A29A0(_DWORD *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // ecx
  int result; // eax
  int v6; // ecx
  void *v7; // edx
  _BYTE *v8; // edi
  int v9; // ecx
  int v10; // ebp
  void *v11; // [esp+8h] [ebp-4h]

  v2 = this[3];
  v3 = 0;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  if ( v2 > 0 )
  {
    v4 = 0;
    do
    {
      *(_DWORD *)(this[4] + v4 + 100) = 0;
      ++v3;
      v4 += 120;
    }
    while ( v3 < this[3] );
  }
  result = this[4];
  this[3] = 0;
  if ( result )
  {
    v6 = *(_DWORD *)(result - 4);
    v7 = (void *)(result - 4);
    v8 = (_BYTE *)(result + 120 * v6);
    v9 = v6 - 1;
    v11 = (void *)(result - 4);
    if ( v9 >= 0 )
    {
      v10 = v9 + 1;
      do
      {
        v8 -= 120;
        sub_4A2220(v8);
        --v10;
      }
      while ( v10 );
      v7 = v11;
    }
    result = sub_587BCF(v7);
  }
  this[4] = 0;
  if ( dword_8AFE88 )
  {
    result = this[5];
    if ( result )
      result = sub_545150(this[5]);
  }
  this[5] = 0;
  return result;
}
