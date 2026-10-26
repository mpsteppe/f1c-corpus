int __thiscall sub_5E2070(float *this, int *a2)
{
  int v3; // edx
  int v4; // esi
  int v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // edi
  int v9; // eax
  float v11; // [esp+0h] [ebp-95Ch] BYREF
  float v12; // [esp+4h] [ebp-958h] BYREF
  char *EndPtr; // [esp+8h] [ebp-954h] BYREF
  char *v14[2]; // [esp+Ch] [ebp-950h] BYREF
  char *v15; // [esp+14h] [ebp-948h] BYREF
  char *v16[2]; // [esp+18h] [ebp-944h] BYREF
  char ArgList[16]; // [esp+20h] [ebp-93Ch] BYREF
  char v18[4]; // [esp+30h] [ebp-92Ch] BYREF
  char String[8]; // [esp+34h] [ebp-928h] BYREF
  char v20[8]; // [esp+3Ch] [ebp-920h] BYREF
  char v21[220]; // [esp+44h] [ebp-918h] BYREF
  int v22; // [esp+120h] [ebp-83Ch] BYREF
  _BYTE v23[4]; // [esp+130h] [ebp-82Ch] BYREF
  _BYTE v24[8]; // [esp+134h] [ebp-828h] BYREF
  int v25; // [esp+13Ch] [ebp-820h] BYREF
  int v26[2]; // [esp+144h] [ebp-818h] BYREF
  int v27; // [esp+14Ch] [ebp-810h]
  _BYTE v28[1024]; // [esp+150h] [ebp-80Ch] BYREF
  int v29; // [esp+92Ch] [ebp-30h]
  int v30; // [esp+930h] [ebp-2Ch]
  int v31; // [esp+934h] [ebp-28h]
  int v32; // [esp+938h] [ebp-24h]
  int v33; // [esp+93Ch] [ebp-20h]
  void *Block; // [esp+94Ch] [ebp-10h]
  int v35; // [esp+950h] [ebp-Ch]
  int v36; // [esp+954h] [ebp-8h]
  int savedregs; // [esp+95Ch] [ebp+0h] BYREF

  memset(v28, 0, sizeof(v28));
  v26[0] = 0;
  v26[1] = 0;
  v27 = 0;
  v35 = 0;
  v36 = 0;
  sub_5D8DD0((int)this, (char)this, 1);
  v3 = *a2;
  v27 = a2[2];
  v36 = v3;
  if ( sub_5DF750(v26) != 3 )
  {
    while ( v26[0] != 3 )
    {
      if ( v26[0] != 2 )
      {
        if ( sub_5DF060(v26, "INCLUDEFILE", v21) )
        {
          EndPtr = 0;
          if ( sub_5E26B0(v21) )
          {
            j__free(Block);
            return -1;
          }
        }
        if ( sub_5DF060(&v25, "SEARCHPATH", v20) )
          sub_5D9420(this, (int)v20, 1);
        if ( sub_5DF240((int)v24, "MASFILE", String, 0, 0, 0, 0, 0, 0, 0) && sub_5EE940((int)v18, (char)String, 1) )
          return -1;
        if ( sub_5DEF70() )
        {
          EndPtr = (char *)(v33 + 1);
          v4 = strtol((const char *)(v33 + 1), &EndPtr, 10);
          v5 = strtol(EndPtr + 1, &EndPtr, 10);
          v6 = strtol(EndPtr + 1, &EndPtr, 10);
          sub_5DCDE0(this, v4, v5, v6);
        }
        if ( sub_5DF240((int)v23, "FOGMODE", v18, 0, 0, 0, 0, 0, 0, 0) )
        {
          if ( !strcmp(v18, "LINEAR") )
          {
            sub_5DD280((int *)this, 16);
          }
          else if ( !strcmp(v18, (const char *)&off_72BBB0) )
          {
            sub_5DD280((int *)this, 32);
          }
          else if ( !strcmp(v18, "EXP2") )
          {
            sub_5DD280((int *)this, 64);
          }
        }
        if ( sub_5DEF70() )
        {
          EndPtr = (char *)(v32 + 1);
          v7 = strtol((const char *)(v32 + 1), &EndPtr, 10);
          v8 = strtol(EndPtr + 1, &EndPtr, 10);
          v9 = strtol(EndPtr + 1, &EndPtr, 10);
          sub_5DD1B0(this, v7, v8, v9);
        }
        if ( sub_5DEF70() )
        {
          v16[0] = (char *)(v31 + 1);
          this[62] = strtod((const char *)(v31 + 1), v16);
        }
        if ( sub_5DEF70() )
        {
          v14[0] = (char *)(v30 + 1);
          this[63] = strtod((const char *)(v30 + 1), v14);
        }
        if ( sub_5DEF70() )
        {
          v15 = (char *)(v29 + 1);
          this[61] = strtod((const char *)(v29 + 1), &v15);
        }
        if ( sub_5DF630((int)"REFLECTPLANE", (int)v14, (int)&v12, (int)v16, (int)&v11) )
          sub_5DD2E0(this, *(float *)v14, v12, *(float *)v16, v11);
        if ( sub_5DF240((int)&v22, "VIEW", ArgList, 0, 0, 0, 0, 0, 0, 0) && sub_5DF7B0((char *)this, ArgList, 0, &v22)
          || sub_5DF240((int)&v22, "INSTANCE", ArgList, 0, 0, 0, 0, 0, 0, 0)
          && sub_5E12E0(this, (float *)&savedregs, ArgList, 0, &v22)
          || sub_5DF240((int)&v22, "LIGHT", ArgList, 0, 0, 0, 0, 0, 0, 0) && sub_5DFD60(this, (int)ArgList, 0, &v22)
          || sub_5DF240((int)&v22, "REFLECTIONMAPPER", ArgList, 0, 0, 0, 0, 0, 0, 0)
          && sub_5E0490(this, (int)ArgList, &v22) )
        {
          return -1;
        }
      }
      if ( sub_5DF750(&v22) == 3 )
        return 0;
    }
  }
  return 0;
}
