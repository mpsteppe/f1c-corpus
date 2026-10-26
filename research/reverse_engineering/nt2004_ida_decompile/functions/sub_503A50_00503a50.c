int __thiscall sub_503A50(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v5; // ebp
  float *v6; // ecx
  double v7; // st7
  double v9; // [esp+0h] [ebp-12Ch]
  int v10; // [esp+14h] [ebp-118h] BYREF
  int v11; // [esp+18h] [ebp-114h] BYREF
  int v12; // [esp+1Ch] [ebp-110h] BYREF
  char ArgList[4]; // [esp+20h] [ebp-10Ch] BYREF
  int v14; // [esp+24h] [ebp-108h] BYREF
  float v15; // [esp+28h] [ebp-104h]
  char Buffer[125]; // [esp+2Ch] [ebp-100h] BYREF
  __int16 v17; // [esp+A9h] [ebp-83h]
  char v18; // [esp+ABh] [ebp-81h]
  char Source[125]; // [esp+ACh] [ebp-80h] BYREF
  __int16 v20; // [esp+129h] [ebp-3h]
  char v21; // [esp+12Bh] [ebp-1h]

  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x7Cu);
  v17 = 0;
  v18 = 0;
  Source[0] = byte_629120;
  memset(&Source[1], 0, 0x7Cu);
  v20 = 0;
  v21 = 0;
  sub_501870();
  sub_501880();
  sub_503CE0(a2, &v10, &v14, &v12);
  v4 = *(_DWORD *)(a3 + 20884);
  v5 = v4 - 1;
  if ( v4 == 1 )
  {
    sub_405480(Source, 0x7Fu, "%d %s", this[58], aLapS);
  }
  else
  {
    v6 = (float *)&this[*(_DWORD *)(a3 + 25248) + 4];
    if ( *v6 <= 0.0 )
    {
      if ( this[58] - *(_DWORD *)(a3 + 20848) <= 0 )
        sub_405480(Source, 0x7Fu, "--");
      else
        sub_405480(Source, 0x7Fu, "+%d LAP(S)", this[58] - *(_DWORD *)(a3 + 20848));
    }
    else
    {
      v7 = *v6;
      v15 = *v6;
      if ( v7 > 0.0 )
      {
        *(_DWORD *)ArgList = 0;
        *(float *)&v11 = 0.0;
        sub_4B2BD0(v15, ArgList, (float *)&v11);
        v9 = *(float *)&v11;
        if ( *(int *)ArgList <= 0 )
          sub_405480(Source, 0x7Fu, "+%.3f", v9);
        else
          sub_405480(Source, 0x7Fu, "+%d:%06.3f", *(_DWORD *)ArgList, v9);
      }
    }
  }
  sprintf(Buffer, "%c", v5 + byte_612B9C);
  sub_501610((int)Buffer, v10, v12, 65280, 0, 3, 0.80000001, 0.80000001);
  sub_5020C0(&dword_7D7978, *(_DWORD *)(a3 + 25248));
  v10 += 32;
  strncpy(Buffer, (const char *)(a3 + 24972), 0x7Fu);
  v18 = 0;
  _strupr(Buffer);
  sub_501610((int)Buffer, v10, v12, 0xFFFFFF, 0, 1, 0.80000001, 0.80000001);
  strncpy(Buffer, Source, 0x7Fu);
  v18 = 0;
  return sub_501610((int)Buffer, v14, v12, 0xFFFFFF, 0, 1, 0.80000001, 0.80000001);
}
