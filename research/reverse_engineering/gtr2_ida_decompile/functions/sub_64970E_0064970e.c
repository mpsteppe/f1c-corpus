int __thiscall sub_64970E(_DWORD *this, int a2)
{
  char *v3; // ebx
  int v5; // eax
  int v6; // eax
  char *v7; // edi
  char *v8; // edx
  char *v9; // ecx
  _DWORD *v10; // eax
  int v11; // eax
  size_t v12; // [esp-4h] [ebp-11Ch]
  char Buffer[256]; // [esp+8h] [ebp-110h] BYREF
  char *v14; // [esp+108h] [ebp-10h]
  int v15; // [esp+10Ch] [ebp-Ch]
  int v16; // [esp+110h] [ebp-8h]
  DWORD NumberOfBytesWritten; // [esp+114h] [ebp-4h] BYREF

  NumberOfBytesWritten = 0;
  v12 = 12 * this[3];
  v15 = -2147467259;
  v3 = (char *)operator new(v12);
  v14 = v3;
  if ( !v3 )
    return -2147024882;
  if ( *this == 116 )
  {
    v5 = sub_6462BB(a2, "PF\n", 3u, &NumberOfBytesWritten);
LABEL_7:
    if ( v5 >= 0 )
    {
      sub_649440(Buffer, 0x100u, "%u %u\n-1.000000\n", this[3], this[4]);
      if ( sub_6462BB(a2, Buffer, strlen(Buffer), &NumberOfBytesWritten) >= 0 )
      {
        v6 = this[4] - 1;
        v7 = (char *)(this[1] + v6 * this[12]);
        v16 = v6;
        if ( v6 < 0 )
        {
LABEL_19:
          v15 = 0;
        }
        else
        {
          while ( 1 )
          {
            v8 = v7;
            if ( *this == 116 )
            {
              v9 = &v7[16 * this[3]];
              if ( v7 != v9 )
              {
                v10 = v3 + 8;
                do
                {
                  *(v10 - 2) = *(_DWORD *)v8;
                  *(v10 - 1) = *((_DWORD *)v8 + 1);
                  *v10 = *((_DWORD *)v8 + 2);
                  v8 += 16;
                  v10 += 3;
                }
                while ( v8 != v9 );
                v3 = v14;
              }
              v11 = sub_6462BB(a2, v3, 12 * this[3], &NumberOfBytesWritten);
            }
            else
            {
              v11 = sub_6462BB(a2, v7, 4 * this[3], &NumberOfBytesWritten);
            }
            if ( v11 < 0 )
              break;
            --v16;
            v7 -= this[12];
            if ( v16 < 0 )
              goto LABEL_19;
          }
        }
      }
    }
    goto LABEL_20;
  }
  if ( *this == 114 )
  {
    v5 = sub_6462BB(a2, "Pf\n", 3u, &NumberOfBytesWritten);
    goto LABEL_7;
  }
LABEL_20:
  j__free(v3);
  return v15;
}
