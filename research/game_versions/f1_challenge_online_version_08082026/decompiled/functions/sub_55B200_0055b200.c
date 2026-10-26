int __thiscall sub_55B200(int this, int a2, int a3)
{
  __int16 v4; // dx
  __int16 v5; // ax
  int v7; // [esp+Ch] [ebp-42Ch] BYREF
  int v8; // [esp+10h] [ebp-428h] BYREF
  int v9; // [esp+14h] [ebp-424h] BYREF
  int v10; // [esp+18h] [ebp-420h] BYREF
  int v11; // [esp+1Ch] [ebp-41Ch] BYREF
  int v12; // [esp+20h] [ebp-418h] BYREF
  char v13[256]; // [esp+24h] [ebp-414h] BYREF
  _DWORD v14[2]; // [esp+124h] [ebp-314h] BYREF
  int v15; // [esp+12Ch] [ebp-30Ch]
  LPVOID v16; // [esp+434h] [ebp-4h]

  sub_559A40(v14);
  v15 = a3;
  v16 = (LPVOID)sub_587C03(a3);
  if ( sub_58803F(v16, 1, v15, a2) == a3 && sub_559A70(v14) != 3 )
  {
    while ( v14[0] != 3 )
    {
      if ( v14[0] != 2 )
      {
        if ( sub_559E20((int)v14, (int)aIncludefile, v13, 0) && sub_55B6B0(v13) )
          goto LABEL_46;
        if ( sub_559E20((int)v14, (int)aSearchpath, v13, 0) )
          sub_53C6F0(v13);
        if ( sub_559E20((int)v14, (int)aGroupmethod, v13, 0) )
        {
          if ( sub_588640(v13, aDynamic, 7) )
          {
            if ( !sub_588640(v13, aLinksingle, 10) )
              sub_54A160((_DWORD *)this, 0x1000u);
          }
          else
          {
            sub_54A160((_DWORD *)this, 0x2000u);
          }
        }
        if ( sub_559E20((int)v14, (int)aFontfile, v13, 0) )
        {
          if ( sub_53CFE0(&v11, v13, 67585) )
            goto LABEL_46;
          sub_53D340(v11);
        }
        if ( sub_559E20((int)v14, (int)aMasfile, v13, 0) && sub_53CE10(&v12, v13) )
          goto LABEL_46;
        if ( sub_559F00(v14, (int)aAmbientcolor, &v10, &v9, &v8, 0) )
          sub_543800((float *)this, v10, v9, v8);
        if ( sub_559E20((int)v14, (int)aFogmode, v13, 0) )
        {
          if ( !strcmp(v13, aLinear) )
          {
            *(_DWORD *)(this + 412) = 0x20000;
          }
          else if ( !strcmp(v13, aExp) )
          {
            *(_DWORD *)(this + 412) = 0x40000;
          }
          else if ( !strcmp(v13, aExp2) )
          {
            *(_DWORD *)(this + 412) = 0x80000;
          }
        }
        if ( sub_559F00(v14, (int)aFogcolor, &v10, &v9, &v8, 0) )
        {
          v4 = v9;
          v5 = v8;
          *(_WORD *)(this + 396) = v10;
          *(_WORD *)(this + 394) = v4;
          *(_WORD *)(this + 392) = v5;
        }
        if ( sub_559FB0(v14, (int)aFogin, (float *)&v7, 0, 0, 0) )
          *(_DWORD *)(this + 404) = v7;
        if ( sub_559FB0(v14, (int)aFogout, (float *)&v7, 0, 0, 0) )
          *(_DWORD *)(this + 408) = v7;
        if ( sub_559FB0(v14, (int)aFogdensity, (float *)&v7, 0, 0, 0) )
          *(_DWORD *)(this + 400) = v7;
        if ( sub_559E20((int)v14, (int)aView, v13, 0) && sub_55A060((_DWORD *)this, v13, 0, v14)
          || sub_559E20((int)v14, (int)aGroup, v13, 0) && sub_55A790((_DWORD *)this, v13, v14)
          || sub_559E20((int)v14, (int)aInstance, v13, 0) && sub_55A910((_DWORD *)this, v13, 0, v14)
          || sub_559E20((int)v14, (int)aLight, v13, 0) && sub_55A500((void *)this, (int)v13, v14) )
        {
LABEL_46:
          sub_587BCF(v16);
          return -1;
        }
      }
      if ( sub_559A70(v14) == 3 )
        break;
    }
  }
  sub_587BCF(v16);
  return 0;
}
