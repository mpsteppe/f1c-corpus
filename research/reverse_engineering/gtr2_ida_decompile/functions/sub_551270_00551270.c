int __thiscall sub_551270(void *this, unsigned __int8 a2)
{
  int v3; // edi
  int v4; // esi
  int v5; // ebp
  unsigned __int8 v6; // bl
  unsigned __int8 v7; // [esp+1h] [ebp-1h] BYREF

  v7 = HIBYTE(this);
  if ( *(_DWORD *)dword_B640C8 == 6 )
    return dword_92501C[5654 * a2];
  v3 = dword_757C10;
  v4 = 0;
  v5 = 1;
  if ( dword_757C10 > 0 )
  {
    v6 = a2;
    do
    {
      v7 = *(_BYTE *)(*(&dword_91E088 + v4) + 22468);
      if ( v7 != v6 && sub_54FB50(&v7, &a2) < 0 )
        ++v5;
      ++v4;
    }
    while ( v4 < v3 );
  }
  return v5;
}
