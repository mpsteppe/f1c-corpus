int __thiscall sub_5F4870(void *this, char *a2)
{
  char *v2; // eax
  char v3; // cl
  char *v4; // edi
  int *v6; // ebp
  int v7; // edi
  char v9; // [esp+0h] [ebp-110h]
  char v10; // [esp+Fh] [ebp-101h] BYREF
  char String[256]; // [esp+10h] [ebp-100h] BYREF

  v2 = a2;
  if ( !a2 )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid video file name", v9);
    return 0;
  }
  do
  {
    v3 = *v2;
    v2[String - a2] = *v2;
    ++v2;
  }
  while ( v3 );
  _strupr(String);
  if ( !strstr(String, ".BIK") )
  {
    v4 = &v10;
    while ( *++v4 )
      ;
    strcpy(v4, ".BIK");
  }
  v6 = (int *)dword_FB27E4;
  dword_FB27EC = dword_FB27E4;
  if ( !dword_FB27E4 )
    return 0;
  v7 = *(_DWORD *)dword_FB27E4;
  if ( !*(_DWORD *)dword_FB27E4 )
    return 0;
  while ( strcmp((const char *)(v7 + 20), String) )
  {
    v6 = (int *)v6[1];
    dword_FB27EC = (int)v6;
    if ( !v6 )
      return 0;
    v7 = *v6;
    if ( !*v6 )
      return 0;
  }
  return v7;
}
