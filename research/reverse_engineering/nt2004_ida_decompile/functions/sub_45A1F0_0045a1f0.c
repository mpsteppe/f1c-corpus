char __thiscall sub_45A1F0(_DWORD *this, _DWORD *a2, int a3)
{
  char result; // al
  int v5; // ecx
  _DWORD *v6; // eax
  int v7; // edx
  _DWORD *v8; // edi
  _DWORD *v9; // ebx
  int v10; // edi

  result = 0;
  if ( a2 && a3 >= 4 )
  {
    sub_459F30((int)this);
    this[1] = a3;
    *this = operator new(28 * a3);
    v5 = 0;
    v6 = a2;
    v7 = a3;
    do
    {
      v8 = (_DWORD *)(v5 + *this);
      *v8 = *v6;
      v8[1] = v6[1];
      v8[2] = v6[2];
      v9 = (_DWORD *)(v5 + *this + 12);
      *v9 = v6[3];
      v9[1] = v6[4];
      v10 = v6[5];
      v6 += 6;
      v5 += 28;
      --v7;
      v9[2] = v10;
    }
    while ( v7 );
    sub_45A2B0(this);
    return 1;
  }
  return result;
}
