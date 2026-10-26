int __init_ctype()
{
  _DWORD *v0; // ebx
  wchar_t *v1; // esi
  _BYTE *v2; // eax
  int i; // eax
  BYTE *v4; // eax
  int v5; // edx
  int v6; // ecx
  wchar_t *v7; // ebx
  BYTE *v8; // eax
  int v9; // ecx
  wchar_t *v10; // edx
  int v11; // esi
  wchar_t *v13; // [esp+10h] [ebp-24h]
  void *v14; // [esp+14h] [ebp-20h]
  _BYTE *Block; // [esp+18h] [ebp-1Ch]
  struct _cpinfo CPInfo; // [esp+1Ch] [ebp-18h] BYREF
  int v17; // [esp+30h] [ebp-4h]

  v17 = dword_912B08;
  Block = 0;
  if ( dword_FB83E4 )
  {
    if ( !CodePage && sub_6422F4(0, (unsigned __int16)word_FB840C, 4100, &CodePage) )
    {
      v1 = v13;
    }
    else
    {
      v0 = malloc(4u);
      v14 = v0;
      v1 = (wchar_t *)malloc(0x300u);
      v2 = malloc(0x101u);
      Block = v2;
      if ( v0 )
      {
        if ( v1 )
        {
          if ( v2 )
          {
            *v0 = 0;
            for ( i = 0; i < 256; ++i )
              Block[i] = i;
            if ( GetCPInfo(CodePage, &CPInfo) && CPInfo.MaxCharSize <= 5 )
            {
              SrcSizeInBytes = LOWORD(CPInfo.MaxCharSize);
              if ( LOWORD(CPInfo.MaxCharSize) > 1u && CPInfo.LeadByte[0] )
              {
                v4 = &CPInfo.LeadByte[1];
                do
                {
                  LOBYTE(v5) = *v4;
                  if ( !*v4 )
                    break;
                  v6 = *(v4 - 1);
                  v5 = (unsigned __int8)v5;
                  while ( v6 <= v5 )
                  {
                    Block[v6] = 0;
                    v5 = *v4;
                    ++v6;
                  }
                  v4 += 2;
                }
                while ( *(v4 - 1) );
              }
              v7 = v1 + 128;
              if ( __crtGetStringTypeA(1, Block, 256, v1 + 128, 0, 0, 0) )
              {
                v1[127] = 0;
                if ( (int)SrcSizeInBytes > 1 && CPInfo.LeadByte[0] )
                {
                  v8 = &CPInfo.LeadByte[1];
                  do
                  {
                    if ( !*v8 )
                      break;
                    v9 = *(v8 - 1);
                    if ( v9 <= *v8 )
                    {
                      v10 = &v1[v9 + 128];
                      do
                      {
                        *v10 = 0x8000;
                        ++v9;
                        ++v10;
                      }
                      while ( v9 <= *v8 );
                      v7 = v1 + 128;
                    }
                    v8 += 2;
                  }
                  while ( *(v8 - 1) );
                }
                memcpy_0(v1, v1 + 256, 0xFEu);
                off_913150 = v7;
                dword_FBB5EC = (int)v14;
                dword_FBB5E8 = (int)(v1 + 127);
                v11 = 0;
                goto LABEL_30;
              }
            }
          }
        }
      }
    }
    free(v14);
    free(v1);
    v11 = 1;
LABEL_30:
    free(Block);
    return v11;
  }
  off_913150 = asc_730AC8;
  dword_FBB5EC = 0;
  dword_FBB5E8 = 0;
  return 0;
}
