void __cdecl sub_55071E(jmp_buf Buf)
{
  int v2; // edi
  int v3; // ecx
  _BYTE *v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned __int16 v8; // cx
  int v9; // eax
  int v10; // edi
  char v11; // [esp+Ch] [ebp-4h]
  char Bufa; // [esp+18h] [ebp+8h]

  v2 = *((unsigned __int8 *)Buf + 278);
  if ( ((unsigned int)aGrandPrix & Buf[24]) != 0 )
  {
    sub_550415(Buf);
    if ( v2 == 3 )
    {
      v3 = *((unsigned __int16 *)Buf + 132);
      if ( *((_WORD *)Buf + 132) )
      {
        v4 = (_BYTE *)(Buf[65] + 2);
        do
        {
          *(v4 - 2) = *(_BYTE *)((unsigned __int8)*(v4 - 2) + Buf[78]);
          *(v4 - 1) = *(_BYTE *)((unsigned __int8)*(v4 - 1) + Buf[78]);
          *v4 = *(_BYTE *)((unsigned __int8)*v4 + Buf[78]);
          v4 += 3;
          --v3;
        }
        while ( v3 );
      }
    }
  }
  if ( (Buf[24] & 8) != 0 && v2 == 3 )
  {
    v5 = 8 - *((unsigned __int8 *)Buf + 336);
    v6 = 8 - *((unsigned __int8 *)Buf + 337);
    v7 = 8 - *((unsigned __int8 *)Buf + 338);
    Bufa = 8 - *((_BYTE *)Buf + 337);
    v11 = 8 - *((_BYTE *)Buf + 338);
    if ( v5 > 8 )
      LOBYTE(v5) = 0;
    if ( v6 > 8 )
      Bufa = 0;
    if ( v7 > 8 )
      v11 = 0;
    v8 = *((_WORD *)Buf + 132);
    if ( v8 )
    {
      v9 = 0;
      v10 = v8;
      do
      {
        *(_BYTE *)(v9 + Buf[65]) >>= v5;
        *(_BYTE *)(v9 + Buf[65] + 1) >>= Bufa;
        *(_BYTE *)(v9 + Buf[65] + 2) >>= v11;
        v9 += 3;
        --v10;
      }
      while ( v10 );
    }
  }
}
