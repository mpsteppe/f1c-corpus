char __thiscall sub_4681B0(_DWORD *this)
{
  const char *v2; // eax
  const char *v3; // ecx
  const char *v4; // eax
  int v5; // ebp
  int i; // ebx
  char *v7; // eax
  int v8; // ecx
  double v9; // st7
  int j; // esi
  float v12; // [esp+0h] [ebp-2B0h]
  float v13; // [esp+4h] [ebp-2ACh]
  float v14; // [esp+8h] [ebp-2A8h]
  float v15; // [esp+14h] [ebp-29Ch]
  float v16; // [esp+18h] [ebp-298h] BYREF
  float v17; // [esp+1Ch] [ebp-294h]
  float v18; // [esp+20h] [ebp-290h]
  float v19; // [esp+24h] [ebp-28Ch] BYREF
  float v20; // [esp+28h] [ebp-288h] BYREF
  float v21; // [esp+2Ch] [ebp-284h] BYREF
  CHAR FileName[128]; // [esp+30h] [ebp-280h] BYREF
  _BYTE v23[512]; // [esp+B0h] [ebp-200h] BYREF

  if ( (int)this[74] >= 0 )
  {
    v2 = (const char *)dword_5EC440;
    if ( !dword_5EC440 )
      v2 = byte_5EA438;
    sub_58815F(FileName, "%s%s", v2, aTmpvehicleScn);
    v3 = (const char *)dword_5EC428;
    if ( !dword_5EC428 )
      v3 = byte_5EA438;
    v4 = (const char *)dword_5EC3D8;
    if ( !dword_5EC3D8 )
      v4 = byte_5EA438;
    sub_58815F(v23, "%s%s%s", v4, v3, aVviewScn);
    sub_4DDF90(0, v23);
    sub_566650(FileName);
    sub_466300(this);
    if ( this[58] )
    {
      this[60] = sub_545340(0);
      sub_4DDF70(this[58]);
    }
    if ( this[58] && this[59] && this[60] )
    {
      if ( sub_5453A0(aCockpit, this[60]) )
        sub_54C030(0, 0, 0, 0);
      if ( sub_5453A0(aMirror, this[60]) )
        sub_54C030(0, 0, 0, 0);
      v5 = 0;
      v16 = 0.0;
      v17 = 0.0;
      v18 = 0.0;
      for ( i = 0; i < 4; ++i )
      {
        if ( i )
        {
          if ( i == 1 )
          {
            v7 = aRftire;
            v15 = -0.037999999;
          }
          else if ( i == 2 )
          {
            v7 = aLrtire;
            v15 = 0.013;
          }
          else
          {
            v7 = aRrtire;
            v15 = -0.013;
          }
        }
        else
        {
          v7 = aLftire;
          v15 = 0.037999999;
        }
        if ( sub_5453A0(v7, this[60]) )
        {
          sub_5506A0(0, 0, 0);
          sub_54B450(0.0, 0.0, v15);
          ++v5;
          sub_54B420(&v19, &v20, &v21);
          v16 = v19 + v16;
          v17 = v20 + v17;
          v18 = v21 + v18;
        }
      }
      if ( v5 > 1 )
      {
        v8 = this[60];
        v17 = 0.0;
        v9 = 1.0 / (double)v5;
        v16 = v16 * v9;
        v18 = v9 * v18;
        sub_40E1F0(v8, &v16);
        for ( j = *(_DWORD *)(this[60] + 68); j; j = *(_DWORD *)(j + 76) )
        {
          v14 = -v18;
          v13 = -v17;
          v12 = -v16;
          sub_54B3F0(v12, v13, v14);
        }
      }
    }
    sub_58986E(FileName);
  }
  return 0;
}
