int __thiscall sub_46EBB0(const char *this, int a2)
{
  const char *v3; // edi
  int v4; // eax
  const char *v5; // edx
  const char *v6; // ecx
  int result; // eax
  int v8; // esi
  char Buffer[256]; // [esp+8h] [ebp-100h] BYREF

  v3 = &this[24 * a2];
  v4 = *((_DWORD *)v3 + 275);
  if ( !*(_DWORD *)&this[4 * v4 + 1028] )
  {
    v5 = (const char *)dword_91CAE8;
    if ( !dword_91CAE8 )
      v5 = WindowName;
    v6 = *(const char **)dword_91CA70;
    if ( !*(_DWORD *)dword_91CA70 )
      v6 = WindowName;
    sprintf(Buffer, "%s%s%s", v6, v5, &this[64 * v4 + 1]);
    if ( sub_5E4940(dword_FB1CE0, &this[4 * *((_DWORD *)v3 + 275) + 1028], Buffer, 0, 0, 0, 1) )
    {
      sub_5E4BF0(dword_FB1CE0, *(void **)&this[4 * *((_DWORD *)v3 + 275) + 1028]);
      *(_DWORD *)&this[4 * *((_DWORD *)v3 + 275) + 1028] = 0;
    }
  }
  result = 32;
  if ( *((_DWORD *)v3 + 279) )
    result = 524320;
  v8 = *(_DWORD *)&this[4 * *((_DWORD *)v3 + 275) + 1028];
  if ( v8 )
    return sub_5EE000(dword_FB1CE0, (int)(v3 + 1096), 1, v8, result, 3136);
  *((_DWORD *)v3 + 274) = 0;
  return result;
}
