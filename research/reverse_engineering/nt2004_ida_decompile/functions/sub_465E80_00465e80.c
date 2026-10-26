int __thiscall sub_465E80(int *this)
{
  int result; // eax
  int v3; // ecx
  const char *v4; // edx
  int v5; // esi
  char *v6; // eax
  int v7; // eax
  CHAR *v8; // eax
  CHAR *v9; // eax
  int v10; // edx
  char v11; // [esp+Bh] [ebp-305h]
  int v12; // [esp+Ch] [ebp-304h] BYREF
  char Destination[32]; // [esp+10h] [ebp-300h] BYREF
  char v14[32]; // [esp+30h] [ebp-2E0h] BYREF
  char v15[48]; // [esp+50h] [ebp-2C0h] BYREF
  char String2[64]; // [esp+80h] [ebp-290h] BYREF
  char Source[77]; // [esp+C0h] [ebp-250h] BYREF
  __int16 v18; // [esp+10Dh] [ebp-203h]
  char v19; // [esp+10Fh] [ebp-201h]
  char v20[512]; // [esp+110h] [ebp-200h] BYREF

  result = *this;
  v3 = *(_DWORD *)(*this + 6720);
  if ( v3 )
  {
    if ( v3 == 2 || v3 == 1 )
    {
      v11 = 1;
      dword_75CBAC = 3;
    }
    else
    {
      v11 = 0;
      dword_75CBAC = 2;
    }
    if ( !byte_766188 )
    {
      sub_462BC0(&v12);
      v4 = (const char *)(*this + 252);
      v12 = 2;
      if ( strlen(v4) )
      {
        strncpy(Destination, v4, 0x1Fu);
      }
      else
      {
        Source[0] = byte_629120;
        memset(&Source[1], 0, 0x4Cu);
        v18 = 0;
        v19 = 0;
        sub_4CE010(Source, 80);
        strncpy(Destination, Source, 0x1Fu);
      }
      Destination[31] = 0;
      String2[0] = 0;
      if ( (unsigned __int8)sub_4CD870(String2, 64) )
      {
        strncpy(v14, String2, 0x1Fu);
        v5 = dword_768228;
        v14[31] = 0;
        sub_4E76F0(String2);
        if ( sub_4E7760(&unk_7D6A50) )
        {
          if ( (unsigned __int8)sub_4E7140(v5, v20, 512) )
          {
            v6 = &v20[strlen(v20)];
            if ( v6 > v20 )
            {
              while ( *v6 != 92 )
              {
                if ( --v6 <= v20 )
                  goto LABEL_18;
              }
              ++v6;
            }
LABEL_18:
            strncpy(v15, v6, 0x1Fu);
            v15[31] = 0;
          }
        }
      }
      sub_463C20((int)&v12);
      *(_DWORD *)(*this + 644) = 1084227584;
    }
    *(_BYTE *)(*this + 32) = 1;
    *(_BYTE *)(*this + 6740) = 9;
    *(_BYTE *)(*this + 6741) = 0;
    switch ( dword_769824 )
    {
      case 1:
        v7 = 8;
        break;
      case 2:
        v7 = 12;
        break;
      case 3:
        v7 = 14;
        break;
      case 4:
        v7 = 32;
        break;
      default:
        v7 = 6;
        break;
    }
    *(_DWORD *)dword_76986C = v7;
    if ( v7 >= dword_769874 )
    {
      if ( v7 > dword_769878 )
        *(_DWORD *)dword_76986C = dword_769878;
    }
    else
    {
      *(_DWORD *)dword_76986C = dword_769874;
    }
    if ( v11 )
    {
      sub_46CE70(dword_769824);
      sub_46CE80(dword_769AF0, -1);
      v8 = (CHAR *)dword_76985C;
      if ( !dword_76985C )
        v8 = &byte_629120;
      sub_578600(v8);
      v9 = (CHAR *)dword_769864;
      if ( !dword_769864 )
        v9 = &byte_629120;
      sub_578600(v9);
      dword_769890 = *(_DWORD *)dword_76986C;
      dword_769894 = dword_769870;
      dword_769898 = dword_769874;
      dword_76989C = dword_769878;
    }
    sub_56A480(dword_7698B4);
    *(_BYTE *)(*this + 40) = 0;
    LOBYTE(result) = sub_45E8B0(*this + 30136);
  }
  v10 = *this;
  *(_DWORD *)(v10 + 668) = 0;
  *(_DWORD *)(v10 + 672) = 0;
  return result;
}
