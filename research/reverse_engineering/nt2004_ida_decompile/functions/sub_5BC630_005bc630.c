char __thiscall sub_5BC630(_BYTE *this)
{
  int v2; // edi
  _BYTE *v3; // esi
  char i; // dl
  int v5; // eax
  int v6; // eax
  int v7; // et2
  char v8; // dl

  v2 = 0;
  v3 = this + 109;
  this[108] = rand() % 93 + 33;
  for ( i = -108 - (_BYTE)this; ; i = -108 - (_BYTE)this )
  {
    v2 ^= (this[108] < 79) ^ (*(v3 - 1) < this[108]) ^ ((_BYTE)v3 + i) & 1 ^ (this[108] ^ *(v3 - 1)) & 1;
    v5 = rand();
    v7 = v5 % 93;
    v6 = v5 / 93;
    v8 = v7 + 33;
    *v3 = v7 + 33;
    if ( !v2 )
    {
      LOBYTE(v6) = v8 & 1;
      if ( (v8 & 1) != 1 )
        goto LABEL_8;
LABEL_7:
      *v3 = v8 + 1;
      goto LABEL_8;
    }
    if ( (v8 & 1) == 0 )
      goto LABEL_7;
LABEL_8:
    if ( (int)&(++v3)[-108 - (_DWORD)this] >= 8 )
      break;
  }
  return v6;
}
