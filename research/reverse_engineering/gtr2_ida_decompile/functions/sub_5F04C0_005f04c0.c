int __thiscall sub_5F04C0(void *this, char *a2)
{
  char *v2; // eax
  char v3; // cl
  int *v4; // ebp
  int v5; // edi
  char v7; // [esp+0h] [ebp-110h]
  char String[256]; // [esp+10h] [ebp-100h] BYREF

  v2 = a2;
  if ( !a2 )
  {
    sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Invalid font name", v7);
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
  v4 = (int *)dword_FB287C;
  dword_FB2884 = dword_FB287C;
  if ( !dword_FB287C )
    return 0;
  v5 = *(_DWORD *)dword_FB287C;
  if ( !*(_DWORD *)dword_FB287C )
    return 0;
  while ( strcmp((const char *)(v5 + 20), String) )
  {
    v4 = (int *)v4[1];
    dword_FB2884 = (int)v4;
    if ( !v4 )
      return 0;
    v5 = *v4;
    if ( !*v4 )
      return 0;
  }
  return v5;
}
