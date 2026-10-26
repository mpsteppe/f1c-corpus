// f1c  0x0047bc30  size=94
int __thiscall sub_47BC30(int this)
{
  const char *v2; // ebx
  unsigned int v3; // kr04_4
  int v4; // edi
  int i; // esi
  int v6; // eax

  v2 = **(const char ***)(this + 224);
  if ( !v2 )
    v2 = byte_5EA438;
  v3 = strlen(v2) + 1;
  v4 = 0;
  for ( i = 0; ; i = v6 )
  {
    v6 = sub_47B730(this, i);
    if ( i == v6 || *(_DWORD *)(this + 228) < v6 || v3 - 1 == v6 && v2[v6 - 1] != -1 )
      break;
    ++v4;
  }
  return v4;
}
