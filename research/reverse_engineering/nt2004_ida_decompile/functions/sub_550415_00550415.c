void __cdecl sub_550415(jmp_buf Buf)
{
  long double v2; // st7
  int v3; // eax
  __int64 v4; // rax
  int v5; // eax
  unsigned int v6; // edi
  int v7; // ebx
  long double v8; // st7
  int v9; // eax
  bool v10; // zf
  int v11; // eax
  int *__attribute__((__org_typedef(jmp_buf))) v12; // edx
  __int16 v13; // cx
  unsigned int v14; // ebx
  int v15; // eax
  int v16; // ebx
  __int64 v17; // rax
  double v18; // [esp+4h] [ebp-28h]
  unsigned int v19; // [esp+14h] [ebp-18h]
  unsigned int v20; // [esp+18h] [ebp-14h]
  char v21; // [esp+1Ch] [ebp-10h]
  unsigned int v22; // [esp+20h] [ebp-Ch]
  int v23; // [esp+28h] [ebp-4h]
  int *__attribute__((__org_typedef(jmp_buf))) Bufa; // [esp+34h] [ebp+8h]
  int *__attribute__((__org_typedef(jmp_buf))) Bufb; // [esp+34h] [ebp+8h]
  int *__attribute__((__org_typedef(jmp_buf))) Bufc; // [esp+34h] [ebp+8h]

  if ( *((float *)Buf + 76) != 0.0 )
  {
    if ( *((_BYTE *)Buf + 279) > 8u )
    {
      if ( (*((_BYTE *)Buf + 278) & 2) != 0 )
      {
        v5 = *((unsigned __int8 *)Buf + 336);
        if ( *((unsigned __int8 *)Buf + 337) > v5 )
          v5 = *((unsigned __int8 *)Buf + 337);
        if ( *((unsigned __int8 *)Buf + 338) > v5 )
          v5 = *((unsigned __int8 *)Buf + 338);
      }
      else
      {
        v5 = *((unsigned __int8 *)Buf + 339);
      }
      v6 = 0;
      if ( v5 <= 0 )
        v23 = 0;
      else
        v23 = 16 - v5;
      if ( (*((_BYTE *)Buf + 97) & 4) != 0 && v23 < 5 )
        v23 = 5;
      if ( v23 > 8 )
        v23 = 8;
      if ( v23 < 0 )
        v23 = 0;
      v7 = 1 << (8 - v23);
      v21 = 8 - v23;
      Buf[75] = (unsigned __int8)v23;
      if ( *((float *)Buf + 77) <= 0.000001 )
        v8 = 1.0;
      else
        v8 = 1.0 / (*((float *)Buf + 77) * *((float *)Buf + 76));
      v9 = sub_554E20(Buf, 4 * v7);
      v10 = (Buf[24] & 0x480) == 0;
      Buf[81] = v9;
      Bufb = 0;
      if ( v10 )
      {
        if ( v7 > 0 )
        {
          do
          {
            *(_DWORD *)(Buf[81] + 4 * (_DWORD)Bufb) = sub_554E20(Buf, 0x200u);
            v16 = 0;
            v22 = (unsigned int)((_DWORD)Bufb * dword_61761C[v23]) >> 4;
            do
            {
              v17 = (__int64)(pow((double)v22 * 0.00001525902189669642, v8) * 65535.0 + 0.5);
              v22 += 256;
              *(_WORD *)(v16 + *(_DWORD *)(Buf[81] + 4 * (_DWORD)Bufb)) = v17;
              v16 += 2;
            }
            while ( v16 < 512 );
            Bufb = (int *)((char *)Bufb + 1);
          }
          while ( (int)Bufb < 1 << (8 - v23) );
        }
      }
      else
      {
        if ( v7 > 0 )
        {
          do
          {
            v11 = sub_554E20(Buf, 0x200u);
            v12 = Bufb;
            Bufb = (int *)((char *)Bufb + 1);
            *(_DWORD *)(Buf[81] + 4 * (_DWORD)v12) = v11;
          }
          while ( (int)Bufb < v7 );
          v6 = 0;
        }
        Bufc = 0;
        v20 = v7 << 8;
        v18 = (double)(unsigned int)(v7 << 8);
        do
        {
          v19 = (__int64)(pow(((double)(int)Bufc + 0.5) * 0.00390625, 1.0 / v8) * v18);
          if ( v6 <= v19 )
          {
            LOBYTE(v13) = 0;
            HIBYTE(v13) = (_BYTE)Bufc;
            do
            {
              v14 = v6 >> v21;
              v15 = *(_DWORD *)(Buf[81] + 4 * (v6++ & (255 >> v23)));
              *(_WORD *)(v15 + 2 * v14) = (unsigned __int16)Bufc | v13;
            }
            while ( v6 <= v19 );
          }
          Bufc = (int *)((char *)Bufc + 1);
        }
        while ( (int)Bufc < 256 );
        for ( ; v6 < v20; ++v6 )
          *(_WORD *)(*(_DWORD *)(Buf[81] + 4 * (v6 & (255 >> v23))) + 2 * (v6 >> v21)) = -1;
      }
    }
    else
    {
      if ( *((float *)Buf + 77) <= 0.000001 )
        v2 = 1.0;
      else
        v2 = 1.0 / (*((float *)Buf + 77) * *((float *)Buf + 76));
      v3 = sub_554E20(Buf, 0x100u);
      Bufa = 0;
      Buf[78] = v3;
      do
      {
        v4 = (__int64)(pow((double)(int)Bufa * 0.00392156862745098, v2) * 255.0 + 0.5);
        HIDWORD(v4) = Bufa;
        Bufa = (int *)((char *)Bufa + 1);
        *(_BYTE *)(HIDWORD(v4) + Buf[78]) = v4;
      }
      while ( (int)Bufa < 256 );
    }
  }
}
