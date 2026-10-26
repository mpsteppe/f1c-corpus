char __thiscall sub_415230(int this)
{
  int v2; // eax
  int v3; // ecx
  char *v4; // eax
  char result; // al

  v2 = *(_DWORD *)(this + 116);
  if ( v2 && *(_DWORD *)(v2 + 36) == 10 )
    sub_4373B0(this + 20);
  if ( *(_BYTE *)(this + 141) )
    return 0;
  sub_40C420(*(int **)(this + 4), 0);
  v3 = *(_DWORD *)(this + 120);
  if ( v3 )
  {
    v4 = (char *)sub_459B80(v3);
    sub_40C400(*(int ****)(this + 4), v4);
  }
  else
  {
    sub_40C3F0(*(_DWORD ***)(this + 4));
  }
  sub_419110(*(_DWORD *)(this + 8));
  sub_414BB0((char *)this);
  result = 1;
  *(_BYTE *)(this + 141) = 1;
  return result;
}
