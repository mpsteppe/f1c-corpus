float *__thiscall sub_5E5050(char *this, __int16 a2)
{
  int v3; // esi
  int v4; // edi
  float *result; // eax
  float v6[16]; // [esp+10h] [ebp-40h] BYREF

  if ( (a2 & 2) != 0 )
  {
    sub_5D7160((int)(this + 560), (float *)this + 86);
    sub_5D7120((_DWORD *)this + 86, (int)v6);
    v3 = 0;
    v4 = (int)(this + 248);
    do
    {
      result = (float *)sub_5D79C0(v4, v4 - 96, (int)v6, 0, v3++);
      v4 += 16;
    }
    while ( v3 < 6 );
    *((float *)this + 13) = -*((float *)this + 104);
    *((float *)this + 14) = -*((float *)this + 105);
    *((float *)this + 15) = -*((float *)this + 106);
  }
  if ( (a2 & 4) != 0 )
  {
    if ( (a2 & 0x20) != 0 )
      result = sub_5D79E0((int)this, v6);
    else
      result = sub_5D85D0((int)this, v6);
    qmemcpy(this + 632, v6, 0x40u);
  }
  if ( (a2 & 0x10) != 0 )
    result = (float *)(*(int (__thiscall **)(int, _DWORD, char *))(*(_DWORD *)dword_FB27A4 + 588))(
                        dword_FB27A4,
                        *((_DWORD *)this + 192),
                        this);
  if ( (a2 & 8) != 0 )
    result = (float *)(*(int (__thiscall **)(int, char *))(*(_DWORD *)dword_FB27A4 + 584))(dword_FB27A4, this);
  if ( (a2 & 6) != 0 && (*(_DWORD *)this & 0x20000) == 0 )
    result = (float *)sub_5D7280(this + 696, (int)(this + 344), (float *)this + 157);
  *(_DWORD *)(dword_FB27A4 + 9000) = this;
  if ( (a2 & 0x100) != 0 )
    return (float *)sub_5F6B80(0, this);
  return result;
}
