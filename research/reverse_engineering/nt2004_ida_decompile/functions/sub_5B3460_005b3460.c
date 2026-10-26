int __thiscall sub_5B3460(int this, FILE *Stream, size_t a3)
{
  __int16 v4; // dx
  __int16 v5; // ax
  int v7; // [esp+Ch] [ebp-92Ch] BYREF
  int v8; // [esp+10h] [ebp-928h] BYREF
  int v9; // [esp+14h] [ebp-924h] BYREF
  int v10; // [esp+18h] [ebp-920h] BYREF
  int *v11; // [esp+1Ch] [ebp-91Ch] BYREF
  int v12; // [esp+20h] [ebp-918h] BYREF
  char Str1[256]; // [esp+24h] [ebp-914h] BYREF
  int v14[2]; // [esp+124h] [ebp-814h] BYREF
  size_t ElementCount; // [esp+12Ch] [ebp-80Ch]
  void *v16; // [esp+934h] [ebp-4h]

  sub_5B19E0(v14);
  ElementCount = a3;
  v16 = operator new(a3);
  if ( sub_5BED6F(v16, 1u, ElementCount, Stream) == a3 && sub_5B1A10(v14) != 3 )
  {
    while ( v14[0] != 3 )
    {
      if ( v14[0] != 2 )
      {
        if ( sub_5B1DC0((int)v14, aIncludefile, Str1, 0) && sub_5B3910(this, Str1) )
          goto LABEL_46;
        if ( sub_5B1DC0((int)v14, aSearchpath, Str1, 0) )
          sub_591DE0(Str1);
        if ( sub_5B1DC0((int)v14, aGroupmethod, Str1, 0) )
        {
          if ( !strncmp(Str1, aDynamic, 7u) )
          {
            sub_5953E0((_DWORD *)this, 0x2000u);
          }
          else if ( !strncmp(Str1, aLinksingle, 0xAu) )
          {
            sub_5953E0((_DWORD *)this, 0x1000u);
          }
        }
        if ( sub_5B1DC0((int)v14, aFontfile, Str1, 0) )
        {
          if ( sub_592A60(&v11, Str1, 67585) )
            goto LABEL_46;
          sub_592E50(v11);
        }
        if ( sub_5B1DC0((int)v14, aMasfile, Str1, 0) && sub_592720((void *)this, &v12, Str1) )
          goto LABEL_46;
        if ( sub_5B1EA0((int)v14, aAmbientcolor, &v10, &v9, &v8, 0) )
          sub_595A30((float *)this, v10, v9, v8);
        if ( sub_5B1DC0((int)v14, aFogmode, Str1, 0) )
        {
          if ( !strcmp(Str1, aLinear) )
          {
            *(_DWORD *)(this + 428) = 0x20000;
          }
          else if ( !strcmp(Str1, (const char *)&off_61BF9C) )
          {
            *(_DWORD *)(this + 428) = 0x40000;
          }
          else if ( !strcmp(Str1, aExp2) )
          {
            *(_DWORD *)(this + 428) = 0x80000;
          }
        }
        if ( sub_5B1EA0((int)v14, aFogcolor, &v10, &v9, &v8, 0) )
        {
          v4 = v9;
          v5 = v8;
          *(_WORD *)(this + 412) = v10;
          *(_WORD *)(this + 410) = v4;
          *(_WORD *)(this + 408) = v5;
        }
        if ( sub_5B1F50((int)v14, aFogin, (float *)&v7, 0, 0, 0) )
          *(_DWORD *)(this + 420) = v7;
        if ( sub_5B1F50((int)v14, aFogout, (float *)&v7, 0, 0, 0) )
          *(_DWORD *)(this + 424) = v7;
        if ( sub_5B1F50((int)v14, aFogdensity, (float *)&v7, 0, 0, 0) )
          *(_DWORD *)(this + 416) = v7;
        if ( sub_5B1DC0((int)v14, aView, Str1, 0) && sub_5B2000((_DWORD *)this, Str1, 0, v14)
          || sub_5B1DC0((int)v14, aGroup, Str1, 0) && sub_5B29A0((_DWORD *)this, Str1, v14)
          || sub_5B1DC0((int)v14, aInstance, Str1, 0) && sub_5B2B20((_DWORD *)this, Str1, 0, v14)
          || sub_5B1DC0((int)v14, aLight, Str1, 0) && sub_5B24B0((void *)this, (int)Str1, v14) )
        {
LABEL_46:
          sub_5BE8AE();
          return -1;
        }
      }
      if ( sub_5B1A10(v14) == 3 )
        break;
    }
  }
  sub_5BE8AE();
  return 0;
}
