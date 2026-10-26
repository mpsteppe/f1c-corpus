int __thiscall sub_4623E0(_DWORD *this)
{
  char *v1; // ebx
  char *v2; // edi
  _DWORD *v3; // esi
  int v4; // ebp
  int result; // eax

  v1 = (char *)(this + 1735);
  v2 = (char *)(this + 188);
  v3 = this + 1629;
  v4 = 48;
  do
  {
    *v3 = -1;
    sub_462BD0(v2);
    result = sub_52E5C0(v1);
    ++v3;
    v2 += 116;
    v1 += 424;
    --v4;
  }
  while ( v4 );
  return result;
}
