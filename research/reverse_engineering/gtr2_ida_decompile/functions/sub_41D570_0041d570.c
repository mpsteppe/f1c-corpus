int __thiscall sub_41D570(_DWORD *this)
{
  const char *v2; // ecx
  const char *v3; // eax
  int v4; // ebp
  int *v5; // esi
  const char *v6; // ecx
  const char *v7; // eax
  void **v8; // ebx
  float v9; // ebp
  float v11; // [esp+0h] [ebp-154h]
  float v12; // [esp+0h] [ebp-154h]
  float v13; // [esp+4h] [ebp-150h]
  float v14; // [esp+4h] [ebp-150h]
  float v15; // [esp+10h] [ebp-144h]
  int v16[4]; // [esp+2Ch] [ebp-128h] BYREF
  char v17[128]; // [esp+3Ch] [ebp-118h] BYREF
  char Buffer[152]; // [esp+BCh] [ebp-98h] BYREF

  *this = -1;
  this[7] = 0;
  v16[0] = 0;
  *((float *)this + 1) = (double)*(int *)dword_903EB8 * 0.00078125001;
  *((float *)this + 2) = (double)dword_903EBC * 0.00078125001;
  v2 = (const char *)dword_91CAE8;
  if ( !dword_91CAE8 )
    v2 = WindowName;
  v3 = *(const char **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v3 = WindowName;
  sprintf(Buffer, "%s%s%s", v3, v2, "STEX.GTR");
  sub_5EE940((int)v16, (char)Buffer, 0);
  v4 = (int)off_757B80;
  v16[1] = (int)off_757B80;
  v5 = this + 3;
  do
  {
    v6 = (const char *)dword_91CAE8;
    if ( !dword_91CAE8 )
      v6 = WindowName;
    v7 = *(const char **)dword_91CA70;
    if ( !*(_DWORD *)dword_91CA70 )
      v7 = WindowName;
    sprintf(v17, "%s%s%s", v7, v6, *(const char **)v4);
    v8 = (void **)(v5 + 2);
    if ( sub_5E4940(dword_FB1CE0, v5 + 2, v17, 0, 0, 0, 1) )
      sub_5E4BF0(dword_FB1CE0, *v8);
    sub_5EE000(dword_FB1CE0, (int)v5, 1, 0, 32, 3136);
    if ( *v5 )
    {
      v11 = *((float *)this + 1) * 576.0;
      v13 = *((float *)this + 2) * 190.0;
      v9 = v13;
      v15 = *((float *)this + 1) * 128.0;
      sub_5EDF20(*v5, 0, v11, v13, 1.0, 0.0, 0.0, -1);
      v14 = v13 + v15;
      sub_5EDF20(*v5, 1, v11, v14, 1.0, 0.0, 1.0, -1);
      v12 = v11 + v15;
      sub_5EDF20(*v5, 2, v12, v14, 1.0, 1.0, 1.0, -1);
      sub_5EDF20(*v5, 3, v12, v9, 1.0, 1.0, 0.0, -1);
      sub_5EDAF0(*v8);
      v4 = 524292;
    }
    v4 += 4;
    ++v5;
  }
  while ( v4 < (int)&unk_757B88 );
  return 0;
}
