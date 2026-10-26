// f1c  0x0054c410  size=241
int __thiscall sub_54C410(_DWORD *this)
{
  _DWORD *v2; // ebp
  int v3; // ebx
  int v4; // edi
  _DWORD *v5; // edi
  void *v6; // ebx
  int v7; // eax
  void *v8; // ebp
  int v9; // edi
  int v10; // ebx

  v2 = (_DWORD *)sub_545F40((_DWORD *)dword_8B8F28);
  v3 = 0;
  if ( (int)this[70] > 0 )
  {
    v4 = 0;
    do
    {
      sub_547710(v2, *(_DWORD **)(v4 + this[71] + 4));
      *(_DWORD *)(v4 + this[71] + 4) = 0;
      sub_540CB0(dword_8B78A0, v4 + this[71]);
      ++v3;
      v4 += 64;
    }
    while ( v3 < this[70] );
  }
  v5 = (_DWORD *)this[79];
  while ( v5 )
  {
    v6 = v5;
    v5 = (_DWORD *)v5[9];
    sub_5511A0(v6);
    sub_587BCF(v6);
  }
  v7 = this[68];
  if ( v7 )
  {
    v8 = (void *)(v7 - 4);
    v9 = v7 + 56 * *(_DWORD *)(v7 - 4);
    if ( *(_DWORD *)(v7 - 4) - 1 >= 0 )
    {
      v10 = *(_DWORD *)(v7 - 4);
      do
      {
        v9 -= 56;
        nullsub_3();
        --v10;
      }
      while ( v10 );
    }
    sub_587BCF(v8);
    this[68] = 0;
  }
  if ( this[81] )
  {
    nullsub_3();
    this[81] = 0;
  }
  return 0;
}
