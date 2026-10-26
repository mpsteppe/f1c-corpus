int __thiscall sub_5453CB(_DWORD *this, char a2, char a3, int a4)
{
  int v4; // eax
  int v5; // ebx
  _WORD *v6; // edx
  _DWORD *v7; // eax
  unsigned int v8; // esi
  _DWORD *v9; // ecx
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c2
  __int16 v13; // cx
  __int16 v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  unsigned int v17; // [esp+18h] [ebp-8h]
  float v18; // [esp+18h] [ebp-8h]
  _DWORD *v19; // [esp+1Ch] [ebp-4h]

  v19 = this;
  if ( this[1042] )
  {
    v4 = sub_543AE8(this, a4);
    this = v19;
    a4 = v4;
  }
  v5 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_544279();
  v7 = v19;
  v8 = 0;
  if ( v19[1046] )
  {
    v16 = 0;
    do
    {
      v15 = 0;
      v17 = 0;
      v9 = v7 + 14;
      do
      {
        if ( v11 | v12 )
          v15 = v17;
        ++v17;
        v9 += 4;
      }
      while ( v17 < 0x100 );
      v18 = *(float *)(v16 + a4 + 12) * 255.0 + *(float *)(v5 + 4 * (v8 & 3));
      v16 += 16;
      LOBYTE(v13) = 0;
      HIBYTE(v13) = (int)v18;
      *v6 = v15 | v13;
      v7 = v19;
      ++v6;
      ++v8;
    }
    while ( v8 < v19[1046] );
  }
  return dword_7E0598;
}
