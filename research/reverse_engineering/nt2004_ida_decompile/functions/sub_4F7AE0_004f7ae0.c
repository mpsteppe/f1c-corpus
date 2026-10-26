int __thiscall sub_4F7AE0(_DWORD *this)
{
  int v2; // eax
  int v3; // ebx
  _DWORD *v4; // edi
  int v5; // ebx
  int v6; // ecx
  LPVOID *v7; // edi
  int v8; // ebx
  int result; // eax
  int v10; // edi
  int v11; // ecx
  void **v12; // edi
  int v13; // ebx
  char v14; // [esp+0h] [ebp-10h]

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_20, 3670) )
    sub_500FE0((int)&unk_7D7920, aEnteredSpecial_3, v14);
  v2 = this[1];
  v3 = 0;
  *this = 0;
  if ( v2 )
  {
    v4 = (_DWORD *)(v2 + 60 * *(_DWORD *)(v2 - 4));
    if ( *(_DWORD *)(v2 - 4) - 1 >= 0 )
    {
      v5 = *(_DWORD *)(v2 - 4);
      do
      {
        v4 -= 15;
        sub_4F16D0(v4);
        --v5;
      }
      while ( v5 );
      v3 = 0;
    }
    sub_5BE8AE();
    this[1] = 0;
  }
  sub_44E8B0((int)dbl_760B48);
  v6 = this[3];
  if ( v6 )
  {
    v7 = (LPVOID *)(v6 + 104 * *(_DWORD *)(v6 - 4));
    if ( *(_DWORD *)(v6 - 4) - 1 >= 0 )
    {
      v8 = *(_DWORD *)(v6 - 4);
      do
      {
        v7 -= 26;
        sub_4B0A60(v7);
        --v8;
      }
      while ( v8 );
      v3 = 0;
    }
    sub_5BE8AE();
  }
  result = this[4];
  v10 = 0;
  this[3] = 0;
  for ( this[2] = 0; v10 < result; v3 += 116 )
  {
    sub_4F2A90((_DWORD *)(v3 + this[5]));
    result = this[4];
    ++v10;
  }
  v11 = this[5];
  if ( v11 )
  {
    v12 = (void **)(v11 + 116 * *(_DWORD *)(v11 - 4));
    if ( *(_DWORD *)(v11 - 4) - 1 >= 0 )
    {
      v13 = *(_DWORD *)(v11 - 4);
      do
      {
        v12 -= 29;
        sub_4F1860(v12);
        --v13;
      }
      while ( v13 );
    }
    result = sub_5BE8AE();
  }
  this[5] = 0;
  this[4] = 0;
  this[7] = 0;
  this[6] = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  return result;
}
