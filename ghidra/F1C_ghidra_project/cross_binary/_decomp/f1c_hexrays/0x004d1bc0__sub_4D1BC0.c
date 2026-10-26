// f1c  0x004d1bc0  size=115
int __thiscall sub_4D1BC0(void *this, unsigned __int8 a2)
{
  int v3; // edi
  int v4; // esi
  int v5; // ebp
  unsigned __int8 v6; // bl
  unsigned __int8 v7; // [esp+1h] [ebp-1h] BYREF

  v7 = HIBYTE(this);
  if ( dword_7C56A4 == 7 )
    return dword_5F0738[4656 * a2];
  v3 = dword_5C329C;
  v4 = 0;
  v5 = 1;
  if ( dword_5C329C > 0 )
  {
    v6 = a2;
    do
    {
      v7 = *(_BYTE *)(dword_7C54F0[v4] + 18580);
      if ( v7 != v6 && sub_4D0C20(&v7, &a2) < 0 )
        ++v5;
      ++v4;
    }
    while ( v4 < v3 );
  }
  return v5;
}
