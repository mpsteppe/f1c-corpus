int __thiscall sub_4F8030(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ebx
  int v5; // edi
  int v6; // ecx
  char v7; // al
  _DWORD *v8; // ecx

  result = this[72];
  v4 = 0;
  if ( result > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this[73];
      v7 = *(_BYTE *)(v6 + v5 + 8);
      v8 = (_DWORD *)(v5 + v6);
      if ( v7 )
        sub_4F7DD0(v8, a2);
      result = this[72];
      ++v4;
      v5 += 768;
    }
    while ( v4 < result );
  }
  return result;
}
