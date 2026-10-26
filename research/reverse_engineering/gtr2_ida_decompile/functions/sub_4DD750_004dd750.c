int __thiscall sub_4DD750(int this, int a2, char a3, char a4, int a5)
{
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  int v11; // edi
  char v12[8]; // [esp+0h] [ebp-118h] BYREF
  char v13[8]; // [esp+8h] [ebp-110h] BYREF
  char v14[8]; // [esp+10h] [ebp-108h] BYREF
  char Buffer[256]; // [esp+18h] [ebp-100h] BYREF

  if ( !a2 )
    return -1;
  strcpy((char *)(this + 368), (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)a2 + 12))(a2));
  *(_BYTE *)(this + 764) = a3;
  *(_DWORD *)(this + 776) = a2;
  *(_BYTE *)(this + 765) = a4;
  *(_BYTE *)(this + 766) = 0;
  if ( sub_4DAC10(this) == -1 )
    return -1;
  sub_4DC320((_DWORD *)this);
  if ( byte_75B170 )
  {
    v7 = (const char *)dword_91CAD0;
    if ( !dword_91CAD0 )
      v7 = WindowName;
    sprintf(Buffer, "%s%s", v7, "SimBin.bik");
    if ( sub_590B70(&unk_FB1E98, Buffer, 1) != -1 )
    {
      v8 = (const char *)dword_91CAD0;
      if ( !dword_91CAD0 )
        v8 = WindowName;
      sprintf(v14, "%s%s", v8, "Intro.bik");
      if ( sub_590B70(&unk_FB1E98, v14, 1) != -1 )
      {
        v9 = (const char *)dword_91CAD0;
        if ( !dword_91CAD0 )
          v9 = WindowName;
        sprintf(v13, "%s%s", v9, "GfxIntro.bik");
        if ( sub_590B70(&unk_FB1E98, v13, 1) != -1 )
        {
          v10 = (const char *)dword_91CAD0;
          if ( !dword_91CAD0 )
            v10 = WindowName;
          sprintf(v12, "%s%s", v10, "GameIntro.bik");
          sub_590B70(&unk_FB1E98, v12, 1);
        }
      }
    }
    sub_58FBA0((int)"Legal.bmp", 0.0, 1);
  }
  v11 = sub_4DD510(this);
  (*(void (__thiscall **)(int))(*(_DWORD *)(this + 92) + 20))(this + 92);
  (*(void (__thiscall **)(int))(*(_DWORD *)(this + 184) + 20))(this + 184);
  (*(void (__thiscall **)(int))(*(_DWORD *)(this + 276) + 20))(this + 276);
  if ( byte_75B170 )
    byte_75B170 = 0;
  return v11;
}
