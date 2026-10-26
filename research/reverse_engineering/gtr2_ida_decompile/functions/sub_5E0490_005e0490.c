int __thiscall sub_5E0490(_DWORD *this, int ArgList, int *a3)
{
  _DWORD *v3; // esi
  int v4; // ebp
  int v5; // eax
  double v6; // st7
  double v7; // st7
  int v8; // eax
  int v10; // [esp+10h] [ebp-194h] BYREF
  int v11; // [esp+14h] [ebp-190h]
  char *v12; // [esp+18h] [ebp-18Ch] BYREF
  char *EndPtr; // [esp+1Ch] [ebp-188h] BYREF
  char *v14; // [esp+20h] [ebp-184h] BYREF
  char String[64]; // [esp+24h] [ebp-180h] BYREF
  char v16[64]; // [esp+64h] [ebp-140h] BYREF
  char v17[256]; // [esp+A4h] [ebp-100h] BYREF

  v3 = this;
  v11 = (int)this;
  v10 = 0;
  v4 = 8;
  if ( sub_5DF750(a3) != 1 )
  {
    while ( *a3 != 3 )
    {
      if ( *a3 != 2 )
      {
        if ( sub_5DF240((int)a3, "TYPE", String, 0, 0, 0, 0, 0, 0, 0) )
        {
          if ( !strcmp(String, "SPHERICAL") )
          {
            v4 = 4;
          }
          else if ( !strcmp(String, "CUBIC") )
          {
            v4 = 8;
          }
          if ( sub_607810(v11, ArgList, v4, 0, 0, (int)&v10) )
          {
            sub_5D8C80(v11, (char *)0xFFFFFFFF, "Error creating reflection mapper %s", ArgList);
            return -1;
          }
          v3 = (_DWORD *)v11;
        }
        if ( sub_5DEF70() )
        {
          EndPtr = (char *)(a3[515] + 1);
          v5 = strtol(EndPtr, &EndPtr, 10);
          *(_DWORD *)(v10 + 44) = v5;
        }
        if ( sub_5DEF70() )
        {
          v12 = (char *)(a3[515] + 1);
          v6 = strtod(v12, &v12);
          *(float *)(v10 + 48) = v6;
        }
        if ( sub_5DEF70() )
        {
          v14 = (char *)(a3[515] + 1);
          v7 = strtod(v14, &v14);
          *(float *)(v10 + 52) = v7;
        }
        if ( sub_5DF240((int)a3, "TRACKINGINS", v16, 0, 0, 0, 0, 0, 0, 0) )
        {
          v8 = sub_5DA9A0(v3, v16, 0);
          sub_607070(v8);
        }
        if ( sub_5DF240((int)a3, "REFLECTOR", v17, 0, 0, 0, 0, 0, 0, 0) )
          sub_6072A0(v10, (char)v17, (int)v3);
      }
      if ( sub_5DF750(a3) == 1 )
        return 0;
    }
  }
  return 0;
}
