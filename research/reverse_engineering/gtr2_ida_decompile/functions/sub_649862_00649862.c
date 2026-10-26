int __thiscall sub_649862(_DWORD *this, int a2)
{
  unsigned int v3; // edx
  unsigned int v4; // eax
  const void *v5; // eax
  bool v6; // zf
  int v7; // eax
  float *v8; // esi
  unsigned __int8 *v9; // ebx
  double v10; // st7
  float v11; // eax
  double v12; // st7
  double v13; // st7
  double v14; // st6
  double v15; // st7
  __int64 v16; // rax
  unsigned int v17; // eax
  char *v18; // esi
  unsigned int v19; // ecx
  unsigned __int8 v20; // bl
  int v21; // eax
  _BYTE *v22; // edx
  char v23; // cl
  char Buffer[256]; // [esp+18h] [ebp-138h] BYREF
  float v26; // [esp+118h] [ebp-38h]
  unsigned int v27; // [esp+11Ch] [ebp-34h]
  int Y; // [esp+120h] [ebp-30h] BYREF
  int v29; // [esp+124h] [ebp-2Ch]
  LPCVOID lpBuffer; // [esp+128h] [ebp-28h]
  unsigned int v31; // [esp+12Ch] [ebp-24h]
  void *Block; // [esp+130h] [ebp-20h]
  char v33; // [esp+137h] [ebp-19h]
  char v34; // [esp+138h] [ebp-18h] BYREF
  char v35; // [esp+139h] [ebp-17h]
  char v36; // [esp+13Ah] [ebp-16h]
  char v37; // [esp+13Bh] [ebp-15h]
  float v38; // [esp+13Ch] [ebp-14h]
  float v39; // [esp+140h] [ebp-10h]
  DWORD NumberOfBytesWritten; // [esp+144h] [ebp-Ch] BYREF
  float v41; // [esp+148h] [ebp-8h]
  unsigned __int8 v42; // [esp+14Fh] [ebp-1h] BYREF

  v3 = this[4];
  NumberOfBytesWritten = 0;
  v29 = -2147467259;
  if ( v3 <= 0x7FFF )
  {
    v4 = this[3];
    if ( v4 <= 0x7FFF )
    {
      Block = operator new(4 * v3 * v4);
      v5 = operator new(0x80u);
      lpBuffer = v5;
      if ( Block && v5 )
      {
        if ( sub_6462BB(a2, (char *)::lpBuffer, strlen((const char *)::lpBuffer), &NumberOfBytesWritten) >= 0 )
        {
          _strtime(Buffer);
          if ( sub_6462BB(a2, Buffer, strlen(Buffer), &NumberOfBytesWritten) >= 0
            && sub_6462BB(a2, (char *)CommandLine, 1u, &NumberOfBytesWritten) >= 0 )
          {
            _strdate(Buffer);
            if ( sub_6462BB(a2, Buffer, strlen(Buffer), &NumberOfBytesWritten) >= 0
              && sub_6462BB(a2, "\n\n", 2u, &NumberOfBytesWritten) >= 0 )
            {
              sub_649440(Buffer, 0x100u, "-Y %u +X %u\n", this[4], this[3]);
              if ( sub_6462BB(a2, Buffer, strlen(Buffer), &NumberOfBytesWritten) >= 0 )
              {
                v6 = this[4] == 0;
                v31 = 0;
                if ( !v6 )
                {
                  do
                  {
                    v7 = this[3];
                    v8 = (float *)(this[1] + v31 * this[12]);
                    v27 = 0;
                    v9 = (unsigned __int8 *)Block + 4 * v31 * v7;
                    if ( v7 )
                    {
                      do
                      {
                        if ( *v8 <= 0.0 )
                          v39 = 0.0;
                        else
                          v39 = *v8;
                        if ( v8[1] <= 0.0 )
                          v38 = 0.0;
                        else
                          v38 = v8[1];
                        if ( v8[2] <= 0.0 )
                          v10 = 0.0;
                        else
                          v10 = v8[2];
                        v26 = v10;
                        v11 = v39;
                        if ( v39 <= (double)v38 )
                          v11 = v38;
                        v41 = v11;
                        if ( v11 <= v10 )
                          v41 = v10;
                        if ( v41 <= 1.0e-32 )
                        {
                          v9[3] = 0;
                          v9[2] = 0;
                          v9[1] = 0;
                          *v9 = 0;
                        }
                        else
                        {
                          v12 = frexp(v41, &Y);
                          Y += 128;
                          v13 = v12 / v41 * 256.0;
                          v14 = v38 * v13;
                          v42 = (__int64)(v39 * v13);
                          *v9 = v42;
                          v15 = v13 * v26;
                          v33 = (__int64)v14;
                          v9[1] = v33;
                          v16 = (__int64)v15;
                          v6 = v42 == 0;
                          v9[2] = (__int64)v15;
                          if ( !v6 || v33 || (_BYTE)v16 )
                            LOBYTE(v16) = 1;
                          v9[3] = (_BYTE)v16 == 0 ? 0 : Y;
                        }
                        ++v27;
                        v8 += 4;
                        v9 += 4;
                      }
                      while ( v27 < this[3] );
                    }
                    ++v31;
                  }
                  while ( v31 < this[4] );
                }
                v6 = this[4] == 0;
                v39 = 0.0;
                if ( v6 )
                {
LABEL_56:
                  v29 = 0;
                }
                else
                {
                  while ( 1 )
                  {
                    v36 = BYTE1(this[3]);
                    v37 = *((_BYTE *)this + 12);
                    v34 = 2;
                    v35 = 2;
                    if ( sub_6462BB(a2, &v34, 4u, &NumberOfBytesWritten) < 0 )
                      break;
                    v38 = 0.0;
                    do
                    {
                      v17 = this[3];
                      v18 = (char *)Block + 4 * LODWORD(v39) * v17 + LODWORD(v38);
                      v41 = 0.0;
                      if ( v17 )
                      {
                        do
                        {
                          v19 = LODWORD(v41) + 1;
                          v20 = 1;
                          if ( LODWORD(v41) + 1 >= v17 )
                            goto LABEL_46;
                          do
                          {
                            if ( v20 >= 0x7Fu )
                              break;
                            if ( v18[4 * v20] != *v18 )
                              break;
                            ++v20;
                          }
                          while ( LODWORD(v41) + (unsigned int)v20 < v17 );
                          if ( v20 <= 1u )
                          {
LABEL_46:
                            v22 = lpBuffer;
                            v42 = 1;
                            *(_BYTE *)lpBuffer = *v18;
                            if ( v19 < this[3] )
                            {
                              do
                              {
                                if ( v42 >= 0x7Fu )
                                  break;
                                v23 = v18[4 * v42];
                                if ( v18[4 * v42 - 4] == v23 )
                                  break;
                                v22[v42++] = v23;
                              }
                              while ( LODWORD(v41) + (unsigned int)v42 < this[3] );
                            }
                            if ( sub_6462BB(a2, (char *)&v42, 1u, &NumberOfBytesWritten) < 0
                              || sub_6462BB(a2, (char *)lpBuffer, v42, &NumberOfBytesWritten) < 0 )
                            {
                              goto LABEL_58;
                            }
                            v21 = v42;
                          }
                          else
                          {
                            v34 = v20 + 0x80;
                            v35 = *v18;
                            if ( sub_6462BB(a2, &v34, 2u, &NumberOfBytesWritten) < 0 )
                              goto LABEL_58;
                            v21 = v20;
                          }
                          LODWORD(v41) += v21;
                          v18 += 4 * v21;
                          v17 = this[3];
                        }
                        while ( LODWORD(v41) < v17 );
                      }
                      ++LODWORD(v38);
                    }
                    while ( SLODWORD(v38) < 4 );
                    if ( ++LODWORD(v39) >= this[4] )
                      goto LABEL_56;
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v29 = -2147024882;
      }
LABEL_58:
      if ( Block )
        j__free(Block);
      if ( lpBuffer )
        j__free((void *)lpBuffer);
    }
  }
  return v29;
}
