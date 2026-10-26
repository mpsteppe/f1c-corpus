// f1c  0x0059491a  size=324
int *sub_59491A()
{
  int *v0; // esi
  _DWORD *v1; // eax
  _DWORD *v2; // edi
  int *v3; // eax
  int v4; // ebp
  int v5; // edx

  if ( dword_5E7978 == -1 )
  {
    v0 = (int *)&off_5E7968;
  }
  else
  {
    v0 = (int *)HeapAlloc(hHeap, 0, 0x2020u);
    if ( !v0 )
      return 0;
  }
  v1 = VirtualAlloc(0, 0x400000u, 0x2000u, 4u);
  v2 = v1;
  if ( !v1 )
  {
LABEL_19:
    if ( v0 != (int *)&off_5E7968 )
      HeapFree(hHeap, 0, v0);
    return 0;
  }
  if ( !VirtualAlloc(v1, 0x10000u, 0x1000u, 4u) )
  {
    VirtualFree(v2, 0, 0x8000u);
    goto LABEL_19;
  }
  if ( v0 == (int *)&off_5E7968 )
  {
    if ( !off_5E7968 )
      off_5E7968 = &off_5E7968;
    if ( !off_5E796C )
      off_5E796C = &off_5E7968;
  }
  else
  {
    *v0 = (int)&off_5E7968;
    v0[1] = (int)off_5E796C;
    off_5E796C = v0;
    *(_DWORD *)v0[1] = v0;
  }
  v0[5] = (int)(v2 + 0x100000);
  v3 = v0 + 6;
  v0[3] = (int)(v0 + 38);
  v0[4] = (int)v2;
  v0[2] = (int)(v0 + 6);
  v4 = 0;
  do
  {
    v5 = v4++ >= 16 ? -1 : 240;
    *v3 = v5;
    v3[1] = 241;
    v3 += 2;
  }
  while ( v4 < 1024 );
  sub_58BB10((unsigned __int8 *)v2, 0, 0x10000u);
  while ( (unsigned int)v2 < v0[4] + 0x10000 )
  {
    *((_BYTE *)v2 + 248) = -1;
    *v2 = v2 + 2;
    v2[1] = 240;
    v2 += 1024;
  }
  return v0;
}
